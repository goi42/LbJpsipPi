#ifndef __set_data_fit_mass_C_INCLUDED__
#define __set_data_fit_mass_C_INCLUDED__
#include <TFile.h>
#include <TFile.h>
#include "TTree.h"
#include <TH1.h>
#include "RooDataSet.h"
#include "RooDataHist.h"

//local
#include "/afs/cern.ch/user/m/mwilkins/algorithms/makeroohistpdf.C"

using namespace RooFit;


RooDataSet get_data(RooRealVar* mass, TString tracktype){
  // //open file and get histogram
  // TFile *inHistos = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/histos_data.root", "READ");
  // TH1F * h100 = (TH1F*)inHistos->Get("h70");
  // cout<<"data histogram gotten"<<endl;
  //unbinned
  // TString placeholder = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/cutfile_newly_optimized";
  // TString placeholder = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/cutfile_new_LM";
  // TString placeholder = "/afs/cern.ch/user/m/mwilkins/LbJpsipPi/cutfile_newest";
  // TString placeholder = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/cutfile_newest";
  TString placeholder = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/B0/cutfile_LimingB0cuts";
  if(tracktype!="") placeholder+="_"+tracktype;
  placeholder+="_B0MC.root";
  TFile *hastree = new TFile(placeholder, "READ");
  TTree * h100 = (TTree*)hastree->Get("mytree");
  // TFile *hastree = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/Lst/Lb_JpsiLambda_mmSpi_1405_200000.root", "READ");
  // TTree * h100 = (TTree*)hastree->Get("MCDecayTreeTuple/MCDecayTree");
  cout<<"tree gotten"<<endl;
  // RooDataHist *data = new RooDataHist("data","1D",RooArgList(*mass),h100);
  //unbinned
  RooDataSet data("data","1D",h100,*mass);
  cout<<"data declared"<<endl;
  return data;
}

#endif
