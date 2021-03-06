void fitWMLL4_singleGaus()
{
//=========Macro generated from canvas: c1/data fits
//=========  (Sat May  7 17:43:16 2016) by ROOT version6.06/02
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
   pad2->Range(230.8642,-26.4,724.6914,8.8);
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
   
   TH1D *frame_3707a40__1 = new TH1D("frame_3707a40__1","",100,300,700);
   frame_3707a40__1->SetBinContent(1,3.940905);
   frame_3707a40__1->SetMinimum(-8.8);
   frame_3707a40__1->SetMaximum(8.8);
   frame_3707a40__1->SetEntries(1);
   frame_3707a40__1->SetDirectory(0);
   frame_3707a40__1->SetStats(0);
   frame_3707a40__1->SetLineWidth(2);
   frame_3707a40__1->SetMarkerStyle(20);
   frame_3707a40__1->GetXaxis()->SetTitle("m(#pi p#rightarrow#pi) (MeV)");
   frame_3707a40__1->GetXaxis()->SetNdivisions(505);
   frame_3707a40__1->GetXaxis()->SetLabelFont(132);
   frame_3707a40__1->GetXaxis()->SetLabelOffset(0.01);
   frame_3707a40__1->GetXaxis()->SetLabelSize(0.15);
   frame_3707a40__1->GetXaxis()->SetTitleSize(0.2);
   frame_3707a40__1->GetXaxis()->SetTitleOffset(1.1);
   frame_3707a40__1->GetXaxis()->SetTitleFont(132);
   frame_3707a40__1->GetYaxis()->SetTitle("Pull");
   frame_3707a40__1->GetYaxis()->CenterTitle(true);
   frame_3707a40__1->GetYaxis()->SetNdivisions(505);
   frame_3707a40__1->GetYaxis()->SetLabelFont(132);
   frame_3707a40__1->GetYaxis()->SetLabelOffset(0.01);
   frame_3707a40__1->GetYaxis()->SetLabelSize(0.15);
   frame_3707a40__1->GetYaxis()->SetTitleSize(0.15);
   frame_3707a40__1->GetYaxis()->SetTitleOffset(0.45);
   frame_3707a40__1->GetYaxis()->SetTitleFont(132);
   frame_3707a40__1->GetZaxis()->SetLabelFont(132);
   frame_3707a40__1->GetZaxis()->SetLabelSize(0.06);
   frame_3707a40__1->GetZaxis()->SetTitleSize(0.072);
   frame_3707a40__1->GetZaxis()->SetTitleOffset(1.2);
   frame_3707a40__1->GetZaxis()->SetTitleFont(132);
   frame_3707a40__1->Draw("FUNC");
   
   Double_t pull_Hist_curvetot_fx3001[66] = {
   322,
   326,
   330,
   334,
   338,
   342,
   346,
   350,
   354,
   358,
   362,
   366,
   370,
   374,
   378,
   382,
   386,
   390,
   394,
   398,
   402,
   406,
   410,
   414,
   418,
   422,
   426,
   430,
   434,
   438,
   442,
   446,
   450,
   454,
   458,
   462,
   466,
   470,
   474,
   478,
   482,
   486,
   490,
   494,
   498,
   502,
   506,
   510,
   514,
   518,
   522,
   526,
   530,
   534,
   538,
   542,
   546,
   550,
   554,
   558,
   562,
   566,
   570,
   574,
   578,
   582};
   Double_t pull_Hist_curvetot_fy3001[66] = {
   -12.14153,
   -0.6976851,
   0.7750337,
   1.667218,
   1.868154,
   2.023742,
   1.730309,
   1.662609,
   1.321347,
   2.127455,
   0.5451555,
   -0.7865873,
   -0.132961,
   -1.397144,
   0.1938362,
   1.09138,
   0.244404,
   -2.514928,
   0.1109374,
   -2.856873,
   -0.3751176,
   0.2575039,
   -0.6700329,
   -1.112626,
   0.4144319,
   -1.166968,
   -2.094051,
   0.791322,
   -0.5970888,
   -0.1469819,
   -1.622048,
   -2.782445,
   -2.576037,
   1.45186,
   0.05315478,
   -0.627191,
   -0.2664914,
   -0.6753902,
   -0.4479562,
   -0.3845109,
   1.185919,
   1.787178,
   0.3499949,
   -2.436943,
   1.982823,
   -0.07849369,
   -1.948658,
   1.820545,
   1.795921,
   1.178958,
   0.540939,
   0.83117,
   1.036778,
   1.480659,
   -1.729956,
   2.01818,
   -0.7451863,
   -1.190792,
   -1.538213,
   -1.202453,
   -1.707599,
   -0.5670883,
   -0.6930774,
   1.913868,
   0,
   0};
   Double_t pull_Hist_curvetot_felx3001[66] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t pull_Hist_curvetot_fely3001[66] = {
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
   0,
   0};
   Double_t pull_Hist_curvetot_fehx3001[66] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t pull_Hist_curvetot_fehy3001[66] = {
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
   0,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(66,pull_Hist_curvetot_fx3001,pull_Hist_curvetot_fy3001,pull_Hist_curvetot_felx3001,pull_Hist_curvetot_fehx3001,pull_Hist_curvetot_fely3001,pull_Hist_curvetot_fehy3001);
   grae->SetName("pull_Hist_curvetot");
   grae->SetTitle("Pull of Histogram of data_plot__R_WM and Projection of totalPdf");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(8);
   
   TH1F *Graph_pull_Hist_curvetot3001 = new TH1F("Graph_pull_Hist_curvetot3001","Pull of Histogram of data_plot__R_WM and Projection of totalPdf",100,296,608);
   Graph_pull_Hist_curvetot3001->SetMinimum(-14.76843);
   Graph_pull_Hist_curvetot3001->SetMaximum(4.754354);
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
   
   TH1D *frame_3707a40__2 = new TH1D("frame_3707a40__2","",100,300,700);
   frame_3707a40__2->SetBinContent(1,3.940905);
   frame_3707a40__2->SetMinimum(-8.8);
   frame_3707a40__2->SetMaximum(8.8);
   frame_3707a40__2->SetEntries(1);
   frame_3707a40__2->SetDirectory(0);
   frame_3707a40__2->SetStats(0);
   frame_3707a40__2->SetLineWidth(2);
   frame_3707a40__2->SetMarkerStyle(20);
   frame_3707a40__2->GetXaxis()->SetTitle("m(#pi p#rightarrow#pi) (MeV)");
   frame_3707a40__2->GetXaxis()->SetNdivisions(505);
   frame_3707a40__2->GetXaxis()->SetLabelFont(132);
   frame_3707a40__2->GetXaxis()->SetLabelOffset(0.01);
   frame_3707a40__2->GetXaxis()->SetLabelSize(0.15);
   frame_3707a40__2->GetXaxis()->SetTitleSize(0.2);
   frame_3707a40__2->GetXaxis()->SetTitleOffset(1.1);
   frame_3707a40__2->GetXaxis()->SetTitleFont(132);
   frame_3707a40__2->GetYaxis()->SetTitle("Pull");
   frame_3707a40__2->GetYaxis()->CenterTitle(true);
   frame_3707a40__2->GetYaxis()->SetNdivisions(505);
   frame_3707a40__2->GetYaxis()->SetLabelFont(132);
   frame_3707a40__2->GetYaxis()->SetLabelOffset(0.01);
   frame_3707a40__2->GetYaxis()->SetLabelSize(0.15);
   frame_3707a40__2->GetYaxis()->SetTitleSize(0.15);
   frame_3707a40__2->GetYaxis()->SetTitleOffset(0.45);
   frame_3707a40__2->GetYaxis()->SetTitleFont(132);
   frame_3707a40__2->GetZaxis()->SetLabelFont(132);
   frame_3707a40__2->GetZaxis()->SetLabelSize(0.06);
   frame_3707a40__2->GetZaxis()->SetTitleSize(0.072);
   frame_3707a40__2->GetZaxis()->SetTitleOffset(1.2);
   frame_3707a40__2->GetZaxis()->SetTitleFont(132);
   frame_3707a40__2->Draw("AXISSAME");
   pad2->Modified();
   c1->cd();
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "pad1",0,0.3,1,1);
   pad1->Draw();
   pad1->cd();
   pad1->Range(230.8642,0,724.6914,299.2215);
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
   
   TH1D *frame_35810d0__3 = new TH1D("frame_35810d0__3","A RooPlot of \"m(#pi p#rightarrow#pi)\"",100,300,700);
   frame_35810d0__3->SetBinContent(1,281.2682);
   frame_35810d0__3->SetMaximum(281.2682);
   frame_35810d0__3->SetEntries(1);
   frame_35810d0__3->SetDirectory(0);
   frame_35810d0__3->SetStats(0);
   frame_35810d0__3->SetLineWidth(2);
   frame_35810d0__3->SetMarkerStyle(20);
   frame_35810d0__3->GetXaxis()->SetTitle("m(#pi p#rightarrow#pi) (MeV)");
   frame_35810d0__3->GetXaxis()->SetNdivisions(505);
   frame_35810d0__3->GetXaxis()->SetLabelFont(132);
   frame_35810d0__3->GetXaxis()->SetLabelOffset(0.01);
   frame_35810d0__3->GetXaxis()->SetLabelSize(0.06);
   frame_35810d0__3->GetXaxis()->SetTitleSize(0.072);
   frame_35810d0__3->GetXaxis()->SetTitleOffset(0.95);
   frame_35810d0__3->GetXaxis()->SetTitleFont(132);
   frame_35810d0__3->GetYaxis()->SetTitle("Events/(5 MeV)");
   frame_35810d0__3->GetYaxis()->SetLabelFont(132);
   frame_35810d0__3->GetYaxis()->SetLabelOffset(0.01);
   frame_35810d0__3->GetYaxis()->SetLabelSize(0.06);
   frame_35810d0__3->GetYaxis()->SetTitleSize(0.072);
   frame_35810d0__3->GetYaxis()->SetTitleOffset(0.95);
   frame_35810d0__3->GetYaxis()->SetTitleFont(132);
   frame_35810d0__3->GetZaxis()->SetLabelFont(132);
   frame_35810d0__3->GetZaxis()->SetLabelSize(0.06);
   frame_35810d0__3->GetZaxis()->SetTitleSize(0.072);
   frame_35810d0__3->GetZaxis()->SetTitleOffset(1.2);
   frame_35810d0__3->GetZaxis()->SetTitleFont(132);
   frame_35810d0__3->Draw("FUNC");
   
   Double_t Hist_fx3002[100] = {
   302,
   306,
   310,
   314,
   318,
   322,
   326,
   330,
   334,
   338,
   342,
   346,
   350,
   354,
   358,
   362,
   366,
   370,
   374,
   378,
   382,
   386,
   390,
   394,
   398,
   402,
   406,
   410,
   414,
   418,
   422,
   426,
   430,
   434,
   438,
   442,
   446,
   450,
   454,
   458,
   462,
   466,
   470,
   474,
   478,
   482,
   486,
   490,
   494,
   498,
   502,
   506,
   510,
   514,
   518,
   522,
   526,
   530,
   534,
   538,
   542,
   546,
   550,
   554,
   558,
   562,
   566,
   570,
   574,
   578,
   582,
   586,
   590,
   594,
   598,
   602,
   606,
   610,
   614,
   618,
   622,
   626,
   630,
   634,
   638,
   642,
   646,
   650,
   654,
   658,
   662,
   666,
   670,
   674,
   678,
   682,
   686,
   690,
   694,
   698};
   Double_t Hist_fy3002[100] = {
   0,
   0,
   0,
   0,
   0,
   10,
   54,
   76,
   95,
   107,
   118,
   123,
   130,
   133,
   150,
   136,
   126,
   138,
   128,
   150,
   165,
   157,
   128,
   160,
   128,
   157,
   166,
   155,
   150,
   169,
   149,
   138,
   172,
   153,
   157,
   138,
   124,
   124,
   169,
   148,
   137,
   138,
   130,
   129,
   126,
   141,
   150,
   153,
   164,
   252,
   181,
   107,
   119,
   108,
   95,
   83,
   80,
   76,
   74,
   44,
   66,
   39,
   31,
   24,
   20,
   13,
   11,
   5,
   4,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Hist_felx3002[100] = {
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2};
   Double_t Hist_fely3002[100] = {
   0,
   0,
   0,
   0,
   0,
   3.162278,
   7.348469,
   8.717798,
   9.746794,
   10.34408,
   10.86278,
   11.09054,
   11.40175,
   11.53256,
   12.24745,
   11.6619,
   11.22497,
   11.74734,
   11.31371,
   12.24745,
   12.84523,
   12.52996,
   11.31371,
   12.64911,
   11.31371,
   12.52996,
   12.8841,
   12.4499,
   12.24745,
   13,
   12.20656,
   11.74734,
   13.11488,
   12.36932,
   12.52996,
   11.74734,
   11.13553,
   11.13553,
   13,
   12.16553,
   11.7047,
   11.74734,
   11.40175,
   11.35782,
   11.22497,
   11.87434,
   12.24745,
   12.36932,
   12.80625,
   15.87451,
   13.45362,
   10.34408,
   10.90871,
   10.3923,
   9.746794,
   9.110434,
   8.944272,
   8.717798,
   8.602325,
   6.63325,
   8.124038,
   6.244998,
   5.567764,
   4.898979,
   4.472136,
   3.605551,
   3.316625,
   2.236068,
   2,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Hist_fehx3002[100] = {
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2};
   Double_t Hist_fehy3002[100] = {
   0,
   0,
   0,
   0,
   0,
   3.162278,
   7.348469,
   8.717798,
   9.746794,
   10.34408,
   10.86278,
   11.09054,
   11.40175,
   11.53256,
   12.24745,
   11.6619,
   11.22497,
   11.74734,
   11.31371,
   12.24745,
   12.84523,
   12.52996,
   11.31371,
   12.64911,
   11.31371,
   12.52996,
   12.8841,
   12.4499,
   12.24745,
   13,
   12.20656,
   11.74734,
   13.11488,
   12.36932,
   12.52996,
   11.74734,
   11.13553,
   11.13553,
   13,
   12.16553,
   11.7047,
   11.74734,
   11.40175,
   11.35782,
   11.22497,
   11.87434,
   12.24745,
   12.36932,
   12.80625,
   15.87451,
   13.45362,
   10.34408,
   10.90871,
   10.3923,
   9.746794,
   9.110434,
   8.944272,
   8.717798,
   8.602325,
   6.63325,
   8.124038,
   6.244998,
   5.567764,
   4.898979,
   4.472136,
   3.605551,
   3.316625,
   2.236068,
   2,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   grae = new TGraphAsymmErrors(100,Hist_fx3002,Hist_fy3002,Hist_felx3002,Hist_fehx3002,Hist_fely3002,Hist_fehy3002);
   grae->SetName("Hist");
   grae->SetTitle("Histogram of data_plot__R_WM");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(8);
   
   TH1F *Graph_Hist3002 = new TH1F("Graph_Hist3002","Histogram of data_plot__R_WM",100,260,740);
   Graph_Hist3002->SetMinimum(0);
   Graph_Hist3002->SetMaximum(294.662);
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
   
   Double_t curvetot_fx1[138] = {
   320,
   322.65,
   325.3,
   327.95,
   330.6,
   333.25,
   335.9,
   338.55,
   341.2,
   343.85,
   346.5,
   349.15,
   351.8,
   354.45,
   357.1,
   359.75,
   362.4,
   365.05,
   367.7,
   370.35,
   373,
   375.65,
   378.3,
   380.95,
   383.6,
   386.25,
   388.9,
   391.55,
   394.2,
   396.85,
   399.5,
   402.15,
   404.8,
   407.45,
   410.1,
   412.75,
   415.4,
   418.05,
   420.7,
   423.35,
   426,
   428.65,
   431.3,
   433.95,
   436.6,
   439.25,
   441.9,
   444.55,
   447.2,
   449.85,
   452.5,
   455.15,
   457.8,
   460.45,
   463.1,
   465.75,
   468.4,
   471.05,
   473.7,
   476.35,
   479,
   481.65,
   482.975,
   484.3,
   485.625,
   486.2875,
   486.95,
   487.6125,
   488.275,
   488.9375,
   489.6,
   490.2625,
   490.925,
   491.5875,
   492.25,
   493.575,
   494.2375,
   494.9,
   495.5625,
   496.225,
   496.5562,
   496.8875,
   497.2187,
   497.55,
   497.8812,
   498.2125,
   498.5437,
   498.875,
   499.2063,
   499.5375,
   500.2,
   500.8625,
   501.525,
   502.85,
   504.175,
   504.8375,
   505.5,
   506.1625,
   506.825,
   507.4875,
   508.15,
   508.8125,
   509.475,
   510.1375,
   510.8,
   512.125,
   513.45,
   516.1,
   518.75,
   521.4,
   524.05,
   526.7,
   529.35,
   532,
   534.65,
   537.3,
   539.95,
   542.6,
   545.25,
   547.9,
   550.55,
   553.2,
   555.85,
   558.5,
   561.15,
   563.8,
   566.45,
   569.1,
   571.75,
   573.075,
   573.7375,
   574.0687,
   574.4,
   577.05,
   579.7,
   582.35,
   585,
   585};
   Double_t curvetot_fy1[138] = {
   42.81757,
   50.20754,
   57.32019,
   64.15996,
   70.73125,
   77.03844,
   83.08585,
   88.87776,
   94.41844,
   99.71211,
   104.7629,
   109.5751,
   114.1526,
   118.4997,
   122.6202,
   126.5183,
   130.1979,
   133.6628,
   136.917,
   139.9644,
   142.8087,
   145.4538,
   147.9033,
   150.161,
   152.2305,
   154.1155,
   155.8195,
   157.3461,
   158.6988,
   159.8812,
   160.8966,
   161.7484,
   162.4401,
   162.9749,
   163.3562,
   163.5872,
   163.6712,
   163.6113,
   163.4106,
   163.0723,
   162.5995,
   161.9952,
   161.2624,
   160.4041,
   159.4232,
   158.3225,
   157.105,
   155.7735,
   154.3306,
   152.7793,
   151.1222,
   149.3619,
   147.5012,
   145.5425,
   143.4885,
   141.3416,
   139.1044,
   136.7794,
   134.3694,
   131.8822,
   129.367,
   127.1095,
   126.3845,
   126.3182,
   127.4269,
   128.6366,
   130.4164,
   132.8691,
   136.0908,
   140.16,
   145.1262,
   150.9969,
   157.726,
   165.2044,
   173.2548,
   190.0316,
   198.1009,
   205.4634,
   211.7429,
   216.5923,
   218.3873,
   219.722,
   220.5732,
   220.9242,
   220.7649,
   220.092,
   218.9095,
   217.2282,
   215.0657,
   212.4456,
   205.9565,
   198.0542,
   189.0882,
   169.4722,
   149.9659,
   140.9672,
   132.7257,
   125.3473,
   118.8749,
   113.2987,
   108.5676,
   104.6017,
   101.3046,
   98.57332,
   96.30652,
   92.80217,
   90.18161,
   86.10849,
   82.4828,
   78.89285,
   75.26658,
   71.59627,
   67.88269,
   64.12739,
   60.33192,
   56.49782,
   52.62657,
   48.71964,
   44.77843,
   40.80433,
   36.79869,
   32.7628,
   28.69794,
   24.60535,
   20.48621,
   16.34169,
   12.17291,
   7.980963,
   3.766889,
   1.651873,
   0.5924243,
   0.06222159,
   8.216028e-52,
   1.484169e-55,
   1.999427e-59,
   2.008762e-63,
   1.505053e-67,
   1.505053e-67};
   TGraph *graph = new TGraph(138,curvetot_fx1,curvetot_fy1);
   graph->SetName("curvetot");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_curvetot1 = new TH1F("Graph_curvetot1","Projection of totalPdf",138,293.5,611.5);
   Graph_curvetot1->SetMinimum(0);
   Graph_curvetot1->SetMaximum(243.0167);
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
   
   Double_t sigWM_fx2[149] = {
   320,
   322.65,
   325.3,
   327.95,
   330.6,
   333.25,
   335.9,
   338.55,
   341.2,
   343.85,
   346.5,
   349.15,
   351.8,
   354.45,
   357.1,
   359.75,
   362.4,
   365.05,
   367.7,
   370.35,
   373,
   375.65,
   378.3,
   380.95,
   383.6,
   386.25,
   388.9,
   391.55,
   394.2,
   396.85,
   399.5,
   402.15,
   404.8,
   407.45,
   410.1,
   412.75,
   415.4,
   418.05,
   420.7,
   423.35,
   426,
   428.65,
   431.3,
   433.95,
   436.6,
   439.25,
   441.9,
   444.55,
   447.2,
   449.85,
   452.5,
   455.15,
   457.8,
   460.45,
   463.1,
   465.75,
   468.4,
   471.05,
   473.7,
   476.35,
   479,
   481.65,
   482.975,
   483.6375,
   484.3,
   484.9625,
   485.625,
   486.2875,
   486.95,
   487.6125,
   488.275,
   488.9375,
   489.2688,
   489.6,
   489.9313,
   490.2625,
   490.925,
   491.5875,
   492.25,
   493.575,
   494.2375,
   494.9,
   495.2312,
   495.5625,
   495.8937,
   496.225,
   496.5562,
   496.8875,
   497.2187,
   497.55,
   497.8812,
   498.2125,
   498.5437,
   498.875,
   499.2063,
   499.5375,
   499.8687,
   500.2,
   500.5312,
   500.8625,
   501.525,
   502.1875,
   502.85,
   503.5125,
   504.175,
   504.8375,
   505.5,
   505.8313,
   506.1625,
   506.4937,
   506.825,
   507.4875,
   508.15,
   508.8125,
   509.475,
   510.1375,
   510.8,
   511.4625,
   512.125,
   513.45,
   514.775,
   516.1,
   518.75,
   521.4,
   524.05,
   526.7,
   529.35,
   532,
   534.65,
   537.3,
   539.95,
   542.6,
   545.25,
   547.9,
   550.55,
   553.2,
   555.85,
   558.5,
   561.15,
   563.8,
   566.45,
   569.1,
   571.75,
   574.4,
   577.05,
   579.7,
   582.35,
   585,
   585};
   Double_t sigWM_fy2[149] = {
   1.225784e-285,
   3.763337e-277,
   8.616544e-269,
   1.471274e-260,
   1.873505e-252,
   1.779167e-244,
   1.260025e-236,
   6.654915e-229,
   2.621237e-221,
   7.699647e-214,
   1.686693e-206,
   2.755508e-199,
   3.35713e-192,
   3.050248e-185,
   2.066821e-178,
   1.044411e-171,
   3.935866e-165,
   1.10614e-158,
   2.318357e-152,
   3.623691e-146,
   4.223989e-140,
   3.671935e-134,
   2.380499e-128,
   1.15091e-122,
   4.14969e-117,
   1.115811e-111,
   2.237515e-106,
   3.346125e-101,
   3.731805e-96,
   3.103819e-91,
   1.925194e-86,
   8.905396e-82,
   3.072081e-77,
   7.903376e-73,
   1.516329e-68,
   2.169575e-64,
   2.31503e-60,
   1.842211e-56,
   1.093258e-52,
   4.838452e-49,
   1.596949e-45,
   3.930758e-42,
   7.215429e-39,
   9.877537e-36,
   1.008407e-32,
   7.677567e-30,
   4.359253e-27,
   1.84587e-24,
   5.828959e-22,
   1.372718e-19,
   2.410862e-17,
   3.157651e-15,
   3.084299e-13,
   2.246723e-11,
   1.220515e-09,
   4.944672e-08,
   1.493937e-06,
   3.366108e-05,
   0.0005656193,
   0.007087958,
   0.06623975,
   0.4616543,
   1.091795,
   1.633464,
   2.399472,
   3.460663,
   4.9005,
   6.813323,
   9.30069,
   12.46548,
   16.40364,
   21.19381,
   23.9253,
   26.88533,
   30.0734,
   33.48569,
   40.94875,
   49.1654,
   57.95836,
   76.23277,
   85.05716,
   93.17889,
   96.85787,
   100.2217,
   103.2281,
   105.8385,
   108.0186,
   109.7394,
   110.9779,
   111.7171,
   111.9469,
   111.6642,
   110.8729,
   109.5837,
   107.8142,
   105.5882,
   102.9353,
   99.89007,
   96.49169,
   92.78267,
   84.61531,
   75.76499,
   66.60789,
   57.49372,
   48.72509,
   40.54361,
   33.123,
   29.7336,
   26.56896,
   23.63258,
   20.92459,
   16.17994,
   12.28385,
   9.156498,
   6.701345,
   4.815397,
   3.397346,
   2.353341,
   1.600544,
   0.7007219,
   0.2850847,
   0.1077835,
   0.01236402,
   0.001057712,
   6.748015e-05,
   3.210593e-06,
   1.139187e-07,
   3.014433e-09,
   5.948628e-11,
   8.754444e-13,
   9.608178e-15,
   7.864193e-17,
   4.800295e-19,
   2.185155e-21,
   7.418179e-24,
   1.878075e-26,
   3.545924e-29,
   4.992825e-32,
   5.242809e-35,
   4.105653e-38,
   2.397735e-41,
   1.044289e-44,
   3.391884e-48,
   8.216028e-52,
   1.484169e-55,
   1.999427e-59,
   2.008762e-63,
   1.505053e-67,
   1.505053e-67};
   graph = new TGraph(149,sigWM_fx2,sigWM_fy2);
   graph->SetName("sigWM");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);
   graph->SetLineColor(2);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_sigWM2 = new TH1F("Graph_sigWM2","Projection of totalPdf",149,293.5,611.5);
   Graph_sigWM2->SetMinimum(0);
   Graph_sigWM2->SetMaximum(123.1416);
   Graph_sigWM2->SetDirectory(0);
   Graph_sigWM2->SetStats(0);
   Graph_sigWM2->SetLineWidth(2);
   Graph_sigWM2->SetMarkerStyle(20);
   Graph_sigWM2->GetXaxis()->SetNdivisions(505);
   Graph_sigWM2->GetXaxis()->SetLabelFont(132);
   Graph_sigWM2->GetXaxis()->SetLabelOffset(0.01);
   Graph_sigWM2->GetXaxis()->SetLabelSize(0.06);
   Graph_sigWM2->GetXaxis()->SetTitleSize(0.072);
   Graph_sigWM2->GetXaxis()->SetTitleOffset(0.95);
   Graph_sigWM2->GetXaxis()->SetTitleFont(132);
   Graph_sigWM2->GetYaxis()->SetLabelFont(132);
   Graph_sigWM2->GetYaxis()->SetLabelOffset(0.01);
   Graph_sigWM2->GetYaxis()->SetLabelSize(0.06);
   Graph_sigWM2->GetYaxis()->SetTitleSize(0.072);
   Graph_sigWM2->GetYaxis()->SetTitleOffset(0.95);
   Graph_sigWM2->GetYaxis()->SetTitleFont(132);
   Graph_sigWM2->GetZaxis()->SetLabelFont(132);
   Graph_sigWM2->GetZaxis()->SetLabelSize(0.06);
   Graph_sigWM2->GetZaxis()->SetTitleSize(0.072);
   Graph_sigWM2->GetZaxis()->SetTitleOffset(1.2);
   Graph_sigWM2->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_sigWM2);
   
   graph->Draw("l");
   
   Double_t bkg_fx3[105] = {
   320,
   322.65,
   325.3,
   327.95,
   330.6,
   333.25,
   335.9,
   338.55,
   341.2,
   343.85,
   346.5,
   349.15,
   351.8,
   354.45,
   357.1,
   359.75,
   362.4,
   365.05,
   367.7,
   370.35,
   373,
   375.65,
   378.3,
   380.95,
   383.6,
   386.25,
   388.9,
   391.55,
   394.2,
   396.85,
   399.5,
   402.15,
   404.8,
   407.45,
   410.1,
   412.75,
   415.4,
   418.05,
   420.7,
   423.35,
   426,
   428.65,
   431.3,
   433.95,
   436.6,
   439.25,
   441.9,
   444.55,
   447.2,
   449.85,
   452.5,
   455.15,
   457.8,
   460.45,
   463.1,
   465.75,
   468.4,
   471.05,
   473.7,
   476.35,
   479,
   481.65,
   484.3,
   486.95,
   489.6,
   492.25,
   494.9,
   497.55,
   500.2,
   502.85,
   505.5,
   508.15,
   510.8,
   513.45,
   516.1,
   518.75,
   521.4,
   524.05,
   526.7,
   529.35,
   532,
   534.65,
   537.3,
   539.95,
   542.6,
   545.25,
   547.9,
   550.55,
   553.2,
   555.85,
   558.5,
   561.15,
   563.8,
   566.45,
   569.1,
   571.75,
   573.075,
   573.7375,
   574.0687,
   574.4,
   577.05,
   579.7,
   582.35,
   585,
   585};
   Double_t bkg_fy3[105] = {
   42.81757,
   50.20754,
   57.32019,
   64.15996,
   70.73125,
   77.03844,
   83.08585,
   88.87776,
   94.41844,
   99.71211,
   104.7629,
   109.5751,
   114.1526,
   118.4997,
   122.6202,
   126.5183,
   130.1979,
   133.6628,
   136.917,
   139.9644,
   142.8087,
   145.4538,
   147.9033,
   150.161,
   152.2305,
   154.1155,
   155.8195,
   157.3461,
   158.6988,
   159.8812,
   160.8966,
   161.7484,
   162.4401,
   162.9749,
   163.3562,
   163.5872,
   163.6712,
   163.6113,
   163.4106,
   163.0723,
   162.5995,
   161.9952,
   161.2624,
   160.4041,
   159.4232,
   158.3225,
   157.105,
   155.7735,
   154.3306,
   152.7793,
   151.1222,
   149.3619,
   147.5012,
   145.5425,
   143.4885,
   141.3416,
   139.1044,
   136.7794,
   134.3688,
   131.8751,
   129.3007,
   126.6478,
   123.9188,
   121.1157,
   118.2409,
   115.2965,
   112.2845,
   109.2071,
   106.0664,
   102.8643,
   99.60274,
   96.28374,
   92.90917,
   89.48089,
   86.00071,
   82.47043,
   78.8918,
   75.26652,
   71.59627,
   67.88269,
   64.12739,
   60.33192,
   56.49782,
   52.62657,
   48.71964,
   44.77843,
   40.80433,
   36.79869,
   32.7628,
   28.69794,
   24.60535,
   20.48621,
   16.34169,
   12.17291,
   7.980963,
   3.766889,
   1.651873,
   0.5924243,
   0.06222159,
   0,
   0,
   0,
   0,
   0,
   0};
   graph = new TGraph(105,bkg_fx3,bkg_fy3);
   graph->SetName("bkg");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);
   graph->SetLineColor(3);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_bkg3 = new TH1F("Graph_bkg3","Projection of totalPdf",105,293.5,611.5);
   Graph_bkg3->SetMinimum(0);
   Graph_bkg3->SetMaximum(180.0383);
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
   entry=leg->AddEntry("sigWM","K_{S} (Gaussian)","l");
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
   
   TH1D *frame_35810d0__4 = new TH1D("frame_35810d0__4","A RooPlot of \"m(#pi p#rightarrow#pi)\"",100,300,700);
   frame_35810d0__4->SetBinContent(1,281.2682);
   frame_35810d0__4->SetMaximum(281.2682);
   frame_35810d0__4->SetEntries(1);
   frame_35810d0__4->SetDirectory(0);
   frame_35810d0__4->SetStats(0);
   frame_35810d0__4->SetLineWidth(2);
   frame_35810d0__4->SetMarkerStyle(20);
   frame_35810d0__4->GetXaxis()->SetTitle("m(#pi p#rightarrow#pi) (MeV)");
   frame_35810d0__4->GetXaxis()->SetNdivisions(505);
   frame_35810d0__4->GetXaxis()->SetLabelFont(132);
   frame_35810d0__4->GetXaxis()->SetLabelOffset(0.01);
   frame_35810d0__4->GetXaxis()->SetLabelSize(0.06);
   frame_35810d0__4->GetXaxis()->SetTitleSize(0.072);
   frame_35810d0__4->GetXaxis()->SetTitleOffset(0.95);
   frame_35810d0__4->GetXaxis()->SetTitleFont(132);
   frame_35810d0__4->GetYaxis()->SetTitle("Events/(5 MeV)");
   frame_35810d0__4->GetYaxis()->SetLabelFont(132);
   frame_35810d0__4->GetYaxis()->SetLabelOffset(0.01);
   frame_35810d0__4->GetYaxis()->SetLabelSize(0.06);
   frame_35810d0__4->GetYaxis()->SetTitleSize(0.072);
   frame_35810d0__4->GetYaxis()->SetTitleOffset(0.95);
   frame_35810d0__4->GetYaxis()->SetTitleFont(132);
   frame_35810d0__4->GetZaxis()->SetLabelFont(132);
   frame_35810d0__4->GetZaxis()->SetLabelSize(0.06);
   frame_35810d0__4->GetZaxis()->SetTitleSize(0.072);
   frame_35810d0__4->GetZaxis()->SetTitleOffset(1.2);
   frame_35810d0__4->GetZaxis()->SetTitleFont(132);
   frame_35810d0__4->Draw("AXISSAME");
   pad1->Modified();
   c1->cd();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
