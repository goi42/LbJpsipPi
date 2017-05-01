#---------------------------------------------
# Author   : Bilas Pal
# Date     : 10/26/2012
# Comments : /\b->J/psi p+ K-
# Data     : Real Data
# Modified : Michael Wilkinson for sigma0 7/10/2015
#---------------------------------------------
from Gaudi.Configuration import *
from Configurables import GaudiSequencer
from Configurables import  DecayTreeTuple, CheckPV
from PhysSelPython.Wrappers import AutomaticData, Selection, SelectionSequence, DataOnDemand, MergedSelection
from Configurables import   CombineParticles, FilterDesktop,  OfflineVertexFitter

#DaughtCut = "(TRCHI2DOF < 4.0) & (MIPCHI2DV(PRIMARY)>9) & (TRGHOSTPROB < 0.2)"
#DaughtCutK = "(MIPCHI2DV(PRIMARY)>4) & (TRCHI2DOF < 4.0) & (PT>250*MeV) &  (PIDK-PIDpi>0) &  (PIDK-PIDp>-6) & (TRGHOSTPROB < 0.2)"
#DaughtCutp = "(MIPCHI2DV(PRIMARY)>4) & (TRCHI2DOF < 4.0) & (PT>250*MeV) & (PIDp-PIDpi>5) & (PIDp-PIDK>0)  & (TRGHOSTPROB < 0.2)"

#----Jpsi->mumu----------------------------------------------------------
location = "/Event/Dimuon/Phys/FullDSTDiMuonJpsi2MuMuDetachedLine/Particles"
Jpsi2MuMu = AutomaticData(Location = location)

#----selection p+ and K- and lambdas and gammas -------------------------
kaons = DataOnDemand(Location = "/Event/Phys/StdNoPIDsKaons/Particles")
protons = DataOnDemand(Location = "/Event/Phys/StdNoPIDsProtons/Particles")
Lambda0LL = DataOnDemand(Location = "/Event/Phys/StdLooseLambdaLL/Particles")
Lambda0DD = DataOnDemand(Location = "/Event/Phys/StdLooseLambdaDD/Particles")
gammaLL = DataOnDemand(Location = "Event/Phys/StdAllLooseGammaLL/Particles")
gammaDD = DataOnDemand(Location = "Event/Phys/StdAllLooseGammaDD/Particles")

#----Selection /\->p+ pi-


AllLambda0 = MergedSelection( "AllLambda0",
                              RequiredSelections = [Lambda0LL, Lambda0DD])

_FilterL = FilterDesktop("_FilterL")
_FilterL.Code = "(ADMASS('Lambda0') < 30.*MeV)"\
                  "& (VFASPF(VCHI2/VDOF) < 12.0)" 

FilterL = Selection( "FilterL",
                      Algorithm          = _FilterL ,
                      RequiredSelections = [ AllLambda0 ] )

#----Selection sigma0->/\0 gamma

Allgamma = MergedSelection( "Allgamma", RequiredSelections = [gammaLL,gammaDD])

_S2L0g   = CombineParticles("_S2L0g",
                            DecayDescriptor = "[sigma_0 -> Lambda0 gamma]cc",
                            CombinationCut  = "(AM<2000.*MeV)"\
                                              "& (ADMASS('sigma_0') < 30.*MeV)"\
                                              "& (VFASPF(VCHI2/VDOF) < 12.0)",
                            MotherCut       = "(VFASPF(VCHI2/VDOF)<25) & (BPVDIRA > 0.999) & (VFASPF(VCHI2PDOF) < 10) & (BPVVD > 1.5 *mm)",
                            ReFitPVs        = True )

S2L0g    = Selection( "S2L0g",
                     Algorithm          = _S2L0g,
                     RequiredSelections = [FilterL, Allgamma] )

#----Selection /\b -> J/psi sigma0-------------------
_Lb2JpsiS = CombineParticles( "_Lb2JpsiS",
                              DecayDescriptor = "[Lambda_b0 -> J/psi(1S) sigma_0]cc",
                              CombinationCut = "AM < 6000. * MeV",
                              MotherCut       = "(VFASPF(VCHI2/VDOF)<25) & (BPVDIRA > 0.999) & (VFASPF(VCHI2PDOF) < 10) & (BPVVD > 1.5 *mm)",
#                              DaughtersCuts   = {  'K-': DaughtCutK },
                              ReFitPVs        = True )



#---- Refit vertices with Jpsi mass constraint----------------
#_Lb2JpsipK.addTool( OfflineVertexFitter() )
#_Lb2JpsipK.VertexFitters.update( { "" : "OfflineVertexFitter"} )
#_Lb2JpsipK.OfflineVertexFitter.applyDauMassConstraint = True


Lb2JpsiS  = Selection( "Lb2JpsiS",
                      Algorithm          = _Lb2JpsiS ,
                      RequiredSelections = [ Jpsi2MuMu, S2L0g, FilterL ] )

### Gaudi sequence
SeqLb2JpsiS = SelectionSequence("SeqLb2JpsiS", TopSelection = Lb2JpsiS)
seq = SeqLb2JpsiS.sequence()

#--------------------------------------------------------------------------
# Configure DaVinci
#-------------------------------------------------------------------------
from Configurables import DaVinci

from Configurables import  OfflineVertexFitter

from Configurables import  DecayTreeTuple, MCDecayTreeTuple
importOptions("Xb2JpsiXTree.py")


tuple = DecayTreeTuple( "Lb2JpsiSTree" )
tuple.Inputs = [ SeqLb2JpsiS.outputLocation() ]



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
DaVinci().TupleFile = "DVNtuples.root"
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

