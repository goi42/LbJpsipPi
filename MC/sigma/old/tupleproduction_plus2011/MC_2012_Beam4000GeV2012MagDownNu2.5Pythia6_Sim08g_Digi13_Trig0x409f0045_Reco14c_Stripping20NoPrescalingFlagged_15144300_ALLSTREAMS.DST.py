#-- GAUDI jobOptions generated on Fri Feb 26 20:08:36 2016
#-- Contains event types : 
#--   15144300 - 26 files - 527728 events - 137.84 GBytes


#--  Extra information about the data processing phases:


#--  Processing Pass Step-125836 

#--  StepId : 125836 
#--  StepName : Stripping20-NoPrescalingFlagged for Sim08 - Implicit merging. 
#--  ApplicationName : DaVinci 
#--  ApplicationVersion : v32r2p1 
#--  OptionFiles : $APPCONFIGOPTS/DaVinci/DV-Stripping20-Stripping-MC-NoPrescaling.py;$APPCONFIGOPTS/DaVinci/DataType-2012.py;$APPCONFIGOPTS/DaVinci/InputType-DST.py;$APPCONFIGOPTS/Persistency/Compression-ZLIB-1.py 
#--  DDDB : fromPreviousStep 
#--  CONDDB : fromPreviousStep 
#--  ExtraPackages : AppConfig.v3r164 
#--  Visible : Y 


#--  Processing Pass Step-127420 

#--  StepId : 127420 
#--  StepName : Reco14c for MC - 2012 
#--  ApplicationName : Brunel 
#--  ApplicationVersion : v43r2p10 
#--  OptionFiles : $APPCONFIGOPTS/Brunel/DataType-2012.py;$APPCONFIGOPTS/Brunel/MC-WithTruth.py;$APPCONFIGOPTS/Persistency/Compression-ZLIB-1.py 
#--  DDDB : fromPreviousStep 
#--  CONDDB : fromPreviousStep 
#--  ExtraPackages : AppConfig.v3r207 
#--  Visible : Y 

from Gaudi.Configuration import * 
from GaudiConf import IOHelper
IOHelper('ROOT').inputFiles(['LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000001_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000002_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000003_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000004_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000005_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000006_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000007_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000008_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000009_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000010_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000011_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000012_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000013_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000014_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000015_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000016_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000017_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000018_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000019_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000020_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000021_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000022_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000023_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000024_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000025_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044332/0000/00044332_00000026_2.AllStreams.dst'
], clear=True)
