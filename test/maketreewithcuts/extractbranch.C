void extractbranch(){
  TFile *cutfile = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/test_temp.root","read");
  cout<<"file opened"<<endl;
  TTree *cuttree = (TTree*)cutfile->Get("mytree");
  cout<<"tree gotten"<<endl;
  cuttree->SetBranchStatus("*",0);
  cuttree->SetBranchStatus("Bs_LOKI_MASS_JpsiConstr",1);
  cout<<"branch statuses in tree set"<<endl;
  TFile *newfile = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/test.root","recreate");
  cout<<"new file recreated"<<endl;
  TTree *newtree = cuttree->CopyTree("");
  cout<<"tree copied"<<endl;
  newtree->Print();
  cout<<"tree printed"<<endl;
  newfile->Write();
  cout<<"file written"<<endl;
  cuttree->SetBranchStatus("*",1);
  cout<<"branches reactivated"<<endl;
  delete cutfile;
  delete newfile;
  cout<<"files deleted"<<endl<<"done"<<endl;
}
