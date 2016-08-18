#---------------------------------------------
# Author   : Bilas Pal
# Date     : 10/26/2012
# Comments : /\b->J/psi p+ K-
# Data     : Real Data
#---------------------------------------------
from Gaudi.Configuration import *
from Configurables import GaudiSequencer
from Configurables import  DecayTreeTuple#, CheckPV
from PhysSelPython.Wrappers import AutomaticData, Selection, SelectionSequence, DataOnDemand, MergedSelection
from Configurables import   CombineParticles, FilterDesktop#,  OfflineVertexFitter


# #DaughtCut = "(TRCHI2DOF < 4.0) & (MIPCHI2DV(PRIMARY)>9) & (TRGHOSTPROB < 0.2)"
# DaughtCutK = "(MIPCHI2DV(PRIMARY)>4) & (TRCHI2DOF < 4.0) & (PT>250*MeV) &  (PIDK-PIDpi>0) &  (PIDK-PIDp>-6) & (TRGHOSTPROB < 0.2)"
# DaughtCutp = "(MIPCHI2DV(PRIMARY)>4) & (TRCHI2DOF < 4.0) & (PT>250*MeV) & (PIDp-PIDpi>5) & (PIDp-PIDK>0)  & (TRGHOSTPROB < 0.2)"

#----Jpsi->mumu---------------------------------
Jpsi2MuMu = AutomaticData(Location = "/Event/Dimuon/Phys/FullDSTDiMuonJpsi2MuMuDetachedLine/Particles")

#----selection p+ and K- -------------------------
# kaons = DataOnDemand(Location = "/Event/Phys/StdNoPIDsKaons/Particles")
# protons = DataOnDemand(Location = "/Event/Phys/StdNoPIDsProtons/Particles")
Lambda0LL = DataOnDemand(Location = "/Event/Phys/StdLooseLambdaLL/Particles")
Lambda0DD = DataOnDemand(Location = "/Event/Phys/StdLooseLambdaDD/Particles")

#----Selection /\->p+ pi-


AllLambda0 = MergedSelection( "AllLambda0", RequiredSelections = [Lambda0LL, Lambda0DD])

_FilterL = FilterDesktop("_FilterL")
_FilterL.Code = "(ADMASS('Lambda0') < 30.*MeV)"\
                  "& (VFASPF(VCHI2/VDOF) < 12.0)"

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

# from Configurables import  OfflineVertexFitter

from Configurables import  DecayTreeTuple, MCDecayTreeTuple
# importOptions("Xb2JpsiXTree.py")

tuple = DecayTreeTuple( "Lb2JpsiLTree" )
tuple.Inputs = [ SeqLb2JpsipK.outputLocation() ]


#----------begin former Xb2JpsiXTree.py-----------------#

########################################################################
#
# J/psi n-tuple
#
# @author Bilas Pal
# @date 2010-11-01
######
########################################################################
from Gaudi.Configuration import *
#
# DecayTreeTuple
#
from Configurables import DecayTreeTuple, LoKi__Hybrid__TupleTool, TupleToolDecay, TupleToolTISTOS#, TupleToolTagging, TupleToolTrigger
from Configurables import TupleToolGeometry#, FitDecayTrees
# tuple = DecayTreeTuple('Lb2JpsiLTree') 
# tuple.Inputs = [ 'Phys/Bs2Jpsif0' ]

tuple.TupleName = "mytree"

tuple.ToolList =  [
       "TupleToolGeometry",
       "TupleToolKinematic",
       "TupleToolEventInfo",
#       "TupleToolTISTOS",
       "TupleToolPid",
       "TupleToolTrackInfo",
#       "TupleToolTagging"
        ]
tistos = TupleToolTISTOS("tistos")
tistos.VerboseL0 = 1
tistos.VerboseHlt1 = 1
tistos.VerboseHlt2 = 1
tistos.TriggerList = [
                          'L0DiMuonDecision',
                             'L0HCALDecision',
                             'L0MuonDecision',
                         'L0MuonHighDecision',
               'Hlt1SingleMuonNoIPL0Decision',
                 'Hlt1DiMuonHighMassDecision',
                  'Hlt1DiMuonLowMassDecision',
               'Hlt1SingleMuonHighPTDecision',
                 'Hlt1SingleMuonNoIPDecision',
                     'Hlt1TrackAllL0Decision',
                      'Hlt1TrackMuonDecision',
               'Hlt1SingleMuonNoIPL0Decision',
                        'Hlt2DiMuonBDecision',
                         'Hlt2DiMuonDecision',                        
                      'Hlt2DiMuonDY1Decision',
                 'Hlt2DiMuonDetachedDecision',
            'Hlt2DiMuonDetachedHeavyDecision',
             'Hlt2DiMuonDetachedJPsiDecision',
                     'Hlt2DiMuonJPsiDecision',
               'Hlt2DiMuonJPsiHighPTDecision',
                    'Hlt2ExpressJPsiDecision',
            'Hlt2ExpressJPsiTagProbeDecision',
                     'Hlt2SingleMuonDecision',
               'Hlt2SingleMuonHighPTDecision',
                'Hlt2SingleMuonLowPTDecision',
                  'Hlt2Topo2BodyBBDTDecision',
                'Hlt2Topo2BodySimpleDecision',      
                  'Hlt2Topo3BodyBBDTDecision',      
                'Hlt2Topo3BodySimpleDecision',
                  'Hlt2Topo4BodyBBDTDecision',        
                'Hlt2Topo4BodySimpleDecision',      
                'Hlt2TopoMu2BodyBBDTDecision',        
                'Hlt2TopoMu3BodyBBDTDecision',      
                'Hlt2TopoMu4BodyBBDTDecision',      
                    'Hlt2TransparentDecision',                           
             'Hlt2DiMuonUnbiasedJPsiDecision'
]

tuple.addTool(TupleToolGeometry)
tuple.TupleToolGeometry.Verbose = True
#tuple.TupleToolTISTOS.UseAutomaticTriggerList = True
#tuple.addTool(TupleToolTagging)
#tuple.TupleToolTagging.Verbose = True
#from FlavourTagging.Tunings import TuneTool
#TuneTool(tuple,'Xmass_2011')

###########################################################################################################################
tuple.Decay = '[Lambda_b0 -> ^(J/psi(1S) -> ^mu+ ^mu-) ^(Lambda0 -> ^p+ ^pi-)]CC'
tuple.Branches = {
    "Bs"   :  "^[Lambda_b0 -> (J/psi(1S) -> mu+ mu-) (Lambda0 -> p+ pi-)]CC",
    "R"    :  "[Lambda_b0 -> (J/psi(1S) -> mu+ mu-) ^(Lambda0 -> p+ pi-)]CC", 
    "H1"   :  "[Lambda_b0 -> (J/psi(1S) -> mu+ mu-) (Lambda0 -> ^p+ pi-)]CC",      
    "H2"   :  "[Lambda_b0 -> (J/psi(1S) -> mu+ mu-) (Lambda0 -> p+ ^pi-)]CC",   
    "J_psi_1S"   :  "[Lambda_b0 -> ^(J/psi(1S) -> mu+ mu-) (Lambda0 -> p+ pi-)]CC"       
}

tuple.addTool(TupleToolDecay, name="Bs")
tuple.Bs.ToolList = [ "TupleToolPropertime" ]
tuple.addTool(TupleToolDecay, name="J_psi_1S")

tuple.Bs.addTool(tistos)
tuple.Bs.ToolList+=["TupleToolTISTOS/tistos"]
tuple.J_psi_1S.addTool(tistos)
tuple.J_psi_1S.ToolList+=["TupleToolTISTOS/tistos"]
tuple.ReFitPVs = True
LoKi_Bs=LoKi__Hybrid__TupleTool("LoKi_Bs")
LoKi_Bs.Variables =  { 
#        "LOKI_FDCHI2"     : "BPVVDCHI2", 
#        "LOKI_FDS"        : "BPVDLS", 
#        "LOKI_DIRA"       : "BPVDIRA" , 
        "LOKI_DTF_CTAU"        : "DTF_CTAU( 0, True )", 
#        "LOKI_DTF_CTAUS"       : "DTF_CTAUSIGNIFICANCE( 0, True )", 
        "LOKI_DTF_CHI2NDOF"    : "DTF_CHI2NDOF( True )", 
        "LOKI_DTF_CTAUERR"     : "DTF_CTAUERR( 0, True )", 
        "LOKI_MASS_JpsiConstr" : "DTF_FUN ( M , True , 'J/psi(1S)' )" , 
        "LOKI_DTF_VCHI2NDOF"   : "DTF_FUN ( VFASPF(VCHI2/VDOF) , True  )"  
        } 
tuple.Bs.addTool(LoKi_Bs)         
tuple.Bs.ToolList+=["LoKi::Hybrid::TupleTool/LoKi_Bs"] 

from Configurables import TupleToolAllTracks
BsAllTracks=TupleToolAllTracks("BsAllTracks")
atlocations = [  ]
atlocations.append(SeqLb2JpsipK.outputLocation())
# BsAllTracks.ANNPIDCut = 0.3 
# BsAllTracks.GhostProb = 0.5
# BsAllTracks.Theta = 0.012
# BsAllTracks.DeltaPhi = 0.005
# BsAllTracks.NewVertexChi2 = 10
# BsAllTracks.MHi = 7000
# BsAllTracks.ImprovedVertex = 6
# BsAllTracks.PVIPchi2 = 8
# BsAllTracks.CorrectedMass = False
BsAllTracks.Target = 'J_psi_1S' #has to be defined in decay descriptor
BsAllTracks.InputParticles = atlocations
tuple.Bs.addTool(BsAllTracks)
tuple.Bs.ToolList+=["TupleToolAllTracks"]

tuple.addTool(TupleToolDecay, name="R")

LoKi_R=LoKi__Hybrid__TupleTool("LoKi_R")
LoKi_R.Variables =  {
    "WM" : "WM( 'pi+' , 'pi-')"
    }
tuple.R.addTool(LoKi_R)
tuple.R.ToolList+=["LoKi::Hybrid::TupleTool/LoKi_R"]

from Configurables import LoKi__Hybrid__EvtTupleTool as LoKiTool
tuple.addTool(LoKiTool , 'MyLoKiTool' )
tuple.ToolList += [ "LoKi::Hybrid::EvtTupleTool/MyLoKiTool" ]
tuple.MyLoKiTool.VOID_Variables = {    'nTracks' :  " CONTAINS ('Rec/Track/Best') "  ,
                                        "nLong"  :   " TrSOURCE('Rec/Track/Best', TrLONG) >> TrSIZE "
                                          }
tuple.MyLoKiTool.Preambulo = [
    "from LoKiTracks.decorators import *",
    "from LoKiCore.functions import *"
    ]


#----------end former Xb2JpsiXTree.py-----------------#

from PhysConf.Filters import LoKi_Filters
fltrs = LoKi_Filters(STRIP_Code = "(HLT_PASS_RE('StrippingFullDSTDiMuonJpsi2MuMuDetachedLineDecision'))" )

# from Configurables import DaVinci
DaVinci().Simulation   = False
DaVinci().EvtMax = -1                        # Number of events
DaVinci().EventPreFilters = fltrs.filters('Filter')
DaVinci().UserAlgorithms = [ seq, tuple  ]
# from Configurables import CondDB
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
# DaVinciInit().OutputLevel                 = 6
# MessageSvc().OutputLevel                  = 6
# GetIntegratedLuminosity().OutputLevel     = 6 #INFO
# ToolSvc().OutputLevel                     = 6
# NTupleSvc().OutputLevel                   = 6




#from GaudiConf import IOHelper
#IOHelper().inputFiles([
#'/tmp/lzhang/00020241_00001413_1.dimuon.dst'
#], clear=True)

