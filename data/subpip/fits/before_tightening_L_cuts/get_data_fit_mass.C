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


RooDataSet get_data(RooRealVar* mass){
  // //open file and get histogram
  // TFile *inHistos = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/histos_data.root", "READ");
  // TH1F * h100 = (TH1F*)inHistos->Get("h70");
  // cout<<"data histogram gotten"<<endl;
  //unbinned
  TFile *hastree = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/cutfile_Optimized.root", "READ");
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

RooDataSet get_Lst_MC(RooRealVar* mass){
  // TFile *hasLsttree = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/Lst/Lst_1405_JpsiLmass.root","READ");
  // TTree * Lsttree = (TTree*)hasLsttree->Get("mytree");
  // RooDataSet LstMC("LstMC","1D",Lsttree,*mass);
  // cout<<"LstMC RooDataSet created"<<endl;
  // return LstMC;
  TFile *hasLsttree = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/cutfile_Optimized_and_require_1405_Lst1405_fullMC.root","READ");
  TTree * Lsttree = (TTree*)hasLsttree->Get("mytree");
  RooDataSet LstMC("LstMC","1D",Lsttree,*mass);
  cout<<"LstMC RooDataSet created"<<endl;
  return LstMC;
}

RooDataSet get_L_MC(RooRealVar* mass){
  TFile *hasLtree = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/cutfile_Optimized_LMC.root","READ");
  TTree * Ltree = (TTree*)hasLtree->Get("mytree");
  RooDataSet LMC("LMC","1D",Ltree,*mass);
  cout<<"LMC RooDataSet created"<<endl;
  return LMC;
}

#endif
