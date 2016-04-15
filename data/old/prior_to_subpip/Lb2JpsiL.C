#define Lb2JpsiL_cxx
#include "Lb2JpsiL.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <iomanip>
#include <ctime>
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

   Long64_t nentries = fChain->GetEntriesFast();
   gROOT->SetBatch();
   double icut = 10;
   cout<<"icut = "<<icut<<endl;
   int massLbyield =0;
   int cutmassLbyield =0;
   int cutmassLb2yield =0;
   int cutmassLb3yield =0;
   int cutmassLb4yield =0;
   int cutmassLb5yield =0;
   int cutmassLb6yield =0;
   
   
   //create histograms
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
   TH1F *cutghostPiLL = new TH1F("cutghostPiLL","GhostProbLL(#pi) with cuts",100,0,1);
   TH1F *cutghostpLL = new TH1F("cutghostpLL","GhostProbLL(pi) with cuts",100,0,1);
   TH1F *cutghostmuplLL = new TH1F("cutghostmuplLL","GhostProbLL(#mu^{+}) with cuts",100,0,1);
   TH1F *cutghostmumiLL = new TH1F("cutghostmumiLL","GhostProbLL(#mu^{-}) with cuts",100,0,1);
   TH1F *cutghostPiDD = new TH1F("cutghostPiDD","GhostProbDD(#pi) with cuts",100,0,1);
   TH1F *cutghostpDD = new TH1F("cutghostpDD","GhostProbDD(pi) with cuts",100,0,1);
   TH1F *cutghostmuplDD = new TH1F("cutghostmuplDD","GhostProbDD(#mu^{+}) with cuts",100,0,1);
   TH1F *cutghostmumiDD = new TH1F("cutghostmumiDD","GhostProbDD(#mu^{-}) with cuts",100,0,1);
   TH1F *cutmassLb2 = new TH1F("cutmassLb2","m(#Lambda_{b}^{0}) with Liming's cuts LL" \
                                  ,400,4100,6100);
   TH1F *massLb = new TH1F("massLb","Bs_LOKI_MASS_JpsiConstr",400,4100,6100);
   TH1F *cutmassLb3 = new TH1F("cutmassLb3","m(#Lambda_{b}^{0}) with Liming's cuts DD"\
                              ,400,4100,6100);
   TH1F *cutmassLb = new TH1F("cutmassLb","m(#Lambda_{b}^{0}) with Liming's cuts from Aug5"\
                               ,400,4100,6100);
   TH1F *cutmassLb4 = new TH1F("cutmassLb4","m(#Lambda_{b}^{0}) with Liming's cuts and pID cut"\
                              ,400,4100,6100);
   TH1F *cutmassLb5 = new TH1F("cutmassLb5","m(#Lambda_{b}^{0}) with Liming's cuts and pID cut LL"\
                               ,400,4100,6100);
   TH1F *cutmassLb6 = new TH1F("cutmassLb6","m(#Lambda_{b}^{0}) with Liming's cuts and pID cut DD"\
                               ,400,4100,6100);
   cout<<"histograms created"<<endl;
   cout<<"nentries = "<<nentries<<endl;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      double zero = 0;
      double chi2ndfv = J_psi_1S_ENDVERTEX_CHI2 / J_psi_1S_ENDVERTEX_NDOF;
      //double mJpsiL = inv_mass(J_psi_1S_PX,J_psi_1S_PY,J_psi_1S_PZ,J_psi_1S_PE,R_PX,R_PY,R_PZ,R_PE,zero,zero,zero,zero);
      /*double mmumu = inv_mass(muplus_PX,muplus_PY,muplus_PZ,muplus_PE,muminus_PX,muminus_PY,muminus_PZ,muminus_PE, \
                              zero,zero,zero,zero);

      TVector3 *Bs_P = new TVector3();
      TVector3 *Bs_PV = new TVector3();
      TVector3 *Bs_EV = new TVector3();
      Bs_P->SetXYZ(Bs_PX,Bs_PY,Bs_PZ);
      Bs_PV->SetXYZ(Bs_OWNPV_X,Bs_OWNPV_Y,Bs_OWNPV_Z);
      Bs_EV->SetXYZ(Bs_ENDVERTEX_X,Bs_ENDVERTEX_Y,Bs_ENDVERTEX_Z);
      TVector3 *Bs_PmE = new TVector3(*Bs_EV - *Bs_PV);
      Double_t anglePPmE = Bs_P->Angle(*Bs_PmE);*/

      TVector3 *H1 = new TVector3();
      TVector3 *H2 = new TVector3();
      TVector3 *Jpsi = new TVector3();
      H1->SetXYZ(H1_OWNPV_X,H1_OWNPV_Y,H1_OWNPV_Z);
      H2->SetXYZ(H2_OWNPV_X,H2_OWNPV_Y,H2_OWNPV_Z);
      Jpsi->SetXYZ(J_psi_1S_ENDVERTEX_X,J_psi_1S_ENDVERTEX_Y,J_psi_1S_ENDVERTEX_Z);
      TVector3 *JpsiH1 = new TVector3(*Jpsi-*H1);
      TVector3 *JpsiH2 = new TVector3(*Jpsi-*H2);
      double dJpsiH1 = JpsiH1->Mag();
      double dJpsiH2 = JpsiH2->Mag();
      
      //double HFPTV = sqrt(pow(H1_PX + H2_PX,2)+pow(H1_PY + H2_PY,2));
      massJpsi->Fill(J_psi_1S_MM);
      chi2ndf->Fill(chi2ndfv);
      if(H2_TRACK_Type==3) ghostPiLL->Fill(H2_TRACK_GhostProb);
      if(H1_TRACK_Type==3) ghostpLL->Fill(H1_TRACK_GhostProb);
      if(muplus_TRACK_Type==3) ghostmuplLL->Fill(muplus_TRACK_GhostProb);
      if(muminus_TRACK_Type==3) ghostmumiLL->Fill(muminus_TRACK_GhostProb);
      if(H2_TRACK_Type==5) ghostPiDD->Fill(H2_TRACK_GhostProb);
      if(H1_TRACK_Type==5) ghostpDD->Fill(H1_TRACK_GhostProb);
      if(muplus_TRACK_Type==5) ghostmuplDD->Fill(muplus_TRACK_GhostProb);
      if(muminus_TRACK_Type==5) ghostmumiDD->Fill(muminus_TRACK_GhostProb);
      //Liming's cuts:
      if(((H1_TRACK_Type==3)&&(H2_TRACK_Type==3)&&(H1_TRACK_GhostProb<0.2)&&(H2_TRACK_GhostProb<0.2)&&(Bs_DIRA_OWNPV>0.9999) \
          &&(R_FDCHI2_ORIVX>50)&&(R_MM>1112)&&(R_MM<1120)&&(R_PT>1000)) \
         ||((R_PT>1000)&&(R_ENDVERTEX_Z>500)&&(H1_TRACK_Type==5)&&(H2_TRACK_Type==5) \
            &&(Bs_DIRA_OWNPV>0.9999)&&(R_FDCHI2_ORIVX>50)&&(R_MM>1110)&&(R_MM<1122)&&(Bs_ENDVERTEX_CHI2/Bs_ENDVERTEX_NDOF<10) \
            &&((J_psi_1S_MM-3096.92)>-48)&&((J_psi_1S_MM-3096.92)<43))){
        cutmassLb->Fill(Bs_LOKI_MASS_JpsiConstr);
        if((Bs_LOKI_MASS_JpsiConstr>=5470)&&(Bs_LOKI_MASS_JpsiConstr<=5770))cutmassLbyield++;
        if((H1_TRACK_Type==3)&&(H2_TRACK_Type==3)){
          cutmassLb2->Fill(Bs_LOKI_MASS_JpsiConstr);
          if((Bs_LOKI_MASS_JpsiConstr>=5470)&&(Bs_LOKI_MASS_JpsiConstr<=5770))cutmassLb2yield++;
        }
        if((H1_TRACK_Type==5)&&(H2_TRACK_Type==5)){
          cutmassLb3->Fill(Bs_LOKI_MASS_JpsiConstr);
          if((Bs_LOKI_MASS_JpsiConstr>=5470)&&(Bs_LOKI_MASS_JpsiConstr<=5770))cutmassLb3yield++;
        }
        //pID cut:
        if((H1_PIDp>10)&&((H1_PIDp-H1_PIDK)>3)){
          cutmassLb4->Fill(Bs_LOKI_MASS_JpsiConstr);
          if((Bs_LOKI_MASS_JpsiConstr>=5470)&&(Bs_LOKI_MASS_JpsiConstr<=5770))cutmassLb4yield++;
          if((H1_TRACK_Type==3)&&(H2_TRACK_Type==3)){
            cutmassLb5->Fill(Bs_LOKI_MASS_JpsiConstr);
            if((Bs_LOKI_MASS_JpsiConstr>=5470)&&(Bs_LOKI_MASS_JpsiConstr<=5770))cutmassLb5yield++;
          }
          if((H1_TRACK_Type==5)&&(H2_TRACK_Type==5)){
            cutmassLb6->Fill(Bs_LOKI_MASS_JpsiConstr);
            if((Bs_LOKI_MASS_JpsiConstr>=5470)&&(Bs_LOKI_MASS_JpsiConstr<=5770))cutmassLb6yield++;
          }
        }
        //cutghost histograms:
        if(H2_TRACK_Type==3) cutghostPiLL->Fill(H2_TRACK_GhostProb);
        if(H1_TRACK_Type==3) cutghostpLL->Fill(H1_TRACK_GhostProb);
        if(muplus_TRACK_Type==3) cutghostmuplLL->Fill(muplus_TRACK_GhostProb);
        if(muminus_TRACK_Type==3) cutghostmumiLL->Fill(muminus_TRACK_GhostProb);
        if(H2_TRACK_Type==5) cutghostPiDD->Fill(H2_TRACK_GhostProb);
        if(H1_TRACK_Type==5) cutghostpDD->Fill(H1_TRACK_GhostProb);
        if(muplus_TRACK_Type==5) cutghostmuplDD->Fill(muplus_TRACK_GhostProb);
        if(muminus_TRACK_Type==5) cutghostmumiDD->Fill(muminus_TRACK_GhostProb);
      }
      massLb->Fill(Bs_LOKI_MASS_JpsiConstr);
      if((Bs_LOKI_MASS_JpsiConstr>=5470)&&(Bs_LOKI_MASS_JpsiConstr<=5770))massLbyield++;
      
      /*      if(jentry%100000==0)cout<<jentry*100/nentries<<'%';
      if(jentry%10000==0)cout<<'.';
      if((jentry+1)/nentries==1)cout<<jentry*100/nentries<<'%';*/
   }
   cout<<endl;

   //   std::time_t t = std::time(NULL);
   // const char mbstr[16];
   //if (std::strftime(mbstr, 16, "%F_%H-%M", std::localtime(&t)));

   TCanvas *canvas1 = new TCanvas("canvas1","J/psi",1200,800);
   canvas1->Divide(2,1);
   cout<<"canvas 1/10 made"<<endl;
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
   canvas1->Print("plots.pdf(");
   TCanvas *canvas2 = new TCanvas("canvas2","GhostProb",1200,800);
   canvas2->Divide(2,2);
   cout<<"canvas 2/10 made"<<endl;
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
   canvas2->Print("plots.pdf(");
   TCanvas *canvas3 = new TCanvas("canvas3","cutGhostProb",1200,800);
   canvas3->Divide(2,2);
   cout<<"canvas 3/10 made"<<endl;
   canvas3->cd(1);
   gStyle->SetOptStat(kFALSE);
   cutghostPiLL->GetXaxis()->SetTitle("GhostProb(#pi) with cuts");
   cutghostPiLL->GetYaxis()->SetTitle("Events / 0.01");
   cutghostPiLL->Draw();
   canvas3->Update();
   cutghostPiDD->SetLineColor(kRed);
   cutghostPiDD->Draw("same");
   canvas3->cd(2);
   gStyle->SetOptStat(kFALSE);
   cutghostpLL->GetXaxis()->SetTitle("GhostProb(p) with cuts");
   cutghostpLL->GetYaxis()->SetTitle("Events / 0.01");
   cutghostpLL->Draw();
   canvas3->Update();
   cutghostpDD->SetLineColor(kRed);
   cutghostpDD->Draw("same");
   canvas3->cd(3);
   gStyle->SetOptStat(kFALSE);
   cutghostmuplLL->GetXaxis()->SetTitle("GhostProb(#mu^{+}) with cuts");
   cutghostmuplLL->GetYaxis()->SetTitle("Events / 0.01");
   cutghostmuplLL->Draw();
   canvas3->Update();
   cutghostmuplDD->SetLineColor(kRed);
   cutghostmuplDD->Draw("same");
   canvas3->cd(4);
   gStyle->SetOptStat(kFALSE);
   cutghostmumiLL->GetXaxis()->SetTitle("GhostProb(#mu^{-}) with cuts");
   cutghostmumiLL->GetYaxis()->SetTitle("Events / 0.01");
   cutghostmumiLL->Draw();
   canvas3->Update();
   cutghostmumiDD->SetLineColor(kRed);
   cutghostmumiDD->Draw("same");
   canvas3->Print("plots.pdf(");
   TCanvas *canvas4 = new TCanvas("canvas4","cutmassLb2",1200,800);
   cout<<"canvas 4/10 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb2->GetXaxis()->SetTitle("Bs_LOKI_MASS_JpsiConstr with Liming's cuts LL (MeV)");
   cutmassLb2->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb2->Draw();
   canvas4->Print("plots.pdf(");
   TCanvas *canvas5 = new TCanvas("canvas5","massLb",1200,800);
   cout<<"canvas 5/10 made"<<endl;
   gStyle->SetOptStat("e");
   massLb->GetXaxis()->SetTitle("Bs_LOKI_MASS_JpsiConstr (MeV)");
   massLb->GetYaxis()->SetTitle("Events / 5MeV");
   massLb->Draw();
   canvas5->Print("plots.pdf(");
   TCanvas *canvas6 = new TCanvas("canvas6","cutmassLb3",1200,800);
   cout<<"canvas 6/10 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb3->GetXaxis()->SetTitle("Bs_LOKI_MASS_JpsiConstr with Liming's cuts DD (MeV)");
   cutmassLb3->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb3->Draw();
   canvas6->Print("plots.pdf(");
   TCanvas *canvas7 = new TCanvas("canvas7","cutmassLb",1200,800);
   cout<<"canvas 7/10 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb->GetXaxis()->SetTitle("Bs_LOKI_MASS_JpsiConstr with Liming's cuts (MeV)");
   cutmassLb->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb->Draw();
   canvas7->Print("plots.pdf(");
   TCanvas *canvas8 = new TCanvas("canvas8","cutmassLb",1200,800);
   cout<<"canvas 8/10 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb4->GetXaxis()->SetTitle("Bs_LOKI_MASS_JpsiConstr with Liming's cuts and pID cut (MeV)");
   cutmassLb4->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb4->Draw();
   canvas8->Print("plots.pdf(");
   TCanvas *canvas9 = new TCanvas("canvas9","cutmassLb",1200,800);
   cout<<"canvas 9/10 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb5->GetXaxis()->SetTitle("Bs_LOKI_MASS_JpsiConstr with Liming's cuts and PID cut LL (MeV)");
   cutmassLb5->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb5->Draw();
   canvas9->Print("plots.pdf(");
   TCanvas *canvas10 = new TCanvas("canvas10","cutmassLb",1200,800);
   cout<<"canvas 10/10 made"<<endl;
   gStyle->SetOptStat("e");
   cutmassLb6->GetXaxis()->SetTitle("Bs_LOKI_MASS_JpsiConstr with Liming's cuts and PID cut DD (MeV)");
   cutmassLb6->GetYaxis()->SetTitle("Events / 5MeV");
   cutmassLb6->Draw();
   canvas10->Print("plots.pdf)");
   
   gROOT->SetBatch(kFALSE);
      
   cout<<"yields of 5470<=Bs_LOKI_MASS_JpsiConstr<=5770 with various cuts:"<<endl<<"no cuts: "<<massLbyield<<endl;
   cout<<"with Liming's Aug5 cuts: "<<cutmassLbyield<<endl<<"ditto LL: "<<cutmassLb2yield<<endl;
   cout<<"ditto DD: "<<cutmassLb3yield<<endl<<"with pID cut: "<<cutmassLb4yield<<endl;
   cout<<"ditto LL: "<<cutmassLb5yield<<endl<<"ditto DD: "<<cutmassLb6yield<<endl;
   cout<<"done"<<endl;
}
