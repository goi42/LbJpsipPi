#-- GAUDI jobOptions generated on Fri Feb 26 21:58:47 2016
#-- Contains event types : 
#--   15144300 - 27 files - 506395 events - 132.53 GBytes


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
IOHelper('ROOT').inputFiles(['LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000001_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000002_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000003_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000004_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000005_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000006_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000007_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000008_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000009_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000010_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000011_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000012_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000013_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000014_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000015_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000016_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000017_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000018_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000019_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000020_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000021_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000022_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000023_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000024_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000025_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000026_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00044330/0000/00044330_00000027_2.AllStreams.dst'
], clear=True)
FileCatalog().Catalogs += [ 'xmlcatalog_file:./pool_xml_catalog.xml' ]
