/*
This is a variant on makeplots2.C that does not require the same number of branches and cuts per file and branch.
It does not do the fancy comparisons that makeplots.C and makeplots2.C do, however.
It is good for comparing cuts on a single branch.
It loops over files, then branches, then cuts, assigning branches and cuts in each 
of these loops, and plotting the cuts as they come.
Each branch gets its own canvas.
\r is apparently the character to print things over previous things, btw.
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
#include "makecuts.C"
#include "/afs/cern.ch/user/m/mwilkins/algorithms/branch.h"
#include "/afs/cern.ch/user/m/mwilkins/algorithms/cut.h"
#include "/afs/cern.ch/user/m/mwilkins/algorithms/file.h"
#include "MyClass.C"

void makeplots3(TString runmode="d", TString drawopt=""){
  gROOT->SetBatch(kTRUE);
  ROOT::v5::TFormula::SetMaxima(10000);//to allow for many operators within cuts
  MyClass t;
  TString placeholder;//this is to avoid adding strings in functions; assign right before use
  TString placeholder2;
  TString placeholder3;
  TString outputlocation="./";
  TString basename="compcuts";
  TString filename=basename+".pdf";
  // ofstream myfile;
  // TString trueratiostring="";//holds information to be put at end of myfile
  // myfile.open(outputlocation+basename+".csv");
  // myfile<<"dataset,branch,cuts,siglo,sighi,bkglo,bkghi,number signal,number background,Nsig^2/Nbkg"<<endl;
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
  map<TString,TString> f2quality {{"filetype","MC"},{"decaymode","#Lambda"}};
  map<TString,TString> f3quality {{"filetype","MC"},{"decaymode","#Sigma^{0}"}};
  map<TString,TString> f4quality {{"filetype","MC"},{"decaymode","#Lambda*(1405)"}};
  map<TString,TString> f5quality {{"filetype","MC"},{"decaymode","#Lambda only"}};
  map<TString,TString> f6quality {{"filetype","MC"},{"decaymode","#Lambda (minbias)"}};
  map<TString,TString> f7quality {{"filetype","data"},{"decaymode","#B_{s}"}};
  file f[]={
    {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/Bs2JpsiKst/cutfile_Liming_selection_cuts_test.root","Bsdata",f7quality},
    // {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/subLimDVNtuples.root","data",f1quality},
    // {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/LMC_tuples_with_gd_info.root","#Lambda MC",f2quality},
    // {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/SMC_tuples_with_gd_info.root","#Sigma^{0} MC",f3quality},
    // {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/withKScut/PV_L/DVNtuples_L.root","#Lambda minbias MC",f6quality},
  };
    // {"/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/onlylambda/DVNtuples_withJpsitrigger.root","#Lambda only MC",f5quality},

  int nFiles = (sizeof(f)/sizeof(f[0]));
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

  // int idatafile=0;//to store the index of the data file; initialized to avoid compiler warnings
  // int iLMCfile=0;//to store the index of the L0 file; initialized to avoid compiler warnings
  // int iSMCfile=0;//to store the index of the sig0 file; initialized to avoid compiler warnings
  cout<<"Starting file loop..."<<endl;
  for(int ifile=0;ifile<nFiles;ifile++){
    // myfile<<f[ifile].name;
    cout<<"trees... ";
    f[ifile].add_tree("mytree");
    // if(f[ifile].quality["decaymode"]=="#Lambda (minbias)")
    //   f[ifile].add_tree("L2ppiTree/mytree");
    // else if(f[ifile].quality["decaymode"]=="#Lambda only")
    //   f[ifile].add_tree("LTree/mytree");
    // else      
    //   f[ifile].add_tree("Lb2JpsiLTree/mytree"); //make sure these names are correct
    cout<<"done"<<endl;
    //store file indices
    // if(f[ifile].name=="data") idatafile = ifile;
    // else if(f[ifile].name=="#Lambda MC") iLMCfile = ifile;
    // else if(f[ifile].name=="#Sigma^{0} MC") iSMCfile = ifile;
    cout<<"Using "<<f[ifile].name<<"..."<<endl;
    placeholder3 = Lbname[ifile]+"_PT";
    f[ifile].b={
      {"sqrt(pow(J_psi_1S_PE+R_PE,2)-pow(J_psi_1S_PX+R_PX,2)-pow(J_psi_1S_PY+R_PY,2)-pow(J_psi_1S_PZ+R_PZ,2))","m(J/#psi K*)",520,3800,6400},	
      // {massname[ifile],"B_{s} mass",520,3800,6400},	
      // {"Added_n_Particles",210,0,210},
      // {"Added_CharmH_M[0]",320,0,16000},
      // {"Added_CharmH_M_pion[0]",320,0,16000},
      // {"Added_CharmH_M_kaon[0]",320,0,16000},
      // {"Added_CharmH_M_proton[0]",320,0,16000},
      // {"Added_CharmH_PT[0]",300,0,30000},
      // {"Added_CharmH_ETA[0]",100,0,10},
      // {"Added_CharmH_PHI[0]",100,-4,4},
      // {"Added_CharmH_FDCHI2_OLD[0]",220,0,80000},
      // {"Added_CharmH_FDCHI2_NEW[0]",500,0,250},
      // {"Added_CharmH_FD_OLD[0]",250,0,250},
      // {"Added_CharmH_FD_NEW[0]",100,0,70000},
      // {"Added_CharmH_VERTEXCHI2_OLD[0]",300,0,6},
      // {"Added_CharmH_VERTEXCHI2_NEW[0]",300,0,500},
      // {"Added_CharmH_VERTEX_X_NEW[0]",480,-4,4},
      // {"Added_CharmH_VERTEX_Y_NEW[0]",480,-4,4},
      // {"Added_CharmH_VERTEX_Z_NEW[0]",400,-200,200},
      // {"Added_CharmH_PV_X_NEW[0]",250,0.2,0.7},
      // {"Added_CharmH_PV_Y_NEW[0]",200,-0.2,0.2},
      // {"Added_CharmH_PV_Z_NEW[0]",400,-200,200},
      // {"Added_CharmH_VERTEX_COV_XX[0]",300,0,0.001},
      // {"Added_CharmH_PV_COV_XX[0]",300,0,0.0015},
      // {"Added_CharmH_VERTEX_COV_XY[0]",300,-0.0005,0.0005},
      // {"Added_CharmH_PV_COV_XY[0]",300,-0.00004,0.00004},
      // {"Added_CharmH_VERTEX_COV_XZ[0]",300,-0.01,0.01},
      // {"Added_CharmH_PV_COV_XZ[0]",300,-0.0025,0.0025},
      // {"Added_CharmH_VERTEX_COV_YY[0]",300,0,0.0012},
      // {"Added_CharmH_PV_COV_YY[0]",300,0,0.0008},
      // {"Added_CharmH_VERTEX_COV_YZ[0]",300,-0.015,0.015},
      // {"Added_CharmH_PV_COV_YZ[0]",300,-0.002,0.002},
      // {"Added_CharmH_VERTEX_COV_ZZ[0]",300,0,0.3},
      // {"Added_CharmH_PV_COV_ZZ[0]",300,0,0.05},
      // {"Added_CharmH_VertexRefitStatus[0]",30,0,2},
      // {"Added_CharmH_IPCHI2_OLD[0]",200,0,5000},
      // {"Added_CharmH_IP_OLD[0]",300,0,30},
      // {"Added_CharmH_IPCHI2_NEW[0]",200,0,4000},
      // {"Added_CharmH_IP_NEW[0]",300,0,30},
      // {"Added_CharmH_MINIPCHI2[0]",400,0,100},
      // {"Bs_H_OPENING[0]",180,0,90},
      // {"Added_H_PT[0]",200,0,4000},
      // {"Added_H_ETA[0]",200,0,10},
      // {"Added_H_PHI[0]",200,-5,5},
      // {"Added_H_THETA[0]",400,0,0.4},
      // {"Added_H_DELTAPHI[0]",280,-7,7},
      // {"abs(Added_H_PID)[0]",40,200,220},
      // {"Added_n_Tracks",200,0,200},
      // {"abs(Added_H_PROBNNPID)[0]",500,0,250},
      // {"Added_H_GHOST[0]",200,0,1},
      // {"Added_H_TRACKCHI2[0]",70,0,3,5},
      // {"Added_H_TRACKTYPE[0]",10,0,5},
      // {"Added_H_PIDe[0]",120,-20,20},
      // {"Added_H_PIDK[0]",140,-70,70},
      // {"Added_H_PIDmu[0]",300,-15,15},
      // {"Added_H_PIDp[0]",280,-70,70},
      // {"Added_H_ProbNNpi[0]",100,0,1},
      // {"Added_H_ProbNNk[0]",100,0,0.12},
      // {"Added_H_ProbNNp[0]",100,0,0.1},
      // {"Added_H_ProbNNe[0]",100,0,0.01},
      // {"Added_H_ProbNNmu[0]",100,0,0.5},
      // {massname[ifile],"#Lambda_{b} mass (PV) LL",400,4100,6100},	
      // {massname[ifile],"#Lambda_{b} mass (endV) LL",400,4100,6100},
      // {massname[ifile],"#Lambda_{b} mass (PV) DD",400,4100,6100},
      // {massname[ifile],"#Lambda_{b} mass (endV) DD",400,4100,6100},
      // {massname[ifile],"#Lambda_{b} mass LL",400,4100,6100}, 
      // {massname[ifile],"#Lambda_{b} mass DD",400,4100,6100}, 
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
      // {"muminus_TRACK_GhostProb","#mu^{-} track GhostProb",100,0,1},
    };
    cout<<"branches declared"<<endl;
    int nBranches = f[ifile].b.size();
    
    cout<<endl<<"Starting branch loop "<<ifile+1<<"/"<<nFiles<<"..."<<endl;
    for(int ibranch=0; ibranch<nBranches; ibranch++){
      if(f[ifile].t.size()>1){
	cout<<"makeplots3.C currently only supports one tree per file"<<endl;
	exit(EXIT_FAILURE);
      }
      branch * mybranch = &f[ifile].b[ibranch];
      cout<<"On branch "<<ibranch+1<<"/"<<nBranches<<" ("<<mybranch->name<<") for file "<<ifile+1<<"/"<<nFiles<<" ("<<f[ifile].name<<")..."<<endl;
      
      //assign cuts
      TCut cLL,cDD,ctrigger,Bs2JpsiKst;
      makecuts(ifile,cLL,cDD,ctrigger,Bs2JpsiKst);

      // if(ifile==0&&ibranch==0) myfile<<"'cnewest' = "<<(TString)cnewest<<endl;
      // if(ifile==0&&ibranch==0) myfile<<"'c062516' = "<<(TString)c062516<<endl;
      // if(ifile==0&&ibranch==0) myfile<<"'c063016' = "<<(TString)c063016<<endl;
      // mybranch->add_cut(cnewest,"'newest' cuts");
      // mybranch->add_cut(c062516,"cuts finalized 6/25/16");
      // mybranch->add_cut(c063016,"cuts finalized 6/30/16");
      mybranch->add_cut("","no additional cuts");
      for(float i=-1.5; i<0; i+=0.1){
      	TString istring = Form("%.1f",i);
	TString cutstring="";
// 	for(int j=0; j<1; j++){
// 	  TString jstring = Form("%i",j);
// 	  TString jstringplus1 = Form("%i",j+1);
// 	  placeholder="Added_CharmH_VERTEXCHI2_NEW["+jstring+"]>"+istring+"||Added_n_Particles<"+jstringplus1;
// // !(Added_CharmH_VERTEXCHI2_NEW["+jstring+"]>0||Added_CharmH_VERTEXCHI2_NEW["+jstring+"]<=0)";
// 	  if(j==0) cutstring  =   "("+placeholder+")";
// 	  else     cutstring += "&&("+placeholder+")";
// 	}
//the actual cutting is currently done in MyClass.C
	TCut acut = (TCut)cutstring;
	// TString cutname  = "All added pions J/#psi vertex #chi^{2}/DoF >"+istring;
	TString cutname  = "All added pions new J/#psi vertex #chi^{2}/DoF - old #chi^{2}/DoF >"+istring;
	mybranch->add_cut(acut,cutname);
      }
      int nCuts = mybranch->c.size();
      if(nCuts==0){
        //for branches with no cuts assigned, 
        //we must give them an empty cut with an empty name
        //so they can be plotted in the cuts loop
        mybranch->c = {{"",""}};
        nCuts = mybranch->c.size();
      }
      cout<<"cuts declared"<<endl;    
      //create necessary canvasy things
      TString cistring = Form("%d",ci);
      placeholder = "c"+cistring;
      c.push_back( new TCanvas(placeholder,placeholder,1200,800) ); //create the canvases
      c[ci]->cd();
      if(mybranch->name=="B_{s} mass"||mybranch->name=="m(J/#psi K*)") gPad->SetLogy();
      gStyle->SetOptStat("");
      // leg.push_back( new TLegend(0.125, 0.6, 0.45, 0.93) );//create legend
      leg.push_back( new TLegend(0.65, 0.6, 0.95, 0.93) );//create legend
      placeholder = "hs"+cistring;
      hs.push_back( new THStack(placeholder,placeholder) ); //create the stack to hold the histograms
      TString leglabel="";
      TString stacktitle="";
      h.resize(ci+1);
      
      int icolor = 0;//color counter
      
      cout<<endl<<"Starting cut loop "<<ibranch+1<<"/"<<nBranches<<" for file "<<ifile+1<<"/"<<nFiles<<" ("<<f[ifile].name<<")..."<<endl;
      for(int icut =0; icut<nCuts; icut++){
        //adjust LL and DD branches to have LL and DD cuts
        if(mybranch->name.Contains("LL")){
          mybranch->c[icut].self=mybranch->c[icut].self&&cLL;
          mybranch->c[icut].name+=" LL";
        }
        if(mybranch->name.Contains("DD")){
          mybranch->c[icut].self=mybranch->c[icut].self&&cDD;
          mybranch->c[icut].name+=" DD";
        }
        
        cout<<"On cut "<<icut+1<<"/"<<nCuts<<" ("<<mybranch->c[icut].name<<") for branch "<<ibranch+1<<"/"<<nBranches<<"..."<<endl;
        //create convenient strings
        TString icutstring = Form("%d",icut);
        TString hname = "h"+cistring+icutstring;
        TString htitle = mybranch->name;
        // cout<<"strings created"<<endl;
	//create histogram
        int nBins = mybranch->nBins;
        double loBin = mybranch->loBin;
        double hiBin = mybranch->hiBin;
	// cout<<"bins declared"<<endl;
        h[ci].push_back( new TH1F(hname,htitle,nBins,loBin,hiBin) );
	// cout<<"histogram declared"<<endl;
        //draw histogram
        cout<<"drawing histogram "<<ifile*nBranches+ibranch*nCuts+icut+1<<"/"<<nFiles*nBranches*nCuts<<"..."<<endl;
        while(icolor==0||icolor==5||icolor==10||(icolor>=17&&icolor<=19))
          icolor++;//skip bad colors
	h[ci][icut]->SetLineColor(icolor);
	// cout<<"line color set"<<endl;
	placeholder = mybranch->self+">>"+hname;
	TCut * thiscut = &mybranch->c[icut].self;
	cut * mycut = &mybranch->c[icut];
	// cout<<"convenient pointers declared"<<endl;
	if(mycut->name=="no additional cuts")
	  f[ifile].t[0]->Draw(placeholder,*thiscut,drawopt);//there's only one tree per file
	else
	  t.Loop(h[ci][icut],mycut->name);//temporarily using a loop in a class to do this... be very careful
	cout<<"done. "<<endl;
	// //calculate sig, bkg
        // cout<<"calculating sig, bkg "<<icut+1<<"/"<<nCuts<<"...";
	// float sigcutofflo=1112,sigcutoffhi=1120,bkgcutofflo=0,bkgcutoffhi=5100;//initialized to avoid compiler warnings
	// // if(mybranch->name.Contains("LL")){
	// //   sigcutofflo = 5594.773954;
	// //   sigcutoffhi = 5647.485654;
	// // } else if(mybranch->name.Contains("DD")){
	// //   sigcutofflo = 5562.230734;
	// //   sigcutoffhi = 5680.694666;
	// // }
	// // bkgcutoffhi = 6100;
	// // bkgcutofflo = sigcutoffhi;
	// // placeholder="(R_M<"+sigcutofflostring+"&&R_M>"+bkgcutofflostring+")||(R_M>"+sigcutoffhistring+"&&R_M<"+bkgcutoffhistring+")";
	// if(f[ifile].name=="data"){
	//   sigcutofflo=5500;
	//   sigcutoffhi=5700;
	// } else if(f[ifile].name=="#Lambda MC"){
	//   sigcutofflo=4100;
	//   sigcutoffhi=6100;
	//   bkgcutofflo=sigcutofflo;
	//   bkgcutoffhi=sigcutoffhi;
	// } else if(f[ifile].name=="#Sigma^{0} MC"){
	//   sigcutofflo=4100;
	//   sigcutoffhi=6100;
	//   bkgcutofflo=sigcutofflo;
	//   bkgcutoffhi=sigcutoffhi;
	// }
	// TString sigcutofflostring = Form("%.0f",sigcutofflo);
	// TString sigcutoffhistring = Form("%.0f",sigcutoffhi);
	// TString bkgcutofflostring = Form("%.0f",bkgcutofflo);
	// TString bkgcutoffhistring = Form("%.0f",bkgcutoffhi);
	// placeholder="("+massname[ifile]+">"+sigcutofflostring+"&&"+massname[ifile]+"<"+sigcutoffhistring+")";
	// if(f[ifile].name=="#Lambda MC") placeholder+="&&abs(R_MC_MOTHER_ID)==5122&&R_BKGCAT==0";
	// else if(f[ifile].name=="#Sigma^{0} MC") placeholder+="&&abs(R_MC_GD_MOTHER_ID)==5122&&abs(R_MC_MOTHER_ID)==3212&&R_BKGCAT==0";
	// TCut csig = (TCut)placeholder;
	// mycut->csig = csig;
	// int nsig = (int)f[ifile].t[0]->GetEntries(*thiscut&&csig);//number passing csig
        // int nent = (int)f[ifile].t[0]->GetEntries(*thiscut);//total number
	// placeholder="("+massname[ifile]+">"+bkgcutofflostring+"&&"+massname[ifile]+"<"+bkgcutoffhistring+")";
	// if(f[ifile].name=="#Lambda MC") placeholder+="&&(abs(R_MC_MOTHER_ID)!=5122||R_BKGCAT!=0)";
	// else if(f[ifile].name=="#Sigma^{0} MC") placeholder+="&&(abs(R_MC_GD_MOTHER_ID)!=5122||abs(R_MC_MOTHER_ID)!=3212||R_BKGCAT!=0)";
	// TCut cbkg = (TCut)placeholder;
	// mycut->cbkg = cbkg;
	// int nbkg = (int)f[ifile].t[0]->GetEntries(*thiscut&&cbkg);//number passing cbkg
        // // int nsig = nent - nbkg;
        // mycut->nbkg = nbkg;
        // mycut->nsig = nsig;
	// // float nsig2= (float)nsig*(float)nsig;
	// // float ratio = nsig2/(float)nbkg;
        // // mycut->nL = (int)f[ifile].t[0]->GetEntries(*thiscut&&cLreg);//number in /\ region
        // // mycut->nS = (int)f[ifile].t[0]->GetEntries(*thiscut&&cSreg);//number in S region
        // // mycut->nb = (int)f[ifile].t[0]->GetEntries(*thiscut&&cbkgreg);//number in bkg region
        
        // // float ratio = sqrt((float)nsig/(float)nbkg); 
        // cout<<"done. ";
	//stack histogram
        cout<<"stacking histogram "<<ifile*nBranches+ibranch*nCuts+icut+1<<"/"<<nFiles*nBranches*nCuts<<"...";
        leglabel=mybranch->c[icut].name;
        // placeholder2=Form("%.3f",ratio);
        leg[ci]->AddEntry(h[ci][icut],leglabel,"l");//fill legend
        hs[ci]->Add(h[ci][icut]);//stack histogram
	cout<<"done."<<endl;;
        // //store calculations
        // cout<<"storing calculations...";
	// myfile<<","<<mybranch->name<<","				\
	//       <<leglabel<<","						\
        //       <<sigcutofflostring<<","					\
        //       <<sigcutoffhistring<<","					\
        //       <<bkgcutofflostring<<","					\
        //       <<bkgcutoffhistring<<","					\
	//       <<Form("%i",nsig)<<","                                    \
        //       <<Form("%i",nbkg)<<","					\
	//       <<Form("%f",ratio)<<endl;
	// cout<<"done"<<endl;
        //calculate SMC sig/data bkg
        // if(ifile==(nFiles-1)){//ensure everything's been calculated
        //   if(ibranch==0&&icut==0)
        //     trueratiostring +="cuts,,L0 sigcut,L0 bkgcut,S0 sigcut,S0 bkgcut,data sigcut,data bkgcut,L0 sig,L0 bkg,S0 sig,S0 bkg,data sig,data bkg,L/sqrt(L+B) (no MC bkg),S/sqrt(S+B) (no MC bkg),L/sqrt(L+B) (MC bkg+data bkg),S/sqrt(S+B) (MC bkg+data bkg)\n";//,nL,nS,nb
        //   if(f[iSMCfile].b[ibranch].c[icut].name==f[idatafile].b[ibranch].c[icut].name&&f[iSMCfile].b[ibranch].c[icut].name==f[iLMCfile].b[ibranch].c[icut].name){//only for cuts in common; should probably check branches too, but the name varies by file and I don't want to code all that in right now
	//     cout<<"declaring pointers to calculate ratios... ";
	//     //pointers to make refering to these values below easier to read
        //     TCut * csigL = &f[iLMCfile].b[ibranch].c[icut].csig;
        //     TCut * cbkgL = &f[iLMCfile].b[ibranch].c[icut].cbkg;
        //     TCut * csigS = &f[iSMCfile].b[ibranch].c[icut].csig;
        //     TCut * cbkgS = &f[iSMCfile].b[ibranch].c[icut].cbkg;
        //     TCut * csigdata = &f[idatafile].b[ibranch].c[icut].csig;
	//     TCut * cbkgdata = &f[idatafile].b[ibranch].c[icut].cbkg;
	//     int * nLs = &f[iLMCfile].b[ibranch].c[icut].nsig;
        //     int * nLb = &f[iLMCfile].b[ibranch].c[icut].nbkg;
        //     int * nSs = &f[iSMCfile].b[ibranch].c[icut].nsig;
        //     int * nSb = &f[iSMCfile].b[ibranch].c[icut].nbkg;
        //     int * nds = &f[idatafile].b[ibranch].c[icut].nsig;
        //     int * ndb = &f[idatafile].b[ibranch].c[icut].nbkg;
	//     // int * nL = &f[iLMCfile].b[ibranch].c[icut].nL;
        //     // int * nS = &f[iLMCfile].b[ibranch].c[icut].nS;
        //     // int * nb = &f[iLMCfile].b[ibranch].c[icut].nb;
	//     cout<<"done. calculating ratios... ";
        //     // float ratioL = ((float)*nLs+(float)*nLb)/sqrt((float)*nLs+(float)*nLb+(float)*ndb);
        //     // float ratioS = ((float)*nSs+(float)*nSb)/sqrt((float)*nSs+(float)*nSb+(float)*ndb);
        //     float ratioL2 = ((float)*nLs)/sqrt((float)*nLs+(float)*ndb);
        //     float ratioS2 = ((float)*nSs)/sqrt((float)*nSs+(float)*ndb);
	//     float ratioL3 = ((float)*nLs)/sqrt((float)*nLs+(float)*nLb+(float)*ndb);
        //     float ratioS3 = ((float)*nSs)/sqrt((float)*nSs+(float)*nSb+(float)*ndb);
	//     cout<<"done. adding to trueratiostring... ";
        //     trueratiostring+=mybranch->c[icut].name+","+(TString)*csigL+","+(TString)*cbkgL+","+(TString)*csigS+","+(TString)*cbkgS+","+(TString)*csigdata+","+(TString)*cbkgdata+","+Form("%i",*nLs)+","+Form("%i",*nLb)+","+Form("%i",*nSs)+","+Form("%i",*nSb)+","+Form("%i",*nds)+","+Form("%i",*ndb)+","+Form("%.6f",ratioL2)+","+Form("%.6f",ratioS2)+","+Form("%.6f",ratioL3)+","+Form("%.6f",ratioS3)+"\n";//+","+Form("%.6f",ratioL)+","+Form("%.6f",ratioS)+","+Form("%i",nL)+","+Form("%i",*nS)+","+Form("%i",nb)
	//     cout<<"done."<<endl;
	//   }
        // }

        icolor++;
      }
      stacktitle+=f[ifile].name+", "+mybranch->name;
      //draw stacked histograms
      cout<<"drawing stack "<<ci+1<<": "<<stacktitle<<"...";
      hs[ci]->SetTitle(stacktitle);
      hs[ci]->Draw("nostack");
      leg[ci]->Draw();
      cout<<"done"<<endl;
      //save stuff:
      cout<<"saving files for stack "<<ci+1<<"...";
      placeholder = outputlocation+filename+"(";//the closing page is added after the loop
      c[ci]->Print(placeholder);
      if(runmode.Contains("C")){
        placeholder = outputlocation+"c"+cistring+"_"+stacktitle+".C";
        c[ci]->SaveAs(placeholder);
      }
      cout<<"done"<<endl;
      ci++;//iterates every time we finish a branch
    }
  }
  int nCanvases=ci;
  float sqnc = sqrt(nCanvases), sqncu = ceil(sqnc), sqncd = floor(sqnc);
  while(sqncu*sqncd<nCanvases) sqncu++;//makes rows and columns close to square
  cf->Divide(sqncu,sqncd);//canvas divided to be able to hold all other canvases
  for(int i=0;i<nCanvases;i++){//fill cf
    cf->cd(i+1);//because cd() counts from 1
    c[i]->DrawClonePad();
  }
  placeholder = outputlocation+filename+")";
  cf->Print(placeholder);
  // myfile<<trueratiostring;//include at end of CSV file
  // myfile.close();
  gROOT->SetBatch(kFALSE);
  cout<<"done"<<endl;
}
