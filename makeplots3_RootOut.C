/*
This is a variant on makeplots2.C that does not require the same number of branches and cuts per file and branch.
It does not do the fancy comparisons that makeplots.C and makeplots2.C do, however.
It is good for comparing cuts on a single branch.
It loops over files, then branches, then cuts, assigning branches and cuts in each 
of these loops, and plotting the cuts as they come.
Each branch gets its own canvas.

Specify "tree" as the runmode to get root file output; include "bron" to keep all the branches in the output file. Specify "hist" to make histograms.

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
  if(runmode.Contains("tree")&&runmode.Contains("hist")){
    cout<<"Cannot do both tree and histogram output."<<endl;
    exit(EXIT_FAILURE);
  }
  if(!(runmode.Contains("tree")||runmode.Contains("hist"))){
    cout<<"This program doesn't do anything unless you specify \"tree\" or \"hist\"."<<endl;
    exit(EXIT_FAILURE);
  }
  if(runmode.Contains("hist")&&runmode.Contains("bron")){
    cout<<"Warning: \"bron\" option doesn't do anything in \"hist\" mode."<<endl;
  }
  gROOT->SetBatch(kTRUE);
  TString placeholder;//this is to avoid adding strings in functions; assign right before use
  TString placeholder2;
  TString placeholder3;
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
  file f[]={// {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/subLimDVNtuples.root","data",f1quality}};
    // {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/LMC_tuples_with_gd_info.root","LMCfile",f2quality}};
    {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/SMC_tuples_with_gd_info.root","SMCfile",f3quality},
    {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/Lst/1405_fullMC/Lb_JpsiLambda_mmSpi_1405_200000.root","Lst1405MC",f4quality}};

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
    file * myfile = &(f[ifile]);
    TFile * thisfile = f[ifile].self;
    cout<<"Using "<<myfile->name<<"..."<<endl;
    myfile->b={{massname[ifile],"#Lambda_{b} mass",400,4100,6100},	\
	       {massname[ifile],"#Lambda_{b} mass LL",400,4100,6100},	\
	       {massname[ifile],"#Lambda_{b} mass DD",400,4100,6100}	\
    };
    // myfile->b={{"R_WM","#Lambda^{0} M with p #rightarrow #pi",80,300,700}, \
    // 		 {"R_WM","#Lambda^{0} M with p #rightarrow #pi LL",80,300,700}, \
    // 		 {"R_WM","#Lambda^{0} M with p #rightarrow #pi DD",80,300,700}};
    // myfile->b={{"R_M","#Lambda M LL",300,1086,1146},
    // 		 {"R_M","#Lambda M DD",300,1086,1146}};
    // // {"R_M","#Lambda^{0} M",300,1086,1146}, \
	 
    cout<<"branches declared"<<endl;
    myfile->add_tree("Lb2JpsiLTree/mytree");//all 3 files have the same tree
    cout<<"tree added"<<endl;
    
    int nBranches = myfile->b.size();
    
    cout<<endl<<"Starting branch loop..."<<endl;
    for(int ibranch=0; ibranch<nBranches; ibranch++){
      branch * mybranch = &(myfile->b[ibranch]);
      TString * thisbranch = &(mybranch->self);
      cout<<"On branch "<<mybranch->name<<" for file "<<myfile->name<<"..."<<endl;
      
      //assign cuts
      TCut cLL,cDD,ctrigger,c070116;
      makecuts(ifile,cLL,cDD,ctrigger,c070116);

      if(f[ifile].name=="SMCfile"){
	placeholder = "abs(R_MC_GD_MOTHER_ID)==5122&&abs(R_MC_MOTHER_ID)==3212&&R_BKGCAT==0";
	placeholder2="SMC";
      }else if(f[ifile].name=="Lst1405MC"){
	placeholder = "abs(R_MC_GD_GD_MOTHER_ID)==5122&&abs(R_MC_GD_MOTHER_ID)==13122&&abs(R_MC_MOTHER_ID)==3212&&R_BKGCAT==0";
	placeholder2="Lst1405MC";
      }
      placeholder3="070116_plus"+placeholder2+"cuts";
      mybranch->c = {{c070116&&(TCut)placeholder,placeholder3}};
      int nCuts = mybranch->c.size();
      if(nCuts==0){
        //for branches with no cuts assigned, 
        //we must give them an empty cut with an empty name
        //so they can be plotted in the cuts loop
        mybranch->c = {{"",""}};
        nCuts = mybranch->c.size();
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
        cut * mycut = &(mybranch->c[icut]);
        TCut * thiscut = &(mycut->self);
        //adjust LL and DD branches to have LL and DD cuts
        if(mybranch->name.Contains("LL")){
          *thiscut=*thiscut&&cLL;
          mycut->name+="_LL";
        }
        if(mybranch->name.Contains("DD")){
          *thiscut=*thiscut&&cDD;
          mycut->name+="_DD";
        }
        
        cout<<"On cut "<<mycut->name<<"..."<<endl;
	if(mycut->name.Contains(" ")){
	  cout<<"spaces are not allowed in cut names. Rename cut "<<mycut->name<<"!"<<endl;
	  exit(EXIT_FAILURE);
	}
	if(runmode.Contains("tree")){
	  //create cut trees
	  if(myfile->t.size()>1){
	    cout<<"tree vector has "<<myfile->t.size()<<"elements. How did this happen?"<<endl;
	    exit(EXIT_FAILURE);
	  }
	  TString fileoutputlocation="./";
	  if(myfile->quality["filetype"].Contains("data"))
	    fileoutputlocation = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/";
	  if(myfile->quality["filetype"].Contains("MC"))
	    fileoutputlocation = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/";
	  TString tempfilelocation=fileoutputlocation+"temp.root";
	  cout<<"creating tempfile... ";
	  TFile *tempfile = new TFile(tempfilelocation,"recreate");
	  cout<<"done"<<endl<<"copying tree with cuts... ";
	  TTree *temptree = myfile->t[0]->CopyTree(*thiscut);
	  cout<<"done"<<endl<<"writing tempfile... ";
	  tempfile->Write();
	  cout<<"done"<<endl<<"deleting "<<myfile->name<<" in memory... ";
	  delete thisfile;
	  cout<<"done"<<endl;
	  if(!runmode.Contains("bron")){
	    cout<<"setting branch statuses... ";
	    temptree->SetBranchStatus("*",0);
	    temptree->SetBranchStatus(*thisbranch,1);
	    cout<<"done"<<endl;
	  }
	  cout<<"creating newfile... ";
	  if(f[ifile].name=="SMCfile"){
	    placeholder2="SMC";
	  }else if(f[ifile].name=="Lst1405MC"){
	    placeholder2="Lst1405MC";
	  }
	  placeholder = fileoutputlocation+"cutfile_"+mycut->name+"_"+placeholder2+".root";
	  TFile *newfile = new TFile(placeholder,"recreate");
	  cout<<"done"<<endl<<"copying temptree... ";
	  TTree *newtree = temptree->CopyTree("");
	  cout<<"done"<<endl<<"writing newfile... ";
	  newfile->Write();
	  cout<<"done"<<endl;
	  if(!runmode.Contains("bron")){
	    cout<<"setting branch statuses... ";
	    temptree->SetBranchStatus("*",1);
	    cout<<"done"<<endl;
	  }
	  cout<<"deleting tempfile... ";
	  delete tempfile;
	  cout<<"done"<<endl<<"deleting newfile... ";
	  delete newfile;
	  cout<<"done"<<endl<<"removing tempfile... ";
	  placeholder= "rm "+tempfilelocation;
	  gSystem->Exec(placeholder);
	  cout<<"done"<<endl<<"reloading "<<myfile->name<<" and its tree in memory... ";
	  thisfile = TFile::Open(myfile->location);
	  myfile->add_tree(myfile->tname[0]);
	  cout<<"done"<<endl<<"removing extra elements in tree vector, currently size "<<myfile->t.size()<<"... ";
	  if(myfile->t.size()>1){
	    myfile->t.erase(myfile->t.begin());
	    myfile->tname.erase(myfile->tname.begin());
	  }
	  cout<<"done"<<endl;
	}
        //create convenient strings
        TString icutstring = Form("%d",icut);
        TString hname = "h"+cistring+icutstring;
        placeholder3 = mycut->name;
        placeholder2 = mybranch->name;
        placeholder = placeholder2 + " " + placeholder3;
        TString htitle = placeholder;
        //create histogram
        int nBins = mybranch->nBins;
        int loBin = mybranch->loBin;
        int hiBin = mybranch->hiBin;
        h[ci].push_back( new TH1F(hname,htitle,nBins,loBin,hiBin) );
        //draw histogram
        cout<<"drawing histogram "<<icut+1<<"/"<<nCuts<<"...";
        while(icolor==0||icolor==5||icolor==10||(icolor>=17&&icolor<=19)) 
          icolor++;//skip bad colors 
        h[ci][icut]->SetLineColor(icolor);
        placeholder = *thisbranch+">>"+hname;
        myfile->t[0]->Draw(placeholder,*thiscut,drawopt);//there's only one tree per file
	cout<<"done"<<endl;
      }
      ci++;//iterates every time we finish a branch
    }
      
    if(runmode.Contains("hist")){
      cout<<"saving histograms... ";
      TString fileoutputlocation="./";
      if(myfile->quality["filetype"].Contains("data"))
	fileoutputlocation = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/";
      if(myfile->quality["filetype"].Contains("MC"))
	fileoutputlocation = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/";
      placeholder = fileoutputlocation+"histos_"+myfile->name+"_c070116.root";
      cout<<endl<<"saving "<<placeholder<<"... ";
      TFile* histfile = new TFile(placeholder,"recreate");
      cout<<"done"<<endl<<"writing histograms... ";
      for(unsigned int i=(ifile*nBranches);i<h.size();i++){//since there's a canvas per branch
	for(unsigned int j=0;j<h[i].size();j++){
	  h[i][j]->Write();
	}
      }
      histfile->Close();
      delete histfile;
      cout<<"done"<<endl;
    }
  }
  
  gROOT->SetBatch(kFALSE);
  cout<<"done"<<endl;
}
