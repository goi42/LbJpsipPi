import os #use this file for everything

# DaVinciVersion = 'v32r2p1'
# myApplication = DaVinci()
# myApplication.version = DaVinciVersion
# myApplication.user_release_area = '~/cmtuser'
# myApplication.platform = 'x86_64-slc5-gcc46-opt'

DaVinciVersion = 'v37r2p4'
myApplication = DaVinci()
myApplication.version = DaVinciVersion
myApplication.user_release_area = '~/cmtuser'
# myApplication.platform = 'x86_64-slc5-gcc46-opt'

myEnv = myApplication.getenv()
myApplication.optsfile = [File('Xb2JpsiLKMC.py')]
j = Job(name='Lb2JpLMC_plus2011', application=myApplication, backend=Dirac())
j.backend.settings['CPUTime'] = 50000
mySplitter = SplitByFiles(filesPerJob=1)
#myData = [ 'LFN:/lhcb/LHCb/Collision11/SEMILEPTONIC.DST/00022761/0000/00022761_00001773_1.semileptonic.dst' ]
#myInputData = LHCbDataset(files = myData)
j.outputfiles = [DiracFile('DVNtuples.root')] #has to match what's in optsfile
#j.inputfiles = [LocalFile('/afs/cern.ch/user/m/mwilkins/luminosity/LUT-M1M2-L0PT.txt')] #inputting lookup table for the L0pt correction
j.splitter = mySplitter
j.splitter.bulksubmit = False 
#j.inputdata = myInputData 
#j.inputdata = j.application.readInputData('../data_list/BK_LHCb_Collision11_Beam3500GeV-VeloClosed-MagUp_Real Data_Reco14_Stripping20r1_90000000_SEMILEPTONIC.DST.py') #you can uncomment these lines and comment the next one to test it
#j.inputdata = j.application.readInputData('/afs/cern.ch/user/m/mwilkins/LbJpsipPi/test/sampleDST/MC_2012_Beam4000GeV2012MagDownNu2.5Pythia6_Sim08a_Digi13_Trig0x409f0045_Reco14a_Stripping20NoPrescalingFlagged_15144103_ALLSTREAMS.DST.py')
filteredFiles = []
path = "/MC/2011/Beam3500GeV-2011-MagDown-Nu2-Pythia6/Sim08a/Digi13/Trig0x40760037/Reco14a/Stripping20r1NoPrescalingFlagged/15144103/ALLSTREAMS.DST"
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
for f in dataset.files:
    filteredFiles.append(f)
path = "/MC/2011/Beam3500GeV-2011-MagUp-Nu2-Pythia6/Sim08a/Digi13/Trig0x40760037/Reco14a/Stripping20r1NoPrescalingFlagged/15144103/ALLSTREAMS.DST"
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
for f in dataset.files:
    filteredFiles.append(f)
path = "/MC/2012/Beam4000GeV-2012-MagDown-Nu2.5-Pythia6/Sim08a/Digi13/Trig0x409f0045/Reco14a/Stripping20NoPrescalingFlagged/15144103/ALLSTREAMS.DST"
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
for f in dataset.files:
    filteredFiles.append(f)
path = "/MC/2012/Beam4000GeV-2012-MagUp-Nu2.5-Pythia6/Sim08a/Digi13/Trig0x409f0045/Reco14a/Stripping20NoPrescalingFlagged/15144103/ALLSTREAMS.DST"
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
for f in dataset.files:
    filteredFiles.append(f)
j.inputdata = filteredFiles
j.submit()
