import os, sys
#jid = sys.argv[1]
j = jobs(160)

for sj in j.subjobs:
   if sj.status != 'completed': continue
   for f in sj.outputfiles.get(DiracFile):
      if (sj.id == 510 or sj.id == 517 or sj.id == 518 or sj.id == 519):
         base_path = '/tmp/mwilkins/'
         os.makedirs(os.path.join(base_path, sj.fqid))
         f.localDir = os.path.join(base_path, sj.fqid)
         f.get()       
