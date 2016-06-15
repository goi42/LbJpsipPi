#copied from https://lhcb.github.io/second-analysis-steps/17-switch-mass-hypo.html

# configure an algorithm to substitute the Kaon in the D0-decay by a second pion
from Configurables import SubstitutePID
subs = SubstitutePID(
    'MakeD02pipi',
    Code = "DECTREE('[D*(2010)+ -> (D0 -> K- pi+) pi+]CC')",
    # note that SubstitutePID can't handle automatic CC
    Substitutions = {
    'Charm -> (D0 -> ^K- pi+) Meson': 'pi-',
    'Charm -> (D0 -> ^K+ pi-) Meson': 'pi+'
    }
)

from PhysSelPython.Wrappers import Selection
from PhysSelPython.Wrappers import SelectionSequence
from PhysSelPython.Wrappers import DataOnDemand

# Stream and stripping line we want to use
stream = 'AllStreams'
line = 'D2hhCompleteEventPromptDst2D2RSLine'
tesLoc = '/Event/{0}/Phys/{1}/Particles'.format(stream, line)

# get the selection(s) created by the stripping
strippingSels = [DataOnDemand(Location=tesLoc)]

# create a selection using the substitution algorithm
selSub = Selection(
    'Dst2D0pi_D02pipi_Sel',
    Algorithm=subs,
    RequiredSelections=strippingSels
)

selSeq = SelectionSequence('SelSeq', TopSelection=selSub)

# Create an ntuple to capture D*+ decays from the new selection
from Configurables import DecayTreeTuple
dtt = DecayTreeTuple('TupleDstToD0pi_D0Topipi')
dtt.Inputs = [selSeq.outputLocation()]
# note the redefined decay of the D0
dtt.Decay = '[D*(2010)+ -> ^(D0 -> ^pi- ^pi+) ^pi+]CC'

# add our new selection and the tuple into the sequencer
from Configurables import GaudiSequencer, DaVinci
seq = GaudiSequencer('MyTupleSeq')
seq.Members += [selSeq.sequence()]
seq.Members += [dtt]
DaVinci().appendToMainSequence([seq])

# from previous file
from PhysConf.Filters import LoKi_Filters
fltrs = LoKi_Filters(STRIP_Code = "(HLT_PASS_RE('StrippingFullDSTDiMuonJpsi2MuMuDetachedLineDecision'))" )

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
