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
from Configurables import DecayTreeTuple, LoKi__Hybrid__TupleTool, TupleToolDecay, TupleToolTrigger, TupleToolTISTOS, TupleToolTagging
from Configurables import FitDecayTrees, TupleToolGeometry
from Configurables import TupleToolIsoGeneric
tuple = DecayTreeTuple('Lb2JpsiLTree') 
tuple.Inputs = [ 'Phys/Bs2Jpsif0' ]

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
tuple.Decay = '[Lambda_b0 -> (^J/psi(1S) -> ^mu+ ^mu-) (^Lambda0 -> ^p+ ^pi-)]cc'
tuple.Branches = {
    "Bs"   :  "[Lambda_b0]cc : [Lambda_b0 -> (J/psi(1S) -> mu+ mu-) (Lambda0 -> p+ pi-)]cc",
    "R"    :  "[Lambda_b0 -> (J/psi(1S) -> mu+ mu-) (^Lambda0 -> p+ pi-)]cc", 
    "H1"   :  "[Lambda_b0 -> (J/psi(1S) -> mu+ mu-) (Lambda0 -> ^p+ pi-)]cc",      
    "H2"   :  "[Lambda_b0 -> (J/psi(1S) -> mu+ mu-) (Lambda0 -> p+ ^pi-)]cc",   
    "J_psi_1S"   :  "[Lambda_b0 -> (^J/psi(1S) -> mu+ mu-) (Lambda0 -> p+ pi-)]cc"       
}

TupleToolIsoGeneric = tuple.addTupleTool("TupleToolIsoGeneric")
TupleToolIsoGeneric.Verbose = True

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


