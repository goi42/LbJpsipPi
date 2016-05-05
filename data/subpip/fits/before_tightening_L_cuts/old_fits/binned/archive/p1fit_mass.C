#include <iostream>
#include <TString.h>
#include <vector>
#include <TCut.h>
#include <TFile.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TPaveText.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TROOT.h>
#include "RooGaussian.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooMinuit.h"
#include "RooDataSet.h"
#include "RooHist.h"
#include "RooPlot.h"
#include "RooFitResult.h"

//local
#include "/afs/cern.ch/user/m/mwilkins/algorithms/makeroohistpdf.C"
using namespace RooFit;

void fit_mass() {

  gROOT->SetBatch(kTRUE);

  cout<<"batch set"<<endl;

  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetTextSize(0.3);

  //open file and get histogram
  TFile *inHistos = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/histos_data.root", "READ");
  TH1F * h100 = (TH1F*)inHistos->Get("h60");
  cout<<"data histogram gotten"<<endl;
  // //unbinned
  // TFile *hastree;
  // TTree * h100;
  // hastree = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/subLimDVNtuples.root", "READ");
  // h100 = (TTree*)hastree->Get("Lb2JpsiLTree/mytree");
  // cout<<"tree gotten"<<endl;

  RooRealVar *mass = new RooRealVar("Bs_LOKI_MASS_JpsiConstr","m(#Lambda_{b})",4300,5950,"MeV");//adding range to variable 
  //instead of including ',Range(5200,5950)' in declaration of NLL
  cout<<"mass declared"<<endl;
  RooDataHist *data = new RooDataHist("data","1D",RooArgList(*mass),h100);
  // //unbinned
  // RooDataSet *data = new RooDataSet("data","1D",h100,*mass);
  cout<<"data declared"<<endl;
  
  TFile *SMChistos= new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/histos_SMCfile.root", "READ");
  cout<<"SMC file opened"<<endl;
  TH1F *SMCh = (TH1F*)SMChistos->Get("h00");
  cout<<"SMC hist gotten"<<endl;

  RooDataHist *SMC = new RooDataHist("SMC","1D",RooArgList(*mass),SMCh);
  cout<<"SMC hist assigned to RooDataHist"<<endl;
  
  // Construct Pdf Model
  // /\0
  double massL = 5625;
  double massLmin = 5525;
  double massLmax = 5700;
  //parameters from MC:
  //   chi2/nDoF: 3.08812
  //   nsig: 8247.41 +/- 91.3281
  //   nbkg: 164.63 +/- 15.3747
  //   mean1: 5614.43
  //   mean2: 5620.54
  //   sig1: 37.6844
  //   sig2: 16.5315
  //   f1: 0.149381
  //   b1: 0.328792
  //parameters from 'successful' complete data fit:
  // chi2/nDoF: 1.55694
  // nsigL: 12137.9 +/- 135.482
  // nsigS: 0.00580958 +/- 11.6125
  // nbkgLst: 20447.4 +/- 1064.13
  // nbkg: 146047 +/- 1222.49
  // yield sigma/yield lambda: 4.7863e-07 +/- 0
  //   mean1L: 5620.89
  //   mean2L: 5621.4
  //   sig1L: 12.4503
  //   sig2L: 6.55332
  //   f1L: 0.439733

  RooRealVar mean1L("mean1L","/\\0 gaus 1: mean",5620.89);
  RooRealVar sig1L("sig1L","/\\0 gaus 1: sigma",12.4503);
  RooRealVar mean2L("mean2L","/\\0 gaus 2: mean",5621.4);
  RooRealVar sig2L("sig2L","/\\0 gaus 2: sigma",6.55332);
  RooGaussian gau1L("gau1L","/\\0 signal: gaussian 1",*mass,mean1L,sig1L);
  RooGaussian gau2L("gau2L","/\\0 signal: gaussian 2",*mass,mean2L,sig2L);
  RooRealVar f1L("f1L","/\\0 signal: fraction gaus 1",0.439733);
  RooAddPdf sigL("sigL","#Lambda^{0} signal",RooArgList(gau1L,gau2L),RooArgList(f1L));
  // sigma0
  //using RooHistPdf from MC--no need to build pdf here
  // double massS = 5500;
  // double massSmin = 5300;
  // double massSmax = 5650;
  // //parameters from MC:
  // //   chi2/nDoF: 0.577763
  // //   nsig: 4208.5 +/- 65.4048
  // //   nbkg: 96.5233 +/- 11.665
  // //   mean1: 5514.79
  // //   mean2: 5573.6
  // //   mean3: 5425.09
  // //   mean4: 5430.08
  // //   sig1: 42.2251
  // //   sig2: 21.1396
  // //   sig3: 32.6071
  // //   sig4: 14.4906
  // //   f1: 0.476244
  // //   f2: 0.14076
  // //   f3: 0.426725
  // //   b1: 0.13928
  // RooRealVar mean1S("mean1S","mean1S",5514.79);
  // RooRealVar sig1S("sig1S","sig1S",42.2251);
  // RooRealVar mean2S("mean2S","mean2S",5573.6);
  // RooRealVar sig2S("sig2S","sig2S",21.1396);
  // RooRealVar mean3S("mean3S","mean3S",5425.09);
  // RooRealVar sig3S("sig3S","sig3S",32.6071);
  // RooRealVar mean4S("mean4S","mean4S",5430.08);
  // RooRealVar sig4S("sig4S","sig4S",14.4906);
  // RooGaussian gau1S("gau1S","gau1S",*mass,mean1S,sig1S);
  // RooGaussian gau2S("gau2S","gau2S",*mass,mean2S,sig2S);
  // RooGaussian gau3S("gau3S","gau3S",*mass,mean3S,sig3S);
  // RooGaussian gau4S("gau4S","gau4S",*mass,mean4S,sig4S);
  // RooRealVar f1S("f1S","gau1S_frac",0.476244);
  // RooRealVar f2S("f2S","gau2S_frac",0.14076);
  // RooRealVar f3S("f3S","gau3S_frac",0.426725);
  // RooAddPdf sigS("sigS","quadruple gaussian for #Sigma^{0}",RooArgList(gau1S,gau2S,gau3S,gau4S),RooArgList(f1S,f2S,f3S));
  RooHistPdf sigS = makeroohistpdf(SMC,mass,"sigS","#Sigma^{0} signal (RooHistPdf)");
  // /\*
  cout<<"Lst stuff"<<endl;
  double massLst = 5000;
  double massLstmin = 4900;
  double massLstmax = 5100;
  double sigmin = 0;
  double sigmax = 1000;
  //parameters from data without sigma0 fit
  //    meanCB1Lst: 4900
  //    mean1Lst: 5007.01
  //    mean2Lst: 4964.93
  //    mean3Lst: 5100
  //    sigCB1Lst: 1000
  //    sig1Lst: 62.8561
  //    sig2Lst: 306.009
  //    sig3Lst: 411.613
  //    aCB1Lst: 94.2774
  //    nCB1Lst: 0.498353
  //    fCB1Lst: 1
  //    f1Lst: 0.236176
  //    f2Lst: 1
  //or (with wider mean ranges)
  //    meanCB1Lst: 4850
  //    mean1Lst: 4850
  //    mean2Lst: 5008.4
  //    mean3Lst: 5150
  //    sigCB1Lst: 468.725
  //    sig1Lst: 1000
  //    sig2Lst: 69.4365
  //    sig3Lst: 536.278
  //    aCB1Lst: 94.2774
  //    nCB1Lst: 0.498353
  //    fCB1Lst: 1
  //    f1Lst: 1
  //    f2Lst: 0.164504
  //parameters from MC fit to 1800,1810,1820 only
  //   chi2/nDoF: 75.7146
  //   nsig: 4829 +/- 69.8231
  //   mean1: 4911.26
  //   mean2: 4700
  //   mean3: 5272.59
  //   mean4: 4700
  //   mean5: 5106.69
  //   sig1: 105.228
  //   sig2: 149.45
  //   sig3: 65.3598
  //   sig4: 201.363
  //   sig5: 104.105
  //   f1: 0.0914155
  //   f2: 2.3415e-10
  //   f3: 0.014961
  //   f4: 0.616663
  //parameters from fitting only 4300-5400 with only Lst and bkg:
  //   mean1Lst: 4927.59
  //   mean2Lst: 4917
  //   mean3Lst: 4877
  //   mean4Lst: 4989.89
  //   mean5Lst: 5008.7
  //   sig1Lst: 968.731
  //   sig2Lst: 168.046
  //   sig3Lst: 0.000953674
  //   sig4Lst: 991.222
  //   sig5Lst: 84.0258
  //   f1Lst: 0.841405
  //   f2Lst: 2.17842e-07
  //   f3Lst: 5.31118e-11
  //   f4Lst: 2.72163e-08
  //  chi2/nDoF: 1.26733
  //  nbkgLst: 24252.7 +/- 13319.9
  //  nbkg: 139062 +/- 15907.5
  //parameters from fitting only Range(4500,5400) with only Lst and bkg:
  //      /\* bkg: fraction gaus 1 = 0.000000 +/- 2.810133E-01
  //      /\* bkg: fraction gaus 2 = 0.155576 +/- 1.302214E-01
  //      /\* bkg: fraction gaus 3 = 0.000000 +/- 1.125377E-04
  //      /\* bkg: fraction gaus 4 = 0.000000 +/- 2.600439E-01
  //      /\* gaus 1: mean = 4927.590000 +/- [exact]
  //      /\* gaus 2: mean = 4917.000000 +/- [exact]
  //      /\* gaus 3: mean = 4877.000000 +/- [exact]
  //      /\* gaus 4: mean = 4989.890000 +/- [exact]
  //      /\* gaus 5: mean = 5008.700000 +/- [exact]
  //      /\* gaus 1: sigma = 968.731000 +/- [exact]
  //      /\* gaus 2: sigma = 168.046000 +/- [exact]
  //      /\* gaus 3: sigma = 0.000954 +/- [exact]
  //      /\* gaus 4: sigma = 991.222000 +/- [exact]
  //      /\* gaus 5: sigma = 84.025800 +/- [exact]
  //      Background: Chebychev b1 = -0.675000 +/- 7.017966E-03
  //      #chi^{2}/N_{DoF} = 1.217327
  //      N_{#Lambda*} = 4448.697174 +/- 1758.315180
  //      N_{bkg} = 161586.979547 +/- 1024.184484
  //      Y_{#Sigma^{0}}/Y_{#Lambda^{0}} = 1.000000E+00 +/- 5.589576E-01  
  //parameters from fitting only Range(4800,5200) with only Lst and bkg:
  //      /\* gaus 5: mean = 5001.607729 +/- 4.489537E+00
  //      /\* gaus 5: sigma = 68.195365 +/- 7.021110E+00
  //      Background: Chebychev b1 = -0.675000 +/- 2.185182E-02
  //      #chi^{2}/N_{DoF} = 1.069825
  //      N_{#Lambda*} = 3265.466965 +/- 478.740196
  //      N_{bkg} = 152458.352215 +/- 2293.380361
  //      Y_{#Sigma^{0}}/Y_{#Lambda^{0}} = 1.000000E+00 +/- 2.073336E-01
  
  // cout<<"declare arrays and lists"<<endl;
  // const int nLstgaus = 5;
  // double Lstmeansnums[nLstgaus] = { 4927.59, 4917, 4877, 4989.89, 5008.7 };
  // double Lstsigsnums[nLstgaus] = { 968.731, 168.04, 0.000953674, 991.222, 84.0258 };
  // double Lstfracnums[nLstgaus-1] = { 0.841405, 2.17842e-07, 5.31118e-11, 2.72163e-08 };
  // if(!((sizeof(Lstsigsnums)/sizeof(Lstsigsnums[0])==nLstgaus)\
  //      &&(sizeof(Lstfracnums)/sizeof(Lstfracnums[0])==nLstgaus-1)\
  //      &&(sizeof(Lstmeansnums)/sizeof(Lstmeansnums[0])==nLstgaus))){
  //   cout<<"check number of /\\* means, sigs, and fracs"<<endl;
  //   break;
  // }
  // cout<<Lstmeansnums[0]<<endl;
  // cout<<Lstsigsnums[0]<<endl;
  // RooRealVar Lstmeans[nLstgaus], Lstsigs[nLstgaus];
  // RooGaussian Lstgaussians[nLstgaus];
  // RooRealVar Lstfractions[nLstgaus];
  // RooArgList Lstgaus, Lstgaufracs;
  // cout<<"start loop"<<endl;
  // for(int i=0; i<nLstgaus; i++){
  //   cout<<"i="<<i<<endl;
  //   cout<<"setting mean and sigma"<<endl;
  //   cout<<"making strings"<<endl;
  //   TString istring = Form("%i",i+1);
  //   TString inamemean = "mean"+istring+"Lst";
  //   TString inamesig = "sig"+istring+"Lst";
  //   TString ititlemean = "/\\* gaus "+istring+": mean";
  //   TString ititlesig = "/\\* gaus "+istring+": sigma";
  //   TString inamegau = "gau"+istring+"Lst";
  //   TString ititlegau = "#Lambda* bkg: gaus"+istring;
    
  //   cout<<"filling arrays"<<endl;
  //   cout<<"Lstmeans"<<endl;
  //   Lstmeans[i] = RooRealVar(inamemean,ititlemean,Lstmeansnums[i],"MeV");
  //   cout<<"Lstsigs"<<endl;
  //   Lstsigs[i] = RooRealVar(inamesig,ititlesig,Lstsigsnums[i],"MeV");
  //   cout<<"Lstgaussians"<<endl;
  //   Lstgaussians[i] = RooGaussian(inamegau,ititlegau,*mass,Lstmeans[i],Lstsigs[i]);
  //   cout<<"putting Lstgaussians into Lstgaus"<<endl;
  //   Lstgaus.add(Lstgaussians[i]);
    
  //   cout<<"setting fractions"<<endl;
  //   if(i<=nLstgaus-1){
  //     TString inamefrac = "f"+istring+"Lst";
  //     TString ititlefrac = "/\\* bkg: fraction gaus"+istring;
  //     //Lstfractions[i].setRange(0,1);
  //     Lstfractions[i] = RooRealVar(inamefrac,ititlefrac,Lstfracnums[i]);
  //     Lstgaufracs.add(Lstfractions[i]);
  //   }
  // }
  // RooRealVar mean1Lst("mean1Lst","/\\* gaus 1: mean",4927.59,massLstmin,massLstmax);
  // RooRealVar sig1Lst("sig1Lst","/\\* gaus 1: sigma",968.731,sigmin,sigmax);
  // RooRealVar mean2Lst("mean2Lst","/\\* gaus 2: mean",4917,massLstmin,massLstmax);
  // RooRealVar sig2Lst("sig2Lst","/\\* gaus 2: sigma",168.046,sigmin,sigmax);
  // RooRealVar mean3Lst("mean3Lst","/\\* gaus 3: mean",4877,massLstmin,massLstmax);
  // RooRealVar sig3Lst("sig3Lst","/\\* gaus 3: sigma",0.000953674,sigmin,sigmax);
  // RooRealVar mean4Lst("mean4Lst","/\\* gaus 4: mean",4989.89,massLstmin,massLstmax);
  // RooRealVar sig4Lst("sig4Lst","/\\* gaus 4: sigma",991.222,sigmin,sigmax);
  RooRealVar mean5Lst("mean5Lst","/\\*: mean",5001.607729,4997.118192,5006.097266);
  RooRealVar sig5Lst("sig5Lst","/\\*: sigma",68.195365,61.174255,75.216475);
  // RooGaussian gau1Lst("gau1Lst","#Lambda* bkg: gaus1",*mass,mean1Lst,sig1Lst);
  // RooGaussian gau2Lst("gau2Lst","#Lambda* bkg: gaus2",*mass,mean2Lst,sig2Lst);
  // RooGaussian gau3Lst("gau3Lst","#Lambda* bkg: gaus3",*mass,mean3Lst,sig3Lst);
  // RooGaussian gau4Lst("gau4Lst","#Lambda* bkg: gaus4",*mass,mean4Lst,sig4Lst);
  RooGaussian bkgLst("bkgLst","#Lambda* bkg",*mass,mean5Lst,sig5Lst);
  // RooRealVar f1Lst("f1Lst","/\\* bkg: fraction gaus 1",.2,0,1);
  // RooRealVar f2Lst("f2Lst","/\\* bkg: fraction gaus 2",.2,0,1);
  // RooRealVar f3Lst("f3Lst","/\\* bkg: fraction gaus 3",.2,0,1);
  // RooRealVar f4Lst("f4L// st","/\\* bkg: fraction gaus 4",.2,0,1);
  // RooAddPdf bkgLst("bkgLst","#Lambda* bkg",RooArgList(gau1Lst,gau2Lst,gau3Lst,gau4Lst,gau5Lst), \
  //                  RooArgList(f1Lst,f2Lst,f3Lst,f4Lst));

  //Poly func BKG mass
  //from fit to range 5150,5950 (no /\*):
  // b1 = -0.626498 +/- 9.999254E-03
  //   /\0 signal: fraction gaus 1 = 0.439733 +/- [exact]
  //   /\0 gaus 1: mean = 5620.890000 +/- [exact]
  //   /\0 gaus 2: mean = 5621.400000 +/- [exact]
  //   /\0 gaus 1: sigma = 12.450300 +/- [exact]
  //   /\0 gaus 2: sigma = 6.553320 +/- [exact]
  //   #chi^{2}/N_{DoF} = 1.483072
  //   Yield #Lambda^{0} = 12150.196052 +/- 122.083405
  //   Yield #Sigma^{0} = 0.000008 +/- 19.040970
  //   N_{bkg} = 160129.006612 +/- 1248.239068
  //   Y_{#Sigma^{0}}/Y_{#Lambda^{0}} = 6.208925E-10 +/- 1.567133E-03
  //from fit to range 4300,4800 (bkg only):
  //  b1 = -0.624194 +/- 5.383318E-02
  //   #chi^{2}/N_{DoF} = 1.273357
  //   N_{bkg} = 166535.940555 +/- 3660.094522
  RooRealVar b1("b1","Background: Chebychev b1",-0.624194,-0.675,-0.55);
  RooArgList bList(b1);
  RooChebychev bkg("bkg","Background", *mass, bList);
  
  //number of each shape  
  RooRealVar nbkg("nbkg","N_{bkg}",100,0,100000000);
  RooRealVar nsigL("nsigL","Yield #Lambda^{0}",100,0,100000000);
  RooRealVar nsigS("nsigS","Yield #Sigma^{0}",100,0,100000000);
  RooRealVar nbkgLst("nbkgLst","N_{#Lambda*}",100,0,100000);

  //add shapes and their number to a totalPdf
  RooArgList shapes;
  RooArgList yields;
  shapes.add(sigL);   yields.add(nsigL);
  shapes.add(sigS);   yields.add(nsigS);
  shapes.add(bkgLst); yields.add(nbkgLst);
  shapes.add(bkg);    yields.add(nbkg);  
  RooAddPdf totalPdf("totalPdf","totalPdf",shapes,yields);

  //fit the totalPdf
  RooAbsReal * nll = totalPdf.createNLL(*data,Extended(kTRUE));//cut off edges
  RooMinuit m(*nll);
  m.setVerbose(kFALSE);
  RooFitResult *logfile = m.save("logfile","Log File");
  m.migrad();
  m.minos();        
  ofstream logfilestream;
  logfilestream.open("plots/fitlog.txt");
  logfile->printMultiline(logfilestream,100000,kTRUE);
  logfilestream.close();

  //display and save information
  ofstream textfile;//create text file to hold data
  textfile.open("plots/fit.txt");
  TString outputtext;//for useful text

  //plot things  
  RooPlot *framex = mass->frame();
  data->plotOn(framex,Binning(330),Name("Hist"),MarkerColor(kBlack),LineColor(kBlack),DataError(RooAbsData::SumW2));
  totalPdf.plotOn(framex,Name("curvetot"),LineColor(kBlue));
  RooArgSet* totalPdfComponents = totalPdf.getComponents();
  TIterator* itertPC = totalPdfComponents->createIterator();
  RooAddPdf* vartPC = (RooAddPdf*) itertPC->Next();
  vartPC = (RooAddPdf*) itertPC->Next();//skip totalPdf
  int i=0;//color index
  TLegend *leg = new TLegend(0.85, 0.5, .985, .9);  
  leg->AddEntry(framex->findObject("curvetot"),"Total PDF","l");
  while(vartPC){//loop over compotents of totalPdf
    TString vartPCtitle = vartPC->GetTitle();
    TIterator* itercompPars;//forward declare so it persists outside the if statement
    RooRealVar* varcompPars;
    if(!(vartPCtitle.Contains(":"))){//only for non-sub-shapes
      while(i==0||i==10||i==4||i==1||i==5||(i>=10&&i<=27))i++;//avoid white and blue and black and yellow and horribleness
      RooArgSet* compPars = vartPC->getParameters(data);//set of the parameters of the component the loop is on
      itercompPars = compPars->createIterator();
      varcompPars = (RooRealVar*) itercompPars->Next();
    
      while(varcompPars){//write and print mean, sig, etc. of sub-shapes
        TString vartitle = varcompPars->GetTitle();
        double varval = varcompPars->getVal();
        TString varvalstring = Form("%f",varval);
        double hi = varcompPars->getErrorHi();
        
        TString varerrorstring = "[exact]";
        if(hi!=-1){
          double lo = varcompPars->getErrorLo();
          double varerror = TMath::Max(fabs(lo),hi);
          varerrorstring = Form("%E",varerror);
        }
        
        outputtext = vartitle+" = "+varvalstring+" +/- "+varerrorstring;
        textfile<<outputtext<<endl;
        cout<<outputtext<<endl;
        
        varcompPars = (RooRealVar*) itercompPars->Next(); 
      }
      totalPdf.plotOn(framex,Name(vartPC->GetName()),LineStyle(kDashed),LineColor(i),Components(vartPC->GetName()));
      leg->AddEntry(framex->findObject(vartPC->GetName()),vartPCtitle,"l");
    
      i++;
    }
    vartPC = (RooAddPdf*) itertPC->Next();
    itercompPars->Reset();//make sure it's ready for the next vartPC
  }
  
  // Calculate chi2/ndf
  RooArgSet *floatpar = totalPdf.getParameters(data);
  int floatpars = (floatpar->selectByAttrib("Constant",kFALSE))->getSize();
  Double_t chi2 = framex->chiSquare("curvetot","Hist",floatpars);
  TString chi2string = Form("%f",chi2);
  //create text box to list important parameters on the plot
  TPaveText* txt = new TPaveText(0.1,0.5,0.7,0.9,"NBNDC");
  txt->SetTextSize(0.04);
  txt->SetTextColor(kBlack);
  txt->SetBorderSize(0);
  txt->SetFillColor(0);
  txt->SetFillStyle(0);
  outputtext = "#chi^{2}/N_{DoF} = "+chi2string;
  cout<<outputtext<<endl;
  textfile<<outputtext<<endl;
  txt->AddText(outputtext);
  
  // Print stuff
  TIterator* iteryields =  yields.createIterator();
  RooRealVar* varyields = (RooRealVar*) iteryields->Next();//only inherits things from TObject unless class specified
  vector<double> Y, E;//holds yields and associated errors
  vector<TString> YS, ES;//holds strings of the corresponding yields
  int j=0;//count vector position
  int jS, jL;;//these hold the position of the S and L results
  while(varyields){//loop over yields
    TString varname = varyields->GetName();
    TString vartitle = varyields->GetTitle();
    double varval = varyields->getVal();
    Y.push_back(varval);
    double lo = varyields->getErrorLo();
    double hi = varyields->getErrorHi();
    E.push_back(TMath::Max(fabs(lo),hi));
    YS.push_back(Form("%f",Y[j]));
    ES.push_back(Form("%f",E[j]));
  
    if(varname=="nsigS") jS=j;
    if(varname=="nsigL") jL=j;
    
    outputtext = vartitle+" = "+YS[j]+" +/- "+ES[j];
    cout<<outputtext<<endl;
    textfile<<outputtext<<endl;
    txt->AddText(outputtext);
    
    varyields = (RooRealVar*) iteryields->Next();
    j++;
  } 
  //S/L
  double result = Y[jS]/Y[jL];
  double E_result = TMath::Abs(result)*sqrt(pow(E[jS]/Y[jS],2)+pow(E[jL]/Y[jL],2));
  TString resultstring = Form("%E",result);
  TString E_resultstring = Form("%E",E_result);
  outputtext = "Y_{#Sigma^{0}}/Y_{#Lambda^{0}} = "+resultstring+" +/- "+E_resultstring;
  cout<<outputtext<<endl;
  textfile<<outputtext<<endl;
  txt->AddText(outputtext);
  
  // Create canvas and pads, set style
  TCanvas *c1 = new TCanvas("c1","data fits",1200,800);
  TPad *pad1 = new TPad("pad1","pad1",0.0,0.3,1.0,1.0);
  TPad *pad2 = new TPad("pad2","pad2",0.0,0.0,1.0,0.3);
  pad1->SetBottomMargin(0);
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.5);
  pad2->SetBorderMode(0);
  pad1->SetBorderMode(0);
  c1->SetBorderMode(0);
  pad1->Draw();
  pad2->Draw();
  pad1->cd();
  framex->SetMinimum(0.0001);

  framex->addObject(leg);//add legend to frame
  framex->addObject(txt);//add text to frame

  gPad->SetTopMargin(0.06);
  //pad1->SetLogy();
  pad1->Range(4100,0,6100,0.0005);
  pad1->Update();
  framex->Draw();

  // Pull distribution
  RooPlot *framex2 = mass->frame();
  RooHist* hpull = framex->pullHist("Hist","curvetot");
  framex2->addPlotable(hpull,"P");
  hpull->SetLineColor(kBlack);
  hpull->SetMarkerColor(kBlack);
  framex2->SetTitle(0);
  framex2->GetYaxis()->SetTitle("Pull");
  framex2->GetYaxis()->SetTitleSize(0.15);
  framex2->GetYaxis()->SetLabelSize(0.15);
  framex2->GetXaxis()->SetTitleSize(0.2);
  framex2->GetXaxis()->SetLabelSize(0.15);
  framex2->GetYaxis()->CenterTitle();
  framex2->GetYaxis()->SetTitleOffset(0.45);
  framex2->GetXaxis()->SetTitleOffset(1.1);
  framex2->GetYaxis()->SetNdivisions(505);
  framex2->GetYaxis()->SetRangeUser(-8.8,8.8);
  pad2->cd();
  framex2->Draw();

  c1->cd();

  c1->Print("plots/fit.pdf");
  c1->SaveAs("plots/fit.C");
  textfile.close();
                          }
