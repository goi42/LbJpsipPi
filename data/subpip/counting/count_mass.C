#include <iostream>
#include <fstream>
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
#include <TH1.h>
//local

void count_mass() {
  TString fileN = "DDlo";//suffix added before file extension, e.g., '.pdf'

  //input regions
  float Smin= 5300, Smax= 5570,Lmin=5570,Lmax=5720;

  TString placeholder;//to add strings before using them, e.g., for saving text files
  gROOT->SetBatch(kTRUE);
  gROOT->ProcessLine(".x /afs/cern.ch/user/m/mwilkins/cmtuser/src/lhcbStyle.C");

  //open file and get histogram
  cout<<"getting histogram... ";
  TFile *inHistos = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/histos_data.root", "READ");
  TH1F * h100 = (TH1F*)inHistos->Get("h81");
  cout<<"done"<<endl;
  //calculate bin numbers corresponding to regions
  cout<<"calculating bin numbers... ";
  // float wlow h100->GetXaxis()->GetBinLowEdge(0);//lower edge of histogram window
  // int nBins h100->GetXaxis()->GetNbins();//number of bins
  // float wup h100->GetXaxis()->GetBinUpEdge(nBins);//higher edge of histogram window
  // float MeVperBin = (wup-wlow)/(float)nBins;
  // if(Smin<wlow) etc
  int Sminbin=h100->FindBin(Smin);
  int Smaxbin=h100->FindBin(Smax);
  int Lminbin=h100->FindBin(Lmin);
  int Lmaxbin=h100->FindBin(Lmax);
  // if((Smin-wlow)%MeVperBin!=0) etc
  //adjust to make sure max excluded
  if(h100->GetXaxis()->GetBinLowEdge(Smaxbin)==Smax)
    Smaxbin=Smaxbin-1;
  if(h100->GetXaxis()->GetBinLowEdge(Lmaxbin)==Lmax)
    Lmaxbin=Lmaxbin-1;
  cout<<"done"<<endl;

  //calculate totals
  cout<<"calculating results... ";
  int NS=0, NL=0;
  for(int i=Sminbin; i<Smaxbin; i++)
    NS+=h100->GetBinContent(i);
  for(int i=Lminbin; i<Lmaxbin; i++)
    NL+=h100->GetBinContent(i);
  float ratio = (float)NS/(float)NL;
  cout<<"done"<<endl;

  //save results
  cout<<"saving results... ";
  ofstream textfile;//create text file to hold data
  placeholder = "output/count"+fileN+".txt";
  textfile.open(placeholder);
  textfile<<"Sigma region from "<<Smin<<" to "<<Smax<<", which, when translated to bins is actually >="
          <<h100->GetXaxis()->GetBinLowEdge(Sminbin)<<" to <"<<h100->GetXaxis()->GetBinUpEdge(Smaxbin)<<endl;
  textfile<<"Lambda region from "<<Lmin<<" to "<<Lmax<<", which, when translated to bins is actually >="
          <<h100->GetXaxis()->GetBinLowEdge(Lminbin)<<" to <"<<h100->GetXaxis()->GetBinUpEdge(Lmaxbin)<<endl;
  textfile<<"N Sigmas = "<<NS<<endl<<"N Lambdas = "<<NL<<endl;
  textfile<<"NS/NL = "<<ratio<<endl;
  textfile.close();
  cout<<"done"<<endl<<"done"<<endl;
}
