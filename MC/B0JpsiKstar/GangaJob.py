import os #use this file for everything

# DaVinciVersion = 'v38r1p2'
# myApplication = DaVinci()
# myApplication.version = DaVinciVersion
# myApplication.user_release_area = '~/cmtuser'
# # myApplication.platform = 'x86_64-slc6-gcc49-opt' #'x86_64-slc5-gcc46-opt'
myApplication = GaudiExec()
myApplication.directory = "/afs/cern.ch/user/m/mwilkins/DaVinciDev_v38r1p2"


#myEnv = myApplication.getenv()
#myApplication.optsfile = [File('MCB02JpsiKstar.py')]
myApplication.options = ['MCB02JpsiKstar.py']
j = Job(name='B02JpsiKstar_MC', application=myApplication, backend=Dirac())
# j.backend.settings['CPUTime'] = 50000
mySplitter = SplitByFiles(filesPerJob=10)
j.outputfiles = [DiracFile('LimDVNtuples.root')] #has to match what's in optsfile
# j.inputfiles = [LocalFile('/afs/cern.ch/user/m/mwilkins/luminosity/LUT-M1M2-L0PT.txt')] #inputting lookup table for the L0pt correction
j.splitter = mySplitter
# j.splitter.bulksubmit = False
j.do_auto_resubmit = True 
filteredFiles = []
path = "/MC/2012/Beam4000GeV-2012-MagUp-Nu2.5-Pythia8/Sim08f/Digi13/Trig0x409f0045/Reco14a/Stripping20NoPrescalingFlagged/11144001/ALLSTREAMS.DST"
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
for f in dataset.files:
    filteredFiles.append(f)
path = "/MC/2012/Beam4000GeV-2012-MagDown-Nu2.5-Pythia8/Sim08f/Digi13/Trig0x409f0045/Reco14a/Stripping20NoPrescalingFlagged/11144001/ALLSTREAMS.DST"
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
for f in dataset.files:
    filteredFiles.append(f)
j.inputdata = filteredFiles
j.submit()
