void fitLMdataLL1()
{
//=========Macro generated from canvas: c1/data fits
//=========  (Thu Jun 30 23:00:26 2016) by ROOT version6.06/02
   TCanvas *c1 = new TCanvas("c1", "data fits",0,0,1200,800);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.14);
   c1->SetRightMargin(0.05);
   c1->SetTopMargin(0.05);
   c1->SetBottomMargin(0.16);
   c1->SetFrameLineWidth(2);
   c1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad2
   TPad *pad2 = new TPad("pad2", "pad2",0,0,1,0.3);
   pad2->Draw();
   pad2->cd();
   pad2->Range(1075.63,-26.4,1149.704,8.8);
   pad2->SetFillColor(0);
   pad2->SetBorderMode(0);
   pad2->SetBorderSize(2);
   pad2->SetTickx(1);
   pad2->SetTicky(1);
   pad2->SetLeftMargin(0.14);
   pad2->SetRightMargin(0.05);
   pad2->SetTopMargin(0);
   pad2->SetBottomMargin(0.5);
   pad2->SetFrameLineWidth(2);
   pad2->SetFrameBorderMode(0);
   pad2->SetFrameLineWidth(2);
   pad2->SetFrameBorderMode(0);
   
   TH1D *frame_3eff460__1 = new TH1D("frame_3eff460__1","",100,1086,1146);
   frame_3eff460__1->SetBinContent(1,3.875628);
   frame_3eff460__1->SetMinimum(-8.8);
   frame_3eff460__1->SetMaximum(8.8);
   frame_3eff460__1->SetEntries(1);
   frame_3eff460__1->SetDirectory(0);
   frame_3eff460__1->SetStats(0);
   frame_3eff460__1->SetLineWidth(2);
   frame_3eff460__1->SetMarkerStyle(20);
   frame_3eff460__1->GetXaxis()->SetTitle("#Lambda mass (MeV)");
   frame_3eff460__1->GetXaxis()->SetNdivisions(505);
   frame_3eff460__1->GetXaxis()->SetLabelFont(132);
   frame_3eff460__1->GetXaxis()->SetLabelOffset(0.01);
   frame_3eff460__1->GetXaxis()->SetLabelSize(0.15);
   frame_3eff460__1->GetXaxis()->SetTitleSize(0.2);
   frame_3eff460__1->GetXaxis()->SetTitleOffset(1.1);
   frame_3eff460__1->GetXaxis()->SetTitleFont(132);
   frame_3eff460__1->GetYaxis()->SetTitle("Pull");
   frame_3eff460__1->GetYaxis()->CenterTitle(true);
   frame_3eff460__1->GetYaxis()->SetNdivisions(505);
   frame_3eff460__1->GetYaxis()->SetLabelFont(132);
   frame_3eff460__1->GetYaxis()->SetLabelOffset(0.01);
   frame_3eff460__1->GetYaxis()->SetLabelSize(0.15);
   frame_3eff460__1->GetYaxis()->SetTitleSize(0.15);
   frame_3eff460__1->GetYaxis()->SetTitleOffset(0.45);
   frame_3eff460__1->GetYaxis()->SetTitleFont(132);
   frame_3eff460__1->GetZaxis()->SetLabelFont(132);
   frame_3eff460__1->GetZaxis()->SetLabelSize(0.06);
   frame_3eff460__1->GetZaxis()->SetTitleSize(0.072);
   frame_3eff460__1->GetZaxis()->SetTitleOffset(1.2);
   frame_3eff460__1->GetZaxis()->SetTitleFont(132);
   frame_3eff460__1->Draw("FUNC");
   
   Double_t pull_Hist_curvetot_fx3001[100] = {
   1086.3,
   1086.9,
   1087.5,
   1088.1,
   1088.7,
   1089.3,
   1089.9,
   1090.5,
   1091.1,
   1091.7,
   1092.3,
   1092.9,
   1093.5,
   1094.1,
   1094.7,
   1095.3,
   1095.9,
   1096.5,
   1097.1,
   1097.7,
   1098.3,
   1098.9,
   1099.5,
   1100.1,
   1100.7,
   1101.3,
   1101.9,
   1102.5,
   1103.1,
   1103.7,
   1104.3,
   1104.9,
   1105.5,
   1106.1,
   1106.7,
   1107.3,
   1107.9,
   1108.5,
   1109.1,
   1109.7,
   1110.3,
   1110.9,
   1111.5,
   1112.1,
   1112.7,
   1113.3,
   1113.9,
   1114.5,
   1115.1,
   1115.7,
   1116.3,
   1116.9,
   1117.5,
   1118.1,
   1118.7,
   1119.3,
   1119.9,
   1120.5,
   1121.1,
   1121.7,
   1122.3,
   1122.9,
   1123.5,
   1124.1,
   1124.7,
   1125.3,
   1125.9,
   1126.5,
   1127.1,
   1127.7,
   1128.3,
   1128.9,
   1129.5,
   1130.1,
   1130.7,
   1131.3,
   1131.9,
   1132.5,
   1133.1,
   1133.7,
   1134.3,
   1134.9,
   1135.5,
   1136.1,
   1136.7,
   1137.3,
   1137.9,
   1138.5,
   1139.1,
   1139.7,
   1140.3,
   1140.9,
   1141.5,
   1142.1,
   1142.7,
   1143.3,
   1143.9,
   1144.5,
   1145.1,
   1145.7};
   Double_t pull_Hist_curvetot_fy3001[100] = {
   0.9512912,
   0.883351,
   0.1548353,
   0.7510138,
   -0.02897719,
   -0.118378,
   0.561366,
   0,
   -0.3765588,
   -0.4592785,
   -0.5403279,
   0,
   0.2139593,
   0,
   -0.8478228,
   -0.9205208,
   0,
   0.969547,
   -1.128593,
   0.902695,
   -0.18311,
   -1.321633,
   0,
   0,
   -0.3532991,
   -1.555636,
   -1.609962,
   -0.4685441,
   -0.504611,
   -1.763031,
   -0.5734706,
   -1.858166,
   1.800879,
   0.02262506,
   -0.02043063,
   -0.09438004,
   1.053636,
   -1.380581,
   -1.177628,
   1.625469,
   0.3098203,
   -2.75568,
   -2.146013,
   -3.314961,
   0.1221816,
   -2.261606,
   0.4337666,
   -0.1938409,
   0.9558935,
   0.8158385,
   -1.4281,
   -1.47963,
   0.7996723,
   0.9944353,
   2.145797,
   2.4856,
   -0.4572304,
   -1.249876,
   -1.463024,
   1.82233,
   1.717098,
   0.5503893,
   1.146609,
   -1.168029,
   1.014951,
   0.2735732,
   0.7056306,
   0.2990673,
   1.631963,
   0.7307242,
   1.083193,
   0.337073,
   0.3483316,
   -0.1611711,
   1.121332,
   0.3871056,
   -0.1135068,
   -0.09569017,
   -2.133211,
   0.4504947,
   -0.7517538,
   -0.01478014,
   0,
   -1.945508,
   0.5485216,
   -0.6072175,
   0,
   -0.5411355,
   -0.5063229,
   0.1933281,
   0.2236811,
   0.7208352,
   -1.502416,
   -1.444832,
   -0.2726449,
   -1.324654,
   -0.1853037,
   0.4631539,
   0.9340706,
   -1.064253};
   Double_t pull_Hist_curvetot_felx3001[100] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t pull_Hist_curvetot_fely3001[100] = {
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   0,
   1,
   1,
   1,
   0,
   1,
   0,
   1,
   1,
   0,
   1,
   1,
   1,
   1,
   1,
   0,
   0,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   0,
   1,
   1,
   1,
   0,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1};
   Double_t pull_Hist_curvetot_fehx3001[100] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t pull_Hist_curvetot_fehy3001[100] = {
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   0,
   1,
   1,
   1,
   0,
   1,
   0,
   1,
   1,
   0,
   1,
   1,
   1,
   1,
   1,
   0,
   0,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   0,
   1,
   1,
   1,
   0,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(100,pull_Hist_curvetot_fx3001,pull_Hist_curvetot_fy3001,pull_Hist_curvetot_felx3001,pull_Hist_curvetot_fehx3001,pull_Hist_curvetot_fely3001,pull_Hist_curvetot_fehy3001);
   grae->SetName("pull_Hist_curvetot");
   grae->SetTitle("Pull of Histogram of data_plot__R_M and Projection of totalPdf");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(8);
   
   TH1F *Graph_pull_Hist_curvetot3001 = new TH1F("Graph_pull_Hist_curvetot3001","Pull of Histogram of data_plot__R_M and Projection of totalPdf",100,1080.36,1151.64);
   Graph_pull_Hist_curvetot3001->SetMinimum(-5.095017);
   Graph_pull_Hist_curvetot3001->SetMaximum(4.265656);
   Graph_pull_Hist_curvetot3001->SetDirectory(0);
   Graph_pull_Hist_curvetot3001->SetStats(0);
   Graph_pull_Hist_curvetot3001->SetLineWidth(2);
   Graph_pull_Hist_curvetot3001->SetMarkerStyle(20);
   Graph_pull_Hist_curvetot3001->GetXaxis()->SetNdivisions(505);
   Graph_pull_Hist_curvetot3001->GetXaxis()->SetLabelFont(132);
   Graph_pull_Hist_curvetot3001->GetXaxis()->SetLabelOffset(0.01);
   Graph_pull_Hist_curvetot3001->GetXaxis()->SetLabelSize(0.06);
   Graph_pull_Hist_curvetot3001->GetXaxis()->SetTitleSize(0.072);
   Graph_pull_Hist_curvetot3001->GetXaxis()->SetTitleOffset(0.95);
   Graph_pull_Hist_curvetot3001->GetXaxis()->SetTitleFont(132);
   Graph_pull_Hist_curvetot3001->GetYaxis()->SetLabelFont(132);
   Graph_pull_Hist_curvetot3001->GetYaxis()->SetLabelOffset(0.01);
   Graph_pull_Hist_curvetot3001->GetYaxis()->SetLabelSize(0.06);
   Graph_pull_Hist_curvetot3001->GetYaxis()->SetTitleSize(0.072);
   Graph_pull_Hist_curvetot3001->GetYaxis()->SetTitleOffset(0.95);
   Graph_pull_Hist_curvetot3001->GetYaxis()->SetTitleFont(132);
   Graph_pull_Hist_curvetot3001->GetZaxis()->SetLabelFont(132);
   Graph_pull_Hist_curvetot3001->GetZaxis()->SetLabelSize(0.06);
   Graph_pull_Hist_curvetot3001->GetZaxis()->SetTitleSize(0.072);
   Graph_pull_Hist_curvetot3001->GetZaxis()->SetTitleOffset(1.2);
   Graph_pull_Hist_curvetot3001->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_pull_Hist_curvetot3001);
   
   grae->Draw("p");
   
   TH1D *frame_3eff460__2 = new TH1D("frame_3eff460__2","",100,1086,1146);
   frame_3eff460__2->SetBinContent(1,3.875628);
   frame_3eff460__2->SetMinimum(-8.8);
   frame_3eff460__2->SetMaximum(8.8);
   frame_3eff460__2->SetEntries(1);
   frame_3eff460__2->SetDirectory(0);
   frame_3eff460__2->SetStats(0);
   frame_3eff460__2->SetLineWidth(2);
   frame_3eff460__2->SetMarkerStyle(20);
   frame_3eff460__2->GetXaxis()->SetTitle("#Lambda mass (MeV)");
   frame_3eff460__2->GetXaxis()->SetNdivisions(505);
   frame_3eff460__2->GetXaxis()->SetLabelFont(132);
   frame_3eff460__2->GetXaxis()->SetLabelOffset(0.01);
   frame_3eff460__2->GetXaxis()->SetLabelSize(0.15);
   frame_3eff460__2->GetXaxis()->SetTitleSize(0.2);
   frame_3eff460__2->GetXaxis()->SetTitleOffset(1.1);
   frame_3eff460__2->GetXaxis()->SetTitleFont(132);
   frame_3eff460__2->GetYaxis()->SetTitle("Pull");
   frame_3eff460__2->GetYaxis()->CenterTitle(true);
   frame_3eff460__2->GetYaxis()->SetNdivisions(505);
   frame_3eff460__2->GetYaxis()->SetLabelFont(132);
   frame_3eff460__2->GetYaxis()->SetLabelOffset(0.01);
   frame_3eff460__2->GetYaxis()->SetLabelSize(0.15);
   frame_3eff460__2->GetYaxis()->SetTitleSize(0.15);
   frame_3eff460__2->GetYaxis()->SetTitleOffset(0.45);
   frame_3eff460__2->GetYaxis()->SetTitleFont(132);
   frame_3eff460__2->GetZaxis()->SetLabelFont(132);
   frame_3eff460__2->GetZaxis()->SetLabelSize(0.06);
   frame_3eff460__2->GetZaxis()->SetTitleSize(0.072);
   frame_3eff460__2->GetZaxis()->SetTitleOffset(1.2);
   frame_3eff460__2->GetZaxis()->SetTitleFont(132);
   frame_3eff460__2->Draw("AXISSAME");
   pad2->Modified();
   c1->cd();
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "pad1",0,0.3,1,1);
   pad1->Draw();
   pad1->cd();
   pad1->Range(1075.63,0,1149.704,4.122406);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetLogy();
   pad1->SetTickx(1);
   pad1->SetTicky(1);
   pad1->SetLeftMargin(0.14);
   pad1->SetRightMargin(0.05);
   pad1->SetTopMargin(0.06);
   pad1->SetBottomMargin(0);
   pad1->SetFrameLineWidth(2);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameLineWidth(2);
   pad1->SetFrameBorderMode(0);
   
   TH1D *frame_3cf79b0__3 = new TH1D("frame_3cf79b0__3","A RooPlot of \"#Lambda mass\"",100,1086,1146);
   frame_3cf79b0__3->SetBinContent(1,1119.464);
   frame_3cf79b0__3->SetMinimum(1);
   frame_3cf79b0__3->SetMaximum(7500);
   frame_3cf79b0__3->SetEntries(1);
   frame_3cf79b0__3->SetDirectory(0);
   frame_3cf79b0__3->SetStats(0);
   frame_3cf79b0__3->SetLineWidth(2);
   frame_3cf79b0__3->SetMarkerStyle(20);
   frame_3cf79b0__3->GetXaxis()->SetTitle("#Lambda mass (MeV)");
   frame_3cf79b0__3->GetXaxis()->SetNdivisions(505);
   frame_3cf79b0__3->GetXaxis()->SetLabelFont(132);
   frame_3cf79b0__3->GetXaxis()->SetLabelOffset(0.01);
   frame_3cf79b0__3->GetXaxis()->SetLabelSize(0.06);
   frame_3cf79b0__3->GetXaxis()->SetTitleSize(0.072);
   frame_3cf79b0__3->GetXaxis()->SetTitleOffset(0.95);
   frame_3cf79b0__3->GetXaxis()->SetTitleFont(132);
   frame_3cf79b0__3->GetYaxis()->SetTitle("Events/(5 MeV)");
   frame_3cf79b0__3->GetYaxis()->SetLabelFont(132);
   frame_3cf79b0__3->GetYaxis()->SetLabelOffset(0.01);
   frame_3cf79b0__3->GetYaxis()->SetLabelSize(0.06);
   frame_3cf79b0__3->GetYaxis()->SetTitleSize(0.072);
   frame_3cf79b0__3->GetYaxis()->SetTitleOffset(0.95);
   frame_3cf79b0__3->GetYaxis()->SetTitleFont(132);
   frame_3cf79b0__3->GetZaxis()->SetLabelFont(132);
   frame_3cf79b0__3->GetZaxis()->SetLabelSize(0.06);
   frame_3cf79b0__3->GetZaxis()->SetTitleSize(0.072);
   frame_3cf79b0__3->GetZaxis()->SetTitleOffset(1.2);
   frame_3cf79b0__3->GetZaxis()->SetTitleFont(132);
   frame_3cf79b0__3->Draw("FUNC");
   
   Double_t Hist_fx3002[100] = {
   1086.3,
   1086.9,
   1087.5,
   1088.1,
   1088.7,
   1089.3,
   1089.9,
   1090.5,
   1091.1,
   1091.7,
   1092.3,
   1092.9,
   1093.5,
   1094.1,
   1094.7,
   1095.3,
   1095.9,
   1096.5,
   1097.1,
   1097.7,
   1098.3,
   1098.9,
   1099.5,
   1100.1,
   1100.7,
   1101.3,
   1101.9,
   1102.5,
   1103.1,
   1103.7,
   1104.3,
   1104.9,
   1105.5,
   1106.1,
   1106.7,
   1107.3,
   1107.9,
   1108.5,
   1109.1,
   1109.7,
   1110.3,
   1110.9,
   1111.5,
   1112.1,
   1112.7,
   1113.3,
   1113.9,
   1114.5,
   1115.1,
   1115.7,
   1116.3,
   1116.9,
   1117.5,
   1118.1,
   1118.7,
   1119.3,
   1119.9,
   1120.5,
   1121.1,
   1121.7,
   1122.3,
   1122.9,
   1123.5,
   1124.1,
   1124.7,
   1125.3,
   1125.9,
   1126.5,
   1127.1,
   1127.7,
   1128.3,
   1128.9,
   1129.5,
   1130.1,
   1130.7,
   1131.3,
   1131.9,
   1132.5,
   1133.1,
   1133.7,
   1134.3,
   1134.9,
   1135.5,
   1136.1,
   1136.7,
   1137.3,
   1137.9,
   1138.5,
   1139.1,
   1139.7,
   1140.3,
   1140.9,
   1141.5,
   1142.1,
   1142.7,
   1143.3,
   1143.9,
   1144.5,
   1145.1,
   1145.7};
   Double_t Hist_fy3002[100] = {
   2,
   2,
   1,
   2,
   1,
   1,
   2,
   0,
   1,
   1,
   1,
   0,
   2,
   0,
   1,
   1,
   0,
   4,
   1,
   4,
   2,
   1,
   0,
   0,
   2,
   1,
   1,
   2,
   2,
   1,
   2,
   1,
   8,
   3,
   3,
   3,
   6,
   2,
   3,
   13,
   12,
   9,
   18,
   25,
   63,
   83,
   216,
   442,
   813,
   1034,
   864,
   545,
   301,
   147,
   96,
   69,
   30,
   16,
   9,
   16,
   12,
   6,
   7,
   2,
   6,
   4,
   5,
   4,
   8,
   5,
   6,
   4,
   4,
   3,
   6,
   4,
   3,
   3,
   1,
   4,
   2,
   3,
   0,
   1,
   4,
   2,
   0,
   2,
   2,
   3,
   3,
   4,
   1,
   1,
   2,
   1,
   2,
   3,
   4,
   1};
   Double_t Hist_felx3002[100] = {
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3};
   Double_t Hist_fely3002[100] = {
   1.414214,
   1.414214,
   1,
   1.414214,
   1,
   1,
   1.414214,
   0,
   1,
   1,
   1,
   0,
   1.414214,
   0,
   1,
   1,
   0,
   2,
   1,
   2,
   1.414214,
   1,
   0,
   0,
   1.414214,
   1,
   1,
   1.414214,
   1.414214,
   1,
   1.414214,
   1,
   2.828427,
   1.732051,
   1.732051,
   1.732051,
   2.44949,
   1.414214,
   1.732051,
   3.605551,
   3.464102,
   3,
   4.242641,
   5,
   7.937254,
   9.110434,
   14.69694,
   21.0238,
   28.51315,
   32.15587,
   29.39388,
   23.34524,
   17.34935,
   12.12436,
   9.797959,
   8.306624,
   5.477226,
   4,
   3,
   4,
   3.464102,
   2.44949,
   2.645751,
   1.414214,
   2.44949,
   2,
   2.236068,
   2,
   2.828427,
   2.236068,
   2.44949,
   2,
   2,
   1.732051,
   2.44949,
   2,
   1.732051,
   1.732051,
   1,
   2,
   1.414214,
   1.732051,
   0,
   1,
   2,
   1.414214,
   0,
   1.414214,
   1.414214,
   1.732051,
   1.732051,
   2,
   1,
   1,
   1.414214,
   1,
   1.414214,
   1.732051,
   2,
   1};
   Double_t Hist_fehx3002[100] = {
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3,
   0.3};
   Double_t Hist_fehy3002[100] = {
   1.414214,
   1.414214,
   1,
   1.414214,
   1,
   1,
   1.414214,
   0,
   1,
   1,
   1,
   0,
   1.414214,
   0,
   1,
   1,
   0,
   2,
   1,
   2,
   1.414214,
   1,
   0,
   0,
   1.414214,
   1,
   1,
   1.414214,
   1.414214,
   1,
   1.414214,
   1,
   2.828427,
   1.732051,
   1.732051,
   1.732051,
   2.44949,
   1.414214,
   1.732051,
   3.605551,
   3.464102,
   3,
   4.242641,
   5,
   7.937254,
   9.110434,
   14.69694,
   21.0238,
   28.51315,
   32.15587,
   29.39388,
   23.34524,
   17.34935,
   12.12436,
   9.797959,
   8.306624,
   5.477226,
   4,
   3,
   4,
   3.464102,
   2.44949,
   2.645751,
   1.414214,
   2.44949,
   2,
   2.236068,
   2,
   2.828427,
   2.236068,
   2.44949,
   2,
   2,
   1.732051,
   2.44949,
   2,
   1.732051,
   1.732051,
   1,
   2,
   1.414214,
   1.732051,
   0,
   1,
   2,
   1.414214,
   0,
   1.414214,
   1.414214,
   1.732051,
   1.732051,
   2,
   1,
   1,
   1.414214,
   1,
   1.414214,
   1.732051,
   2,
   1};
   grae = new TGraphAsymmErrors(100,Hist_fx3002,Hist_fy3002,Hist_felx3002,Hist_fehx3002,Hist_fely3002,Hist_fehy3002);
   grae->SetName("Hist");
   grae->SetTitle("Histogram of data_plot__R_M");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(8);
   
   TH1F *Graph_Hist3002 = new TH1F("Graph_Hist3002","Histogram of data_plot__R_M",100,1080,1152);
   Graph_Hist3002->SetMinimum(1.172771);
   Graph_Hist3002->SetMaximum(1172.771);
   Graph_Hist3002->SetDirectory(0);
   Graph_Hist3002->SetStats(0);
   Graph_Hist3002->SetLineWidth(2);
   Graph_Hist3002->SetMarkerStyle(20);
   Graph_Hist3002->GetXaxis()->SetNdivisions(505);
   Graph_Hist3002->GetXaxis()->SetLabelFont(132);
   Graph_Hist3002->GetXaxis()->SetLabelOffset(0.01);
   Graph_Hist3002->GetXaxis()->SetLabelSize(0.06);
   Graph_Hist3002->GetXaxis()->SetTitleSize(0.072);
   Graph_Hist3002->GetXaxis()->SetTitleOffset(0.95);
   Graph_Hist3002->GetXaxis()->SetTitleFont(132);
   Graph_Hist3002->GetYaxis()->SetLabelFont(132);
   Graph_Hist3002->GetYaxis()->SetLabelOffset(0.01);
   Graph_Hist3002->GetYaxis()->SetLabelSize(0.06);
   Graph_Hist3002->GetYaxis()->SetTitleSize(0.072);
   Graph_Hist3002->GetYaxis()->SetTitleOffset(0.95);
   Graph_Hist3002->GetYaxis()->SetTitleFont(132);
   Graph_Hist3002->GetZaxis()->SetLabelFont(132);
   Graph_Hist3002->GetZaxis()->SetLabelSize(0.06);
   Graph_Hist3002->GetZaxis()->SetTitleSize(0.072);
   Graph_Hist3002->GetZaxis()->SetTitleOffset(1.2);
   Graph_Hist3002->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Hist3002);
   
   grae->Draw("p");
   
   Double_t curvetot_fx1[150] = {
   1086,
   1086.6,
   1087.2,
   1087.8,
   1088.4,
   1089,
   1089.6,
   1090.2,
   1090.8,
   1091.4,
   1092,
   1092.6,
   1093.2,
   1093.8,
   1094.4,
   1095,
   1095.6,
   1096.2,
   1096.8,
   1097.4,
   1098,
   1098.6,
   1099.2,
   1099.8,
   1100.4,
   1101,
   1101.6,
   1102.2,
   1102.8,
   1103.4,
   1104,
   1104.6,
   1105.2,
   1105.8,
   1106.4,
   1107,
   1107.6,
   1108.2,
   1108.8,
   1109.4,
   1110,
   1110.6,
   1111.2,
   1111.8,
   1112.4,
   1112.7,
   1113,
   1113.15,
   1113.3,
   1113.45,
   1113.6,
   1113.75,
   1113.825,
   1113.9,
   1113.975,
   1114.05,
   1114.125,
   1114.2,
   1114.275,
   1114.35,
   1114.425,
   1114.5,
   1114.65,
   1114.8,
   1114.95,
   1115.1,
   1115.175,
   1115.25,
   1115.325,
   1115.4,
   1115.475,
   1115.55,
   1115.625,
   1115.7,
   1115.775,
   1115.85,
   1115.925,
   1116,
   1116.075,
   1116.15,
   1116.225,
   1116.3,
   1116.375,
   1116.45,
   1116.6,
   1116.9,
   1117.05,
   1117.2,
   1117.275,
   1117.35,
   1117.425,
   1117.5,
   1117.575,
   1117.65,
   1117.725,
   1117.8,
   1117.95,
   1118.1,
   1118.25,
   1118.4,
   1118.55,
   1118.7,
   1119,
   1119.3,
   1119.6,
   1120.2,
   1120.8,
   1121.4,
   1122,
   1122.6,
   1123.2,
   1123.8,
   1124.4,
   1125,
   1125.6,
   1126.2,
   1126.8,
   1127.4,
   1128,
   1128.6,
   1129.2,
   1129.8,
   1130.4,
   1131,
   1131.6,
   1132.2,
   1132.8,
   1133.4,
   1134,
   1134.6,
   1135.2,
   1135.8,
   1136.4,
   1137,
   1137.6,
   1138.2,
   1138.8,
   1139.4,
   1140,
   1140.6,
   1141.2,
   1141.8,
   1142.4,
   1143,
   1143.6,
   1144.2,
   1144.8,
   1145.4,
   1146,
   1146};
   Double_t curvetot_fy1[150] = {
   0.6062126,
   0.7031296,
   0.7983764,
   0.891953,
   0.9838592,
   1.074095,
   1.162661,
   1.249556,
   1.334781,
   1.418336,
   1.500221,
   1.580435,
   1.658979,
   1.735853,
   1.811056,
   1.884589,
   1.956452,
   2.026645,
   2.095167,
   2.162019,
   2.227201,
   2.290712,
   2.352554,
   2.412725,
   2.471225,
   2.528056,
   2.583216,
   2.636708,
   2.688535,
   2.73872,
   2.787341,
   2.834679,
   2.881652,
   2.931039,
   2.990586,
   3.080188,
   3.246754,
   3.591503,
   4.31337,
   5.766055,
   8.512525,
   13.34098,
   21.1931,
   33.01642,
   50.13319,
   62.03021,
   78.49357,
   89.60889,
   103.6042,
   121.4321,
   144.216,
   173.1953,
   190.4036,
   209.625,
   230.9942,
   254.6259,
   280.6078,
   308.9935,
   339.7956,
   372.979,
   408.4549,
   446.0753,
   526.8424,
   612.8174,
   700.5436,
   785.7445,
   825.9131,
   863.6421,
   898.3277,
   929.3933,
   956.3061,
   978.5922,
   995.8506,
   1007.766,
   1014.118,
   1014.789,
   1009.765,
   999.1411,
   983.1137,
   961.9767,
   936.1119,
   905.9774,
   872.0935,
   835.0281,
   753.7627,
   579.5423,
   495.2118,
   417.1541,
   381.1637,
   347.4366,
   316.075,
   287.1262,
   260.5881,
   236.4159,
   214.5295,
   194.8199,
   161.3932,
   134.9431,
   114.2056,
   97.97649,
   85.19334,
   74.97557,
   59.64116,
   48.35306,
   39.35099,
   25.65771,
   16.34129,
   10.43685,
   6.984517,
   5.119076,
   4.184578,
   3.74814,
   3.555545,
   3.472231,
   3.433477,
   3.410847,
   3.392884,
   3.375339,
   3.356763,
   3.336698,
   3.31501,
   3.291664,
   3.266649,
   3.239966,
   3.211612,
   3.181587,
   3.149893,
   3.116528,
   3.081493,
   3.044788,
   3.006412,
   2.966366,
   2.92465,
   2.881264,
   2.836207,
   2.78948,
   2.741082,
   2.691015,
   2.639277,
   2.585869,
   2.53079,
   2.474042,
   2.415623,
   2.355533,
   2.293774,
   2.230344,
   2.165244,
   2.098474,
   2.030033,
   2.030033};
   TGraph *graph = new TGraph(150,curvetot_fx1,curvetot_fy1);
   graph->SetName("curvetot");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_curvetot1 = new TH1F("Graph_curvetot1","Projection of totalPdf",150,1080,1152);
   Graph_curvetot1->SetMinimum(0.5455913);
   Graph_curvetot1->SetMaximum(1116.207);
   Graph_curvetot1->SetDirectory(0);
   Graph_curvetot1->SetStats(0);
   Graph_curvetot1->SetLineWidth(2);
   Graph_curvetot1->SetMarkerStyle(20);
   Graph_curvetot1->GetXaxis()->SetNdivisions(505);
   Graph_curvetot1->GetXaxis()->SetLabelFont(132);
   Graph_curvetot1->GetXaxis()->SetLabelOffset(0.01);
   Graph_curvetot1->GetXaxis()->SetLabelSize(0.06);
   Graph_curvetot1->GetXaxis()->SetTitleSize(0.072);
   Graph_curvetot1->GetXaxis()->SetTitleOffset(0.95);
   Graph_curvetot1->GetXaxis()->SetTitleFont(132);
   Graph_curvetot1->GetYaxis()->SetLabelFont(132);
   Graph_curvetot1->GetYaxis()->SetLabelOffset(0.01);
   Graph_curvetot1->GetYaxis()->SetLabelSize(0.06);
   Graph_curvetot1->GetYaxis()->SetTitleSize(0.072);
   Graph_curvetot1->GetYaxis()->SetTitleOffset(0.95);
   Graph_curvetot1->GetYaxis()->SetTitleFont(132);
   Graph_curvetot1->GetZaxis()->SetLabelFont(132);
   Graph_curvetot1->GetZaxis()->SetLabelSize(0.06);
   Graph_curvetot1->GetZaxis()->SetTitleSize(0.072);
   Graph_curvetot1->GetZaxis()->SetTitleOffset(1.2);
   Graph_curvetot1->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_curvetot1);
   
   graph->Draw("l");
   
   Double_t bkg_fx2[102] = {
   1086,
   1086.6,
   1087.2,
   1087.8,
   1088.4,
   1089,
   1089.6,
   1090.2,
   1090.8,
   1091.4,
   1092,
   1092.6,
   1093.2,
   1093.8,
   1094.4,
   1095,
   1095.6,
   1096.2,
   1096.8,
   1097.4,
   1098,
   1098.6,
   1099.2,
   1099.8,
   1100.4,
   1101,
   1101.6,
   1102.2,
   1102.8,
   1103.4,
   1104,
   1104.6,
   1105.2,
   1105.8,
   1106.4,
   1107,
   1107.6,
   1108.2,
   1108.8,
   1109.4,
   1110,
   1110.6,
   1111.2,
   1111.8,
   1112.4,
   1113,
   1113.6,
   1114.2,
   1114.8,
   1115.4,
   1116,
   1116.6,
   1117.2,
   1117.8,
   1118.4,
   1119,
   1119.6,
   1120.2,
   1120.8,
   1121.4,
   1122,
   1122.6,
   1123.2,
   1123.8,
   1124.4,
   1125,
   1125.6,
   1126.2,
   1126.8,
   1127.4,
   1128,
   1128.6,
   1129.2,
   1129.8,
   1130.4,
   1131,
   1131.6,
   1132.2,
   1132.8,
   1133.4,
   1134,
   1134.6,
   1135.2,
   1135.8,
   1136.4,
   1137,
   1137.6,
   1138.2,
   1138.8,
   1139.4,
   1140,
   1140.6,
   1141.2,
   1141.8,
   1142.4,
   1143,
   1143.6,
   1144.2,
   1144.8,
   1145.4,
   1146,
   1146};
   Double_t bkg_fy2[102] = {
   0.6062126,
   0.7031296,
   0.7983764,
   0.891953,
   0.9838592,
   1.074095,
   1.162661,
   1.249556,
   1.334781,
   1.418336,
   1.500221,
   1.580435,
   1.658979,
   1.735853,
   1.811056,
   1.884589,
   1.956452,
   2.026645,
   2.095167,
   2.162019,
   2.227201,
   2.290712,
   2.352554,
   2.412725,
   2.471225,
   2.528056,
   2.583216,
   2.636705,
   2.688525,
   2.738674,
   2.787153,
   2.833962,
   2.8791,
   2.922568,
   2.964366,
   3.004494,
   3.042951,
   3.079738,
   3.114855,
   3.148301,
   3.180077,
   3.210183,
   3.238619,
   3.265384,
   3.290479,
   3.313904,
   3.335658,
   3.355742,
   3.374156,
   3.3909,
   3.405973,
   3.419376,
   3.431109,
   3.441172,
   3.449564,
   3.456286,
   3.461337,
   3.464719,
   3.46643,
   3.466471,
   3.464841,
   3.461541,
   3.456571,
   3.449931,
   3.441621,
   3.43164,
   3.419989,
   3.406667,
   3.391675,
   3.375013,
   3.356681,
   3.336679,
   3.315006,
   3.291663,
   3.266649,
   3.239966,
   3.211612,
   3.181587,
   3.149893,
   3.116528,
   3.081493,
   3.044788,
   3.006412,
   2.966366,
   2.92465,
   2.881264,
   2.836207,
   2.78948,
   2.741082,
   2.691015,
   2.639277,
   2.585869,
   2.53079,
   2.474042,
   2.415623,
   2.355533,
   2.293774,
   2.230344,
   2.165244,
   2.098474,
   2.030033,
   2.030033};
   graph = new TGraph(102,bkg_fx2,bkg_fy2);
   graph->SetName("bkg");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);
   graph->SetLineColor(2);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_bkg2 = new TH1F("Graph_bkg2","Projection of totalPdf",102,1080,1152);
   Graph_bkg2->SetMinimum(0.3201867);
   Graph_bkg2->SetMaximum(3.752497);
   Graph_bkg2->SetDirectory(0);
   Graph_bkg2->SetStats(0);
   Graph_bkg2->SetLineWidth(2);
   Graph_bkg2->SetMarkerStyle(20);
   Graph_bkg2->GetXaxis()->SetNdivisions(505);
   Graph_bkg2->GetXaxis()->SetLabelFont(132);
   Graph_bkg2->GetXaxis()->SetLabelOffset(0.01);
   Graph_bkg2->GetXaxis()->SetLabelSize(0.06);
   Graph_bkg2->GetXaxis()->SetTitleSize(0.072);
   Graph_bkg2->GetXaxis()->SetTitleOffset(0.95);
   Graph_bkg2->GetXaxis()->SetTitleFont(132);
   Graph_bkg2->GetYaxis()->SetLabelFont(132);
   Graph_bkg2->GetYaxis()->SetLabelOffset(0.01);
   Graph_bkg2->GetYaxis()->SetLabelSize(0.06);
   Graph_bkg2->GetYaxis()->SetTitleSize(0.072);
   Graph_bkg2->GetYaxis()->SetTitleOffset(0.95);
   Graph_bkg2->GetYaxis()->SetTitleFont(132);
   Graph_bkg2->GetZaxis()->SetLabelFont(132);
   Graph_bkg2->GetZaxis()->SetLabelSize(0.06);
   Graph_bkg2->GetZaxis()->SetTitleSize(0.072);
   Graph_bkg2->GetZaxis()->SetTitleOffset(1.2);
   Graph_bkg2->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_bkg2);
   
   graph->Draw("l");
   
   Double_t sigLM_fx3[150] = {
   1086,
   1086.6,
   1087.2,
   1087.8,
   1088.4,
   1089,
   1089.6,
   1090.2,
   1090.8,
   1091.4,
   1092,
   1092.6,
   1093.2,
   1093.8,
   1094.4,
   1095,
   1095.6,
   1096.2,
   1096.8,
   1097.4,
   1098,
   1098.6,
   1099.2,
   1099.8,
   1100.4,
   1101,
   1101.6,
   1102.2,
   1102.8,
   1103.4,
   1104,
   1104.6,
   1105.2,
   1105.8,
   1106.4,
   1107,
   1107.6,
   1108.2,
   1108.8,
   1109.4,
   1110,
   1110.6,
   1111.2,
   1111.8,
   1112.4,
   1112.7,
   1113,
   1113.15,
   1113.3,
   1113.45,
   1113.6,
   1113.75,
   1113.825,
   1113.9,
   1113.975,
   1114.05,
   1114.125,
   1114.2,
   1114.275,
   1114.35,
   1114.425,
   1114.5,
   1114.65,
   1114.8,
   1114.95,
   1115.1,
   1115.175,
   1115.25,
   1115.325,
   1115.4,
   1115.475,
   1115.55,
   1115.625,
   1115.7,
   1115.775,
   1115.85,
   1115.925,
   1116,
   1116.075,
   1116.15,
   1116.225,
   1116.3,
   1116.375,
   1116.45,
   1116.6,
   1116.9,
   1117.05,
   1117.2,
   1117.275,
   1117.35,
   1117.425,
   1117.5,
   1117.575,
   1117.65,
   1117.725,
   1117.8,
   1117.95,
   1118.1,
   1118.25,
   1118.4,
   1118.55,
   1118.7,
   1119,
   1119.3,
   1119.6,
   1120.2,
   1120.8,
   1121.4,
   1122,
   1122.6,
   1123.2,
   1123.8,
   1124.4,
   1125,
   1125.6,
   1126.2,
   1126.8,
   1127.4,
   1128,
   1128.6,
   1129.2,
   1129.8,
   1130.4,
   1131,
   1131.6,
   1132.2,
   1132.8,
   1133.4,
   1134,
   1134.6,
   1135.2,
   1135.8,
   1136.4,
   1137,
   1137.6,
   1138.2,
   1138.8,
   1139.4,
   1140,
   1140.6,
   1141.2,
   1141.8,
   1142.4,
   1143,
   1143.6,
   1144.2,
   1144.8,
   1145.4,
   1146,
   1146};
   Double_t sigLM_fy3[150] = {
   5.530582e-36,
   1.709941e-34,
   4.930645e-33,
   1.325986e-31,
   3.325727e-30,
   7.779412e-29,
   1.697147e-27,
   3.453064e-26,
   6.552428e-25,
   1.159611e-23,
   1.91397e-22,
   2.946254e-21,
   4.229781e-20,
   5.663411e-19,
   7.072138e-18,
   8.23637e-17,
   8.946095e-16,
   9.062409e-15,
   8.561824e-14,
   7.543996e-13,
   6.199392e-12,
   4.751265e-11,
   3.396111e-10,
   2.263951e-09,
   1.407553e-08,
   8.161589e-08,
   4.413645e-07,
   2.226038e-06,
   1.047081e-05,
   4.593463e-05,
   0.0001879372,
   0.0007171301,
   0.002552087,
   0.008470434,
   0.02621973,
   0.07569433,
   0.2038032,
   0.5117656,
   1.198515,
   2.617754,
   5.332448,
   10.13079,
   17.95448,
   29.75104,
   46.84271,
   58.72781,
   75.17966,
   86.28939,
   100.2792,
   118.1017,
   140.8803,
   169.8545,
   187.0602,
   206.279,
   227.6458,
   251.2751,
   277.2545,
   305.6377,
   336.4374,
   369.6185,
   405.092,
   442.7101,
   523.4727,
   609.4432,
   697.1651,
   782.3617,
   822.5283,
   860.2552,
   894.9388,
   926.0024,
   952.9133,
   975.1973,
   992.4538,
   1004.367,
   1010.718,
   1011.386,
   1006.361,
   995.7352,
   979.706,
   958.5672,
   932.7007,
   902.5645,
   868.679,
   831.6119,
   750.3434,
   576.1169,
   491.7835,
   413.723,
   377.7313,
   344.0028,
   312.64,
   283.6899,
   257.1505,
   232.9771,
   211.0895,
   191.3787,
   157.9498,
   131.4975,
   110.758,
   94.52692,
   81.74194,
   71.52244,
   56.18488,
   44.89404,
   35.88966,
   22.193,
   12.87486,
   6.970376,
   3.519676,
   1.657535,
   0.7280064,
   0.2982086,
   0.1139247,
   0.04059082,
   0.01348809,
   0.004180087,
   0.001208183,
   0.0003256813,
   8.187766e-05,
   1.919775e-05,
   4.198053e-06,
   8.561659e-07,
   1.628473e-07,
   2.888787e-08,
   4.779285e-09,
   7.374337e-10,
   1.061196e-10,
   1.424231e-11,
   1.782699e-12,
   2.081076e-13,
   2.265742e-14,
   2.300623e-15,
   2.178677e-16,
   1.924212e-17,
   1.584986e-18,
   1.217616e-19,
   8.723842e-21,
   5.829318e-22,
   3.63279e-23,
   2.111423e-24,
   1.144518e-25,
   5.786056e-27,
   2.728067e-28,
   1.19961e-29,
   4.919687e-31,
   1.881687e-32,
   6.712278e-34,
   2.233083e-35,
   6.928709e-37,
   6.928709e-37};
   graph = new TGraph(150,sigLM_fx3,sigLM_fy3);
   graph->SetName("sigLM");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);
   graph->SetLineColor(3);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_sigLM3 = new TH1F("Graph_sigLM3","Projection of totalPdf",150,1080,1152);
   Graph_sigLM3->SetMinimum(6.235838e-37);
   Graph_sigLM3->SetMaximum(1112.525);
   Graph_sigLM3->SetDirectory(0);
   Graph_sigLM3->SetStats(0);
   Graph_sigLM3->SetLineWidth(2);
   Graph_sigLM3->SetMarkerStyle(20);
   Graph_sigLM3->GetXaxis()->SetNdivisions(505);
   Graph_sigLM3->GetXaxis()->SetLabelFont(132);
   Graph_sigLM3->GetXaxis()->SetLabelOffset(0.01);
   Graph_sigLM3->GetXaxis()->SetLabelSize(0.06);
   Graph_sigLM3->GetXaxis()->SetTitleSize(0.072);
   Graph_sigLM3->GetXaxis()->SetTitleOffset(0.95);
   Graph_sigLM3->GetXaxis()->SetTitleFont(132);
   Graph_sigLM3->GetYaxis()->SetLabelFont(132);
   Graph_sigLM3->GetYaxis()->SetLabelOffset(0.01);
   Graph_sigLM3->GetYaxis()->SetLabelSize(0.06);
   Graph_sigLM3->GetYaxis()->SetTitleSize(0.072);
   Graph_sigLM3->GetYaxis()->SetTitleOffset(0.95);
   Graph_sigLM3->GetYaxis()->SetTitleFont(132);
   Graph_sigLM3->GetZaxis()->SetLabelFont(132);
   Graph_sigLM3->GetZaxis()->SetLabelSize(0.06);
   Graph_sigLM3->GetZaxis()->SetTitleSize(0.072);
   Graph_sigLM3->GetZaxis()->SetTitleOffset(1.2);
   Graph_sigLM3->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_sigLM3);
   
   graph->Draw("l");
   
   TLegend *leg = new TLegend(0.75,0.5,1,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(132);
   leg->SetTextSize(0.06);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("curvetot","Total PDF","l");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("bkg","Background","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(2);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("sigLM","#Lambda M (dbl Gaus)","l");
   entry->SetLineColor(3);
   entry->SetLineStyle(2);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   leg->Draw();
   
   TH1D *frame_3cf79b0__4 = new TH1D("frame_3cf79b0__4","A RooPlot of \"#Lambda mass\"",100,1086,1146);
   frame_3cf79b0__4->SetBinContent(1,1119.464);
   frame_3cf79b0__4->SetMinimum(1);
   frame_3cf79b0__4->SetMaximum(7500);
   frame_3cf79b0__4->SetEntries(1);
   frame_3cf79b0__4->SetDirectory(0);
   frame_3cf79b0__4->SetStats(0);
   frame_3cf79b0__4->SetLineWidth(2);
   frame_3cf79b0__4->SetMarkerStyle(20);
   frame_3cf79b0__4->GetXaxis()->SetTitle("#Lambda mass (MeV)");
   frame_3cf79b0__4->GetXaxis()->SetNdivisions(505);
   frame_3cf79b0__4->GetXaxis()->SetLabelFont(132);
   frame_3cf79b0__4->GetXaxis()->SetLabelOffset(0.01);
   frame_3cf79b0__4->GetXaxis()->SetLabelSize(0.06);
   frame_3cf79b0__4->GetXaxis()->SetTitleSize(0.072);
   frame_3cf79b0__4->GetXaxis()->SetTitleOffset(0.95);
   frame_3cf79b0__4->GetXaxis()->SetTitleFont(132);
   frame_3cf79b0__4->GetYaxis()->SetTitle("Events/(5 MeV)");
   frame_3cf79b0__4->GetYaxis()->SetLabelFont(132);
   frame_3cf79b0__4->GetYaxis()->SetLabelOffset(0.01);
   frame_3cf79b0__4->GetYaxis()->SetLabelSize(0.06);
   frame_3cf79b0__4->GetYaxis()->SetTitleSize(0.072);
   frame_3cf79b0__4->GetYaxis()->SetTitleOffset(0.95);
   frame_3cf79b0__4->GetYaxis()->SetTitleFont(132);
   frame_3cf79b0__4->GetZaxis()->SetLabelFont(132);
   frame_3cf79b0__4->GetZaxis()->SetLabelSize(0.06);
   frame_3cf79b0__4->GetZaxis()->SetTitleSize(0.072);
   frame_3cf79b0__4->GetZaxis()->SetTitleOffset(1.2);
   frame_3cf79b0__4->GetZaxis()->SetTitleFont(132);
   frame_3cf79b0__4->Draw("AXISSAME");
   pad1->Modified();
   c1->cd();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
