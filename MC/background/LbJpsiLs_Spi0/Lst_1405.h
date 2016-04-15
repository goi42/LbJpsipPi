//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Mar 11 21:25:36 2016 by ROOT version 6.06/00
// from TTree MCDecayTree/MCDecayTree
// found on file: /afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/Lst/Lb_JpsiLambda_mmSpi_1405_200000.root
//////////////////////////////////////////////////////////

#ifndef Lst_1405_h
#define Lst_1405_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class Lst_1405 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        J_psi_1S_TRUEP_E;
   Double_t        J_psi_1S_TRUEP_X;
   Double_t        J_psi_1S_TRUEP_Y;
   Double_t        J_psi_1S_TRUEP_Z;
   Double_t        Lambda0_TRUEP_E;
   Double_t        Lambda0_TRUEP_X;
   Double_t        Lambda0_TRUEP_Y;
   Double_t        Lambda0_TRUEP_Z;

   // List of branches
   TBranch        *b_J_psi_1S_TRUEP_E;   //!
   TBranch        *b_J_psi_1S_TRUEP_X;   //!
   TBranch        *b_J_psi_1S_TRUEP_Y;   //!
   TBranch        *b_J_psi_1S_TRUEP_Z;   //!
   TBranch        *b_Lambda0_TRUEP_E;   //!
   TBranch        *b_Lambda0_TRUEP_X;   //!
   TBranch        *b_Lambda0_TRUEP_Y;   //!
   TBranch        *b_Lambda0_TRUEP_Z;   //!

   Lst_1405(TTree *tree=0);
   virtual ~Lst_1405();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Lst_1405_cxx
Lst_1405::Lst_1405(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/Lst/Lb_JpsiLambda_mmSpi_1405_200000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/Lst/Lb_JpsiLambda_mmSpi_1405_200000.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/MC/Lst/Lb_JpsiLambda_mmSpi_1405_200000.root:/MCDecayTreeTuple");
      dir->GetObject("MCDecayTree",tree);

   }
   Init(tree);
}

Lst_1405::~Lst_1405()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Lst_1405::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Lst_1405::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Lst_1405::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("J_psi_1S_TRUEP_E", &J_psi_1S_TRUEP_E, &b_J_psi_1S_TRUEP_E);
   fChain->SetBranchAddress("J_psi_1S_TRUEP_X", &J_psi_1S_TRUEP_X, &b_J_psi_1S_TRUEP_X);
   fChain->SetBranchAddress("J_psi_1S_TRUEP_Y", &J_psi_1S_TRUEP_Y, &b_J_psi_1S_TRUEP_Y);
   fChain->SetBranchAddress("J_psi_1S_TRUEP_Z", &J_psi_1S_TRUEP_Z, &b_J_psi_1S_TRUEP_Z);
   fChain->SetBranchAddress("Lambda0_TRUEP_E", &Lambda0_TRUEP_E, &b_Lambda0_TRUEP_E);
   fChain->SetBranchAddress("Lambda0_TRUEP_X", &Lambda0_TRUEP_X, &b_Lambda0_TRUEP_X);
   fChain->SetBranchAddress("Lambda0_TRUEP_Y", &Lambda0_TRUEP_Y, &b_Lambda0_TRUEP_Y);
   fChain->SetBranchAddress("Lambda0_TRUEP_Z", &Lambda0_TRUEP_Z, &b_Lambda0_TRUEP_Z);
   Notify();
}

Bool_t Lst_1405::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Lst_1405::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Lst_1405::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Lst_1405_cxx
