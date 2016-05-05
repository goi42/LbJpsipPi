/*
for normal operation, make sure to assign a unique ID in run_fit_mass. Also, make sure to comment out the shapes you don't want added to totalPdf and to specify the range for the nll
for quasi-normal operation, check that data_temp is getting the proper data set
*/
#include <iostream>
#include <TString.h>
#include <vector>
#include <TCut.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TPaveText.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TROOT.h>
#include <TF1.h>
#include <RooTFnPdfBinding.h>
#include "RooGaussian.h"
#include "RooChebychev.h"
#include <RooCBShape.h>
#include "RooIpatia.cxx"
#include "RooAddPdf.h"
#include "RooMinuit.h"
#include "RooHist.h"
#include "RooPlot.h"
#include "RooFitResult.h"

//local
#include "get_data_fit_mass.C"
#include "save_plot_fit_mass.C"
using namespace RooFit;

void fit_mass(TString fileN="test") {//suffix added before file extension, e.g., '.pdf'
  cout<<"fileN = "<<fileN<<endl;
  gROOT->SetBatch(kTRUE);
  gROOT->ProcessLine(".x /afs/cern.ch/user/m/mwilkins/cmtuser/src/lhcbStyle.C");  
  
  cout<<"fit_mass: Set mass and data:"<<endl;
  RooRealVar *mass = new RooRealVar("Bs_LOKI_MASS_JpsiConstr","m(J/#psi #Lambda)",4100,6100,"MeV");
  mass->setRange("bkg1",4300,4800);
  mass->setRange("bkg2",5700,5950);
  mass->setRange("bkg3",4300,5500);
  mass->setRange("bkg4",5100,5500);
  mass->setRange("1405",4220,5460);
  mass->setRange("L",5350,5950);
  mass->setRange("tail",5950,6040);
  mass->setRange("Ltail",5350,6040);
  mass->setRange("tot",4300,6040);
  cout<<"mass declared"<<endl;
  RooDataSet data_temp = get_data(mass);
  RooDataSet *data = &data_temp;
  cout<<"fit_mass: Mass and data set."<<endl;

  cout<<"fit_mass: Assign shapes:"<<endl;
  // sigma
  TFile *SMChistos= new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/histos_SMCfile_fullMC.root", "READ");
  cout<<"SMC file opened"<<endl;
  TH1F *SMCh = (TH1F*)SMChistos->Get("h00");
  cout<<"SMC hist gotten"<<endl;
  RooDataHist *SMC = new RooDataHist("SMC","1D",RooArgList(*mass),SMCh);
  cout<<"SMC hist assigned to RooDataHist"<<endl;
  RooHistPdf sigS = makeroohistpdf(SMC,mass,"sigS","#Sigma^{0} signal (RooHistPdf)");
  // /\
  // //Gaussian
  // RooRealVar mean1L("mean1L","/\\ gaus 1: mean",5621.351842,5525,5700);
  // RooRealVar sig1L("sig1L","/\\ gaus 1: sigma",8.030005,0,100);
  // RooGaussian gau1L("gau1L","#Lambda signal: gaussian 1",*mass,mean1L,sig1L);
  // RooFormulaVar mean2L("mean2L","@0",mean1L);
  // RooRealVar sig2L("sig2L","/\\ gaus 2: sigma",23.209486,0,100);
  // RooGaussian gau2L("gau2L","#Lambda signal: gaussian 2",*mass,mean2L,sig2L);
  // RooRealVar f1L("f1L","/\\ signal: fraction gaussian 1",0.827146,0,1);
  // RooAddPdf sigL("sigL","#Lambda signal (dbl gaus)",RooArgList(gau1L,gau2L),RooArgList(f1L));
  // //CB&Gaus
  // RooRealVar mean3L("mean3L","/\\ CB: mean",5621.063180,5525,5700);
  // RooRealVar sig3L("sig3L","/\\ CB: sigma",7.683292,0,100);
  // RooRealVar alphaL3("alphaL3","/\\ CB: alpha",1.524053,0,1000);
  // RooRealVar nL3("nL1","/\\ CB: n",2.598785,0,1000);
  // RooCBShape CBL("CBL","#Lambda signal: CB",*mass,mean3L,sig3L,alphaL3,nL3);
  // RooFormulaVar mean4L("mean4L","@0",mean3L);
  // RooRealVar sig4L("sig4L","/\\ gaus: sigma",14.799543,0,100);
  // RooGaussian gauL("gauL","#Lambda signal: gaussian",*mass,mean4L,sig4L);
  // RooRealVar f1L("f1L","/\\ signal: fraction CB",0.852015,0,1);
  // RooAddPdf sigL("sigL","#Lambda signal (CB & gaus)",RooArgList(CBL,gauL),RooArgList(f1L));
  // //CB
  // RooRealVar mean5L("mean5L","/\\ CB: mean",5621.063180,5525,5700);
  // RooRealVar sig5L("sig5L","/\\ CB: sigma",7.683292,0,100);
  // RooRealVar alphaL5("alphaL5","/\\ CB: alpha",1.524053,0,1000);
  // RooRealVar nL5("nL1","/\\ CB: n",2.598785,0,1000);
  // RooCBShape sigL("CBL","#Lambda signal (CB)",*mass,mean5L,sig5L,alphaL5,nL5);
  // //Gaus&bifurGaus
  // RooRealVar mean6L("mean6L","/\\ biGau: mean",5621.063180,5525,5700);
  // RooRealVar sig6L_left("sig6L_left","/\\ biGau: sigma_left",7.683292,0,100);
  // RooRealVar sig6L_right("sig6L_right","/\\ biGau: sigma_right",7.683292,0,100);
  // RooBifurGauss bigauL("bigauL","#Lambda signal: bifurcated Gaussian",*mass,mean6L,sig6L_left,sig6L_right);
  // RooFormulaVar mean7L("mean7L","@0",mean6L);
  // RooRealVar sig7L("sig7L","/\\ gaus: sigma",14.799543,0,100);
  // RooGaussian gauL("gauL","#Lambda signal: Gaussian",*mass,mean7L,sig7L);
  // RooRealVar f1L("f1L","/\\ signal: fraction bifurcated Gaussian",0.852015,0,1);
  // RooAddPdf sigL("sigL","#Lambda signal (biGaus & Gaus)",RooArgList(bigauL,gauL),RooArgList(f1L));
  //Hypatia
  RooRealVar lL("lL","/\\ Hypatia: l",-1.048729);
  RooRealVar zetaL("zetaL","/\\ Hypatia: zeta",0);
  RooRealVar fbL("fbL","/\\ Hypatia: fb",0);
  RooRealVar sigmaL("sigmaL","/\\ Hypatia: sigma",9.617338,0,100);
  RooRealVar muL("muL","/\\ Hypatia: mu",5620.000034,5525,5700);
  RooRealVar aL("aL","/\\ Hypatia: a",1.727025);
  RooRealVar nL("nL","/\\ Hypatia: n",4.661879);
  RooIpatia sigL("sigL","#Lambda signal (hypatia)",*mass,lL,zetaL,fbL,sigmaL,muL,aL,nL);
  // /\*
  // /\*(1405)
  TFile *Lst1405MChistos= new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/histos_Lst1405MC.root", "READ");
  cout<<"Lst1405MC file opened"<<endl;
  TH1F *Lst1405MCh = (TH1F*)Lst1405MChistos->Get("h00");
  cout<<"Lst1405MC hist gotten"<<endl;
  RooDataHist *Lst1405MC = new RooDataHist("Lst1405MC","1D",RooArgList(*mass),Lst1405MCh);
  cout<<"Lst1405MC hist assigned to RooDataHist"<<endl;
  RooHistPdf sigLst1405 = makeroohistpdf(Lst1405MC,mass,"sigLst1405","#Lambda*(1405) signal (RooHistPdf)");
  // RooRealVar meanLst1("mean5Lst1","/\\*(1405): mean1",5290.815782,5000,5400);
  // RooRealVar sigLst1("sigLst1","/\\*(1405): sigma1",75.880004,0,10000);
  // RooRealVar alphaLst1("alphaLst1","/\\*(1405): alpha1",0.586106,0,10000);
  // RooRealVar nLst1("nLst1","/\\*(1405): n1",126.153761,0,10000);
  // RooCBShape CBLst1405_1("CBLst1405_1","#Lambda*(1405): CB1",*mass,meanLst1,sigLst1,alphaLst1,nLst1);
  // RooRealVar meanLst2("mean5Lst2","/\\*(1405): mean2",5162.652596,5000,5400);
  // RooRealVar sigLst2("sigLst2","/\\*(1405): sigma2",115.047402,0,10000);
  // RooRealVar alphaLst2("alphaLst2","/\\*(1405): alpha2",2.872964,0,10000);
  // RooRealVar nLst2("nLst2","/\\*(1405): n2",1.998455,0,10000);
  // RooCBShape CBLst1405_2("CBLst1405_2","#Lambda*(1405): CB2",*mass,meanLst2,sigLst2,alphaLst2,nLst2);
  // RooRealVar f1Lst("f1Lst","/\\*(1405): fraction CB1",0.582193,0,1);
  // RooAddPdf sigLst1405("sigLst1405","#Lambda*(1405) (dbl CB)",RooArgList(CBLst1405_1,CBLst1405_2),RooArgList(f1Lst));
  // /\*(misc.)
  //gaussian
  RooRealVar meanLst3("meanLst3","/\\*(misc.): mean3",4998.348223,4900,5100);
  RooRealVar sigLst3("sigLst3","/\\*(misc.): sigma3",61.585037,0,100);
  RooGaussian gauLstmisc("gauLstmisc","#Lambda*(misc.) (gaussian)",*mass,meanLst3,sigLst3);
  
  // bkg
  // RooRealVar b0("b0","Background: Chebychev b0",-1.071,-10000,10000);
  RooRealVar b1("b1","Background: Chebychev b1",-1.183578,-10,-0.00000000000000000000001);
  RooRealVar b2("b2","Background: Chebychev b2",0.227144,0,10);
  RooRealVar b3("b3","Background: Chebychev b3",-0.387522,-2,2);
  RooRealVar b4("b4","Background: Chebychev b4",0.281777,-2,2);
  RooRealVar b5("b5","Background: Chebychev b5",0.187079,-2,2);
  RooRealVar b6("b6","Background: Chebychev b6",-0.015,-10000,10000);
  RooRealVar b7("b7","Background: Chebychev b7",0.012,-10000,10000);
  RooArgList bList(b1,b2);
  RooChebychev bkg("bkg","Background", *mass, bList);
  // TF1 *ep = new TF1("ep","[2]*exp([0]*x+[1]*x*x)",4300,5950);
  // ep->SetParameter(0,1);
  // ep->SetParameter(1,-1);
  // ep->SetParameter(2,2000);
  // ep->SetParName(0,"a");
  // ep->SetParName(1,"b");
  // ep->SetParName(2,"c");
  // RooRealVar a("a","Background: Coefficent of x",1,-10000,10000);
  // RooRealVar b("b","Background: Coefficent of x*x",-1,-10000,10000);
  // RooRealVar c("c","Background: Coefficent of exp()",2000,-10000,10000);
  // RooTFnPdfBinding bkg("ep","ep",ep,RooArgList(*mass,a,b));
  cout<<"fit_mass: Shapes assigned."<<endl;
  
  //number of each shape
  cout<<"fit_mass: declaring number of each shape:"<<endl;
  RooRealVar nbkg("nbkg","N bkg",2165.490249,0,100000000);
  RooRealVar nsigL("nsigL","N /\\",1689.637290,0,1000000000);
  RooRealVar nsigS("nsigS","N sigma",0.000002,0,10000000000);
  RooRealVar nsigLst1405("nsigLst1405","N /\\*(1405)",152.061617,0,10000000000);
  RooRealVar ngauLstmisc("ngauLstmisc","N /\\*(misc.)",439.812103,0,10000000000);
  RooRealVar nbkgLst("nbkgLst","N /\\*",591.828,0,1000000000);
  cout<<"fit_mass: Numbers declared."<<endl;

  //add shapes and their number to a totalPdf
  cout<<"fit_mass: adding shapes and their numbers to totalPdf:"<<endl;
  RooArgList shapes;
  RooArgList yields;
  shapes.add(sigS);       yields.add(nsigS);
  shapes.add(sigL);       yields.add(nsigL);
  shapes.add(sigLst1405); yields.add(nsigLst1405);
  shapes.add(gauLstmisc); yields.add(ngauLstmisc);
  shapes.add(bkg);        yields.add(nbkg);
  RooAddPdf totalPdf("totalPdf","totalPdf",shapes,yields);
  cout<<"fit_mass: totalPdf constructed."<<endl;

  //fit the totalPdf
  cout<<"fit_mass: Starting the fit:"<<endl;
  RooAbsReal * nll = totalPdf.createNLL(*data,Extended(kTRUE),Range("tot"));
  RooMinuit m(*nll);
  m.setVerbose(kFALSE);
  m.migrad();
  m.minos();
  m.minos();
  cout<<"fit_mass: Fit complete."<<endl;

  cout<<"fit_mass: Starting save_plot_fit_mass():"<<endl;
  save_plot_fit_mass(fileN,mass,data,totalPdf,shapes,yields);
  cout<<"save_plot_fit_mass() complete."<<endl;

  cout<<"fit_mass complete."<<endl;
}
