import os #use this file for everything

DaVinciVersion = 'v32r2p1'
myApplication = DaVinci()
myApplication.version = DaVinciVersion
myApplication.user_release_area = '~/cmtuser'
myApplication.platform = 'x86_64-slc5-gcc46-opt'

myEnv = myApplication.getenv()
myApplication.optsfile = [File('DataXb2JpsiLK.py')]
j = Job(name='Lb2JpLData', application=myApplication, backend=Dirac())
j.backend.settings['CPUTime'] = 50000
mySplitter = SplitByFiles(filesPerJob=50)
#myData = [ 'LFN:/lhcb/LHCb/Collision11/SEMILEPTONIC.DST/00022761/0000/00022761_00001773_1.semileptonic.dst' ]
#myInputData = LHCbDataset(files = myData)
j.outputfiles = [DiracFile('DVNtuples.root')] #has to match what's in optsfile
j.inputsandbox = ['/afs/cern.ch/user/m/mwilkins/luminosity/LUT-M1M2-L0PT.txt'] #inputting lookup table for the L0pt correction
j.splitter = mySplitter
j.splitter.bulksubmit = False 
#j.inputdata = myInputData 
#j.inputdata = j.application.readInputData('../data_list/BK_LHCb_Collision11_Beam3500GeV-VeloClosed-MagUp_Real Data_Reco14_Stripping20r1_90000000_SEMILEPTONIC.DST.py') #you can uncomment these lines and comment the next one to test it
#j.inputdata = j.application.readInputData('LHCb_Collision11_Beam3500GeVVeloClosedMagDown_Real_Data_Reco14_Stripping20r1_90000000_DIMUON.DST.py')
path = "/LHCb/Collision11/Beam3500GeV-VeloClosed-MagDown/Real Data/Reco14/Stripping20r1/90000000/DIMUON.DST"
#badtcks = ['0x760037']
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
filteredFiles = []
for f in dataset.files:
    #if datasetM['Value'][f.name]['TCK'] in badtcks:
    filteredFiles.append(f)
path = "/LHCb/Collision11/Beam3500GeV-VeloClosed-MagUp/Real Data/Reco14/Stripping20r1/90000000/DIMUON.DST"
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
for f in dataset.files:
    #if datasetM['Value'][f.name]['TCK'] in badtcks:
    filteredFiles.append(f)
path = "/LHCb/Collision12/Beam4000GeV-VeloClosed-MagDown/Real Data/Reco14/Stripping20/90000000/DIMUON.DST"
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
for f in dataset.files:
        #if datasetM['Value'][f.name]['TCK'] in badtcks:
        filteredFiles.append(f)
path = "/LHCb/Collision12/Beam4000GeV-VeloClosed-MagUp/Real Data/Reco14/Stripping20/90000000/DIMUON.DST"
dataset = BKQuery(path).getDataset()
datasetM = BKQuery(path).getDatasetMetadata()
for f in dataset.files:
    #if datasetM['Value'][f.name]['TCK'] in badtcks:
    filteredFiles.append(f)
j.inputdata = filteredFiles
j.submit()
