#---------------------------------------------
# Author   : Bilas Pal
# Date     : 10/26/2012
# Comments : /\b->J/psi p+ K-
# Data     : Real Data
# Modified : Michael Wilkinson for /\b->J/psi p+ Pi- MC 7/9/2015
# Note     : Items marked #! differ from test/runmc.py
#---------------------------------------------
import GaudiKernel.SystemOfUnits as Units
from Gaudi.Configuration import *
from Configurables import GaudiSequencer #!
from Configurables import  DecayTreeTuple, MCDecayTreeTuple, CheckPV #!
from PhysSelPython.Wrappers import AutomaticData, Selection, SelectionSequence, DataOnDemand, MergedSelection #!
from Configurables import   CombineParticles, FilterDesktop,  OfflineVertexFitter
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
location = "Phys/FullDSTDiMuonJpsi2MuMuDetachedLine/Particles"
Jpsi2MuMu = AutomaticData(Location = location)

#----selection p+ and K- and Lambda0 -------------------------
kaons = DataOnDemand(Location = "Phys/StdNoPIDsKaons/Particles")
protons = DataOnDemand(Location = "Phys/StdNoPIDsProtons/Particles")
Lambda0LL = DataOnDemand(Location = "Phys/StdLooseLambdaLL/Particles")
Lambda0DD = DataOnDemand(Location = "Phys/StdLooseLambdaDD/Particles")
AllLambda0 = MergedSelection( "AllLambda0", RequiredSelections = [Lambda0LL, Lambda0DD])

#DaughtCut = "(TRCHI2DOF < 4.0) & (MIPCHI2DV(PRIMARY)>9) & (TRGHOSTPROB < 0.2)"
DaughtCutK = "(MIPCHI2DV(PRIMARY)>4) & (TRCHI2DOF < 4.0) & (PT>250*MeV) &  (PIDK-PIDpi>0) &  (PIDK-PIDp>-6) & (TRGHOSTPROB < 0.2)"
DaughtCutp = "(MIPCHI2DV(PRIMARY)>4) & (TRCHI2DOF < 4.0) & (PT>250*MeV) & (PIDp-PIDpi>5) & (PIDp-PIDK>0)  & (TRGHOSTPROB < 0.2)"

#----Selection /\->p+ pi-

_FilterL = FilterDesktop("_FilterL")
_FilterL.Code = "(ADMASS('Lambda0') < 30.*MeV)"\
                  "& (VFASPF(VCHI2/VDOF) < 12.0)" 

FilterL = Selection( "FilterL",
                      Algorithm          = _FilterL ,
                      RequiredSelections = [ AllLambda0 ] )

#----Selection /\b -> J/psi /\-------------------
_Lb2JpsiL = CombineParticles( "_Lb2JpsiL",
                              DecayDescriptor = "[Lambda_b0 -> J/psi(1S) Lambda0]cc",
                              CombinationCut = "AM < 6000. * MeV",
                              MotherCut       = "(VFASPF(VCHI2/VDOF)<25) & (BPVDIRA > 0.999) & (VFASPF(VCHI2PDOF) < 10) & (BPVVD > 1.5 *mm)",
#                              DaughtersCuts   = {  'K-': DaughtCutK },
                              ReFitPVs        = True )



#---- Refit vertices with Jpsi mass constraint----------------
#_Lb2JpsipK.addTool( OfflineVertexFitter() )
#_Lb2JpsipK.VertexFitters.update( { "" : "OfflineVertexFitter"} )
#_Lb2JpsipK.OfflineVertexFitter.applyDauMassConstraint = True


Lb2JpsiL  = Selection( "Lb2JpsiL",
                      Algorithm          = _Lb2JpsiL ,
                      RequiredSelections = [ Jpsi2MuMu, FilterL ] )

### Gaudi sequence
SeqLb2JpsiL = SelectionSequence("SeqLb2JpsiL", TopSelection = Lb2JpsiL)
seq = SeqLb2JpsiL.sequence()

#--------------------------------------------------------------------------
# Configure DaVinci
#-------------------------------------------------------------------------
from Configurables import DaVinci

DaVinci().appendToMainSequence( [sc.sequence() ] )   # Append the stripping selection sequence to DaVinci

from Configurables import  OfflineVertexFitter

from Configurables import  DecayTreeTuple, MCDecayTreeTuple
importOptions("Xb2JpsiXTreeMC.py")


tuple = DecayTreeTuple( "Lb2JpsiLTree" )
tuple.Inputs = [ SeqLb2JpsiL.outputLocation() ]



from PhysConf.Filters import LoKi_Filters #!
fltrs = LoKi_Filters(STRIP_Code = "(HLT_PASS_RE('StrippingFullDSTDiMuonJpsi2MuMuDetachedLineDecision'))" ) #!

from Configurables import DaVinci #!
DaVinci().Simulation   = True
DaVinci().EvtMax = -1                        # Number of events
#DaVinci().EventPreFilters = fltrs.filters('Filter') #!
DaVinci().UserAlgorithms = [ seq, tuple  ]
from Configurables import CondDB #!
DaVinci().DataType = "2012"
DaVinci().DDDBtag   = "Sim08-20130503-1" #!
DaVinci().CondDBtag = "Sim08-20130503-1-vc-md100" #!
DaVinci().TupleFile = "DVNtuples.root"
DaVinci().PrintFreq = 50000 #10000 #!
DaVinci().Lumi = False



########################################################################
MessageSvc().Format = "% F%60W%S%7W%R%T %0W%M"
from Configurables import  DaVinciInit#, GetIntegratedLuminosity #!
#DaVinciInit().OutputLevel = 6 #!
#MessageSvc().OutputLevel                  = 6
#GetIntegratedLuminosity().OutputLevel       = INFO #!
#ToolSvc().OutputLevel                     = 6
#NTupleSvc().OutputLevel                   = 6 #!




from GaudiConf import IOHelper
IOHelper().inputFiles([
'/tmp/lzhang/00029181_00000018_1.allstreams.dst'
], clear=True)

