/*
This is a variant on makeplots3.C that is just for making a histogram file of m(J/psi /\) from /\*(1405) MC
*/
// Include files
#include <vector>
#include <TLegend.h>
#include <TTree.h>
#include "TROOT.h"
#include "TRint.h"
#include <TFile.h>
#include <THStack.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "TVector3.h"
#include "TPaveStats.h"
#include <math.h>
#include <TString.h>
#include <TCut.h>
#include <TSystem.h>

// local
#include "/afs/cern.ch/user/m/mwilkins/algorithms/branch.h"
#include "/afs/cern.ch/user/m/mwilkins/algorithms/file.h"

void makeplots4(TString runmode="d", TString drawopt=""){
  gROOT->SetBatch(kTRUE);
  TString placeholder;//this is to avoid adding strings in functions; assign right before use
  TString placeholder2;
  TString placeholder3;
    //create necessary counters, canvases, legends, etc.
  cout<<endl;
  vector<TCanvas*> c;//each canvas holds one stack of histograms
  int ci = 0;//how many canvases have been plotted?
  vector< vector<TH1F*> > h;

  //assign things to actually be plotted
  map<TString,TString> fquality {{"filetype","MC"},{"decaymode","#Lambda*(1405)"}};
  file f[]={{"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/Lst/Lb_JpsiLambda_mmSpi_1405_200000.root","LstMCfile",fquality}};
  int nFiles = (sizeof(f)/sizeof(f[0]));

  cout<<"Starting file loop..."<<endl;
  for(int ifile=0;ifile<nFiles;ifile++){
    file * thisfile = &f[ifile];
    cout<<"Using "<<thisfile->name<<"..."<<endl;
    placeholder="sqrt(pow(J_psi_1S_TRUEP_E+Lambda0_TRUEP_E,2)-pow(J_psi_1S_TRUEP_X+Lambda0_TRUEP_X,2)";
    placeholder+="-pow(J_psi_1S_TRUEP_Y+Lambda0_TRUEP_Y,2)-pow(J_psi_1S_TRUEP_Z+Lambda0_TRUEP_Z,2))";
    thisfile->b={{placeholder,"m(J/#psi #Lambda)",400,4100,6100}};
    cout<<"branches declared"<<endl;
    thisfile->add_tree("MCDecayTreeTuple/MCDecayTree");
    cout<<"tree added"<<endl;
    
    int nBranches = thisfile->b.size();
    
    cout<<endl<<"Starting branch loop..."<<endl;
    for(int ibranch=0; ibranch<nBranches; ibranch++){
      branch * thisbranch = &(thisfile->b[ibranch]);      
      cout<<"On branch "<<thisbranch->name<<" for file "<<thisfile->name<<"..."<<endl;
      
      //assign cuts
      int nCuts = thisbranch->c.size();
      if(nCuts==0){
        //for branches with no cuts assigned, 
        //we must give them an empty cut with an empty name
        //so they can be plotted in the cuts loop
        thisbranch->c = {{"",""}};
        nCuts = thisbranch->c.size();
      }
      //create necessary canvasy things
      TString cistring = Form("%d",ci);
      placeholder = "c"+cistring;
      c.push_back( new TCanvas(placeholder,placeholder,1200,800) ); //create the canvases
      c[ci]->cd();
      gStyle->SetOptStat("");
      h.resize(ci+1);
      
      int icolor = 0;//color counter
      
      for(int icut =0; icut<nCuts; icut++){
        cut * thiscut = &(thisbranch->c[icut]);
        cout<<"On cut "<<thiscut->name<<"..."<<endl;
        //create convenient strings
        TString icutstring = Form("%d",icut);
        TString hname = "h"+cistring+icutstring;
        placeholder3 = thiscut->name;
        placeholder2 = thisbranch->name;
        placeholder = placeholder2 + " " + placeholder3;
        TString htitle = placeholder;
        //create histogram
        int nBins = thisbranch->nBins;
        int loBin = thisbranch->loBin;
        int hiBin = thisbranch->hiBin;
        h[ci].push_back( new TH1F(hname,htitle,nBins,loBin,hiBin) );
        //draw histogram
        cout<<"drawing histogram "<<icut+1<<"/"<<nCuts<<"...";
        placeholder = thisbranch->self+">>"+hname;
        thisfile->t[0]->Draw(placeholder,thiscut->self,drawopt);//there's only one tree per file    
      }
      ci++;//iterates every time we finish a branch
    }
      
    cout<<"saving histograms... ";
    TString fileoutputlocation="/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/Lst/";
    placeholder = fileoutputlocation+"histos_"+thisfile->name+".root";
    cout<<endl<<"saving "<<placeholder<<"... ";
    TFile* histfile = new TFile(placeholder,"recreate");
    cout<<"done"<<endl<<"writing histograms... ";
    for(int i=(ifile*nBranches);i<h.size();i++){//since there's a canvas per branch
      for(int j=0;j<h[i].size();j++){
        h[i][j]->Write();
      }
    }
    histfile->Close();
    delete histfile;
    cout<<"done"<<endl;
  }
  

  gROOT->SetBatch(kFALSE);
  cout<<"done"<<endl;
}
