// Include files 
#include <TCut.h>
#include <TString.h>

// local

TString placeholder;
TString Lbname[]={"Bs"};//,"Bs","Bs"};//,"Bs","Bs"};//make sure to have 1 per file
TString massname[]={"Bs_LOKI_MASS_JpsiConstr"};//,"Bs_LOKI_MASS_JpsiConstr","Bs_LOKI_MASS_JpsiConstr"};//,"Bs_LOKI_MASS_JpsiConstr"};
TString Jpsi_[]={""};//,"_","_"};//,"_"};
TCut cLbDIRA(int i,float input=0.9999){//declared here because of weirdness
  TString inputstring = Form("%f",input);
  TString place=Lbname[i]+"_DIRA_OWNPV>"+inputstring;
  TCut output=(TCut)place;
  return output;
}
TCut cLbendv(int ifile){
  TString place=Lbname[ifile]+"_ENDVERTEX_CHI2/"+Lbname[ifile]+"_ENDVERTEX_NDOF<10";
  TCut output =(TCut)place;
  return output;
}
TCut cJpsiMM(){
  TCut output= "((J_psi_1S_MM-3096.92)>-48)&&((J_psi_1S_MM-3096.92)<43)";
  return output;
}
TCut cgprob(float in=0.2){
  TString input = Form("%f",in);
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
TCut cLWM(float lo=-40, float hi=40, float mass=497.611){//mass was 497.614 before 5/5/16
  TString lostring = Form("%f",lo);
  TString histring = Form("%f",hi);
  TString massstring = Form("%f",mass);
  TString place = "(R_WM-"+massstring+"<"+lostring+")||(R_WM-"+massstring+">"+histring+")";
  TCut output=(TCut)place;
  return output;
}
TCut cLZlo(float Lvzlo=500){
  TString Lvzlostring = Form("%f",Lvzlo);
  TString place = "R_ENDVERTEX_Z>"+Lvzlostring;
  TCut output = (TCut)place;
  return output;
}
TCut cLZhi(float Lvzhi=2300){
  TString Lvzhistring = Form("%f",Lvzhi);
  TString place = "R_ENDVERTEX_Z<"+Lvzhistring;
  TCut output = (TCut)place;
  return output;
}
TCut cLFD(float LFDchi=50){
  TString LFDchistring = Form("%f",LFDchi);
  TString place = "R_FDCHI2_ORIVX>"+LFDchistring;
  TCut output = (TCut)place;
  return output;
}
TCut cLDIRATOP(double LDIRA=1){
  TString LDIRAstring = Form("%.15f",LDIRA);
  TString place = "R_DIRA_TOPPV<"+LDIRAstring;
  TCut output = (TCut)place;
  return output;
}
TCut cLDIRA(double LDIRA=0){
  TString LDIRAstring = Form("%.15f",LDIRA);
  TString place = "R_DIRA_OWNPV>"+LDIRAstring;
  TCut output = (TCut)place;
  return output;
}
TCut cLendVerrXY(double LendVerrXY){
  TString LendVerrXYstring = Form("%.15f",LendVerrXY);
  TString place = "sqrt(R_ENDVERTEX_XERR*R_ENDVERTEX_XERR+R_ENDVERTEX_YERR*R_ENDVERTEX_YERR)<"+LendVerrXYstring;
  TCut output = (TCut)place;
  return output;
}
TCut cLendVerrZ(double LendVerrZ){
  TString LendVerrZstring = Form("%.15f",LendVerrZ);
  TString place = "R_ENDVERTEX_ZERR<"+LendVerrZstring;
  TCut output = (TCut)place;
  return output;
}
TCut cLMMerr(double LMMerr){
  TString LMMerrstring = Form("%.15f",LMMerr);
  TString place = "R_MMERR<"+LMMerrstring;
  TCut output = (TCut)place;
  return output;
}
TCut cLM(double mean,double factor,double sigma){
  double lo= mean - factor*sigma;
  double hi= mean + factor*sigma;
  TString lostring = Form("%.15f",lo);
  TString histring = Form("%.15f",hi);
  TString place = "R_M>"+lostring+"&&R_M<"+histring;
  TCut output = (TCut)place;
  return output;
}
void makecuts(int ifile,TCut &cLL,TCut &cDD,TCut &ctrigger,TCut &c063016){
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
  //----these are old--//    
  // TCut cLMM1 = "(R_MM>1112)&&(R_MM<1120)";
  // TCut cLMM2 = "(R_MM>1110)&&(R_MM<1122)";
  
  // TCut cLMLL = "(R_M>1110.3518805)&&(R_M<1121.2920055)";
  // TCut cLMDD = "(R_M>1106.7300395)&&(R_M<1125.1347545)";
  //-------------------//  

  placeholder = "(J_psi_1S"+Jpsi_[ifile]+"Hlt1DiMuonHighMassDecision_TOS==1)||(J_psi_1S"+Jpsi_[ifile]+"Hlt1TrackMuonDecision_TOS==1)";
  TCut ctriggerHlt1part1=(TCut)placeholder;
  placeholder="J_psi_1S"+Jpsi_[ifile]+"Hlt1TrackAllL0Decision_TOS==1";
  TCut ctriggerHlt1part2=(TCut)placeholder;
  TCut ctriggerHlt1=ctriggerHlt1part1||ctriggerHlt1part2;
  placeholder="J_psi_1S"+Jpsi_[ifile]+"Hlt2DiMuonDetachedJPsiDecision_TOS==1";
  TCut ctriggerHlt2=(TCut)placeholder;
  ctrigger = ctriggerHlt1&&ctriggerHlt2;

  // TCut c062516LL = cLL&&cLPT(1300)&&cLFD(2660)&&cLZlo(0)&&cgprob(0.30)&&cLWM(-7.42162085,7.42162085,497.975235)&&cLMLL&&cLendVerrXY(0.54)&&cLendVerrZ(12)&&cLZhi(638)&&cLDIRA(0.999426);
  // TCut c062516DD = cDD&&cLbendv(ifile)&&cLPT(2100)&&cLFD(0)&&cLZlo(100)&&cgprob(1)&&cLWM(-15.22162671,15.22162671,497.764269)&&cLMDD&&cLendVerrXY(35)&&cLendVerrZ(195)&&cLDIRA(0.999971);
  // c062516 = (c062516LL||c062516DD)&&cLbDIRA(ifile,0.999993)&&cJpsiMM()&&ctrigger;

  // TCut c062516_noLMLL = cLL&&cLPT(1300)&&cLFD(2660)&&cLZlo(0)&&cgprob(0.30)&&cLWM(-7.42162085,7.42162085,497.975235)&&cLendVerrXY(0.54)&&cLendVerrZ(12)&&cLZhi(638)&&cLDIRA(0.999426);
  // TCut c062516_noLMDD = cDD&&cLbendv(ifile)&&cLPT(2100)&&cLFD(0)&&cLZlo(100)&&cgprob(1)&&cLWM(-15.22162671,15.22162671,497.764269)&&cLendVerrXY(35)&&cLendVerrZ(195)&&cLDIRA(0.999971);
  // c062516_noLM = (c062516_noLMLL||c062516_noLMDD)&&cLbDIRA(ifile,0.999993)&&cJpsiMM()&&ctrigger;

  // TCut c063016_noLMLL = cLL&&cLPT(1300)&&cLFD(2660)&&cLZlo(0)&&cgprob(0.30)&&cLWM(-7.42162085,7.42162085,497.975235)&&cLendVerrXY(0.54)&&cLendVerrZ(12)&&cLZhi(638)&&cLDIRA(0.999426);
  // TCut c063016_noLMDD = cDD&&cLbendv(ifile)&&cLPT(2100)&&cLFD(0)&&cLZlo(100)&&cgprob(1)&&cLWM(-15.22162671,15.22162671,497.764269)&&cLendVerrXY(35)&&cLendVerrZ(195)&&cLZhi(2300)&&cLDIRA(0.999971)&&cLMMerr(8.2);
  // c063016_noLM = (c063016_noLMLL||c063016_noLMDD)&&cLbDIRA(ifile,0.999993)&&cJpsiMM()&&ctrigger;

  TCut c063016LL = cLL&&cLPT(1300)&&cLFD(2660)&&cLZlo(0)&&cgprob(0.30)&&cLWM(-7.42162085,7.42162085,497.975235)&&cLendVerrXY(0.54)&&cLendVerrZ(12)&&cLZhi(638)&&cLDIRA(0.999426)&&cLM(1115.821289,2,2.272018);
  TCut c063016DD = cDD&&cLbendv(ifile)&&cLPT(2100)&&cLFD(0)&&cLZlo(100)&&cgprob(1)&&cLWM(-15.22162671,15.22162671,497.764269)&&cLendVerrXY(35)&&cLendVerrZ(195)&&cLZhi(2300)&&cLDIRA(0.999971)&&cLMMerr(8.2)&&cLM(1115.937550,2,3.809068);
  c063016 = (c063016LL||c063016DD)&&cLbDIRA(ifile,0.999993)&&cJpsiMM()&&ctrigger;

  // TCut cnewestLL = (cLL&&cLPT(1300)&&cLFD(2660)&&cLZlo(0)&&cgprob(0.30)&&cLWM(-7.42162085,7.42162085,497.975235)&&cLMLL);
  // TCut cnewestDD = (cDD&&cLbendv(ifile)&&cLPT(2100)&&cLFD(0)&&cLZlo(100)&&cgprob(1)&&cLWM(-15.22162671,15.22162671,497.764269)&&cLMDD);  
  // cnewest = (cnewestLL||cnewestDD)&&cLbDIRA(ifile,0.999993)&&cJpsiMM()&&ctrigger;
  
  // TCut cnewest_PV_L_LL = (cLL&&cLPT(1300)/*&&cLFD(2660)*/&&cLZlo(0)&&cgprob(0.30)&&cLWM(-7.42162085,7.42162085,497.975235)/*&&cLMLL*/);
  // TCut cnewest_PV_L_DD = (cDD/*&&cLbendv(ifile)*/&&cLPT(2100)/*&&cLFD(0)*/&&cLZlo(100)&&cgprob(1)&&cLWM(-15.22162671,15.22162671,497.764269)/*&&cLMDD*/);  
  // cnewest_PV_L = (cnewest_PV_L_LL||cnewest_PV_L_DD)/*&&cLbDIRA(ifile,0.999993)&&cJpsiMM()&&ctrigger*/;
  // TCut cnewest_PV_L_M_LL = (cLL&&cLPT(1300)/*&&cLFD(2660)*/&&cLZlo(0)&&cgprob(0.30)&&cLWM(-7.42162085,7.42162085,497.975235)&&cLMLL);
  // TCut cnewest_PV_L_M_DD = (cDD/*&&cLbendv(ifile)*/&&cLPT(2100)/*&&cLFD(0)*/&&cLZlo(100)&&cgprob(1)&&cLWM(-15.22162671,15.22162671,497.764269)&&cLMDD);  
  // cnewest_PV_L_M = (cnewest_PV_L_M_LL||cnewest_PV_L_M_DD)/*&&cLbDIRA(ifile,0.999993)&&cJpsiMM()&&ctrigger*/;
  
  // TCut motherL="abs(R_MC_MOTHER_ID)==5122";//for /\ MC
  // cnewest=cnewest&&motherL;
  // if(ifile==0){//cut tails off SMC
  //   placeholder=massname[ifile]+">5300&&"+massname[ifile]+"<5655";
  //   cnewest=cnewest&&(TCut)placeholder;
  //   // ctight=ctight&&(TCut)placeholder;
  //   // cloose=cloose&&(TCut)placeholder;
  //   TCut mlambda="abs(R_MC_MOTHER_ID)==3212";//for sigma MC
  //   cnewest=cnewest&&mlambda;
  // }else if(ifile==1){// gd mother id for /\*(1405)
  //   TCut mother1405="abs(R_MC_GD_MOTHER_ID)==13122";//for /\*(1405) MC
  //   cnewest=cnewest&&mother1405;
  // }

  // cnew_noLMcut = ((cLL&&cLWM(-16.65590481,16.65590481,497.742391)		\
  // 	   &&cLFD(10))							\
  // 	  ||(cDD&&cLWM(-16.55951271,16.55951271,498.289686)		\
  // 	     ))								\
  //   &&cLbDIRA(ifile,0.999993)&&cJpsiMM()&&ctrigger			\
  //   &&((cLL&&cLPT(1300))||(cDD&&cLPT(2100)&&cLbendv(ifile)));
  
  //cnewopt was misguided  
  // cnewopt = ((cLL&&cLWM(-2.759994,2.759994,497.742391)			\
  // 	      &&cLFD(1340)&&cLZlo(100)&&cgprob(0.2)&&cLMLL)		\
  // 	     ||(cDD&&cLWM(-21.321261,21.321261,498.289686)		\
  // 		&&cLFD(10)&&cLZlo(400)&&cgprob(0.9)&&cLMDD))		\
  //   &&cLbDIRA(ifile,0.999993)&&cJpsiMM()&&ctrigger			\
  //   &&((cLL&&cLPT(1300))||(cDD&&cLPT(2100)&&cLbendv(ifile)));

  // cbase=cLM&&((cLL&&cLWM(-16.65590481,16.65590481,497.742391)&&cLPT(1300))||(cDD&&cLWM(-16.55951271,16.55951271,498.289686)&&cLPT(2100)));
  // coptimized=((cLL&&cLPT(1300)&&cLWM(-2.759994,2.759994,497.742391))||(cDD&&cLPT(2100)&&cLWM(-21.321261,21.321261,498.289686))) \
  // 	      &&cLbDIRA(ifile,0.999993)&&cLFD()&&cJpsiMM()&&ctrigger	\
  // 	      &&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2&&cLbendv(ifile)));
  // coptimized_noLMcut=((cLL&&cLPT(1300)&&cLWM(-2.759994,2.759994,497.742391))||(cDD&&cLPT(2100)&&cLWM(-21.321261,21.321261,498.289686))) \
  // 	      &&cLbDIRA(ifile,0.999993)&&cLFD()&&cJpsiMM()&&ctrigger	\
  // 	      &&((cLL&&cgprob())||(cDD&&cLZlo()&&cLbendv(ifile)));

  //---------------old stuff--------------------//
  //cuts whose name varies by file:
  // TCut cLiming = cLPT()&&cLbDIRA(ifile)&&cLFD()&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2&&cLbendv(ifile)&&cJpsiMM()));
  // TCut cWMtot = cLiming&&cLWM();
  // TCut ctriggertot = cWMtot&&ctrigger;
  // coptimized=((cLL&&cLPT(1300))||(cDD&&cLPT(2100)))&&cLbDIRA(ifile,0.999993) \
  //   &&cLFD()&&cJpsiMM()&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2&&cLbendv(ifile))) \
  //   &&cLWM()&&ctrigger;
  // coptimized_noLMcut=((cLL&&cLPT(1300))||(cDD&&cLPT(2100)))&&cLbDIRA(ifile,0.999993) \
  //   &&cLFD()&&cJpsiMM()&&((cLL&&cgprob())||(cDD&&cLZlo()&&cLbendv(ifile))) \
  //   &&cLWM()&&ctrigger;
  // coptimized_noWM=((cLL&&cLPT(1300))||(cDD&&cLPT(2100)))&&cLbDIRA(ifile,0.999993) \
  //   &&cLFD()&&cJpsiMM()&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2&&cLbendv(ifile))) \
  //   &&ctrigger;
  // coptimized_forL=((cLL&&cLPT(1300))||(cDD&&cLPT(2100)))		\
  //   &&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2))			\
  //   &&cLWM();
  // TCut motherL="abs(R_MC_GD_MOTHER_ID)==5122";//for /\ MC
  // cgd=coptimized&&motherL;

  // coptimized_sans_WM=((cLL&&cLPT(1300))||(cDD&&cLPT(2100)))&&cLbDIRA(ifile,0.999993) \
  //   &&cLFD()&&cJpsiMM()&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2&&cLbendv(ifile))) \
  //   &&ctrigger;
  // ctight=((cLL&&cLPT(6000))||(cDD&&cLPT(7000)))&&cLbDIRA(ifile,0.999999) \
  //   &&cLFD()&&cJpsiMM()&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2&&cLbendv(ifile))) \
  //   &&cLWM()&&ctrigger;
  // cloose=                                                               \
  //   cLFD()&&cJpsiMM()&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2&&cLbendv(ifile))) \
  //   &&cLWM()&&ctrigger;
  // cold=((cLL&&cLPT(1000))||(cDD&&cLPT(1000)))&&cLbDIRA(ifile,0.9999) \
  //   &&cLFD()&&cJpsiMM()&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2&&cLbendv(ifile))) \
  //   &&cLWM()&&ctrigger;
  // coptimizedbelow=((cLL&&cLPTbelow(1300))||(cDD&&cLPTbelow(2100)))&&cLbDIRA(ifile,0.999993) \
  //   &&cLFD()&&cJpsiMM()&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2&&cLbendv(ifile))) \
  //   &&cLWM()&&ctrigger;
  // ctightbelow=((cLL&&cLPTbelow(6000))||(cDD&&cLPTbelow(7000)))&&cLbDIRA(ifile,0.999999) \
  //   &&cLFD()&&cJpsiMM()&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2&&cLbendv(ifile))) \
  //   &&cLWM()&&ctrigger;
  // coptimizednoPT=cLbDIRA(ifile,0.999993)                                \
  //   &&cLFD()&&cJpsiMM()&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2&&cLbendv(ifile))) \
  //   &&cLWM()&&ctrigger;
  // ctightnoPT=cLbDIRA(ifile,0.999999)                                    \
  //   &&cLFD()&&cJpsiMM()&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2&&cLbendv(ifile))) \
  //   &&cLWM()&&ctrigger;

  // coptimizedLPTstep=cLPTstep(lo,hi)&&cLbDIRA(ifile,0.999993)            \
  //   &&cLFD()&&cJpsiMM()&&((cLL&&cgprob()&&cLMM1)||(cDD&&cLZlo()&&cLMM2&&cLbendv(ifile))) \
  //   &&cLWM()&&ctrigger;

}  
