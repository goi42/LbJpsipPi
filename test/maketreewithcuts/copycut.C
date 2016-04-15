TCut cLbDIRA(int i,TString input="0.9999"){//declared here because of weirdness
  TString place="Bs_DIRA_OWNPV>"+input;
  TCut output=(TCut)place;
  return output;
}
TCut cgprob(TString input="0.2"){
  TString place="(H1_TRACK_GhostProb<"+input+")&&(H2_TRACK_GhostProb<"+input+")";
  TCut output=(TCut)place;
  return output;
}

void copycut(){
  //declare cuts
  TString placeholder;
  TString placeholder2;
  
  float bkgcutofflo = 5100;
  float bkgcutoffhi = 0;

  int ifile = 0;

  TCut cH1LL = "H1_TRACK_Type==3";
  TCut cH2LL = "H2_TRACK_Type==3";
  TCut cLL = cH1LL&&cH2LL;
  TCut cH1DD = "H1_TRACK_Type==5";
  TCut cH2DD = "H2_TRACK_Type==5";
  TCut cDD = cH1DD&&cH2DD;
  TCut cmupLL = "muplus_TRACK_Type==3";
  TCut cmumLL = "muminus_TRACK_Type==3";
  TCut cmupDD = "muplus_TRACK_Type==5";
  TCut cmumDD = "muminus_TRACK_Type==5";
    
  TCut cLbBKGCAT = "Lambda_b0_BKGCAT<20";
  TCut cLBKGCAT = "R_BKGCAT==0";
  TCut cpTRUEID = "H1_TRUEID==2212||H1_TRUEID==-2212";
  TCut cpiTRUEID = "H2_TRUEID==211||H2_TRUEID==-211";
  TCut cJpsiBKGCAT = "J_psi_1S_BKGCAT==0";
    
  TCut cLFD = "R_FDCHI2_ORIVX>50";
  TCut cLMM1 = "(R_MM>1112)&&(R_MM<1120)";
  TCut cLMM2 = "(R_MM>1110)&&(R_MM<1122)";
  TCut cLPT = "R_PT>1000";
  TCut cLZ = "R_ENDVERTEX_Z>500";
  TCut cJpsiMM = "((J_psi_1S_MM-3096.92)>-48)&&((J_psi_1S_MM-3096.92)<43)";
    
  TCut cLWM = "(R_WM-497.614<-40)||(R_WM-497.614>40)";
  placeholder = "(J_psi_1SHlt1DiMuonHighMassDecision_TOS==1)||(J_psi_1SHlt1TrackMuonDecision_TOS==1)";
  TCut ctriggerHlt1part1=(TCut)placeholder;
  placeholder="J_psi_1SHlt1TrackAllL0Decision_TOS==1";
  TCut ctriggerHlt1part2=(TCut)placeholder;
  TCut ctriggerHlt1=ctriggerHlt1part1||ctriggerHlt1part2;
  placeholder="J_psi_1SHlt2DiMuonDetachedJPsiDecision_TOS==1";
  TCut ctriggerHlt2=(TCut)placeholder;
  TCut ctrigger = ctriggerHlt1&&ctriggerHlt2;
  //cuts whose name varies by file:
  placeholder="Bs_ENDVERTEX_CHI2/Bs_ENDVERTEX_NDOF<10";
  TCut cLbendv=(TCut)placeholder;
  TCut cLiming = cLPT&&cLbDIRA(ifile)&&cLFD&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv&&cJpsiMM));
  TCut cWMtot = cLiming&&cLWM;
  TCut ctriggertot = cWMtot&&ctrigger;
    
  placeholder = "Bs_LOKI_MASS_JpsiConstr";
  placeholder2=Form("%f",bkgcutofflo);
  placeholder+="<"+placeholder2;
  TCut cbkglo=(TCut)placeholder;
  placeholder = "Bs_LOKI_MASS_JpsiConstr";
  placeholder2=Form("%f",bkgcutoffhi);
  placeholder+=">"+placeholder2;
  TCut cbkghi=(TCut)placeholder;
  TCut cbkg;
  if(bkgcutofflo<bkgcutoffhi) cbkg = cbkglo||cbkghi;
  if(bkgcutofflo>=bkgcutoffhi) cbkg = cbkglo;
  cout<<"cbkg = "<<cbkg<<endl;

  //the following cuts are variations on the above:
  TCut cmid = cLPT&&cLbDIRA(ifile)&&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))&&cLWM&&ctrigger;
  TCut clo=cLPT&&cLbDIRA(ifile,"0.999")&&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))&&cLWM&&ctrigger;
  TCut chiLL=cLPT&&cLbDIRA(ifile,"0.99999993")&&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut chiDD=cLPT&&cLbDIRA(ifile,"0.999999995")&&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut chi=(chiLL&&cLL)||(chiDD&&cDD);

  TCut cmidcg = cLPT&&cLbDIRA(ifile)&&cLFD&&cJpsiMM&&((cLL&&cgprob("0.1")&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut clocg=cLPT&&cLbDIRA(ifile,"0.999")&&cLFD&&cJpsiMM&&((cLL&&cgprob("0.1")&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut chiLLcg=cLPT&&cLbDIRA(ifile,"0.99999993")&&cLFD&&cJpsiMM&&((cLL&&cgprob("0.1")&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut chiDDcg=cLPT&&cLbDIRA(ifile,"0.999999995")&&cLFD&&cJpsiMM&&((cLL&&cgprob("0.1")&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut chicg=(chiLL&&cLL)||(chiDD&&cDD);

  TCut cmidcg2 = cLPT&&cLbDIRA(ifile)&&cLFD&&cJpsiMM&&((cLL&&cgprob("0.05")&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut clocg2=cLPT&&cLbDIRA(ifile,"0.999")&&cLFD&&cJpsiMM&&((cLL&&cgprob("0.05")&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut chiLLcg2=cLPT&&cLbDIRA(ifile,"0.99999993")&&cLFD&&cJpsiMM&&((cLL&&cgprob("0.05")&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut chiDDcg2=cLPT&&cLbDIRA(ifile,"0.999999995")&&cLFD&&cJpsiMM&&((cLL&&cgprob("0.05")&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut chicg2=(chiLL&&cLL)||(chiDD&&cDD);

  TCut cmidcg3 = cLPT&&cLbDIRA(ifile)&&cLFD&&cJpsiMM&&((cLL&&cgprob("0.001")&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut clocg3=cLPT&&cLbDIRA(ifile,"0.999")&&cLFD&&cJpsiMM&&((cLL&&cgprob("0.001")&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut chiLLcg3=cLPT&&cLbDIRA(ifile,"0.99999993")&&cLFD&&cJpsiMM&&((cLL&&cgprob("0.001")&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut chiDDcg3=cLPT&&cLbDIRA(ifile,"0.999999995")&&cLFD&&cJpsiMM&&((cLL&&cgprob("0.001")&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv))\
    &&cLWM&&ctrigger;
  TCut chicg3=(chiLL&&cLL)||(chiDD&&cDD);

  cout<<"cuts declared"<<endl;


  TFile *oldfile = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/subLimDVNtuples.root","READ");
  cout<<"oldfile opened"<<endl;
  TTree *oldtree = (TTree*)oldfile->Get("Lb2JpsiLTree/mytree");
  cout<<"oldtree gotten"<<endl;
  oldtree->Draw("Bs_LOKI_MASS_JpsiConstr",cmid&&"Bs_LOKI_MASS_JpsiConstr>0");
  cout<<"Bs_LOKI_MASS_JpsiConstr drawn with cuts"<<endl;
  TFile *newfile = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/test_temp.root","recreate");
  cout<<"newfile recreated"<<endl;
  TTree *newtree = oldtree->CopyTree(cmid);
  cout<<"newtree declared as copy of oldtree with cuts"<<endl;
  // newtree->SetBranchStatus("*",0);
  // newtree->SetBranchStatus("Bs_LOKI_MASS_JpsiConstr",1);
  // cout<<"branch statuses in newtree set"<<endl;
  // TFile *savefile = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/test.root","recreate");
  // cout<<"savefile recreated"<<endl;
  // TTree *savetree = newtree->CopyTree("");
  // cout<<"savetree declared as copy of newtree"<<endl;
  newtree->Print();
  cout<<"newtree printed"<<endl;
  newfile->Write();
  cout<<"newfile written"<<endl;
  delete oldfile;
  delete newfile;
  cout<<"files deleted"<<endl<<"done"<<endl;
}