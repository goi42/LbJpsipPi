#define Lb2JpsiL_cxx
#include "Lb2JpsiL.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <iomanip>
#include "TVector3.h"
#include "inv_mass.C"

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
   TH1F *mass = new TH1F("mass","invariant mass of J/#psi, p, and #pi",160,5000,5800);
   cout<<"histograms created"<<endl;
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      double zero = 0;
      double mJpsippi = inv_mass(J_psi_1S_PX,J_psi_1S_PY,J_psi_1S_PZ,J_psi_1S_PE,H1_PX,H1_PY,H1_PZ,H1_PE,H2_PX,H2_PY,H2_PZ,H2_PE);
      mass->Fill(mJpsippi);
      if(jentry%100000==0)cout<<jentry*100/nentries<<'%';
      if(jentry%10000==0)cout<<'.';
   }
   TCanvas *canvas = new TCanvas("canvas","mass",1200,800);
   cout<<"canvas made"<<endl;
   gStyle->SetOptStat("nemruo");
   mass->GetXaxis()->SetTitle("m(J/#psi p #pi) (MeV)");
   mass->GetYaxis()->SetTitle("Events / 5MeV");
   mass->Draw();
   canvas->Print("massJpsippi.ps");
   cout<<"done"<<endl;
}
