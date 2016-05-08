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

# #--Stripping--------------------------------------------------------
# from StrippingConf.Configuration import StrippingConf, StrippingStream
# from StrippingSettings.Utils import strippingConfiguration
# from StrippingArchive.Utils import buildStreams
# from StrippingArchive import strippingArchive

# #----------------------Standard stripping20-------------------------
# stripping='stripping20'
# config  = strippingConfiguration(stripping)
# archive = strippingArchive(stripping)
# streams = buildStreams(stripping=config, archive=archive)

# #----Select my line-------------------------------------------------
# MyStream = StrippingStream("MyStream")
# MyLines = [ 'StrippingFullDSTDiMuonJpsi2MuMuDetachedLine' ]

# for stream in streams:
#     for line in stream.lines:
#         if line.name() in MyLines:
#             MyStream.appendLines( [ line ] )

# sc = StrippingConf( HDRLocation = "MyStrip", Streams = [ MyStream ] )
# #------------------------------------------------------------------------

#----selection p+ and K- -------------------------
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

### Gaudi sequence
SeqL = SelectionSequence("SeqL", TopSelection = FilterL)
seq = SeqL.sequence()

#--------------------------------------------------------------------------
# Configure DaVinci
#-------------------------------------------------------------------------
from Configurables import DaVinci

# DaVinci().appendToMainSequence( [sc.sequence() ] )   # Append the stripping selection sequence to DaVinci

from Configurables import  OfflineVertexFitter

from Configurables import  DecayTreeTuple, MCDecayTreeTuple
importOptions("Xb2JpsiXTree.py")


tuple = DecayTreeTuple( "LTree" )
tuple.Inputs = [ SeqL.outputLocation() ]



from PhysConf.Filters import LoKi_Filters
fltrs = LoKi_Filters(STRIP_Code = "(HLT_PASS_RE('StrippingFullDSTDiMuonJpsi2MuMuDetachedLineDecision'))" )

from Configurables import DaVinci
DaVinci().TupleFile = "DVNtuples.root"
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
DaVinci().PrintFreq = 10000
#For luminosity
#CondDB().LocalTags["LHCBCOND"] = ['lumi-20100825']
DaVinci().Lumi = True


########################################################################
MessageSvc().Format = "% F%60W%S%7W%R%T %0W%M"
from Configurables import  DaVinciInit, GetIntegratedLuminosity
# DaVinciInit().OutputLevel = 6
# MessageSvc().OutputLevel                  = 6
# GetIntegratedLuminosity().OutputLevel       = INFO
# ToolSvc().OutputLevel                     = 6
# NTupleSvc().OutputLevel                   = 6




#from GaudiConf import IOHelper
#IOHelper().inputFiles([
#'/tmp/lzhang/00020241_00001413_1.dimuon.dst'
#], clear=True)

