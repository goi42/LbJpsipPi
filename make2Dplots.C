/*
This program is a variant on makeplots2.C that compares specific combinations of elements within one given layer 
by drawing one on the x axis and the other on the y axis of a histogram and of a graph.
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
#include <TGraph.h>

// local
#include "/afs/cern.ch/user/m/mwilkins/algorithms/branch.h"
#include "/afs/cern.ch/user/m/mwilkins/algorithms/cut.h"
#include "/afs/cern.ch/user/m/mwilkins/algorithms/file.h"
#include "/afs/cern.ch/user/m/mwilkins/algorithms/layer.h"
#include "makecuts.C"

void make2Dplots(TString runmode ="d"){
  gROOT->SetBatch(kTRUE);
  TString placeholder;//this is to avoid adding strings in functions; assign right before use
  TString placeholder2;
  TString placeholder3;
  //default parameters
  TString outputlocation="./";
  TString filename="plots.pdf";

  //-----assign files, branches, cuts-------//
  cout<<"files... ";
  map<TString,TString> f1quality {{"filetype","data"},{"decaymode","data (both)"}};
  map<TString,TString> f2quality {{"filetype","MC"},{"decaymode","#Lambda^{0}"}};
  map<TString,TString> f3quality {{"filetype","MC"},{"decaymode","#Sigma^{0}"}};
  file f[]={{"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/subLimDVNtuples.root","datafile",f1quality}};
  int nFiles = (sizeof(f)/sizeof(f[0]));
  int nBranches=0;//initialized both of these to ensure there are no compiler warnings
  int nCuts=0;
  if((unsigned int)nFiles != sizeof(Lbname)/sizeof(Lbname[0])){
    cout<<endl<<"number of Lbnames must = nFiles"<<endl;
    cout<<"nFiles = "<<nFiles<<" while sizeof(Lbname)/sizeof(Lbname[0]) = "<<sizeof(Lbname)/sizeof(Lbname[0])<<endl;
    exit(EXIT_FAILURE);
  }else if((unsigned int)nFiles != sizeof(Jpsi_)/sizeof(Jpsi_[0])){
    cout<<endl<<"number of Jpsi_ must = nFiles"<<endl;
    cout<<"nFiles = "<<nFiles<<" while sizeof(Jpsi_)/sizeof(Jpsi_[0]) = "<<sizeof(Jpsi_)/sizeof(Jpsi_[0])<<endl;
    exit(EXIT_FAILURE);
  }else if((unsigned int)nFiles != sizeof(massname)/sizeof(massname[0])){
    cout<<endl<<"number of mass names must = nFiles"<<endl;
    cout<<"nFiles = "<<nFiles<<" while sizeof(massname)/sizeof(massname[0]) = "<<sizeof(massname)/sizeof(massname[0])<<endl;
    exit(EXIT_FAILURE);
  }
  cout<<"done"<<endl;
  for(int ifile=0;ifile<nFiles;ifile++){
    placeholder = massname[ifile];
    placeholder2 = Lbname[ifile]+"_P";
    cout<<"branches for file "<<f[ifile].name<<"... ";
    placeholder3 = Lbname[ifile]+"_PT";
    f[ifile].b={{placeholder3,"#Lambda_{b} p_{T}",120,0,60000},         \
                {placeholder3,"#Lambda_{b} p_{T} LL",120,0,60000},      \
                {placeholder3,"#Lambda_{b} p_{T} DD",120,0,60000},      \
                {placeholder,"#Lambda_{b} MM",400,4100,6100},        \
                {placeholder,"#Lambda_{b} MM LL",400,4100,6100},        \
                {placeholder,"#Lambda_{b} MM DD",400,4100,6100}        \
                // {placeholder2,"#Lambda_{b} p",160,0,800000},           \
                // {placeholder2,"#Lambda_{b} p LL",160,0,800000},        \
                // {placeholder2,"#Lambda_{b} p DD",160,0,800000}         \
                // {placeholder2,"#Lambda_{b} p",160000,0,800000},      \
                // {placeholder2,"#Lambda_{b} p LL",160000,0,800000},   \
                // {placeholder2,"#Lambda_{b} p DD",160000,0,800000},   \
                // {placeholder3,"#Lambda_{b} p_{T}",12000,0,60000},    \
                // {placeholder3,"#Lambda_{b} p_{T} LL",12000,0,60000}, \
                // {placeholder3,"#Lambda_{b} p_{T} DD",12000,0,60000}, \
                // {placeholder,"#Lambda_{b} MM",400,4100,6100},        \
                // {placeholder2,"#Lambda_{b} BKGCAT",131,0,131},       \
                // {placeholder3,"#Lambda_{b} p_{T}",4000,0,20000},     \
                // {"J_psi_1S_MM","J/#psi(1S) MM",48,2980,3220},        \
                // {"J_psi_1S_ENDVERTEX_CHI2/J_psi_1S_ENDVERTEX_NDOF","#chi^{2}/ndof(J/#psi(1S))",210,0,21}, \
                // {"R_WM","#Lambda^{0} M with p #rightarrow #pi",80,300,700}, \
                // {"H2_TRACK_GhostProb","#pi track GhostProb",100,0,1}, \
                // {"H1_TRACK_GhostProb","p track GhostProb",100,0,1},  \
                // {"muplus_TRACK_GhostProb","#mu^{+} track GhostProb",100,0,1}, \
                // {"muminus_TRACK_GhostProb","#mu^{-} track GhostProb",100,0,1}
    };
    cout<<"done"<<endl<<"trees... ";
    f[ifile].add_tree("Lb2JpsiLTree/mytree");//all 3 files have the same tree
    cout<<"done"<<endl;
    
    nBranches = f[ifile].b.size();
    if(ifile>0 && (unsigned int)nBranches != f[ifile-1].b.size()){
      cout<<endl<<"number of branches must be the same for each file"<<endl;
      cout<<"nBraches = "<<nBranches<<" for "<<f[ifile].name\
          <<" and  = "<<f[ifile-1].b.size()<<" for "<<f[ifile-1].name<<endl;
      exit(EXIT_FAILURE);
    } 
    //declare cuts
    cout<<"cuts... ";
    TCut cLL="", cDD="", coptimized="", ctight="", coptimizedbelow="", ctightbelow="",  coptimizednoPT="", ctightnoPT="";
    makecuts(ifile,cLL,cDD,coptimized,ctight,coptimizedbelow,ctightbelow,coptimizednoPT,ctightnoPT);
    cout<<"done"<<endl;
    
    for(int ibranch=0; ibranch<nBranches; ibranch++){
      branch * thisbranch = &f[ifile].b[ibranch];
      cout<<"cuts for branch "<<thisbranch->name<<"... ";
      //assign cuts
      thisbranch->c ={{coptimized,"Optimized: cos()>0.999993 with #Lambda_{p_{T}}>1300 LL or >2100 DD"}, \
                      {ctight,"Tight: cos()>0.999999 with #Lambda_{p_{T}}>6000 LL or >7000 DD"}, \
                      {coptimizedbelow,"Optimized with #Lambda_{p_{T}} > #rightarrow <"}, \
                      {ctightbelow,"Tight with #Lambda_{p_{T}} > #rightarrow <"}, \
                      {coptimizednoPT,"Optimized without #Lambda_{p_{T}} cut"}, \
                      {ctightnoPT,"Tight without #Lambda_{p_{T}} cut"}};
      

      nCuts = thisbranch->c.size();
      
      if(ibranch>0 && (unsigned int)nCuts != f[ifile].b[ibranch-1].c.size()){
        cout<<endl<<"number of cuts must be the same for each branch"<<endl;
        cout<<"nCuts = "<<nCuts<<" for "<<f[ifile].name<<", "<<thisbranch->name \
            <<" and  = "<<f[ifile].b[ibranch-1].c.size()<<" for "<<thisbranch->name<<endl;
        exit(EXIT_FAILURE);
      }

      //add LL or DD cuts for branches specified as LL or DD
      for(int icut=0;icut<nCuts;icut++){
        cut * thiscut = &(thisbranch->c[icut]);
        if(thisbranch->name.Contains("LL")){
          thiscut->self=(thiscut->self)&&cLL;
          thiscut->name+=" LL";
        } else if(thisbranch->name.Contains("DD")){
          thiscut->self=(thiscut->self)&&cDD;
          thiscut->name+=" DD";
        }
      }
         
      cout<<"done"<<endl;
    }
  }
  //----------done---------//  
  
  //-------assign layers, etc.---------//
  cout<<"assigning layers... ";
  int nLayers=3;//file, branch, cuts
  vector<layer> L(nLayers);
  L[0].name="decaymode";
  L[1].name="branch";
  L[2].name="cut";
  int bL=0;//index corresponding to branch layer, initialized to avoid compiler warnings
  int cL=0;//index corresponding to cut layer, initialized to avoid compiler warnings
  int nCanvases=1;//actual value assigned below
  for(int i =0; i<nLayers; i++){
    //assign layers; this is not an algorithm 
    if(L[i].name=="decaymode") {
      for(int j=0;j<nFiles;j++) {
        L[i].add_element(&f[j].quality["decaymode"]);
      }
    }else if(L[i].name=="branch") {
      bL=i;
      for(int k=0;k<nBranches;k++) {
        L[i].add_element(&f[0].b[k].name);//all files have the same named branches
        if(f[0].b[k].name.Contains("#Lambda_{b} p_{T}"))
          L[i].add_comparison(&f[0].b[k].name,&f[0].b[k+3].name);//want to compare pT and mass; uses order I list them above
      }
    }else if(L[i].name=="cut") {
      cL=i;
      for(int l=0;l<nCuts;l++) {
        L[i].add_element(&f[0].b[0].c[l].name);//all branches of all files have the same named cuts
      }
    }
    if(!L[i].comparison.empty()) {
      L[i].compared = kTRUE;
      L[i].nLec = L[i].comparison.size();
    }else L[i].nLec = L[i].element.size();
    L[i].nL=L[i].element.size();
    
    //calculate nCanvases
    nCanvases *= L[i].nLec;
  }
  nCanvases*=2;//because TH2F and also graph
  cout<<"done"<<endl<<"nFiles = "<<nFiles<<", nBranches = "<<nBranches<<", nCuts = "<<nCuts<<endl;
  cout<<"nLayers = "<<nLayers<<", nCanvases = "<<nCanvases<<endl;
  //------------done-----------//
  //------------------------------------canvas loop-----------------------------//
  //create necessary counters, canvases, legends, etc.
  cout<<endl<<"creating canvasy things... ";
  vector<TCanvas*> c(nCanvases);//each canvas holds one stack of histograms
  vector<TH2F*> h(nCanvases);
  TCanvas *cf = new TCanvas("cf","combined");//canvas to hold everything
  float sqnc = sqrt(nCanvases), sqncu = ceil(sqnc), sqncd = floor(sqnc);
  while(sqncu*sqncd<nCanvases) sqncu++;
  cf->Divide(sqncu,sqncd);//canvas divided to be able to hold all other canvases
  //calculate plL (product of lower layers) (helps iterate L[i].Li)
  for(int i=0; i<nLayers; i++){ 
    for(int j=(nLayers-1); j>i; j--){
      if(!L[i].compared){//non-compared need product of all lower levels
        L[i].plL*=L[j].nL;
        L[i].plLec*=L[j].nLec;
        if(!(L[j].name=="cut"||L[j].name=="branch")){
          L[i].plLx*=L[j].nL;
          L[i].plLecx*=L[j].nLec;
        }
      }else if(L[j].compared){//compared need product of all lower compared levels
        L[i].plL*=L[j].nL;
        L[i].plLec*=L[j].nLec;
        if(!(L[j].name=="cut"||L[j].name=="branch")){
          L[i].plLx*=L[j].nL;
          L[i].plLecx*=L[j].nLec;
        }
      }      
    }
    if(!L[i].compared){//non-compared need
      for(int k=0; k<i; k++){//product of all higher
        if(L[k].compared){//compared levels
          L[i].plL*=L[k].nL;
          L[i].plLec*=L[k].nLec;
          if(!(L[k].name=="cut"||L[k].name=="branch")){
            L[i].plLx*=L[k].nL;
            L[i].plLecx*=L[k].nLec;
          }
        }
      }
    }
  }

  int pli=0;//this counts the number of plots generated; helps iterate L[i].Li
  cout<<"done"<<endl;

  cout<<endl<<"starting canvas loop..."<<endl;
  //actual start of the loop
  for(int ci=0; ci<nCanvases; ci++){
    cout<<ci+1<<" out of "<<nCanvases<<endl;
    
    //create necessary canvasy things
    TString cistring = Form("%d",ci);
    placeholder = "c"+cistring;
    c[ci] = new TCanvas(placeholder,placeholder,1200,800); //create the canvases
    c[ci]->cd();
    gStyle->SetOptStat("");
    //decide which file to use
    int file_num=0;
    for(int i=0;i<nLayers;i++)
      if(!(L[i].name=="cut"||L[i].name=="branch"))//cuts and branches do not get their own files
        file_num += L[i].Li*L[i].plLecx;
    cout<<"creating strings and pointers for canvas loop... ";
    //create convenient strings
    TString hname = "h"+cistring;
    //create convenient pointers
    file * thisfile = &(f[file_num]);
    branch * thisbranchx = &(thisfile->b[L[bL].Li]);//lazy; this only works for both branches being from the same file
    branch * thisbranchy = &(thisfile->b[L[bL].Li+3]);//lazy; uses the way I assigned the branches to avoid being clever
    cut * thiscut = &(thisbranchx->c[L[cL].Li]);//should be the same for both branches
    cout<<"done"<<endl;

    //loop over layers
    cout<<"labelling... ";
    TString title;
    for(int i=0;i<nLayers;i++){
      if(!(L[i].name=="branch")){//lazy; I know branch goes in axis title
        if(title!="") title+=": ";
        title+=*L[i].element[L[i].Li];//non-compared goes in title
      }
    }
    cout<<"done"<<endl;
    //draw histogram/graph
    placeholder = thisbranchy->self+":"+thisbranchx->self;
    if(ci%2==0){//create histogram
      cout<<"creating histogram... ";
      h[ci] = new TH2F(hname,title,thisbranchx->nBins,thisbranchx->loBin,thisbranchx->hiBin, \
                       thisbranchy->nBins,thisbranchy->loBin,thisbranchy->hiBin);
      h[ci]->SetXTitle(thisbranchx->name);//lazy; only works since I know I'm comparing branches
      h[ci]->SetYTitle(thisbranchy->name);
      cout<<"done"<<endl;
      cout<<"drawing histogram... ";
      thisfile->t[0]->Project(hname,placeholder,thiscut->self);//one tree per file
      c[ci]->cd();
      h[ci]->Draw("COLZ");
    }else{//create graph
      cout<<"drawing graph...";
      placeholder2=massname[file_num]+">0";
      thisfile->t[0]->Draw(placeholder,(thiscut->self)&&placeholder2);
      TGraph *graph = (TGraph*)gPad->GetPrimitive("Graph");
      c[ci]->cd();
      graph->Draw("*");
    }
    cout<<"done"<<endl;
    if(ci%2==1){//we only iterate after the graphs are drawn
      pli++;//iterate the number of plots that have been drawn
      //loop over layers
      for(int i=0;i<nLayers;i++){
        //iterate layer counters
        if(L[i].plLec==1)L[i].Li++;//if it's at the lowest hierarchy, iterate
        else if((pli%L[i].plLec==0)&&(pli!=0))L[i].Li++;//if all variations of plots lower than it have been plotted, iterate
        if(L[i].Li==L[i].nLec) L[i].Li=0;//reset the iteration if it's reached the end
      }//end layer loop
    }
    
    cf->cd(ci+1);
    c[ci]->DrawClonePad();
    //save stuff:
    cout<<"saving files... ";
    placeholder = outputlocation+filename+"(";//the closing page is added after the loop
    c[ci]->Print(placeholder);
    if(runmode.Contains("C")){
      placeholder = outputlocation+"c"+cistring+"_"+title+".C";
      c[ci]->SaveAs(placeholder);
    }
    cout<<"done"<<endl<<endl;
  }//end canvas loop
  cf->cd();
  placeholder = outputlocation+filename+")";
  cf->Print(placeholder);
  gROOT->SetBatch(kFALSE);
  cout<<"done"<<endl;
}