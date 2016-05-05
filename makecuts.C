// Include files 
#include <TCut.h>
#include <TString.h>

// local

TString placeholder;
TString Lbname[]={"Bs","Bs","Bs"};//make sure to have 1 per file
TString massname[]={"Bs_LOKI_MASS_JpsiConstr","Bs_LOKI_MASS_JpsiConstr","Bs_LOKI_MASS_JpsiConstr"};
TString Jpsi_[]={"","_","_"};//,"_",""};
TCut cLbDIRA(int i,float input=0.9999){//declared here because of weirdness
  TString inputstring = Form("%f",input);
  TString place=Lbname[i]+"_DIRA_OWNPV>"+inputstring;
  TCut output=(TCut)place;
  return output;
}
TCut cgprob(TString input="0.2"){
  TString place="(H1_TRACK_GhostProb<"+input+")&&(H2_TRACK_GhostProb<"+input+")";
  TCut output=(TCut)place;
  return output;
}  
TCut cLPT(float input=1000){
  TString inputstring = Form("%f",input);
  TString place = "R_PT>"+inputstring;
  TCut output=(TCut)place;
  return output;
}
TCut cLPTbelow(float input=1000){
  TString inputstring = Form("%f",input);
  TString place = "R_PT<"+inputstring;
  TCut output=(TCut)place;
  return output;
}
TCut cLPTstep(float lo, float hi){
  TString lostring = Form("%f",lo);
  TString histring = Form("%f",hi);
  TString place = "R_PT>="+lostring+"&&R_PT<"+histring;
  TCut output=(TCut)place;
  return output;
}
TCut cLWM(float lo=-40, float hi=40){
  TString lostring = Form("%f",lo);
  TString histring = Form("%f",hi);
  TString place = "(R_WM-497.611<"+lostring+")||(R_WM-497.611>"+histring+")";//was 497.614 before 5/5/16
  TCut output=(TCut)place;
  return output;
}
void makecuts(int ifile,TCut &cLL,TCut &cDD,TCut &coptimized_noWM){
  TCut cH1LL = "H1_TRACK_Type==3";
  TCut cH2LL = "H2_TRACK_Type==3";
  cLL = cH1LL&&cH2LL;
  TCut cH1DD = "H1_TRACK_Type==5";
  TCut cH2DD = "H2_TRACK_Type==5";
  cDD = cH1DD&&cH2DD;
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
  TCut cLZ = "R_ENDVERTEX_Z>500";
  TCut cJpsiMM = "((J_psi_1S_MM-3096.92)>-48)&&((J_psi_1S_MM-3096.92)<43)";
    
  placeholder = "(J_psi_1S"+Jpsi_[ifile]+"Hlt1DiMuonHighMassDecision_TOS==1)||(J_psi_1S"+Jpsi_[ifile]+"Hlt1TrackMuonDecision_TOS==1)";
  TCut ctriggerHlt1part1=(TCut)placeholder;
  placeholder="J_psi_1S"+Jpsi_[ifile]+"Hlt1TrackAllL0Decision_TOS==1";
  TCut ctriggerHlt1part2=(TCut)placeholder;
  TCut ctriggerHlt1=ctriggerHlt1part1||ctriggerHlt1part2;
  placeholder="J_psi_1S"+Jpsi_[ifile]+"Hlt2DiMuonDetachedJPsiDecision_TOS==1";
  TCut ctriggerHlt2=(TCut)placeholder;
  TCut ctrigger = ctriggerHlt1&&ctriggerHlt2;
  //cuts whose name varies by file:
  placeholder=Lbname[ifile]+"_ENDVERTEX_CHI2/"+Lbname[ifile]+"_ENDVERTEX_NDOF<10";
  TCut cLbendv=(TCut)placeholder;
  TCut cLiming = cLPT()&&cLbDIRA(ifile)&&cLFD&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv&&cJpsiMM));
  TCut cWMtot = cLiming&&cLWM();
  TCut ctriggertot = cWMtot&&ctrigger;

  // coptimized=((cLL&&cLPT(1300))||(cDD&&cLPT(2100)))&&cLbDIRA(ifile,0.999993) \
  //   &&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv)) \
  //   &&cLWM()&&ctrigger;
  coptimized_noWM=((cLL&&cLPT(1300))||(cDD&&cLPT(2100)))&&cLbDIRA(ifile,0.999993) \
    &&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv)) \
    &&ctrigger;
  // coptimized_forL=((cLL&&cLPT(1300))||(cDD&&cLPT(2100)))		\
  //   &&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2))			\
  //   &&cLWM();
  // TCut motherL="abs(R_MC_MOTHER_ID)==5122";//for /\ MC
  // cgd=coptimized&&motherL;
  // TCut motherL="abs(R_MC_GD_MOTHER_ID)==5122";//for /\ MC
  // cgd=coptimized&&motherL;
  // if(ifile==0){//cut tails off SMC
  //   placeholder=massname[ifile]+">5300&&"+massname[ifile]+"<5655";
  //   coptimized=coptimized&&(TCut)placeholder;
  //   // ctight=ctight&&(TCut)placeholder;
  //   // cloose=cloose&&(TCut)placeholder;
  // }
  // TCut mlambda="abs(R_MC_MOTHER_ID)==3212";//for sigma MC
  // cgd=coptimized&&mlambda;
  // TCut mother1405="abs(R_MC_GD_MOTHER_ID)==13122";//for /\*(1405) MC
  // cgd=coptimized&&mother1405;

  // coptimized_sans_WM=((cLL&&cLPT(1300))||(cDD&&cLPT(2100)))&&cLbDIRA(ifile,0.999993) \
  //   &&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv)) \
  //   &&ctrigger;
  // ctight=((cLL&&cLPT(6000))||(cDD&&cLPT(7000)))&&cLbDIRA(ifile,0.999999) \
  //   &&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv)) \
  //   &&cLWM()&&ctrigger;
  // cloose=                                                               \
  //   cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv)) \
  //   &&cLWM()&&ctrigger;
  // cold=((cLL&&cLPT(1000))||(cDD&&cLPT(1000)))&&cLbDIRA(ifile,0.9999) \
  //   &&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv)) \
  //   &&cLWM()&&ctrigger;
  // coptimizedbelow=((cLL&&cLPTbelow(1300))||(cDD&&cLPTbelow(2100)))&&cLbDIRA(ifile,0.999993) \
  //   &&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv)) \
  //   &&cLWM()&&ctrigger;
  // ctightbelow=((cLL&&cLPTbelow(6000))||(cDD&&cLPTbelow(7000)))&&cLbDIRA(ifile,0.999999) \
  //   &&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv)) \
  //   &&cLWM()&&ctrigger;
  // coptimizednoPT=cLbDIRA(ifile,0.999993)                                \
  //   &&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv)) \
  //   &&cLWM()&&ctrigger;
  // ctightnoPT=cLbDIRA(ifile,0.999999)                                    \
  //   &&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv)) \
  //   &&cLWM()&&ctrigger;

  // coptimizedLPTstep=cLPTstep(lo,hi)&&cLbDIRA(ifile,0.999993)            \
  //   &&cLFD&&cJpsiMM&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZ&&cLMM2&&cLbendv)) \
  //   &&cLWM()&&ctrigger;

}  
