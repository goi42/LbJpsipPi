#define Lb2JpsiL_cxx
#include "Lb2JpsiL.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <iomanip>
#include "TVector3.h"
#include "inv_mass.C"
#include "TPaveStats.h"

void Lb2JpsiL::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L Lb2JpsiL.C
//      Root > Lb2JpsiL t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
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

   Long64_t nentries = fChain->GetEntries();

   //create histograms
   TH1F *massJpsipPi = new TH1F("massJpsipPi","invariant mass of J/#psi, p, and #pi",160,5000,5800);
   //   TH1F *massJpsiL = new TH1F("massJpsiL","invariant mass of J/#psi and #Lambda",160,5000,5800);
   //   TH1F *massdiff = new TH1F("massdiff","invariant mass of J/#psi,\
   // p, and #pi minus invariant mass of J/#psi and #Lambda",40,-100,100);
   TH1F *massJpsi = new TH1F("massJpsi","J/#psi_MM",48,2980,3220);
   TH1F *chi2ndf = new TH1F("chi2ndf","#chi^{2}/NDF(J/#psi)",210,0,21);
   TH1F *ghostPiLL = new TH1F("ghostPiLL","GhostProbLL(#pi)",100,0,1);
   TH1F *ghostpLL = new TH1F("ghostpLL","GhostProbLL(pi)",100,0,1);
   TH1F *ghostmuplLL = new TH1F("ghostmuplLL","GhostProbLL(#mu^{+})",100,0,1);
   TH1F *ghostmumiLL = new TH1F("ghostmumiLL","GhostProbLL(#mu^{-})",100,0,1);
   TH1F *ghostPiDD = new TH1F("ghostPiDD","GhostProbDD(#pi)",100,0,1);
   TH1F *ghostpDD = new TH1F("ghostpDD","GhostProbDD(pi)",100,0,1);
   TH1F *ghostmuplDD = new TH1F("ghostmuplDD","GhostProbDD(#mu^{+})",100,0,1);
   TH1F *ghostmumiDD = new TH1F("ghostmumiDD","GhostProbDD(#mu^{-})",100,0,1);
   TH1F *cutmassJpsipPi = new TH1F("cutmassJpsipPi","invariant mass of J/#psi, p, and #pi with cuts",160,5000,5800);
   cout<<"histograms created"<<endl;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      double zero = 0;
      double mJpsipPi = inv_mass(J_psi_1S_PX,J_psi_1S_PY,J_psi_1S_PZ,J_psi_1S_PE,H1_PX,H1_PY,H1_PZ,H1_PE,H2_PX,H2_PY,H2_PZ,H2_PE);
      //double mJpsiL = inv_mass(J_psi_1S_PX,J_psi_1S_PY,J_psi_1S_PZ,J_psi_1S_PE,R_PX,R_PY,R_PZ,R_PE,zero,zero,zero,zero);
      //double mdiff = mJpsipPi-mJpsiL;
      double chi2ndfv = J_psi_1S_ENDVERTEX_CHI2 / J_psi_1S_ENDVERTEX_NDOF;
      massJpsipPi->Fill(mJpsipPi);
      //massJpsiL->Fill(mJpsiL);
      //massdiff->Fill(mdiff);
      massJpsi->Fill(J_psi_1S_MM);
      chi2ndf->Fill(chi2ndfv);
      if(H2_TRACK_Type==3) ghostPiLL->Fill(H2_TRACK_GhostProb);
      if(H1_TRACK_Type==3) ghostpLL->Fill(H1_TRACK_GhostProb);
      if(muplus_TRACK_Type==3) ghostmuplLL->Fill(muplus_TRACK_GhostProb);
      if(muminus_TRACK_Type==3) ghostmumiLL->Fill(muminus_TRACK_GhostProb);
      if(H2_TRACK_Type!=3) ghostPiDD->Fill(H2_TRACK_GhostProb);
      if(H1_TRACK_Type!=3) ghostpDD->Fill(H1_TRACK_GhostProb);
      if(muplus_TRACK_Type!=3) ghostmuplDD->Fill(muplus_TRACK_GhostProb);
      if(muminus_TRACK_Type!=3) ghostmumiDD->Fill(muminus_TRACK_GhostProb);
      if((mJpsipPi>=5300)&&(mJpsipPi<=5750)&&(Bs_ENDVERTEX_CHI2/Bs_ENDVERTEX_NDOF<10)\
         &&(chi2ndfv<16)&&(J_psi_1S_MM>=3036.9)&&(J_psi_1S_MM<=3156.9)&&\
         (((H2_TRACK_Type==3) && (H2_TRACK_GhostProb<0.2))||H2_TRACK_Type!=3)&&\
         (((H1_TRACK_Type==3) && (H1_TRACK_GhostProb<0.2))||H1_TRACK_Type!=3)&&\
         (((muplus_TRACK_Type==3) && (muplus_TRACK_GhostProb<0.2))||muplus_TRACK_Type!=3)&&\
         (((muminus_TRACK_Type==3) && (muminus_TRACK_GhostProb<0.2))||muminus_TRACK_Type!=3)) cutmassJpsipPi->Fill(mJpsipPi);
      if(jentry%100000==0)cout<<jentry*100/nentries<<'%';
      if(jentry%10000==0)cout<<'.';
   }
   TCanvas *canvas1 = new TCanvas("canvas1","massJpsipPi",1200,800);
   cout<<"canvas 1/4  made"<<endl;
   gStyle->SetOptStat("nemruo");
   massJpsipPi->GetXaxis()->SetTitle("m(J/#psi p #pi) (MeV)");
   massJpsipPi->GetYaxis()->SetTitle("Events / 5MeV");
   massJpsipPi->Draw();
   canvas1->Print("massJpsipPi.ps");
   TCanvas *canvas2 = new TCanvas("canvas2","J/psi",1200,800);
   canvas2->Divide(2,1);
   cout<<"canvas 2/4 made"<<endl;
   canvas2->cd(1);
   gStyle->SetOptStat("nemruo");
   massJpsi->GetXaxis()->SetTitle("m(J/#psi) (MeV)");
   massJpsi->GetYaxis()->SetTitle("Events / 5MeV");
   massJpsi->Draw();
   canvas2->cd(2);
   gStyle->SetOptStat("nemruo");
   gPad->SetLogy();
   chi2ndf->GetXaxis()->SetTitle("#chi^{2}/NDF(J/#psi)");
   chi2ndf->GetYaxis()->SetTitle("Events / 0.1");
   chi2ndf->Draw();
   canvas2->Print("Jpsi.ps");
   TCanvas *canvas3 = new TCanvas("canvas3","GhostProb",1200,800);
   canvas3->Divide(2,2);
   cout<<"canvas 3/4 made"<<endl;
   canvas3->cd(1);
   gStyle->SetOptStat("nemruo");
   ghostPiLL->GetXaxis()->SetTitle("GhostProb(#pi)");
   ghostPiLL->GetYaxis()->SetTitle("Events / 0.01");
   ghostPiLL->Draw();
   canvas3->Update();
   ghostPiDD->SetLineColor(kRed);
   ghostPiDD->Draw("same");
   canvas3->cd(2);
   gStyle->SetOptStat("nemruo");
   ghostpLL->GetXaxis()->SetTitle("GhostProb(p)");
   ghostpLL->GetYaxis()->SetTitle("Events / 0.01");
   ghostpLL->Draw();
   canvas3->Update();
   ghostpDD->SetLineColor(kRed);
   ghostpDD->Draw("same");
   canvas3->cd(3);
   gStyle->SetOptStat("nemruo");
   ghostmuplLL->GetXaxis()->SetTitle("GhostProb(#mu^{+})");
   ghostmuplLL->GetYaxis()->SetTitle("Events / 0.01");
   ghostmuplLL->Draw();
   canvas3->Update();
   ghostmuplDD->SetLineColor(kRed);
   ghostmuplDD->Draw("same");
   canvas3->cd(4);
   gStyle->SetOptStat("nemruo");
   ghostmumiLL->GetXaxis()->SetTitle("GhostProb(#mu^{-})");
   ghostmumiLL->GetYaxis()->SetTitle("Events / 0.01");
   ghostmumiLL->Draw();
   canvas3->Update();
   ghostmumiDD->SetLineColor(kRed);
   ghostmumiDD->Draw("same");
   canvas3->Print("ghost.ps");
   TCanvas *canvas4 = new TCanvas("canvas4","cutmassJpsipPi",1200,800);
   canvas4->Divide(2,1);
   cout<<"canvas 4/4 made"<<endl;
   gStyle->SetOptStat("nemruo");
   cutmassJpsipPi->GetXaxis()->SetTitle("m(J/#psi p #pi) with cuts (MeV)");
   cutmassJpsipPi->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassJpsipPi->Draw();
   canvas4->Print("cutmassJpsipPi.ps");
   cout<<"done"<<endl;
}
