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
#include "/afs/cern.ch/user/m/mwilkins/algorithms/chain.h"

void makeplots3_chain(TString runmode="d", TString drawopt=""){
  gROOT->SetBatch(kTRUE);
  TString placeholder;//this is to avoid adding strings in functions; assign right before use
  TString placeholder2;
  TString placeholder3;
  TString outputlocation="./";
  TString basename="compcuts";
  TString filename=basename+".pdf";
  // ofstream myfile;
  // TString trueratiostring="";//holds information to be put at end of myfile
  // myfile.open(outputlocation+basename+".csv");
  // // myfile<<"dataset,branch,cuts,siglo,sighi,bkglo,bkghi,number signal,number background,Nsig^2/Nbkg"<<endl;
  // //create necessary counters, canvases, legends, etc.
  cout<<endl;
  vector<TCanvas*> c;//each canvas holds one stack of histograms
  int ci = 0;//how many canvases have been plotted?
  vector<TLegend*> leg;//one legend per canvas
  vector<THStack*> hs;//one stack per canvas
  vector< vector<TH1F*> > h;
  TCanvas *cf = new TCanvas("cf","combined");//canvas to hold everything

  //assign things to actually be plotted
  map<TString,TString> chquality {{"filetype","data"},{"decaymode","B_{s}"}};
  vector<file> f={{"/afs/cern.ch/user/m/mwilkins/EOS/lhcb/user/m/mwilkins/ganga/outputfiles/DVNtuples353_0-230.root"},
		  {"/afs/cern.ch/user/m/mwilkins/EOS/lhcb/user/m/mwilkins/ganga/outputfiles/DVNtuples353_231-507.root"},
		  {"/afs/cern.ch/user/m/mwilkins/EOS/lhcb/user/m/mwilkins/ganga/outputfiles/DVNtuples354.root"},
  };
  chain ch[]={{"Bs2JpsiKpiTree/mytree",f,"data",chquality}};

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

  // int idatafile=0;//to store the index of the data file; initialized to avoid compiler warnings
  // int iLMCfile=0;//to store the index of the L0 file; initialized to avoid compiler warnings
  // int iSMCfile=0;//to store the index of the sig0 file; initialized to avoid compiler warnings
  cout<<"Starting chain loop..."<<endl;
  for(int ichain=0;ichain<nChains;ichain++){
    //store chain indices
    // if(ch[ichain].name=="data") idatafile = ichain;
    // else if(ch[ichain].name=="#Lambda MC") iLMCfile = ichain;
    // else if(ch[ichain].name=="#Sigma^{0} MC") iSMCfile = ichain;
    cout<<"Using "<<ch[ichain].name<<"..."<<endl;
    placeholder3 = Lbname[ichain]+"_PT";
    ch[ichain].b={// {massname[ichain],"#Lambda_{b} mass (PV) LL",400,4100,6100},	
                // {massname[ichain],"#Lambda_{b} mass (endV) LL",400,4100,6100},	
                // {massname[ichain],"#Lambda_{b} mass (PV) DD",400,4100,6100},	
                // {massname[ichain],"#Lambda_{b} mass (endV) DD",400,4100,6100},	
                // {massname[ichain],"#Lambda_{b} mass LL",400,4100,6100}, 
		// {massname[ichain],"#Lambda_{b} mass DD",400,4100,6100}, 
		{massname[ichain],"B_{s} mass"   ,700,3500,7000},
		{massname[ichain],"B_{s} mass LL",700,3500,7000},
		{massname[ichain],"B_{s} mass DD",700,3500,7000},
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
    int nBranches = ch[ichain].b.size();
    
    cout<<endl<<"Starting branch loop "<<ichain+1<<"/"<<nChains<<"..."<<endl;
    for(int ibranch=0; ibranch<nBranches; ibranch++){
      branch * mybranch = &ch[ichain].b[ibranch];
      cout<<"On branch "<<ibranch+1<<"/"<<nBranches<<" ("<<mybranch->name<<") for file "<<ichain+1<<"/"<<nChains<<" ("<<ch[ichain].name<<")..."<<endl;
      
      //assign cuts
      TCut cLL,cDD,ctrigger,Bs2JpsiKst;
      makecuts(ichain,cLL,cDD,ctrigger,Bs2JpsiKst);

      // if(ichain==0&&ibranch==0) myfile<<"'c070116_LL' = "<<(TString)c070116_LL<<endl;
      // if(ichain==0&&ibranch==0) myfile<<"'c070116_DD' = "<<(TString)c070116_DD<<endl;
      mybranch->add_cut(Bs2JpsiKst,"Liming's selection cuts");

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
      gStyle->SetOptStat("");
      leg.push_back( new TLegend(0.125, 0.6, 0.45, 0.93) );//create legend
      placeholder = "hs"+cistring;
      hs.push_back( new THStack(placeholder,placeholder) ); //create the stack to hold the histograms
      TString leglabel="";
      TString stacktitle="";
      h.resize(ci+1);
      
      int icolor = 0;//color counter
      
      cout<<endl<<"Starting cut loop "<<ibranch+1<<"/"<<nBranches<<" for file "<<ichain+1<<"/"<<nChains<<" ("<<ch[ichain].name<<")..."<<endl;
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
        int loBin = mybranch->loBin;
        int hiBin = mybranch->hiBin;
	// cout<<"bins declared"<<endl;
        h[ci].push_back( new TH1F(hname,htitle,nBins,loBin,hiBin) );
	// cout<<"histogram declared"<<endl;
        //draw histogram
        cout<<"drawing histogram "<<icut+1<<"/"<<nCuts<<"..."<<endl;
        while(icolor==0||icolor==5||icolor==10||(icolor>=17&&icolor<=19)) 
          icolor++;//skip bad colors 
	h[ci][icut]->SetLineColor(icolor);
	// cout<<"line color set"<<endl;
	placeholder = mybranch->self+">>"+hname;
	TCut * thiscut = &mybranch->c[icut].self;
	cut * mycut = &mybranch->c[icut];
	// cout<<"convenient pointers declared"<<endl;
	ch[ichain].Draw(placeholder,*thiscut,drawopt);//there's only one tree per file
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
	// if(ch[ichain].name=="data"){
	//   sigcutofflo=5500;
	//   sigcutoffhi=5700;
	// } else if(ch[ichain].name=="#Lambda MC"){
	//   sigcutofflo=4100;
	//   sigcutoffhi=6100;
	//   bkgcutofflo=sigcutofflo;
	//   bkgcutoffhi=sigcutoffhi;
	// } else if(ch[ichain].name=="#Sigma^{0} MC"){
	//   sigcutofflo=4100;
	//   sigcutoffhi=6100;
	//   bkgcutofflo=sigcutofflo;
	//   bkgcutoffhi=sigcutoffhi;
	// }
	// TString sigcutofflostring = Form("%.0f",sigcutofflo);
	// TString sigcutoffhistring = Form("%.0f",sigcutoffhi);
	// TString bkgcutofflostring = Form("%.0f",bkgcutofflo);
	// TString bkgcutoffhistring = Form("%.0f",bkgcutoffhi);
	// placeholder="("+massname[ichain]+">"+sigcutofflostring+"&&"+massname[ichain]+"<"+sigcutoffhistring+")";
	// if(ch[ichain].name=="#Lambda MC") placeholder+="&&abs(R_MC_MOTHER_ID)==5122&&R_BKGCAT==0";
	// else if(ch[ichain].name=="#Sigma^{0} MC") placeholder+="&&abs(R_MC_GD_MOTHER_ID)==5122&&abs(R_MC_MOTHER_ID)==3212&&R_BKGCAT==0";
	// TCut csig = (TCut)placeholder;
	// mycut->csig = csig;
	// int nsig = (int)ch[ichain].t[0]->GetEntries(*thiscut&&csig);//number passing csig
        // int nent = (int)ch[ichain].t[0]->GetEntries(*thiscut);//total number
	// placeholder="("+massname[ichain]+">"+bkgcutofflostring+"&&"+massname[ichain]+"<"+bkgcutoffhistring+")";
	// if(ch[ichain].name=="#Lambda MC") placeholder+="&&(abs(R_MC_MOTHER_ID)!=5122||R_BKGCAT!=0)";
	// else if(ch[ichain].name=="#Sigma^{0} MC") placeholder+="&&(abs(R_MC_GD_MOTHER_ID)!=5122||abs(R_MC_MOTHER_ID)!=3212||R_BKGCAT!=0)";
	// TCut cbkg = (TCut)placeholder;
	// mycut->cbkg = cbkg;
	// int nbkg = (int)ch[ichain].t[0]->GetEntries(*thiscut&&cbkg);//number passing cbkg
        // // int nsig = nent - nbkg;
        // mycut->nbkg = nbkg;
        // mycut->nsig = nsig;
	// // float nsig2= (float)nsig*(float)nsig;
	// // float ratio = nsig2/(float)nbkg;
        // // mycut->nL = (int)ch[ichain].t[0]->GetEntries(*thiscut&&cLreg);//number in /\ region
        // // mycut->nS = (int)ch[ichain].t[0]->GetEntries(*thiscut&&cSreg);//number in S region
        // // mycut->nb = (int)ch[ichain].t[0]->GetEntries(*thiscut&&cbkgreg);//number in bkg region
        
        // // float ratio = sqrt((float)nsig/(float)nbkg); 
        // cout<<"done. ";
	//stack histogram
        cout<<"stacking histogram "<<icut+1<<"/"<<nCuts<<"...";
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
        // if(ichain==(nChains-1)){//ensure everything's been calculated
        //   if(ibranch==0&&icut==0)
        //     trueratiostring +="cuts,,L0 sigcut,L0 bkgcut,S0 sigcut,S0 bkgcut,data sigcut,data bkgcut,L0 sig,L0 bkg,S0 sig,S0 bkg,data sig,data bkg,L/sqrt(L+B) (no MC bkg),S/sqrt(S+B) (no MC bkg),L/sqrt(L+B) (MC bkg+data bkg),S/sqrt(S+B) (MC bkg+data bkg)\n";//,nL,nS,nb
        //   if(ch[iSMCfile].b[ibranch].c[icut].name==ch[idatafile].b[ibranch].c[icut].name&&ch[iSMCfile].b[ibranch].c[icut].name==ch[iLMCfile].b[ibranch].c[icut].name){//only for cuts in common; should probably check branches too, but the name varies by file and I don't want to code all that in right now
	//     cout<<"declaring pointers to calculate ratios... ";
	//     //pointers to make refering to these values below easier to read
        //     TCut * csigL = &ch[iLMCfile].b[ibranch].c[icut].csig;
        //     TCut * cbkgL = &ch[iLMCfile].b[ibranch].c[icut].cbkg;
        //     TCut * csigS = &ch[iSMCfile].b[ibranch].c[icut].csig;
        //     TCut * cbkgS = &ch[iSMCfile].b[ibranch].c[icut].cbkg;
        //     TCut * csigdata = &ch[idatafile].b[ibranch].c[icut].csig;
	//     TCut * cbkgdata = &ch[idatafile].b[ibranch].c[icut].cbkg;
	//     int * nLs = &ch[iLMCfile].b[ibranch].c[icut].nsig;
        //     int * nLb = &ch[iLMCfile].b[ibranch].c[icut].nbkg;
        //     int * nSs = &ch[iSMCfile].b[ibranch].c[icut].nsig;
        //     int * nSb = &ch[iSMCfile].b[ibranch].c[icut].nbkg;
        //     int * nds = &ch[idatafile].b[ibranch].c[icut].nsig;
        //     int * ndb = &ch[idatafile].b[ibranch].c[icut].nbkg;
	//     // int * nL = &ch[iLMCfile].b[ibranch].c[icut].nL;
        //     // int * nS = &ch[iLMCfile].b[ibranch].c[icut].nS;
        //     // int * nb = &ch[iLMCfile].b[ibranch].c[icut].nb;
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
      stacktitle+=ch[ichain].name+", "+mybranch->name;
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
