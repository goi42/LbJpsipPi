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
#include "/afs/cern.ch/user/m/mwilkins/algorithms/chain.h"

void makeplots3_chain_RootOut(TString runmode="d", TString drawopt=""){
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
  cout<<"Running in mode "<<runmode;
  if(runmode.Contains("tree")){
    cout<<"(will create new root file";
    if(runmode.Contains("bron"))
      cout<<" with all branches copied";
    else cout<<" with only the given branch copied";
    cout<<")";
  }else if(runmode.Contains("hist"))
    cout<<"(will create root file with histograms)";
  cout<<"..."<<endl<<endl;
  vector<TCanvas*> c;//each canvas holds one stack of histograms
  int ci = 0;//how many canvases have been plotted?
  vector<TLegend*> leg;//one legend per canvas
  vector<THStack*> hs;//one stack per canvas
  vector< vector<TH1F*> > h;
  TCanvas *cf = new TCanvas("cf","combined");//canvas to hold everything

  //assign things to actually be plotted
  map<TString,TString> chquality {{"filetype","data"},{"decaymode","B_{s}"}};
  vector<file> f={
    // {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/cutfile_070116_data.root"},
    // {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/cutfile_Loose_DD.root"},
    {"/afs/cern.ch/user/m/mwilkins/EOS/lhcb/user/m/mwilkins/ganga/outputfiles/DVNtuples353_0-230.root"},
    {"/afs/cern.ch/user/m/mwilkins/EOS/lhcb/user/m/mwilkins/ganga/outputfiles/DVNtuples353_231-507.root"},
    {"/afs/cern.ch/user/m/mwilkins/EOS/lhcb/user/m/mwilkins/ganga/outputfiles/DVNtuples354.root"},
  };
  chain ch[]={{"Bs2JpsiKpiTree/mytree",f,"data",chquality}};
  // chain ch[]={{"mytree",f,"data",chquality}};

  int nChains = (sizeof(ch)/sizeof(ch[0]));
  if((unsigned int)nChains != sizeof(Lbname)/sizeof(Lbname[0])){
    cout<<endl<<"number of Lbnames must = nChains"<<endl;
    cout<<"nChains = "<<nChains<<" while sizeof(Lbname)/sizeof(Lbname[0]) = "<<sizeof(Lbname)/sizeof(Lbname[0])<<endl;
    exit(EXIT_FAILURE);
  }else if((unsigned int)nChains != sizeof(Jpsi_)/sizeof(Jpsi_[0])){
    cout<<endl<<"number of Jpsi_ must = nChains"<<endl;
    cout<<"nChains = "<<nChains<<" while sizeof(Jpsi_)/sizeof(Jpsi_[0]) = "<<sizeof(Jpsi_)/sizeof(Jpsi_[0])<<endl;
    exit(EXIT_FAILURE);
  }else if((unsigned int)nChains != sizeof(massname)/sizeof(massname[0])){
    cout<<endl<<"number of mass names must = nChains"<<endl;
    cout<<"nChains = "<<nChains<<" while sizeof(massname)/sizeof(massname[0]) = "<<sizeof(massname)/sizeof(massname[0])<<endl;
    exit(EXIT_FAILURE);
  }

  cout<<"Starting chain loop..."<<endl;
  for(int ichain=0;ichain<nChains;ichain++){
    chain * mychain = &(ch[ichain]);
    TChain * thischain = mychain->self;
    cout<<"Using "<<mychain->name<<"..."<<endl;
    placeholder3 = Lbname[ichain]+"_PT";
    mychain->b={// {massname[ichain],"#Lambda_{b} mass (PV) LL",400,4100,6100},	
                // {massname[ichain],"#Lambda_{b} mass (endV) LL",400,4100,6100},
                // {massname[ichain],"#Lambda_{b} mass (PV) DD",400,4100,6100},	
                // {massname[ichain],"#Lambda_{b} mass (endV) DD",400,4100,6100},
                {massname[ichain],"#Lambda_{b} mass",400,4100,6100}, 
                // {massname[ichain],"#Lambda_{b} mass LL",400,4100,6100}, 
		// {massname[ichain],"#Lambda_{b} mass DD",400,4100,6100}, 
		// {massname[ichain],"B_{s} mass"   ,700,3500,7000},
		// {massname[ichain],"B_{s} mass LL",700,3500,7000},
		// {massname[ichain],"B_{s} mass DD",700,3500,7000},
		// {"R_M","#Lambda M",300,1086,1146},			
                // {"R_M","#Lambda M (PV) LL",300,1086,1146},			
                // {"R_M","#Lambda M (endV) LL",300,1086,1146},			
                // {"R_M","#Lambda M (PV) DD",300,1086,1146},			
                // {"R_M","#Lambda M (endV) DD",300,1086,1146},			
                // {"R_WM","#Lambda^{0} M with p #rightarrow #pi",80,300,700}, 
		// {"R_WM","#Lambda^{0} M with p #rightarrow #pi LL",80,300,700}, 
                // {"R_WM","#Lambda^{0} M with p #rightarrow #pi DD",80,300,700}, 
                // {"R_P","#Lambda p",144,0,385000},			
                // {"R_P","#Lambda p LL",144,0,385000},         
                // {"R_P","#Lambda p DD",144,0,385000},         
                // {"R_PT","#Lambda p_{T}",148,0,37000},         
                // {"R_PT","#Lambda p_{T} LL",148,0,37000},      
                // {"R_PT","#Lambda p_{T} DD",148,0,37000}       
                // {placeholder3,"#Lambda_{b} p_{T}",4000,0,20000},        
                // {placeholder3,"#Lambda_{b} p_{T} LL",4000,0,20000},     
                // {placeholder3,"#Lambda_{b} p_{T} DD",4000,0,20000},     
                // {placeholder3,"#Lambda_{b} p_{T}",400,0,20000},         
                // {placeholder3,"#Lambda_{b} p_{T} LL",400,0,20000},     
                // {placeholder3,"#Lambda_{b} p_{T} DD",400,0,20000}};
                // {placeholder2,"#Lambda_{b} BKGCAT",131,0,131}                    
                // {"J_psi_1S_MM","J/#psi(1S) MM",48,2980,3220},                    
                // {"J_psi_1S_ENDVERTEX_CHI2/J_psi_1S_ENDVERTEX_NDOF","#chi^{2}/ndof(J/#psi(1S))",210,0,21}, 
                // {"H2_TRACK_GhostProb","#pi track GhostProb",100,0,1},   
                // {"H1_TRACK_GhostProb","p track GhostProb",100,0,1},      
                // {"muplus_TRACK_GhostProb","#mu^{+} track GhostProb",100,0,1}, 
                // {"muminus_TRACK_GhostProb","#mu^{-} track GhostProb",100,0,1}};
    };
    cout<<"branches declared"<<endl;    
    int nBranches = mychain->b.size();
    if(nBranches>1){
      cout<<"Due to weirdness reloading the chain in memory, no more than one branch is currently supported."<<endl;
      exit(EXIT_FAILURE);
    }

    cout<<endl<<"Starting branch loop "<<ichain+1<<"/"<<nChains<<"..."<<endl;
    for(int ibranch=0; ibranch<nBranches; ibranch++){
      branch * mybranch = &(mychain->b[ibranch]);
      TString * thisbranch = &(mybranch->self);
      cout<<"On branch "<<ibranch+1<<"/"<<nBranches<<" ("<<mybranch->name<<") for file "<<ichain+1<<"/"<<nChains<<" ("<<mychain->name<<")..."<<endl;
      
      //assign cuts
      TCut cLL,cDD,ctrigger,Bs2JpsiKst;
      makecuts(ichain,cLL,cDD,ctrigger,Bs2JpsiKst);

      mybranch->add_cut(Bs2JpsiKst,"Liming_selection_cuts");
      // mybranch->add_cut("Bs_LOKI_MASS_JpsiConstr>5000","test_cut");

      int nCuts = mybranch->c.size();
      if(nCuts==0){
        //for branches with no cuts assigned, 
        //we must give them an empty cut with an empty name
        //so they can be plotted in the cuts loop
        mybranch->c = {{"",""}};
        nCuts = mybranch->c.size();
      }
      if(nCuts>1){
	cout<<"Due to weirdness reloading the chain in memory, no more than one cut is currently supported."<<endl;
	exit(EXIT_FAILURE);
      }

      cout<<"cuts declared"<<endl;    
      //create necessary canvasy things
      TString cistring = Form("%d",ci);
      placeholder = "c"+cistring;
      c.push_back( new TCanvas(placeholder,placeholder,1200,800) ); //create the canvases
      c[ci]->cd();
      gStyle->SetOptStat("");
      leg.push_back( new TLegend(0.125, 0.6, 0.45, 0.93) );//create legend
      placeholder = "hs"+cistring;
      hs.push_back( new THStack(placeholder,placeholder) ); //create the stack to hold the histograms
      TString leglabel="";
      TString stacktitle="";
      h.resize(ci+1);
      
      int icolor = 0;//color counter
      
      cout<<endl<<"Starting cut loop "<<ibranch+1<<"/"<<nBranches<<" for file "<<ichain+1<<"/"<<nChains<<" ("<<mychain->name<<")..."<<endl;
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
        
        cout<<"On cut "<<icut+1<<"/"<<nCuts<<" ("<<mycut->name<<") for branch "<<ibranch+1<<"/"<<nBranches<<"..."<<endl;
        if(mycut->name.Contains(" ")){
          cout<<"spaces are not allowed in cut names. Rename cut "<<mycut->name<<"!"<<endl;
          exit(EXIT_FAILURE);
        }
	if(runmode.Contains("tree")){
	  //create cut trees
	  TString fileoutputlocation="./";
	  if(mychain->quality["filetype"].Contains("data")&&mychain->quality["decaymode"].Contains("B_{s}"))
	    fileoutputlocation = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/Bs2JpsiKst/";//should end with '/'
	  else {
	    cout<<"Edit code"<<endl;
	    exit(EXIT_FAILURE);
	  }
	  if(!mychain->quality["decaymode"].Contains("B_{s}")){
	    cout<<"Why are you using this code for something other than B_{s}?"<<endl;
	    exit(EXIT_FAILURE);
	  }
	  TString tempfilelocation=fileoutputlocation+"temp.root";
	  cout<<"creating tempfile... ";
	  TFile *tempfile = new TFile(tempfilelocation,"recreate");
	  cout<<"done"<<endl<<"copying tree with cuts... ";
	  TTree *temptree = thischain->CopyTree(*thiscut);
	  cout<<"done"<<endl<<"writing tempfile... ";
	  tempfile->Write();
	  cout<<"done"<<endl<<"deleting "<<mychain->name<<" in memory... ";
	  delete thischain;
	  cout<<"done"<<endl;
	  if(!runmode.Contains("bron")){
	    cout<<"setting branch statuses... ";
	    temptree->SetBranchStatus("*",0);
	    cout<<"set to 0...";
	    temptree->SetBranchStatus(*thisbranch,1);
	    cout<<"done"<<endl;
	  }
	  cout<<"creating newfile... ";
	  placeholder = fileoutputlocation+"cutfile_"+mycut->name+"_test.root";
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
	  cout<<"done"<<endl;
	  // cout<<"reloading "<<mychain->name<<" and its tree in memory... ";
	  // mychain->add_files(f,1);
	  // cout<<"done"<<endl;
	}
	if(runmode.Contains("hist")){
	  //create convenient strings
	  TString icutstring = Form("%d",icut);
	  TString hname = "h"+cistring+icutstring;
	  TString htitle = mybranch->name;
	  //create histogram
	  int nBins = mybranch->nBins;
	  int loBin = mybranch->loBin;
	  int hiBin = mybranch->hiBin;
	  h[ci].push_back( new TH1F(hname,htitle,nBins,loBin,hiBin) );
	  //draw histogram
	  cout<<"drawing histogram "<<icut+1<<"/"<<nCuts<<"..."<<endl;
	  while(icolor==0||icolor==5||icolor==10||(icolor>=17&&icolor<=19)) 
	    icolor++;//skip bad colors 
	  h[ci][icut]->SetLineColor(icolor);
	  placeholder = *thisbranch+">>"+hname;
	  // cout<<"convenient pointers declared"<<endl;
	  mychain->Draw(placeholder,*thiscut,drawopt);
	  cout<<"done. "<<endl;
	}
      }
      ci++;//iterates every time we finish a branch
    }

    if(runmode.Contains("hist")){
      cout<<"saving histograms... ";
      TString fileoutputlocation="./";
      if(mychain->quality["filetype"].Contains("data")&&mychain->quality["decaymode"].Contains("B_{s}"))
	fileoutputlocation = "/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/Bs2JpsiKst";
      else {
	cout<<"Edit code"<<endl;
	exit(EXIT_FAILURE);
      }
      placeholder = fileoutputlocation+"histos_"+mychain->name+".root";
      cout<<endl<<"saving "<<placeholder<<"... ";
      TFile* histfile = new TFile(placeholder,"recreate");
      cout<<"done"<<endl<<"writing histograms... ";
      for(unsigned int i=(ichain*nBranches);i<h.size();i++){//since there's a canvas per branch
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
