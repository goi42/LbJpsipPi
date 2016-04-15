#-- GAUDI jobOptions generated on Tue Mar  1 14:50:11 2016
#-- Contains event types : 
#--   15144300 - 27 files - 502908 events - 120.33 GBytes


#--  Extra information about the data processing phases:


#--  Processing Pass Step-127421 

#--  StepId : 127421 
#--  StepName : Reco14c for MC - 2011 
#--  ApplicationName : Brunel 
#--  ApplicationVersion : v43r2p10 
#--  OptionFiles : $APPCONFIGOPTS/Brunel/DataType-2011.py;$APPCONFIGOPTS/Brunel/MC-WithTruth.py;$APPCONFIGOPTS/Persistency/Compression-ZLIB-1.py 
#--  DDDB : fromPreviousStep 
#--  CONDDB : fromPreviousStep 
#--  ExtraPackages : AppConfig.v3r207 
#--  Visible : Y 


#--  Processing Pass Step-126731 

#--  StepId : 126731 
#--  StepName : Stripping20r1-NoPrescalingFlagged for Sim08 
#--  ApplicationName : DaVinci 
#--  ApplicationVersion : v32r2p3 
#--  OptionFiles : $APPCONFIGOPTS/DaVinci/DV-Stripping20r1-Stripping-MC-NoPrescaling.py;$APPCONFIGOPTS/DaVinci/DataType-2011.py;$APPCONFIGOPTS/DaVinci/InputType-DST.py;$APPCONFIGOPTS/Persistency/Compression-ZLIB-1.py 
#--  DDDB : fromPreviousStep 
#--  CONDDB : fromPreviousStep 
#--  ExtraPackages : AppConfig.v3r171 
#--  Visible : Y 

from Gaudi.Configuration import * 
from GaudiConf import IOHelper
IOHelper('ROOT').inputFiles(['LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000001_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000002_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000003_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000004_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000005_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000006_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000007_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000008_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000009_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000010_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000011_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000012_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000013_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000014_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000015_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000016_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000017_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000018_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000019_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000020_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000021_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000022_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000023_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000024_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000025_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000026_2.AllStreams.dst',
'LFN:/lhcb/MC/2011/ALLSTREAMS.DST/00044207/0000/00044207_00000027_2.AllStreams.dst'
], clear=True)
