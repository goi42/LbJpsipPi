#define MySigmaClass_cxx
#include "MySigmaClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "TVector3.h"
#include "inv_mass.C"
#include "TPaveStats.h"

void MySigmaClass::Loop()
{
//   In a ROOT session, you can do:
//      root> .L MySigmaClass.C
//      root> MySigmaClass t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   gROOT->SetBatch();
   int massLbyield =0;
   int cutmassLbyield =0;
   int cutmassLb2yield =0;
   int cutmassLb3yield =0;
   int cutmassLb4yield =0;
   int cutmassLb5yield =0;
   int cutmassLb6yield =0;
   int cutmassLb7yield =0;
   int cutmassLb8yield =0;
   int cutmassLb9yield =0;
   int cutmassLb10yield =0;
   int cutmassLb11yield =0;
   int cutmassLb12yield =0;
   float fLfdtot =0;
   float fLfdLLtot =0;
   float fLfdDDtot =0;

   //create histograms
   TH1F *masspipi = new TH1F("masspipi","m(#pi (p->#pi))",80,300,700);
   TH1F *massJpsi = new TH1F("massJpsi","m(J/#psi)",48,2980,3220);
   TH1F *chi2ndf = new TH1F("chi2ndf","#chi^{2}/NDF(J/#psi)",210,0,21);
   TH1F *ghostPiLL = new TH1F("ghostPiLL","GhostProbLL(#pi)",100,0,1);
   TH1F *ghostpLL = new TH1F("ghostpLL","GhostProbLL(pi)",100,0,1);
   TH1F *ghostmuplLL = new TH1F("ghostmuplLL","GhostProbLL(#mu^{+})",100,0,1);
   TH1F *ghostmumiLL = new TH1F("ghostmumiLL","GhostProbLL(#mu^{-})",100,0,1);
   TH1F *ghostPiDD = new TH1F("ghostPiDD","GhostProbDD(#pi)",100,0,1);
   TH1F *ghostpDD = new TH1F("ghostpDD","GhostProbDD(pi)",100,0,1);
   TH1F *ghostmuplDD = new TH1F("ghostmuplDD","GhostProbDD(#mu^{+})",100,0,1);
   TH1F *ghostmumiDD = new TH1F("ghostmumiDD","GhostProbDD(#mu^{-})",100,0,1);
   TH1F *cutghostPiLL = new TH1F("cutghostPiLL","GhostProbLL(#pi) with all cuts",100,0,1);
   TH1F *cutghostpLL = new TH1F("cutghostpLL","GhostProbLL(pi) with all cuts",100,0,1);
   TH1F *cutghostmuplLL = new TH1F("cutghostmuplLL","GhostProbLL(#mu^{+}) with all cuts",100,0,1);
   TH1F *cutghostmumiLL = new TH1F("cutghostmumiLL","GhostProbLL(#mu^{-}) with all cuts",100,0,1);
   TH1F *cutghostPiDD = new TH1F("cutghostPiDD","GhostProbDD(#pi) with all cuts",100,0,1);
   TH1F *cutghostpDD = new TH1F("cutghostpDD","GhostProbDD(pi) with all cuts",100,0,1);
   TH1F *cutghostmuplDD = new TH1F("cutghostmuplDD","GhostProbDD(#mu^{+}) with all cuts",100,0,1);
   TH1F *cutghostmumiDD = new TH1F("cutghostmumiDD","GhostProbDD(#mu^{-}) with all cuts",100,0,1);
   TH1F *massLb = new TH1F("massLb","Lambda_b0_MM",400,4100,6100);
   TH1F *cutmassLb = new TH1F("cutmassLb","m(#Lambda_{b}^{0}) with Liming's cuts from Aug5" \
                              ,400,4100,6100);
   TH1F *cutmassLb2 = new TH1F("cutmassLb2","m(#Lambda_{b}^{0}) with Liming's cuts LL" \
                               ,400,4100,6100);
   TH1F *cutmassLb3 = new TH1F("cutmassLb3","m(#Lambda_{b}^{0}) with Liming's cuts DD"\
                               ,400,4100,6100);
   TH1F *cutmassLb4 = new TH1F("cutmassLb4","m(#Lambda_{b}^{0}) with Liming's cuts and pID cut"\
                               ,400,4100,6100);
   TH1F *cutmassLb5 = new TH1F("cutmassLb5","m(#Lambda_{b}^{0}) with Liming's cuts and pID cut LL"\
                               ,400,4100,6100);
   TH1F *cutmassLb6 = new TH1F("cutmassLb6","m(#Lambda_{b}^{0}) with Liming's cuts and pID cut DD"\
                               ,400,4100,6100);
   TH1F *cutmassLb7 = new TH1F("cutmassLb7","m(#Lambda_{b}^{0}) with Liming's cuts and KS cut"\
                               ,400,4100,6100);
   TH1F *cutmassLb8 = new TH1F("cutmassLb8","m(#Lambda_{b}^{0}) with Liming's cuts and KS cut LL"\
                               ,400,4100,6100);
   TH1F *cutmassLb9 = new TH1F("cutmassLb9","m(#Lambda_{b}^{0}) with Liming's cuts and KS cut DD"\
                               ,400,4100,6100);
   TH1F *cutmassLb10 = new TH1F("cutmassLb10","m(#Lambda_{b}^{0}) with Liming's cuts, pID cut, and KS cut"\
                                ,400,4100,6100);
   TH1F *cutmassLb11 = new TH1F("cutmassLb11","m(#Lambda_{b}^{0}) with Liming's cuts, pID cut, and KS cut LL"\
                                ,400,4100,6100);
   TH1F *cutmassLb12 = new TH1F("cutmassLb12","m(#Lambda_{b}^{0}) with Liming's cuts, pID cut, and KS cut DD"\
                                ,400,4100,6100);
   TH1F *cutmassLb13 = new TH1F("cutmassLb13","m(#Lambda_{b}^{0}) with Liming's cuts and KS cut and trigger cut"\
                                ,400,4100,6100);
   TH1F *cutmassLb14 = new TH1F("cutmassLb14","m(#Lambda_{b}^{0}) with Liming's cuts and KS cut and trigger cut LL"\
                                ,400,4100,6100);
   TH1F *cutmassLb15 = new TH1F("cutmassLb15","m(#Lambda_{b}^{0}) with Liming's cuts and KS cut and trigger cut DD"\
                                ,400,4100,6100);
   TH1F *cutmassLb16 = new TH1F("cutmassLb16","m(#Lambda_{b}^{0}) with Liming's cuts, KS cut, trigger cut and Lb_BKGCAT cut"\
                                ,400,4100,6100);
   TH1F *cutmassLb17 = new TH1F("cutmassLb17","m(#Lambda_{b}^{0}) with Liming's cuts, KS cut, trigger cut and Lb_BKGCAT cut LL"\
                                ,400,4100,6100);
   TH1F *cutmassLb18 = new TH1F("cutmassLb18","m(#Lambda_{b}^{0}) with Liming's cuts, KS cut, trigger cut and Lb_BKGCAT cut DD"\
                                ,400,4100,6100);
   TH1F *cutmassLb19 = new TH1F("cutmassLb19","m(#Lambda_{b}^{0}) with Liming's, KS, trigger and Lambda0,J/psi_BKGCAT cut"\
                                ,400,4100,6100);
   TH1F *cutmassLb20 = new TH1F("cutmassLb20","m(#Lambda_{b}^{0}) with Liming's, KS, trigger and Lambda0,J/psi_BKGCAT cut LL"\
                                ,400,4100,6100);
   TH1F *cutmassLb21 = new TH1F("cutmassLb21","m(#Lambda_{b}^{0}) with Liming's, KS, trigger and Lambda0,J/psi_BKGCAT cut DD"\
                                ,400,4100,6100);
   TH1F *LbBKGCAT = new TH1F("LbBKGCAT","Lambda_b0_BKGCAT with Liming's cuts, KS cut and trigger cut"\
                                ,132,0,132);
   TH1F *LbBKGCATLL = new TH1F("LbBKGCATLL","Lambda_b0_BKGCAT with Liming's cuts, KS cut and trigger cut LL"\
                                ,132,0,132);
   TH1F *LbBKGCATDD = new TH1F("LbBKGCATDD","Lambda_b0_BKGCAT with Liming's cuts, KS cut and trigger cut DD"\
                                ,132,0,132);
   TH1F *pTLb = new TH1F("pTLb","p_{T}(#Lambda_{b}^{0}) with Liming's cuts and KS cut with a mass falling in the yield" \
                         ,4000,0,20000);
   TH1F *pTLbLL = new TH1F("pTLbLL","p_{T}(#Lambda_{b}^{0}) with Liming's cuts and KS cut with a mass falling in the yield LL"\
                         ,4000,0,20000);
   TH1F *pTLbDD = new TH1F("pTLbDD","p_{T}(#Lambda_{b}^{0}) with Liming's cuts and KS cut with a mass falling in the yield DD"\
                         ,4000,0,20000);
   TH1F *fLfd = new TH1F("fLfd","f_{#Lambda_{b}^{0}}/f_{d}(p_{T})=0.151+exp(-0.573-0.095#times p_{T}/1000); p_{T}=pTLb"\
                         ,100,0,1);
   TH1F *fLfdLL = new TH1F("fLfdLL","f_{#Lambda_{b}^{0}}/f_{d}(p_{T})=0.151+exp(-0.573-0.095#times p_{T}/1000); p_{T}=pTLbLL"\
                         ,100,0,1);
   TH1F *fLfdDD = new TH1F("fLfdDD","f_{#Lambda_{b}^{0}}/f_{d}(p_{T})=0.151+exp(-0.573-0.095#times p_{T}/1000); p_{T}=pTLbDD"\
                         ,100,0,1);

   cout<<"histograms created"<<endl;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      double chi2ndfv = J_psi_1S_ENDVERTEX_CHI2 / J_psi_1S_ENDVERTEX_NDOF;

      float dmassJpsi = J_psi_1S_MM-3096.92;
      float dwmassR = R_WM-497.614;

      massJpsi->Fill(J_psi_1S_MM);
      chi2ndf->Fill(chi2ndfv);
      masspipi->Fill(R_WM);
      if(H2_TRACK_Type==3) ghostPiLL->Fill(H2_TRACK_GhostProb);
      if(H1_TRACK_Type==3) ghostpLL->Fill(H1_TRACK_GhostProb);
      if(muplus_TRACK_Type==3) ghostmuplLL->Fill(muplus_TRACK_GhostProb);
      if(muminus_TRACK_Type==3) ghostmumiLL->Fill(muminus_TRACK_GhostProb);
      if(H2_TRACK_Type==5) ghostPiDD->Fill(H2_TRACK_GhostProb);
      if(H1_TRACK_Type==5) ghostpDD->Fill(H1_TRACK_GhostProb);
      if(muplus_TRACK_Type==5) ghostmuplDD->Fill(muplus_TRACK_GhostProb);
      if(muminus_TRACK_Type==5) ghostmumiDD->Fill(muminus_TRACK_GhostProb);
      //Liming's cuts:
      if(((H1_TRACK_Type==3)&&(H2_TRACK_Type==3)&&(H1_TRACK_GhostProb<0.2)&&(H2_TRACK_GhostProb<0.2)\
          &&(Lambda_b0_DIRA_OWNPV>0.9999)                               \
          &&(R_FDCHI2_ORIVX>50)&&(R_MM>1112)&&(R_MM<1120)&&(R_PT>1000)) \
         ||((R_PT>1000)&&(R_ENDVERTEX_Z>500)&&(H1_TRACK_Type==5)&&(H2_TRACK_Type==5) \
            &&(Lambda_b0_DIRA_OWNPV>0.9999)&&(R_FDCHI2_ORIVX>50)&&(R_MM>1110)&&(R_MM<1122)\
            &&(Lambda_b0_ENDVERTEX_CHI2/Lambda_b0_ENDVERTEX_NDOF<10)    \
            &&(dmassJpsi>-48)&&(dmassJpsi<43))){
        cutmassLb->Fill(Lambda_b0_MM);
        if((Lambda_b0_MM>=5470)&&(Lambda_b0_MM<=5770))cutmassLbyield++;
        if((H1_TRACK_Type==3)&&(H2_TRACK_Type==3)){
          cutmassLb2->Fill(Lambda_b0_MM);
          if((Lambda_b0_MM>=5470)&&(Lambda_b0_MM<=5770))cutmassLb2yield++;
        }
        if((H1_TRACK_Type==5)&&(H2_TRACK_Type==5)){
          cutmassLb3->Fill(Lambda_b0_MM);
          if((Lambda_b0_MM>=5470)&&(Lambda_b0_MM<=5770))cutmassLb3yield++;
        }
        //WM cut:
        if((dwmassR<-40)||(dwmassR>40)){
          cutmassLb7->Fill(Lambda_b0_MM);
          //trigger cut
          if(((J_psi_1S_Hlt1DiMuonHighMassDecision_TOS==1)||(J_psi_1S_Hlt1TrackMuonDecision_TOS==1)|| \
              (J_psi_1S_Hlt1TrackAllL0Decision_TOS==1))&&(J_psi_1S_Hlt2DiMuonDetachedJPsiDecision_TOS==1)){
            cutmassLb13->Fill(Lambda_b0_MM);
            LbBKGCAT->Fill(Lambda_b0_BKGCAT);
            if(Lambda_b0_BKGCAT<20) cutmassLb16->Fill(Lambda_b0_MM);
            if(R_BKGCAT==0&&J_psi_1S_BKGCAT==0) cutmassLb19->Fill(Lambda_b0_MM);
          }
          if((Lambda_b0_MM>=5470)&&(Lambda_b0_MM<=5770)){
            cutmassLb7yield++;
            pTLb->Fill(Lambda_b0_PT);
            float fLfd_ = 0.151+exp(-0.573-0.095 * Lambda_b0_PT/1000);
            fLfd->Fill(fLfd_);
            fLfdtot+=fLfd_;
          }
          if((H1_TRACK_Type==3)&&(H2_TRACK_Type==3)){
            cutmassLb8->Fill(Lambda_b0_MM);
            //trigger cut
            if(((J_psi_1S_Hlt1DiMuonHighMassDecision_TOS==1)||(J_psi_1S_Hlt1TrackMuonDecision_TOS==1)|| \
                (J_psi_1S_Hlt1TrackAllL0Decision_TOS==1))&&(J_psi_1S_Hlt2DiMuonDetachedJPsiDecision_TOS==1)){
              cutmassLb14->Fill(Lambda_b0_MM);
              LbBKGCATLL->Fill(Lambda_b0_BKGCAT);
              if(Lambda_b0_BKGCAT<20) cutmassLb17->Fill(Lambda_b0_MM);
              if(R_BKGCAT==0&&J_psi_1S_BKGCAT==0) cutmassLb20->Fill(Lambda_b0_MM);
            }
            if((Lambda_b0_MM>=5470)&&(Lambda_b0_MM<=5770)){
              cutmassLb8yield++;
              pTLbLL->Fill(Lambda_b0_PT);
              float fLfdLL_ = 0.151+exp(-0.573-0.095 * Lambda_b0_PT/1000);
              fLfdLL->Fill(fLfdLL_);
              fLfdLLtot+=fLfdLL_;
            }
          }
          if((H1_TRACK_Type==5)&&(H2_TRACK_Type==5)){
            cutmassLb9->Fill(Lambda_b0_MM);
            //trigger cut
            if(((J_psi_1S_Hlt1DiMuonHighMassDecision_TOS==1)||(J_psi_1S_Hlt1TrackMuonDecision_TOS==1)|| \
                (J_psi_1S_Hlt1TrackAllL0Decision_TOS==1))&&(J_psi_1S_Hlt2DiMuonDetachedJPsiDecision_TOS==1)){
              cutmassLb15->Fill(Lambda_b0_MM);
              LbBKGCATDD->Fill(Lambda_b0_BKGCAT);
              if(Lambda_b0_BKGCAT<20) cutmassLb18->Fill(Lambda_b0_MM);
              if(R_BKGCAT==0&&J_psi_1S_BKGCAT==0) cutmassLb21->Fill(Lambda_b0_MM);
            }
            if((Lambda_b0_MM>=5470)&&(Lambda_b0_MM<=5770)){
               cutmassLb9yield++;
              pTLbDD->Fill(Lambda_b0_PT);
              float fLfdDD_ = 0.151+exp(-0.573-0.095 * Lambda_b0_PT/1000);
              fLfdDD->Fill(fLfdDD_);
              fLfdDDtot+=fLfdDD_;
            }
          }
        }
        //pID cut:
        if((H1_PIDp>10)&&((H1_PIDp-H1_PIDK)>3)){
          cutmassLb4->Fill(Lambda_b0_MM);
          if((Lambda_b0_MM>=5470)&&(Lambda_b0_MM<=5770))cutmassLb4yield++;
          if((H1_TRACK_Type==3)&&(H2_TRACK_Type==3)){
            cutmassLb5->Fill(Lambda_b0_MM);
            if((Lambda_b0_MM>=5470)&&(Lambda_b0_MM<=5770))cutmassLb5yield++;
          }
          if((H1_TRACK_Type==5)&&(H2_TRACK_Type==5)){
            cutmassLb6->Fill(Lambda_b0_MM);
            if((Lambda_b0_MM>=5470)&&(Lambda_b0_MM<=5770))cutmassLb6yield++;
          }
          //WM cut:
          if((dwmassR<-40)||(dwmassR>40)){
            cutmassLb10->Fill(Lambda_b0_MM);
            if((Lambda_b0_MM>=5470)&&(Lambda_b0_MM<=5770))cutmassLb10yield++;
            if((H1_TRACK_Type==3)&&(H2_TRACK_Type==3)){
              cutmassLb11->Fill(Lambda_b0_MM);
              if((Lambda_b0_MM>=5470)&&(Lambda_b0_MM<=5770))cutmassLb11yield++;
            }
            if((H1_TRACK_Type==5)&&(H2_TRACK_Type==5)){
              cutmassLb12->Fill(Lambda_b0_MM);
              if((Lambda_b0_MM>=5470)&&(Lambda_b0_MM<=5770))cutmassLb12yield++;
            }
            //cutghost histogram:
            if(H2_TRACK_Type==3) cutghostPiLL->Fill(H2_TRACK_GhostProb);
            if(H1_TRACK_Type==3) cutghostpLL->Fill(H1_TRACK_GhostProb);
            if(muplus_TRACK_Type==3) cutghostmuplLL->Fill(muplus_TRACK_GhostProb);
            if(muminus_TRACK_Type==3) cutghostmumiLL->Fill(muminus_TRACK_GhostProb);
            if(H2_TRACK_Type==5) cutghostPiDD->Fill(H2_TRACK_GhostProb);
            if(H1_TRACK_Type==5) cutghostpDD->Fill(H1_TRACK_GhostProb);
            if(muplus_TRACK_Type==5) cutghostmuplDD->Fill(muplus_TRACK_GhostProb);
            if(muminus_TRACK_Type==5) cutghostmumiDD->Fill(muminus_TRACK_GhostProb);
          }
        }
      }
      massLb->Fill(Lambda_b0_MM);
      if((Lambda_b0_MM>=5470)&&(Lambda_b0_MM<=5770))massLbyield++;
   }
   cout<<endl;

   TFile file("output/histos.root","RECREATE");
   TCanvas *canvas1 = new TCanvas("canvas1","J/psi",1200,800);
   canvas1->Divide(2,1);
   cout<<"canvas 1/35 made"<<endl;
   canvas1->cd(1);
   gStyle->SetOptStat(kFALSE);
   massJpsi->GetXaxis()->SetTitle("m(J/#psi) (MeV)");
   massJpsi->GetYaxis()->SetTitle("Events / 5MeV");
   massJpsi->Draw();
   canvas1->cd(2);
   gStyle->SetOptStat(kFALSE);
   gPad->SetLogy();
   chi2ndf->GetXaxis()->SetTitle("#chi^{2}/NDF(J/#psi)");
   chi2ndf->GetYaxis()->SetTitle("Events / 0.1");
   chi2ndf->Draw();
   canvas1->Print("output/plots.pdf(");
   TCanvas *canvas2 = new TCanvas("canvas2","GhostProb",1200,800);
   canvas2->Divide(2,2);
   cout<<"canvas 2/35 made"<<endl;
   canvas2->cd(1);
   gStyle->SetOptStat(kFALSE);
   ghostPiLL->GetXaxis()->SetTitle("GhostProb(#pi)");
   ghostPiLL->GetYaxis()->SetTitle("Events / 0.01");
   ghostPiLL->Draw();
   canvas2->Update();
   ghostPiDD->SetLineColor(kRed);
   ghostPiDD->Draw("same");
   canvas2->cd(2);
   gStyle->SetOptStat(kFALSE);
   ghostpLL->GetXaxis()->SetTitle("GhostProb(p)");
   ghostpLL->GetYaxis()->SetTitle("Events / 0.01");
   ghostpLL->Draw();
   canvas2->Update();
   ghostpDD->SetLineColor(kRed);
   ghostpDD->Draw("same");
   canvas2->cd(3);
   gStyle->SetOptStat(kFALSE);
   ghostmuplLL->GetXaxis()->SetTitle("GhostProb(#mu^{+})");
   ghostmuplLL->GetYaxis()->SetTitle("Events / 0.01");
   ghostmuplLL->Draw();
   canvas2->Update();
   ghostmuplDD->SetLineColor(kRed);
   ghostmuplDD->Draw("same");
   canvas2->cd(4);
   gStyle->SetOptStat(kFALSE);
   ghostmumiLL->GetXaxis()->SetTitle("GhostProb(#mu^{-})");
   ghostmumiLL->GetYaxis()->SetTitle("Events / 0.01");
   ghostmumiLL->Draw();
   canvas2->Update();
   ghostmumiDD->SetLineColor(kRed);
   ghostmumiDD->Draw("same");
   canvas2->Print("output/plots.pdf(");
   TCanvas *canvas3 = new TCanvas("canvas3","cutGhostProb",1200,800);
   canvas3->Divide(2,2);
   cout<<"canvas 3/35 made"<<endl;
   canvas3->cd(1);
   gStyle->SetOptStat(kFALSE);
   cutghostPiLL->GetXaxis()->SetTitle("GhostProb(#pi) with all cuts");
   cutghostPiLL->GetYaxis()->SetTitle("Events / 0.01");
   cutghostPiLL->Draw();
   canvas3->Update();
   cutghostPiDD->SetLineColor(kRed);
   cutghostPiDD->Draw("same");
   canvas3->cd(2);
   gStyle->SetOptStat(kFALSE);
   cutghostpLL->GetXaxis()->SetTitle("GhostProb(p) with all cuts");
   cutghostpLL->GetYaxis()->SetTitle("Events / 0.01");
   cutghostpLL->Draw();
   canvas3->Update();
   cutghostpDD->SetLineColor(kRed);
   cutghostpDD->Draw("same");
   canvas3->cd(3);
   gStyle->SetOptStat(kFALSE);
   cutghostmuplLL->GetXaxis()->SetTitle("GhostProb(#mu^{+}) with all cuts");
   cutghostmuplLL->GetYaxis()->SetTitle("Events / 0.01");
   cutghostmuplLL->Draw();
   canvas3->Update();
   cutghostmuplDD->SetLineColor(kRed);
   cutghostmuplDD->Draw("same");
   canvas3->cd(4);
   gStyle->SetOptStat(kFALSE);
   cutghostmumiLL->GetXaxis()->SetTitle("GhostProb(#mu^{-}) with all cuts");
   cutghostmumiLL->GetYaxis()->SetTitle("Events / 0.01");
   cutghostmumiLL->Draw();
   canvas3->Update();
   cutghostmumiDD->SetLineColor(kRed);
   cutghostmumiDD->Draw("same");
   canvas3->Print("output/plots.pdf(");
   TCanvas *canvas4 = new TCanvas("canvas4","cutmassLb2",1200,800);
   cout<<"canvas 4/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb2->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts LL (MeV)");
   cutmassLb2->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb2->Draw();
   canvas4->Print("output/plots.pdf(");
   TCanvas *canvas5 = new TCanvas("canvas5","massLb",1200,800);
   cout<<"canvas 5/35 made"<<endl;
   gStyle->SetOptStat("e");
   massLb->GetXaxis()->SetTitle("Lambda_b0_MM (MeV)");
   massLb->GetYaxis()->SetTitle("Events / 5MeV");
   massLb->Draw();
   canvas5->Print("output/plots.pdf(");
   TCanvas *canvas6 = new TCanvas("canvas6","cutmassLb3",1200,800);
   cout<<"canvas 6/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb3->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts DD (MeV)");
   cutmassLb3->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb3->Draw();
   canvas6->Print("output/plots.pdf(");
   TCanvas *canvas7 = new TCanvas("canvas7","cutmassLb",1200,800);
   cout<<"canvas 7/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts (MeV)");
   cutmassLb->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb->Draw();
   canvas7->Print("output/plots.pdf(");
   TCanvas *canvas8 = new TCanvas("canvas8","cutmassLb4",1200,800);
   cout<<"canvas 8/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb4->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts and pID cut (MeV)");
   cutmassLb4->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb4->Draw();
   canvas8->Print("output/plots.pdf(");
   TCanvas *canvas9 = new TCanvas("canvas9","cutmassLb5",1200,800);
   cout<<"canvas 9/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb5->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts and pID cut LL (MeV)");
   cutmassLb5->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb5->Draw();
   canvas9->Print("output/plots.pdf(");
   TCanvas *canvas10 = new TCanvas("canvas10","cutmassLb6",1200,800);
   cout<<"canvas 10/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb6->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts and pID cut DD (MeV)");
   cutmassLb6->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb6->Draw();
   canvas10->Print("output/plots.pdf(");
   TCanvas *canvas11 = new TCanvas("canvas11","cutmassLb7",1200,800);
   cout<<"canvas 11/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb7->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts and KS cut (MeV)");
   cutmassLb7->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb7->Draw();
   cutmassLb7->Write();
   canvas11->Print("output/plots.pdf(");
   TCanvas *canvas12 = new TCanvas("canvas12","cutmassLb8",1200,800);
   cout<<"canvas 12/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb8->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts and KS cut LL (MeV)");
   cutmassLb8->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb8->Draw();
   cutmassLb8->Write();
   canvas12->Print("output/plots.pdf(");
   TCanvas *canvas13 = new TCanvas("canvas13","cutmassLb9",1200,800);
   cout<<"canvas 13/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb9->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts and KS cut DD (MeV)");
   cutmassLb9->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb9->Draw();
   cutmassLb9->Write();
   canvas13->Print("output/plots.pdf(");
   TCanvas *canvas14 = new TCanvas("canvas14","cutmassLb10",1200,800);
   cout<<"canvas 14/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb10->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts, pID cut, and KS cut (MeV)");
   cutmassLb10->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb10->Draw();
   canvas14->Print("output/plots.pdf(");
   TCanvas *canvas15 = new TCanvas("canvas15","cutmassLb11",1200,800);
   cout<<"canvas 15/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb11->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts, pID cut, and KS cut LL (MeV)");
   cutmassLb11->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb11->Draw();
   canvas15->Print("output/plots.pdf(");
   TCanvas *canvas16 = new TCanvas("canvas16","cutmassLb12",1200,800);
   cout<<"canvas 16/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb12->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts, pID cut, and KS cut DD (MeV)");
   cutmassLb12->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb12->Draw();
   canvas16->Print("output/plots.pdf(");
   TCanvas *canvas17 = new TCanvas("canvas17","masspipi",1200,800);
   cout<<"canvas 17/35 made"<<endl;
   gStyle->SetOptStat("e");
   masspipi->GetXaxis()->SetTitle("R_WM (MeV)");
   masspipi->GetYaxis()->SetTitle("Events / 5MeV");
   masspipi->Draw();
   canvas17->Print("output/plots.pdf(");
   TCanvas *canvas18 = new TCanvas("canvas18","pTLb",1200,800);
   cout<<"canvas 18/35 made"<<endl;
   gStyle->SetOptStat("e");
   pTLb->GetXaxis()->SetTitle("Lambda_b0_PT (MeV)");
   pTLb->GetYaxis()->SetTitle("Events / 5MeV");
   pTLb->Draw();
   canvas18->Print("output/plots.pdf(");
   TCanvas *canvas19 = new TCanvas("canvas19","pTLbLL",1200,800);
   cout<<"canvas 19/35 made"<<endl;
   gStyle->SetOptStat("e");
   pTLbLL->GetXaxis()->SetTitle("Lambda_b0_PT LL (MeV)");
   pTLbLL->GetYaxis()->SetTitle("Events / 5MeV");
   pTLbLL->Draw();
   canvas19->Print("output/plots.pdf(");
   TCanvas *canvas20 = new TCanvas("canvas20","pTLbDD",1200,800);
   cout<<"canvas 20/35 made"<<endl;
   gStyle->SetOptStat("e");
   pTLbDD->GetXaxis()->SetTitle("Lambda_b0_PT DD (MeV)");
   pTLbDD->GetYaxis()->SetTitle("Events / 5MeV");
   pTLbDD->Draw();
   canvas20->Print("output/plots.pdf(");
   TCanvas *canvas21 = new TCanvas("canvas21","fLfd",1200,800);
   cout<<"canvas 21/35 made"<<endl;
   gStyle->SetOptStat("e");
   fLfd->GetXaxis()->SetTitle("f_{#Lambda_{b}^{0}}/f_{d}(p_{T}) = 0.151+exp(-0.573-0.095 #times Lambda_b0_PT/1000)");
   fLfd->GetYaxis()->SetTitle("Events / 0.01");
   fLfd->Draw();
   canvas21->Print("output/plots.pdf(");
   TCanvas *canvas22 = new TCanvas("canvas22","fLfdLL",1200,800);
   cout<<"canvas 22/35 made"<<endl;
   gStyle->SetOptStat("e");
   fLfdLL->GetXaxis()->SetTitle("f_{#Lambda_{b}^{0}}/f_{d}(p_{T}) = 0.151+exp(-0.573-0.095 #times Lambda_b0_PT/1000)  LL");
   fLfdLL->GetYaxis()->SetTitle("Events / 0.01");
   fLfdLL->Draw();
   canvas22->Print("output/plots.pdf(");
   TCanvas *canvas23 = new TCanvas("canvas23","fLfdDD",1200,800);
   cout<<"canvas 23/35 made"<<endl;
   gStyle->SetOptStat("e");
   fLfdDD->GetXaxis()->SetTitle("f_{#Lambda_{b}^{0}}/f_{d}(p_{T}) = 0.151+exp(-0.573-0.095 #times Lambda_b0_PT/1000)  DD");
   fLfdDD->GetYaxis()->SetTitle("Events / 0.01");
   fLfdDD->Draw();
   canvas23->Print("output/plots.pdf)");
   TCanvas *canvas24 = new TCanvas("canvas24","cutmassLb13",1200,800);
   cout<<"canvas 24/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb13->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts and KS cut and trigger cut (MeV)");
   cutmassLb13->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb13->Draw();
   cutmassLb13->Write();
   canvas24->Print("output/yesplots.eps(");
   TCanvas *canvas25 = new TCanvas("canvas25","cutmassLb14",1200,800);
   cout<<"canvas 25/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb14->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts and KS cut and trigger cut LL (MeV)");
   cutmassLb14->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb14->Draw();
   cutmassLb14->Write();
   canvas25->Print("output/yesplots.eps(");
   TCanvas *canvas26 = new TCanvas("canvas26","cutmassLb15",1200,800);
   cout<<"canvas 26/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb15->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts and KS cut and trigger cut DD (MeV)");
   cutmassLb15->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb15->Draw();
   cutmassLb15->Write();
   canvas26->Print("output/yesplots.eps(");
   TCanvas *canvas27 = new TCanvas("canvas27","cutmassLb16",1200,800);
   cout<<"canvas 27/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb16->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts, KS cut, trigger cut, and Lb_BKGCAT cut (MeV)");
   cutmassLb16->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb16->Draw();
   cutmassLb16->Write();
   canvas27->Print("output/yesplots.eps(");
   TCanvas *canvas28 = new TCanvas("canvas28","cutmassLb17",1200,800);
   cout<<"canvas 28/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb17->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts, KS cut, trigger cut, and Lb_BKGCAT cut LL (MeV)");
   cutmassLb17->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb17->Draw();
   cutmassLb17->Write();
   canvas28->Print("output/yesplots.eps(");
   TCanvas *canvas29 = new TCanvas("canvas29","cutmassLb18",1200,800);
   cout<<"canvas 29/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb18->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's cuts, KS cut, trigger cut, and Lb_BKGCAT cut DD (MeV)");
   cutmassLb18->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb18->Draw();
   cutmassLb18->Write();
   canvas29->Print("output/yesplots.eps(");
   TCanvas *canvas30 = new TCanvas("canvas30","LbBKGCAT",1200,800);
   cout<<"canvas 30/35 made"<<endl;
   gStyle->SetOptStat("e");
   LbBKGCAT->GetXaxis()->SetTitle("Lambda_b0_BKGCAT with Liming's cuts, KS cut and trigger cut (MeV)");
   LbBKGCAT->Draw();
   LbBKGCAT->Write();
   canvas30->Print("output/yesplots.eps(");
   TCanvas *canvas31 = new TCanvas("canvas31","LbBKGCATLL",1200,800);
   cout<<"canvas 31/35 made"<<endl;
   gStyle->SetOptStat("e");
   LbBKGCATLL->GetXaxis()->SetTitle("Lambda_b0_BKGCAT with Liming's cuts, KS cut and trigger cut LL (MeV)");
   LbBKGCATLL->Draw();
   LbBKGCATLL->Write();
   canvas31->Print("output/yesplots.eps(");
   TCanvas *canvas32 = new TCanvas("canvas32","LbBKGCATDD",1200,800);
   cout<<"canvas 32/35 made"<<endl;
   gStyle->SetOptStat("e");
   LbBKGCATDD->GetXaxis()->SetTitle("Lambda_b0_BKGCAT with Liming's cuts, KS cut and trigger cut DD (MeV)");
   LbBKGCATDD->Draw();
   LbBKGCATDD->Write();
   canvas32->Print("output/yesplots.eps(");
   TCanvas *canvas33 = new TCanvas("canvas33","cutmassLb19",1200,800);
   cout<<"canvas 33/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb19->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's, KS, trigger, and Lambda0,J/psi_BKGCAT cut (MeV)");
   cutmassLb19->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb19->Draw();
   cutmassLb19->Write();
   canvas33->Print("output/yesplots.eps(");
   TCanvas *canvas34 = new TCanvas("canvas34","cutmassLb20",1200,800);
   cout<<"canvas 34/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb20->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's, KS, trigger, and Lambda0,J/psi_BKGCAT cut LL (MeV)");
   cutmassLb20->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb20->Draw();
   cutmassLb20->Write();
   canvas34->Print("output/yesplots.eps(");
   TCanvas *canvas35 = new TCanvas("canvas35","cutmassLb21",1200,800);
   cout<<"canvas 35/35 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb21->GetXaxis()->SetTitle("Lambda_b0_MM with Liming's, KS, trigger, and Lambda0,J/psi_BKGCAT cut DD (MeV)");
   cutmassLb21->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb21->Draw();
   cutmassLb21->Write();
   canvas35->Print("output/yesplots.eps)");

   gROOT->SetBatch(kFALSE);

   cout<<"creating yields.txt"<<endl;
   ofstream myfile;
   myfile.open("output/yields.txt");
   cout<<"yields.txt created"<<endl;
   myfile<<"yields of 5470<=Lambda_b0_MM<=5770 with various cuts:"<<endl<<"no cuts: "<<massLbyield<<endl;
   myfile<<"with Liming's Aug5 cuts: "<<cutmassLbyield<<endl<<"ditto LL: "<<cutmassLb2yield<<endl;
   myfile<<"ditto DD: "<<cutmassLb3yield<<endl<<"with pID cut: "<<cutmassLb4yield<<endl;
   myfile<<"ditto LL: "<<cutmassLb5yield<<endl<<"ditto DD: "<<cutmassLb6yield<<endl;
   myfile<<"Liming's and KS: "<<cutmassLb7yield<<endl;
   myfile<<"ditto LL: "<<cutmassLb8yield<<endl<<"ditto DD: "<<cutmassLb9yield<<endl;
   myfile<<"Liming's, KS, and pID: "<<cutmassLb10yield<<endl;
   myfile<<"ditto LL: "<<cutmassLb11yield<<endl<<"ditto DD: "<<cutmassLb12yield<<endl<<endl;
   myfile<<"fLfdtot/cutmassLb7yield= "<<fLfdtot/cutmassLb7yield<<endl;
   myfile<<"fLfdLLtot/cutmassLb8yield= "<<fLfdLLtot/cutmassLb8yield<<endl;
   myfile<<"fLfdDDtot/cutmassLb9yield= "<<fLfdDDtot/cutmassLb9yield<<endl;
   myfile<<"currently not counting yields from trigger cut"<<endl;
   myfile.close();
   cout<<"yields stored"<<endl;

   cout<<"done"<<endl;
}
