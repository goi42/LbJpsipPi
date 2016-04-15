//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jul 23 16:44:39 2015 by ROOT version 5.34/10
// from TTree mytree/mytree
// found on file: /afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/Lb2JpsiL2.root
//////////////////////////////////////////////////////////

#ifndef Lb2JpsiL_h
#define Lb2JpsiL_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxBs_ENDVERTEX_COV = 1;
const Int_t kMaxBs_OWNPV_COV = 1;
const Int_t kMaxBs_TOPPV_COV = 1;
const Int_t kMaxR_ENDVERTEX_COV = 1;
const Int_t kMaxR_OWNPV_COV = 1;
const Int_t kMaxR_TOPPV_COV = 1;
const Int_t kMaxR_ORIVX_COV = 1;
const Int_t kMaxH2_OWNPV_COV = 1;
const Int_t kMaxH2_TOPPV_COV = 1;
const Int_t kMaxH2_ORIVX_COV = 1;
const Int_t kMaxH1_OWNPV_COV = 1;
const Int_t kMaxH1_TOPPV_COV = 1;
const Int_t kMaxH1_ORIVX_COV = 1;
const Int_t kMaxJ_psi_1S_ENDVERTEX_COV = 1;
const Int_t kMaxJ_psi_1S_OWNPV_COV = 1;
const Int_t kMaxJ_psi_1S_TOPPV_COV = 1;
const Int_t kMaxJ_psi_1S_ORIVX_COV = 1;
const Int_t kMaxmuminus_OWNPV_COV = 1;
const Int_t kMaxmuminus_TOPPV_COV = 1;
const Int_t kMaxmuminus_ORIVX_COV = 1;
const Int_t kMaxmuplus_OWNPV_COV = 1;
const Int_t kMaxmuplus_TOPPV_COV = 1;
const Int_t kMaxmuplus_ORIVX_COV = 1;

class Lb2JpsiL {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        Bs_MINIP;
   Double_t        Bs_MINIPCHI2;
   Double_t        Bs_MINIPNEXTBEST;
   Double_t        Bs_MINIPCHI2NEXTBEST;
   Double_t        Bs_ENDVERTEX_X;
   Double_t        Bs_ENDVERTEX_Y;
   Double_t        Bs_ENDVERTEX_Z;
   Double_t        Bs_ENDVERTEX_XERR;
   Double_t        Bs_ENDVERTEX_YERR;
   Double_t        Bs_ENDVERTEX_ZERR;
   Double_t        Bs_ENDVERTEX_CHI2;
   Int_t           Bs_ENDVERTEX_NDOF;
   Float_t         Bs_ENDVERTEX_COV_[3][3];
   Double_t        Bs_OWNPV_X;
   Double_t        Bs_OWNPV_Y;
   Double_t        Bs_OWNPV_Z;
   Double_t        Bs_OWNPV_XERR;
   Double_t        Bs_OWNPV_YERR;
   Double_t        Bs_OWNPV_ZERR;
   Double_t        Bs_OWNPV_CHI2;
   Int_t           Bs_OWNPV_NDOF;
   Float_t         Bs_OWNPV_COV_[3][3];
   Double_t        Bs_IP_OWNPV;
   Double_t        Bs_IPCHI2_OWNPV;
   Double_t        Bs_FD_OWNPV;
   Double_t        Bs_FDCHI2_OWNPV;
   Double_t        Bs_DIRA_OWNPV;
   Double_t        Bs_TOPPV_X;
   Double_t        Bs_TOPPV_Y;
   Double_t        Bs_TOPPV_Z;
   Double_t        Bs_TOPPV_XERR;
   Double_t        Bs_TOPPV_YERR;
   Double_t        Bs_TOPPV_ZERR;
   Double_t        Bs_TOPPV_CHI2;
   Int_t           Bs_TOPPV_NDOF;
   Float_t         Bs_TOPPV_COV_[3][3];
   Double_t        Bs_IP_TOPPV;
   Double_t        Bs_IPCHI2_TOPPV;
   Double_t        Bs_FD_TOPPV;
   Double_t        Bs_FDCHI2_TOPPV;
   Double_t        Bs_DIRA_TOPPV;
   Double_t        Bs_P;
   Double_t        Bs_PT;
   Double_t        Bs_PE;
   Double_t        Bs_PX;
   Double_t        Bs_PY;
   Double_t        Bs_PZ;
   Double_t        Bs_MM;
   Double_t        Bs_MMERR;
   Double_t        Bs_M;
   Int_t           Bs_ID;
   Double_t        Bs_LOKI_DTF_CHI2NDOF;
   Double_t        Bs_LOKI_DTF_CTAU;
   Double_t        Bs_LOKI_DTF_CTAUERR;
   Double_t        Bs_LOKI_DTF_VCHI2NDOF;
   Double_t        Bs_LOKI_MASS_JpsiConstr;
   Double_t        Bs_TAU;
   Double_t        Bs_TAUERR;
   Double_t        Bs_TAUCHI2;
   Bool_t          BsL0Global_Dec;
   Bool_t          BsL0Global_TIS;
   Bool_t          BsL0Global_TOS;
   Bool_t          BsHlt1Global_Dec;
   Bool_t          BsHlt1Global_TIS;
   Bool_t          BsHlt1Global_TOS;
   Bool_t          BsHlt1Phys_Dec;
   Bool_t          BsHlt1Phys_TIS;
   Bool_t          BsHlt1Phys_TOS;
   Bool_t          BsHlt2Global_Dec;
   Bool_t          BsHlt2Global_TIS;
   Bool_t          BsHlt2Global_TOS;
   Bool_t          BsHlt2Phys_Dec;
   Bool_t          BsHlt2Phys_TIS;
   Bool_t          BsHlt2Phys_TOS;
   Bool_t          BsStrippingGlobal_Dec;
   Bool_t          BsStrippingGlobal_TIS;
   Bool_t          BsStrippingGlobal_TOS;
   Bool_t          BsL0DiMuonDecision_Dec;
   Bool_t          BsL0DiMuonDecision_TIS;
   Bool_t          BsL0DiMuonDecision_TOS;
   Bool_t          BsL0HCALDecision_Dec;
   Bool_t          BsL0HCALDecision_TIS;
   Bool_t          BsL0HCALDecision_TOS;
   Bool_t          BsL0MuonDecision_Dec;
   Bool_t          BsL0MuonDecision_TIS;
   Bool_t          BsL0MuonDecision_TOS;
   Bool_t          BsL0MuonHighDecision_Dec;
   Bool_t          BsL0MuonHighDecision_TIS;
   Bool_t          BsL0MuonHighDecision_TOS;
   Bool_t          BsHlt1SingleMuonNoIPL0Decision_Dec;
   Bool_t          BsHlt1SingleMuonNoIPL0Decision_TIS;
   Bool_t          BsHlt1SingleMuonNoIPL0Decision_TOS;
   Bool_t          BsHlt1DiMuonHighMassDecision_Dec;
   Bool_t          BsHlt1DiMuonHighMassDecision_TIS;
   Bool_t          BsHlt1DiMuonHighMassDecision_TOS;
   Bool_t          BsHlt1DiMuonLowMassDecision_Dec;
   Bool_t          BsHlt1DiMuonLowMassDecision_TIS;
   Bool_t          BsHlt1DiMuonLowMassDecision_TOS;
   Bool_t          BsHlt1SingleMuonHighPTDecision_Dec;
   Bool_t          BsHlt1SingleMuonHighPTDecision_TIS;
   Bool_t          BsHlt1SingleMuonHighPTDecision_TOS;
   Bool_t          BsHlt1SingleMuonNoIPDecision_Dec;
   Bool_t          BsHlt1SingleMuonNoIPDecision_TIS;
   Bool_t          BsHlt1SingleMuonNoIPDecision_TOS;
   Bool_t          BsHlt1TrackAllL0Decision_Dec;
   Bool_t          BsHlt1TrackAllL0Decision_TIS;
   Bool_t          BsHlt1TrackAllL0Decision_TOS;
   Bool_t          BsHlt1TrackMuonDecision_Dec;
   Bool_t          BsHlt1TrackMuonDecision_TIS;
   Bool_t          BsHlt1TrackMuonDecision_TOS;
   Bool_t          BsHlt2DiMuonBDecision_Dec;
   Bool_t          BsHlt2DiMuonBDecision_TIS;
   Bool_t          BsHlt2DiMuonBDecision_TOS;
   Bool_t          BsHlt2DiMuonDecision_Dec;
   Bool_t          BsHlt2DiMuonDecision_TIS;
   Bool_t          BsHlt2DiMuonDecision_TOS;
   Bool_t          BsHlt2DiMuonDY1Decision_Dec;
   Bool_t          BsHlt2DiMuonDY1Decision_TIS;
   Bool_t          BsHlt2DiMuonDY1Decision_TOS;
   Bool_t          BsHlt2DiMuonDetachedDecision_Dec;
   Bool_t          BsHlt2DiMuonDetachedDecision_TIS;
   Bool_t          BsHlt2DiMuonDetachedDecision_TOS;
   Bool_t          BsHlt2DiMuonDetachedHeavyDecision_Dec;
   Bool_t          BsHlt2DiMuonDetachedHeavyDecision_TIS;
   Bool_t          BsHlt2DiMuonDetachedHeavyDecision_TOS;
   Bool_t          BsHlt2DiMuonDetachedJPsiDecision_Dec;
   Bool_t          BsHlt2DiMuonDetachedJPsiDecision_TIS;
   Bool_t          BsHlt2DiMuonDetachedJPsiDecision_TOS;
   Bool_t          BsHlt2DiMuonJPsiDecision_Dec;
   Bool_t          BsHlt2DiMuonJPsiDecision_TIS;
   Bool_t          BsHlt2DiMuonJPsiDecision_TOS;
   Bool_t          BsHlt2DiMuonJPsiHighPTDecision_Dec;
   Bool_t          BsHlt2DiMuonJPsiHighPTDecision_TIS;
   Bool_t          BsHlt2DiMuonJPsiHighPTDecision_TOS;
   Bool_t          BsHlt2ExpressJPsiDecision_Dec;
   Bool_t          BsHlt2ExpressJPsiDecision_TIS;
   Bool_t          BsHlt2ExpressJPsiDecision_TOS;
   Bool_t          BsHlt2ExpressJPsiTagProbeDecision_Dec;
   Bool_t          BsHlt2ExpressJPsiTagProbeDecision_TIS;
   Bool_t          BsHlt2ExpressJPsiTagProbeDecision_TOS;
   Bool_t          BsHlt2SingleMuonDecision_Dec;
   Bool_t          BsHlt2SingleMuonDecision_TIS;
   Bool_t          BsHlt2SingleMuonDecision_TOS;
   Bool_t          BsHlt2SingleMuonHighPTDecision_Dec;
   Bool_t          BsHlt2SingleMuonHighPTDecision_TIS;
   Bool_t          BsHlt2SingleMuonHighPTDecision_TOS;
   Bool_t          BsHlt2SingleMuonLowPTDecision_Dec;
   Bool_t          BsHlt2SingleMuonLowPTDecision_TIS;
   Bool_t          BsHlt2SingleMuonLowPTDecision_TOS;
   Bool_t          BsHlt2Topo2BodyBBDTDecision_Dec;
   Bool_t          BsHlt2Topo2BodyBBDTDecision_TIS;
   Bool_t          BsHlt2Topo2BodyBBDTDecision_TOS;
   Bool_t          BsHlt2Topo2BodySimpleDecision_Dec;
   Bool_t          BsHlt2Topo2BodySimpleDecision_TIS;
   Bool_t          BsHlt2Topo2BodySimpleDecision_TOS;
   Bool_t          BsHlt2Topo3BodyBBDTDecision_Dec;
   Bool_t          BsHlt2Topo3BodyBBDTDecision_TIS;
   Bool_t          BsHlt2Topo3BodyBBDTDecision_TOS;
   Bool_t          BsHlt2Topo3BodySimpleDecision_Dec;
   Bool_t          BsHlt2Topo3BodySimpleDecision_TIS;
   Bool_t          BsHlt2Topo3BodySimpleDecision_TOS;
   Bool_t          BsHlt2Topo4BodyBBDTDecision_Dec;
   Bool_t          BsHlt2Topo4BodyBBDTDecision_TIS;
   Bool_t          BsHlt2Topo4BodyBBDTDecision_TOS;
   Bool_t          BsHlt2Topo4BodySimpleDecision_Dec;
   Bool_t          BsHlt2Topo4BodySimpleDecision_TIS;
   Bool_t          BsHlt2Topo4BodySimpleDecision_TOS;
   Bool_t          BsHlt2TopoMu2BodyBBDTDecision_Dec;
   Bool_t          BsHlt2TopoMu2BodyBBDTDecision_TIS;
   Bool_t          BsHlt2TopoMu2BodyBBDTDecision_TOS;
   Bool_t          BsHlt2TopoMu3BodyBBDTDecision_Dec;
   Bool_t          BsHlt2TopoMu3BodyBBDTDecision_TIS;
   Bool_t          BsHlt2TopoMu3BodyBBDTDecision_TOS;
   Bool_t          BsHlt2TopoMu4BodyBBDTDecision_Dec;
   Bool_t          BsHlt2TopoMu4BodyBBDTDecision_TIS;
   Bool_t          BsHlt2TopoMu4BodyBBDTDecision_TOS;
   Bool_t          BsHlt2TransparentDecision_Dec;
   Bool_t          BsHlt2TransparentDecision_TIS;
   Bool_t          BsHlt2TransparentDecision_TOS;
   Bool_t          BsHlt2DiMuonUnbiasedJPsiDecision_Dec;
   Bool_t          BsHlt2DiMuonUnbiasedJPsiDecision_TIS;
   Bool_t          BsHlt2DiMuonUnbiasedJPsiDecision_TOS;
   Double_t        R_MINIP;
   Double_t        R_MINIPCHI2;
   Double_t        R_MINIPNEXTBEST;
   Double_t        R_MINIPCHI2NEXTBEST;
   Double_t        R_ENDVERTEX_X;
   Double_t        R_ENDVERTEX_Y;
   Double_t        R_ENDVERTEX_Z;
   Double_t        R_ENDVERTEX_XERR;
   Double_t        R_ENDVERTEX_YERR;
   Double_t        R_ENDVERTEX_ZERR;
   Double_t        R_ENDVERTEX_CHI2;
   Int_t           R_ENDVERTEX_NDOF;
   Float_t         R_ENDVERTEX_COV_[3][3];
   Double_t        R_OWNPV_X;
   Double_t        R_OWNPV_Y;
   Double_t        R_OWNPV_Z;
   Double_t        R_OWNPV_XERR;
   Double_t        R_OWNPV_YERR;
   Double_t        R_OWNPV_ZERR;
   Double_t        R_OWNPV_CHI2;
   Int_t           R_OWNPV_NDOF;
   Float_t         R_OWNPV_COV_[3][3];
   Double_t        R_IP_OWNPV;
   Double_t        R_IPCHI2_OWNPV;
   Double_t        R_FD_OWNPV;
   Double_t        R_FDCHI2_OWNPV;
   Double_t        R_DIRA_OWNPV;
   Double_t        R_TOPPV_X;
   Double_t        R_TOPPV_Y;
   Double_t        R_TOPPV_Z;
   Double_t        R_TOPPV_XERR;
   Double_t        R_TOPPV_YERR;
   Double_t        R_TOPPV_ZERR;
   Double_t        R_TOPPV_CHI2;
   Int_t           R_TOPPV_NDOF;
   Float_t         R_TOPPV_COV_[3][3];
   Double_t        R_IP_TOPPV;
   Double_t        R_IPCHI2_TOPPV;
   Double_t        R_FD_TOPPV;
   Double_t        R_FDCHI2_TOPPV;
   Double_t        R_DIRA_TOPPV;
   Double_t        R_ORIVX_X;
   Double_t        R_ORIVX_Y;
   Double_t        R_ORIVX_Z;
   Double_t        R_ORIVX_XERR;
   Double_t        R_ORIVX_YERR;
   Double_t        R_ORIVX_ZERR;
   Double_t        R_ORIVX_CHI2;
   Int_t           R_ORIVX_NDOF;
   Float_t         R_ORIVX_COV_[3][3];
   Double_t        R_IP_ORIVX;
   Double_t        R_IPCHI2_ORIVX;
   Double_t        R_FD_ORIVX;
   Double_t        R_FDCHI2_ORIVX;
   Double_t        R_DIRA_ORIVX;
   Double_t        R_P;
   Double_t        R_PT;
   Double_t        R_PE;
   Double_t        R_PX;
   Double_t        R_PY;
   Double_t        R_PZ;
   Double_t        R_MM;
   Double_t        R_MMERR;
   Double_t        R_M;
   Int_t           R_ID;
   Double_t        H2_MINIP;
   Double_t        H2_MINIPCHI2;
   Double_t        H2_MINIPNEXTBEST;
   Double_t        H2_MINIPCHI2NEXTBEST;
   Double_t        H2_OWNPV_X;
   Double_t        H2_OWNPV_Y;
   Double_t        H2_OWNPV_Z;
   Double_t        H2_OWNPV_XERR;
   Double_t        H2_OWNPV_YERR;
   Double_t        H2_OWNPV_ZERR;
   Double_t        H2_OWNPV_CHI2;
   Int_t           H2_OWNPV_NDOF;
   Float_t         H2_OWNPV_COV_[3][3];
   Double_t        H2_IP_OWNPV;
   Double_t        H2_IPCHI2_OWNPV;
   Double_t        H2_TOPPV_X;
   Double_t        H2_TOPPV_Y;
   Double_t        H2_TOPPV_Z;
   Double_t        H2_TOPPV_XERR;
   Double_t        H2_TOPPV_YERR;
   Double_t        H2_TOPPV_ZERR;
   Double_t        H2_TOPPV_CHI2;
   Int_t           H2_TOPPV_NDOF;
   Float_t         H2_TOPPV_COV_[3][3];
   Double_t        H2_IP_TOPPV;
   Double_t        H2_IPCHI2_TOPPV;
   Double_t        H2_ORIVX_X;
   Double_t        H2_ORIVX_Y;
   Double_t        H2_ORIVX_Z;
   Double_t        H2_ORIVX_XERR;
   Double_t        H2_ORIVX_YERR;
   Double_t        H2_ORIVX_ZERR;
   Double_t        H2_ORIVX_CHI2;
   Int_t           H2_ORIVX_NDOF;
   Float_t         H2_ORIVX_COV_[3][3];
   Double_t        H2_IP_ORIVX;
   Double_t        H2_IPCHI2_ORIVX;
   Double_t        H2_P;
   Double_t        H2_PT;
   Double_t        H2_PE;
   Double_t        H2_PX;
   Double_t        H2_PY;
   Double_t        H2_PZ;
   Double_t        H2_M;
   Int_t           H2_ID;
   Double_t        H2_PIDe;
   Double_t        H2_PIDmu;
   Double_t        H2_PIDK;
   Double_t        H2_PIDp;
   Double_t        H2_ProbNNe;
   Double_t        H2_ProbNNk;
   Double_t        H2_ProbNNp;
   Double_t        H2_ProbNNpi;
   Double_t        H2_ProbNNmu;
   Double_t        H2_ProbNNghost;
   Bool_t          H2_hasMuon;
   Bool_t          H2_isMuon;
   Bool_t          H2_hasRich;
   Bool_t          H2_hasCalo;
   Int_t           H2_TRACK_Type;
   Int_t           H2_TRACK_Key;
   Double_t        H2_TRACK_CHI2NDOF;
   Double_t        H2_TRACK_PCHI2;
   Double_t        H2_TRACK_MatchCHI2;
   Double_t        H2_TRACK_GhostProb;
   Double_t        H2_TRACK_CloneDist;
   Double_t        H2_TRACK_Likelihood;
   Double_t        H1_MINIP;
   Double_t        H1_MINIPCHI2;
   Double_t        H1_MINIPNEXTBEST;
   Double_t        H1_MINIPCHI2NEXTBEST;
   Double_t        H1_OWNPV_X;
   Double_t        H1_OWNPV_Y;
   Double_t        H1_OWNPV_Z;
   Double_t        H1_OWNPV_XERR;
   Double_t        H1_OWNPV_YERR;
   Double_t        H1_OWNPV_ZERR;
   Double_t        H1_OWNPV_CHI2;
   Int_t           H1_OWNPV_NDOF;
   Float_t         H1_OWNPV_COV_[3][3];
   Double_t        H1_IP_OWNPV;
   Double_t        H1_IPCHI2_OWNPV;
   Double_t        H1_TOPPV_X;
   Double_t        H1_TOPPV_Y;
   Double_t        H1_TOPPV_Z;
   Double_t        H1_TOPPV_XERR;
   Double_t        H1_TOPPV_YERR;
   Double_t        H1_TOPPV_ZERR;
   Double_t        H1_TOPPV_CHI2;
   Int_t           H1_TOPPV_NDOF;
   Float_t         H1_TOPPV_COV_[3][3];
   Double_t        H1_IP_TOPPV;
   Double_t        H1_IPCHI2_TOPPV;
   Double_t        H1_ORIVX_X;
   Double_t        H1_ORIVX_Y;
   Double_t        H1_ORIVX_Z;
   Double_t        H1_ORIVX_XERR;
   Double_t        H1_ORIVX_YERR;
   Double_t        H1_ORIVX_ZERR;
   Double_t        H1_ORIVX_CHI2;
   Int_t           H1_ORIVX_NDOF;
   Float_t         H1_ORIVX_COV_[3][3];
   Double_t        H1_IP_ORIVX;
   Double_t        H1_IPCHI2_ORIVX;
   Double_t        H1_P;
   Double_t        H1_PT;
   Double_t        H1_PE;
   Double_t        H1_PX;
   Double_t        H1_PY;
   Double_t        H1_PZ;
   Double_t        H1_M;
   Int_t           H1_ID;
   Double_t        H1_PIDe;
   Double_t        H1_PIDmu;
   Double_t        H1_PIDK;
   Double_t        H1_PIDp;
   Double_t        H1_ProbNNe;
   Double_t        H1_ProbNNk;
   Double_t        H1_ProbNNp;
   Double_t        H1_ProbNNpi;
   Double_t        H1_ProbNNmu;
   Double_t        H1_ProbNNghost;
   Bool_t          H1_hasMuon;
   Bool_t          H1_isMuon;
   Bool_t          H1_hasRich;
   Bool_t          H1_hasCalo;
   Int_t           H1_TRACK_Type;
   Int_t           H1_TRACK_Key;
   Double_t        H1_TRACK_CHI2NDOF;
   Double_t        H1_TRACK_PCHI2;
   Double_t        H1_TRACK_MatchCHI2;
   Double_t        H1_TRACK_GhostProb;
   Double_t        H1_TRACK_CloneDist;
   Double_t        H1_TRACK_Likelihood;
   Double_t        J_psi_1S_MINIP;
   Double_t        J_psi_1S_MINIPCHI2;
   Double_t        J_psi_1S_MINIPNEXTBEST;
   Double_t        J_psi_1S_MINIPCHI2NEXTBEST;
   Double_t        J_psi_1S_ENDVERTEX_X;
   Double_t        J_psi_1S_ENDVERTEX_Y;
   Double_t        J_psi_1S_ENDVERTEX_Z;
   Double_t        J_psi_1S_ENDVERTEX_XERR;
   Double_t        J_psi_1S_ENDVERTEX_YERR;
   Double_t        J_psi_1S_ENDVERTEX_ZERR;
   Double_t        J_psi_1S_ENDVERTEX_CHI2;
   Int_t           J_psi_1S_ENDVERTEX_NDOF;
   Float_t         J_psi_1S_ENDVERTEX_COV_[3][3];
   Double_t        J_psi_1S_OWNPV_X;
   Double_t        J_psi_1S_OWNPV_Y;
   Double_t        J_psi_1S_OWNPV_Z;
   Double_t        J_psi_1S_OWNPV_XERR;
   Double_t        J_psi_1S_OWNPV_YERR;
   Double_t        J_psi_1S_OWNPV_ZERR;
   Double_t        J_psi_1S_OWNPV_CHI2;
   Int_t           J_psi_1S_OWNPV_NDOF;
   Float_t         J_psi_1S_OWNPV_COV_[3][3];
   Double_t        J_psi_1S_IP_OWNPV;
   Double_t        J_psi_1S_IPCHI2_OWNPV;
   Double_t        J_psi_1S_FD_OWNPV;
   Double_t        J_psi_1S_FDCHI2_OWNPV;
   Double_t        J_psi_1S_DIRA_OWNPV;
   Double_t        J_psi_1S_TOPPV_X;
   Double_t        J_psi_1S_TOPPV_Y;
   Double_t        J_psi_1S_TOPPV_Z;
   Double_t        J_psi_1S_TOPPV_XERR;
   Double_t        J_psi_1S_TOPPV_YERR;
   Double_t        J_psi_1S_TOPPV_ZERR;
   Double_t        J_psi_1S_TOPPV_CHI2;
   Int_t           J_psi_1S_TOPPV_NDOF;
   Float_t         J_psi_1S_TOPPV_COV_[3][3];
   Double_t        J_psi_1S_IP_TOPPV;
   Double_t        J_psi_1S_IPCHI2_TOPPV;
   Double_t        J_psi_1S_FD_TOPPV;
   Double_t        J_psi_1S_FDCHI2_TOPPV;
   Double_t        J_psi_1S_DIRA_TOPPV;
   Double_t        J_psi_1S_ORIVX_X;
   Double_t        J_psi_1S_ORIVX_Y;
   Double_t        J_psi_1S_ORIVX_Z;
   Double_t        J_psi_1S_ORIVX_XERR;
   Double_t        J_psi_1S_ORIVX_YERR;
   Double_t        J_psi_1S_ORIVX_ZERR;
   Double_t        J_psi_1S_ORIVX_CHI2;
   Int_t           J_psi_1S_ORIVX_NDOF;
   Float_t         J_psi_1S_ORIVX_COV_[3][3];
   Double_t        J_psi_1S_IP_ORIVX;
   Double_t        J_psi_1S_IPCHI2_ORIVX;
   Double_t        J_psi_1S_FD_ORIVX;
   Double_t        J_psi_1S_FDCHI2_ORIVX;
   Double_t        J_psi_1S_DIRA_ORIVX;
   Double_t        J_psi_1S_P;
   Double_t        J_psi_1S_PT;
   Double_t        J_psi_1S_PE;
   Double_t        J_psi_1S_PX;
   Double_t        J_psi_1S_PY;
   Double_t        J_psi_1S_PZ;
   Double_t        J_psi_1S_MM;
   Double_t        J_psi_1S_MMERR;
   Double_t        J_psi_1S_M;
   Int_t           J_psi_1S_ID;
   Bool_t          J_psi_1SL0Global_Dec;
   Bool_t          J_psi_1SL0Global_TIS;
   Bool_t          J_psi_1SL0Global_TOS;
   Bool_t          J_psi_1SHlt1Global_Dec;
   Bool_t          J_psi_1SHlt1Global_TIS;
   Bool_t          J_psi_1SHlt1Global_TOS;
   Bool_t          J_psi_1SHlt1Phys_Dec;
   Bool_t          J_psi_1SHlt1Phys_TIS;
   Bool_t          J_psi_1SHlt1Phys_TOS;
   Bool_t          J_psi_1SHlt2Global_Dec;
   Bool_t          J_psi_1SHlt2Global_TIS;
   Bool_t          J_psi_1SHlt2Global_TOS;
   Bool_t          J_psi_1SHlt2Phys_Dec;
   Bool_t          J_psi_1SHlt2Phys_TIS;
   Bool_t          J_psi_1SHlt2Phys_TOS;
   Bool_t          J_psi_1SStrippingGlobal_Dec;
   Bool_t          J_psi_1SStrippingGlobal_TIS;
   Bool_t          J_psi_1SStrippingGlobal_TOS;
   Bool_t          J_psi_1SL0DiMuonDecision_Dec;
   Bool_t          J_psi_1SL0DiMuonDecision_TIS;
   Bool_t          J_psi_1SL0DiMuonDecision_TOS;
   Bool_t          J_psi_1SL0HCALDecision_Dec;
   Bool_t          J_psi_1SL0HCALDecision_TIS;
   Bool_t          J_psi_1SL0HCALDecision_TOS;
   Bool_t          J_psi_1SL0MuonDecision_Dec;
   Bool_t          J_psi_1SL0MuonDecision_TIS;
   Bool_t          J_psi_1SL0MuonDecision_TOS;
   Bool_t          J_psi_1SL0MuonHighDecision_Dec;
   Bool_t          J_psi_1SL0MuonHighDecision_TIS;
   Bool_t          J_psi_1SL0MuonHighDecision_TOS;
   Bool_t          J_psi_1SHlt1SingleMuonNoIPL0Decision_Dec;
   Bool_t          J_psi_1SHlt1SingleMuonNoIPL0Decision_TIS;
   Bool_t          J_psi_1SHlt1SingleMuonNoIPL0Decision_TOS;
   Bool_t          J_psi_1SHlt1DiMuonHighMassDecision_Dec;
   Bool_t          J_psi_1SHlt1DiMuonHighMassDecision_TIS;
   Bool_t          J_psi_1SHlt1DiMuonHighMassDecision_TOS;
   Bool_t          J_psi_1SHlt1DiMuonLowMassDecision_Dec;
   Bool_t          J_psi_1SHlt1DiMuonLowMassDecision_TIS;
   Bool_t          J_psi_1SHlt1DiMuonLowMassDecision_TOS;
   Bool_t          J_psi_1SHlt1SingleMuonHighPTDecision_Dec;
   Bool_t          J_psi_1SHlt1SingleMuonHighPTDecision_TIS;
   Bool_t          J_psi_1SHlt1SingleMuonHighPTDecision_TOS;
   Bool_t          J_psi_1SHlt1SingleMuonNoIPDecision_Dec;
   Bool_t          J_psi_1SHlt1SingleMuonNoIPDecision_TIS;
   Bool_t          J_psi_1SHlt1SingleMuonNoIPDecision_TOS;
   Bool_t          J_psi_1SHlt1TrackAllL0Decision_Dec;
   Bool_t          J_psi_1SHlt1TrackAllL0Decision_TIS;
   Bool_t          J_psi_1SHlt1TrackAllL0Decision_TOS;
   Bool_t          J_psi_1SHlt1TrackMuonDecision_Dec;
   Bool_t          J_psi_1SHlt1TrackMuonDecision_TIS;
   Bool_t          J_psi_1SHlt1TrackMuonDecision_TOS;
   Bool_t          J_psi_1SHlt2DiMuonBDecision_Dec;
   Bool_t          J_psi_1SHlt2DiMuonBDecision_TIS;
   Bool_t          J_psi_1SHlt2DiMuonBDecision_TOS;
   Bool_t          J_psi_1SHlt2DiMuonDecision_Dec;
   Bool_t          J_psi_1SHlt2DiMuonDecision_TIS;
   Bool_t          J_psi_1SHlt2DiMuonDecision_TOS;
   Bool_t          J_psi_1SHlt2DiMuonDY1Decision_Dec;
   Bool_t          J_psi_1SHlt2DiMuonDY1Decision_TIS;
   Bool_t          J_psi_1SHlt2DiMuonDY1Decision_TOS;
   Bool_t          J_psi_1SHlt2DiMuonDetachedDecision_Dec;
   Bool_t          J_psi_1SHlt2DiMuonDetachedDecision_TIS;
   Bool_t          J_psi_1SHlt2DiMuonDetachedDecision_TOS;
   Bool_t          J_psi_1SHlt2DiMuonDetachedHeavyDecision_Dec;
   Bool_t          J_psi_1SHlt2DiMuonDetachedHeavyDecision_TIS;
   Bool_t          J_psi_1SHlt2DiMuonDetachedHeavyDecision_TOS;
   Bool_t          J_psi_1SHlt2DiMuonDetachedJPsiDecision_Dec;
   Bool_t          J_psi_1SHlt2DiMuonDetachedJPsiDecision_TIS;
   Bool_t          J_psi_1SHlt2DiMuonDetachedJPsiDecision_TOS;
   Bool_t          J_psi_1SHlt2DiMuonJPsiDecision_Dec;
   Bool_t          J_psi_1SHlt2DiMuonJPsiDecision_TIS;
   Bool_t          J_psi_1SHlt2DiMuonJPsiDecision_TOS;
   Bool_t          J_psi_1SHlt2DiMuonJPsiHighPTDecision_Dec;
   Bool_t          J_psi_1SHlt2DiMuonJPsiHighPTDecision_TIS;
   Bool_t          J_psi_1SHlt2DiMuonJPsiHighPTDecision_TOS;
   Bool_t          J_psi_1SHlt2ExpressJPsiDecision_Dec;
   Bool_t          J_psi_1SHlt2ExpressJPsiDecision_TIS;
   Bool_t          J_psi_1SHlt2ExpressJPsiDecision_TOS;
   Bool_t          J_psi_1SHlt2ExpressJPsiTagProbeDecision_Dec;
   Bool_t          J_psi_1SHlt2ExpressJPsiTagProbeDecision_TIS;
   Bool_t          J_psi_1SHlt2ExpressJPsiTagProbeDecision_TOS;
   Bool_t          J_psi_1SHlt2SingleMuonDecision_Dec;
   Bool_t          J_psi_1SHlt2SingleMuonDecision_TIS;
   Bool_t          J_psi_1SHlt2SingleMuonDecision_TOS;
   Bool_t          J_psi_1SHlt2SingleMuonHighPTDecision_Dec;
   Bool_t          J_psi_1SHlt2SingleMuonHighPTDecision_TIS;
   Bool_t          J_psi_1SHlt2SingleMuonHighPTDecision_TOS;
   Bool_t          J_psi_1SHlt2SingleMuonLowPTDecision_Dec;
   Bool_t          J_psi_1SHlt2SingleMuonLowPTDecision_TIS;
   Bool_t          J_psi_1SHlt2SingleMuonLowPTDecision_TOS;
   Bool_t          J_psi_1SHlt2Topo2BodyBBDTDecision_Dec;
   Bool_t          J_psi_1SHlt2Topo2BodyBBDTDecision_TIS;
   Bool_t          J_psi_1SHlt2Topo2BodyBBDTDecision_TOS;
   Bool_t          J_psi_1SHlt2Topo2BodySimpleDecision_Dec;
   Bool_t          J_psi_1SHlt2Topo2BodySimpleDecision_TIS;
   Bool_t          J_psi_1SHlt2Topo2BodySimpleDecision_TOS;
   Bool_t          J_psi_1SHlt2Topo3BodyBBDTDecision_Dec;
   Bool_t          J_psi_1SHlt2Topo3BodyBBDTDecision_TIS;
   Bool_t          J_psi_1SHlt2Topo3BodyBBDTDecision_TOS;
   Bool_t          J_psi_1SHlt2Topo3BodySimpleDecision_Dec;
   Bool_t          J_psi_1SHlt2Topo3BodySimpleDecision_TIS;
   Bool_t          J_psi_1SHlt2Topo3BodySimpleDecision_TOS;
   Bool_t          J_psi_1SHlt2Topo4BodyBBDTDecision_Dec;
   Bool_t          J_psi_1SHlt2Topo4BodyBBDTDecision_TIS;
   Bool_t          J_psi_1SHlt2Topo4BodyBBDTDecision_TOS;
   Bool_t          J_psi_1SHlt2Topo4BodySimpleDecision_Dec;
   Bool_t          J_psi_1SHlt2Topo4BodySimpleDecision_TIS;
   Bool_t          J_psi_1SHlt2Topo4BodySimpleDecision_TOS;
   Bool_t          J_psi_1SHlt2TopoMu2BodyBBDTDecision_Dec;
   Bool_t          J_psi_1SHlt2TopoMu2BodyBBDTDecision_TIS;
   Bool_t          J_psi_1SHlt2TopoMu2BodyBBDTDecision_TOS;
   Bool_t          J_psi_1SHlt2TopoMu3BodyBBDTDecision_Dec;
   Bool_t          J_psi_1SHlt2TopoMu3BodyBBDTDecision_TIS;
   Bool_t          J_psi_1SHlt2TopoMu3BodyBBDTDecision_TOS;
   Bool_t          J_psi_1SHlt2TopoMu4BodyBBDTDecision_Dec;
   Bool_t          J_psi_1SHlt2TopoMu4BodyBBDTDecision_TIS;
   Bool_t          J_psi_1SHlt2TopoMu4BodyBBDTDecision_TOS;
   Bool_t          J_psi_1SHlt2TransparentDecision_Dec;
   Bool_t          J_psi_1SHlt2TransparentDecision_TIS;
   Bool_t          J_psi_1SHlt2TransparentDecision_TOS;
   Bool_t          J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_Dec;
   Bool_t          J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_TIS;
   Bool_t          J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_TOS;
   Double_t        muminus_MINIP;
   Double_t        muminus_MINIPCHI2;
   Double_t        muminus_MINIPNEXTBEST;
   Double_t        muminus_MINIPCHI2NEXTBEST;
   Double_t        muminus_OWNPV_X;
   Double_t        muminus_OWNPV_Y;
   Double_t        muminus_OWNPV_Z;
   Double_t        muminus_OWNPV_XERR;
   Double_t        muminus_OWNPV_YERR;
   Double_t        muminus_OWNPV_ZERR;
   Double_t        muminus_OWNPV_CHI2;
   Int_t           muminus_OWNPV_NDOF;
   Float_t         muminus_OWNPV_COV_[3][3];
   Double_t        muminus_IP_OWNPV;
   Double_t        muminus_IPCHI2_OWNPV;
   Double_t        muminus_TOPPV_X;
   Double_t        muminus_TOPPV_Y;
   Double_t        muminus_TOPPV_Z;
   Double_t        muminus_TOPPV_XERR;
   Double_t        muminus_TOPPV_YERR;
   Double_t        muminus_TOPPV_ZERR;
   Double_t        muminus_TOPPV_CHI2;
   Int_t           muminus_TOPPV_NDOF;
   Float_t         muminus_TOPPV_COV_[3][3];
   Double_t        muminus_IP_TOPPV;
   Double_t        muminus_IPCHI2_TOPPV;
   Double_t        muminus_ORIVX_X;
   Double_t        muminus_ORIVX_Y;
   Double_t        muminus_ORIVX_Z;
   Double_t        muminus_ORIVX_XERR;
   Double_t        muminus_ORIVX_YERR;
   Double_t        muminus_ORIVX_ZERR;
   Double_t        muminus_ORIVX_CHI2;
   Int_t           muminus_ORIVX_NDOF;
   Float_t         muminus_ORIVX_COV_[3][3];
   Double_t        muminus_IP_ORIVX;
   Double_t        muminus_IPCHI2_ORIVX;
   Double_t        muminus_P;
   Double_t        muminus_PT;
   Double_t        muminus_PE;
   Double_t        muminus_PX;
   Double_t        muminus_PY;
   Double_t        muminus_PZ;
   Double_t        muminus_M;
   Int_t           muminus_ID;
   Double_t        muminus_PIDe;
   Double_t        muminus_PIDmu;
   Double_t        muminus_PIDK;
   Double_t        muminus_PIDp;
   Double_t        muminus_ProbNNe;
   Double_t        muminus_ProbNNk;
   Double_t        muminus_ProbNNp;
   Double_t        muminus_ProbNNpi;
   Double_t        muminus_ProbNNmu;
   Double_t        muminus_ProbNNghost;
   Bool_t          muminus_hasMuon;
   Bool_t          muminus_isMuon;
   Bool_t          muminus_hasRich;
   Bool_t          muminus_hasCalo;
   Int_t           muminus_TRACK_Type;
   Int_t           muminus_TRACK_Key;
   Double_t        muminus_TRACK_CHI2NDOF;
   Double_t        muminus_TRACK_PCHI2;
   Double_t        muminus_TRACK_MatchCHI2;
   Double_t        muminus_TRACK_GhostProb;
   Double_t        muminus_TRACK_CloneDist;
   Double_t        muminus_TRACK_Likelihood;
   Double_t        muplus_MINIP;
   Double_t        muplus_MINIPCHI2;
   Double_t        muplus_MINIPNEXTBEST;
   Double_t        muplus_MINIPCHI2NEXTBEST;
   Double_t        muplus_OWNPV_X;
   Double_t        muplus_OWNPV_Y;
   Double_t        muplus_OWNPV_Z;
   Double_t        muplus_OWNPV_XERR;
   Double_t        muplus_OWNPV_YERR;
   Double_t        muplus_OWNPV_ZERR;
   Double_t        muplus_OWNPV_CHI2;
   Int_t           muplus_OWNPV_NDOF;
   Float_t         muplus_OWNPV_COV_[3][3];
   Double_t        muplus_IP_OWNPV;
   Double_t        muplus_IPCHI2_OWNPV;
   Double_t        muplus_TOPPV_X;
   Double_t        muplus_TOPPV_Y;
   Double_t        muplus_TOPPV_Z;
   Double_t        muplus_TOPPV_XERR;
   Double_t        muplus_TOPPV_YERR;
   Double_t        muplus_TOPPV_ZERR;
   Double_t        muplus_TOPPV_CHI2;
   Int_t           muplus_TOPPV_NDOF;
   Float_t         muplus_TOPPV_COV_[3][3];
   Double_t        muplus_IP_TOPPV;
   Double_t        muplus_IPCHI2_TOPPV;
   Double_t        muplus_ORIVX_X;
   Double_t        muplus_ORIVX_Y;
   Double_t        muplus_ORIVX_Z;
   Double_t        muplus_ORIVX_XERR;
   Double_t        muplus_ORIVX_YERR;
   Double_t        muplus_ORIVX_ZERR;
   Double_t        muplus_ORIVX_CHI2;
   Int_t           muplus_ORIVX_NDOF;
   Float_t         muplus_ORIVX_COV_[3][3];
   Double_t        muplus_IP_ORIVX;
   Double_t        muplus_IPCHI2_ORIVX;
   Double_t        muplus_P;
   Double_t        muplus_PT;
   Double_t        muplus_PE;
   Double_t        muplus_PX;
   Double_t        muplus_PY;
   Double_t        muplus_PZ;
   Double_t        muplus_M;
   Int_t           muplus_ID;
   Double_t        muplus_PIDe;
   Double_t        muplus_PIDmu;
   Double_t        muplus_PIDK;
   Double_t        muplus_PIDp;
   Double_t        muplus_ProbNNe;
   Double_t        muplus_ProbNNk;
   Double_t        muplus_ProbNNp;
   Double_t        muplus_ProbNNpi;
   Double_t        muplus_ProbNNmu;
   Double_t        muplus_ProbNNghost;
   Bool_t          muplus_hasMuon;
   Bool_t          muplus_isMuon;
   Bool_t          muplus_hasRich;
   Bool_t          muplus_hasCalo;
   Int_t           muplus_TRACK_Type;
   Int_t           muplus_TRACK_Key;
   Double_t        muplus_TRACK_CHI2NDOF;
   Double_t        muplus_TRACK_PCHI2;
   Double_t        muplus_TRACK_MatchCHI2;
   Double_t        muplus_TRACK_GhostProb;
   Double_t        muplus_TRACK_CloneDist;
   Double_t        muplus_TRACK_Likelihood;
   UInt_t          nCandidate;
   ULong64_t       totCandidates;
   ULong64_t       EventInSequence;
   Double_t        nLong;
   Double_t        nTracks;
   UInt_t          runNumber;
   ULong64_t       eventNumber;
   UInt_t          BCID;
   Int_t           BCType;
   UInt_t          OdinTCK;
   UInt_t          L0DUTCK;
   UInt_t          HLTTCK;
   ULong64_t       GpsTime;
   UInt_t          Primaries;
   Short_t         Polarity;

   // List of branches
   TBranch        *b_Bs_MINIP;   //!
   TBranch        *b_Bs_MINIPCHI2;   //!
   TBranch        *b_Bs_MINIPNEXTBEST;   //!
   TBranch        *b_Bs_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_Bs_ENDVERTEX_X;   //!
   TBranch        *b_Bs_ENDVERTEX_Y;   //!
   TBranch        *b_Bs_ENDVERTEX_Z;   //!
   TBranch        *b_Bs_ENDVERTEX_XERR;   //!
   TBranch        *b_Bs_ENDVERTEX_YERR;   //!
   TBranch        *b_Bs_ENDVERTEX_ZERR;   //!
   TBranch        *b_Bs_ENDVERTEX_CHI2;   //!
   TBranch        *b_Bs_ENDVERTEX_NDOF;   //!
   TBranch        *b_Bs_ENDVERTEX_COV_;   //!
   TBranch        *b_Bs_OWNPV_X;   //!
   TBranch        *b_Bs_OWNPV_Y;   //!
   TBranch        *b_Bs_OWNPV_Z;   //!
   TBranch        *b_Bs_OWNPV_XERR;   //!
   TBranch        *b_Bs_OWNPV_YERR;   //!
   TBranch        *b_Bs_OWNPV_ZERR;   //!
   TBranch        *b_Bs_OWNPV_CHI2;   //!
   TBranch        *b_Bs_OWNPV_NDOF;   //!
   TBranch        *b_Bs_OWNPV_COV_;   //!
   TBranch        *b_Bs_IP_OWNPV;   //!
   TBranch        *b_Bs_IPCHI2_OWNPV;   //!
   TBranch        *b_Bs_FD_OWNPV;   //!
   TBranch        *b_Bs_FDCHI2_OWNPV;   //!
   TBranch        *b_Bs_DIRA_OWNPV;   //!
   TBranch        *b_Bs_TOPPV_X;   //!
   TBranch        *b_Bs_TOPPV_Y;   //!
   TBranch        *b_Bs_TOPPV_Z;   //!
   TBranch        *b_Bs_TOPPV_XERR;   //!
   TBranch        *b_Bs_TOPPV_YERR;   //!
   TBranch        *b_Bs_TOPPV_ZERR;   //!
   TBranch        *b_Bs_TOPPV_CHI2;   //!
   TBranch        *b_Bs_TOPPV_NDOF;   //!
   TBranch        *b_Bs_TOPPV_COV_;   //!
   TBranch        *b_Bs_IP_TOPPV;   //!
   TBranch        *b_Bs_IPCHI2_TOPPV;   //!
   TBranch        *b_Bs_FD_TOPPV;   //!
   TBranch        *b_Bs_FDCHI2_TOPPV;   //!
   TBranch        *b_Bs_DIRA_TOPPV;   //!
   TBranch        *b_Bs_P;   //!
   TBranch        *b_Bs_PT;   //!
   TBranch        *b_Bs_PE;   //!
   TBranch        *b_Bs_PX;   //!
   TBranch        *b_Bs_PY;   //!
   TBranch        *b_Bs_PZ;   //!
   TBranch        *b_Bs_MM;   //!
   TBranch        *b_Bs_MMERR;   //!
   TBranch        *b_Bs_M;   //!
   TBranch        *b_Bs_ID;   //!
   TBranch        *b_Bs_LOKI_DTF_CHI2NDOF;   //!
   TBranch        *b_Bs_LOKI_DTF_CTAU;   //!
   TBranch        *b_Bs_LOKI_DTF_CTAUERR;   //!
   TBranch        *b_Bs_LOKI_DTF_VCHI2NDOF;   //!
   TBranch        *b_Bs_LOKI_MASS_JpsiConstr;   //!
   TBranch        *b_Bs_TAU;   //!
   TBranch        *b_Bs_TAUERR;   //!
   TBranch        *b_Bs_TAUCHI2;   //!
   TBranch        *b_BsL0Global_Dec;   //!
   TBranch        *b_BsL0Global_TIS;   //!
   TBranch        *b_BsL0Global_TOS;   //!
   TBranch        *b_BsHlt1Global_Dec;   //!
   TBranch        *b_BsHlt1Global_TIS;   //!
   TBranch        *b_BsHlt1Global_TOS;   //!
   TBranch        *b_BsHlt1Phys_Dec;   //!
   TBranch        *b_BsHlt1Phys_TIS;   //!
   TBranch        *b_BsHlt1Phys_TOS;   //!
   TBranch        *b_BsHlt2Global_Dec;   //!
   TBranch        *b_BsHlt2Global_TIS;   //!
   TBranch        *b_BsHlt2Global_TOS;   //!
   TBranch        *b_BsHlt2Phys_Dec;   //!
   TBranch        *b_BsHlt2Phys_TIS;   //!
   TBranch        *b_BsHlt2Phys_TOS;   //!
   TBranch        *b_BsStrippingGlobal_Dec;   //!
   TBranch        *b_BsStrippingGlobal_TIS;   //!
   TBranch        *b_BsStrippingGlobal_TOS;   //!
   TBranch        *b_BsL0DiMuonDecision_Dec;   //!
   TBranch        *b_BsL0DiMuonDecision_TIS;   //!
   TBranch        *b_BsL0DiMuonDecision_TOS;   //!
   TBranch        *b_BsL0HCALDecision_Dec;   //!
   TBranch        *b_BsL0HCALDecision_TIS;   //!
   TBranch        *b_BsL0HCALDecision_TOS;   //!
   TBranch        *b_BsL0MuonDecision_Dec;   //!
   TBranch        *b_BsL0MuonDecision_TIS;   //!
   TBranch        *b_BsL0MuonDecision_TOS;   //!
   TBranch        *b_BsL0MuonHighDecision_Dec;   //!
   TBranch        *b_BsL0MuonHighDecision_TIS;   //!
   TBranch        *b_BsL0MuonHighDecision_TOS;   //!
   TBranch        *b_BsHlt1SingleMuonNoIPL0Decision_Dec;   //!
   TBranch        *b_BsHlt1SingleMuonNoIPL0Decision_TIS;   //!
   TBranch        *b_BsHlt1SingleMuonNoIPL0Decision_TOS;   //!
   TBranch        *b_BsHlt1DiMuonHighMassDecision_Dec;   //!
   TBranch        *b_BsHlt1DiMuonHighMassDecision_TIS;   //!
   TBranch        *b_BsHlt1DiMuonHighMassDecision_TOS;   //!
   TBranch        *b_BsHlt1DiMuonLowMassDecision_Dec;   //!
   TBranch        *b_BsHlt1DiMuonLowMassDecision_TIS;   //!
   TBranch        *b_BsHlt1DiMuonLowMassDecision_TOS;   //!
   TBranch        *b_BsHlt1SingleMuonHighPTDecision_Dec;   //!
   TBranch        *b_BsHlt1SingleMuonHighPTDecision_TIS;   //!
   TBranch        *b_BsHlt1SingleMuonHighPTDecision_TOS;   //!
   TBranch        *b_BsHlt1SingleMuonNoIPDecision_Dec;   //!
   TBranch        *b_BsHlt1SingleMuonNoIPDecision_TIS;   //!
   TBranch        *b_BsHlt1SingleMuonNoIPDecision_TOS;   //!
   TBranch        *b_BsHlt1TrackAllL0Decision_Dec;   //!
   TBranch        *b_BsHlt1TrackAllL0Decision_TIS;   //!
   TBranch        *b_BsHlt1TrackAllL0Decision_TOS;   //!
   TBranch        *b_BsHlt1TrackMuonDecision_Dec;   //!
   TBranch        *b_BsHlt1TrackMuonDecision_TIS;   //!
   TBranch        *b_BsHlt1TrackMuonDecision_TOS;   //!
   TBranch        *b_BsHlt2DiMuonBDecision_Dec;   //!
   TBranch        *b_BsHlt2DiMuonBDecision_TIS;   //!
   TBranch        *b_BsHlt2DiMuonBDecision_TOS;   //!
   TBranch        *b_BsHlt2DiMuonDecision_Dec;   //!
   TBranch        *b_BsHlt2DiMuonDecision_TIS;   //!
   TBranch        *b_BsHlt2DiMuonDecision_TOS;   //!
   TBranch        *b_BsHlt2DiMuonDY1Decision_Dec;   //!
   TBranch        *b_BsHlt2DiMuonDY1Decision_TIS;   //!
   TBranch        *b_BsHlt2DiMuonDY1Decision_TOS;   //!
   TBranch        *b_BsHlt2DiMuonDetachedDecision_Dec;   //!
   TBranch        *b_BsHlt2DiMuonDetachedDecision_TIS;   //!
   TBranch        *b_BsHlt2DiMuonDetachedDecision_TOS;   //!
   TBranch        *b_BsHlt2DiMuonDetachedHeavyDecision_Dec;   //!
   TBranch        *b_BsHlt2DiMuonDetachedHeavyDecision_TIS;   //!
   TBranch        *b_BsHlt2DiMuonDetachedHeavyDecision_TOS;   //!
   TBranch        *b_BsHlt2DiMuonDetachedJPsiDecision_Dec;   //!
   TBranch        *b_BsHlt2DiMuonDetachedJPsiDecision_TIS;   //!
   TBranch        *b_BsHlt2DiMuonDetachedJPsiDecision_TOS;   //!
   TBranch        *b_BsHlt2DiMuonJPsiDecision_Dec;   //!
   TBranch        *b_BsHlt2DiMuonJPsiDecision_TIS;   //!
   TBranch        *b_BsHlt2DiMuonJPsiDecision_TOS;   //!
   TBranch        *b_BsHlt2DiMuonJPsiHighPTDecision_Dec;   //!
   TBranch        *b_BsHlt2DiMuonJPsiHighPTDecision_TIS;   //!
   TBranch        *b_BsHlt2DiMuonJPsiHighPTDecision_TOS;   //!
   TBranch        *b_BsHlt2ExpressJPsiDecision_Dec;   //!
   TBranch        *b_BsHlt2ExpressJPsiDecision_TIS;   //!
   TBranch        *b_BsHlt2ExpressJPsiDecision_TOS;   //!
   TBranch        *b_BsHlt2ExpressJPsiTagProbeDecision_Dec;   //!
   TBranch        *b_BsHlt2ExpressJPsiTagProbeDecision_TIS;   //!
   TBranch        *b_BsHlt2ExpressJPsiTagProbeDecision_TOS;   //!
   TBranch        *b_BsHlt2SingleMuonDecision_Dec;   //!
   TBranch        *b_BsHlt2SingleMuonDecision_TIS;   //!
   TBranch        *b_BsHlt2SingleMuonDecision_TOS;   //!
   TBranch        *b_BsHlt2SingleMuonHighPTDecision_Dec;   //!
   TBranch        *b_BsHlt2SingleMuonHighPTDecision_TIS;   //!
   TBranch        *b_BsHlt2SingleMuonHighPTDecision_TOS;   //!
   TBranch        *b_BsHlt2SingleMuonLowPTDecision_Dec;   //!
   TBranch        *b_BsHlt2SingleMuonLowPTDecision_TIS;   //!
   TBranch        *b_BsHlt2SingleMuonLowPTDecision_TOS;   //!
   TBranch        *b_BsHlt2Topo2BodyBBDTDecision_Dec;   //!
   TBranch        *b_BsHlt2Topo2BodyBBDTDecision_TIS;   //!
   TBranch        *b_BsHlt2Topo2BodyBBDTDecision_TOS;   //!
   TBranch        *b_BsHlt2Topo2BodySimpleDecision_Dec;   //!
   TBranch        *b_BsHlt2Topo2BodySimpleDecision_TIS;   //!
   TBranch        *b_BsHlt2Topo2BodySimpleDecision_TOS;   //!
   TBranch        *b_BsHlt2Topo3BodyBBDTDecision_Dec;   //!
   TBranch        *b_BsHlt2Topo3BodyBBDTDecision_TIS;   //!
   TBranch        *b_BsHlt2Topo3BodyBBDTDecision_TOS;   //!
   TBranch        *b_BsHlt2Topo3BodySimpleDecision_Dec;   //!
   TBranch        *b_BsHlt2Topo3BodySimpleDecision_TIS;   //!
   TBranch        *b_BsHlt2Topo3BodySimpleDecision_TOS;   //!
   TBranch        *b_BsHlt2Topo4BodyBBDTDecision_Dec;   //!
   TBranch        *b_BsHlt2Topo4BodyBBDTDecision_TIS;   //!
   TBranch        *b_BsHlt2Topo4BodyBBDTDecision_TOS;   //!
   TBranch        *b_BsHlt2Topo4BodySimpleDecision_Dec;   //!
   TBranch        *b_BsHlt2Topo4BodySimpleDecision_TIS;   //!
   TBranch        *b_BsHlt2Topo4BodySimpleDecision_TOS;   //!
   TBranch        *b_BsHlt2TopoMu2BodyBBDTDecision_Dec;   //!
   TBranch        *b_BsHlt2TopoMu2BodyBBDTDecision_TIS;   //!
   TBranch        *b_BsHlt2TopoMu2BodyBBDTDecision_TOS;   //!
   TBranch        *b_BsHlt2TopoMu3BodyBBDTDecision_Dec;   //!
   TBranch        *b_BsHlt2TopoMu3BodyBBDTDecision_TIS;   //!
   TBranch        *b_BsHlt2TopoMu3BodyBBDTDecision_TOS;   //!
   TBranch        *b_BsHlt2TopoMu4BodyBBDTDecision_Dec;   //!
   TBranch        *b_BsHlt2TopoMu4BodyBBDTDecision_TIS;   //!
   TBranch        *b_BsHlt2TopoMu4BodyBBDTDecision_TOS;   //!
   TBranch        *b_BsHlt2TransparentDecision_Dec;   //!
   TBranch        *b_BsHlt2TransparentDecision_TIS;   //!
   TBranch        *b_BsHlt2TransparentDecision_TOS;   //!
   TBranch        *b_BsHlt2DiMuonUnbiasedJPsiDecision_Dec;   //!
   TBranch        *b_BsHlt2DiMuonUnbiasedJPsiDecision_TIS;   //!
   TBranch        *b_BsHlt2DiMuonUnbiasedJPsiDecision_TOS;   //!
   TBranch        *b_R_MINIP;   //!
   TBranch        *b_R_MINIPCHI2;   //!
   TBranch        *b_R_MINIPNEXTBEST;   //!
   TBranch        *b_R_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_R_ENDVERTEX_X;   //!
   TBranch        *b_R_ENDVERTEX_Y;   //!
   TBranch        *b_R_ENDVERTEX_Z;   //!
   TBranch        *b_R_ENDVERTEX_XERR;   //!
   TBranch        *b_R_ENDVERTEX_YERR;   //!
   TBranch        *b_R_ENDVERTEX_ZERR;   //!
   TBranch        *b_R_ENDVERTEX_CHI2;   //!
   TBranch        *b_R_ENDVERTEX_NDOF;   //!
   TBranch        *b_R_ENDVERTEX_COV_;   //!
   TBranch        *b_R_OWNPV_X;   //!
   TBranch        *b_R_OWNPV_Y;   //!
   TBranch        *b_R_OWNPV_Z;   //!
   TBranch        *b_R_OWNPV_XERR;   //!
   TBranch        *b_R_OWNPV_YERR;   //!
   TBranch        *b_R_OWNPV_ZERR;   //!
   TBranch        *b_R_OWNPV_CHI2;   //!
   TBranch        *b_R_OWNPV_NDOF;   //!
   TBranch        *b_R_OWNPV_COV_;   //!
   TBranch        *b_R_IP_OWNPV;   //!
   TBranch        *b_R_IPCHI2_OWNPV;   //!
   TBranch        *b_R_FD_OWNPV;   //!
   TBranch        *b_R_FDCHI2_OWNPV;   //!
   TBranch        *b_R_DIRA_OWNPV;   //!
   TBranch        *b_R_TOPPV_X;   //!
   TBranch        *b_R_TOPPV_Y;   //!
   TBranch        *b_R_TOPPV_Z;   //!
   TBranch        *b_R_TOPPV_XERR;   //!
   TBranch        *b_R_TOPPV_YERR;   //!
   TBranch        *b_R_TOPPV_ZERR;   //!
   TBranch        *b_R_TOPPV_CHI2;   //!
   TBranch        *b_R_TOPPV_NDOF;   //!
   TBranch        *b_R_TOPPV_COV_;   //!
   TBranch        *b_R_IP_TOPPV;   //!
   TBranch        *b_R_IPCHI2_TOPPV;   //!
   TBranch        *b_R_FD_TOPPV;   //!
   TBranch        *b_R_FDCHI2_TOPPV;   //!
   TBranch        *b_R_DIRA_TOPPV;   //!
   TBranch        *b_R_ORIVX_X;   //!
   TBranch        *b_R_ORIVX_Y;   //!
   TBranch        *b_R_ORIVX_Z;   //!
   TBranch        *b_R_ORIVX_XERR;   //!
   TBranch        *b_R_ORIVX_YERR;   //!
   TBranch        *b_R_ORIVX_ZERR;   //!
   TBranch        *b_R_ORIVX_CHI2;   //!
   TBranch        *b_R_ORIVX_NDOF;   //!
   TBranch        *b_R_ORIVX_COV_;   //!
   TBranch        *b_R_IP_ORIVX;   //!
   TBranch        *b_R_IPCHI2_ORIVX;   //!
   TBranch        *b_R_FD_ORIVX;   //!
   TBranch        *b_R_FDCHI2_ORIVX;   //!
   TBranch        *b_R_DIRA_ORIVX;   //!
   TBranch        *b_R_P;   //!
   TBranch        *b_R_PT;   //!
   TBranch        *b_R_PE;   //!
   TBranch        *b_R_PX;   //!
   TBranch        *b_R_PY;   //!
   TBranch        *b_R_PZ;   //!
   TBranch        *b_R_MM;   //!
   TBranch        *b_R_MMERR;   //!
   TBranch        *b_R_M;   //!
   TBranch        *b_R_ID;   //!
   TBranch        *b_H2_MINIP;   //!
   TBranch        *b_H2_MINIPCHI2;   //!
   TBranch        *b_H2_MINIPNEXTBEST;   //!
   TBranch        *b_H2_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_H2_OWNPV_X;   //!
   TBranch        *b_H2_OWNPV_Y;   //!
   TBranch        *b_H2_OWNPV_Z;   //!
   TBranch        *b_H2_OWNPV_XERR;   //!
   TBranch        *b_H2_OWNPV_YERR;   //!
   TBranch        *b_H2_OWNPV_ZERR;   //!
   TBranch        *b_H2_OWNPV_CHI2;   //!
   TBranch        *b_H2_OWNPV_NDOF;   //!
   TBranch        *b_H2_OWNPV_COV_;   //!
   TBranch        *b_H2_IP_OWNPV;   //!
   TBranch        *b_H2_IPCHI2_OWNPV;   //!
   TBranch        *b_H2_TOPPV_X;   //!
   TBranch        *b_H2_TOPPV_Y;   //!
   TBranch        *b_H2_TOPPV_Z;   //!
   TBranch        *b_H2_TOPPV_XERR;   //!
   TBranch        *b_H2_TOPPV_YERR;   //!
   TBranch        *b_H2_TOPPV_ZERR;   //!
   TBranch        *b_H2_TOPPV_CHI2;   //!
   TBranch        *b_H2_TOPPV_NDOF;   //!
   TBranch        *b_H2_TOPPV_COV_;   //!
   TBranch        *b_H2_IP_TOPPV;   //!
   TBranch        *b_H2_IPCHI2_TOPPV;   //!
   TBranch        *b_H2_ORIVX_X;   //!
   TBranch        *b_H2_ORIVX_Y;   //!
   TBranch        *b_H2_ORIVX_Z;   //!
   TBranch        *b_H2_ORIVX_XERR;   //!
   TBranch        *b_H2_ORIVX_YERR;   //!
   TBranch        *b_H2_ORIVX_ZERR;   //!
   TBranch        *b_H2_ORIVX_CHI2;   //!
   TBranch        *b_H2_ORIVX_NDOF;   //!
   TBranch        *b_H2_ORIVX_COV_;   //!
   TBranch        *b_H2_IP_ORIVX;   //!
   TBranch        *b_H2_IPCHI2_ORIVX;   //!
   TBranch        *b_H2_P;   //!
   TBranch        *b_H2_PT;   //!
   TBranch        *b_H2_PE;   //!
   TBranch        *b_H2_PX;   //!
   TBranch        *b_H2_PY;   //!
   TBranch        *b_H2_PZ;   //!
   TBranch        *b_H2_M;   //!
   TBranch        *b_H2_ID;   //!
   TBranch        *b_H2_PIDe;   //!
   TBranch        *b_H2_PIDmu;   //!
   TBranch        *b_H2_PIDK;   //!
   TBranch        *b_H2_PIDp;   //!
   TBranch        *b_H2_ProbNNe;   //!
   TBranch        *b_H2_ProbNNk;   //!
   TBranch        *b_H2_ProbNNp;   //!
   TBranch        *b_H2_ProbNNpi;   //!
   TBranch        *b_H2_ProbNNmu;   //!
   TBranch        *b_H2_ProbNNghost;   //!
   TBranch        *b_H2_hasMuon;   //!
   TBranch        *b_H2_isMuon;   //!
   TBranch        *b_H2_hasRich;   //!
   TBranch        *b_H2_hasCalo;   //!
   TBranch        *b_H2_TRACK_Type;   //!
   TBranch        *b_H2_TRACK_Key;   //!
   TBranch        *b_H2_TRACK_CHI2NDOF;   //!
   TBranch        *b_H2_TRACK_PCHI2;   //!
   TBranch        *b_H2_TRACK_MatchCHI2;   //!
   TBranch        *b_H2_TRACK_GhostProb;   //!
   TBranch        *b_H2_TRACK_CloneDist;   //!
   TBranch        *b_H2_TRACK_Likelihood;   //!
   TBranch        *b_H1_MINIP;   //!
   TBranch        *b_H1_MINIPCHI2;   //!
   TBranch        *b_H1_MINIPNEXTBEST;   //!
   TBranch        *b_H1_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_H1_OWNPV_X;   //!
   TBranch        *b_H1_OWNPV_Y;   //!
   TBranch        *b_H1_OWNPV_Z;   //!
   TBranch        *b_H1_OWNPV_XERR;   //!
   TBranch        *b_H1_OWNPV_YERR;   //!
   TBranch        *b_H1_OWNPV_ZERR;   //!
   TBranch        *b_H1_OWNPV_CHI2;   //!
   TBranch        *b_H1_OWNPV_NDOF;   //!
   TBranch        *b_H1_OWNPV_COV_;   //!
   TBranch        *b_H1_IP_OWNPV;   //!
   TBranch        *b_H1_IPCHI2_OWNPV;   //!
   TBranch        *b_H1_TOPPV_X;   //!
   TBranch        *b_H1_TOPPV_Y;   //!
   TBranch        *b_H1_TOPPV_Z;   //!
   TBranch        *b_H1_TOPPV_XERR;   //!
   TBranch        *b_H1_TOPPV_YERR;   //!
   TBranch        *b_H1_TOPPV_ZERR;   //!
   TBranch        *b_H1_TOPPV_CHI2;   //!
   TBranch        *b_H1_TOPPV_NDOF;   //!
   TBranch        *b_H1_TOPPV_COV_;   //!
   TBranch        *b_H1_IP_TOPPV;   //!
   TBranch        *b_H1_IPCHI2_TOPPV;   //!
   TBranch        *b_H1_ORIVX_X;   //!
   TBranch        *b_H1_ORIVX_Y;   //!
   TBranch        *b_H1_ORIVX_Z;   //!
   TBranch        *b_H1_ORIVX_XERR;   //!
   TBranch        *b_H1_ORIVX_YERR;   //!
   TBranch        *b_H1_ORIVX_ZERR;   //!
   TBranch        *b_H1_ORIVX_CHI2;   //!
   TBranch        *b_H1_ORIVX_NDOF;   //!
   TBranch        *b_H1_ORIVX_COV_;   //!
   TBranch        *b_H1_IP_ORIVX;   //!
   TBranch        *b_H1_IPCHI2_ORIVX;   //!
   TBranch        *b_H1_P;   //!
   TBranch        *b_H1_PT;   //!
   TBranch        *b_H1_PE;   //!
   TBranch        *b_H1_PX;   //!
   TBranch        *b_H1_PY;   //!
   TBranch        *b_H1_PZ;   //!
   TBranch        *b_H1_M;   //!
   TBranch        *b_H1_ID;   //!
   TBranch        *b_H1_PIDe;   //!
   TBranch        *b_H1_PIDmu;   //!
   TBranch        *b_H1_PIDK;   //!
   TBranch        *b_H1_PIDp;   //!
   TBranch        *b_H1_ProbNNe;   //!
   TBranch        *b_H1_ProbNNk;   //!
   TBranch        *b_H1_ProbNNp;   //!
   TBranch        *b_H1_ProbNNpi;   //!
   TBranch        *b_H1_ProbNNmu;   //!
   TBranch        *b_H1_ProbNNghost;   //!
   TBranch        *b_H1_hasMuon;   //!
   TBranch        *b_H1_isMuon;   //!
   TBranch        *b_H1_hasRich;   //!
   TBranch        *b_H1_hasCalo;   //!
   TBranch        *b_H1_TRACK_Type;   //!
   TBranch        *b_H1_TRACK_Key;   //!
   TBranch        *b_H1_TRACK_CHI2NDOF;   //!
   TBranch        *b_H1_TRACK_PCHI2;   //!
   TBranch        *b_H1_TRACK_MatchCHI2;   //!
   TBranch        *b_H1_TRACK_GhostProb;   //!
   TBranch        *b_H1_TRACK_CloneDist;   //!
   TBranch        *b_H1_TRACK_Likelihood;   //!
   TBranch        *b_J_psi_1S_MINIP;   //!
   TBranch        *b_J_psi_1S_MINIPCHI2;   //!
   TBranch        *b_J_psi_1S_MINIPNEXTBEST;   //!
   TBranch        *b_J_psi_1S_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_J_psi_1S_ENDVERTEX_X;   //!
   TBranch        *b_J_psi_1S_ENDVERTEX_Y;   //!
   TBranch        *b_J_psi_1S_ENDVERTEX_Z;   //!
   TBranch        *b_J_psi_1S_ENDVERTEX_XERR;   //!
   TBranch        *b_J_psi_1S_ENDVERTEX_YERR;   //!
   TBranch        *b_J_psi_1S_ENDVERTEX_ZERR;   //!
   TBranch        *b_J_psi_1S_ENDVERTEX_CHI2;   //!
   TBranch        *b_J_psi_1S_ENDVERTEX_NDOF;   //!
   TBranch        *b_J_psi_1S_ENDVERTEX_COV_;   //!
   TBranch        *b_J_psi_1S_OWNPV_X;   //!
   TBranch        *b_J_psi_1S_OWNPV_Y;   //!
   TBranch        *b_J_psi_1S_OWNPV_Z;   //!
   TBranch        *b_J_psi_1S_OWNPV_XERR;   //!
   TBranch        *b_J_psi_1S_OWNPV_YERR;   //!
   TBranch        *b_J_psi_1S_OWNPV_ZERR;   //!
   TBranch        *b_J_psi_1S_OWNPV_CHI2;   //!
   TBranch        *b_J_psi_1S_OWNPV_NDOF;   //!
   TBranch        *b_J_psi_1S_OWNPV_COV_;   //!
   TBranch        *b_J_psi_1S_IP_OWNPV;   //!
   TBranch        *b_J_psi_1S_IPCHI2_OWNPV;   //!
   TBranch        *b_J_psi_1S_FD_OWNPV;   //!
   TBranch        *b_J_psi_1S_FDCHI2_OWNPV;   //!
   TBranch        *b_J_psi_1S_DIRA_OWNPV;   //!
   TBranch        *b_J_psi_1S_TOPPV_X;   //!
   TBranch        *b_J_psi_1S_TOPPV_Y;   //!
   TBranch        *b_J_psi_1S_TOPPV_Z;   //!
   TBranch        *b_J_psi_1S_TOPPV_XERR;   //!
   TBranch        *b_J_psi_1S_TOPPV_YERR;   //!
   TBranch        *b_J_psi_1S_TOPPV_ZERR;   //!
   TBranch        *b_J_psi_1S_TOPPV_CHI2;   //!
   TBranch        *b_J_psi_1S_TOPPV_NDOF;   //!
   TBranch        *b_J_psi_1S_TOPPV_COV_;   //!
   TBranch        *b_J_psi_1S_IP_TOPPV;   //!
   TBranch        *b_J_psi_1S_IPCHI2_TOPPV;   //!
   TBranch        *b_J_psi_1S_FD_TOPPV;   //!
   TBranch        *b_J_psi_1S_FDCHI2_TOPPV;   //!
   TBranch        *b_J_psi_1S_DIRA_TOPPV;   //!
   TBranch        *b_J_psi_1S_ORIVX_X;   //!
   TBranch        *b_J_psi_1S_ORIVX_Y;   //!
   TBranch        *b_J_psi_1S_ORIVX_Z;   //!
   TBranch        *b_J_psi_1S_ORIVX_XERR;   //!
   TBranch        *b_J_psi_1S_ORIVX_YERR;   //!
   TBranch        *b_J_psi_1S_ORIVX_ZERR;   //!
   TBranch        *b_J_psi_1S_ORIVX_CHI2;   //!
   TBranch        *b_J_psi_1S_ORIVX_NDOF;   //!
   TBranch        *b_J_psi_1S_ORIVX_COV_;   //!
   TBranch        *b_J_psi_1S_IP_ORIVX;   //!
   TBranch        *b_J_psi_1S_IPCHI2_ORIVX;   //!
   TBranch        *b_J_psi_1S_FD_ORIVX;   //!
   TBranch        *b_J_psi_1S_FDCHI2_ORIVX;   //!
   TBranch        *b_J_psi_1S_DIRA_ORIVX;   //!
   TBranch        *b_J_psi_1S_P;   //!
   TBranch        *b_J_psi_1S_PT;   //!
   TBranch        *b_J_psi_1S_PE;   //!
   TBranch        *b_J_psi_1S_PX;   //!
   TBranch        *b_J_psi_1S_PY;   //!
   TBranch        *b_J_psi_1S_PZ;   //!
   TBranch        *b_J_psi_1S_MM;   //!
   TBranch        *b_J_psi_1S_MMERR;   //!
   TBranch        *b_J_psi_1S_M;   //!
   TBranch        *b_J_psi_1S_ID;   //!
   TBranch        *b_J_psi_1SL0Global_Dec;   //!
   TBranch        *b_J_psi_1SL0Global_TIS;   //!
   TBranch        *b_J_psi_1SL0Global_TOS;   //!
   TBranch        *b_J_psi_1SHlt1Global_Dec;   //!
   TBranch        *b_J_psi_1SHlt1Global_TIS;   //!
   TBranch        *b_J_psi_1SHlt1Global_TOS;   //!
   TBranch        *b_J_psi_1SHlt1Phys_Dec;   //!
   TBranch        *b_J_psi_1SHlt1Phys_TIS;   //!
   TBranch        *b_J_psi_1SHlt1Phys_TOS;   //!
   TBranch        *b_J_psi_1SHlt2Global_Dec;   //!
   TBranch        *b_J_psi_1SHlt2Global_TIS;   //!
   TBranch        *b_J_psi_1SHlt2Global_TOS;   //!
   TBranch        *b_J_psi_1SHlt2Phys_Dec;   //!
   TBranch        *b_J_psi_1SHlt2Phys_TIS;   //!
   TBranch        *b_J_psi_1SHlt2Phys_TOS;   //!
   TBranch        *b_J_psi_1SStrippingGlobal_Dec;   //!
   TBranch        *b_J_psi_1SStrippingGlobal_TIS;   //!
   TBranch        *b_J_psi_1SStrippingGlobal_TOS;   //!
   TBranch        *b_J_psi_1SL0DiMuonDecision_Dec;   //!
   TBranch        *b_J_psi_1SL0DiMuonDecision_TIS;   //!
   TBranch        *b_J_psi_1SL0DiMuonDecision_TOS;   //!
   TBranch        *b_J_psi_1SL0HCALDecision_Dec;   //!
   TBranch        *b_J_psi_1SL0HCALDecision_TIS;   //!
   TBranch        *b_J_psi_1SL0HCALDecision_TOS;   //!
   TBranch        *b_J_psi_1SL0MuonDecision_Dec;   //!
   TBranch        *b_J_psi_1SL0MuonDecision_TIS;   //!
   TBranch        *b_J_psi_1SL0MuonDecision_TOS;   //!
   TBranch        *b_J_psi_1SL0MuonHighDecision_Dec;   //!
   TBranch        *b_J_psi_1SL0MuonHighDecision_TIS;   //!
   TBranch        *b_J_psi_1SL0MuonHighDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt1SingleMuonNoIPL0Decision_Dec;   //!
   TBranch        *b_J_psi_1SHlt1SingleMuonNoIPL0Decision_TIS;   //!
   TBranch        *b_J_psi_1SHlt1SingleMuonNoIPL0Decision_TOS;   //!
   TBranch        *b_J_psi_1SHlt1DiMuonHighMassDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt1DiMuonHighMassDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt1DiMuonHighMassDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt1DiMuonLowMassDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt1DiMuonLowMassDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt1DiMuonLowMassDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt1SingleMuonHighPTDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt1SingleMuonHighPTDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt1SingleMuonHighPTDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt1SingleMuonNoIPDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt1SingleMuonNoIPDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt1SingleMuonNoIPDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt1TrackAllL0Decision_Dec;   //!
   TBranch        *b_J_psi_1SHlt1TrackAllL0Decision_TIS;   //!
   TBranch        *b_J_psi_1SHlt1TrackAllL0Decision_TOS;   //!
   TBranch        *b_J_psi_1SHlt1TrackMuonDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt1TrackMuonDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt1TrackMuonDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonBDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonBDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonBDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDY1Decision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDY1Decision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDY1Decision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDetachedDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDetachedDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDetachedDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDetachedHeavyDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDetachedHeavyDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDetachedHeavyDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDetachedJPsiDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDetachedJPsiDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonDetachedJPsiDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonJPsiDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonJPsiDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonJPsiDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonJPsiHighPTDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonJPsiHighPTDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonJPsiHighPTDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2ExpressJPsiDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2ExpressJPsiDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2ExpressJPsiDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2ExpressJPsiTagProbeDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2ExpressJPsiTagProbeDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2ExpressJPsiTagProbeDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2SingleMuonDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2SingleMuonDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2SingleMuonDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2SingleMuonHighPTDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2SingleMuonHighPTDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2SingleMuonHighPTDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2SingleMuonLowPTDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2SingleMuonLowPTDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2SingleMuonLowPTDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2Topo2BodyBBDTDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2Topo2BodyBBDTDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2Topo2BodyBBDTDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2Topo2BodySimpleDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2Topo2BodySimpleDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2Topo2BodySimpleDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2Topo3BodyBBDTDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2Topo3BodyBBDTDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2Topo3BodyBBDTDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2Topo3BodySimpleDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2Topo3BodySimpleDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2Topo3BodySimpleDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2Topo4BodyBBDTDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2Topo4BodyBBDTDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2Topo4BodyBBDTDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2Topo4BodySimpleDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2Topo4BodySimpleDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2Topo4BodySimpleDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2TopoMu2BodyBBDTDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2TopoMu2BodyBBDTDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2TopoMu2BodyBBDTDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2TopoMu3BodyBBDTDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2TopoMu3BodyBBDTDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2TopoMu3BodyBBDTDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2TopoMu4BodyBBDTDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2TopoMu4BodyBBDTDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2TopoMu4BodyBBDTDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2TransparentDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2TransparentDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2TransparentDecision_TOS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_Dec;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_TIS;   //!
   TBranch        *b_J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_TOS;   //!
   TBranch        *b_muminus_MINIP;   //!
   TBranch        *b_muminus_MINIPCHI2;   //!
   TBranch        *b_muminus_MINIPNEXTBEST;   //!
   TBranch        *b_muminus_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_muminus_OWNPV_X;   //!
   TBranch        *b_muminus_OWNPV_Y;   //!
   TBranch        *b_muminus_OWNPV_Z;   //!
   TBranch        *b_muminus_OWNPV_XERR;   //!
   TBranch        *b_muminus_OWNPV_YERR;   //!
   TBranch        *b_muminus_OWNPV_ZERR;   //!
   TBranch        *b_muminus_OWNPV_CHI2;   //!
   TBranch        *b_muminus_OWNPV_NDOF;   //!
   TBranch        *b_muminus_OWNPV_COV_;   //!
   TBranch        *b_muminus_IP_OWNPV;   //!
   TBranch        *b_muminus_IPCHI2_OWNPV;   //!
   TBranch        *b_muminus_TOPPV_X;   //!
   TBranch        *b_muminus_TOPPV_Y;   //!
   TBranch        *b_muminus_TOPPV_Z;   //!
   TBranch        *b_muminus_TOPPV_XERR;   //!
   TBranch        *b_muminus_TOPPV_YERR;   //!
   TBranch        *b_muminus_TOPPV_ZERR;   //!
   TBranch        *b_muminus_TOPPV_CHI2;   //!
   TBranch        *b_muminus_TOPPV_NDOF;   //!
   TBranch        *b_muminus_TOPPV_COV_;   //!
   TBranch        *b_muminus_IP_TOPPV;   //!
   TBranch        *b_muminus_IPCHI2_TOPPV;   //!
   TBranch        *b_muminus_ORIVX_X;   //!
   TBranch        *b_muminus_ORIVX_Y;   //!
   TBranch        *b_muminus_ORIVX_Z;   //!
   TBranch        *b_muminus_ORIVX_XERR;   //!
   TBranch        *b_muminus_ORIVX_YERR;   //!
   TBranch        *b_muminus_ORIVX_ZERR;   //!
   TBranch        *b_muminus_ORIVX_CHI2;   //!
   TBranch        *b_muminus_ORIVX_NDOF;   //!
   TBranch        *b_muminus_ORIVX_COV_;   //!
   TBranch        *b_muminus_IP_ORIVX;   //!
   TBranch        *b_muminus_IPCHI2_ORIVX;   //!
   TBranch        *b_muminus_P;   //!
   TBranch        *b_muminus_PT;   //!
   TBranch        *b_muminus_PE;   //!
   TBranch        *b_muminus_PX;   //!
   TBranch        *b_muminus_PY;   //!
   TBranch        *b_muminus_PZ;   //!
   TBranch        *b_muminus_M;   //!
   TBranch        *b_muminus_ID;   //!
   TBranch        *b_muminus_PIDe;   //!
   TBranch        *b_muminus_PIDmu;   //!
   TBranch        *b_muminus_PIDK;   //!
   TBranch        *b_muminus_PIDp;   //!
   TBranch        *b_muminus_ProbNNe;   //!
   TBranch        *b_muminus_ProbNNk;   //!
   TBranch        *b_muminus_ProbNNp;   //!
   TBranch        *b_muminus_ProbNNpi;   //!
   TBranch        *b_muminus_ProbNNmu;   //!
   TBranch        *b_muminus_ProbNNghost;   //!
   TBranch        *b_muminus_hasMuon;   //!
   TBranch        *b_muminus_isMuon;   //!
   TBranch        *b_muminus_hasRich;   //!
   TBranch        *b_muminus_hasCalo;   //!
   TBranch        *b_muminus_TRACK_Type;   //!
   TBranch        *b_muminus_TRACK_Key;   //!
   TBranch        *b_muminus_TRACK_CHI2NDOF;   //!
   TBranch        *b_muminus_TRACK_PCHI2;   //!
   TBranch        *b_muminus_TRACK_MatchCHI2;   //!
   TBranch        *b_muminus_TRACK_GhostProb;   //!
   TBranch        *b_muminus_TRACK_CloneDist;   //!
   TBranch        *b_muminus_TRACK_Likelihood;   //!
   TBranch        *b_muplus_MINIP;   //!
   TBranch        *b_muplus_MINIPCHI2;   //!
   TBranch        *b_muplus_MINIPNEXTBEST;   //!
   TBranch        *b_muplus_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_muplus_OWNPV_X;   //!
   TBranch        *b_muplus_OWNPV_Y;   //!
   TBranch        *b_muplus_OWNPV_Z;   //!
   TBranch        *b_muplus_OWNPV_XERR;   //!
   TBranch        *b_muplus_OWNPV_YERR;   //!
   TBranch        *b_muplus_OWNPV_ZERR;   //!
   TBranch        *b_muplus_OWNPV_CHI2;   //!
   TBranch        *b_muplus_OWNPV_NDOF;   //!
   TBranch        *b_muplus_OWNPV_COV_;   //!
   TBranch        *b_muplus_IP_OWNPV;   //!
   TBranch        *b_muplus_IPCHI2_OWNPV;   //!
   TBranch        *b_muplus_TOPPV_X;   //!
   TBranch        *b_muplus_TOPPV_Y;   //!
   TBranch        *b_muplus_TOPPV_Z;   //!
   TBranch        *b_muplus_TOPPV_XERR;   //!
   TBranch        *b_muplus_TOPPV_YERR;   //!
   TBranch        *b_muplus_TOPPV_ZERR;   //!
   TBranch        *b_muplus_TOPPV_CHI2;   //!
   TBranch        *b_muplus_TOPPV_NDOF;   //!
   TBranch        *b_muplus_TOPPV_COV_;   //!
   TBranch        *b_muplus_IP_TOPPV;   //!
   TBranch        *b_muplus_IPCHI2_TOPPV;   //!
   TBranch        *b_muplus_ORIVX_X;   //!
   TBranch        *b_muplus_ORIVX_Y;   //!
   TBranch        *b_muplus_ORIVX_Z;   //!
   TBranch        *b_muplus_ORIVX_XERR;   //!
   TBranch        *b_muplus_ORIVX_YERR;   //!
   TBranch        *b_muplus_ORIVX_ZERR;   //!
   TBranch        *b_muplus_ORIVX_CHI2;   //!
   TBranch        *b_muplus_ORIVX_NDOF;   //!
   TBranch        *b_muplus_ORIVX_COV_;   //!
   TBranch        *b_muplus_IP_ORIVX;   //!
   TBranch        *b_muplus_IPCHI2_ORIVX;   //!
   TBranch        *b_muplus_P;   //!
   TBranch        *b_muplus_PT;   //!
   TBranch        *b_muplus_PE;   //!
   TBranch        *b_muplus_PX;   //!
   TBranch        *b_muplus_PY;   //!
   TBranch        *b_muplus_PZ;   //!
   TBranch        *b_muplus_M;   //!
   TBranch        *b_muplus_ID;   //!
   TBranch        *b_muplus_PIDe;   //!
   TBranch        *b_muplus_PIDmu;   //!
   TBranch        *b_muplus_PIDK;   //!
   TBranch        *b_muplus_PIDp;   //!
   TBranch        *b_muplus_ProbNNe;   //!
   TBranch        *b_muplus_ProbNNk;   //!
   TBranch        *b_muplus_ProbNNp;   //!
   TBranch        *b_muplus_ProbNNpi;   //!
   TBranch        *b_muplus_ProbNNmu;   //!
   TBranch        *b_muplus_ProbNNghost;   //!
   TBranch        *b_muplus_hasMuon;   //!
   TBranch        *b_muplus_isMuon;   //!
   TBranch        *b_muplus_hasRich;   //!
   TBranch        *b_muplus_hasCalo;   //!
   TBranch        *b_muplus_TRACK_Type;   //!
   TBranch        *b_muplus_TRACK_Key;   //!
   TBranch        *b_muplus_TRACK_CHI2NDOF;   //!
   TBranch        *b_muplus_TRACK_PCHI2;   //!
   TBranch        *b_muplus_TRACK_MatchCHI2;   //!
   TBranch        *b_muplus_TRACK_GhostProb;   //!
   TBranch        *b_muplus_TRACK_CloneDist;   //!
   TBranch        *b_muplus_TRACK_Likelihood;   //!
   TBranch        *b_nCandidate;   //!
   TBranch        *b_totCandidates;   //!
   TBranch        *b_EventInSequence;   //!
   TBranch        *b_nLong;   //!
   TBranch        *b_nTracks;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_BCID;   //!
   TBranch        *b_BCType;   //!
   TBranch        *b_OdinTCK;   //!
   TBranch        *b_L0DUTCK;   //!
   TBranch        *b_HLTTCK;   //!
   TBranch        *b_GpsTime;   //!
   TBranch        *b_Primaries;   //!
   TBranch        *b_Polarity;   //!

   Lb2JpsiL(TTree *tree=0);
   virtual ~Lb2JpsiL();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Lb2JpsiL_cxx
Lb2JpsiL::Lb2JpsiL(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/Lb2JpsiL2.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/Lb2JpsiL2.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/afs/cern.ch/work/m/mwilkins/Lb2JpsiLtr/data/Lb2JpsiL2.root:/Lb2JpsiLTree");
      dir->GetObject("mytree",tree);

   }
   Init(tree);
}

Lb2JpsiL::~Lb2JpsiL()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Lb2JpsiL::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Lb2JpsiL::LoadTree(Long64_t entry)
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

void Lb2JpsiL::Init(TTree *tree)
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

   fChain->SetBranchAddress("Bs_MINIP", &Bs_MINIP, &b_Bs_MINIP);
   fChain->SetBranchAddress("Bs_MINIPCHI2", &Bs_MINIPCHI2, &b_Bs_MINIPCHI2);
   fChain->SetBranchAddress("Bs_MINIPNEXTBEST", &Bs_MINIPNEXTBEST, &b_Bs_MINIPNEXTBEST);
   fChain->SetBranchAddress("Bs_MINIPCHI2NEXTBEST", &Bs_MINIPCHI2NEXTBEST, &b_Bs_MINIPCHI2NEXTBEST);
   fChain->SetBranchAddress("Bs_ENDVERTEX_X", &Bs_ENDVERTEX_X, &b_Bs_ENDVERTEX_X);
   fChain->SetBranchAddress("Bs_ENDVERTEX_Y", &Bs_ENDVERTEX_Y, &b_Bs_ENDVERTEX_Y);
   fChain->SetBranchAddress("Bs_ENDVERTEX_Z", &Bs_ENDVERTEX_Z, &b_Bs_ENDVERTEX_Z);
   fChain->SetBranchAddress("Bs_ENDVERTEX_XERR", &Bs_ENDVERTEX_XERR, &b_Bs_ENDVERTEX_XERR);
   fChain->SetBranchAddress("Bs_ENDVERTEX_YERR", &Bs_ENDVERTEX_YERR, &b_Bs_ENDVERTEX_YERR);
   fChain->SetBranchAddress("Bs_ENDVERTEX_ZERR", &Bs_ENDVERTEX_ZERR, &b_Bs_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("Bs_ENDVERTEX_CHI2", &Bs_ENDVERTEX_CHI2, &b_Bs_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("Bs_ENDVERTEX_NDOF", &Bs_ENDVERTEX_NDOF, &b_Bs_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("Bs_ENDVERTEX_COV_", Bs_ENDVERTEX_COV_, &b_Bs_ENDVERTEX_COV_);
   fChain->SetBranchAddress("Bs_OWNPV_X", &Bs_OWNPV_X, &b_Bs_OWNPV_X);
   fChain->SetBranchAddress("Bs_OWNPV_Y", &Bs_OWNPV_Y, &b_Bs_OWNPV_Y);
   fChain->SetBranchAddress("Bs_OWNPV_Z", &Bs_OWNPV_Z, &b_Bs_OWNPV_Z);
   fChain->SetBranchAddress("Bs_OWNPV_XERR", &Bs_OWNPV_XERR, &b_Bs_OWNPV_XERR);
   fChain->SetBranchAddress("Bs_OWNPV_YERR", &Bs_OWNPV_YERR, &b_Bs_OWNPV_YERR);
   fChain->SetBranchAddress("Bs_OWNPV_ZERR", &Bs_OWNPV_ZERR, &b_Bs_OWNPV_ZERR);
   fChain->SetBranchAddress("Bs_OWNPV_CHI2", &Bs_OWNPV_CHI2, &b_Bs_OWNPV_CHI2);
   fChain->SetBranchAddress("Bs_OWNPV_NDOF", &Bs_OWNPV_NDOF, &b_Bs_OWNPV_NDOF);
   fChain->SetBranchAddress("Bs_OWNPV_COV_", Bs_OWNPV_COV_, &b_Bs_OWNPV_COV_);
   fChain->SetBranchAddress("Bs_IP_OWNPV", &Bs_IP_OWNPV, &b_Bs_IP_OWNPV);
   fChain->SetBranchAddress("Bs_IPCHI2_OWNPV", &Bs_IPCHI2_OWNPV, &b_Bs_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Bs_FD_OWNPV", &Bs_FD_OWNPV, &b_Bs_FD_OWNPV);
   fChain->SetBranchAddress("Bs_FDCHI2_OWNPV", &Bs_FDCHI2_OWNPV, &b_Bs_FDCHI2_OWNPV);
   fChain->SetBranchAddress("Bs_DIRA_OWNPV", &Bs_DIRA_OWNPV, &b_Bs_DIRA_OWNPV);
   fChain->SetBranchAddress("Bs_TOPPV_X", &Bs_TOPPV_X, &b_Bs_TOPPV_X);
   fChain->SetBranchAddress("Bs_TOPPV_Y", &Bs_TOPPV_Y, &b_Bs_TOPPV_Y);
   fChain->SetBranchAddress("Bs_TOPPV_Z", &Bs_TOPPV_Z, &b_Bs_TOPPV_Z);
   fChain->SetBranchAddress("Bs_TOPPV_XERR", &Bs_TOPPV_XERR, &b_Bs_TOPPV_XERR);
   fChain->SetBranchAddress("Bs_TOPPV_YERR", &Bs_TOPPV_YERR, &b_Bs_TOPPV_YERR);
   fChain->SetBranchAddress("Bs_TOPPV_ZERR", &Bs_TOPPV_ZERR, &b_Bs_TOPPV_ZERR);
   fChain->SetBranchAddress("Bs_TOPPV_CHI2", &Bs_TOPPV_CHI2, &b_Bs_TOPPV_CHI2);
   fChain->SetBranchAddress("Bs_TOPPV_NDOF", &Bs_TOPPV_NDOF, &b_Bs_TOPPV_NDOF);
   fChain->SetBranchAddress("Bs_TOPPV_COV_", Bs_TOPPV_COV_, &b_Bs_TOPPV_COV_);
   fChain->SetBranchAddress("Bs_IP_TOPPV", &Bs_IP_TOPPV, &b_Bs_IP_TOPPV);
   fChain->SetBranchAddress("Bs_IPCHI2_TOPPV", &Bs_IPCHI2_TOPPV, &b_Bs_IPCHI2_TOPPV);
   fChain->SetBranchAddress("Bs_FD_TOPPV", &Bs_FD_TOPPV, &b_Bs_FD_TOPPV);
   fChain->SetBranchAddress("Bs_FDCHI2_TOPPV", &Bs_FDCHI2_TOPPV, &b_Bs_FDCHI2_TOPPV);
   fChain->SetBranchAddress("Bs_DIRA_TOPPV", &Bs_DIRA_TOPPV, &b_Bs_DIRA_TOPPV);
   fChain->SetBranchAddress("Bs_P", &Bs_P, &b_Bs_P);
   fChain->SetBranchAddress("Bs_PT", &Bs_PT, &b_Bs_PT);
   fChain->SetBranchAddress("Bs_PE", &Bs_PE, &b_Bs_PE);
   fChain->SetBranchAddress("Bs_PX", &Bs_PX, &b_Bs_PX);
   fChain->SetBranchAddress("Bs_PY", &Bs_PY, &b_Bs_PY);
   fChain->SetBranchAddress("Bs_PZ", &Bs_PZ, &b_Bs_PZ);
   fChain->SetBranchAddress("Bs_MM", &Bs_MM, &b_Bs_MM);
   fChain->SetBranchAddress("Bs_MMERR", &Bs_MMERR, &b_Bs_MMERR);
   fChain->SetBranchAddress("Bs_M", &Bs_M, &b_Bs_M);
   fChain->SetBranchAddress("Bs_ID", &Bs_ID, &b_Bs_ID);
   fChain->SetBranchAddress("Bs_LOKI_DTF_CHI2NDOF", &Bs_LOKI_DTF_CHI2NDOF, &b_Bs_LOKI_DTF_CHI2NDOF);
   fChain->SetBranchAddress("Bs_LOKI_DTF_CTAU", &Bs_LOKI_DTF_CTAU, &b_Bs_LOKI_DTF_CTAU);
   fChain->SetBranchAddress("Bs_LOKI_DTF_CTAUERR", &Bs_LOKI_DTF_CTAUERR, &b_Bs_LOKI_DTF_CTAUERR);
   fChain->SetBranchAddress("Bs_LOKI_DTF_VCHI2NDOF", &Bs_LOKI_DTF_VCHI2NDOF, &b_Bs_LOKI_DTF_VCHI2NDOF);
   fChain->SetBranchAddress("Bs_LOKI_MASS_JpsiConstr", &Bs_LOKI_MASS_JpsiConstr, &b_Bs_LOKI_MASS_JpsiConstr);
   fChain->SetBranchAddress("Bs_TAU", &Bs_TAU, &b_Bs_TAU);
   fChain->SetBranchAddress("Bs_TAUERR", &Bs_TAUERR, &b_Bs_TAUERR);
   fChain->SetBranchAddress("Bs_TAUCHI2", &Bs_TAUCHI2, &b_Bs_TAUCHI2);
   fChain->SetBranchAddress("BsL0Global_Dec", &BsL0Global_Dec, &b_BsL0Global_Dec);
   fChain->SetBranchAddress("BsL0Global_TIS", &BsL0Global_TIS, &b_BsL0Global_TIS);
   fChain->SetBranchAddress("BsL0Global_TOS", &BsL0Global_TOS, &b_BsL0Global_TOS);
   fChain->SetBranchAddress("BsHlt1Global_Dec", &BsHlt1Global_Dec, &b_BsHlt1Global_Dec);
   fChain->SetBranchAddress("BsHlt1Global_TIS", &BsHlt1Global_TIS, &b_BsHlt1Global_TIS);
   fChain->SetBranchAddress("BsHlt1Global_TOS", &BsHlt1Global_TOS, &b_BsHlt1Global_TOS);
   fChain->SetBranchAddress("BsHlt1Phys_Dec", &BsHlt1Phys_Dec, &b_BsHlt1Phys_Dec);
   fChain->SetBranchAddress("BsHlt1Phys_TIS", &BsHlt1Phys_TIS, &b_BsHlt1Phys_TIS);
   fChain->SetBranchAddress("BsHlt1Phys_TOS", &BsHlt1Phys_TOS, &b_BsHlt1Phys_TOS);
   fChain->SetBranchAddress("BsHlt2Global_Dec", &BsHlt2Global_Dec, &b_BsHlt2Global_Dec);
   fChain->SetBranchAddress("BsHlt2Global_TIS", &BsHlt2Global_TIS, &b_BsHlt2Global_TIS);
   fChain->SetBranchAddress("BsHlt2Global_TOS", &BsHlt2Global_TOS, &b_BsHlt2Global_TOS);
   fChain->SetBranchAddress("BsHlt2Phys_Dec", &BsHlt2Phys_Dec, &b_BsHlt2Phys_Dec);
   fChain->SetBranchAddress("BsHlt2Phys_TIS", &BsHlt2Phys_TIS, &b_BsHlt2Phys_TIS);
   fChain->SetBranchAddress("BsHlt2Phys_TOS", &BsHlt2Phys_TOS, &b_BsHlt2Phys_TOS);
   fChain->SetBranchAddress("BsStrippingGlobal_Dec", &BsStrippingGlobal_Dec, &b_BsStrippingGlobal_Dec);
   fChain->SetBranchAddress("BsStrippingGlobal_TIS", &BsStrippingGlobal_TIS, &b_BsStrippingGlobal_TIS);
   fChain->SetBranchAddress("BsStrippingGlobal_TOS", &BsStrippingGlobal_TOS, &b_BsStrippingGlobal_TOS);
   fChain->SetBranchAddress("BsL0DiMuonDecision_Dec", &BsL0DiMuonDecision_Dec, &b_BsL0DiMuonDecision_Dec);
   fChain->SetBranchAddress("BsL0DiMuonDecision_TIS", &BsL0DiMuonDecision_TIS, &b_BsL0DiMuonDecision_TIS);
   fChain->SetBranchAddress("BsL0DiMuonDecision_TOS", &BsL0DiMuonDecision_TOS, &b_BsL0DiMuonDecision_TOS);
   fChain->SetBranchAddress("BsL0HCALDecision_Dec", &BsL0HCALDecision_Dec, &b_BsL0HCALDecision_Dec);
   fChain->SetBranchAddress("BsL0HCALDecision_TIS", &BsL0HCALDecision_TIS, &b_BsL0HCALDecision_TIS);
   fChain->SetBranchAddress("BsL0HCALDecision_TOS", &BsL0HCALDecision_TOS, &b_BsL0HCALDecision_TOS);
   fChain->SetBranchAddress("BsL0MuonDecision_Dec", &BsL0MuonDecision_Dec, &b_BsL0MuonDecision_Dec);
   fChain->SetBranchAddress("BsL0MuonDecision_TIS", &BsL0MuonDecision_TIS, &b_BsL0MuonDecision_TIS);
   fChain->SetBranchAddress("BsL0MuonDecision_TOS", &BsL0MuonDecision_TOS, &b_BsL0MuonDecision_TOS);
   fChain->SetBranchAddress("BsL0MuonHighDecision_Dec", &BsL0MuonHighDecision_Dec, &b_BsL0MuonHighDecision_Dec);
   fChain->SetBranchAddress("BsL0MuonHighDecision_TIS", &BsL0MuonHighDecision_TIS, &b_BsL0MuonHighDecision_TIS);
   fChain->SetBranchAddress("BsL0MuonHighDecision_TOS", &BsL0MuonHighDecision_TOS, &b_BsL0MuonHighDecision_TOS);
   fChain->SetBranchAddress("BsHlt1SingleMuonNoIPL0Decision_Dec", &BsHlt1SingleMuonNoIPL0Decision_Dec, &b_BsHlt1SingleMuonNoIPL0Decision_Dec);
   fChain->SetBranchAddress("BsHlt1SingleMuonNoIPL0Decision_TIS", &BsHlt1SingleMuonNoIPL0Decision_TIS, &b_BsHlt1SingleMuonNoIPL0Decision_TIS);
   fChain->SetBranchAddress("BsHlt1SingleMuonNoIPL0Decision_TOS", &BsHlt1SingleMuonNoIPL0Decision_TOS, &b_BsHlt1SingleMuonNoIPL0Decision_TOS);
   fChain->SetBranchAddress("BsHlt1DiMuonHighMassDecision_Dec", &BsHlt1DiMuonHighMassDecision_Dec, &b_BsHlt1DiMuonHighMassDecision_Dec);
   fChain->SetBranchAddress("BsHlt1DiMuonHighMassDecision_TIS", &BsHlt1DiMuonHighMassDecision_TIS, &b_BsHlt1DiMuonHighMassDecision_TIS);
   fChain->SetBranchAddress("BsHlt1DiMuonHighMassDecision_TOS", &BsHlt1DiMuonHighMassDecision_TOS, &b_BsHlt1DiMuonHighMassDecision_TOS);
   fChain->SetBranchAddress("BsHlt1DiMuonLowMassDecision_Dec", &BsHlt1DiMuonLowMassDecision_Dec, &b_BsHlt1DiMuonLowMassDecision_Dec);
   fChain->SetBranchAddress("BsHlt1DiMuonLowMassDecision_TIS", &BsHlt1DiMuonLowMassDecision_TIS, &b_BsHlt1DiMuonLowMassDecision_TIS);
   fChain->SetBranchAddress("BsHlt1DiMuonLowMassDecision_TOS", &BsHlt1DiMuonLowMassDecision_TOS, &b_BsHlt1DiMuonLowMassDecision_TOS);
   fChain->SetBranchAddress("BsHlt1SingleMuonHighPTDecision_Dec", &BsHlt1SingleMuonHighPTDecision_Dec, &b_BsHlt1SingleMuonHighPTDecision_Dec);
   fChain->SetBranchAddress("BsHlt1SingleMuonHighPTDecision_TIS", &BsHlt1SingleMuonHighPTDecision_TIS, &b_BsHlt1SingleMuonHighPTDecision_TIS);
   fChain->SetBranchAddress("BsHlt1SingleMuonHighPTDecision_TOS", &BsHlt1SingleMuonHighPTDecision_TOS, &b_BsHlt1SingleMuonHighPTDecision_TOS);
   fChain->SetBranchAddress("BsHlt1SingleMuonNoIPDecision_Dec", &BsHlt1SingleMuonNoIPDecision_Dec, &b_BsHlt1SingleMuonNoIPDecision_Dec);
   fChain->SetBranchAddress("BsHlt1SingleMuonNoIPDecision_TIS", &BsHlt1SingleMuonNoIPDecision_TIS, &b_BsHlt1SingleMuonNoIPDecision_TIS);
   fChain->SetBranchAddress("BsHlt1SingleMuonNoIPDecision_TOS", &BsHlt1SingleMuonNoIPDecision_TOS, &b_BsHlt1SingleMuonNoIPDecision_TOS);
   fChain->SetBranchAddress("BsHlt1TrackAllL0Decision_Dec", &BsHlt1TrackAllL0Decision_Dec, &b_BsHlt1TrackAllL0Decision_Dec);
   fChain->SetBranchAddress("BsHlt1TrackAllL0Decision_TIS", &BsHlt1TrackAllL0Decision_TIS, &b_BsHlt1TrackAllL0Decision_TIS);
   fChain->SetBranchAddress("BsHlt1TrackAllL0Decision_TOS", &BsHlt1TrackAllL0Decision_TOS, &b_BsHlt1TrackAllL0Decision_TOS);
   fChain->SetBranchAddress("BsHlt1TrackMuonDecision_Dec", &BsHlt1TrackMuonDecision_Dec, &b_BsHlt1TrackMuonDecision_Dec);
   fChain->SetBranchAddress("BsHlt1TrackMuonDecision_TIS", &BsHlt1TrackMuonDecision_TIS, &b_BsHlt1TrackMuonDecision_TIS);
   fChain->SetBranchAddress("BsHlt1TrackMuonDecision_TOS", &BsHlt1TrackMuonDecision_TOS, &b_BsHlt1TrackMuonDecision_TOS);
   fChain->SetBranchAddress("BsHlt2DiMuonBDecision_Dec", &BsHlt2DiMuonBDecision_Dec, &b_BsHlt2DiMuonBDecision_Dec);
   fChain->SetBranchAddress("BsHlt2DiMuonBDecision_TIS", &BsHlt2DiMuonBDecision_TIS, &b_BsHlt2DiMuonBDecision_TIS);
   fChain->SetBranchAddress("BsHlt2DiMuonBDecision_TOS", &BsHlt2DiMuonBDecision_TOS, &b_BsHlt2DiMuonBDecision_TOS);
   fChain->SetBranchAddress("BsHlt2DiMuonDecision_Dec", &BsHlt2DiMuonDecision_Dec, &b_BsHlt2DiMuonDecision_Dec);
   fChain->SetBranchAddress("BsHlt2DiMuonDecision_TIS", &BsHlt2DiMuonDecision_TIS, &b_BsHlt2DiMuonDecision_TIS);
   fChain->SetBranchAddress("BsHlt2DiMuonDecision_TOS", &BsHlt2DiMuonDecision_TOS, &b_BsHlt2DiMuonDecision_TOS);
   fChain->SetBranchAddress("BsHlt2DiMuonDY1Decision_Dec", &BsHlt2DiMuonDY1Decision_Dec, &b_BsHlt2DiMuonDY1Decision_Dec);
   fChain->SetBranchAddress("BsHlt2DiMuonDY1Decision_TIS", &BsHlt2DiMuonDY1Decision_TIS, &b_BsHlt2DiMuonDY1Decision_TIS);
   fChain->SetBranchAddress("BsHlt2DiMuonDY1Decision_TOS", &BsHlt2DiMuonDY1Decision_TOS, &b_BsHlt2DiMuonDY1Decision_TOS);
   fChain->SetBranchAddress("BsHlt2DiMuonDetachedDecision_Dec", &BsHlt2DiMuonDetachedDecision_Dec, &b_BsHlt2DiMuonDetachedDecision_Dec);
   fChain->SetBranchAddress("BsHlt2DiMuonDetachedDecision_TIS", &BsHlt2DiMuonDetachedDecision_TIS, &b_BsHlt2DiMuonDetachedDecision_TIS);
   fChain->SetBranchAddress("BsHlt2DiMuonDetachedDecision_TOS", &BsHlt2DiMuonDetachedDecision_TOS, &b_BsHlt2DiMuonDetachedDecision_TOS);
   fChain->SetBranchAddress("BsHlt2DiMuonDetachedHeavyDecision_Dec", &BsHlt2DiMuonDetachedHeavyDecision_Dec, &b_BsHlt2DiMuonDetachedHeavyDecision_Dec);
   fChain->SetBranchAddress("BsHlt2DiMuonDetachedHeavyDecision_TIS", &BsHlt2DiMuonDetachedHeavyDecision_TIS, &b_BsHlt2DiMuonDetachedHeavyDecision_TIS);
   fChain->SetBranchAddress("BsHlt2DiMuonDetachedHeavyDecision_TOS", &BsHlt2DiMuonDetachedHeavyDecision_TOS, &b_BsHlt2DiMuonDetachedHeavyDecision_TOS);
   fChain->SetBranchAddress("BsHlt2DiMuonDetachedJPsiDecision_Dec", &BsHlt2DiMuonDetachedJPsiDecision_Dec, &b_BsHlt2DiMuonDetachedJPsiDecision_Dec);
   fChain->SetBranchAddress("BsHlt2DiMuonDetachedJPsiDecision_TIS", &BsHlt2DiMuonDetachedJPsiDecision_TIS, &b_BsHlt2DiMuonDetachedJPsiDecision_TIS);
   fChain->SetBranchAddress("BsHlt2DiMuonDetachedJPsiDecision_TOS", &BsHlt2DiMuonDetachedJPsiDecision_TOS, &b_BsHlt2DiMuonDetachedJPsiDecision_TOS);
   fChain->SetBranchAddress("BsHlt2DiMuonJPsiDecision_Dec", &BsHlt2DiMuonJPsiDecision_Dec, &b_BsHlt2DiMuonJPsiDecision_Dec);
   fChain->SetBranchAddress("BsHlt2DiMuonJPsiDecision_TIS", &BsHlt2DiMuonJPsiDecision_TIS, &b_BsHlt2DiMuonJPsiDecision_TIS);
   fChain->SetBranchAddress("BsHlt2DiMuonJPsiDecision_TOS", &BsHlt2DiMuonJPsiDecision_TOS, &b_BsHlt2DiMuonJPsiDecision_TOS);
   fChain->SetBranchAddress("BsHlt2DiMuonJPsiHighPTDecision_Dec", &BsHlt2DiMuonJPsiHighPTDecision_Dec, &b_BsHlt2DiMuonJPsiHighPTDecision_Dec);
   fChain->SetBranchAddress("BsHlt2DiMuonJPsiHighPTDecision_TIS", &BsHlt2DiMuonJPsiHighPTDecision_TIS, &b_BsHlt2DiMuonJPsiHighPTDecision_TIS);
   fChain->SetBranchAddress("BsHlt2DiMuonJPsiHighPTDecision_TOS", &BsHlt2DiMuonJPsiHighPTDecision_TOS, &b_BsHlt2DiMuonJPsiHighPTDecision_TOS);
   fChain->SetBranchAddress("BsHlt2ExpressJPsiDecision_Dec", &BsHlt2ExpressJPsiDecision_Dec, &b_BsHlt2ExpressJPsiDecision_Dec);
   fChain->SetBranchAddress("BsHlt2ExpressJPsiDecision_TIS", &BsHlt2ExpressJPsiDecision_TIS, &b_BsHlt2ExpressJPsiDecision_TIS);
   fChain->SetBranchAddress("BsHlt2ExpressJPsiDecision_TOS", &BsHlt2ExpressJPsiDecision_TOS, &b_BsHlt2ExpressJPsiDecision_TOS);
   fChain->SetBranchAddress("BsHlt2ExpressJPsiTagProbeDecision_Dec", &BsHlt2ExpressJPsiTagProbeDecision_Dec, &b_BsHlt2ExpressJPsiTagProbeDecision_Dec);
   fChain->SetBranchAddress("BsHlt2ExpressJPsiTagProbeDecision_TIS", &BsHlt2ExpressJPsiTagProbeDecision_TIS, &b_BsHlt2ExpressJPsiTagProbeDecision_TIS);
   fChain->SetBranchAddress("BsHlt2ExpressJPsiTagProbeDecision_TOS", &BsHlt2ExpressJPsiTagProbeDecision_TOS, &b_BsHlt2ExpressJPsiTagProbeDecision_TOS);
   fChain->SetBranchAddress("BsHlt2SingleMuonDecision_Dec", &BsHlt2SingleMuonDecision_Dec, &b_BsHlt2SingleMuonDecision_Dec);
   fChain->SetBranchAddress("BsHlt2SingleMuonDecision_TIS", &BsHlt2SingleMuonDecision_TIS, &b_BsHlt2SingleMuonDecision_TIS);
   fChain->SetBranchAddress("BsHlt2SingleMuonDecision_TOS", &BsHlt2SingleMuonDecision_TOS, &b_BsHlt2SingleMuonDecision_TOS);
   fChain->SetBranchAddress("BsHlt2SingleMuonHighPTDecision_Dec", &BsHlt2SingleMuonHighPTDecision_Dec, &b_BsHlt2SingleMuonHighPTDecision_Dec);
   fChain->SetBranchAddress("BsHlt2SingleMuonHighPTDecision_TIS", &BsHlt2SingleMuonHighPTDecision_TIS, &b_BsHlt2SingleMuonHighPTDecision_TIS);
   fChain->SetBranchAddress("BsHlt2SingleMuonHighPTDecision_TOS", &BsHlt2SingleMuonHighPTDecision_TOS, &b_BsHlt2SingleMuonHighPTDecision_TOS);
   fChain->SetBranchAddress("BsHlt2SingleMuonLowPTDecision_Dec", &BsHlt2SingleMuonLowPTDecision_Dec, &b_BsHlt2SingleMuonLowPTDecision_Dec);
   fChain->SetBranchAddress("BsHlt2SingleMuonLowPTDecision_TIS", &BsHlt2SingleMuonLowPTDecision_TIS, &b_BsHlt2SingleMuonLowPTDecision_TIS);
   fChain->SetBranchAddress("BsHlt2SingleMuonLowPTDecision_TOS", &BsHlt2SingleMuonLowPTDecision_TOS, &b_BsHlt2SingleMuonLowPTDecision_TOS);
   fChain->SetBranchAddress("BsHlt2Topo2BodyBBDTDecision_Dec", &BsHlt2Topo2BodyBBDTDecision_Dec, &b_BsHlt2Topo2BodyBBDTDecision_Dec);
   fChain->SetBranchAddress("BsHlt2Topo2BodyBBDTDecision_TIS", &BsHlt2Topo2BodyBBDTDecision_TIS, &b_BsHlt2Topo2BodyBBDTDecision_TIS);
   fChain->SetBranchAddress("BsHlt2Topo2BodyBBDTDecision_TOS", &BsHlt2Topo2BodyBBDTDecision_TOS, &b_BsHlt2Topo2BodyBBDTDecision_TOS);
   fChain->SetBranchAddress("BsHlt2Topo2BodySimpleDecision_Dec", &BsHlt2Topo2BodySimpleDecision_Dec, &b_BsHlt2Topo2BodySimpleDecision_Dec);
   fChain->SetBranchAddress("BsHlt2Topo2BodySimpleDecision_TIS", &BsHlt2Topo2BodySimpleDecision_TIS, &b_BsHlt2Topo2BodySimpleDecision_TIS);
   fChain->SetBranchAddress("BsHlt2Topo2BodySimpleDecision_TOS", &BsHlt2Topo2BodySimpleDecision_TOS, &b_BsHlt2Topo2BodySimpleDecision_TOS);
   fChain->SetBranchAddress("BsHlt2Topo3BodyBBDTDecision_Dec", &BsHlt2Topo3BodyBBDTDecision_Dec, &b_BsHlt2Topo3BodyBBDTDecision_Dec);
   fChain->SetBranchAddress("BsHlt2Topo3BodyBBDTDecision_TIS", &BsHlt2Topo3BodyBBDTDecision_TIS, &b_BsHlt2Topo3BodyBBDTDecision_TIS);
   fChain->SetBranchAddress("BsHlt2Topo3BodyBBDTDecision_TOS", &BsHlt2Topo3BodyBBDTDecision_TOS, &b_BsHlt2Topo3BodyBBDTDecision_TOS);
   fChain->SetBranchAddress("BsHlt2Topo3BodySimpleDecision_Dec", &BsHlt2Topo3BodySimpleDecision_Dec, &b_BsHlt2Topo3BodySimpleDecision_Dec);
   fChain->SetBranchAddress("BsHlt2Topo3BodySimpleDecision_TIS", &BsHlt2Topo3BodySimpleDecision_TIS, &b_BsHlt2Topo3BodySimpleDecision_TIS);
   fChain->SetBranchAddress("BsHlt2Topo3BodySimpleDecision_TOS", &BsHlt2Topo3BodySimpleDecision_TOS, &b_BsHlt2Topo3BodySimpleDecision_TOS);
   fChain->SetBranchAddress("BsHlt2Topo4BodyBBDTDecision_Dec", &BsHlt2Topo4BodyBBDTDecision_Dec, &b_BsHlt2Topo4BodyBBDTDecision_Dec);
   fChain->SetBranchAddress("BsHlt2Topo4BodyBBDTDecision_TIS", &BsHlt2Topo4BodyBBDTDecision_TIS, &b_BsHlt2Topo4BodyBBDTDecision_TIS);
   fChain->SetBranchAddress("BsHlt2Topo4BodyBBDTDecision_TOS", &BsHlt2Topo4BodyBBDTDecision_TOS, &b_BsHlt2Topo4BodyBBDTDecision_TOS);
   fChain->SetBranchAddress("BsHlt2Topo4BodySimpleDecision_Dec", &BsHlt2Topo4BodySimpleDecision_Dec, &b_BsHlt2Topo4BodySimpleDecision_Dec);
   fChain->SetBranchAddress("BsHlt2Topo4BodySimpleDecision_TIS", &BsHlt2Topo4BodySimpleDecision_TIS, &b_BsHlt2Topo4BodySimpleDecision_TIS);
   fChain->SetBranchAddress("BsHlt2Topo4BodySimpleDecision_TOS", &BsHlt2Topo4BodySimpleDecision_TOS, &b_BsHlt2Topo4BodySimpleDecision_TOS);
   fChain->SetBranchAddress("BsHlt2TopoMu2BodyBBDTDecision_Dec", &BsHlt2TopoMu2BodyBBDTDecision_Dec, &b_BsHlt2TopoMu2BodyBBDTDecision_Dec);
   fChain->SetBranchAddress("BsHlt2TopoMu2BodyBBDTDecision_TIS", &BsHlt2TopoMu2BodyBBDTDecision_TIS, &b_BsHlt2TopoMu2BodyBBDTDecision_TIS);
   fChain->SetBranchAddress("BsHlt2TopoMu2BodyBBDTDecision_TOS", &BsHlt2TopoMu2BodyBBDTDecision_TOS, &b_BsHlt2TopoMu2BodyBBDTDecision_TOS);
   fChain->SetBranchAddress("BsHlt2TopoMu3BodyBBDTDecision_Dec", &BsHlt2TopoMu3BodyBBDTDecision_Dec, &b_BsHlt2TopoMu3BodyBBDTDecision_Dec);
   fChain->SetBranchAddress("BsHlt2TopoMu3BodyBBDTDecision_TIS", &BsHlt2TopoMu3BodyBBDTDecision_TIS, &b_BsHlt2TopoMu3BodyBBDTDecision_TIS);
   fChain->SetBranchAddress("BsHlt2TopoMu3BodyBBDTDecision_TOS", &BsHlt2TopoMu3BodyBBDTDecision_TOS, &b_BsHlt2TopoMu3BodyBBDTDecision_TOS);
   fChain->SetBranchAddress("BsHlt2TopoMu4BodyBBDTDecision_Dec", &BsHlt2TopoMu4BodyBBDTDecision_Dec, &b_BsHlt2TopoMu4BodyBBDTDecision_Dec);
   fChain->SetBranchAddress("BsHlt2TopoMu4BodyBBDTDecision_TIS", &BsHlt2TopoMu4BodyBBDTDecision_TIS, &b_BsHlt2TopoMu4BodyBBDTDecision_TIS);
   fChain->SetBranchAddress("BsHlt2TopoMu4BodyBBDTDecision_TOS", &BsHlt2TopoMu4BodyBBDTDecision_TOS, &b_BsHlt2TopoMu4BodyBBDTDecision_TOS);
   fChain->SetBranchAddress("BsHlt2TransparentDecision_Dec", &BsHlt2TransparentDecision_Dec, &b_BsHlt2TransparentDecision_Dec);
   fChain->SetBranchAddress("BsHlt2TransparentDecision_TIS", &BsHlt2TransparentDecision_TIS, &b_BsHlt2TransparentDecision_TIS);
   fChain->SetBranchAddress("BsHlt2TransparentDecision_TOS", &BsHlt2TransparentDecision_TOS, &b_BsHlt2TransparentDecision_TOS);
   fChain->SetBranchAddress("BsHlt2DiMuonUnbiasedJPsiDecision_Dec", &BsHlt2DiMuonUnbiasedJPsiDecision_Dec, &b_BsHlt2DiMuonUnbiasedJPsiDecision_Dec);
   fChain->SetBranchAddress("BsHlt2DiMuonUnbiasedJPsiDecision_TIS", &BsHlt2DiMuonUnbiasedJPsiDecision_TIS, &b_BsHlt2DiMuonUnbiasedJPsiDecision_TIS);
   fChain->SetBranchAddress("BsHlt2DiMuonUnbiasedJPsiDecision_TOS", &BsHlt2DiMuonUnbiasedJPsiDecision_TOS, &b_BsHlt2DiMuonUnbiasedJPsiDecision_TOS);
   fChain->SetBranchAddress("R_MINIP", &R_MINIP, &b_R_MINIP);
   fChain->SetBranchAddress("R_MINIPCHI2", &R_MINIPCHI2, &b_R_MINIPCHI2);
   fChain->SetBranchAddress("R_MINIPNEXTBEST", &R_MINIPNEXTBEST, &b_R_MINIPNEXTBEST);
   fChain->SetBranchAddress("R_MINIPCHI2NEXTBEST", &R_MINIPCHI2NEXTBEST, &b_R_MINIPCHI2NEXTBEST);
   fChain->SetBranchAddress("R_ENDVERTEX_X", &R_ENDVERTEX_X, &b_R_ENDVERTEX_X);
   fChain->SetBranchAddress("R_ENDVERTEX_Y", &R_ENDVERTEX_Y, &b_R_ENDVERTEX_Y);
   fChain->SetBranchAddress("R_ENDVERTEX_Z", &R_ENDVERTEX_Z, &b_R_ENDVERTEX_Z);
   fChain->SetBranchAddress("R_ENDVERTEX_XERR", &R_ENDVERTEX_XERR, &b_R_ENDVERTEX_XERR);
   fChain->SetBranchAddress("R_ENDVERTEX_YERR", &R_ENDVERTEX_YERR, &b_R_ENDVERTEX_YERR);
   fChain->SetBranchAddress("R_ENDVERTEX_ZERR", &R_ENDVERTEX_ZERR, &b_R_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("R_ENDVERTEX_CHI2", &R_ENDVERTEX_CHI2, &b_R_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("R_ENDVERTEX_NDOF", &R_ENDVERTEX_NDOF, &b_R_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("R_ENDVERTEX_COV_", R_ENDVERTEX_COV_, &b_R_ENDVERTEX_COV_);
   fChain->SetBranchAddress("R_OWNPV_X", &R_OWNPV_X, &b_R_OWNPV_X);
   fChain->SetBranchAddress("R_OWNPV_Y", &R_OWNPV_Y, &b_R_OWNPV_Y);
   fChain->SetBranchAddress("R_OWNPV_Z", &R_OWNPV_Z, &b_R_OWNPV_Z);
   fChain->SetBranchAddress("R_OWNPV_XERR", &R_OWNPV_XERR, &b_R_OWNPV_XERR);
   fChain->SetBranchAddress("R_OWNPV_YERR", &R_OWNPV_YERR, &b_R_OWNPV_YERR);
   fChain->SetBranchAddress("R_OWNPV_ZERR", &R_OWNPV_ZERR, &b_R_OWNPV_ZERR);
   fChain->SetBranchAddress("R_OWNPV_CHI2", &R_OWNPV_CHI2, &b_R_OWNPV_CHI2);
   fChain->SetBranchAddress("R_OWNPV_NDOF", &R_OWNPV_NDOF, &b_R_OWNPV_NDOF);
   fChain->SetBranchAddress("R_OWNPV_COV_", R_OWNPV_COV_, &b_R_OWNPV_COV_);
   fChain->SetBranchAddress("R_IP_OWNPV", &R_IP_OWNPV, &b_R_IP_OWNPV);
   fChain->SetBranchAddress("R_IPCHI2_OWNPV", &R_IPCHI2_OWNPV, &b_R_IPCHI2_OWNPV);
   fChain->SetBranchAddress("R_FD_OWNPV", &R_FD_OWNPV, &b_R_FD_OWNPV);
   fChain->SetBranchAddress("R_FDCHI2_OWNPV", &R_FDCHI2_OWNPV, &b_R_FDCHI2_OWNPV);
   fChain->SetBranchAddress("R_DIRA_OWNPV", &R_DIRA_OWNPV, &b_R_DIRA_OWNPV);
   fChain->SetBranchAddress("R_TOPPV_X", &R_TOPPV_X, &b_R_TOPPV_X);
   fChain->SetBranchAddress("R_TOPPV_Y", &R_TOPPV_Y, &b_R_TOPPV_Y);
   fChain->SetBranchAddress("R_TOPPV_Z", &R_TOPPV_Z, &b_R_TOPPV_Z);
   fChain->SetBranchAddress("R_TOPPV_XERR", &R_TOPPV_XERR, &b_R_TOPPV_XERR);
   fChain->SetBranchAddress("R_TOPPV_YERR", &R_TOPPV_YERR, &b_R_TOPPV_YERR);
   fChain->SetBranchAddress("R_TOPPV_ZERR", &R_TOPPV_ZERR, &b_R_TOPPV_ZERR);
   fChain->SetBranchAddress("R_TOPPV_CHI2", &R_TOPPV_CHI2, &b_R_TOPPV_CHI2);
   fChain->SetBranchAddress("R_TOPPV_NDOF", &R_TOPPV_NDOF, &b_R_TOPPV_NDOF);
   fChain->SetBranchAddress("R_TOPPV_COV_", R_TOPPV_COV_, &b_R_TOPPV_COV_);
   fChain->SetBranchAddress("R_IP_TOPPV", &R_IP_TOPPV, &b_R_IP_TOPPV);
   fChain->SetBranchAddress("R_IPCHI2_TOPPV", &R_IPCHI2_TOPPV, &b_R_IPCHI2_TOPPV);
   fChain->SetBranchAddress("R_FD_TOPPV", &R_FD_TOPPV, &b_R_FD_TOPPV);
   fChain->SetBranchAddress("R_FDCHI2_TOPPV", &R_FDCHI2_TOPPV, &b_R_FDCHI2_TOPPV);
   fChain->SetBranchAddress("R_DIRA_TOPPV", &R_DIRA_TOPPV, &b_R_DIRA_TOPPV);
   fChain->SetBranchAddress("R_ORIVX_X", &R_ORIVX_X, &b_R_ORIVX_X);
   fChain->SetBranchAddress("R_ORIVX_Y", &R_ORIVX_Y, &b_R_ORIVX_Y);
   fChain->SetBranchAddress("R_ORIVX_Z", &R_ORIVX_Z, &b_R_ORIVX_Z);
   fChain->SetBranchAddress("R_ORIVX_XERR", &R_ORIVX_XERR, &b_R_ORIVX_XERR);
   fChain->SetBranchAddress("R_ORIVX_YERR", &R_ORIVX_YERR, &b_R_ORIVX_YERR);
   fChain->SetBranchAddress("R_ORIVX_ZERR", &R_ORIVX_ZERR, &b_R_ORIVX_ZERR);
   fChain->SetBranchAddress("R_ORIVX_CHI2", &R_ORIVX_CHI2, &b_R_ORIVX_CHI2);
   fChain->SetBranchAddress("R_ORIVX_NDOF", &R_ORIVX_NDOF, &b_R_ORIVX_NDOF);
   fChain->SetBranchAddress("R_ORIVX_COV_", R_ORIVX_COV_, &b_R_ORIVX_COV_);
   fChain->SetBranchAddress("R_IP_ORIVX", &R_IP_ORIVX, &b_R_IP_ORIVX);
   fChain->SetBranchAddress("R_IPCHI2_ORIVX", &R_IPCHI2_ORIVX, &b_R_IPCHI2_ORIVX);
   fChain->SetBranchAddress("R_FD_ORIVX", &R_FD_ORIVX, &b_R_FD_ORIVX);
   fChain->SetBranchAddress("R_FDCHI2_ORIVX", &R_FDCHI2_ORIVX, &b_R_FDCHI2_ORIVX);
   fChain->SetBranchAddress("R_DIRA_ORIVX", &R_DIRA_ORIVX, &b_R_DIRA_ORIVX);
   fChain->SetBranchAddress("R_P", &R_P, &b_R_P);
   fChain->SetBranchAddress("R_PT", &R_PT, &b_R_PT);
   fChain->SetBranchAddress("R_PE", &R_PE, &b_R_PE);
   fChain->SetBranchAddress("R_PX", &R_PX, &b_R_PX);
   fChain->SetBranchAddress("R_PY", &R_PY, &b_R_PY);
   fChain->SetBranchAddress("R_PZ", &R_PZ, &b_R_PZ);
   fChain->SetBranchAddress("R_MM", &R_MM, &b_R_MM);
   fChain->SetBranchAddress("R_MMERR", &R_MMERR, &b_R_MMERR);
   fChain->SetBranchAddress("R_M", &R_M, &b_R_M);
   fChain->SetBranchAddress("R_ID", &R_ID, &b_R_ID);
   fChain->SetBranchAddress("H2_MINIP", &H2_MINIP, &b_H2_MINIP);
   fChain->SetBranchAddress("H2_MINIPCHI2", &H2_MINIPCHI2, &b_H2_MINIPCHI2);
   fChain->SetBranchAddress("H2_MINIPNEXTBEST", &H2_MINIPNEXTBEST, &b_H2_MINIPNEXTBEST);
   fChain->SetBranchAddress("H2_MINIPCHI2NEXTBEST", &H2_MINIPCHI2NEXTBEST, &b_H2_MINIPCHI2NEXTBEST);
   fChain->SetBranchAddress("H2_OWNPV_X", &H2_OWNPV_X, &b_H2_OWNPV_X);
   fChain->SetBranchAddress("H2_OWNPV_Y", &H2_OWNPV_Y, &b_H2_OWNPV_Y);
   fChain->SetBranchAddress("H2_OWNPV_Z", &H2_OWNPV_Z, &b_H2_OWNPV_Z);
   fChain->SetBranchAddress("H2_OWNPV_XERR", &H2_OWNPV_XERR, &b_H2_OWNPV_XERR);
   fChain->SetBranchAddress("H2_OWNPV_YERR", &H2_OWNPV_YERR, &b_H2_OWNPV_YERR);
   fChain->SetBranchAddress("H2_OWNPV_ZERR", &H2_OWNPV_ZERR, &b_H2_OWNPV_ZERR);
   fChain->SetBranchAddress("H2_OWNPV_CHI2", &H2_OWNPV_CHI2, &b_H2_OWNPV_CHI2);
   fChain->SetBranchAddress("H2_OWNPV_NDOF", &H2_OWNPV_NDOF, &b_H2_OWNPV_NDOF);
   fChain->SetBranchAddress("H2_OWNPV_COV_", H2_OWNPV_COV_, &b_H2_OWNPV_COV_);
   fChain->SetBranchAddress("H2_IP_OWNPV", &H2_IP_OWNPV, &b_H2_IP_OWNPV);
   fChain->SetBranchAddress("H2_IPCHI2_OWNPV", &H2_IPCHI2_OWNPV, &b_H2_IPCHI2_OWNPV);
   fChain->SetBranchAddress("H2_TOPPV_X", &H2_TOPPV_X, &b_H2_TOPPV_X);
   fChain->SetBranchAddress("H2_TOPPV_Y", &H2_TOPPV_Y, &b_H2_TOPPV_Y);
   fChain->SetBranchAddress("H2_TOPPV_Z", &H2_TOPPV_Z, &b_H2_TOPPV_Z);
   fChain->SetBranchAddress("H2_TOPPV_XERR", &H2_TOPPV_XERR, &b_H2_TOPPV_XERR);
   fChain->SetBranchAddress("H2_TOPPV_YERR", &H2_TOPPV_YERR, &b_H2_TOPPV_YERR);
   fChain->SetBranchAddress("H2_TOPPV_ZERR", &H2_TOPPV_ZERR, &b_H2_TOPPV_ZERR);
   fChain->SetBranchAddress("H2_TOPPV_CHI2", &H2_TOPPV_CHI2, &b_H2_TOPPV_CHI2);
   fChain->SetBranchAddress("H2_TOPPV_NDOF", &H2_TOPPV_NDOF, &b_H2_TOPPV_NDOF);
   fChain->SetBranchAddress("H2_TOPPV_COV_", H2_TOPPV_COV_, &b_H2_TOPPV_COV_);
   fChain->SetBranchAddress("H2_IP_TOPPV", &H2_IP_TOPPV, &b_H2_IP_TOPPV);
   fChain->SetBranchAddress("H2_IPCHI2_TOPPV", &H2_IPCHI2_TOPPV, &b_H2_IPCHI2_TOPPV);
   fChain->SetBranchAddress("H2_ORIVX_X", &H2_ORIVX_X, &b_H2_ORIVX_X);
   fChain->SetBranchAddress("H2_ORIVX_Y", &H2_ORIVX_Y, &b_H2_ORIVX_Y);
   fChain->SetBranchAddress("H2_ORIVX_Z", &H2_ORIVX_Z, &b_H2_ORIVX_Z);
   fChain->SetBranchAddress("H2_ORIVX_XERR", &H2_ORIVX_XERR, &b_H2_ORIVX_XERR);
   fChain->SetBranchAddress("H2_ORIVX_YERR", &H2_ORIVX_YERR, &b_H2_ORIVX_YERR);
   fChain->SetBranchAddress("H2_ORIVX_ZERR", &H2_ORIVX_ZERR, &b_H2_ORIVX_ZERR);
   fChain->SetBranchAddress("H2_ORIVX_CHI2", &H2_ORIVX_CHI2, &b_H2_ORIVX_CHI2);
   fChain->SetBranchAddress("H2_ORIVX_NDOF", &H2_ORIVX_NDOF, &b_H2_ORIVX_NDOF);
   fChain->SetBranchAddress("H2_ORIVX_COV_", H2_ORIVX_COV_, &b_H2_ORIVX_COV_);
   fChain->SetBranchAddress("H2_IP_ORIVX", &H2_IP_ORIVX, &b_H2_IP_ORIVX);
   fChain->SetBranchAddress("H2_IPCHI2_ORIVX", &H2_IPCHI2_ORIVX, &b_H2_IPCHI2_ORIVX);
   fChain->SetBranchAddress("H2_P", &H2_P, &b_H2_P);
   fChain->SetBranchAddress("H2_PT", &H2_PT, &b_H2_PT);
   fChain->SetBranchAddress("H2_PE", &H2_PE, &b_H2_PE);
   fChain->SetBranchAddress("H2_PX", &H2_PX, &b_H2_PX);
   fChain->SetBranchAddress("H2_PY", &H2_PY, &b_H2_PY);
   fChain->SetBranchAddress("H2_PZ", &H2_PZ, &b_H2_PZ);
   fChain->SetBranchAddress("H2_M", &H2_M, &b_H2_M);
   fChain->SetBranchAddress("H2_ID", &H2_ID, &b_H2_ID);
   fChain->SetBranchAddress("H2_PIDe", &H2_PIDe, &b_H2_PIDe);
   fChain->SetBranchAddress("H2_PIDmu", &H2_PIDmu, &b_H2_PIDmu);
   fChain->SetBranchAddress("H2_PIDK", &H2_PIDK, &b_H2_PIDK);
   fChain->SetBranchAddress("H2_PIDp", &H2_PIDp, &b_H2_PIDp);
   fChain->SetBranchAddress("H2_ProbNNe", &H2_ProbNNe, &b_H2_ProbNNe);
   fChain->SetBranchAddress("H2_ProbNNk", &H2_ProbNNk, &b_H2_ProbNNk);
   fChain->SetBranchAddress("H2_ProbNNp", &H2_ProbNNp, &b_H2_ProbNNp);
   fChain->SetBranchAddress("H2_ProbNNpi", &H2_ProbNNpi, &b_H2_ProbNNpi);
   fChain->SetBranchAddress("H2_ProbNNmu", &H2_ProbNNmu, &b_H2_ProbNNmu);
   fChain->SetBranchAddress("H2_ProbNNghost", &H2_ProbNNghost, &b_H2_ProbNNghost);
   fChain->SetBranchAddress("H2_hasMuon", &H2_hasMuon, &b_H2_hasMuon);
   fChain->SetBranchAddress("H2_isMuon", &H2_isMuon, &b_H2_isMuon);
   fChain->SetBranchAddress("H2_hasRich", &H2_hasRich, &b_H2_hasRich);
   fChain->SetBranchAddress("H2_hasCalo", &H2_hasCalo, &b_H2_hasCalo);
   fChain->SetBranchAddress("H2_TRACK_Type", &H2_TRACK_Type, &b_H2_TRACK_Type);
   fChain->SetBranchAddress("H2_TRACK_Key", &H2_TRACK_Key, &b_H2_TRACK_Key);
   fChain->SetBranchAddress("H2_TRACK_CHI2NDOF", &H2_TRACK_CHI2NDOF, &b_H2_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("H2_TRACK_PCHI2", &H2_TRACK_PCHI2, &b_H2_TRACK_PCHI2);
   fChain->SetBranchAddress("H2_TRACK_MatchCHI2", &H2_TRACK_MatchCHI2, &b_H2_TRACK_MatchCHI2);
   fChain->SetBranchAddress("H2_TRACK_GhostProb", &H2_TRACK_GhostProb, &b_H2_TRACK_GhostProb);
   fChain->SetBranchAddress("H2_TRACK_CloneDist", &H2_TRACK_CloneDist, &b_H2_TRACK_CloneDist);
   fChain->SetBranchAddress("H2_TRACK_Likelihood", &H2_TRACK_Likelihood, &b_H2_TRACK_Likelihood);
   fChain->SetBranchAddress("H1_MINIP", &H1_MINIP, &b_H1_MINIP);
   fChain->SetBranchAddress("H1_MINIPCHI2", &H1_MINIPCHI2, &b_H1_MINIPCHI2);
   fChain->SetBranchAddress("H1_MINIPNEXTBEST", &H1_MINIPNEXTBEST, &b_H1_MINIPNEXTBEST);
   fChain->SetBranchAddress("H1_MINIPCHI2NEXTBEST", &H1_MINIPCHI2NEXTBEST, &b_H1_MINIPCHI2NEXTBEST);
   fChain->SetBranchAddress("H1_OWNPV_X", &H1_OWNPV_X, &b_H1_OWNPV_X);
   fChain->SetBranchAddress("H1_OWNPV_Y", &H1_OWNPV_Y, &b_H1_OWNPV_Y);
   fChain->SetBranchAddress("H1_OWNPV_Z", &H1_OWNPV_Z, &b_H1_OWNPV_Z);
   fChain->SetBranchAddress("H1_OWNPV_XERR", &H1_OWNPV_XERR, &b_H1_OWNPV_XERR);
   fChain->SetBranchAddress("H1_OWNPV_YERR", &H1_OWNPV_YERR, &b_H1_OWNPV_YERR);
   fChain->SetBranchAddress("H1_OWNPV_ZERR", &H1_OWNPV_ZERR, &b_H1_OWNPV_ZERR);
   fChain->SetBranchAddress("H1_OWNPV_CHI2", &H1_OWNPV_CHI2, &b_H1_OWNPV_CHI2);
   fChain->SetBranchAddress("H1_OWNPV_NDOF", &H1_OWNPV_NDOF, &b_H1_OWNPV_NDOF);
   fChain->SetBranchAddress("H1_OWNPV_COV_", H1_OWNPV_COV_, &b_H1_OWNPV_COV_);
   fChain->SetBranchAddress("H1_IP_OWNPV", &H1_IP_OWNPV, &b_H1_IP_OWNPV);
   fChain->SetBranchAddress("H1_IPCHI2_OWNPV", &H1_IPCHI2_OWNPV, &b_H1_IPCHI2_OWNPV);
   fChain->SetBranchAddress("H1_TOPPV_X", &H1_TOPPV_X, &b_H1_TOPPV_X);
   fChain->SetBranchAddress("H1_TOPPV_Y", &H1_TOPPV_Y, &b_H1_TOPPV_Y);
   fChain->SetBranchAddress("H1_TOPPV_Z", &H1_TOPPV_Z, &b_H1_TOPPV_Z);
   fChain->SetBranchAddress("H1_TOPPV_XERR", &H1_TOPPV_XERR, &b_H1_TOPPV_XERR);
   fChain->SetBranchAddress("H1_TOPPV_YERR", &H1_TOPPV_YERR, &b_H1_TOPPV_YERR);
   fChain->SetBranchAddress("H1_TOPPV_ZERR", &H1_TOPPV_ZERR, &b_H1_TOPPV_ZERR);
   fChain->SetBranchAddress("H1_TOPPV_CHI2", &H1_TOPPV_CHI2, &b_H1_TOPPV_CHI2);
   fChain->SetBranchAddress("H1_TOPPV_NDOF", &H1_TOPPV_NDOF, &b_H1_TOPPV_NDOF);
   fChain->SetBranchAddress("H1_TOPPV_COV_", H1_TOPPV_COV_, &b_H1_TOPPV_COV_);
   fChain->SetBranchAddress("H1_IP_TOPPV", &H1_IP_TOPPV, &b_H1_IP_TOPPV);
   fChain->SetBranchAddress("H1_IPCHI2_TOPPV", &H1_IPCHI2_TOPPV, &b_H1_IPCHI2_TOPPV);
   fChain->SetBranchAddress("H1_ORIVX_X", &H1_ORIVX_X, &b_H1_ORIVX_X);
   fChain->SetBranchAddress("H1_ORIVX_Y", &H1_ORIVX_Y, &b_H1_ORIVX_Y);
   fChain->SetBranchAddress("H1_ORIVX_Z", &H1_ORIVX_Z, &b_H1_ORIVX_Z);
   fChain->SetBranchAddress("H1_ORIVX_XERR", &H1_ORIVX_XERR, &b_H1_ORIVX_XERR);
   fChain->SetBranchAddress("H1_ORIVX_YERR", &H1_ORIVX_YERR, &b_H1_ORIVX_YERR);
   fChain->SetBranchAddress("H1_ORIVX_ZERR", &H1_ORIVX_ZERR, &b_H1_ORIVX_ZERR);
   fChain->SetBranchAddress("H1_ORIVX_CHI2", &H1_ORIVX_CHI2, &b_H1_ORIVX_CHI2);
   fChain->SetBranchAddress("H1_ORIVX_NDOF", &H1_ORIVX_NDOF, &b_H1_ORIVX_NDOF);
   fChain->SetBranchAddress("H1_ORIVX_COV_", H1_ORIVX_COV_, &b_H1_ORIVX_COV_);
   fChain->SetBranchAddress("H1_IP_ORIVX", &H1_IP_ORIVX, &b_H1_IP_ORIVX);
   fChain->SetBranchAddress("H1_IPCHI2_ORIVX", &H1_IPCHI2_ORIVX, &b_H1_IPCHI2_ORIVX);
   fChain->SetBranchAddress("H1_P", &H1_P, &b_H1_P);
   fChain->SetBranchAddress("H1_PT", &H1_PT, &b_H1_PT);
   fChain->SetBranchAddress("H1_PE", &H1_PE, &b_H1_PE);
   fChain->SetBranchAddress("H1_PX", &H1_PX, &b_H1_PX);
   fChain->SetBranchAddress("H1_PY", &H1_PY, &b_H1_PY);
   fChain->SetBranchAddress("H1_PZ", &H1_PZ, &b_H1_PZ);
   fChain->SetBranchAddress("H1_M", &H1_M, &b_H1_M);
   fChain->SetBranchAddress("H1_ID", &H1_ID, &b_H1_ID);
   fChain->SetBranchAddress("H1_PIDe", &H1_PIDe, &b_H1_PIDe);
   fChain->SetBranchAddress("H1_PIDmu", &H1_PIDmu, &b_H1_PIDmu);
   fChain->SetBranchAddress("H1_PIDK", &H1_PIDK, &b_H1_PIDK);
   fChain->SetBranchAddress("H1_PIDp", &H1_PIDp, &b_H1_PIDp);
   fChain->SetBranchAddress("H1_ProbNNe", &H1_ProbNNe, &b_H1_ProbNNe);
   fChain->SetBranchAddress("H1_ProbNNk", &H1_ProbNNk, &b_H1_ProbNNk);
   fChain->SetBranchAddress("H1_ProbNNp", &H1_ProbNNp, &b_H1_ProbNNp);
   fChain->SetBranchAddress("H1_ProbNNpi", &H1_ProbNNpi, &b_H1_ProbNNpi);
   fChain->SetBranchAddress("H1_ProbNNmu", &H1_ProbNNmu, &b_H1_ProbNNmu);
   fChain->SetBranchAddress("H1_ProbNNghost", &H1_ProbNNghost, &b_H1_ProbNNghost);
   fChain->SetBranchAddress("H1_hasMuon", &H1_hasMuon, &b_H1_hasMuon);
   fChain->SetBranchAddress("H1_isMuon", &H1_isMuon, &b_H1_isMuon);
   fChain->SetBranchAddress("H1_hasRich", &H1_hasRich, &b_H1_hasRich);
   fChain->SetBranchAddress("H1_hasCalo", &H1_hasCalo, &b_H1_hasCalo);
   fChain->SetBranchAddress("H1_TRACK_Type", &H1_TRACK_Type, &b_H1_TRACK_Type);
   fChain->SetBranchAddress("H1_TRACK_Key", &H1_TRACK_Key, &b_H1_TRACK_Key);
   fChain->SetBranchAddress("H1_TRACK_CHI2NDOF", &H1_TRACK_CHI2NDOF, &b_H1_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("H1_TRACK_PCHI2", &H1_TRACK_PCHI2, &b_H1_TRACK_PCHI2);
   fChain->SetBranchAddress("H1_TRACK_MatchCHI2", &H1_TRACK_MatchCHI2, &b_H1_TRACK_MatchCHI2);
   fChain->SetBranchAddress("H1_TRACK_GhostProb", &H1_TRACK_GhostProb, &b_H1_TRACK_GhostProb);
   fChain->SetBranchAddress("H1_TRACK_CloneDist", &H1_TRACK_CloneDist, &b_H1_TRACK_CloneDist);
   fChain->SetBranchAddress("H1_TRACK_Likelihood", &H1_TRACK_Likelihood, &b_H1_TRACK_Likelihood);
   fChain->SetBranchAddress("J_psi_1S_MINIP", &J_psi_1S_MINIP, &b_J_psi_1S_MINIP);
   fChain->SetBranchAddress("J_psi_1S_MINIPCHI2", &J_psi_1S_MINIPCHI2, &b_J_psi_1S_MINIPCHI2);
   fChain->SetBranchAddress("J_psi_1S_MINIPNEXTBEST", &J_psi_1S_MINIPNEXTBEST, &b_J_psi_1S_MINIPNEXTBEST);
   fChain->SetBranchAddress("J_psi_1S_MINIPCHI2NEXTBEST", &J_psi_1S_MINIPCHI2NEXTBEST, &b_J_psi_1S_MINIPCHI2NEXTBEST);
   fChain->SetBranchAddress("J_psi_1S_ENDVERTEX_X", &J_psi_1S_ENDVERTEX_X, &b_J_psi_1S_ENDVERTEX_X);
   fChain->SetBranchAddress("J_psi_1S_ENDVERTEX_Y", &J_psi_1S_ENDVERTEX_Y, &b_J_psi_1S_ENDVERTEX_Y);
   fChain->SetBranchAddress("J_psi_1S_ENDVERTEX_Z", &J_psi_1S_ENDVERTEX_Z, &b_J_psi_1S_ENDVERTEX_Z);
   fChain->SetBranchAddress("J_psi_1S_ENDVERTEX_XERR", &J_psi_1S_ENDVERTEX_XERR, &b_J_psi_1S_ENDVERTEX_XERR);
   fChain->SetBranchAddress("J_psi_1S_ENDVERTEX_YERR", &J_psi_1S_ENDVERTEX_YERR, &b_J_psi_1S_ENDVERTEX_YERR);
   fChain->SetBranchAddress("J_psi_1S_ENDVERTEX_ZERR", &J_psi_1S_ENDVERTEX_ZERR, &b_J_psi_1S_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("J_psi_1S_ENDVERTEX_CHI2", &J_psi_1S_ENDVERTEX_CHI2, &b_J_psi_1S_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("J_psi_1S_ENDVERTEX_NDOF", &J_psi_1S_ENDVERTEX_NDOF, &b_J_psi_1S_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("J_psi_1S_ENDVERTEX_COV_", J_psi_1S_ENDVERTEX_COV_, &b_J_psi_1S_ENDVERTEX_COV_);
   fChain->SetBranchAddress("J_psi_1S_OWNPV_X", &J_psi_1S_OWNPV_X, &b_J_psi_1S_OWNPV_X);
   fChain->SetBranchAddress("J_psi_1S_OWNPV_Y", &J_psi_1S_OWNPV_Y, &b_J_psi_1S_OWNPV_Y);
   fChain->SetBranchAddress("J_psi_1S_OWNPV_Z", &J_psi_1S_OWNPV_Z, &b_J_psi_1S_OWNPV_Z);
   fChain->SetBranchAddress("J_psi_1S_OWNPV_XERR", &J_psi_1S_OWNPV_XERR, &b_J_psi_1S_OWNPV_XERR);
   fChain->SetBranchAddress("J_psi_1S_OWNPV_YERR", &J_psi_1S_OWNPV_YERR, &b_J_psi_1S_OWNPV_YERR);
   fChain->SetBranchAddress("J_psi_1S_OWNPV_ZERR", &J_psi_1S_OWNPV_ZERR, &b_J_psi_1S_OWNPV_ZERR);
   fChain->SetBranchAddress("J_psi_1S_OWNPV_CHI2", &J_psi_1S_OWNPV_CHI2, &b_J_psi_1S_OWNPV_CHI2);
   fChain->SetBranchAddress("J_psi_1S_OWNPV_NDOF", &J_psi_1S_OWNPV_NDOF, &b_J_psi_1S_OWNPV_NDOF);
   fChain->SetBranchAddress("J_psi_1S_OWNPV_COV_", J_psi_1S_OWNPV_COV_, &b_J_psi_1S_OWNPV_COV_);
   fChain->SetBranchAddress("J_psi_1S_IP_OWNPV", &J_psi_1S_IP_OWNPV, &b_J_psi_1S_IP_OWNPV);
   fChain->SetBranchAddress("J_psi_1S_IPCHI2_OWNPV", &J_psi_1S_IPCHI2_OWNPV, &b_J_psi_1S_IPCHI2_OWNPV);
   fChain->SetBranchAddress("J_psi_1S_FD_OWNPV", &J_psi_1S_FD_OWNPV, &b_J_psi_1S_FD_OWNPV);
   fChain->SetBranchAddress("J_psi_1S_FDCHI2_OWNPV", &J_psi_1S_FDCHI2_OWNPV, &b_J_psi_1S_FDCHI2_OWNPV);
   fChain->SetBranchAddress("J_psi_1S_DIRA_OWNPV", &J_psi_1S_DIRA_OWNPV, &b_J_psi_1S_DIRA_OWNPV);
   fChain->SetBranchAddress("J_psi_1S_TOPPV_X", &J_psi_1S_TOPPV_X, &b_J_psi_1S_TOPPV_X);
   fChain->SetBranchAddress("J_psi_1S_TOPPV_Y", &J_psi_1S_TOPPV_Y, &b_J_psi_1S_TOPPV_Y);
   fChain->SetBranchAddress("J_psi_1S_TOPPV_Z", &J_psi_1S_TOPPV_Z, &b_J_psi_1S_TOPPV_Z);
   fChain->SetBranchAddress("J_psi_1S_TOPPV_XERR", &J_psi_1S_TOPPV_XERR, &b_J_psi_1S_TOPPV_XERR);
   fChain->SetBranchAddress("J_psi_1S_TOPPV_YERR", &J_psi_1S_TOPPV_YERR, &b_J_psi_1S_TOPPV_YERR);
   fChain->SetBranchAddress("J_psi_1S_TOPPV_ZERR", &J_psi_1S_TOPPV_ZERR, &b_J_psi_1S_TOPPV_ZERR);
   fChain->SetBranchAddress("J_psi_1S_TOPPV_CHI2", &J_psi_1S_TOPPV_CHI2, &b_J_psi_1S_TOPPV_CHI2);
   fChain->SetBranchAddress("J_psi_1S_TOPPV_NDOF", &J_psi_1S_TOPPV_NDOF, &b_J_psi_1S_TOPPV_NDOF);
   fChain->SetBranchAddress("J_psi_1S_TOPPV_COV_", J_psi_1S_TOPPV_COV_, &b_J_psi_1S_TOPPV_COV_);
   fChain->SetBranchAddress("J_psi_1S_IP_TOPPV", &J_psi_1S_IP_TOPPV, &b_J_psi_1S_IP_TOPPV);
   fChain->SetBranchAddress("J_psi_1S_IPCHI2_TOPPV", &J_psi_1S_IPCHI2_TOPPV, &b_J_psi_1S_IPCHI2_TOPPV);
   fChain->SetBranchAddress("J_psi_1S_FD_TOPPV", &J_psi_1S_FD_TOPPV, &b_J_psi_1S_FD_TOPPV);
   fChain->SetBranchAddress("J_psi_1S_FDCHI2_TOPPV", &J_psi_1S_FDCHI2_TOPPV, &b_J_psi_1S_FDCHI2_TOPPV);
   fChain->SetBranchAddress("J_psi_1S_DIRA_TOPPV", &J_psi_1S_DIRA_TOPPV, &b_J_psi_1S_DIRA_TOPPV);
   fChain->SetBranchAddress("J_psi_1S_ORIVX_X", &J_psi_1S_ORIVX_X, &b_J_psi_1S_ORIVX_X);
   fChain->SetBranchAddress("J_psi_1S_ORIVX_Y", &J_psi_1S_ORIVX_Y, &b_J_psi_1S_ORIVX_Y);
   fChain->SetBranchAddress("J_psi_1S_ORIVX_Z", &J_psi_1S_ORIVX_Z, &b_J_psi_1S_ORIVX_Z);
   fChain->SetBranchAddress("J_psi_1S_ORIVX_XERR", &J_psi_1S_ORIVX_XERR, &b_J_psi_1S_ORIVX_XERR);
   fChain->SetBranchAddress("J_psi_1S_ORIVX_YERR", &J_psi_1S_ORIVX_YERR, &b_J_psi_1S_ORIVX_YERR);
   fChain->SetBranchAddress("J_psi_1S_ORIVX_ZERR", &J_psi_1S_ORIVX_ZERR, &b_J_psi_1S_ORIVX_ZERR);
   fChain->SetBranchAddress("J_psi_1S_ORIVX_CHI2", &J_psi_1S_ORIVX_CHI2, &b_J_psi_1S_ORIVX_CHI2);
   fChain->SetBranchAddress("J_psi_1S_ORIVX_NDOF", &J_psi_1S_ORIVX_NDOF, &b_J_psi_1S_ORIVX_NDOF);
   fChain->SetBranchAddress("J_psi_1S_ORIVX_COV_", J_psi_1S_ORIVX_COV_, &b_J_psi_1S_ORIVX_COV_);
   fChain->SetBranchAddress("J_psi_1S_IP_ORIVX", &J_psi_1S_IP_ORIVX, &b_J_psi_1S_IP_ORIVX);
   fChain->SetBranchAddress("J_psi_1S_IPCHI2_ORIVX", &J_psi_1S_IPCHI2_ORIVX, &b_J_psi_1S_IPCHI2_ORIVX);
   fChain->SetBranchAddress("J_psi_1S_FD_ORIVX", &J_psi_1S_FD_ORIVX, &b_J_psi_1S_FD_ORIVX);
   fChain->SetBranchAddress("J_psi_1S_FDCHI2_ORIVX", &J_psi_1S_FDCHI2_ORIVX, &b_J_psi_1S_FDCHI2_ORIVX);
   fChain->SetBranchAddress("J_psi_1S_DIRA_ORIVX", &J_psi_1S_DIRA_ORIVX, &b_J_psi_1S_DIRA_ORIVX);
   fChain->SetBranchAddress("J_psi_1S_P", &J_psi_1S_P, &b_J_psi_1S_P);
   fChain->SetBranchAddress("J_psi_1S_PT", &J_psi_1S_PT, &b_J_psi_1S_PT);
   fChain->SetBranchAddress("J_psi_1S_PE", &J_psi_1S_PE, &b_J_psi_1S_PE);
   fChain->SetBranchAddress("J_psi_1S_PX", &J_psi_1S_PX, &b_J_psi_1S_PX);
   fChain->SetBranchAddress("J_psi_1S_PY", &J_psi_1S_PY, &b_J_psi_1S_PY);
   fChain->SetBranchAddress("J_psi_1S_PZ", &J_psi_1S_PZ, &b_J_psi_1S_PZ);
   fChain->SetBranchAddress("J_psi_1S_MM", &J_psi_1S_MM, &b_J_psi_1S_MM);
   fChain->SetBranchAddress("J_psi_1S_MMERR", &J_psi_1S_MMERR, &b_J_psi_1S_MMERR);
   fChain->SetBranchAddress("J_psi_1S_M", &J_psi_1S_M, &b_J_psi_1S_M);
   fChain->SetBranchAddress("J_psi_1S_ID", &J_psi_1S_ID, &b_J_psi_1S_ID);
   fChain->SetBranchAddress("J_psi_1SL0Global_Dec", &J_psi_1SL0Global_Dec, &b_J_psi_1SL0Global_Dec);
   fChain->SetBranchAddress("J_psi_1SL0Global_TIS", &J_psi_1SL0Global_TIS, &b_J_psi_1SL0Global_TIS);
   fChain->SetBranchAddress("J_psi_1SL0Global_TOS", &J_psi_1SL0Global_TOS, &b_J_psi_1SL0Global_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt1Global_Dec", &J_psi_1SHlt1Global_Dec, &b_J_psi_1SHlt1Global_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt1Global_TIS", &J_psi_1SHlt1Global_TIS, &b_J_psi_1SHlt1Global_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt1Global_TOS", &J_psi_1SHlt1Global_TOS, &b_J_psi_1SHlt1Global_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt1Phys_Dec", &J_psi_1SHlt1Phys_Dec, &b_J_psi_1SHlt1Phys_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt1Phys_TIS", &J_psi_1SHlt1Phys_TIS, &b_J_psi_1SHlt1Phys_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt1Phys_TOS", &J_psi_1SHlt1Phys_TOS, &b_J_psi_1SHlt1Phys_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2Global_Dec", &J_psi_1SHlt2Global_Dec, &b_J_psi_1SHlt2Global_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2Global_TIS", &J_psi_1SHlt2Global_TIS, &b_J_psi_1SHlt2Global_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2Global_TOS", &J_psi_1SHlt2Global_TOS, &b_J_psi_1SHlt2Global_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2Phys_Dec", &J_psi_1SHlt2Phys_Dec, &b_J_psi_1SHlt2Phys_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2Phys_TIS", &J_psi_1SHlt2Phys_TIS, &b_J_psi_1SHlt2Phys_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2Phys_TOS", &J_psi_1SHlt2Phys_TOS, &b_J_psi_1SHlt2Phys_TOS);
   fChain->SetBranchAddress("J_psi_1SStrippingGlobal_Dec", &J_psi_1SStrippingGlobal_Dec, &b_J_psi_1SStrippingGlobal_Dec);
   fChain->SetBranchAddress("J_psi_1SStrippingGlobal_TIS", &J_psi_1SStrippingGlobal_TIS, &b_J_psi_1SStrippingGlobal_TIS);
   fChain->SetBranchAddress("J_psi_1SStrippingGlobal_TOS", &J_psi_1SStrippingGlobal_TOS, &b_J_psi_1SStrippingGlobal_TOS);
   fChain->SetBranchAddress("J_psi_1SL0DiMuonDecision_Dec", &J_psi_1SL0DiMuonDecision_Dec, &b_J_psi_1SL0DiMuonDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SL0DiMuonDecision_TIS", &J_psi_1SL0DiMuonDecision_TIS, &b_J_psi_1SL0DiMuonDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SL0DiMuonDecision_TOS", &J_psi_1SL0DiMuonDecision_TOS, &b_J_psi_1SL0DiMuonDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SL0HCALDecision_Dec", &J_psi_1SL0HCALDecision_Dec, &b_J_psi_1SL0HCALDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SL0HCALDecision_TIS", &J_psi_1SL0HCALDecision_TIS, &b_J_psi_1SL0HCALDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SL0HCALDecision_TOS", &J_psi_1SL0HCALDecision_TOS, &b_J_psi_1SL0HCALDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SL0MuonDecision_Dec", &J_psi_1SL0MuonDecision_Dec, &b_J_psi_1SL0MuonDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SL0MuonDecision_TIS", &J_psi_1SL0MuonDecision_TIS, &b_J_psi_1SL0MuonDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SL0MuonDecision_TOS", &J_psi_1SL0MuonDecision_TOS, &b_J_psi_1SL0MuonDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SL0MuonHighDecision_Dec", &J_psi_1SL0MuonHighDecision_Dec, &b_J_psi_1SL0MuonHighDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SL0MuonHighDecision_TIS", &J_psi_1SL0MuonHighDecision_TIS, &b_J_psi_1SL0MuonHighDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SL0MuonHighDecision_TOS", &J_psi_1SL0MuonHighDecision_TOS, &b_J_psi_1SL0MuonHighDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt1SingleMuonNoIPL0Decision_Dec", &J_psi_1SHlt1SingleMuonNoIPL0Decision_Dec, &b_J_psi_1SHlt1SingleMuonNoIPL0Decision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt1SingleMuonNoIPL0Decision_TIS", &J_psi_1SHlt1SingleMuonNoIPL0Decision_TIS, &b_J_psi_1SHlt1SingleMuonNoIPL0Decision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt1SingleMuonNoIPL0Decision_TOS", &J_psi_1SHlt1SingleMuonNoIPL0Decision_TOS, &b_J_psi_1SHlt1SingleMuonNoIPL0Decision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt1DiMuonHighMassDecision_Dec", &J_psi_1SHlt1DiMuonHighMassDecision_Dec, &b_J_psi_1SHlt1DiMuonHighMassDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt1DiMuonHighMassDecision_TIS", &J_psi_1SHlt1DiMuonHighMassDecision_TIS, &b_J_psi_1SHlt1DiMuonHighMassDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt1DiMuonHighMassDecision_TOS", &J_psi_1SHlt1DiMuonHighMassDecision_TOS, &b_J_psi_1SHlt1DiMuonHighMassDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt1DiMuonLowMassDecision_Dec", &J_psi_1SHlt1DiMuonLowMassDecision_Dec, &b_J_psi_1SHlt1DiMuonLowMassDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt1DiMuonLowMassDecision_TIS", &J_psi_1SHlt1DiMuonLowMassDecision_TIS, &b_J_psi_1SHlt1DiMuonLowMassDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt1DiMuonLowMassDecision_TOS", &J_psi_1SHlt1DiMuonLowMassDecision_TOS, &b_J_psi_1SHlt1DiMuonLowMassDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt1SingleMuonHighPTDecision_Dec", &J_psi_1SHlt1SingleMuonHighPTDecision_Dec, &b_J_psi_1SHlt1SingleMuonHighPTDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt1SingleMuonHighPTDecision_TIS", &J_psi_1SHlt1SingleMuonHighPTDecision_TIS, &b_J_psi_1SHlt1SingleMuonHighPTDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt1SingleMuonHighPTDecision_TOS", &J_psi_1SHlt1SingleMuonHighPTDecision_TOS, &b_J_psi_1SHlt1SingleMuonHighPTDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt1SingleMuonNoIPDecision_Dec", &J_psi_1SHlt1SingleMuonNoIPDecision_Dec, &b_J_psi_1SHlt1SingleMuonNoIPDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt1SingleMuonNoIPDecision_TIS", &J_psi_1SHlt1SingleMuonNoIPDecision_TIS, &b_J_psi_1SHlt1SingleMuonNoIPDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt1SingleMuonNoIPDecision_TOS", &J_psi_1SHlt1SingleMuonNoIPDecision_TOS, &b_J_psi_1SHlt1SingleMuonNoIPDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt1TrackAllL0Decision_Dec", &J_psi_1SHlt1TrackAllL0Decision_Dec, &b_J_psi_1SHlt1TrackAllL0Decision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt1TrackAllL0Decision_TIS", &J_psi_1SHlt1TrackAllL0Decision_TIS, &b_J_psi_1SHlt1TrackAllL0Decision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt1TrackAllL0Decision_TOS", &J_psi_1SHlt1TrackAllL0Decision_TOS, &b_J_psi_1SHlt1TrackAllL0Decision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt1TrackMuonDecision_Dec", &J_psi_1SHlt1TrackMuonDecision_Dec, &b_J_psi_1SHlt1TrackMuonDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt1TrackMuonDecision_TIS", &J_psi_1SHlt1TrackMuonDecision_TIS, &b_J_psi_1SHlt1TrackMuonDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt1TrackMuonDecision_TOS", &J_psi_1SHlt1TrackMuonDecision_TOS, &b_J_psi_1SHlt1TrackMuonDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonBDecision_Dec", &J_psi_1SHlt2DiMuonBDecision_Dec, &b_J_psi_1SHlt2DiMuonBDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonBDecision_TIS", &J_psi_1SHlt2DiMuonBDecision_TIS, &b_J_psi_1SHlt2DiMuonBDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonBDecision_TOS", &J_psi_1SHlt2DiMuonBDecision_TOS, &b_J_psi_1SHlt2DiMuonBDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDecision_Dec", &J_psi_1SHlt2DiMuonDecision_Dec, &b_J_psi_1SHlt2DiMuonDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDecision_TIS", &J_psi_1SHlt2DiMuonDecision_TIS, &b_J_psi_1SHlt2DiMuonDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDecision_TOS", &J_psi_1SHlt2DiMuonDecision_TOS, &b_J_psi_1SHlt2DiMuonDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDY1Decision_Dec", &J_psi_1SHlt2DiMuonDY1Decision_Dec, &b_J_psi_1SHlt2DiMuonDY1Decision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDY1Decision_TIS", &J_psi_1SHlt2DiMuonDY1Decision_TIS, &b_J_psi_1SHlt2DiMuonDY1Decision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDY1Decision_TOS", &J_psi_1SHlt2DiMuonDY1Decision_TOS, &b_J_psi_1SHlt2DiMuonDY1Decision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDetachedDecision_Dec", &J_psi_1SHlt2DiMuonDetachedDecision_Dec, &b_J_psi_1SHlt2DiMuonDetachedDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDetachedDecision_TIS", &J_psi_1SHlt2DiMuonDetachedDecision_TIS, &b_J_psi_1SHlt2DiMuonDetachedDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDetachedDecision_TOS", &J_psi_1SHlt2DiMuonDetachedDecision_TOS, &b_J_psi_1SHlt2DiMuonDetachedDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDetachedHeavyDecision_Dec", &J_psi_1SHlt2DiMuonDetachedHeavyDecision_Dec, &b_J_psi_1SHlt2DiMuonDetachedHeavyDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDetachedHeavyDecision_TIS", &J_psi_1SHlt2DiMuonDetachedHeavyDecision_TIS, &b_J_psi_1SHlt2DiMuonDetachedHeavyDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDetachedHeavyDecision_TOS", &J_psi_1SHlt2DiMuonDetachedHeavyDecision_TOS, &b_J_psi_1SHlt2DiMuonDetachedHeavyDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDetachedJPsiDecision_Dec", &J_psi_1SHlt2DiMuonDetachedJPsiDecision_Dec, &b_J_psi_1SHlt2DiMuonDetachedJPsiDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDetachedJPsiDecision_TIS", &J_psi_1SHlt2DiMuonDetachedJPsiDecision_TIS, &b_J_psi_1SHlt2DiMuonDetachedJPsiDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonDetachedJPsiDecision_TOS", &J_psi_1SHlt2DiMuonDetachedJPsiDecision_TOS, &b_J_psi_1SHlt2DiMuonDetachedJPsiDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonJPsiDecision_Dec", &J_psi_1SHlt2DiMuonJPsiDecision_Dec, &b_J_psi_1SHlt2DiMuonJPsiDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonJPsiDecision_TIS", &J_psi_1SHlt2DiMuonJPsiDecision_TIS, &b_J_psi_1SHlt2DiMuonJPsiDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonJPsiDecision_TOS", &J_psi_1SHlt2DiMuonJPsiDecision_TOS, &b_J_psi_1SHlt2DiMuonJPsiDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonJPsiHighPTDecision_Dec", &J_psi_1SHlt2DiMuonJPsiHighPTDecision_Dec, &b_J_psi_1SHlt2DiMuonJPsiHighPTDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonJPsiHighPTDecision_TIS", &J_psi_1SHlt2DiMuonJPsiHighPTDecision_TIS, &b_J_psi_1SHlt2DiMuonJPsiHighPTDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonJPsiHighPTDecision_TOS", &J_psi_1SHlt2DiMuonJPsiHighPTDecision_TOS, &b_J_psi_1SHlt2DiMuonJPsiHighPTDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2ExpressJPsiDecision_Dec", &J_psi_1SHlt2ExpressJPsiDecision_Dec, &b_J_psi_1SHlt2ExpressJPsiDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2ExpressJPsiDecision_TIS", &J_psi_1SHlt2ExpressJPsiDecision_TIS, &b_J_psi_1SHlt2ExpressJPsiDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2ExpressJPsiDecision_TOS", &J_psi_1SHlt2ExpressJPsiDecision_TOS, &b_J_psi_1SHlt2ExpressJPsiDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2ExpressJPsiTagProbeDecision_Dec", &J_psi_1SHlt2ExpressJPsiTagProbeDecision_Dec, &b_J_psi_1SHlt2ExpressJPsiTagProbeDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2ExpressJPsiTagProbeDecision_TIS", &J_psi_1SHlt2ExpressJPsiTagProbeDecision_TIS, &b_J_psi_1SHlt2ExpressJPsiTagProbeDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2ExpressJPsiTagProbeDecision_TOS", &J_psi_1SHlt2ExpressJPsiTagProbeDecision_TOS, &b_J_psi_1SHlt2ExpressJPsiTagProbeDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2SingleMuonDecision_Dec", &J_psi_1SHlt2SingleMuonDecision_Dec, &b_J_psi_1SHlt2SingleMuonDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2SingleMuonDecision_TIS", &J_psi_1SHlt2SingleMuonDecision_TIS, &b_J_psi_1SHlt2SingleMuonDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2SingleMuonDecision_TOS", &J_psi_1SHlt2SingleMuonDecision_TOS, &b_J_psi_1SHlt2SingleMuonDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2SingleMuonHighPTDecision_Dec", &J_psi_1SHlt2SingleMuonHighPTDecision_Dec, &b_J_psi_1SHlt2SingleMuonHighPTDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2SingleMuonHighPTDecision_TIS", &J_psi_1SHlt2SingleMuonHighPTDecision_TIS, &b_J_psi_1SHlt2SingleMuonHighPTDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2SingleMuonHighPTDecision_TOS", &J_psi_1SHlt2SingleMuonHighPTDecision_TOS, &b_J_psi_1SHlt2SingleMuonHighPTDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2SingleMuonLowPTDecision_Dec", &J_psi_1SHlt2SingleMuonLowPTDecision_Dec, &b_J_psi_1SHlt2SingleMuonLowPTDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2SingleMuonLowPTDecision_TIS", &J_psi_1SHlt2SingleMuonLowPTDecision_TIS, &b_J_psi_1SHlt2SingleMuonLowPTDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2SingleMuonLowPTDecision_TOS", &J_psi_1SHlt2SingleMuonLowPTDecision_TOS, &b_J_psi_1SHlt2SingleMuonLowPTDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo2BodyBBDTDecision_Dec", &J_psi_1SHlt2Topo2BodyBBDTDecision_Dec, &b_J_psi_1SHlt2Topo2BodyBBDTDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo2BodyBBDTDecision_TIS", &J_psi_1SHlt2Topo2BodyBBDTDecision_TIS, &b_J_psi_1SHlt2Topo2BodyBBDTDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo2BodyBBDTDecision_TOS", &J_psi_1SHlt2Topo2BodyBBDTDecision_TOS, &b_J_psi_1SHlt2Topo2BodyBBDTDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo2BodySimpleDecision_Dec", &J_psi_1SHlt2Topo2BodySimpleDecision_Dec, &b_J_psi_1SHlt2Topo2BodySimpleDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo2BodySimpleDecision_TIS", &J_psi_1SHlt2Topo2BodySimpleDecision_TIS, &b_J_psi_1SHlt2Topo2BodySimpleDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo2BodySimpleDecision_TOS", &J_psi_1SHlt2Topo2BodySimpleDecision_TOS, &b_J_psi_1SHlt2Topo2BodySimpleDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo3BodyBBDTDecision_Dec", &J_psi_1SHlt2Topo3BodyBBDTDecision_Dec, &b_J_psi_1SHlt2Topo3BodyBBDTDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo3BodyBBDTDecision_TIS", &J_psi_1SHlt2Topo3BodyBBDTDecision_TIS, &b_J_psi_1SHlt2Topo3BodyBBDTDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo3BodyBBDTDecision_TOS", &J_psi_1SHlt2Topo3BodyBBDTDecision_TOS, &b_J_psi_1SHlt2Topo3BodyBBDTDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo3BodySimpleDecision_Dec", &J_psi_1SHlt2Topo3BodySimpleDecision_Dec, &b_J_psi_1SHlt2Topo3BodySimpleDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo3BodySimpleDecision_TIS", &J_psi_1SHlt2Topo3BodySimpleDecision_TIS, &b_J_psi_1SHlt2Topo3BodySimpleDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo3BodySimpleDecision_TOS", &J_psi_1SHlt2Topo3BodySimpleDecision_TOS, &b_J_psi_1SHlt2Topo3BodySimpleDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo4BodyBBDTDecision_Dec", &J_psi_1SHlt2Topo4BodyBBDTDecision_Dec, &b_J_psi_1SHlt2Topo4BodyBBDTDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo4BodyBBDTDecision_TIS", &J_psi_1SHlt2Topo4BodyBBDTDecision_TIS, &b_J_psi_1SHlt2Topo4BodyBBDTDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo4BodyBBDTDecision_TOS", &J_psi_1SHlt2Topo4BodyBBDTDecision_TOS, &b_J_psi_1SHlt2Topo4BodyBBDTDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo4BodySimpleDecision_Dec", &J_psi_1SHlt2Topo4BodySimpleDecision_Dec, &b_J_psi_1SHlt2Topo4BodySimpleDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo4BodySimpleDecision_TIS", &J_psi_1SHlt2Topo4BodySimpleDecision_TIS, &b_J_psi_1SHlt2Topo4BodySimpleDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2Topo4BodySimpleDecision_TOS", &J_psi_1SHlt2Topo4BodySimpleDecision_TOS, &b_J_psi_1SHlt2Topo4BodySimpleDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2TopoMu2BodyBBDTDecision_Dec", &J_psi_1SHlt2TopoMu2BodyBBDTDecision_Dec, &b_J_psi_1SHlt2TopoMu2BodyBBDTDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2TopoMu2BodyBBDTDecision_TIS", &J_psi_1SHlt2TopoMu2BodyBBDTDecision_TIS, &b_J_psi_1SHlt2TopoMu2BodyBBDTDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2TopoMu2BodyBBDTDecision_TOS", &J_psi_1SHlt2TopoMu2BodyBBDTDecision_TOS, &b_J_psi_1SHlt2TopoMu2BodyBBDTDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2TopoMu3BodyBBDTDecision_Dec", &J_psi_1SHlt2TopoMu3BodyBBDTDecision_Dec, &b_J_psi_1SHlt2TopoMu3BodyBBDTDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2TopoMu3BodyBBDTDecision_TIS", &J_psi_1SHlt2TopoMu3BodyBBDTDecision_TIS, &b_J_psi_1SHlt2TopoMu3BodyBBDTDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2TopoMu3BodyBBDTDecision_TOS", &J_psi_1SHlt2TopoMu3BodyBBDTDecision_TOS, &b_J_psi_1SHlt2TopoMu3BodyBBDTDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2TopoMu4BodyBBDTDecision_Dec", &J_psi_1SHlt2TopoMu4BodyBBDTDecision_Dec, &b_J_psi_1SHlt2TopoMu4BodyBBDTDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2TopoMu4BodyBBDTDecision_TIS", &J_psi_1SHlt2TopoMu4BodyBBDTDecision_TIS, &b_J_psi_1SHlt2TopoMu4BodyBBDTDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2TopoMu4BodyBBDTDecision_TOS", &J_psi_1SHlt2TopoMu4BodyBBDTDecision_TOS, &b_J_psi_1SHlt2TopoMu4BodyBBDTDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2TransparentDecision_Dec", &J_psi_1SHlt2TransparentDecision_Dec, &b_J_psi_1SHlt2TransparentDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2TransparentDecision_TIS", &J_psi_1SHlt2TransparentDecision_TIS, &b_J_psi_1SHlt2TransparentDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2TransparentDecision_TOS", &J_psi_1SHlt2TransparentDecision_TOS, &b_J_psi_1SHlt2TransparentDecision_TOS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_Dec", &J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_Dec, &b_J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_Dec);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_TIS", &J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_TIS, &b_J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_TIS);
   fChain->SetBranchAddress("J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_TOS", &J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_TOS, &b_J_psi_1SHlt2DiMuonUnbiasedJPsiDecision_TOS);
   fChain->SetBranchAddress("muminus_MINIP", &muminus_MINIP, &b_muminus_MINIP);
   fChain->SetBranchAddress("muminus_MINIPCHI2", &muminus_MINIPCHI2, &b_muminus_MINIPCHI2);
   fChain->SetBranchAddress("muminus_MINIPNEXTBEST", &muminus_MINIPNEXTBEST, &b_muminus_MINIPNEXTBEST);
   fChain->SetBranchAddress("muminus_MINIPCHI2NEXTBEST", &muminus_MINIPCHI2NEXTBEST, &b_muminus_MINIPCHI2NEXTBEST);
   fChain->SetBranchAddress("muminus_OWNPV_X", &muminus_OWNPV_X, &b_muminus_OWNPV_X);
   fChain->SetBranchAddress("muminus_OWNPV_Y", &muminus_OWNPV_Y, &b_muminus_OWNPV_Y);
   fChain->SetBranchAddress("muminus_OWNPV_Z", &muminus_OWNPV_Z, &b_muminus_OWNPV_Z);
   fChain->SetBranchAddress("muminus_OWNPV_XERR", &muminus_OWNPV_XERR, &b_muminus_OWNPV_XERR);
   fChain->SetBranchAddress("muminus_OWNPV_YERR", &muminus_OWNPV_YERR, &b_muminus_OWNPV_YERR);
   fChain->SetBranchAddress("muminus_OWNPV_ZERR", &muminus_OWNPV_ZERR, &b_muminus_OWNPV_ZERR);
   fChain->SetBranchAddress("muminus_OWNPV_CHI2", &muminus_OWNPV_CHI2, &b_muminus_OWNPV_CHI2);
   fChain->SetBranchAddress("muminus_OWNPV_NDOF", &muminus_OWNPV_NDOF, &b_muminus_OWNPV_NDOF);
   fChain->SetBranchAddress("muminus_OWNPV_COV_", muminus_OWNPV_COV_, &b_muminus_OWNPV_COV_);
   fChain->SetBranchAddress("muminus_IP_OWNPV", &muminus_IP_OWNPV, &b_muminus_IP_OWNPV);
   fChain->SetBranchAddress("muminus_IPCHI2_OWNPV", &muminus_IPCHI2_OWNPV, &b_muminus_IPCHI2_OWNPV);
   fChain->SetBranchAddress("muminus_TOPPV_X", &muminus_TOPPV_X, &b_muminus_TOPPV_X);
   fChain->SetBranchAddress("muminus_TOPPV_Y", &muminus_TOPPV_Y, &b_muminus_TOPPV_Y);
   fChain->SetBranchAddress("muminus_TOPPV_Z", &muminus_TOPPV_Z, &b_muminus_TOPPV_Z);
   fChain->SetBranchAddress("muminus_TOPPV_XERR", &muminus_TOPPV_XERR, &b_muminus_TOPPV_XERR);
   fChain->SetBranchAddress("muminus_TOPPV_YERR", &muminus_TOPPV_YERR, &b_muminus_TOPPV_YERR);
   fChain->SetBranchAddress("muminus_TOPPV_ZERR", &muminus_TOPPV_ZERR, &b_muminus_TOPPV_ZERR);
   fChain->SetBranchAddress("muminus_TOPPV_CHI2", &muminus_TOPPV_CHI2, &b_muminus_TOPPV_CHI2);
   fChain->SetBranchAddress("muminus_TOPPV_NDOF", &muminus_TOPPV_NDOF, &b_muminus_TOPPV_NDOF);
   fChain->SetBranchAddress("muminus_TOPPV_COV_", muminus_TOPPV_COV_, &b_muminus_TOPPV_COV_);
   fChain->SetBranchAddress("muminus_IP_TOPPV", &muminus_IP_TOPPV, &b_muminus_IP_TOPPV);
   fChain->SetBranchAddress("muminus_IPCHI2_TOPPV", &muminus_IPCHI2_TOPPV, &b_muminus_IPCHI2_TOPPV);
   fChain->SetBranchAddress("muminus_ORIVX_X", &muminus_ORIVX_X, &b_muminus_ORIVX_X);
   fChain->SetBranchAddress("muminus_ORIVX_Y", &muminus_ORIVX_Y, &b_muminus_ORIVX_Y);
   fChain->SetBranchAddress("muminus_ORIVX_Z", &muminus_ORIVX_Z, &b_muminus_ORIVX_Z);
   fChain->SetBranchAddress("muminus_ORIVX_XERR", &muminus_ORIVX_XERR, &b_muminus_ORIVX_XERR);
   fChain->SetBranchAddress("muminus_ORIVX_YERR", &muminus_ORIVX_YERR, &b_muminus_ORIVX_YERR);
   fChain->SetBranchAddress("muminus_ORIVX_ZERR", &muminus_ORIVX_ZERR, &b_muminus_ORIVX_ZERR);
   fChain->SetBranchAddress("muminus_ORIVX_CHI2", &muminus_ORIVX_CHI2, &b_muminus_ORIVX_CHI2);
   fChain->SetBranchAddress("muminus_ORIVX_NDOF", &muminus_ORIVX_NDOF, &b_muminus_ORIVX_NDOF);
   fChain->SetBranchAddress("muminus_ORIVX_COV_", muminus_ORIVX_COV_, &b_muminus_ORIVX_COV_);
   fChain->SetBranchAddress("muminus_IP_ORIVX", &muminus_IP_ORIVX, &b_muminus_IP_ORIVX);
   fChain->SetBranchAddress("muminus_IPCHI2_ORIVX", &muminus_IPCHI2_ORIVX, &b_muminus_IPCHI2_ORIVX);
   fChain->SetBranchAddress("muminus_P", &muminus_P, &b_muminus_P);
   fChain->SetBranchAddress("muminus_PT", &muminus_PT, &b_muminus_PT);
   fChain->SetBranchAddress("muminus_PE", &muminus_PE, &b_muminus_PE);
   fChain->SetBranchAddress("muminus_PX", &muminus_PX, &b_muminus_PX);
   fChain->SetBranchAddress("muminus_PY", &muminus_PY, &b_muminus_PY);
   fChain->SetBranchAddress("muminus_PZ", &muminus_PZ, &b_muminus_PZ);
   fChain->SetBranchAddress("muminus_M", &muminus_M, &b_muminus_M);
   fChain->SetBranchAddress("muminus_ID", &muminus_ID, &b_muminus_ID);
   fChain->SetBranchAddress("muminus_PIDe", &muminus_PIDe, &b_muminus_PIDe);
   fChain->SetBranchAddress("muminus_PIDmu", &muminus_PIDmu, &b_muminus_PIDmu);
   fChain->SetBranchAddress("muminus_PIDK", &muminus_PIDK, &b_muminus_PIDK);
   fChain->SetBranchAddress("muminus_PIDp", &muminus_PIDp, &b_muminus_PIDp);
   fChain->SetBranchAddress("muminus_ProbNNe", &muminus_ProbNNe, &b_muminus_ProbNNe);
   fChain->SetBranchAddress("muminus_ProbNNk", &muminus_ProbNNk, &b_muminus_ProbNNk);
   fChain->SetBranchAddress("muminus_ProbNNp", &muminus_ProbNNp, &b_muminus_ProbNNp);
   fChain->SetBranchAddress("muminus_ProbNNpi", &muminus_ProbNNpi, &b_muminus_ProbNNpi);
   fChain->SetBranchAddress("muminus_ProbNNmu", &muminus_ProbNNmu, &b_muminus_ProbNNmu);
   fChain->SetBranchAddress("muminus_ProbNNghost", &muminus_ProbNNghost, &b_muminus_ProbNNghost);
   fChain->SetBranchAddress("muminus_hasMuon", &muminus_hasMuon, &b_muminus_hasMuon);
   fChain->SetBranchAddress("muminus_isMuon", &muminus_isMuon, &b_muminus_isMuon);
   fChain->SetBranchAddress("muminus_hasRich", &muminus_hasRich, &b_muminus_hasRich);
   fChain->SetBranchAddress("muminus_hasCalo", &muminus_hasCalo, &b_muminus_hasCalo);
   fChain->SetBranchAddress("muminus_TRACK_Type", &muminus_TRACK_Type, &b_muminus_TRACK_Type);
   fChain->SetBranchAddress("muminus_TRACK_Key", &muminus_TRACK_Key, &b_muminus_TRACK_Key);
   fChain->SetBranchAddress("muminus_TRACK_CHI2NDOF", &muminus_TRACK_CHI2NDOF, &b_muminus_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("muminus_TRACK_PCHI2", &muminus_TRACK_PCHI2, &b_muminus_TRACK_PCHI2);
   fChain->SetBranchAddress("muminus_TRACK_MatchCHI2", &muminus_TRACK_MatchCHI2, &b_muminus_TRACK_MatchCHI2);
   fChain->SetBranchAddress("muminus_TRACK_GhostProb", &muminus_TRACK_GhostProb, &b_muminus_TRACK_GhostProb);
   fChain->SetBranchAddress("muminus_TRACK_CloneDist", &muminus_TRACK_CloneDist, &b_muminus_TRACK_CloneDist);
   fChain->SetBranchAddress("muminus_TRACK_Likelihood", &muminus_TRACK_Likelihood, &b_muminus_TRACK_Likelihood);
   fChain->SetBranchAddress("muplus_MINIP", &muplus_MINIP, &b_muplus_MINIP);
   fChain->SetBranchAddress("muplus_MINIPCHI2", &muplus_MINIPCHI2, &b_muplus_MINIPCHI2);
   fChain->SetBranchAddress("muplus_MINIPNEXTBEST", &muplus_MINIPNEXTBEST, &b_muplus_MINIPNEXTBEST);
   fChain->SetBranchAddress("muplus_MINIPCHI2NEXTBEST", &muplus_MINIPCHI2NEXTBEST, &b_muplus_MINIPCHI2NEXTBEST);
   fChain->SetBranchAddress("muplus_OWNPV_X", &muplus_OWNPV_X, &b_muplus_OWNPV_X);
   fChain->SetBranchAddress("muplus_OWNPV_Y", &muplus_OWNPV_Y, &b_muplus_OWNPV_Y);
   fChain->SetBranchAddress("muplus_OWNPV_Z", &muplus_OWNPV_Z, &b_muplus_OWNPV_Z);
   fChain->SetBranchAddress("muplus_OWNPV_XERR", &muplus_OWNPV_XERR, &b_muplus_OWNPV_XERR);
   fChain->SetBranchAddress("muplus_OWNPV_YERR", &muplus_OWNPV_YERR, &b_muplus_OWNPV_YERR);
   fChain->SetBranchAddress("muplus_OWNPV_ZERR", &muplus_OWNPV_ZERR, &b_muplus_OWNPV_ZERR);
   fChain->SetBranchAddress("muplus_OWNPV_CHI2", &muplus_OWNPV_CHI2, &b_muplus_OWNPV_CHI2);
   fChain->SetBranchAddress("muplus_OWNPV_NDOF", &muplus_OWNPV_NDOF, &b_muplus_OWNPV_NDOF);
   fChain->SetBranchAddress("muplus_OWNPV_COV_", muplus_OWNPV_COV_, &b_muplus_OWNPV_COV_);
   fChain->SetBranchAddress("muplus_IP_OWNPV", &muplus_IP_OWNPV, &b_muplus_IP_OWNPV);
   fChain->SetBranchAddress("muplus_IPCHI2_OWNPV", &muplus_IPCHI2_OWNPV, &b_muplus_IPCHI2_OWNPV);
   fChain->SetBranchAddress("muplus_TOPPV_X", &muplus_TOPPV_X, &b_muplus_TOPPV_X);
   fChain->SetBranchAddress("muplus_TOPPV_Y", &muplus_TOPPV_Y, &b_muplus_TOPPV_Y);
   fChain->SetBranchAddress("muplus_TOPPV_Z", &muplus_TOPPV_Z, &b_muplus_TOPPV_Z);
   fChain->SetBranchAddress("muplus_TOPPV_XERR", &muplus_TOPPV_XERR, &b_muplus_TOPPV_XERR);
   fChain->SetBranchAddress("muplus_TOPPV_YERR", &muplus_TOPPV_YERR, &b_muplus_TOPPV_YERR);
   fChain->SetBranchAddress("muplus_TOPPV_ZERR", &muplus_TOPPV_ZERR, &b_muplus_TOPPV_ZERR);
   fChain->SetBranchAddress("muplus_TOPPV_CHI2", &muplus_TOPPV_CHI2, &b_muplus_TOPPV_CHI2);
   fChain->SetBranchAddress("muplus_TOPPV_NDOF", &muplus_TOPPV_NDOF, &b_muplus_TOPPV_NDOF);
   fChain->SetBranchAddress("muplus_TOPPV_COV_", muplus_TOPPV_COV_, &b_muplus_TOPPV_COV_);
   fChain->SetBranchAddress("muplus_IP_TOPPV", &muplus_IP_TOPPV, &b_muplus_IP_TOPPV);
   fChain->SetBranchAddress("muplus_IPCHI2_TOPPV", &muplus_IPCHI2_TOPPV, &b_muplus_IPCHI2_TOPPV);
   fChain->SetBranchAddress("muplus_ORIVX_X", &muplus_ORIVX_X, &b_muplus_ORIVX_X);
   fChain->SetBranchAddress("muplus_ORIVX_Y", &muplus_ORIVX_Y, &b_muplus_ORIVX_Y);
   fChain->SetBranchAddress("muplus_ORIVX_Z", &muplus_ORIVX_Z, &b_muplus_ORIVX_Z);
   fChain->SetBranchAddress("muplus_ORIVX_XERR", &muplus_ORIVX_XERR, &b_muplus_ORIVX_XERR);
   fChain->SetBranchAddress("muplus_ORIVX_YERR", &muplus_ORIVX_YERR, &b_muplus_ORIVX_YERR);
   fChain->SetBranchAddress("muplus_ORIVX_ZERR", &muplus_ORIVX_ZERR, &b_muplus_ORIVX_ZERR);
   fChain->SetBranchAddress("muplus_ORIVX_CHI2", &muplus_ORIVX_CHI2, &b_muplus_ORIVX_CHI2);
   fChain->SetBranchAddress("muplus_ORIVX_NDOF", &muplus_ORIVX_NDOF, &b_muplus_ORIVX_NDOF);
   fChain->SetBranchAddress("muplus_ORIVX_COV_", muplus_ORIVX_COV_, &b_muplus_ORIVX_COV_);
   fChain->SetBranchAddress("muplus_IP_ORIVX", &muplus_IP_ORIVX, &b_muplus_IP_ORIVX);
   fChain->SetBranchAddress("muplus_IPCHI2_ORIVX", &muplus_IPCHI2_ORIVX, &b_muplus_IPCHI2_ORIVX);
   fChain->SetBranchAddress("muplus_P", &muplus_P, &b_muplus_P);
   fChain->SetBranchAddress("muplus_PT", &muplus_PT, &b_muplus_PT);
   fChain->SetBranchAddress("muplus_PE", &muplus_PE, &b_muplus_PE);
   fChain->SetBranchAddress("muplus_PX", &muplus_PX, &b_muplus_PX);
   fChain->SetBranchAddress("muplus_PY", &muplus_PY, &b_muplus_PY);
   fChain->SetBranchAddress("muplus_PZ", &muplus_PZ, &b_muplus_PZ);
   fChain->SetBranchAddress("muplus_M", &muplus_M, &b_muplus_M);
   fChain->SetBranchAddress("muplus_ID", &muplus_ID, &b_muplus_ID);
   fChain->SetBranchAddress("muplus_PIDe", &muplus_PIDe, &b_muplus_PIDe);
   fChain->SetBranchAddress("muplus_PIDmu", &muplus_PIDmu, &b_muplus_PIDmu);
   fChain->SetBranchAddress("muplus_PIDK", &muplus_PIDK, &b_muplus_PIDK);
   fChain->SetBranchAddress("muplus_PIDp", &muplus_PIDp, &b_muplus_PIDp);
   fChain->SetBranchAddress("muplus_ProbNNe", &muplus_ProbNNe, &b_muplus_ProbNNe);
   fChain->SetBranchAddress("muplus_ProbNNk", &muplus_ProbNNk, &b_muplus_ProbNNk);
   fChain->SetBranchAddress("muplus_ProbNNp", &muplus_ProbNNp, &b_muplus_ProbNNp);
   fChain->SetBranchAddress("muplus_ProbNNpi", &muplus_ProbNNpi, &b_muplus_ProbNNpi);
   fChain->SetBranchAddress("muplus_ProbNNmu", &muplus_ProbNNmu, &b_muplus_ProbNNmu);
   fChain->SetBranchAddress("muplus_ProbNNghost", &muplus_ProbNNghost, &b_muplus_ProbNNghost);
   fChain->SetBranchAddress("muplus_hasMuon", &muplus_hasMuon, &b_muplus_hasMuon);
   fChain->SetBranchAddress("muplus_isMuon", &muplus_isMuon, &b_muplus_isMuon);
   fChain->SetBranchAddress("muplus_hasRich", &muplus_hasRich, &b_muplus_hasRich);
   fChain->SetBranchAddress("muplus_hasCalo", &muplus_hasCalo, &b_muplus_hasCalo);
   fChain->SetBranchAddress("muplus_TRACK_Type", &muplus_TRACK_Type, &b_muplus_TRACK_Type);
   fChain->SetBranchAddress("muplus_TRACK_Key", &muplus_TRACK_Key, &b_muplus_TRACK_Key);
   fChain->SetBranchAddress("muplus_TRACK_CHI2NDOF", &muplus_TRACK_CHI2NDOF, &b_muplus_TRACK_CHI2NDOF);
   fChain->SetBranchAddress("muplus_TRACK_PCHI2", &muplus_TRACK_PCHI2, &b_muplus_TRACK_PCHI2);
   fChain->SetBranchAddress("muplus_TRACK_MatchCHI2", &muplus_TRACK_MatchCHI2, &b_muplus_TRACK_MatchCHI2);
   fChain->SetBranchAddress("muplus_TRACK_GhostProb", &muplus_TRACK_GhostProb, &b_muplus_TRACK_GhostProb);
   fChain->SetBranchAddress("muplus_TRACK_CloneDist", &muplus_TRACK_CloneDist, &b_muplus_TRACK_CloneDist);
   fChain->SetBranchAddress("muplus_TRACK_Likelihood", &muplus_TRACK_Likelihood, &b_muplus_TRACK_Likelihood);
   fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
   fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
   fChain->SetBranchAddress("EventInSequence", &EventInSequence, &b_EventInSequence);
   fChain->SetBranchAddress("nLong", &nLong, &b_nLong);
   fChain->SetBranchAddress("nTracks", &nTracks, &b_nTracks);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("BCID", &BCID, &b_BCID);
   fChain->SetBranchAddress("BCType", &BCType, &b_BCType);
   fChain->SetBranchAddress("OdinTCK", &OdinTCK, &b_OdinTCK);
   fChain->SetBranchAddress("L0DUTCK", &L0DUTCK, &b_L0DUTCK);
   fChain->SetBranchAddress("HLTTCK", &HLTTCK, &b_HLTTCK);
   fChain->SetBranchAddress("GpsTime", &GpsTime, &b_GpsTime);
   fChain->SetBranchAddress("Primaries", &Primaries, &b_Primaries);
   fChain->SetBranchAddress("Polarity", &Polarity, &b_Polarity);
   Notify();
}

Bool_t Lb2JpsiL::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Lb2JpsiL::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Lb2JpsiL::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Lb2JpsiL_cxx
