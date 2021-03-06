void fitLMLL1testbkg2()
{
//=========Macro generated from canvas: c1/data fits
//=========  (Tue May 10 15:06:15 2016) by ROOT version6.06/02
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
   
   TH1D *frame_4efb950__1 = new TH1D("frame_4efb950__1","",100,1086,1146);
   frame_4efb950__1->SetBinContent(1,3.572229);
   frame_4efb950__1->SetMinimum(-8.8);
   frame_4efb950__1->SetMaximum(8.8);
   frame_4efb950__1->SetEntries(1);
   frame_4efb950__1->SetDirectory(0);
   frame_4efb950__1->SetStats(0);
   frame_4efb950__1->SetLineWidth(2);
   frame_4efb950__1->SetMarkerStyle(20);
   frame_4efb950__1->GetXaxis()->SetTitle("#Lambda mass (MeV)");
   frame_4efb950__1->GetXaxis()->SetNdivisions(505);
   frame_4efb950__1->GetXaxis()->SetLabelFont(132);
   frame_4efb950__1->GetXaxis()->SetLabelOffset(0.01);
   frame_4efb950__1->GetXaxis()->SetLabelSize(0.15);
   frame_4efb950__1->GetXaxis()->SetTitleSize(0.2);
   frame_4efb950__1->GetXaxis()->SetTitleOffset(1.1);
   frame_4efb950__1->GetXaxis()->SetTitleFont(132);
   frame_4efb950__1->GetYaxis()->SetTitle("Pull");
   frame_4efb950__1->GetYaxis()->CenterTitle(true);
   frame_4efb950__1->GetYaxis()->SetNdivisions(505);
   frame_4efb950__1->GetYaxis()->SetLabelFont(132);
   frame_4efb950__1->GetYaxis()->SetLabelOffset(0.01);
   frame_4efb950__1->GetYaxis()->SetLabelSize(0.15);
   frame_4efb950__1->GetYaxis()->SetTitleSize(0.15);
   frame_4efb950__1->GetYaxis()->SetTitleOffset(0.45);
   frame_4efb950__1->GetYaxis()->SetTitleFont(132);
   frame_4efb950__1->GetZaxis()->SetLabelFont(132);
   frame_4efb950__1->GetZaxis()->SetLabelSize(0.06);
   frame_4efb950__1->GetZaxis()->SetTitleSize(0.072);
   frame_4efb950__1->GetZaxis()->SetTitleOffset(1.2);
   frame_4efb950__1->GetZaxis()->SetTitleFont(132);
   frame_4efb950__1->Draw("FUNC");
   
   Double_t pull_Hist_curvetot_fx3001[20] = {
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
   Double_t pull_Hist_curvetot_fy3001[20] = {
   1.017965,
   -0.2069978,
   0.6417016,
   0.4489128,
   0.2528608,
   0.5637843,
   1.093159,
   0.1768523,
   0.609278,
   -1.383777,
   -0.4288038,
   0.888012,
   -0.7084145,
   2.247092,
   -2.255657,
   -0.9197495,
   -0.3025418,
   -1.819515,
   -1.131084,
   0.4958906};
   Double_t pull_Hist_curvetot_felx3001[20] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t pull_Hist_curvetot_fely3001[20] = {
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
   Double_t pull_Hist_curvetot_fehx3001[20] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t pull_Hist_curvetot_fehy3001[20] = {
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
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(20,pull_Hist_curvetot_fx3001,pull_Hist_curvetot_fy3001,pull_Hist_curvetot_felx3001,pull_Hist_curvetot_fehx3001,pull_Hist_curvetot_fely3001,pull_Hist_curvetot_fehy3001);
   grae->SetName("pull_Hist_curvetot");
   grae->SetTitle("Pull of Histogram of data_plot__R_M and Projection of totalPdf");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(8);
   
   TH1F *Graph_pull_Hist_curvetot3001 = new TH1F("Graph_pull_Hist_curvetot3001","Pull of Histogram of data_plot__R_M and Projection of totalPdf",100,1122.96,1136.64);
   Graph_pull_Hist_curvetot3001->SetMinimum(-3.905932);
   Graph_pull_Hist_curvetot3001->SetMaximum(3.897366);
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
   
   TH1D *frame_4efb950__2 = new TH1D("frame_4efb950__2","",100,1086,1146);
   frame_4efb950__2->SetBinContent(1,3.572229);
   frame_4efb950__2->SetMinimum(-8.8);
   frame_4efb950__2->SetMaximum(8.8);
   frame_4efb950__2->SetEntries(1);
   frame_4efb950__2->SetDirectory(0);
   frame_4efb950__2->SetStats(0);
   frame_4efb950__2->SetLineWidth(2);
   frame_4efb950__2->SetMarkerStyle(20);
   frame_4efb950__2->GetXaxis()->SetTitle("#Lambda mass (MeV)");
   frame_4efb950__2->GetXaxis()->SetNdivisions(505);
   frame_4efb950__2->GetXaxis()->SetLabelFont(132);
   frame_4efb950__2->GetXaxis()->SetLabelOffset(0.01);
   frame_4efb950__2->GetXaxis()->SetLabelSize(0.15);
   frame_4efb950__2->GetXaxis()->SetTitleSize(0.2);
   frame_4efb950__2->GetXaxis()->SetTitleOffset(1.1);
   frame_4efb950__2->GetXaxis()->SetTitleFont(132);
   frame_4efb950__2->GetYaxis()->SetTitle("Pull");
   frame_4efb950__2->GetYaxis()->CenterTitle(true);
   frame_4efb950__2->GetYaxis()->SetNdivisions(505);
   frame_4efb950__2->GetYaxis()->SetLabelFont(132);
   frame_4efb950__2->GetYaxis()->SetLabelOffset(0.01);
   frame_4efb950__2->GetYaxis()->SetLabelSize(0.15);
   frame_4efb950__2->GetYaxis()->SetTitleSize(0.15);
   frame_4efb950__2->GetYaxis()->SetTitleOffset(0.45);
   frame_4efb950__2->GetYaxis()->SetTitleFont(132);
   frame_4efb950__2->GetZaxis()->SetLabelFont(132);
   frame_4efb950__2->GetZaxis()->SetLabelSize(0.06);
   frame_4efb950__2->GetZaxis()->SetTitleSize(0.072);
   frame_4efb950__2->GetZaxis()->SetTitleOffset(1.2);
   frame_4efb950__2->GetZaxis()->SetTitleFont(132);
   frame_4efb950__2->Draw("AXISSAME");
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
   
   TH1D *frame_4eb1b20__3 = new TH1D("frame_4eb1b20__3","A RooPlot of \"#Lambda mass\"",100,1086,1146);
   frame_4eb1b20__3->SetBinContent(1,1469.915);
   frame_4eb1b20__3->SetMaximum(1469.915);
   frame_4eb1b20__3->SetEntries(1);
   frame_4eb1b20__3->SetDirectory(0);
   frame_4eb1b20__3->SetStats(0);
   frame_4eb1b20__3->SetLineWidth(2);
   frame_4eb1b20__3->SetMarkerStyle(20);
   frame_4eb1b20__3->GetXaxis()->SetTitle("#Lambda mass (MeV)");
   frame_4eb1b20__3->GetXaxis()->SetNdivisions(505);
   frame_4eb1b20__3->GetXaxis()->SetLabelFont(132);
   frame_4eb1b20__3->GetXaxis()->SetLabelOffset(0.01);
   frame_4eb1b20__3->GetXaxis()->SetLabelSize(0.06);
   frame_4eb1b20__3->GetXaxis()->SetTitleSize(0.072);
   frame_4eb1b20__3->GetXaxis()->SetTitleOffset(0.95);
   frame_4eb1b20__3->GetXaxis()->SetTitleFont(132);
   frame_4eb1b20__3->GetYaxis()->SetTitle("Events/(5 MeV)");
   frame_4eb1b20__3->GetYaxis()->SetLabelFont(132);
   frame_4eb1b20__3->GetYaxis()->SetLabelOffset(0.01);
   frame_4eb1b20__3->GetYaxis()->SetLabelSize(0.06);
   frame_4eb1b20__3->GetYaxis()->SetTitleSize(0.072);
   frame_4eb1b20__3->GetYaxis()->SetTitleOffset(0.95);
   frame_4eb1b20__3->GetYaxis()->SetTitleFont(132);
   frame_4eb1b20__3->GetZaxis()->SetLabelFont(132);
   frame_4eb1b20__3->GetZaxis()->SetLabelSize(0.06);
   frame_4eb1b20__3->GetZaxis()->SetTitleSize(0.072);
   frame_4eb1b20__3->GetZaxis()->SetTitleOffset(1.2);
   frame_4eb1b20__3->GetZaxis()->SetTitleFont(132);
   frame_4eb1b20__3->Draw("FUNC");
   
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
   
   Double_t curvetot_fx1[102] = {
   1090,
   1090.16,
   1090.32,
   1090.48,
   1090.64,
   1090.8,
   1090.96,
   1091.12,
   1091.28,
   1091.44,
   1091.6,
   1091.76,
   1091.92,
   1092.08,
   1092.24,
   1092.4,
   1092.56,
   1092.72,
   1092.88,
   1093.04,
   1093.2,
   1093.36,
   1093.52,
   1093.68,
   1093.84,
   1094,
   1094.16,
   1094.32,
   1094.48,
   1094.64,
   1094.8,
   1094.96,
   1095.12,
   1095.28,
   1095.44,
   1095.6,
   1095.76,
   1095.92,
   1096.08,
   1096.24,
   1096.4,
   1096.56,
   1096.72,
   1096.88,
   1097.04,
   1097.2,
   1097.36,
   1097.52,
   1097.68,
   1097.84,
   1098,
   1098.16,
   1098.32,
   1098.48,
   1098.64,
   1098.8,
   1098.96,
   1099.12,
   1099.28,
   1099.44,
   1099.6,
   1099.76,
   1099.92,
   1100.08,
   1100.24,
   1100.4,
   1100.56,
   1100.72,
   1100.88,
   1101.04,
   1101.2,
   1101.36,
   1101.52,
   1101.68,
   1101.84,
   1102,
   1102.16,
   1102.32,
   1102.48,
   1102.64,
   1102.8,
   1102.96,
   1103.12,
   1103.28,
   1103.44,
   1103.6,
   1103.76,
   1103.92,
   1104.08,
   1104.24,
   1104.4,
   1104.56,
   1104.72,
   1104.88,
   1105.04,
   1105.2,
   1105.36,
   1105.52,
   1105.68,
   1105.84,
   1106,
   1106};
   Double_t curvetot_fy1[102] = {
   24.29286,
   24.43218,
   24.57149,
   24.71081,
   24.85012,
   24.98944,
   25.12876,
   25.26807,
   25.40739,
   25.5467,
   25.68602,
   25.82533,
   25.96465,
   26.10397,
   26.24328,
   26.3826,
   26.52191,
   26.66123,
   26.80054,
   26.93986,
   27.07918,
   27.21849,
   27.35781,
   27.49712,
   27.63644,
   27.77575,
   27.91507,
   28.05439,
   28.1937,
   28.33302,
   28.47233,
   28.61165,
   28.75096,
   28.89028,
   29.0296,
   29.16891,
   29.30823,
   29.44754,
   29.58686,
   29.72618,
   29.86549,
   30.00481,
   30.14412,
   30.28344,
   30.42275,
   30.56207,
   30.70139,
   30.8407,
   30.98002,
   31.11933,
   31.25865,
   31.39796,
   31.53728,
   31.6766,
   31.81591,
   31.95523,
   32.09454,
   32.23386,
   32.37317,
   32.51249,
   32.65181,
   32.79112,
   32.93044,
   33.06975,
   33.20907,
   33.34839,
   33.4877,
   33.62702,
   33.76633,
   33.90565,
   34.04496,
   34.18428,
   34.3236,
   34.46291,
   34.60223,
   34.74154,
   34.88086,
   35.02017,
   35.15949,
   35.29881,
   35.43812,
   35.57744,
   35.71675,
   35.85607,
   35.99538,
   36.1347,
   36.27402,
   36.41333,
   36.55265,
   36.69196,
   36.83128,
   36.9706,
   37.10991,
   37.24923,
   37.38854,
   37.52786,
   37.66717,
   37.80649,
   37.94581,
   38.08512,
   38.22444,
   38.22444};
   TGraph *graph = new TGraph(102,curvetot_fx1,curvetot_fy1);
   graph->SetName("curvetot");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_curvetot1 = new TH1F("Graph_curvetot1","Projection of totalPdf",102,1088.4,1107.6);
   Graph_curvetot1->SetMinimum(22.8997);
   Graph_curvetot1->SetMaximum(39.61759);
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
   
   Double_t curvetot_fx2[102] = {
   1124,
   1124.12,
   1124.24,
   1124.36,
   1124.48,
   1124.6,
   1124.72,
   1124.84,
   1124.96,
   1125.08,
   1125.2,
   1125.32,
   1125.44,
   1125.56,
   1125.68,
   1125.8,
   1125.92,
   1126.04,
   1126.16,
   1126.28,
   1126.4,
   1126.52,
   1126.64,
   1126.76,
   1126.88,
   1127,
   1127.12,
   1127.24,
   1127.36,
   1127.48,
   1127.6,
   1127.72,
   1127.84,
   1127.96,
   1128.08,
   1128.2,
   1128.32,
   1128.44,
   1128.56,
   1128.68,
   1128.8,
   1128.92,
   1129.04,
   1129.16,
   1129.28,
   1129.4,
   1129.52,
   1129.64,
   1129.76,
   1129.88,
   1130,
   1130.12,
   1130.24,
   1130.36,
   1130.48,
   1130.6,
   1130.72,
   1130.84,
   1130.96,
   1131.08,
   1131.2,
   1131.32,
   1131.44,
   1131.56,
   1131.68,
   1131.8,
   1131.92,
   1132.04,
   1132.16,
   1132.28,
   1132.4,
   1132.52,
   1132.64,
   1132.76,
   1132.88,
   1133,
   1133.12,
   1133.24,
   1133.36,
   1133.48,
   1133.6,
   1133.72,
   1133.84,
   1133.96,
   1134.08,
   1134.2,
   1134.32,
   1134.44,
   1134.56,
   1134.68,
   1134.8,
   1134.92,
   1135.04,
   1135.16,
   1135.28,
   1135.4,
   1135.52,
   1135.64,
   1135.76,
   1135.88,
   1136,
   1136};
   Double_t curvetot_fy2[102] = {
   53.89746,
   54.00195,
   54.10643,
   54.21092,
   54.31541,
   54.41989,
   54.52438,
   54.62887,
   54.73336,
   54.83784,
   54.94233,
   55.04682,
   55.1513,
   55.25579,
   55.36028,
   55.46476,
   55.56925,
   55.67374,
   55.77822,
   55.88271,
   55.9872,
   56.09168,
   56.19617,
   56.30066,
   56.40514,
   56.50963,
   56.61412,
   56.7186,
   56.82309,
   56.92758,
   57.03207,
   57.13655,
   57.24104,
   57.34553,
   57.45001,
   57.5545,
   57.65899,
   57.76347,
   57.86796,
   57.97245,
   58.07693,
   58.18142,
   58.28591,
   58.39039,
   58.49488,
   58.59937,
   58.70385,
   58.80834,
   58.91283,
   59.01731,
   59.1218,
   59.22629,
   59.33078,
   59.43526,
   59.53975,
   59.64424,
   59.74872,
   59.85321,
   59.9577,
   60.06218,
   60.16667,
   60.27116,
   60.37564,
   60.48013,
   60.58462,
   60.6891,
   60.79359,
   60.89808,
   61.00256,
   61.10705,
   61.21154,
   61.31603,
   61.42051,
   61.525,
   61.62949,
   61.73397,
   61.83846,
   61.94295,
   62.04743,
   62.15192,
   62.25641,
   62.36089,
   62.46538,
   62.56987,
   62.67435,
   62.77884,
   62.88333,
   62.98781,
   63.0923,
   63.19679,
   63.30127,
   63.40576,
   63.51025,
   63.61474,
   63.71922,
   63.82371,
   63.9282,
   64.03268,
   64.13717,
   64.24166,
   64.34614,
   64.34614};
   graph = new TGraph(102,curvetot_fx2,curvetot_fy2);
   graph->SetName("curvetot");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_curvetot2 = new TH1F("Graph_curvetot2","Projection of totalPdf",102,1122.8,1137.2);
   Graph_curvetot2->SetMinimum(52.85259);
   Graph_curvetot2->SetMaximum(65.39101);
   Graph_curvetot2->SetDirectory(0);
   Graph_curvetot2->SetStats(0);
   Graph_curvetot2->SetLineWidth(2);
   Graph_curvetot2->SetMarkerStyle(20);
   Graph_curvetot2->GetXaxis()->SetNdivisions(505);
   Graph_curvetot2->GetXaxis()->SetLabelFont(132);
   Graph_curvetot2->GetXaxis()->SetLabelOffset(0.01);
   Graph_curvetot2->GetXaxis()->SetLabelSize(0.06);
   Graph_curvetot2->GetXaxis()->SetTitleSize(0.072);
   Graph_curvetot2->GetXaxis()->SetTitleOffset(0.95);
   Graph_curvetot2->GetXaxis()->SetTitleFont(132);
   Graph_curvetot2->GetYaxis()->SetLabelFont(132);
   Graph_curvetot2->GetYaxis()->SetLabelOffset(0.01);
   Graph_curvetot2->GetYaxis()->SetLabelSize(0.06);
   Graph_curvetot2->GetYaxis()->SetTitleSize(0.072);
   Graph_curvetot2->GetYaxis()->SetTitleOffset(0.95);
   Graph_curvetot2->GetYaxis()->SetTitleFont(132);
   Graph_curvetot2->GetZaxis()->SetLabelFont(132);
   Graph_curvetot2->GetZaxis()->SetLabelSize(0.06);
   Graph_curvetot2->GetZaxis()->SetTitleSize(0.072);
   Graph_curvetot2->GetZaxis()->SetTitleOffset(1.2);
   Graph_curvetot2->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_curvetot2);
   
   graph->Draw("l");
   
   Double_t bkg_fx3[102] = {
   1090,
   1090.16,
   1090.32,
   1090.48,
   1090.64,
   1090.8,
   1090.96,
   1091.12,
   1091.28,
   1091.44,
   1091.6,
   1091.76,
   1091.92,
   1092.08,
   1092.24,
   1092.4,
   1092.56,
   1092.72,
   1092.88,
   1093.04,
   1093.2,
   1093.36,
   1093.52,
   1093.68,
   1093.84,
   1094,
   1094.16,
   1094.32,
   1094.48,
   1094.64,
   1094.8,
   1094.96,
   1095.12,
   1095.28,
   1095.44,
   1095.6,
   1095.76,
   1095.92,
   1096.08,
   1096.24,
   1096.4,
   1096.56,
   1096.72,
   1096.88,
   1097.04,
   1097.2,
   1097.36,
   1097.52,
   1097.68,
   1097.84,
   1098,
   1098.16,
   1098.32,
   1098.48,
   1098.64,
   1098.8,
   1098.96,
   1099.12,
   1099.28,
   1099.44,
   1099.6,
   1099.76,
   1099.92,
   1100.08,
   1100.24,
   1100.4,
   1100.56,
   1100.72,
   1100.88,
   1101.04,
   1101.2,
   1101.36,
   1101.52,
   1101.68,
   1101.84,
   1102,
   1102.16,
   1102.32,
   1102.48,
   1102.64,
   1102.8,
   1102.96,
   1103.12,
   1103.28,
   1103.44,
   1103.6,
   1103.76,
   1103.92,
   1104.08,
   1104.24,
   1104.4,
   1104.56,
   1104.72,
   1104.88,
   1105.04,
   1105.2,
   1105.36,
   1105.52,
   1105.68,
   1105.84,
   1106,
   1106};
   Double_t bkg_fy3[102] = {
   24.29286,
   24.43218,
   24.57149,
   24.71081,
   24.85012,
   24.98944,
   25.12876,
   25.26807,
   25.40739,
   25.5467,
   25.68602,
   25.82533,
   25.96465,
   26.10397,
   26.24328,
   26.3826,
   26.52191,
   26.66123,
   26.80054,
   26.93986,
   27.07918,
   27.21849,
   27.35781,
   27.49712,
   27.63644,
   27.77575,
   27.91507,
   28.05439,
   28.1937,
   28.33302,
   28.47233,
   28.61165,
   28.75096,
   28.89028,
   29.0296,
   29.16891,
   29.30823,
   29.44754,
   29.58686,
   29.72618,
   29.86549,
   30.00481,
   30.14412,
   30.28344,
   30.42275,
   30.56207,
   30.70139,
   30.8407,
   30.98002,
   31.11933,
   31.25865,
   31.39796,
   31.53728,
   31.6766,
   31.81591,
   31.95523,
   32.09454,
   32.23386,
   32.37317,
   32.51249,
   32.65181,
   32.79112,
   32.93044,
   33.06975,
   33.20907,
   33.34839,
   33.4877,
   33.62702,
   33.76633,
   33.90565,
   34.04496,
   34.18428,
   34.3236,
   34.46291,
   34.60223,
   34.74154,
   34.88086,
   35.02017,
   35.15949,
   35.29881,
   35.43812,
   35.57744,
   35.71675,
   35.85607,
   35.99538,
   36.1347,
   36.27402,
   36.41333,
   36.55265,
   36.69196,
   36.83128,
   36.9706,
   37.10991,
   37.24923,
   37.38854,
   37.52786,
   37.66717,
   37.80649,
   37.94581,
   38.08512,
   38.22444,
   38.22444};
   graph = new TGraph(102,bkg_fx3,bkg_fy3);
   graph->SetName("bkg");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);
   graph->SetLineColor(2);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_bkg3 = new TH1F("Graph_bkg3","Projection of totalPdf",102,1088.4,1107.6);
   Graph_bkg3->SetMinimum(22.8997);
   Graph_bkg3->SetMaximum(39.61759);
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
   
   Double_t bkg_fx4[102] = {
   1124,
   1124.12,
   1124.24,
   1124.36,
   1124.48,
   1124.6,
   1124.72,
   1124.84,
   1124.96,
   1125.08,
   1125.2,
   1125.32,
   1125.44,
   1125.56,
   1125.68,
   1125.8,
   1125.92,
   1126.04,
   1126.16,
   1126.28,
   1126.4,
   1126.52,
   1126.64,
   1126.76,
   1126.88,
   1127,
   1127.12,
   1127.24,
   1127.36,
   1127.48,
   1127.6,
   1127.72,
   1127.84,
   1127.96,
   1128.08,
   1128.2,
   1128.32,
   1128.44,
   1128.56,
   1128.68,
   1128.8,
   1128.92,
   1129.04,
   1129.16,
   1129.28,
   1129.4,
   1129.52,
   1129.64,
   1129.76,
   1129.88,
   1130,
   1130.12,
   1130.24,
   1130.36,
   1130.48,
   1130.6,
   1130.72,
   1130.84,
   1130.96,
   1131.08,
   1131.2,
   1131.32,
   1131.44,
   1131.56,
   1131.68,
   1131.8,
   1131.92,
   1132.04,
   1132.16,
   1132.28,
   1132.4,
   1132.52,
   1132.64,
   1132.76,
   1132.88,
   1133,
   1133.12,
   1133.24,
   1133.36,
   1133.48,
   1133.6,
   1133.72,
   1133.84,
   1133.96,
   1134.08,
   1134.2,
   1134.32,
   1134.44,
   1134.56,
   1134.68,
   1134.8,
   1134.92,
   1135.04,
   1135.16,
   1135.28,
   1135.4,
   1135.52,
   1135.64,
   1135.76,
   1135.88,
   1136,
   1136};
   Double_t bkg_fy4[102] = {
   53.89746,
   54.00195,
   54.10643,
   54.21092,
   54.31541,
   54.41989,
   54.52438,
   54.62887,
   54.73336,
   54.83784,
   54.94233,
   55.04682,
   55.1513,
   55.25579,
   55.36028,
   55.46476,
   55.56925,
   55.67374,
   55.77822,
   55.88271,
   55.9872,
   56.09168,
   56.19617,
   56.30066,
   56.40514,
   56.50963,
   56.61412,
   56.7186,
   56.82309,
   56.92758,
   57.03207,
   57.13655,
   57.24104,
   57.34553,
   57.45001,
   57.5545,
   57.65899,
   57.76347,
   57.86796,
   57.97245,
   58.07693,
   58.18142,
   58.28591,
   58.39039,
   58.49488,
   58.59937,
   58.70385,
   58.80834,
   58.91283,
   59.01731,
   59.1218,
   59.22629,
   59.33078,
   59.43526,
   59.53975,
   59.64424,
   59.74872,
   59.85321,
   59.9577,
   60.06218,
   60.16667,
   60.27116,
   60.37564,
   60.48013,
   60.58462,
   60.6891,
   60.79359,
   60.89808,
   61.00256,
   61.10705,
   61.21154,
   61.31603,
   61.42051,
   61.525,
   61.62949,
   61.73397,
   61.83846,
   61.94295,
   62.04743,
   62.15192,
   62.25641,
   62.36089,
   62.46538,
   62.56987,
   62.67435,
   62.77884,
   62.88333,
   62.98781,
   63.0923,
   63.19679,
   63.30127,
   63.40576,
   63.51025,
   63.61474,
   63.71922,
   63.82371,
   63.9282,
   64.03268,
   64.13717,
   64.24166,
   64.34614,
   64.34614};
   graph = new TGraph(102,bkg_fx4,bkg_fy4);
   graph->SetName("bkg");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);
   graph->SetLineColor(2);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_bkg4 = new TH1F("Graph_bkg4","Projection of totalPdf",102,1122.8,1137.2);
   Graph_bkg4->SetMinimum(52.85259);
   Graph_bkg4->SetMaximum(65.39101);
   Graph_bkg4->SetDirectory(0);
   Graph_bkg4->SetStats(0);
   Graph_bkg4->SetLineWidth(2);
   Graph_bkg4->SetMarkerStyle(20);
   Graph_bkg4->GetXaxis()->SetNdivisions(505);
   Graph_bkg4->GetXaxis()->SetLabelFont(132);
   Graph_bkg4->GetXaxis()->SetLabelOffset(0.01);
   Graph_bkg4->GetXaxis()->SetLabelSize(0.06);
   Graph_bkg4->GetXaxis()->SetTitleSize(0.072);
   Graph_bkg4->GetXaxis()->SetTitleOffset(0.95);
   Graph_bkg4->GetXaxis()->SetTitleFont(132);
   Graph_bkg4->GetYaxis()->SetLabelFont(132);
   Graph_bkg4->GetYaxis()->SetLabelOffset(0.01);
   Graph_bkg4->GetYaxis()->SetLabelSize(0.06);
   Graph_bkg4->GetYaxis()->SetTitleSize(0.072);
   Graph_bkg4->GetYaxis()->SetTitleOffset(0.95);
   Graph_bkg4->GetYaxis()->SetTitleFont(132);
   Graph_bkg4->GetZaxis()->SetLabelFont(132);
   Graph_bkg4->GetZaxis()->SetLabelSize(0.06);
   Graph_bkg4->GetZaxis()->SetTitleSize(0.072);
   Graph_bkg4->GetZaxis()->SetTitleOffset(1.2);
   Graph_bkg4->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_bkg4);
   
   graph->Draw("l");
   
   TLegend *leg = new TLegend(0.75,0.02,1,0.42,NULL,"brNDC");
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
   leg->Draw();
   
   TH1D *frame_4eb1b20__4 = new TH1D("frame_4eb1b20__4","A RooPlot of \"#Lambda mass\"",100,1086,1146);
   frame_4eb1b20__4->SetBinContent(1,1469.915);
   frame_4eb1b20__4->SetMaximum(1469.915);
   frame_4eb1b20__4->SetEntries(1);
   frame_4eb1b20__4->SetDirectory(0);
   frame_4eb1b20__4->SetStats(0);
   frame_4eb1b20__4->SetLineWidth(2);
   frame_4eb1b20__4->SetMarkerStyle(20);
   frame_4eb1b20__4->GetXaxis()->SetTitle("#Lambda mass (MeV)");
   frame_4eb1b20__4->GetXaxis()->SetNdivisions(505);
   frame_4eb1b20__4->GetXaxis()->SetLabelFont(132);
   frame_4eb1b20__4->GetXaxis()->SetLabelOffset(0.01);
   frame_4eb1b20__4->GetXaxis()->SetLabelSize(0.06);
   frame_4eb1b20__4->GetXaxis()->SetTitleSize(0.072);
   frame_4eb1b20__4->GetXaxis()->SetTitleOffset(0.95);
   frame_4eb1b20__4->GetXaxis()->SetTitleFont(132);
   frame_4eb1b20__4->GetYaxis()->SetTitle("Events/(5 MeV)");
   frame_4eb1b20__4->GetYaxis()->SetLabelFont(132);
   frame_4eb1b20__4->GetYaxis()->SetLabelOffset(0.01);
   frame_4eb1b20__4->GetYaxis()->SetLabelSize(0.06);
   frame_4eb1b20__4->GetYaxis()->SetTitleSize(0.072);
   frame_4eb1b20__4->GetYaxis()->SetTitleOffset(0.95);
   frame_4eb1b20__4->GetYaxis()->SetTitleFont(132);
   frame_4eb1b20__4->GetZaxis()->SetLabelFont(132);
   frame_4eb1b20__4->GetZaxis()->SetLabelSize(0.06);
   frame_4eb1b20__4->GetZaxis()->SetTitleSize(0.072);
   frame_4eb1b20__4->GetZaxis()->SetTitleOffset(1.2);
   frame_4eb1b20__4->GetZaxis()->SetTitleFont(132);
   frame_4eb1b20__4->Draw("AXISSAME");
   pad1->Modified();
   c1->cd();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
