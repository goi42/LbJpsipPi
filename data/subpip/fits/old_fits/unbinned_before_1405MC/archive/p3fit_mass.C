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
#include <TF1.h>
#include <RooTFnPdfBinding.h>
#include "RooGaussian.h"
#include "RooChebychev.h"
#include <RooCBShape.h>
#include "RooAddPdf.h"
#include "RooMinuit.h"
#include "RooDataSet.h"
#include "RooHist.h"
#include "RooPlot.h"
#include "RooFitResult.h"

//local
#include "/afs/cern.ch/user/m/mwilkins/algorithms/makeroohistpdf.C"
using namespace RooFit;

void fit_mass(TString fileN="") {//suffix added before file extension, e.g., '.pdf'
  TString placeholder;//to add strings before using them, e.g., for saving text files
  gROOT->SetBatch(kTRUE);
  gROOT->ProcessLine(".x /afs/cern.ch/user/m/mwilkins/cmtuser/src/lhcbStyle.C");
  
  // gStyle->SetPadTickX(1);
  // gStyle->SetPadTickY(1);
  // gStyle->SetPadLeftMargin(0.15);
  // gStyle->SetTextSize(0.3);

  // //open file and get histogram
  // TFile *inHistos = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/histos_data.root", "READ");
  // TH1F * h100 = (TH1F*)inHistos->Get("h70");
  // cout<<"data histogram gotten"<<endl;
  //unbinned
  TFile *hastree = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/cutfile_Optimized.root", "READ");
  TTree * h100 = (TTree*)hastree->Get("mytree");
  cout<<"tree gotten"<<endl;
  TFile *SMChistos= new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/histos_SMCfile_fullMC.root", "READ");
  cout<<"SMC file opened"<<endl;
  TH1F *SMCh = (TH1F*)SMChistos->Get("h00");
  cout<<"SMC hist gotten"<<endl;

  RooRealVar *mass = new RooRealVar("Bs_LOKI_MASS_JpsiConstr","m(J/#psi #Lambda)",4100,6100,"MeV");
  mass->setRange("bkg1",4300,4800);
  mass->setRange("bkg2",5700,5950);
  mass->setRange("bkg3",4300,5500);
  mass->setRange("bkg4",5100,5500);
  mass->setRange("L",5350,5950);
  mass->setRange("tot",4300,5950);
  cout<<"mass declared"<<endl;
  // RooDataHist *data = new RooDataHist("data","1D",RooArgList(*mass),h100);
  //unbinned
  RooDataSet *data = new RooDataSet("data","1D",h100,*mass);
  cout<<"data declared"<<endl;

  RooDataHist *SMC = new RooDataHist("SMC","1D",RooArgList(*mass),SMCh);
  cout<<"SMC hist assigned to RooDataHist"<<endl;
  
  // Construct Pdf Model
  // /\0
  //gaussian
  RooRealVar mean1L("mean1L","/\\ gaus 1: mean",5621.103095,5525,5700);
  RooRealVar sig1L("sig1L","/\\ gaus 1: sigma",6.898126,0,100);
  RooGaussian gau1L("gau1L","#Lambda signal: gaussian 1",*mass,mean1L,sig1L);
  RooFormulaVar mean2L("mean2L","@0",mean1L);
  RooRealVar sig2L("sig2L","/\\ gaus 2: sigma",14.693117,0,100);
  RooGaussian gau2L("gau2L","#Lambda signal: gaussian 2",*mass,mean2L,sig2L);
  RooRealVar f1L("f1L","/\\ signal: fraction gaussian 1",0.748776,0,1);
  RooAddPdf sigL("sigL","#Lambda signal",RooArgList(gau1L,gau2L),RooArgList(f1L));
  // //CB
  // RooRealVar mean3L("mean3L","/\\ CB: mean",5621.001,5525,5700);
  // RooRealVar sig3L("sig3L","/\\ CB: sigma",5.161,0,100);
  // RooRealVar alphaL3("alphaL3","/\\ CB: alpha",2.077,0,1000);
  // RooRealVar nL3("nL1","/\\ CB: n",0.286,0,1000);
  // RooCBShape CBL("CBL","#Lambda signal: CB",*mass,mean3L,sig3L,alphaL3,nL3);
  // RooRealVar mean4L("mean4L","/\\ gaus: mean",5621.804,5525,5700);
  // RooRealVar sig4L("sig4L","/\\ gaus: sigma",10.819,0,100);
  // RooGaussian gauL("gauL","#Lambda signal: gaussian",*mass,mean4L,sig4L);
  // RooRealVar f1L("f1L","/\\ signal: fraction CB",0.578,0,1);
  // RooAddPdf sigL("sigL","#Lambda signal",RooArgList(CBL,gauL),RooArgList(f1L));

  // sigma0
  //using RooHistPdf from MC--no need to build pdf here
  RooHistPdf sigS = makeroohistpdf(SMC,mass,"sigS","#Sigma^{0} signal (RooHistPdf)");
  // /\*
  cout<<"Lst stuff"<<endl;
  RooRealVar meanLst1("meanLst1","/\\*(misc.): mean1",5011.031237,4900,5100);
  RooRealVar sigLst1("sigLst1","/\\*(misc.): sigma1",70.522092,0,100);
  RooRealVar meanLst2("mean5Lst2","/\\*(1405): mean2",5245.261703,5100,5350);
  RooRealVar sigLst2("sigLst2","/\\*(1405): sigma2",64.564763,0,100);
  RooRealVar alphaLst2("alphaLst2","/\\*(1405): alpha2",29.150301);
  RooRealVar nLst2("nLst2","/\\*(1405): n2",4.615817,0,50);
  RooGaussian gauLst1("gauLst1","#Lambda*(misc.), gaus",*mass,meanLst1,sigLst1);
  RooCBShape gauLst2("gauLst2","#Lambda*(1405), CB",*mass,meanLst2,sigLst2,alphaLst2,nLst2);
  // RooRealVar fLst1("fLst1","/\\* bkg: fraction gaus 1",0.743,0,1);
  // RooAddPdf bkgLst("bkgLst","#Lambda* signal",RooArgList(gauLst1,gauLst2),RooArgList(fLst1));
  
  //Poly func BKG mass
  // RooRealVar b0("b0","Background: Chebychev b0",-1.071,-10000,10000);
  RooRealVar b1("b1","Background: Chebychev b1",-1.323004,-10,-0.00000000000000000000001);
  RooRealVar b2("b2","Background: Chebychev b2",0.145494,0,10);
  RooRealVar b3("b3","Background: Chebychev b3",-0.316,-10000,10000);
  RooRealVar b4("b4","Background: Chebychev b4",0.102,-10000,10000);
  RooRealVar b5("b5","Background: Chebychev b5",0.014,-10000,10000);
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
  
  //number of each shape  
  RooRealVar nbkg("nbkg","N bkg",2165.490249,0,100000000);
  RooRealVar nsigL("nsigL","N /\\",1689.637290,0,1000000000);
  RooRealVar nsigS("nsigS","N sigma",0.000002,0,10000000000);
  RooRealVar ngauLst1("ngauLst1","N /\\*(misc.)",439.812103,0,10000000000);
  RooRealVar ngauLst2("ngauLst2","N /\\*(1405)",152.061617,0,10000000000);
  RooRealVar nbkgLst("nbkgLst","N /\\*",591.828,0,1000000000);

  //add shapes and their number to a totalPdf
  RooArgList shapes;
  RooArgList yields;
  shapes.add(sigL);    yields.add(nsigL);
  shapes.add(sigS);    yields.add(nsigS);
  // shapes.add(bkgLst);  yields.add(nbkgLst);
  shapes.add(gauLst1); yields.add(ngauLst1);
  shapes.add(gauLst2); yields.add(ngauLst2);
  shapes.add(bkg);     yields.add(nbkg);
  RooAddPdf totalPdf("totalPdf","totalPdf",shapes,yields);

  //fit the totalPdf
  RooAbsReal * nll = totalPdf.createNLL(*data,Extended(kTRUE),Range("tot"));
  RooMinuit m(*nll);
  m.setVerbose(kFALSE);
  m.migrad();
  m.minos();
  m.minos();

  //display and save information
  ofstream textfile;//create text file to hold data
  placeholder = "plots/fit"+fileN+".txt";
  textfile.open(placeholder);
  TString outputtext;//for useful text

  //plot things  
  RooPlot *framex = mass->frame();
  framex->GetYaxis()->SetTitle("Events/(5 MeV)");
  data->plotOn(framex,Name("Hist"),MarkerColor(kBlack),LineColor(kBlack),DataError(RooAbsData::SumW2));
  totalPdf.plotOn(framex,Name("curvetot"),LineColor(kBlue));
  RooArgSet* totalPdfComponents = totalPdf.getComponents();
  TIterator* itertPC = totalPdfComponents->createIterator();
  RooAddPdf* vartPC = (RooAddPdf*) itertPC->Next();
  vartPC = (RooAddPdf*) itertPC->Next();//skip totalPdf
  int i=0;//color index
  TLegend *leg = new TLegend(0.2, 0.02, .4, .42);  
  leg->SetTextSize(0.06);
  leg->AddEntry(framex->findObject("curvetot"),"Total PDF","l");
  while(vartPC){//loop over compotents of totalPdf
    TString vartPCtitle = vartPC->GetTitle();
    TIterator* itercompPars;//forward declare so it persists outside the if statement
    RooRealVar* varcompPars;
    if(!(vartPCtitle.Contains(":")||vartPCtitle.Contains("@"))){//only for non-sub-shapes
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
  // TPaveText* txt = new TPaveText(0.1,0.5,0.7,0.9,"NBNDC");
  // txt->SetTextSize(0.06);
  // txt->SetTextColor(kBlack);
  // txt->SetBorderSize(0);
  // txt->SetFillColor(0);
  // txt->SetFillStyle(0);
  outputtext = "#chi^{2}/N_{DoF} = "+chi2string;
  cout<<outputtext<<endl;
  textfile<<outputtext<<endl;
  // txt->AddText(outputtext);
  
  // Print stuff
  TIterator* iteryields =  yields.createIterator();
  RooRealVar* varyields = (RooRealVar*) iteryields->Next();//only inherits things from TObject unless class specified
  vector<double> Y, E;//holds yields and associated errors
  vector<TString> YS, ES;//holds strings of the corresponding yields
  int j=0;//count vector position
  int jS=0, jL=0;//these hold the position of the S and L results;initialized in case there is no nsigS or nsigL
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
    //txt->AddText(outputtext);
    
    varyields = (RooRealVar*) iteryields->Next();
    j++;
  }
  //S/L
  double result = Y[jS]/Y[jL];
  cout<<"result declared"<<endl;
  double E_result = TMath::Abs(result)*sqrt(pow(E[jS]/Y[jS],2)+pow(E[jL]/Y[jL],2));
  cout<<"E_result declared"<<endl;
  TString resultstring = Form("%E",result);
  TString E_resultstring = Form("%E",E_result);
  outputtext = "Y_{#Sigma^{0}}/Y_{#Lambda} = "+resultstring+" +/- "+E_resultstring;
  cout<<outputtext<<endl;
  textfile<<outputtext<<endl;
  //txt->AddText(outputtext);
  double resultlimit = (Y[jS]+E[jS])/(Y[jL]-E[jL]);
  outputtext = Form("%E",resultlimit);
  outputtext = "limit = "+outputtext;
  cout<<outputtext<<endl;
  textfile<<outputtext<<endl;
  //txt->AddText(outputtext);
  
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
  pad2->Draw();
  pad1->Draw();
  pad1->cd();
  framex->SetMinimum(1);
  framex->SetMaximum(3000);
  
  framex->addObject(leg);//add legend to frame
  //framex->addObject(txt);//add text to frame

  gPad->SetTopMargin(0.06);
  pad1->SetLogy();
  // pad1->Range(4100,0,6100,0.0005);
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

  placeholder = "plots/fit"+fileN+".eps";
  c1->Print(placeholder);
  placeholder = "plots/fit"+fileN+".C";
  c1->SaveAs(placeholder);
  textfile.close();
}
