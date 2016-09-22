#define MyClass_cxx
#include "MyClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <string.h>

void MyClass::Loop(TH1F*hist,TString cutin)
{
//   In a ROOT session, you can do:
//      root> .L MyClass.C
//      root> MyClass t
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

   string cut = cutin.Data();
   double cutval = stod(cut.substr(cut.find(">")+1,cut.length()));


   Long64_t nentries = fChain->GetEntries();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      bool pass=1;
      if(Added_n_Particles>0)
	for(int i=0; i<Added_n_Particles; i++)
	  // if(Added_CharmH_VERTEXCHI2_NEW[i]<=cutval)//the event fails if any of these values are not greater than the cutoff
	  if((Added_CharmH_VERTEXCHI2_NEW[i]-Added_CharmH_VERTEXCHI2_OLD[i])<=cutval)
	    pass=0;
      if(pass){
	double value;
	TString brname = hist->GetTitle();
	if(brname.Contains("m(J/#psi K*)")) value = sqrt(pow(J_psi_1S_PE+R_PE,2)-pow(J_psi_1S_PX+R_PX,2)-pow(J_psi_1S_PY+R_PY,2)-pow(J_psi_1S_PZ+R_PZ,2));
	if(brname.Contains("B_{s} mass")) value = Bs_LOKI_MASS_JpsiConstr;
	if(brname.Contains("Added_n_Particles")) value = Added_n_Particles;
	hist->Fill(value);
      }
   }
}
