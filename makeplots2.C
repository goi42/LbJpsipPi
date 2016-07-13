/*
This program is a variant on makeplots.C that uses layer, file, branch, and cut classes instead of inelegant sets of vectors.
This also dispenses with the UI in makeplots in favor of just coding the cuts and such you want.
It suffers from a need for there to be the same number of branches and cuts for every file and branch.
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

// local
#include "/afs/cern.ch/user/m/mwilkins/algorithms/branch.h"
#include "/afs/cern.ch/user/m/mwilkins/algorithms/cut.h"
#include "/afs/cern.ch/user/m/mwilkins/algorithms/file.h"
#include "/afs/cern.ch/user/m/mwilkins/algorithms/layer.h"
#include "makecuts.C"

void makeplots2(TString runmode ="d", TString drawopt=""){
  gROOT->SetBatch(kTRUE);
  // gROOT->ProcessLine(".x /afs/cern.ch/user/m/mwilkins/cmtuser/src/lhcbStyle.C");
  TString placeholder;//this is to avoid adding strings in functions; assign right before use
  TString placeholder2;
  TString placeholder3;
  //default parameters
  TString outputlocation="./";
  TString filename="plots.pdf";

  //-----assign files, branches, cuts-------//
  cout<<"files... ";
  map<TString,TString> f1quality {{"filetype","data"},{"decaymode","data (both)"}};
  map<TString,TString> f2quality {{"filetype","MC"},{"decaymode","#Lambda"}};
  map<TString,TString> f3quality {{"filetype","MC"},{"decaymode","#Sigma^{0}"}};
  map<TString,TString> f4quality {{"filetype","MC"},{"decaymode","#Lambda*(1405)"}};
  map<TString,TString> f5quality {{"filetype","MC"},{"decaymode","#Lambda only"}};
  map<TString,TString> f6quality {{"filetype","MC"},{"decaymode","#Lambda (minbias)"}};
  file f[]={								\
    {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/subLimDVNtuples.root","data",f1quality}, 
    {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/LMC_tuples_with_gd_info.root","#Lambda MC",f2quality}, 
    {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/SMC_tuples_with_gd_info.root","#Sigma^{0} MC",f3quality},
    // {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/PV_L/DVNtuples_L.root","#Lambda minbias MC",f6quality}, 
  };
    // {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/onlylambda/DVNtuples.root","#Lambda only MC",f5quality},
    // {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/Lst/1405_fullMC/Lb_JpsiLambda_mmSpi_1405_200000.root","Lst(1405)MC",f4quality},
  
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
    cout<<"trees... ";
    if(f[ifile].quality["decaymode"]=="#Lambda (minbias)")
      f[ifile].add_tree("L2ppiTree/mytree");
    else if(f[ifile].quality["decaymode"]=="#Lambda only")
      f[ifile].add_tree("LTree/mytree");
    else      
      f[ifile].add_tree("Lb2JpsiLTree/mytree"); //make sure these names are correct
    cout<<"done"<<endl;
    placeholder2 = Lbname[ifile]+"_P";
    cout<<"branches for file "<<f[ifile].name<<"... ";
    placeholder3 = Lbname[ifile]+"_PT";
    f[ifile].b={
      // {"R_MINIP","#Lambda MINIP",35,-1,6},
      // {"R_MINIPCHI2","#Lambda MINIP #chi^{2}",100,-100,900},
      // {"R_MINIPNEXTBEST","#Lambda MINIP (next best)",110,-2,20},
      // {"R_MINIPCHI2NEXTBEST","#Lambda MINIP (next best) #chi^{2}",100,-500,3500},
      // {"R_ENDVERTEX_X","#Lambda endvertex X",100,-175,175},
      // {"R_ENDVERTEX_Y","#Lambda endvertex Y",100,-175,175},
      // {"R_ENDVERTEX_Z","#Lambda endvertex Z",305,-50,3000},
      // {"R_ENDVERTEX_XERR","#Lambda endvertex error X",110,-1,10},
      // {"R_ENDVERTEX_YERR","#Lambda endvertex error Y",110,-1,10},	  
      // {"R_ENDVERTEX_ZERR","#Lambda endvertex error Z",165,-5,160},
      // {"sqrt(R_ENDVERTEX_XERR*R_ENDVERTEX_XERR+R_ENDVERTEX_YERR*R_ENDVERTEX_YERR)","#Lambda endvertex error x&y",78,-1,15},
      // {"R_ENDVERTEX_CHI2","#Lambda endvertex #chi^{2}",130,-1,12},
      // {"R_ENDVERTEX_NDOF","#Lambda endvertex ndof",10,0,10},
      // {"R_OWNPV_X","#Lambda PV X",100,0,1},
      // {"R_OWNPV_Y","#Lambda PV Y",50,-0.2,0.3},	  
      // {"R_OWNPV_Z","#Lambda PV Z",100,-250,250},	  
      // {"R_OWNPV_XERR","#Lambda PV error X",50,0,0.05},
      // {"R_OWNPV_YERR","#Lambda PV error Y",50,0,0.05},	  
      // {"R_OWNPV_ZERR","#Lambda PV error Z",50,0,0.5},
      // {"sqrt(R_OWNPV_XERR*R_OWNPV_XERR+R_OWNPV_YERR*R_OWNPV_YERR)","#Lambda PV error x&y",60,0,0.06},
      // {"R_OWNPV_CHI2","#Lambda PV #chi^{2}",120,0,120},
      // {"R_OWNPV_NDOF","#Lambda PV ndof",158,0,316},
      // {"R_IP_OWNPV","#Lambda PV IP",35,-1,6},
      // {"R_IPCHI2_OWNPV","#Lambda PV IP #chi^{2}",100,-100,900},
      // {"R_FD_OWNPV","#Lambda FD (OWNPV)",100,-100,3000},
      // {"R_FDCHI2_OWNPV","#Lambda FD #chi^{2} (OWNPV)",100,-5000,75000},
      // {"-R_DIRA_OWNPV","-cos(angle #Lambda_{p} and OWNPV)",100,-1.00000025,-0.99999},
      // {"R_TOPPV_X","#Lambda top PV X",100,0,1},
      // {"R_TOPPV_Y","#Lambda top PV Y",100,-0.2,0.35},
      // {"R_TOPPV_Z","#Lambda top PV Z",100,-220,220},
      // {"R_TOPPV_XERR","#Lambda top PV XERR",100,0,0.05},
      // {"R_TOPPV_YERR","#Lambda top PV YERR",100,0,0.05},
      // {"R_TOPPV_ZERR","#Lambda top PV ZERR",100,0,0.3},
      // {"R_TOPPV_CHI2","#Lambda top PV #chi^{2}",100,-10,300},
      // {"R_TOPPV_NDOF","#Lambda top PV ndof",158,0,316},
      // {"R_IP_TOPPV","#Lambda top PV IP",50,-5,45},
      // {"R_IPCHI2_TOPPV","#Lambda top PV IP #chi^{2}",100,-2000,16000},
      // {"R_FD_TOPPV","#Lambda top PV FD",100,-100,3000},
      // {"R_FDCHI2_TOPPV","#Lambda top PV FD #chi^{2}",100,-20000,200000},
      // {"-R_DIRA_TOPPV","-cos(angle #Lambda_{p} and TOPPV)",100,-1.00000025,-0.99999},
      // {"R_P","#Lambda_{p}",144,0,270000},
      // {"R_PT","#Lambda_{p_{T}}",110,0,11000},
      // {"R_PE","#Lambda_{p_{E}}",100,0,300000},
      // {"R_PX","#Lambda_{p_{X}}",100,-10000,10000},
      // {"R_PY","#Lambda_{p_{Y}}",100,-10000,10000},
      // {"R_PZ","#Lambda_{p_{Z}}",100,0,300000},
      // {"R_MM","#Lambda MM",100,1081,1150},
      // {"R_MMERR","#Lambda MM error",100,0,8},
      // {"R_M","#Lambda^{0} M",70,1085,1150},
      // {"R_WM","#Lambda^{0} M with p#rightarrow#pi",80,300,700}, 
      // {"H1_OWNPV_X","p PV X",90,0,0.9},	  
      // {"H1_OWNPV_Y","p PV Y",50,-0.2,0.3},	  
      // {"H1_OWNPV_Z","p PV Z",500,-250,250},	  
      // {"H1_OWNPV_XERR","p PV error X",60,0,0.06},
      // {"H1_OWNPV_YERR","p PV error Y",60,0,0.06},	  
      // {"H1_OWNPV_ZERR","p PV error Z",350,0,0.35},	  
      // {"H2_OWNPV_X","#pi PV X",90,0,0.9},
      // {"H2_OWNPV_Y","#pi PV Y",50,-0.2,0.3},	  
      // {"H2_OWNPV_Z","#pi PV Z",500,-250,250},	  
      // {"H2_OWNPV_XERR","#pi PV error X",60,0,0.06},
      // {"H2_OWNPV_YERR","#pi PV error Y",60,0,0.06},	  
      // {"H2_OWNPV_ZERR","#pi PV error Z",350,0,0.35},	  
      // {massname[ifile],"#Lambda_{b} MM",400,4100,6100},       
      {massname[ifile],"#Lambda_{b} MM LL",400,4100,6100},    
      {massname[ifile],"#Lambda_{b} MM DD",400,4100,6100}     
      // {placeholder2,"#Lambda_{b} p",160,0,800000},         
      // {placeholder2,"#Lambda_{b} p LL",160,0,800000},         
      // {placeholder2,"#Lambda_{b} p DD",160,0,800000},         
      // {placeholder3,"#Lambda_{b} p_{T}",120,0,60000},         
      // {placeholder3,"#Lambda_{b} p_{T} LL",120,0,60000},      
      // {placeholder3,"#Lambda_{b} p_{T} DD",120,0,60000}       
      // {placeholder2,"#Lambda_{b} p",160000,0,800000},      
      // {placeholder2,"#Lambda_{b} p LL",160000,0,800000},   
      // {placeholder2,"#Lambda_{b} p DD",160000,0,800000},   
      // {placeholder3,"#Lambda_{b} p_{T}",12000,0,60000},    
      // {placeholder3,"#Lambda_{b} p_{T} LL",12000,0,60000}, 
      // {placeholder3,"#Lambda_{b} p_{T} DD",12000,0,60000}, 
      // {placeholder2,"#Lambda_{b} BKGCAT",131,0,131},       
      // {placeholder3,"#Lambda_{b} p_{T}",4000,0,20000},     
      // {"J_psi_1S_MM","J/#psi(1S) MM",48,2980,3220},        
      // {"J_psi_1S_ENDVERTEX_CHI2/J_psi_1S_ENDVERTEX_NDOF","#chi^{2}/ndof(J/#psi(1S))",210,0,21}, 
      // {"H2_TRACK_GhostProb","#pi track GhostProb",100,0,1}, 
      // {"H1_TRACK_GhostProb","p track GhostProb",100,0,1},  
      // {"muplus_TRACK_GhostProb","#mu^{+} track GhostProb",100,0,1}, 
      // {"muminus_TRACK_GhostProb","#mu^{-} track GhostProb",100,0,1}
    };
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
    TCut cLL,cDD,ctrigger,c070116_LL,c070116_DD;
    makecuts(ifile,cLL,cDD,ctrigger,c070116_LL,c070116_DD);
    cout<<"done"<<endl;
    
    for(int ibranch=0; ibranch<nBranches; ibranch++){
      branch * thisbranch = &f[ifile].b[ibranch];
      cout<<"cuts for branch "<<thisbranch->name<<"... ";
      //assign cuts
      thisbranch->add_cut(c070116_LL,"7/1/16 LL cuts");
      thisbranch->add_cut(c070116_DD,"7/1/16 DD cuts");
      nCuts = thisbranch->c.size();
      
      if(ibranch>0 && (unsigned int)nCuts != f[ifile].b[ibranch-1].c.size()){
        cout<<endl<<"number of cuts must be the same for each branch"<<endl;
        cout<<"nCuts = "<<nCuts<<" for "<<f[ifile].name<<", "<<thisbranch->name \
            <<" and  = "<<f[ifile].b[ibranch-1].c.size()<<" for "<<f[ifile].b[ibranch-1].name<<endl;
        exit(EXIT_FAILURE);
      }

      //add LL or DD cuts for branches specified as LL or DD
      for(int icut=0;icut<nCuts;icut++){
        cut * thiscut = &(thisbranch->c[icut]);
        if(thisbranch->name.Contains("LL")){
          thiscut->self=(thiscut->self)&&cLL;
          // thiscut->name+=" LL"; //all cuts must have the same name
        } else if(thisbranch->name.Contains("DD")){
          thiscut->self=(thiscut->self)&&cDD;
          // thiscut->name+=" DD"; //all cuts must have the same name
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
  L[0].name="file";
  L[1].name="cut";
  L[2].name="branch";
  int bL=0;//index corresponding to branch layer, initialized to avoid compiler warnings
  int cL=0;//index corresponding to cut layer, initialized to avoid compiler warnings
  int nhpc=1;//actual value assigned below
  int nCanvases=1;//actual value assigned below
  for(int i =0; i<nLayers; i++){
    //assign layers; this is not an algorithm 
    if(L[i].name=="file") {
      for(int j=0;j<nFiles;j++) {
        L[i].add_element(&f[j].name);
      }
    }else if(L[i].name=="branch") {
      L[i].compared=kTRUE;
      bL=i;
      for(int k=0;k<nBranches;k++) {
        L[i].add_element(&f[0].b[k].name);//all files have the same named branches
      }
    }else if(L[i].name=="cut") {
      L[i].compared=kTRUE;
      cL=i;
      for(int l=0;l<nCuts;l++)
	L[i].add_element(&f[0].b[0].c[l].name);//all branches have the same named cuts
    }
    L[i].nL=L[i].element.size();

    //calculate nhpc and nCanvases
    if(L[i].compared) nhpc *= L[i].nL;
    else nCanvases *= L[i].nL;
  }
  cout<<"done"<<endl<<"nFiles = "<<nFiles<<", nBranches = "<<nBranches<<", nCuts = "<<nCuts<<endl;
  cout<<"nLayers = "<<nLayers<<", nCanvases = "<<nCanvases<<", nhpc = "<<nhpc<<endl;
  //------------done-----------//
  //------------------------------------canvas loop-----------------------------//
  //create necessary counters, canvases, legends, etc.
  cout<<endl<<"creating canvasy things... ";
  vector<TCanvas*> c(nCanvases);//each canvas holds one stack of histograms
  vector<TLegend*> leg(nCanvases);//one legend per canvas
  vector<THStack*> hs(nCanvases);//one stack per canvas
  vector< vector<TH1F*> > h;
  h.resize(nCanvases, vector<TH1F*>(nhpc));
  TCanvas *cf = new TCanvas("cf","combined");//canvas to hold everything
  float sqnc = sqrt(nCanvases), sqncu = ceil(sqnc), sqncd = floor(sqnc);
  while(sqncu*sqncd<nCanvases) sqncu++;
  cf->Divide(sqncu,sqncd);//canvas divided to be able to hold all other canvases
  //calculate plL (product of lower layers) (helps iterate L[i].Li)
  //this name made more sense when the order layers were specified mattered
  //now, compared layers must iterate most frequently and non-compared less frequently
  //the if statements below allow the user to specify what layers to use in any order
  //        instead of just iterating the last most frequently
  for(int i=0; i<nLayers; i++){ 
    for(int j=(nLayers-1); j>i; j--){
      if(!L[i].compared){//non-compared need product of all lower levels
        L[i].plL*=L[j].nL;
        if(!(L[j].name=="cut"||L[j].name=="branch")) L[i].plLx*=L[j].nL;
      }else if(L[j].compared){//compared need product of all lower compared levels
        L[i].plL*=L[j].nL;
        if(!(L[j].name=="cut"||L[j].name=="branch")) L[i].plLx*=L[j].nL;
      }      
    }
    if(!L[i].compared){//non-compared need
      for(int k=0; k<i; k++){//product of all higher
        if(L[k].compared){//compared levels
          L[i].plL*=L[k].nL;
          if(!(L[k].name=="cut"||L[k].name=="branch")) L[i].plLx*=L[k].nL;
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
    gPad->SetLogy();
    gStyle->SetOptStat("");
    // leg[ci] = new TLegend(0.41, 0.7, 0.85, 0.9);//create legend
    leg[ci] = new TLegend(0.65, 0.7, 1, 0.9);//create legend
    placeholder = "hs"+cistring;
    hs[ci] = new THStack(placeholder,placeholder); //create the stack to hold the histograms
    TString stacktitle="";

    //histogram loop
    for(int hi=0; hi<nhpc; hi++){
      //decide which file to use
      int file_num=0;
      for(int i=0;i<nLayers;i++)
        if(!(L[i].name=="cut"||L[i].name=="branch"))//cuts and branches do not get their own files
          file_num += L[i].Li*L[i].plLx;
      cout<<"creating strings and pointers for histogram loop "<<hi+1<<"/"<<nhpc<<"... ";
      //create convenient strings
      TString histring = Form("%d",hi);
      TString hname = "h"+cistring+histring;
      //create convenient pointers
      file * thisfile = &(f[file_num]);
      branch * thisbranch = &(thisfile->b[L[bL].Li]);
      cut * thiscut = &(thisbranch->c[L[cL].Li]);
      cout<<"done"<<endl;
      //create histogram
      cout<<"creating histogram "<<hi+1<<"... ";
      h[ci][hi] = new TH1F(hname,thisbranch->name,thisbranch->nBins,thisbranch->loBin,thisbranch->hiBin);
      cout<<"done"<<endl;
      //draw histograms
      cout<<"drawing histogram "<<hi+1<<"... ";
      h[ci][hi]->SetLineColor(hi+1);
      if((hi+1==5)||(hi+1==10)) h[ci][hi]->SetLineColor(hi+21);
      placeholder = thisbranch->self+">>"+hname;
      thisfile->t[0]->Draw(placeholder,thiscut->self,drawopt);//one tree per file
      cout<<"done"<<endl;
      pli++;//iterate the number of plots that have been drawn
      cout<<"stacking histogram "<<hi+1<<"... ";
      hs[ci]->Add(h[ci][hi]);//stack histograms
      cout<<"done"<<endl;
      
      //loop over layers
      cout<<"creating legend "<<hi+1<<"... ";
      TString leglabel="";
      for(int i=0;i<nLayers;i++){
        //determine the name of the stack title
        if(L[i].compared){//compared layers in the legend entry
          if(leglabel!="") leglabel+=", ";
          leglabel+= *(L[i].element[L[i].Li]);
        }else if(hi==0){//since stacktitle reflects non-compared layers, it only needs to change per canvas
          if(stacktitle!="") stacktitle+=": ";
          stacktitle+= *(L[i].element[L[i].Li]);//non-compared goes in title
        }

        //iterate layer counters
        if(L[i].plL==1)L[i].Li++;//if it's at the lowest hierarchy, iterate
        else if((pli%L[i].plL==0)&&(pli!=0))L[i].Li++;//if all variations of plots lower than it have been plotted, iterate
        if(L[i].Li==L[i].nL) L[i].Li=0;//reset the iteration if it's reached the end
      }//end layer loop

      //fill legends
      leg[ci]->AddEntry(h[ci][hi],leglabel,"l");
      cout<<"done"<<endl;
    }//end histogram loop

    //draw stacked histograms
    cout<<"drawing stack "<<ci+1<<": "<<stacktitle<<"... ";
    hs[ci]->SetTitle(stacktitle);
    hs[ci]->Draw("nostack");
    if(leg[ci]->GetNRows()>0) leg[ci]->Draw();//you don't need a legend if nothing's compared
    cf->cd(ci+1);
    c[ci]->DrawClonePad();
    cout<<"done"<<endl;
    //save stuff:
    cout<<"saving files... ";
    placeholder = outputlocation+filename+"(";//the closing page is added after the loop
    c[ci]->Print(placeholder);
    if(runmode.Contains("C")){
      placeholder = outputlocation+"c"+cistring+"_"+stacktitle+".C";
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
  
