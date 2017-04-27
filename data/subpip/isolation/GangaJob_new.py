import os #use this file for everything

# DaVinciVersion = 'v40r3p1'
# myApplication = DaVinci()
# myApplication.version = DaVinciVersion
# myApplication.user_release_area = '~/cmtuser'
# # myApplication.platform = 'x86_64-slc6-gcc49-opt' #'x86_64-slc5-gcc46-opt'
myApplication = GaudiExec()
myApplication.directory = "/afs/cern.ch/user/m/mwilkins/LbJpsipPi/data/subpip/isolation/DaVinciDev_v36r1p4"
myApplication.platform = 'x86_64-slc6-gcc48-opt'

# myEnv = myApplication.getenv()
# myApplication.optsfile = [File('DataXb2JpsiLK.py')]

paths = ["/LHCb/Collision11/Beam3500GeV-VeloClosed-MagDown/Real Data/Reco14/Stripping21r1/90000000/DIMUON.DST","/LHCb/Collision11/Beam3500GeV-VeloClosed-MagUp/Real Data/Reco14/Stripping21r1/90000000/DIMUON.DST","/LHCb/Collision12/Beam4000GeV-VeloClosed-MagDown/Real Data/Reco14/Stripping21/90000000/DIMUON.DST","/LHCb/Collision12/Beam4000GeV-VeloClosed-MagUp/Real Data/Reco14/Stripping21/90000000/DIMUON.DST"]

for path in paths:
    filteredFiles = []
    dataset = BKQuery(path).getDataset()
    for f in dataset.files:
        filteredFiles.append(f)
    
    j = Job(backend=Dirac(),name="Lb_str21"+"_"+path.split("Collision")[1].split("/")[0]+"_"+path.split("Mag")[1].split("/")[0]) #add _year_polarity to the job name
    # j.backend.settings['CPUTime'] = 50000
    mySplitter = SplitByFiles(filesPerJob=10)
    j.outputfiles = [DiracFile('LimDVNtuples.root')] #has to match what's in optsfile
    # j.inputfiles = [LocalFile('/afs/cern.ch/user/m/mwilkins/luminosity/LUT-M1M2-L0PT.txt')] #inputting lookup table for the L0pt correction
    j.splitter = mySplitter
    # j.splitter.bulksubmit = False 

    j.inputdata = filteredFiles
    optsfilename = 'DataXb2JpsiLK'+"_"+path.split("Collision")[1].split("/")[0]+'.py' 
    myApplication.optsfile = [File(optsfilename)]
    j.application=myApplication
    j.submit()
