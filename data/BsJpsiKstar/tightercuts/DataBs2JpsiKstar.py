#---------------------------------------------
# Author   : Michael Wilkinson
# Date     : 7/27/16
# Comments : Bs->J/psi K*
# Data     : Real Data
#---------------------------------------------
from Gaudi.Configuration import *
from Configurables import GaudiSequencer
from Configurables import  DecayTreeTuple#, CheckPV
from PhysSelPython.Wrappers import AutomaticData, Selection, SelectionSequence, DataOnDemand, MergedSelection
from Configurables import   CombineParticles, FilterDesktop#,  OfflineVertexFitter

#----Jpsi->mumu---------------------------------
J2MuMu = AutomaticData(Location = "/Event/Dimuon/Phys/FullDSTDiMuonJpsi2MuMuDetachedLine/Particles")

_Jpsi2MuMu = FilterDesktop("_J2MuMu")
_Jpsi2MuMu.Code = "(ADMASS('J/psi(1S)')<50*MeV)"\
    "& (MINTREE(ABSID=='mu+',PT)>500*MeV)"\
    "& (MINTREE(ABSID=='mu+',TRCHI2DOF)<4)"

Jpsi2MuMu = Selection("FilterJ",
                      Algorithm = _Jpsi2MuMu ,
                      RequiredSelections = [ J2MuMu ] )

#----Selection K*->K+ pi-
Kstar2Kpi = DataOnDemand(Location = "/Event/Phys/StdLooseKstar2Kpi/Particles")

_Kst2Kpi = FilterDesktop("_Kst2Kpi")
_Kst2Kpi.Code = "(ADMASS('K*(892)0') < 100.*MeV)"\
    "& (VFASPF(VCHI2/VDOF) < 4)"\
    "& (MINTREE(ABSID=='K+',PT)>250*MeV)"\
    "& (MINTREE(ABSID=='pi-',PT)>250*MeV)"\
    "& ((MINTREE(ABSID=='K+',PT)+MINTREE(ABSID=='pi-',PT))>900*MeV)"\
    "& (MINTREE(ABSID=='K+',TRCHI2DOF)<4)"\
    "& (MINTREE(ABSID=='pi-',TRCHI2DOF)<4)"

Kst2Kpi = Selection( "FilterKst",
                      Algorithm          = _Kst2Kpi ,
                      RequiredSelections = [ Kstar2Kpi ] )

# _Kst2Kpi = CombineParticles( "_Kst2Kpi",
#                              DecayDescriptor = "[K*(892)0 -> K+ pi-]cc",
#                              CombinationCut  = "ADAMASS('K*(892)0') < 200.*MeV",
#                              ReFitPVs        = False )
# _Kst2Kpi.DaughtersCuts = {
#     "K+"  : "(PT>250*MeV) & (MINIPCHI2>6) & (TRCHI2DOF<7)",
#     "pi-" : "(PT>250*MeV) & (MINIPCHI2>6) & (TRCHI2DOF<7)"
#     }
# Kst2Kpi = Selection ("Kst2Kpi",
#                      Algorithm = _Kst2Kpi,
#                      RequiredSelections = [ Kstar2Kpi ] )

#----Selection Bs -> J/psi K+ pi-------------------
_Bs2JpsiKpi = CombineParticles( "_Bs2JpsiKpi",
                              DecayDescriptor = "[B_s0 -> J/psi(1S) K*(892)0]cc",
                              CombinationCut  = "AM < 6500. * MeV",
                              MotherCut       = "(VFASPF(VCHI2/VDOF)<5) & (BPVDIRA > 0.99993)",
                              ReFitPVs        = True )

Bs2JpsiKpi  = Selection( "Bs2JpsiKpi",
                      Algorithm          = _Bs2JpsiKpi ,
                      RequiredSelections = [ Jpsi2MuMu, Kst2Kpi ] )

### Gaudi sequence
SeqBs2JpsiKpi = SelectionSequence("SeqBs2JpsiKpi", TopSelection = Bs2JpsiKpi)
seq = SeqBs2JpsiKpi.sequence()

#--------------------------------------------------------------------------
# Configure DaVinci
#-------------------------------------------------------------------------
from Configurables import DaVinci

# from Configurables import  OfflineVertexFitter

from Configurables import  DecayTreeTuple, MCDecayTreeTuple
# importOptions("Xb2JpsiXTree.py")

tuple = DecayTreeTuple( "Bs2JpsiKpiTree" )
tuple.Inputs = [ SeqBs2JpsiKpi.outputLocation() ]


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

###########################################################################################################################
tuple.Decay = '[B_s0 -> ^(J/psi(1S) -> ^mu+ ^mu-) ^(K*(892)0 -> ^K+ ^pi-)]CC'
tuple.Branches = {
    "Bs"   :  "^[B_s0 -> (J/psi(1S) -> mu+ mu-) (K*(892)0 -> K+ pi-)]CC",
    "R"    :  "[B_s0 -> (J/psi(1S) -> mu+ mu-) ^(K*(892)0 -> K+ pi-)]CC", 
    "H1"   :  "[B_s0 -> (J/psi(1S) -> mu+ mu-) (K*(892)0 -> ^K+ pi-)]CC",
    "H2"   :  "[B_s0 -> (J/psi(1S) -> mu+ mu-) (K*(892)0 -> K+ ^pi-)]CC",
    "J_psi_1S"   :  "[B_s0 -> ^(J/psi(1S) -> mu+ mu-) (K*(892)0 -> K+ pi-)]CC"       
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
#----Select K+ pi- for TupleToolAllTracks (should be same as above)
Ks = DataOnDemand(Location = "/Event/Phys/StdAllLooseKaons/Particles")
_Kaons = FilterDesktop("_Kaons")
_Kaons.Code = "(PT>250*MeV)"\
    "& (TRCHI2DOF<4)"
Kaons = Selection( "FilterKaons",
                   Algorithm          = _Kaons ,
                   RequiredSelections = [ Ks ] )
SeqKaons = SelectionSequence("SeqKaons", TopSelection = Kaons)

pis = DataOnDemand(Location = "/Event/Phys/StdAllLoosePions/Particles")
_pions = FilterDesktop("_pions")
_pions.Code = "(PT>250*MeV)"\
    "& (TRCHI2DOF<4)"
pions = Selection( "Filterpions",
                   Algorithm          = _pions ,
                   RequiredSelections = [ pis ] )
Seqpions = SelectionSequence("Seqpions", TopSelection = pions)

from Configurables import TupleToolAllTracks
BsAllTracks=TupleToolAllTracks("BsAllTracks")
atlocations = [  ]
atlocations.append(SeqKaons.outputLocation())
atlocations.append(Seqpions.outputLocation())
# BsAllTracks.ANNPIDCut = 0.3 
# BsAllTracks.GhostProb = 0.5
# BsAllTracks.Theta = 0.012
# BsAllTracks.DeltaPhi = 0.005
# BsAllTracks.NewVertexChi2 = 10
# BsAllTracks.MHi = 7000
# BsAllTracks.ImprovedVertex = 6
# BsAllTracks.PVIPchi2 = 8
# BsAllTracks.CorrectedMass = False
BsAllTracks.Target = "J/psi(1S)" #has to be defined in decay descriptor
BsAllTracks.InputParticles = atlocations
tuple.Bs.addTool(BsAllTracks)
tuple.Bs.ToolList+=["TupleToolAllTracks/BsAllTracks"]

# tuple.addTool(TupleToolDecay, name="R")

# LoKi_R=LoKi__Hybrid__TupleTool("LoKi_R")
# LoKi_R.Variables =  {
#     "WM" : "WM( 'pi+' , 'pi-')"
#     }
# tuple.R.addTool(LoKi_R)
# tuple.R.ToolList+=["LoKi::Hybrid::TupleTool/LoKi_R"]

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
DaVinci().UserAlgorithms = [ seq, tuple, SeqKaons, Seqpions ]
# from Configurables import CondDB
#CondDB(UseOracle = True)
#importOptions("$APPCONFIGOPTS/DisableLFC.py")
#CondDB().IgnoreHeartBeat = True
DaVinci().DataType = "2012"
#DaVinci().DDDBtag   = "head-20110914"
#DaVinci().CondDBtag = "head-20111102"
DaVinci().TupleFile = "LimDVNtuples.root"
DaVinci().PrintFreq = 1#0000
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

