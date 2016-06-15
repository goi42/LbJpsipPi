#---------------------------------------------
# Author   : Bilas Pal
# Date     : 10/26/2012
# Comments : /\b->J/psi p+ K-
# Data     : Real Data
# Modified : 08/11/2015 by Michael Wilkinson to replace protons with pions
#          : earlier by Liming Zhang and MW for /\b->J/psi /\0
#---------------------------------------------
from Gaudi.Configuration import *
from Configurables import GaudiSequencer
from Configurables import  DecayTreeTuple, CheckPV
from PhysSelPython.Wrappers import AutomaticData, Selection, SelectionSequence, DataOnDemand, MergedSelection
from Configurables import   CombineParticles, FilterDesktop,  OfflineVertexFitter, SubstitutePID

#----from https://lhcb.github.io/second-analysis-steps/17-switch-mass-hypo.html -----------------------------
subs = SubstitutePID(
    'MakeL02pipi',
    Code = "DECTREE('[Lambda0 -> p+ pi-]cc')",
    Substitutions = {
    'Lambda0 -> ^p+ pi-': 'pi+',
    'Lambda0 -> ^p- pi+': 'pi-'
    }
    )

#----Jpsi->mumu---------------------------------
location = "/Event/Dimuon/Phys/FullDSTDiMuonJpsi2MuMuDetachedLine/Particles"
Jpsi2MuMu = AutomaticData(Location = location)

#----selection p+ and pi- -------------------------
pions = DataOnDemand(Location = "/Event/Phys/StdNoPIDsPions/Particles")
protons = DataOnDemand(Location = "/Event/Phys/StdNoPIDsProtons/Particles")

#----Selection /\->p+ pi-

_FilterL = CombineParticles("_FilterL",
                            DecayDescriptor = "[Lambda0 -> p+ pi-]cc",
                            MotherCut = "(ADMASS('Lambda0') < 30.*MeV)"\
                            "& (VFASPF(VCHI2/VDOF) < 12.0)",
                            ReFitPVs = True )

FilterL = Selection( "FilterL",
                     Algorithm = _FilterL ,
                     RequiredSelections = [pions, protons] )

selSub = Selection("selSub",
    Algorithm = subs,
    RequiredSelections =[ FilterL ] )

#----Selection /\b -> J/psi p+ K-------------------
_Lb2JpsipK = CombineParticles( "_Lb2JpsipK",
                              DecayDescriptor = "[Lambda_b0 -> J/psi(1S) (Lambda0 -> p+ pi-)]cc",
                              CombinationCut = "AM < 6000. * MeV",
                              MotherCut       = "(VFASPF(VCHI2/VDOF)<25) & (BPVDIRA > 0.999) & (VFASPF(VCHI2PDOF) < 10) & (BPVVD > 1.5 *mm)",
#                              DaughtersCuts   = {  'K-': DaughtCutK },
                              ReFitPVs        = True )



#---- Refit vertices with Jpsi mass constraint----------------
#_Lb2JpsipK.addTool( OfflineVertexFitter() )
#_Lb2JpsipK.VertexFitters.update( { "" : "OfflineVertexFitter"} )
#_Lb2JpsipK.OfflineVertexFitter.applyDauMassConstraint = True


Lb2JpsipK  = Selection( "Lb2JpsipK ",
                      Algorithm          = _Lb2JpsipK ,
                      RequiredSelections = [ Jpsi2MuMu, selSub ] )

### Gaudi sequence
SeqLb2JpsipK = SelectionSequence("SeqLb2JpsipK", TopSelection = Lb2JpsipK)
seq = SeqLb2JpsipK.sequence()

#--------------------------------------------------------------------------
# Configure DaVinci
#-------------------------------------------------------------------------
from Configurables import DaVinci

from Configurables import  OfflineVertexFitter

from Configurables import  DecayTreeTuple, MCDecayTreeTuple
importOptions("Xb2JpsiXTree.py")


tuple = DecayTreeTuple( "Lb2JpsiLTree" )
tuple.Inputs = [ SeqLb2JpsipK.outputLocation() ]



from PhysConf.Filters import LoKi_Filters
fltrs = LoKi_Filters(STRIP_Code = "(HLT_PASS_RE('StrippingFullDSTDiMuonJpsi2MuMuDetachedLineDecision'))" )

from Configurables import DaVinci
DaVinci().Simulation   = False
DaVinci().EvtMax = -1                        # Number of events
DaVinci().EventPreFilters = fltrs.filters('Filter')
DaVinci().UserAlgorithms = [ seq, tuple  ]
from Configurables import CondDB
#CondDB(UseOracle = True)
#importOptions("$APPCONFIGOPTS/DisableLFC.py")
#CondDB().IgnoreHeartBeat = True
DaVinci().DataType = "2012"
#DaVinci().DDDBtag   = "head-20110914"
#DaVinci().CondDBtag = "head-20111102"
DaVinci().TupleFile = "subDVNtuples.root"
DaVinci().PrintFreq = 10000
#For luminosity
#CondDB().LocalTags["LHCBCOND"] = ['lumi-20100825']
DaVinci().Lumi = True


########################################################################
MessageSvc().Format = "% F%60W%S%7W%R%T %0W%M"
from Configurables import  DaVinciInit, GetIntegratedLuminosity
DaVinciInit().OutputLevel = 6
MessageSvc().OutputLevel                  = 6
GetIntegratedLuminosity().OutputLevel       = INFO
ToolSvc().OutputLevel                     = 6
NTupleSvc().OutputLevel                   = 6




#from GaudiConf import IOHelper
#IOHelper().inputFiles([
#'/tmp/lzhang/00020241_00001413_1.dimuon.dst'
#], clear=True)

