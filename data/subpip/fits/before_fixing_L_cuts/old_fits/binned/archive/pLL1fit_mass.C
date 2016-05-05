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
  TString fileN = "LL1";//suffix added before file extension, e.g., '.pdf'
  TString placeholder;//to add strings before using them, e.g., for saving text files
  gROOT->SetBatch(kTRUE);
  gROOT->ProcessLine(".x /afs/cern.ch/user/m/mwilkins/cmtuser/src/lhcbStyle.C");
  
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetTextSize(0.3);

  //open file and get histogram
  TFile *inHistos = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/histos_data.root", "READ");
  TH1F * h100 = (TH1F*)inHistos->Get("h70");
  cout<<"data histogram gotten"<<endl;
  // //unbinned
  // TFile *hastree;
  // TTree * h100;
  // hastree = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/subLimDVNtuples.root", "READ");
  // h100 = (TTree*)hastree->Get("Lb2JpsiLTree/mytree");
  // cout<<"tree gotten"<<endl;

  RooRealVar *mass = new RooRealVar("Bs_LOKI_MASS_JpsiConstr","m(#Lambda_{b})",4300,5950,"MeV");//adding range to variable 
  //instead of including ',Range(5200,5950)' in declaration of NLL
  mass->setRange("bkg1",4300,4800);
  mass->setRange("bkg2",5700,5950);
  cout<<"mass declared"<<endl;
  RooDataHist *data = new RooDataHist("data","1D",RooArgList(*mass),h100);
  // //unbinned
  // RooDataSet *data = new RooDataSet("data","1D",h100,*mass);
  cout<<"data declared"<<endl;
  
  TFile *SMChistos= new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/histos_SMCfile.root", "READ");
  cout<<"SMC file opened"<<endl;
  TH1F *SMCh = (TH1F*)SMChistos->Get("h10");
  cout<<"SMC hist gotten"<<endl;

  RooDataHist *SMC = new RooDataHist("SMC","1D",RooArgList(*mass),SMCh);
  cout<<"SMC hist assigned to RooDataHist"<<endl;
  
  // Construct Pdf Model
  // /\0
  RooRealVar mean1L("mean1L","/\\0 gaus 1: mean",5621.302,5525,5700);
  RooRealVar sig1L("sig1L","/\\0 gaus 1: sigma",7.789,0,100);
  RooFormulaVar mean2L("mean2L","@0",RooArgList(mean1L));
  // RooRealVar mean2L("mean2L","/\\0 gaus 2: mean",5621.302,5525,5700);
  RooRealVar sig2L("sig2L","/\\0 gaus 2: sigma",18.292,0,100);
  RooGaussian gau1L("gau1L","/\\0 signal: gaussian 1",*mass,mean1L,sig1L);
  RooGaussian gau2L("gau2L","/\\0 signal: gaussian 2",*mass,mean2L,sig2L);
  RooRealVar f1L("f1L","/\\0 signal: fraction gaus 1",0.769,0,1);
  RooAddPdf sigL("sigL","#Lambda^{0} signal",RooArgList(gau1L,gau2L),RooArgList(f1L));
  // sigma0
  //using RooHistPdf from MC--no need to build pdf here
  RooHistPdf sigS = makeroohistpdf(SMC,mass,"sigS","#Sigma^{0} signal (RooHistPdf)");
  // /\*
  cout<<"Lst stuff"<<endl;
  RooRealVar meanLst1("meanLst1","/\\*: mean1",5000.643,4800,5150);
  RooRealVar meanLst2("mean5Lst2","/\\*: mean2",5150.000,4800,5150);
  RooRealVar sigLst1("sigLst1","/\\*: sigma1",51.848,0,1000);
  RooRealVar sigLst2("sigLst2","/\\*: sigma2",135.726,0,1000);
  RooGaussian gauLst1("gauLst1","#Lambda* bkg: gaussian 1",*mass,meanLst1,sigLst1);
  RooGaussian gauLst2("gauLst2","#Lambda* bkg: gaussian 2",*mass,meanLst2,sigLst2);
  RooRealVar fLst1("fLst1","/\\* bkg: fraction gaus 1",0.444,0,1);
  RooAddPdf bkgLst("bkgLst","#Lambda* signal",RooArgList(gauLst1,gauLst2),RooArgList(fLst1));
  
  //Poly func BKG mass
  RooRealVar b0("b0","Background: Chebychev b0",-0.980,-10000,10000);
  RooRealVar b1("b1","Background: Chebychev b1",-0.016,-10000,10000);
  RooRealVar b2("b2","Background: Chebychev b2",-0.019,-10000,10000);
  RooRealVar b3("b3","Background: Chebychev b3",0.215,-10000,10000);
  RooRealVar b4("b4","Background: Chebychev b4",-0.068,-10000,10000);
  RooRealVar b5("b5","Background: Chebychev b5",-0.086,-10000,10000);
  RooRealVar b6("b6","Background: Chebychev b6",0.018,-10000,10000);
  RooArgList bList(b0,b1,b2,b3,b4,b5,b6);
  RooChebychev bkg("bkg","Background", *mass, bList);
  
  //number of each shape  
  RooRealVar nbkg("nbkg","N_{bkg}",5530.974,0,100000000);
  RooRealVar nsigL("nsigL","Yield #Lambda^{0}",4637.149,0,100000000);
  RooRealVar nsigS("nsigS","Yield #Sigma^{0}",0.000000002,0,100000000);
  RooRealVar nbkgLst("nbkgLst","N_{#Lambda*}",1050.028,0,100000);

  //add shapes and their number to a totalPdf
  RooArgList shapes;
  RooArgList yields;
  shapes.add(sigL);   yields.add(nsigL);
  shapes.add(sigS);   yields.add(nsigS);
  shapes.add(bkgLst); yields.add(nbkgLst);
  shapes.add(bkg);    yields.add(nbkg);  
  RooAddPdf totalPdf("totalPdf","totalPdf",shapes,yields);

  //fit the totalPdf
  RooAbsReal * nll = totalPdf.createNLL(*data,Extended(kTRUE));//,Range("bkg1,bkg2"));
  RooMinuit m(*nll);
  m.setVerbose(kFALSE);
  RooFitResult *logfile = m.save("logfile","Log File");
  m.migrad();
  m.minos();
  m.minos();
  ofstream logfilestream;
  placeholder = "plots/fitlog"+fileN+".txt";
  logfilestream.open(placeholder);
  logfile->printMultiline(logfilestream,100000,kTRUE);
  logfilestream.close();

  //display and save information
  ofstream textfile;//create text file to hold data
  placeholder = "plots/fit"+fileN+".txt";
  textfile.open(placeholder);
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
  TLegend *leg = new TLegend(0.55, 0.5, .685, .9);  
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
        TString varvalstring = Form("%.3f",varval);
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
  TString chi2string = Form("%.3f",chi2);
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
  int jS=0, jL=0;//these hold the position of the S and L results;initialized in case there is no nsigS or nsigL
  while(varyields){//loop over yields
    TString varname = varyields->GetName();
    TString vartitle = varyields->GetTitle();
    double varval = varyields->getVal();
    Y.push_back(varval);
    double lo = varyields->getErrorLo();
    double hi = varyields->getErrorHi();
    E.push_back(TMath::Max(fabs(lo),hi));
    YS.push_back(Form("%.3f",Y[j]));
    ES.push_back(Form("%.3f",E[j]));
    
    if(varname=="nsigS") jS=j;
    if(varname=="nsigL") jL=j;
    
    outputtext = vartitle+" = "+YS[j]+" +/- "+ES[j];
    textfile<<outputtext<<endl;
    txt->AddText(outputtext);
    
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

  placeholder = "plots/fit"+fileN+".eps";
  c1->Print(placeholder);
  placeholder = "plots/fit"+fileN+".C";
  c1->SaveAs(placeholder);
  textfile.close();
}
