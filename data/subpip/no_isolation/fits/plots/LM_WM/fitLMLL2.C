void fitLMLL2()
{
//=========Macro generated from canvas: c1/data fits
//=========  (Tue May 10 17:45:52 2016) by ROOT version6.06/02
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
   
   TH1D *frame_4e18f70__1 = new TH1D("frame_4e18f70__1","",100,1086,1146);
   frame_4e18f70__1->SetBinContent(1,3.690675);
   frame_4e18f70__1->SetMinimum(-8.8);
   frame_4e18f70__1->SetMaximum(8.8);
   frame_4e18f70__1->SetEntries(1);
   frame_4e18f70__1->SetDirectory(0);
   frame_4e18f70__1->SetStats(0);
   frame_4e18f70__1->SetLineWidth(2);
   frame_4e18f70__1->SetMarkerStyle(20);
   frame_4e18f70__1->GetXaxis()->SetTitle("#Lambda mass (MeV)");
   frame_4e18f70__1->GetXaxis()->SetNdivisions(505);
   frame_4e18f70__1->GetXaxis()->SetLabelFont(132);
   frame_4e18f70__1->GetXaxis()->SetLabelOffset(0.01);
   frame_4e18f70__1->GetXaxis()->SetLabelSize(0.15);
   frame_4e18f70__1->GetXaxis()->SetTitleSize(0.2);
   frame_4e18f70__1->GetXaxis()->SetTitleOffset(1.1);
   frame_4e18f70__1->GetXaxis()->SetTitleFont(132);
   frame_4e18f70__1->GetYaxis()->SetTitle("Pull");
   frame_4e18f70__1->GetYaxis()->CenterTitle(true);
   frame_4e18f70__1->GetYaxis()->SetNdivisions(505);
   frame_4e18f70__1->GetYaxis()->SetLabelFont(132);
   frame_4e18f70__1->GetYaxis()->SetLabelOffset(0.01);
   frame_4e18f70__1->GetYaxis()->SetLabelSize(0.15);
   frame_4e18f70__1->GetYaxis()->SetTitleSize(0.15);
   frame_4e18f70__1->GetYaxis()->SetTitleOffset(0.45);
   frame_4e18f70__1->GetYaxis()->SetTitleFont(132);
   frame_4e18f70__1->GetZaxis()->SetLabelFont(132);
   frame_4e18f70__1->GetZaxis()->SetLabelSize(0.06);
   frame_4e18f70__1->GetZaxis()->SetTitleSize(0.072);
   frame_4e18f70__1->GetZaxis()->SetTitleOffset(1.2);
   frame_4e18f70__1->GetZaxis()->SetTitleFont(132);
   frame_4e18f70__1->Draw("FUNC");
   
   Double_t pull_Hist_curvetot_fx3001[76] = {
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
   1135.5};
   Double_t pull_Hist_curvetot_fy3001[76] = {
   0.5100437,
   -1.315701,
   -1.537205,
   1.371583,
   1.053899,
   0.7279355,
   0.02241236,
   0.04864639,
   0.4326879,
   -0.4674646,
   1.540642,
   -0.1957098,
   -0.1576182,
   0.05696638,
   0.4239856,
   -0.9710442,
   -2.769945,
   -0.8519245,
   0.08483413,
   0.7384269,
   -0.1534881,
   -0.7960629,
   -0.2173431,
   1.410387,
   -0.9639592,
   0.3966603,
   -0.653111,
   -0.9335096,
   -0.05217127,
   0.286456,
   -0.7858217,
   0.08996766,
   1.319637,
   1.282019,
   -0.4214709,
   0.5833935,
   -2.641153,
   -1.215655,
   -1.61158,
   0.08595243,
   0.009797382,
   1.586721,
   -0.7813001,
   -0.473925,
   -1.095841,
   1.462622,
   0.9384188,
   1.056559,
   2.231709,
   0.564468,
   -1.414357,
   0.3787934,
   0.4412312,
   -0.7396031,
   -0.9360588,
   1.279145,
   0.6712653,
   -0.548258,
   0.3501421,
   0.1843841,
   0.01697228,
   0.3651438,
   0.9335891,
   0.04282803,
   0.5145205,
   -1.450146,
   -0.4509549,
   0.9056129,
   -0.6458369,
   2.335408,
   -2.087991,
   -0.7188825,
   -0.06340284,
   -1.504546,
   -0.7788605,
   0.8605845};
   Double_t pull_Hist_curvetot_felx3001[76] = {
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
   Double_t pull_Hist_curvetot_fely3001[76] = {
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
   1};
   Double_t pull_Hist_curvetot_fehx3001[76] = {
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
   Double_t pull_Hist_curvetot_fehy3001[76] = {
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
   1};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(76,pull_Hist_curvetot_fx3001,pull_Hist_curvetot_fy3001,pull_Hist_curvetot_felx3001,pull_Hist_curvetot_fehx3001,pull_Hist_curvetot_fely3001,pull_Hist_curvetot_fehy3001);
   grae->SetName("pull_Hist_curvetot");
   grae->SetTitle("Pull of Histogram of data_plot__R_M and Projection of totalPdf");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(8);
   
   TH1F *Graph_pull_Hist_curvetot3001 = new TH1F("Graph_pull_Hist_curvetot3001","Pull of Histogram of data_plot__R_M and Projection of totalPdf",100,1086,1140);
   Graph_pull_Hist_curvetot3001->SetMinimum(-4.48048);
   Graph_pull_Hist_curvetot3001->SetMaximum(4.045943);
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
   
   TH1D *frame_4e18f70__2 = new TH1D("frame_4e18f70__2","",100,1086,1146);
   frame_4e18f70__2->SetBinContent(1,3.690675);
   frame_4e18f70__2->SetMinimum(-8.8);
   frame_4e18f70__2->SetMaximum(8.8);
   frame_4e18f70__2->SetEntries(1);
   frame_4e18f70__2->SetDirectory(0);
   frame_4e18f70__2->SetStats(0);
   frame_4e18f70__2->SetLineWidth(2);
   frame_4e18f70__2->SetMarkerStyle(20);
   frame_4e18f70__2->GetXaxis()->SetTitle("#Lambda mass (MeV)");
   frame_4e18f70__2->GetXaxis()->SetNdivisions(505);
   frame_4e18f70__2->GetXaxis()->SetLabelFont(132);
   frame_4e18f70__2->GetXaxis()->SetLabelOffset(0.01);
   frame_4e18f70__2->GetXaxis()->SetLabelSize(0.15);
   frame_4e18f70__2->GetXaxis()->SetTitleSize(0.2);
   frame_4e18f70__2->GetXaxis()->SetTitleOffset(1.1);
   frame_4e18f70__2->GetXaxis()->SetTitleFont(132);
   frame_4e18f70__2->GetYaxis()->SetTitle("Pull");
   frame_4e18f70__2->GetYaxis()->CenterTitle(true);
   frame_4e18f70__2->GetYaxis()->SetNdivisions(505);
   frame_4e18f70__2->GetYaxis()->SetLabelFont(132);
   frame_4e18f70__2->GetYaxis()->SetLabelOffset(0.01);
   frame_4e18f70__2->GetYaxis()->SetLabelSize(0.15);
   frame_4e18f70__2->GetYaxis()->SetTitleSize(0.15);
   frame_4e18f70__2->GetYaxis()->SetTitleOffset(0.45);
   frame_4e18f70__2->GetYaxis()->SetTitleFont(132);
   frame_4e18f70__2->GetZaxis()->SetLabelFont(132);
   frame_4e18f70__2->GetZaxis()->SetLabelSize(0.06);
   frame_4e18f70__2->GetZaxis()->SetTitleSize(0.072);
   frame_4e18f70__2->GetZaxis()->SetTitleOffset(1.2);
   frame_4e18f70__2->GetZaxis()->SetTitleFont(132);
   frame_4e18f70__2->Draw("AXISSAME");
   pad2->Modified();
   c1->cd();
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "pad1",0,0.3,1,1);
   pad1->Draw();
   pad1->cd();
   pad1->Range(1075.63,0,1149.704,1563.739);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
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
   
   TH1D *frame_4b75b90__3 = new TH1D("frame_4b75b90__3","A RooPlot of \"#Lambda mass\"",100,1086,1146);
   frame_4b75b90__3->SetBinContent(1,1469.915);
   frame_4b75b90__3->SetMaximum(1469.915);
   frame_4b75b90__3->SetEntries(1);
   frame_4b75b90__3->SetDirectory(0);
   frame_4b75b90__3->SetStats(0);
   frame_4b75b90__3->SetLineWidth(2);
   frame_4b75b90__3->SetMarkerStyle(20);
   frame_4b75b90__3->GetXaxis()->SetTitle("#Lambda mass (MeV)");
   frame_4b75b90__3->GetXaxis()->SetNdivisions(505);
   frame_4b75b90__3->GetXaxis()->SetLabelFont(132);
   frame_4b75b90__3->GetXaxis()->SetLabelOffset(0.01);
   frame_4b75b90__3->GetXaxis()->SetLabelSize(0.06);
   frame_4b75b90__3->GetXaxis()->SetTitleSize(0.072);
   frame_4b75b90__3->GetXaxis()->SetTitleOffset(0.95);
   frame_4b75b90__3->GetXaxis()->SetTitleFont(132);
   frame_4b75b90__3->GetYaxis()->SetTitle("Events/(5 MeV)");
   frame_4b75b90__3->GetYaxis()->SetLabelFont(132);
   frame_4b75b90__3->GetYaxis()->SetLabelOffset(0.01);
   frame_4b75b90__3->GetYaxis()->SetLabelSize(0.06);
   frame_4b75b90__3->GetYaxis()->SetTitleSize(0.072);
   frame_4b75b90__3->GetYaxis()->SetTitleOffset(0.95);
   frame_4b75b90__3->GetYaxis()->SetTitleFont(132);
   frame_4b75b90__3->GetZaxis()->SetLabelFont(132);
   frame_4b75b90__3->GetZaxis()->SetLabelSize(0.06);
   frame_4b75b90__3->GetZaxis()->SetTitleSize(0.072);
   frame_4b75b90__3->GetZaxis()->SetTitleOffset(1.2);
   frame_4b75b90__3->GetZaxis()->SetTitleFont(132);
   frame_4b75b90__3->Draw("FUNC");
   
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
   17,
   20,
   22,
   33,
   22,
   28,
   18,
   24,
   17,
   17,
   32,
   31,
   30,
   27,
   28,
   31,
   27,
   40,
   30,
   31,
   33,
   36,
   29,
   22,
   31,
   37,
   42,
   37,
   34,
   38,
   50,
   35,
   44,
   38,
   37,
   43,
   46,
   40,
   47,
   59,
   64,
   60,
   85,
   82,
   133,
   193,
   358,
   659,
   1156,
   1363,
   1224,
   776,
   473,
   270,
   185,
   152,
   99,
   64,
   68,
   63,
   52,
   50,
   67,
   62,
   53,
   60,
   59,
   58,
   61,
   66,
   59,
   63,
   49,
   56,
   67,
   55,
   81,
   46,
   55,
   60,
   50,
   55,
   68,
   57,
   57,
   53,
   52,
   57,
   67,
   56,
   51,
   70,
   71,
   70,
   53,
   67,
   66,
   65,
   77,
   24};
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
   4.123106,
   4.472136,
   4.690416,
   5.744563,
   4.690416,
   5.291503,
   4.242641,
   4.898979,
   4.123106,
   4.123106,
   5.656854,
   5.567764,
   5.477226,
   5.196152,
   5.291503,
   5.567764,
   5.196152,
   6.324555,
   5.477226,
   5.567764,
   5.744563,
   6,
   5.385165,
   4.690416,
   5.567764,
   6.082763,
   6.480741,
   6.082763,
   5.830952,
   6.164414,
   7.071068,
   5.91608,
   6.63325,
   6.164414,
   6.082763,
   6.557439,
   6.78233,
   6.324555,
   6.855655,
   7.681146,
   8,
   7.745967,
   9.219544,
   9.055385,
   11.53256,
   13.89244,
   18.92089,
   25.671,
   34,
   36.91883,
   34.98571,
   27.85678,
   21.74856,
   16.43168,
   13.60147,
   12.32883,
   9.949874,
   8,
   8.246211,
   7.937254,
   7.211103,
   7.071068,
   8.185353,
   7.874008,
   7.28011,
   7.745967,
   7.681146,
   7.615773,
   7.81025,
   8.124038,
   7.681146,
   7.937254,
   7,
   7.483315,
   8.185353,
   7.416198,
   9,
   6.78233,
   7.416198,
   7.745967,
   7.071068,
   7.416198,
   8.246211,
   7.549834,
   7.549834,
   7.28011,
   7.211103,
   7.549834,
   8.185353,
   7.483315,
   7.141428,
   8.3666,
   8.42615,
   8.3666,
   7.28011,
   8.185353,
   8.124038,
   8.062258,
   8.774964,
   4.898979};
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
   4.123106,
   4.472136,
   4.690416,
   5.744563,
   4.690416,
   5.291503,
   4.242641,
   4.898979,
   4.123106,
   4.123106,
   5.656854,
   5.567764,
   5.477226,
   5.196152,
   5.291503,
   5.567764,
   5.196152,
   6.324555,
   5.477226,
   5.567764,
   5.744563,
   6,
   5.385165,
   4.690416,
   5.567764,
   6.082763,
   6.480741,
   6.082763,
   5.830952,
   6.164414,
   7.071068,
   5.91608,
   6.63325,
   6.164414,
   6.082763,
   6.557439,
   6.78233,
   6.324555,
   6.855655,
   7.681146,
   8,
   7.745967,
   9.219544,
   9.055385,
   11.53256,
   13.89244,
   18.92089,
   25.671,
   34,
   36.91883,
   34.98571,
   27.85678,
   21.74856,
   16.43168,
   13.60147,
   12.32883,
   9.949874,
   8,
   8.246211,
   7.937254,
   7.211103,
   7.071068,
   8.185353,
   7.874008,
   7.28011,
   7.745967,
   7.681146,
   7.615773,
   7.81025,
   8.124038,
   7.681146,
   7.937254,
   7,
   7.483315,
   8.185353,
   7.416198,
   9,
   6.78233,
   7.416198,
   7.745967,
   7.071068,
   7.416198,
   8.246211,
   7.549834,
   7.549834,
   7.28011,
   7.211103,
   7.549834,
   8.185353,
   7.483315,
   7.141428,
   8.3666,
   8.42615,
   8.3666,
   7.28011,
   8.185353,
   8.124038,
   8.062258,
   8.774964,
   4.898979};
   grae = new TGraphAsymmErrors(100,Hist_fx3002,Hist_fy3002,Hist_felx3002,Hist_fehx3002,Hist_fely3002,Hist_fehy3002);
   grae->SetName("Hist");
   grae->SetTitle("Histogram of data_plot__R_M");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(8);
   
   TH1F *Graph_Hist3002 = new TH1F("Graph_Hist3002","Histogram of data_plot__R_M",100,1080,1152);
   Graph_Hist3002->SetMinimum(0);
   Graph_Hist3002->SetMaximum(1538.623);
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
   
   Double_t curvetot_fx1[144] = {
   1090,
   1090.46,
   1090.92,
   1091.38,
   1091.84,
   1092.3,
   1092.76,
   1093.22,
   1093.68,
   1094.14,
   1094.6,
   1095.06,
   1095.52,
   1095.98,
   1096.44,
   1096.9,
   1097.36,
   1097.82,
   1098.28,
   1098.74,
   1099.2,
   1099.66,
   1100.12,
   1100.58,
   1101.04,
   1101.5,
   1101.96,
   1102.42,
   1102.88,
   1103.34,
   1103.8,
   1104.26,
   1104.72,
   1105.18,
   1105.64,
   1106.1,
   1106.56,
   1107.02,
   1107.48,
   1107.94,
   1108.4,
   1108.86,
   1109.32,
   1109.78,
   1110.24,
   1110.7,
   1111.16,
   1111.62,
   1112.08,
   1112.54,
   1112.77,
   1113,
   1113.23,
   1113.46,
   1113.575,
   1113.69,
   1113.805,
   1113.92,
   1114.035,
   1114.15,
   1114.265,
   1114.38,
   1114.495,
   1114.61,
   1114.725,
   1114.84,
   1115.07,
   1115.185,
   1115.3,
   1115.358,
   1115.415,
   1115.472,
   1115.53,
   1115.588,
   1115.645,
   1115.702,
   1115.76,
   1115.818,
   1115.875,
   1115.932,
   1115.99,
   1116.048,
   1116.105,
   1116.162,
   1116.22,
   1116.278,
   1116.335,
   1116.45,
   1116.565,
   1116.68,
   1116.91,
   1117.025,
   1117.14,
   1117.255,
   1117.37,
   1117.485,
   1117.6,
   1117.715,
   1117.83,
   1117.945,
   1118.06,
   1118.175,
   1118.29,
   1118.52,
   1118.75,
   1118.98,
   1119.44,
   1119.9,
   1120.36,
   1120.82,
   1121.28,
   1121.74,
   1122.2,
   1122.66,
   1123.12,
   1123.58,
   1124.04,
   1124.5,
   1124.96,
   1125.42,
   1125.88,
   1126.34,
   1126.8,
   1127.26,
   1127.72,
   1128.18,
   1128.64,
   1129.1,
   1129.56,
   1130.02,
   1130.48,
   1130.94,
   1131.4,
   1131.86,
   1132.32,
   1132.78,
   1133.24,
   1133.7,
   1134.16,
   1134.62,
   1135.08,
   1135.54,
   1136,
   1136};
   Double_t curvetot_fy1[144] = {
   20.72335,
   21.43958,
   22.14947,
   22.85303,
   23.55026,
   24.24116,
   24.92572,
   25.60395,
   26.27585,
   26.94142,
   27.60065,
   28.25355,
   28.90012,
   29.54036,
   30.17427,
   30.80184,
   31.42308,
   32.03799,
   32.64657,
   33.24881,
   33.84472,
   34.4343,
   35.01755,
   35.59447,
   36.16505,
   36.7293,
   37.28722,
   37.8388,
   38.38406,
   38.92298,
   39.45557,
   39.98185,
   40.50182,
   41.01559,
   41.52341,
   42.02605,
   42.52559,
   43.0274,
   43.54442,
   44.10599,
   44.77447,
   45.67378,
   47.03353,
   49.24897,
   52.94842,
   59.04672,
   68.74807,
   83.45902,
   104.6407,
   133.9875,
   152.7212,
   175.4098,
   203.9615,
   241.5083,
   265.027,
   292.6107,
   325.0076,
   362.9771,
   407.2315,
   458.3631,
   516.758,
   582.5057,
   655.3093,
   734.4108,
   818.54,
   905.9002,
   1080.724,
   1162.48,
   1236.35,
   1269.373,
   1299.306,
   1325.82,
   1348.615,
   1367.429,
   1382.045,
   1392.29,
   1398.043,
   1399.236,
   1395.855,
   1387.94,
   1375.588,
   1358.945,
   1338.206,
   1313.612,
   1285.444,
   1254.018,
   1219.678,
   1143.732,
   1060.679,
   973.6213,
   798.9314,
   716.0903,
   638.6431,
   567.7293,
   503.986,
   447.606,
   398.4173,
   355.9737,
   319.6456,
   288.7026,
   262.3833,
   239.9494,
   220.7227,
   189.602,
   165.359,
   145.6666,
   115.219,
   93.38361,
   78.29814,
   68.49591,
   62.54956,
   59.2072,
   57.49764,
   56.74193,
   56.50619,
   56.53471,
   56.68759,
   56.89354,
   57.11857,
   57.34754,
   57.57408,
   57.7957,
   58.01145,
   58.22103,
   58.42432,
   58.6213,
   58.81194,
   58.99626,
   59.17424,
   59.34589,
   59.5112,
   59.67019,
   59.82284,
   59.96916,
   60.10915,
   60.2428,
   60.37013,
   60.49112,
   60.60577,
   60.7141,
   60.81609,
   60.91176,
   61.00109,
   61.00109};
   TGraph *graph = new TGraph(144,curvetot_fx1,curvetot_fy1);
   graph->SetName("curvetot");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_curvetot1 = new TH1F("Graph_curvetot1","Projection of totalPdf",144,1085.4,1140.6);
   Graph_curvetot1->SetMinimum(0);
   Graph_curvetot1->SetMaximum(1537.087);
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
   
   Double_t sigLM_fx2[145] = {
   1090,
   1090.46,
   1090.92,
   1091.38,
   1091.84,
   1092.3,
   1092.76,
   1093.22,
   1093.68,
   1094.14,
   1094.6,
   1095.06,
   1095.52,
   1095.98,
   1096.44,
   1096.9,
   1097.36,
   1097.82,
   1098.28,
   1098.74,
   1099.2,
   1099.66,
   1100.12,
   1100.58,
   1101.04,
   1101.5,
   1101.96,
   1102.42,
   1102.88,
   1103.34,
   1103.8,
   1104.26,
   1104.72,
   1105.18,
   1105.64,
   1106.1,
   1106.56,
   1107.02,
   1107.48,
   1107.94,
   1108.4,
   1108.86,
   1109.32,
   1109.78,
   1110.24,
   1110.7,
   1111.16,
   1111.62,
   1112.08,
   1112.54,
   1112.77,
   1113,
   1113.23,
   1113.345,
   1113.46,
   1113.575,
   1113.69,
   1113.805,
   1113.92,
   1114.035,
   1114.15,
   1114.265,
   1114.38,
   1114.495,
   1114.61,
   1114.725,
   1114.84,
   1115.07,
   1115.185,
   1115.3,
   1115.358,
   1115.415,
   1115.472,
   1115.53,
   1115.588,
   1115.645,
   1115.702,
   1115.76,
   1115.818,
   1115.875,
   1115.932,
   1115.99,
   1116.048,
   1116.105,
   1116.162,
   1116.22,
   1116.278,
   1116.335,
   1116.45,
   1116.565,
   1116.68,
   1116.91,
   1117.025,
   1117.14,
   1117.255,
   1117.37,
   1117.485,
   1117.6,
   1117.715,
   1117.83,
   1117.945,
   1118.06,
   1118.175,
   1118.29,
   1118.52,
   1118.75,
   1118.98,
   1119.44,
   1119.9,
   1120.36,
   1120.82,
   1121.28,
   1121.74,
   1122.2,
   1122.66,
   1123.12,
   1123.58,
   1124.04,
   1124.5,
   1124.96,
   1125.42,
   1125.88,
   1126.34,
   1126.8,
   1127.26,
   1127.72,
   1128.18,
   1128.64,
   1129.1,
   1129.56,
   1130.02,
   1130.48,
   1130.94,
   1131.4,
   1131.86,
   1132.32,
   1132.78,
   1133.24,
   1133.7,
   1134.16,
   1134.62,
   1135.08,
   1135.54,
   1136,
   1136};
   Double_t sigLM_fy2[145] = {
   2.621204e-34,
   4.938872e-33,
   8.827103e-32,
   1.496484e-30,
   2.40652e-29,
   3.670883e-28,
   5.311473e-27,
   7.289924e-26,
   9.490619e-25,
   1.172005e-23,
   1.372866e-22,
   1.525423e-21,
   1.60774e-20,
   1.607329e-19,
   1.524255e-18,
   1.371114e-17,
   1.169912e-16,
   9.468833e-16,
   7.269476e-15,
   5.293871e-14,
   3.656849e-13,
   2.396096e-12,
   1.489241e-11,
   8.779895e-11,
   4.90995e-10,
   2.604524e-09,
   1.310519e-08,
   6.254917e-08,
   2.831805e-07,
   1.216099e-06,
   4.953791e-06,
   1.914124e-05,
   7.015619e-05,
   0.0002439077,
   0.0008043561,
   0.00251614,
   0.007465946,
   0.0210135,
   0.05610161,
   0.1420744,
   0.3412872,
   0.777656,
   1.68081,
   3.445984,
   6.701493,
   12.36219,
   21.63226,
   35.91827,
   56.68136,
   85.61583,
   104.1458,
   126.6322,
   154.9833,
   172.2811,
   192.3311,
   215.7509,
   243.236,
   275.5349,
   313.4066,
   357.5638,
   408.5983,
   466.8968,
   532.5483,
   605.2561,
   684.2623,
   768.2965,
   855.5622,
   1030.198,
   1111.86,
   1185.638,
   1218.614,
   1248.501,
   1274.969,
   1297.718,
   1316.486,
   1331.056,
   1341.256,
   1346.963,
   1348.11,
   1344.683,
   1336.724,
   1324.326,
   1307.638,
   1286.854,
   1262.215,
   1234.002,
   1202.532,
   1168.146,
   1092.112,
   1008.97,
   921.8241,
   746.9589,
   664.0308,
   586.497,
   515.4969,
   451.6678,
   395.2023,
   345.9285,
   303.4003,
   266.988,
   235.9611,
   209.5583,
   187.0413,
   167.7319,
   136.4471,
   112.0414,
   92.18796,
   61.4231,
   39.27676,
   23.88666,
   13.78614,
   7.547821,
   3.919831,
   1.930976,
   0.9022979,
   0.3999324,
   0.168146,
   0.06705795,
   0.02536749,
   0.009102655,
   0.003098291,
   0.001000322,
   0.0003063523,
   8.899506e-05,
   2.452303e-05,
   6.409821e-06,
   1.58921e-06,
   3.737489e-07,
   8.337623e-08,
   1.764282e-08,
   3.541257e-09,
   6.742335e-10,
   1.217662e-10,
   2.085963e-11,
   3.389612e-12,
   5.224647e-13,
   7.638839e-14,
   1.059403e-14,
   1.393666e-15,
   1.739081e-16,
   2.058469e-17,
   2.311172e-18,
   2.46141e-19,
   2.48656e-20,
   2.48656e-20};
   graph = new TGraph(145,sigLM_fx2,sigLM_fy2);
   graph->SetName("sigLM");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);
   graph->SetLineColor(2);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_sigLM2 = new TH1F("Graph_sigLM2","Projection of totalPdf",145,1085.4,1140.6);
   Graph_sigLM2->SetMinimum(0);
   Graph_sigLM2->SetMaximum(1482.921);
   Graph_sigLM2->SetDirectory(0);
   Graph_sigLM2->SetStats(0);
   Graph_sigLM2->SetLineWidth(2);
   Graph_sigLM2->SetMarkerStyle(20);
   Graph_sigLM2->GetXaxis()->SetNdivisions(505);
   Graph_sigLM2->GetXaxis()->SetLabelFont(132);
   Graph_sigLM2->GetXaxis()->SetLabelOffset(0.01);
   Graph_sigLM2->GetXaxis()->SetLabelSize(0.06);
   Graph_sigLM2->GetXaxis()->SetTitleSize(0.072);
   Graph_sigLM2->GetXaxis()->SetTitleOffset(0.95);
   Graph_sigLM2->GetXaxis()->SetTitleFont(132);
   Graph_sigLM2->GetYaxis()->SetLabelFont(132);
   Graph_sigLM2->GetYaxis()->SetLabelOffset(0.01);
   Graph_sigLM2->GetYaxis()->SetLabelSize(0.06);
   Graph_sigLM2->GetYaxis()->SetTitleSize(0.072);
   Graph_sigLM2->GetYaxis()->SetTitleOffset(0.95);
   Graph_sigLM2->GetYaxis()->SetTitleFont(132);
   Graph_sigLM2->GetZaxis()->SetLabelFont(132);
   Graph_sigLM2->GetZaxis()->SetLabelSize(0.06);
   Graph_sigLM2->GetZaxis()->SetTitleSize(0.072);
   Graph_sigLM2->GetZaxis()->SetTitleOffset(1.2);
   Graph_sigLM2->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_sigLM2);
   
   graph->Draw("l");
   
   Double_t bkg_fx3[102] = {
   1090,
   1090.46,
   1090.92,
   1091.38,
   1091.84,
   1092.3,
   1092.76,
   1093.22,
   1093.68,
   1094.14,
   1094.6,
   1095.06,
   1095.52,
   1095.98,
   1096.44,
   1096.9,
   1097.36,
   1097.82,
   1098.28,
   1098.74,
   1099.2,
   1099.66,
   1100.12,
   1100.58,
   1101.04,
   1101.5,
   1101.96,
   1102.42,
   1102.88,
   1103.34,
   1103.8,
   1104.26,
   1104.72,
   1105.18,
   1105.64,
   1106.1,
   1106.56,
   1107.02,
   1107.48,
   1107.94,
   1108.4,
   1108.86,
   1109.32,
   1109.78,
   1110.24,
   1110.7,
   1111.16,
   1111.62,
   1112.08,
   1112.54,
   1113,
   1113.46,
   1113.92,
   1114.38,
   1114.84,
   1115.3,
   1115.76,
   1116.22,
   1116.68,
   1117.14,
   1117.6,
   1118.06,
   1118.52,
   1118.98,
   1119.44,
   1119.9,
   1120.36,
   1120.82,
   1121.28,
   1121.74,
   1122.2,
   1122.66,
   1123.12,
   1123.58,
   1124.04,
   1124.5,
   1124.96,
   1125.42,
   1125.88,
   1126.34,
   1126.8,
   1127.26,
   1127.72,
   1128.18,
   1128.64,
   1129.1,
   1129.56,
   1130.02,
   1130.48,
   1130.94,
   1131.4,
   1131.86,
   1132.32,
   1132.78,
   1133.24,
   1133.7,
   1134.16,
   1134.62,
   1135.08,
   1135.54,
   1136,
   1136};
   Double_t bkg_fy3[102] = {
   20.72335,
   21.43958,
   22.14947,
   22.85303,
   23.55026,
   24.24116,
   24.92572,
   25.60395,
   26.27585,
   26.94142,
   27.60065,
   28.25355,
   28.90012,
   29.54036,
   30.17427,
   30.80184,
   31.42308,
   32.03799,
   32.64657,
   33.24881,
   33.84472,
   34.4343,
   35.01755,
   35.59447,
   36.16505,
   36.7293,
   37.28722,
   37.8388,
   38.38406,
   38.92298,
   39.45557,
   39.98183,
   40.50175,
   41.01534,
   41.5226,
   42.02353,
   42.51813,
   43.00639,
   43.48832,
   43.96392,
   44.43318,
   44.89612,
   45.35272,
   45.80299,
   46.24693,
   46.68453,
   47.1158,
   47.54075,
   47.95935,
   48.37163,
   48.77757,
   49.17718,
   49.57046,
   49.95741,
   50.33802,
   50.71231,
   51.08026,
   51.44187,
   51.79716,
   52.14611,
   52.48873,
   52.82502,
   53.15498,
   53.4786,
   53.79589,
   54.10685,
   54.41148,
   54.70977,
   55.00173,
   55.28737,
   55.56666,
   55.83963,
   56.10626,
   56.36656,
   56.62053,
   56.86817,
   57.10947,
   57.34444,
   57.57308,
   57.79539,
   58.01137,
   58.22101,
   58.42432,
   58.6213,
   58.81194,
   58.99626,
   59.17424,
   59.34589,
   59.5112,
   59.67019,
   59.82284,
   59.96916,
   60.10915,
   60.2428,
   60.37013,
   60.49112,
   60.60577,
   60.7141,
   60.81609,
   60.91176,
   61.00109,
   61.00109};
   graph = new TGraph(102,bkg_fx3,bkg_fy3);
   graph->SetName("bkg");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);
   graph->SetLineColor(3);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_bkg3 = new TH1F("Graph_bkg3","Projection of totalPdf",102,1085.4,1140.6);
   Graph_bkg3->SetMinimum(16.69558);
   Graph_bkg3->SetMaximum(65.02886);
   Graph_bkg3->SetDirectory(0);
   Graph_bkg3->SetStats(0);
   Graph_bkg3->SetLineWidth(2);
   Graph_bkg3->SetMarkerStyle(20);
   Graph_bkg3->GetXaxis()->SetNdivisions(505);
   Graph_bkg3->GetXaxis()->SetLabelFont(132);
   Graph_bkg3->GetXaxis()->SetLabelOffset(0.01);
   Graph_bkg3->GetXaxis()->SetLabelSize(0.06);
   Graph_bkg3->GetXaxis()->SetTitleSize(0.072);
   Graph_bkg3->GetXaxis()->SetTitleOffset(0.95);
   Graph_bkg3->GetXaxis()->SetTitleFont(132);
   Graph_bkg3->GetYaxis()->SetLabelFont(132);
   Graph_bkg3->GetYaxis()->SetLabelOffset(0.01);
   Graph_bkg3->GetYaxis()->SetLabelSize(0.06);
   Graph_bkg3->GetYaxis()->SetTitleSize(0.072);
   Graph_bkg3->GetYaxis()->SetTitleOffset(0.95);
   Graph_bkg3->GetYaxis()->SetTitleFont(132);
   Graph_bkg3->GetZaxis()->SetLabelFont(132);
   Graph_bkg3->GetZaxis()->SetLabelSize(0.06);
   Graph_bkg3->GetZaxis()->SetTitleSize(0.072);
   Graph_bkg3->GetZaxis()->SetTitleOffset(1.2);
   Graph_bkg3->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_bkg3);
   
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
   entry=leg->AddEntry("sigLM","#Lambda M (dbl Gaus)","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(2);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("bkg","Background","l");
   entry->SetLineColor(3);
   entry->SetLineStyle(2);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   leg->Draw();
   
   TH1D *frame_4b75b90__4 = new TH1D("frame_4b75b90__4","A RooPlot of \"#Lambda mass\"",100,1086,1146);
   frame_4b75b90__4->SetBinContent(1,1469.915);
   frame_4b75b90__4->SetMaximum(1469.915);
   frame_4b75b90__4->SetEntries(1);
   frame_4b75b90__4->SetDirectory(0);
   frame_4b75b90__4->SetStats(0);
   frame_4b75b90__4->SetLineWidth(2);
   frame_4b75b90__4->SetMarkerStyle(20);
   frame_4b75b90__4->GetXaxis()->SetTitle("#Lambda mass (MeV)");
   frame_4b75b90__4->GetXaxis()->SetNdivisions(505);
   frame_4b75b90__4->GetXaxis()->SetLabelFont(132);
   frame_4b75b90__4->GetXaxis()->SetLabelOffset(0.01);
   frame_4b75b90__4->GetXaxis()->SetLabelSize(0.06);
   frame_4b75b90__4->GetXaxis()->SetTitleSize(0.072);
   frame_4b75b90__4->GetXaxis()->SetTitleOffset(0.95);
   frame_4b75b90__4->GetXaxis()->SetTitleFont(132);
   frame_4b75b90__4->GetYaxis()->SetTitle("Events/(5 MeV)");
   frame_4b75b90__4->GetYaxis()->SetLabelFont(132);
   frame_4b75b90__4->GetYaxis()->SetLabelOffset(0.01);
   frame_4b75b90__4->GetYaxis()->SetLabelSize(0.06);
   frame_4b75b90__4->GetYaxis()->SetTitleSize(0.072);
   frame_4b75b90__4->GetYaxis()->SetTitleOffset(0.95);
   frame_4b75b90__4->GetYaxis()->SetTitleFont(132);
   frame_4b75b90__4->GetZaxis()->SetLabelFont(132);
   frame_4b75b90__4->GetZaxis()->SetLabelSize(0.06);
   frame_4b75b90__4->GetZaxis()->SetTitleSize(0.072);
   frame_4b75b90__4->GetZaxis()->SetTitleOffset(1.2);
   frame_4b75b90__4->GetZaxis()->SetTitleFont(132);
   frame_4b75b90__4->Draw("AXISSAME");
   pad1->Modified();
   c1->cd();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
