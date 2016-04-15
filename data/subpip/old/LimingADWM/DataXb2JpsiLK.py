#---------------------------------------------
# Author   : Bilas Pal
# Date     : 10/26/2012
# Comments : /\b->J/psi p+ K-
# Data     : Real Data
#---------------------------------------------
from Gaudi.Configuration import *
from Configurables import GaudiSequencer
from Configurables import  DecayTreeTuple, CheckPV
from PhysSelPython.Wrappers import AutomaticData, Selection, SelectionSequence, DataOnDemand, MergedSelection
from Configurables import   CombineParticles, FilterDesktop,  OfflineVertexFitter

#DaughtCut = "(TRCHI2DOF < 4.0) & (MIPCHI2DV(PRIMARY)>9) & (TRGHOSTPROB < 0.2)"
DaughtCutK = "(MIPCHI2DV(PRIMARY)>4) & (TRCHI2DOF < 4.0) & (PT>250*MeV) &  (PIDK-PIDpi>0) &  (PIDK-PIDp>-6) & (TRGHOSTPROB < 0.2)"
DaughtCutp = "(MIPCHI2DV(PRIMARY)>4) & (TRCHI2DOF < 4.0) & (PT>250*MeV) & (PIDp-PIDpi>5) & (PIDp-PIDK>0)  & (TRGHOSTPROB < 0.2)"

#----Jpsi->mumu---------------------------------
location = "/Event/Dimuon/Phys/FullDSTDiMuonJpsi2MuMuDetachedLine/Particles"
Jpsi2MuMu = AutomaticData(Location = location)

#----selection p+ and K- -------------------------
kaons = DataOnDemand(Location = "/Event/Phys/StdNoPIDsKaons/Particles")
protons = DataOnDemand(Location = "/Event/Phys/StdNoPIDsProtons/Particles")
Lambda0LL = DataOnDemand(Location = "/Event/Phys/StdLooseLambdaLL/Particles")
Lambda0DD = DataOnDemand(Location = "/Event/Phys/StdLooseLambdaDD/Particles")

#----Selection /\->p+ pi-


AllLambda0 = MergedSelection( "AllLambda0", RequiredSelections = [Lambda0LL, Lambda0DD])

_FilterL = FilterDesktop("_FilterL")
_FilterL.Code = "(ADMASS('Lambda0') < 30.*MeV)"\
                  "& (VFASPF(VCHI2/VDOF) < 12.0)"\
                  "& (ADWM( 'KS0' , WM( 'pi+' , 'pi-') ) > 20*MeV )"

FilterL = Selection( "FilterL",
                      Algorithm          = _FilterL ,
                      RequiredSelections = [ AllLambda0 ] )

#----Selection /\b -> J/psi p+ K-------------------
_Lb2JpsipK = CombineParticles( "_Lb2JpsipK",
                              DecayDescriptor = "[Lambda_b0 -> J/psi(1S) Lambda0]cc",
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
                      RequiredSelections = [ Jpsi2MuMu, FilterL ] )

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
DaVinci().TupleFile = "LimDVNtuples.root"
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

