/*
for normal operation, make sure to assign a unique ID in run_fit_mass. Also, make sure to comment out the shapes you don't want added to totalPdf and to specify the range for the nll
for quasi-normal operation, check that data_temp is getting the proper data set
double check that the name given to mass is the branch in use
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
  
  TString tracktype = ""; //"LL","DD",""
  if(!(tracktype=="LL"||tracktype=="DD"||tracktype=="")) {
    cout<<"What track type? fit_mass.C line 38."<<endl;
    exit(EXIT_FAILURE);
  }
  cout<<"fit_mass: Set mass and data:"<<endl;
  RooRealVar *mass = new RooRealVar("B0_LOKI_MASS_JpsiConstr","m(J/#psi K*)",3800,6600,"MeV");
  mass->setRange("tot",3800,6600);
  RooDataSet data_temp = get_data(mass,tracktype);
  RooDataSet *data = &data_temp;
  cout<<"fit_mass: Mass and data set."<<endl;

  cout<<"fit_mass: Assign shapes:"<<endl;
  // B0
  //dbl Gaussian
  RooRealVar mean1("mean1L","B0 gaus 1: mean",5350,5200,5500);
  RooRealVar sig1("sig1L","B0 gaus 1: sigma",8,0,200);
  RooGaussian gau1("gau1L","B^{0} signal: gaussian 1",*mass,mean1L,sig1L);
  RooFormulaVar mean2("mean2L","@0",mean1L);
  RooRealVar sig2("sig2L","B0 gaus 2: sigma",23,0,200);
  RooGaussian gau2("gau2L","B^{0} signal: gaussian 2",*mass,mean2L,sig2L);
  RooRealVar f1("f1L","B0 signal: fraction gaussian 1",0.8,0,1);
  RooAddPdf sig("sigL","B^{0} signal (dbl gaus)",RooArgList(gau1L,gau2L),RooArgList(f1L));

  // bkg
  // RooRealVar b0("b0","Background: Chebychev b0",-1.071,-10000,10000);
  RooRealVar b1("b1","Background: Chebychev b1",-1.183578,-10,10);
  RooRealVar b2("b2","Background: Chebychev b2",0.154520,-10,10);
  RooRealVar b3("b3","Background: Chebychev b3",-0.387522,-10,10);
  RooRealVar b4("b4","Background: Chebychev b4",0.281777,-10,10);
  RooRealVar b5("b5","Background: Chebychev b5",0.187079,-2,2);
  RooRealVar b6("b6","Background: Chebychev b6",-0.015,-10000,10000);
  RooRealVar b7("b7","Background: Chebychev b7",0.012,-10000,10000);
  RooArgList bList(b1,b2,b3);
  RooChebychev bkg("bkg","Background", *mass, bList);

  cout<<"fit_mass: Shapes assigned."<<endl;
  
  //number of each shape
  cout<<"fit_mass: declaring number of each shape:"<<endl;
  RooRealVar nbkg("nbkg","N bkg",2165,0,100000000);
  RooRealVar nsig("nsig","N B0" ,1689,0,100000000);
  cout<<"fit_mass: Numbers declared."<<endl;

  //add shapes and their number to a totalPdf
  cout<<"fit_mass: adding shapes and their numbers to totalPdf:"<<endl;
  RooArgList shapes;
  RooArgList yields;
  shapes.add(sig);        yields.add(nsig);
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
