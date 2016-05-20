/*
This is a variant on makeplots2.C that does not require the same number of branches and cuts per file and branch.
It does not do the fancy comparisons that makeplots.C and makeplots2.C do, however.
It is good for comparing cuts on a single branch.
It loops over files, then branches, then cuts, assigning branches and cuts in each 
of these loops, and plotting the cuts as they come.
Each branch gets its own canvas.

MAKE SURE TO DOUBLE CHECK THE OUTPUT FILE NAMES 
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
#include "makecuts.C"
#include "/afs/cern.ch/user/m/mwilkins/algorithms/branch.h"
#include "/afs/cern.ch/user/m/mwilkins/algorithms/cut.h"
#include "/afs/cern.ch/user/m/mwilkins/algorithms/file.h"

void makeplots3_RootOut(TString runmode="d", TString drawopt=""){
  gROOT->SetBatch(kTRUE);
  TString placeholder;//this is to avoid adding strings in functions; assign right before use
  TString placeholder2;
  TString placeholder3;
  TString outputlocation="./";
  TString filename="plots.pdf";
  //create necessary counters, canvases, legends, etc.
  cout<<endl;
  vector<TCanvas*> c;//each canvas holds one stack of histograms
  int ci = 0;//how many canvases have been plotted?
  vector<TLegend*> leg;//one legend per canvas
  vector<THStack*> hs;//one stack per canvas
  vector< vector<TH1F*> > h;
  TCanvas *cf = new TCanvas("cf","combined");//canvas to hold everything

  //assign things to actually be plotted
  map<TString,TString> f1quality {{"filetype","data"},{"decaymode","both"}};
  map<TString,TString> f2quality {{"filetype","MC"},{"decaymode","#Lambda^{0}"}};
  map<TString,TString> f3quality {{"filetype","MC"},{"decaymode","#Sigma^{0}"}};
  map<TString,TString> f4quality {{"filetype","MC"},{"decaymode","#Lambda*(1405)"}};
  map<TString,TString> f5quality {{"filetype","MC"},{"decaymode","#Lambda only"}};
  file f[]={{"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/SMC_tuples_with_gd_info.root","SMCfile",f3quality}, \
	    {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/Lst/1405_fullMC/Lb_JpsiLambda_mmSpi_1405_200000.root","Lst(1405)MC",f4quality}};
            // {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/subLimDVNtuples.root","data",f1quality}};
	    // {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/LMC_tuples_with_gd_info.root","LMCfile",f2quality}};
            
  int nFiles = (sizeof(f)/sizeof(f[0]));
  if((unsigned int)nFiles != (sizeof(Lbname)/sizeof(Lbname[0]))){
    cout<<"number of Lbnames must = nFiles"<<endl;
    cout<<"nFiles = "<<nFiles<<" while (sizeof(Lbname)/sizeof(Lbname[0])) = "<<(sizeof(Lbname)/sizeof(Lbname[0]))<<endl;
    exit(EXIT_FAILURE);
  }else if((unsigned int)nFiles != (sizeof(Jpsi_)/sizeof(Jpsi_[0]))){
    cout<<"number of Jpsi_ must = nFiles"<<endl;
    cout<<"nFiles = "<<nFiles<<" while (sizeof(Jpsi_)/sizeof(Jpsi_[0])) = "<<(sizeof(Jpsi_)/sizeof(Jpsi_[0]))<<endl;
    exit(EXIT_FAILURE);
  }else if((unsigned int)nFiles != (sizeof(massname)/sizeof(massname[0]))){
    cout<<"number of mass names must equal the number of files"<<endl;
    exit(EXIT_FAILURE);
  }

  cout<<"Starting file loop..."<<endl;
  for(int ifile=0;ifile<nFiles;ifile++){
    file * thisfile = &f[ifile];
    cout<<"Using "<<thisfile->name<<"..."<<endl;
    thisfile->b={{massname[ifile],"#Lambda_{b} mass",400,4100,6100},	\
    		 {massname[ifile],"#Lambda_{b} mass LL",400,4100,6100}, \
                 {massname[ifile],"#Lambda_{b} mass DD",400,4100,6100}  \
    };
    // thisfile->b={{"R_WM","#Lambda^{0} M with p #rightarrow #pi",80,300,700}, \
    // 		 {"R_WM","#Lambda^{0} M with p #rightarrow #pi LL",80,300,700}, \
    // 		 {"R_WM","#Lambda^{0} M with p #rightarrow #pi DD",80,300,700}};
    // thisfile->b={{"R_M","#Lambda^{0} M LL",300,1086,1146}, \
    // 		 {"R_M","#Lambda^{0} M DD",300,1086,1146}};
    // // {"R_M","#Lambda^{0} M",300,1086,1146}, \
	 
    cout<<"branches declared"<<endl;
    thisfile->add_tree("Lb2JpsiLTree/mytree");//all 3 files have the same tree
    cout<<"tree added"<<endl;
    
    int nBranches = thisfile->b.size();
    
    cout<<endl<<"Starting branch loop..."<<endl;
    for(int ibranch=0; ibranch<nBranches; ibranch++){
      branch * thisbranch = &(thisfile->b[ibranch]);
      thisbranch->xlabel=thisbranch->name;
      float temp = ((float)thisbranch->hiBin - (float)thisbranch->loBin)/(float)thisbranch->nBins;
      placeholder2=Form("%.0f",temp);
      placeholder="N events/"+placeholder2+" MeV";
      thisbranch->ylabel=placeholder;
      
      cout<<"On branch "<<thisbranch->name<<" for file "<<thisfile->name<<"..."<<endl;
      
      //assign cuts
      TCut cLL,cDD,ctrigger,cnewest;
      makecuts(ifile,cLL,cDD,ctrigger,cnewest);

      thisbranch->c = {{cnewest,"newest"}};
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
      leg.push_back( new TLegend(0.125, 0.6, 0.625, 0.93) );//create legend
      placeholder = "hs"+cistring;
      hs.push_back( new THStack(placeholder,placeholder) ); //create the stack to hold the histograms
      TString leglabel="";
      TString stacktitle="";
      h.resize(ci+1);
      
      int icolor = 0;//color counter
      
      for(int icut =0; icut<nCuts; icut++){
        cut * thiscut = &(thisbranch->c[icut]);
        //adjust LL and DD branches to have LL and DD cuts
        if(thisbranch->name.Contains("LL")){
          thiscut->self=thiscut->self&&cLL;
          thiscut->name+="_LL";
        }
        if(thisbranch->name.Contains("DD")){
          thiscut->self=thiscut->self&&cDD;
          thiscut->name+="_DD";
        }
        
        cout<<"On cut "<<thiscut->name<<"..."<<endl;
	if(thiscut->name.Contains(" ")){
	  cout<<"spaces are not allowed in cut names. Rename cut "<<thiscut->name<<"!"<<endl;
	  exit(EXIT_FAILURE);
	}
        // //create cut trees
        // if(thisfile->t.size()>1){
        //   cout<<"tree vector has "<<thisfile->t.size()<<"elements. How did this happen?"<<endl;
        //   exit(EXIT_FAILURE);
        // }
        // TString fileoutputlocation="./";
        // // if(thisfile->quality["filetype"].Contains("data"))
        // //   fileoutputlocation = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/";
        // // if(thisfile->quality["filetype"].Contains("MC"))
        // //   fileoutputlocation = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/";
        // TString tempfilelocation=fileoutputlocation+"temp.root";
        // cout<<"creating tempfile... ";
        // TFile *tempfile = new TFile(tempfilelocation,"recreate");
        // cout<<"done"<<endl<<"copying tree with cuts... ";
        // TTree *temptree = thisfile->t[0]->CopyTree(thiscut->self);
        // cout<<"done"<<endl<<"writing tempfile... ";
        // tempfile->Write();
        // cout<<"done"<<endl<<"deleting "<<thisfile->name<<" in memory... ";
        // delete thisfile->self;
        // cout<<"done"<<endl<<"setting branch statuses... ";
        // temptree->SetBranchStatus("*",0);
        // temptree->SetBranchStatus(thisbranch->self,1);
        // cout<<"done"<<endl<<"creating newfile... ";
        // placeholder = fileoutputlocation+"cutfile_"+thiscut->name+"_LbM.root";
        // TFile *newfile = new TFile(placeholder,"recreate");
        // cout<<"done"<<endl<<"copying temptree... ";
        // TTree *newtree = temptree->CopyTree("");
        // cout<<"done"<<endl<<"writing newfile... ";
        // newfile->Write();
        // cout<<"done"<<endl<<"setting branch statuses... ";
        // temptree->SetBranchStatus("*",1);
        // cout<<"done"<<endl<<"deleting tempfile... ";
        // delete tempfile;
        // cout<<"done"<<endl<<"deleting newfile... ";
        // delete newfile;
        // cout<<"done"<<endl<<"removing tempfile... ";
        // placeholder= "rm "+tempfilelocation;
        // gSystem->Exec(placeholder);
        // cout<<"done"<<endl<<"reloading "<<thisfile->name<<" and its tree in memory... ";
        // thisfile->self = TFile::Open(thisfile->location);
        // thisfile->add_tree(thisfile->tname[0]);
        // cout<<"done"<<endl<<"removing extra elements in tree vector, currently size "<<thisfile->t.size()<<"... ";
        // if(thisfile->t.size()>1){
        //   thisfile->t.erase(thisfile->t.begin());
        //   thisfile->tname.erase(thisfile->tname.begin());
        // }
        // cout<<"done"<<endl;
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
        while(icolor==0||icolor==5||icolor==10||(icolor>=17&&icolor<=19)) 
          icolor++;//skip bad colors 
        h[ci][icut]->SetLineColor(icolor);
        placeholder = thisbranch->self+">>"+hname;
        thisfile->t[0]->Draw(placeholder,thiscut->self,drawopt);//there's only one tree per file
	cout<<"done"<<endl;
      }
      ci++;//iterates every time we finish a branch
    }
      
    cout<<"saving histograms... ";
    TString fileoutputlocation="./";
    if(thisfile->quality["filetype"].Contains("data"))
      fileoutputlocation = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/";
    if(thisfile->quality["filetype"].Contains("MC"))
      fileoutputlocation = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/";
    placeholder = fileoutputlocation+"histos_"+thisfile->name+"_newest.root";
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
