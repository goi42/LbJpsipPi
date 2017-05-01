//////////////////////////////////////////////////////////////////////////
//
// 'SPECIAL PDFS' RooFit tutorial macro #706
// 
// Histogram based p.d.f.s and functions
//
//
//
// 07/2008 - Wouter Verkerke 
// 
/////////////////////////////////////////////////////////////////////////

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooPolynomial.h"
#include "RooHistPdf.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
using namespace RooFit ;


void rf706_histpdf_modified()
{
  //  gROOT->SetBatch(kTRUE);

  //load data
  TFile *inHistos= new TFile("output/histos.root", "READ");
  TH1F * h100   = (TH1F*)inHistos->Get("cutmassLb7");
  TFile * inHistos2 = new TFile("../lambda/output/histos.root", "READ");
  TH1F * h200 = (TH1F*)inHistos2->Get("cutmassLb7");  

  double massLb = 5500;
  double massLbmin = 5300;
  double massLbmax = 5650;

  RooRealVar *mass = new RooRealVar("mass","m(#Lambda_{b})",massLb,"MeV");
  RooDataHist *hist1 = new RooDataHist("hist1","1D",RooArgList(*mass),h100);
  RooDataHist *hist2 = new RooDataHist("hist2","1D",RooArgList(*mass),h200);
  
  // Represent data in hist1 as pdf in *mass
  RooHistPdf* histpdf1 = new RooHistPdf("histpdf1","histpdf1",*mass,*hist1) ;

  // Plot binned data and histogram pdf overlaid
  RooPlot* frame1 = mass->frame(Title("#Sigma^{0} data with RooHistPdf")) ;
  frame1->SetMaximum(1100);
  hist1->plotOn(frame1) ;
  histpdf1->plotOn(frame1) ;
  histpdf1->paramOn(frame1) ;
  
  TCanvas* c1 = new TCanvas("rf706_histpdf","rf706_histpdf",800,400) ;
  c1->Divide(1,2);
  c1->cd(1);
  frame1->Draw() ;

  //see what happens if I try to fit histpdf1 to lambda data
  RooHistPdf *histpdf2 = histpdf1->Clone("histpdf2");
  RooAbsReal * nll = histpdf2->createNLL(*hist2,Extended(kTRUE));
  RooMinuit m(*nll);
  m.setVerbose(kTRUE);
  m.migrad();
  m.minos();
  RooPlot* frame2 = mass->frame(Title("#Lambda^{0} data fit with RooHistPdf from #Sigma^{0} data"));
  frame2->SetMaximum(1100);
  hist2->plotOn(frame2);
  histpdf2->plotOn(frame2);
  histpdf2->paramOn(frame2);
  c1->cd(2);
  frame2->Draw();

  //save histpdf1
  // cout<<"saving histpdf1..."<<endl;
  // histpdf1.RooHistPdf::SavePrimitive(std::cout);

  //  gROOT->SetPrimitive(kFALSE);
}
