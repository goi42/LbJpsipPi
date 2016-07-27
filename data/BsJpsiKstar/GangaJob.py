import os #use this file for everything

DaVinciVersion = 'v40r3p1'
myApplication = DaVinci()
myApplication.version = DaVinciVersion
myApplication.user_release_area = '~/cmtuser'
# myApplication.platform = 'x86_64-slc6-gcc49-opt' #'x86_64-slc5-gcc46-opt'

myEnv = myApplication.getenv()
myApplication.optsfile = [File('DataBs2JpsiKstar.py')]
j = Job(name='Bs2JpsiKstar', application=myApplication, backend=Dirac())
# j.backend.settings['CPUTime'] = 50000
mySplitter = SplitByFiles(filesPerJob=10)
j.outputfiles = [DiracFile('LimDVNtuples.root')] #has to match what's in optsfile
# j.inputfiles = [LocalFile('/afs/cern.ch/user/m/mwilkins/luminosity/LUT-M1M2-L0PT.txt')] #inputting lookup table for the L0pt correction
j.splitter = mySplitter
# j.splitter.bulksubmit = False 
path = "/LHCb/Collision11/Beam3500GeV-VeloClosed-MagDown/Real Data/Reco14/Stripping20r1/90000000/DIMUON.DST"
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
filteredFiles = []
for f in dataset.files:
    filteredFiles.append(f)
path = "/LHCb/Collision11/Beam3500GeV-VeloClosed-MagUp/Real Data/Reco14/Stripping20r1/90000000/DIMUON.DST"
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
for f in dataset.files:
    filteredFiles.append(f)
path = "/LHCb/Collision12/Beam4000GeV-VeloClosed-MagDown/Real Data/Reco14/Stripping20/90000000/DIMUON.DST"
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
for f in dataset.files:
        filteredFiles.append(f)
path = "/LHCb/Collision12/Beam4000GeV-VeloClosed-MagUp/Real Data/Reco14/Stripping20/90000000/DIMUON.DST"
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
for f in dataset.files:
    filteredFiles.append(f)
j.inputdata = filteredFiles
j.submit()
