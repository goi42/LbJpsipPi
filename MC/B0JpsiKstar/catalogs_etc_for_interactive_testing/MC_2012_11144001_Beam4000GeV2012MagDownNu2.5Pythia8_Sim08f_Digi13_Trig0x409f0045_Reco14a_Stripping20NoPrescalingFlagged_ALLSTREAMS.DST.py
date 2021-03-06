#-- GAUDI jobOptions generated on Thu Sep 22 16:13:44 2016
#-- Contains event types : 
#--   11144001 - 216 files - 4435958 events - 1302.90 GBytes


#--  Extra information about the data processing phases:


#--  Processing Pass Step-124834 

#--  StepId : 124834 
#--  StepName : Reco14a for MC 
#--  ApplicationName : Brunel 
#--  ApplicationVersion : v43r2p7 
#--  OptionFiles : $APPCONFIGOPTS/Brunel/DataType-2012.py;$APPCONFIGOPTS/Brunel/MC-WithTruth.py;$APPCONFIGOPTS/Persistency/Compression-ZLIB-1.py 
#--  DDDB : fromPreviousStep 
#--  CONDDB : fromPreviousStep 
#--  ExtraPackages : AppConfig.v3r164 
#--  Visible : Y 


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

from Gaudi.Configuration import * 
from GaudiConf import IOHelper
IOHelper('ROOT').inputFiles(['LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000001_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000002_2.AllStreams.dst',
'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000003_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000004_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000005_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000006_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000007_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000008_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000009_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000010_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000012_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000013_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000014_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000015_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000016_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000017_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000018_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000019_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000021_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000022_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000023_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000024_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000025_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000026_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000027_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000028_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000029_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000030_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000031_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000032_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000033_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000034_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000035_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000036_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000037_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000038_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000040_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000041_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000042_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000043_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000044_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000045_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000046_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000047_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000048_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000049_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000050_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000051_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000052_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000053_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000054_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000055_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000056_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000057_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000058_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000059_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000060_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000061_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000062_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000064_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000065_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000066_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000067_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000068_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000070_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000072_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000073_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000074_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000075_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000077_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000078_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000079_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000080_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000081_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000082_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000083_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000084_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000085_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000086_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000087_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000089_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000090_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000092_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000095_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000096_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000097_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000098_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000099_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000102_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000103_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000104_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000105_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000106_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000107_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000108_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000109_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000110_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000111_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000112_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000113_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000114_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000115_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000117_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000118_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000119_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000120_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000122_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000124_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000127_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000128_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000129_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000131_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000132_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000133_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000134_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000135_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000136_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000138_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000139_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000140_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000141_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000142_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000143_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000145_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000146_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000147_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000148_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000149_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000150_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000151_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000152_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000153_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000155_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000156_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000157_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000158_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000159_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000160_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000161_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000162_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000163_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000164_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000166_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000167_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000168_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000169_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000170_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000171_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000172_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000173_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000174_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000175_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000177_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000178_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000179_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000180_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000181_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000182_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000183_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000184_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000185_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000186_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000187_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000188_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000189_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000190_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000193_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000194_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000195_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000196_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000197_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000198_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000199_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000200_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000201_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000202_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000205_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000206_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000207_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000208_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000209_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000210_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000211_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000212_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000213_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000214_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000215_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000216_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000217_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000218_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000219_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000220_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000221_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000222_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000223_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000224_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000225_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000226_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000227_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000228_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000229_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000230_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000231_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000233_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000240_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000241_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000242_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000243_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000244_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000246_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000247_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000249_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000251_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000252_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000253_2.AllStreams.dst',
# 'LFN:/lhcb/MC/2012/ALLSTREAMS.DST/00042094/0000/00042094_00000255_2.AllStreams.dst'
], clear=True)
