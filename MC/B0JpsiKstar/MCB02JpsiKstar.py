#---------------------------------------------
# Author   : Michael Wilkinson
# Date     : 7/27/16
# Comments : B0->J/psi K*
# Data     : Real Data
#---------------------------------------------
from Gaudi.Configuration import *
from Configurables import GaudiSequencer
from Configurables import  DecayTreeTuple#, CheckPV
from PhysSelPython.Wrappers import AutomaticData, Selection, SelectionSequence, DataOnDemand, MergedSelection
from Configurables import   CombineParticles, FilterDesktop#,  OfflineVertexFitter
from Configurables import SelDSTWriter, DaVinci

#--Stripping--------------------------------------------------------
from StrippingConf.Configuration import StrippingConf, StrippingStream
from StrippingSettings.Utils import strippingConfiguration
from StrippingArchive.Utils import buildStreams
from StrippingArchive import strippingArchive

#----------------------Standard stripping20-------------------------
stripping='stripping20'
config  = strippingConfiguration(stripping)
archive = strippingArchive(stripping)
streams = buildStreams(stripping=config, archive=archive)

#----Select my line-------------------------------------------------
MyStream = StrippingStream("MyStream")
MyLines = [ 'StrippingFullDSTDiMuonJpsi2MuMuDetachedLine' ]

for stream in streams:
    for line in stream.lines:
        if line.name() in MyLines:
            MyStream.appendLines( [ line ] )

sc = StrippingConf( HDRLocation = "MyStrip", Streams = [ MyStream ] )
#------------------------------------------------------------------------

#----Jpsi->mumu---------------------------------
J2MuMu = AutomaticData(Location = "Phys/FullDSTDiMuonJpsi2MuMuDetachedLine/Particles")

_Jpsi2MuMu = FilterDesktop("_J2MuMu")
_Jpsi2MuMu.Code = "(ADMASS('J/psi(1S)')<50*MeV)"\
    "& (MINTREE(ABSID=='mu+',PT)>500*MeV)"\
    "& (MINTREE(ABSID=='mu+',TRCHI2DOF)<4)"

Jpsi2MuMu = Selection("FilterJ",
                      Algorithm = _Jpsi2MuMu ,
                      RequiredSelections = [ J2MuMu ] )

#----Selection K*->K+ pi-
Kstar2Kpi = DataOnDemand(Location = "Phys/StdLooseKstar2Kpi/Particles")

_Kst2Kpi = FilterDesktop("_Kst2Kpi")
_Kst2Kpi.Code = "(ADMASS('K*(892)0') < 100.*MeV)"\
    # "& (VFASPF(VCHI2/VDOF) < 4)"\
    # "& (MINTREE(ABSID=='K+',PT)>250*MeV)"\
    # "& (MINTREE(ABSID=='pi-',PT)>250*MeV)"\
    # "& ((MINTREE(ABSID=='K+',PT)+MINTREE(ABSID=='pi-',PT))>900*MeV)"\
    # "& (MINTREE(ABSID=='K+',TRCHI2DOF)<4)"\
    # "& (MINTREE(ABSID=='pi-',TRCHI2DOF)<4)"

Kst2Kpi = Selection( "FilterKst",
                      Algorithm          = _Kst2Kpi ,
                      RequiredSelections = [ Kstar2Kpi ] )

#----Selection B0 -> J/psi K+ pi-------------------
_B02JpsiKpi = CombineParticles( "_B02JpsiKpi",
                              DecayDescriptor = "[B0 -> J/psi(1S) K*(892)0]cc",
                              CombinationCut  = "AM < 6500. * MeV",
                              MotherCut       = "(VFASPF(VCHI2/VDOF)<5) & (BPVDIRA > 0.99993)",
                              ReFitPVs        = True )

B02JpsiKpi  = Selection( "B02JpsiKpi",
                      Algorithm          = _B02JpsiKpi ,
                      RequiredSelections = [ Jpsi2MuMu, Kst2Kpi ] )

### Gaudi sequence
SeqB02JpsiKpi = SelectionSequence("SeqB02JpsiKpi", TopSelection = B02JpsiKpi)
seq = SeqB02JpsiKpi.sequence()

#--------------------------------------------------------------------------
# Configure DaVinci
#-------------------------------------------------------------------------
from Configurables import DaVinci

DaVinci().appendToMainSequence( [sc.sequence() ] )   # Append the stripping selection sequence to DaVinci
from Configurables import  OfflineVertexFitter

from Configurables import  DecayTreeTuple, MCDecayTreeTuple

tuple = DecayTreeTuple( "B02JpsiKpiTree" )
tuple.Inputs = [ SeqB02JpsiKpi.outputLocation() ]


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
from Configurables import DecayTreeTuple, LoKi__Hybrid__TupleTool, TupleToolDecay, TupleToolTISTOS, TupleToolTagging, TupleToolTrigger, MCDecayTreeTuple
from Configurables import TupleToolGeometry, FitDecayTrees

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
tuple.Decay = '[B0 -> ^(J/psi(1S) -> ^mu+ ^mu-) ^(K*(892)0 -> ^K+ ^pi-)]CC'
tuple.Branches = {
    "B0"   :  "^[B0 -> (J/psi(1S) -> mu+ mu-) (K*(892)0 -> K+ pi-)]CC",
    "R"    :  "[B0 -> (J/psi(1S) -> mu+ mu-) ^(K*(892)0 -> K+ pi-)]CC", 
    "H1"   :  "[B0 -> (J/psi(1S) -> mu+ mu-) (K*(892)0 -> ^K+ pi-)]CC",
    "H2"   :  "[B0 -> (J/psi(1S) -> mu+ mu-) (K*(892)0 -> K+ ^pi-)]CC",
    "J_psi_1S"   :  "[B0 -> ^(J/psi(1S) -> mu+ mu-) (K*(892)0 -> K+ pi-)]CC"       
}

tuple.ToolList += [
    "TupleToolMCTruth",
    "TupleToolMCBackgroundInfo"
    ]

from Configurables import TupleToolMCTruth, MCTupleToolP2VV

tuple.addTool(TupleToolDecay, name="B0")
tuple.B0.ToolList = [ "TupleToolMCTruth", "TupleToolPropertime" ]
tuple.B0.addTool(TupleToolMCTruth)
tuple.addTool(TupleToolDecay, name="J_psi_1S")

tuple.B0.addTool(tistos)
tuple.B0.ToolList+=["TupleToolTISTOS/tistos"]
tuple.J_psi_1S.addTool(tistos)
tuple.J_psi_1S.ToolList+=["TupleToolTISTOS/tistos"]
tuple.ReFitPVs = True
LoKi_B0=LoKi__Hybrid__TupleTool("LoKi_B0")
LoKi_B0.Variables =  { 
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
tuple.B0.addTool(LoKi_B0)         
tuple.B0.ToolList+=["LoKi::Hybrid::TupleTool/LoKi_B0"] 
# #----Select K+ pi- for TupleToolAllTracks (should be same as above)

# from Configurables import TupleToolAllTracks
# B0AllTracks=TupleToolAllTracks("B0AllTracks")
# atlocations = [  ]
# atlocations.append("Phys/StdAllLooseKaons/Particles")
# atlocations.append("Phys/StdAllLoosePions/Particles")
# # B0AllTracks.ANNPIDCut = 0.3 
# # B0AllTracks.GhostProb = 0.5
# # B0AllTracks.Theta = 0.012
# # B0AllTracks.DeltaPhi = 0.005
# B0AllTracks.NewVertexChi2 = 10
# # B0AllTracks.MHi = 7000
# B0AllTracks.ImprovedVertex = 6
# B0AllTracks.PVIPchi2 = 8
# # B0AllTracks.CorrectedMass = False
# B0AllTracks.Target = "J/psi(1S)" #has to be defined in decay descriptor
# B0AllTracks.InputParticles = atlocations
# tuple.B0.addTool(B0AllTracks)
# tuple.B0.ToolList+=["TupleToolAllTracks/B0AllTracks"]

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
DaVinci().Simulation   = True
DaVinci().EvtMax = -1                        # Number of events
DaVinci().EventPreFilters = fltrs.filters('Filter')
DaVinci().UserAlgorithms = [ seq, tuple ]
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
DaVinci().Lumi = False


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

