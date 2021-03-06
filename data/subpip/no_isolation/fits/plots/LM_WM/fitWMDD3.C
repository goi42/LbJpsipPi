void fitWMDD3()
{
//=========Macro generated from canvas: c1/data fits
//=========  (Sun May  8 19:13:28 2016) by ROOT version6.06/02
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
   
   TH1D *frame_4a0ca30__1 = new TH1D("frame_4a0ca30__1","",100,300,700);
   frame_4a0ca30__1->SetBinContent(1,4.521388);
   frame_4a0ca30__1->SetMinimum(-8.8);
   frame_4a0ca30__1->SetMaximum(8.8);
   frame_4a0ca30__1->SetEntries(1);
   frame_4a0ca30__1->SetDirectory(0);
   frame_4a0ca30__1->SetStats(0);
   frame_4a0ca30__1->SetLineWidth(2);
   frame_4a0ca30__1->SetMarkerStyle(20);
   frame_4a0ca30__1->GetXaxis()->SetTitle("m(#pi p#rightarrow#pi) (MeV)");
   frame_4a0ca30__1->GetXaxis()->SetNdivisions(505);
   frame_4a0ca30__1->GetXaxis()->SetLabelFont(132);
   frame_4a0ca30__1->GetXaxis()->SetLabelOffset(0.01);
   frame_4a0ca30__1->GetXaxis()->SetLabelSize(0.15);
   frame_4a0ca30__1->GetXaxis()->SetTitleSize(0.2);
   frame_4a0ca30__1->GetXaxis()->SetTitleOffset(1.1);
   frame_4a0ca30__1->GetXaxis()->SetTitleFont(132);
   frame_4a0ca30__1->GetYaxis()->SetTitle("Pull");
   frame_4a0ca30__1->GetYaxis()->CenterTitle(true);
   frame_4a0ca30__1->GetYaxis()->SetNdivisions(505);
   frame_4a0ca30__1->GetYaxis()->SetLabelFont(132);
   frame_4a0ca30__1->GetYaxis()->SetLabelOffset(0.01);
   frame_4a0ca30__1->GetYaxis()->SetLabelSize(0.15);
   frame_4a0ca30__1->GetYaxis()->SetTitleSize(0.15);
   frame_4a0ca30__1->GetYaxis()->SetTitleOffset(0.45);
   frame_4a0ca30__1->GetYaxis()->SetTitleFont(132);
   frame_4a0ca30__1->GetZaxis()->SetLabelFont(132);
   frame_4a0ca30__1->GetZaxis()->SetLabelSize(0.06);
   frame_4a0ca30__1->GetZaxis()->SetTitleSize(0.072);
   frame_4a0ca30__1->GetZaxis()->SetTitleOffset(1.2);
   frame_4a0ca30__1->GetZaxis()->SetTitleFont(132);
   frame_4a0ca30__1->Draw("FUNC");
   
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
   -5.803829,
   0.9986305,
   1.539434,
   -0.8591994,
   -0.4601457,
   -0.6126432,
   0.3453163,
   -0.3198175,
   2.449104,
   1.379077,
   1.185853,
   -0.5625215,
   2.06896,
   1.647759,
   1.046377,
   -1.932727,
   -0.1140887,
   0.8215013,
   0.2400942,
   0.08940955,
   -1.143694,
   1.922468,
   -0.7923193,
   0.8829932,
   0.3819953,
   0.140549,
   -1.38159,
   -1.057986,
   -0.8905997,
   0.1458744,
   -1.138516,
   -1.77117,
   -1.388491,
   -0.8758409,
   -2.266354,
   -3.594958,
   -2.562593,
   -1.584811,
   -0.1407651,
   -1.081816,
   1.561437,
   0.3913628,
   -0.9784603,
   0.5382513,
   0.3403384,
   -0.434315,
   -0.678975,
   -0.03454914,
   0.2022769,
   0.2136387,
   0.1032672,
   1.087701,
   0.1642521,
   -1.635217,
   1.129146,
   2.595865,
   1.586566,
   1.627333,
   2.358718,
   2.417761,
   2.463478,
   2.982092,
   -0.2826207,
   -1.250696,
   -3.756791,
   -4.197678};
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
   1,
   1};
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
   1,
   1};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(66,pull_Hist_curvetot_fx3001,pull_Hist_curvetot_fy3001,pull_Hist_curvetot_felx3001,pull_Hist_curvetot_fehx3001,pull_Hist_curvetot_fely3001,pull_Hist_curvetot_fehy3001);
   grae->SetName("pull_Hist_curvetot");
   grae->SetTitle("Pull of Histogram of data_plot__R_WM and Projection of totalPdf");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(8);
   
   TH1F *Graph_pull_Hist_curvetot3001 = new TH1F("Graph_pull_Hist_curvetot3001","Pull of Histogram of data_plot__R_WM and Projection of totalPdf",100,296,608);
   Graph_pull_Hist_curvetot3001->SetMinimum(-7.882421);
   Graph_pull_Hist_curvetot3001->SetMaximum(5.060684);
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
   
   TH1D *frame_4a0ca30__2 = new TH1D("frame_4a0ca30__2","",100,300,700);
   frame_4a0ca30__2->SetBinContent(1,4.521388);
   frame_4a0ca30__2->SetMinimum(-8.8);
   frame_4a0ca30__2->SetMaximum(8.8);
   frame_4a0ca30__2->SetEntries(1);
   frame_4a0ca30__2->SetDirectory(0);
   frame_4a0ca30__2->SetStats(0);
   frame_4a0ca30__2->SetLineWidth(2);
   frame_4a0ca30__2->SetMarkerStyle(20);
   frame_4a0ca30__2->GetXaxis()->SetTitle("m(#pi p#rightarrow#pi) (MeV)");
   frame_4a0ca30__2->GetXaxis()->SetNdivisions(505);
   frame_4a0ca30__2->GetXaxis()->SetLabelFont(132);
   frame_4a0ca30__2->GetXaxis()->SetLabelOffset(0.01);
   frame_4a0ca30__2->GetXaxis()->SetLabelSize(0.15);
   frame_4a0ca30__2->GetXaxis()->SetTitleSize(0.2);
   frame_4a0ca30__2->GetXaxis()->SetTitleOffset(1.1);
   frame_4a0ca30__2->GetXaxis()->SetTitleFont(132);
   frame_4a0ca30__2->GetYaxis()->SetTitle("Pull");
   frame_4a0ca30__2->GetYaxis()->CenterTitle(true);
   frame_4a0ca30__2->GetYaxis()->SetNdivisions(505);
   frame_4a0ca30__2->GetYaxis()->SetLabelFont(132);
   frame_4a0ca30__2->GetYaxis()->SetLabelOffset(0.01);
   frame_4a0ca30__2->GetYaxis()->SetLabelSize(0.15);
   frame_4a0ca30__2->GetYaxis()->SetTitleSize(0.15);
   frame_4a0ca30__2->GetYaxis()->SetTitleOffset(0.45);
   frame_4a0ca30__2->GetYaxis()->SetTitleFont(132);
   frame_4a0ca30__2->GetZaxis()->SetLabelFont(132);
   frame_4a0ca30__2->GetZaxis()->SetLabelSize(0.06);
   frame_4a0ca30__2->GetZaxis()->SetTitleSize(0.072);
   frame_4a0ca30__2->GetZaxis()->SetTitleOffset(1.2);
   frame_4a0ca30__2->GetZaxis()->SetTitleFont(132);
   frame_4a0ca30__2->Draw("AXISSAME");
   pad2->Modified();
   c1->cd();
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "pad1",0,0.3,1,1);
   pad1->Draw();
   pad1->cd();
   pad1->Range(230.8642,0,724.6914,971.8085);
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
   
   TH1D *frame_49add50__3 = new TH1D("frame_49add50__3","A RooPlot of \"m(#pi p#rightarrow#pi)\"",100,300,700);
   frame_49add50__3->SetBinContent(1,913.5);
   frame_49add50__3->SetMaximum(913.5);
   frame_49add50__3->SetEntries(1);
   frame_49add50__3->SetDirectory(0);
   frame_49add50__3->SetStats(0);
   frame_49add50__3->SetLineWidth(2);
   frame_49add50__3->SetMarkerStyle(20);
   frame_49add50__3->GetXaxis()->SetTitle("m(#pi p#rightarrow#pi) (MeV)");
   frame_49add50__3->GetXaxis()->SetNdivisions(505);
   frame_49add50__3->GetXaxis()->SetLabelFont(132);
   frame_49add50__3->GetXaxis()->SetLabelOffset(0.01);
   frame_49add50__3->GetXaxis()->SetLabelSize(0.06);
   frame_49add50__3->GetXaxis()->SetTitleSize(0.072);
   frame_49add50__3->GetXaxis()->SetTitleOffset(0.95);
   frame_49add50__3->GetXaxis()->SetTitleFont(132);
   frame_49add50__3->GetYaxis()->SetTitle("Events/(5 MeV)");
   frame_49add50__3->GetYaxis()->SetLabelFont(132);
   frame_49add50__3->GetYaxis()->SetLabelOffset(0.01);
   frame_49add50__3->GetYaxis()->SetLabelSize(0.06);
   frame_49add50__3->GetYaxis()->SetTitleSize(0.072);
   frame_49add50__3->GetYaxis()->SetTitleOffset(0.95);
   frame_49add50__3->GetYaxis()->SetTitleFont(132);
   frame_49add50__3->GetZaxis()->SetLabelFont(132);
   frame_49add50__3->GetZaxis()->SetLabelSize(0.06);
   frame_49add50__3->GetZaxis()->SetTitleSize(0.072);
   frame_49add50__3->GetZaxis()->SetTitleOffset(1.2);
   frame_49add50__3->GetZaxis()->SetTitleFont(132);
   frame_49add50__3->Draw("FUNC");
   
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
   39,
   96,
   113,
   98,
   111,
   118,
   137,
   137,
   181,
   173,
   177,
   160,
   202,
   201,
   197,
   162,
   189,
   206,
   201,
   202,
   188,
   236,
   198,
   225,
   220,
   219,
   200,
   207,
   212,
   230,
   214,
   208,
   216,
   226,
   209,
   194,
   209,
   224,
   248,
   242,
   319,
   388,
   524,
   752,
   841,
   738,
   538,
   367,
   260,
   211,
   188,
   188,
   163,
   130,
   150,
   156,
   129,
   116,
   111,
   98,
   85,
   77,
   38,
   23,
   8,
   3,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   6.244998,
   9.797959,
   10.63015,
   9.899495,
   10.53565,
   10.86278,
   11.7047,
   11.7047,
   13.45362,
   13.15295,
   13.30413,
   12.64911,
   14.21267,
   14.17745,
   14.03567,
   12.72792,
   13.74773,
   14.3527,
   14.17745,
   14.21267,
   13.71131,
   15.36229,
   14.07125,
   15,
   14.8324,
   14.79865,
   14.14214,
   14.38749,
   14.56022,
   15.16575,
   14.62874,
   14.42221,
   14.69694,
   15.0333,
   14.45683,
   13.92839,
   14.45683,
   14.96663,
   15.74802,
   15.55635,
   17.86057,
   19.69772,
   22.89105,
   27.42262,
   29,
   27.16616,
   23.19483,
   19.15724,
   16.12452,
   14.52584,
   13.71131,
   13.71131,
   12.76715,
   11.40175,
   12.24745,
   12.49,
   11.35782,
   10.77033,
   10.53565,
   9.899495,
   9.219544,
   8.774964,
   6.164414,
   4.795832,
   2.828427,
   1.732051,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   6.244998,
   9.797959,
   10.63015,
   9.899495,
   10.53565,
   10.86278,
   11.7047,
   11.7047,
   13.45362,
   13.15295,
   13.30413,
   12.64911,
   14.21267,
   14.17745,
   14.03567,
   12.72792,
   13.74773,
   14.3527,
   14.17745,
   14.21267,
   13.71131,
   15.36229,
   14.07125,
   15,
   14.8324,
   14.79865,
   14.14214,
   14.38749,
   14.56022,
   15.16575,
   14.62874,
   14.42221,
   14.69694,
   15.0333,
   14.45683,
   13.92839,
   14.45683,
   14.96663,
   15.74802,
   15.55635,
   17.86057,
   19.69772,
   22.89105,
   27.42262,
   29,
   27.16616,
   23.19483,
   19.15724,
   16.12452,
   14.52584,
   13.71131,
   13.71131,
   12.76715,
   11.40175,
   12.24745,
   12.49,
   11.35782,
   10.77033,
   10.53565,
   9.899495,
   9.219544,
   8.774964,
   6.164414,
   4.795832,
   2.828427,
   1.732051,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Graph_Hist3002->SetMaximum(957);
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
   
   Double_t curvetot_fx1[137] = {
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
   477.675,
   479,
   480.325,
   481.65,
   482.3125,
   482.975,
   483.6375,
   484.3,
   484.9625,
   485.625,
   486.2875,
   486.95,
   487.6125,
   488.275,
   489.6,
   492.25,
   492.9125,
   493.575,
   494.2375,
   494.9,
   495.5625,
   496.225,
   496.8875,
   497.55,
   498.2125,
   498.875,
   499.5375,
   500.2,
   500.8625,
   501.525,
   502.1875,
   502.85,
   503.5125,
   504.175,
   505.5,
   506.825,
   508.15,
   508.8125,
   509.475,
   510.1375,
   510.8,
   511.4625,
   512.125,
   512.7875,
   513.45,
   514.1125,
   514.775,
   516.1,
   517.425,
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
   581.025,
   582.35,
   585,
   585};
   Double_t curvetot_fy1[137] = {
   69.57176,
   77.08867,
   84.35929,
   91.3862,
   98.172,
   104.7193,
   111.0309,
   117.1095,
   122.958,
   128.5793,
   133.9765,
   139.1528,
   144.1116,
   148.8564,
   153.391,
   157.7195,
   161.8461,
   165.7756,
   169.5129,
   173.0635,
   176.4332,
   179.6285,
   182.6561,
   185.5237,
   188.2391,
   190.8111,
   193.2489,
   195.5624,
   197.7621,
   199.8589,
   201.8645,
   203.7906,
   205.6495,
   207.4537,
   209.2154,
   210.947,
   212.6602,
   214.3663,
   216.0755,
   217.7971,
   219.5386,
   221.3061,
   223.1035,
   224.9322,
   226.7914,
   228.6772,
   230.5828,
   232.4981,
   234.4099,
   236.3017,
   238.1538,
   239.9434,
   241.6447,
   243.2297,
   244.6697,
   245.9418,
   247.0565,
   248.1542,
   249.7876,
   253.5787,
   257.3571,
   263.3583,
   272.6077,
   286.3578,
   295.3565,
   306.0103,
   318.4921,
   332.96,
   349.5481,
   368.3566,
   389.4408,
   412.8015,
   438.3746,
   466.0234,
   526.6027,
   657.7463,
   689.4684,
   719.4932,
   747.1569,
   771.8163,
   792.8721,
   809.7927,
   822.1355,
   829.5654,
   831.8691,
   828.9637,
   820.9009,
   807.8644,
   790.162,
   768.2129,
   742.5299,
   713.6984,
   682.3539,
   649.1574,
   579.8409,
   510.6966,
   445.8001,
   415.8915,
   388.0168,
   362.3308,
   338.9137,
   317.7793,
   298.884,
   282.1373,
   267.4121,
   254.5551,
   243.3962,
   225.4569,
   212.1844,
   202.3041,
   188.7516,
   179.1785,
   170.8992,
   162.8818,
   154.8144,
   146.6391,
   138.371,
   130.0419,
   121.6857,
   113.3341,
   105.0165,
   96.75933,
   88.58565,
   80.51545,
   72.56537,
   64.74887,
   57.0763,
   49.55506,
   42.18984,
   34.98287,
   27.93417,
   21.04184,
   14.30238,
   10.98851,
   10.01288,
   8.689896,
   8.689896};
   TGraph *graph = new TGraph(137,curvetot_fx1,curvetot_fy1);
   graph->SetName("curvetot");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_curvetot1 = new TH1F("Graph_curvetot1","Projection of totalPdf",137,293.5,611.5);
   Graph_curvetot1->SetMinimum(0);
   Graph_curvetot1->SetMaximum(914.187);
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
   
   Double_t sigWM_fx2[139] = {
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
   477.675,
   479,
   480.325,
   481.65,
   482.3125,
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
   489.6,
   492.25,
   492.9125,
   493.575,
   494.2375,
   494.9,
   495.5625,
   496.225,
   496.8875,
   497.55,
   498.2125,
   498.875,
   499.5375,
   500.2,
   500.8625,
   501.525,
   502.1875,
   502.85,
   503.5125,
   504.175,
   505.5,
   506.825,
   507.4875,
   508.15,
   508.8125,
   509.475,
   510.1375,
   510.8,
   511.4625,
   512.125,
   512.7875,
   513.45,
   514.1125,
   514.775,
   516.1,
   517.425,
   518.75,
   520.075,
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
   Double_t sigWM_fy2[139] = {
   0.004350785,
   0.005836076,
   0.007794068,
   0.01036328,
   0.01371893,
   0.01808145,
   0.02372664,
   0.03099767,
   0.0403192,
   0.05221371,
   0.06732047,
   0.0864171,
   0.110444,
   0.1405318,
   0.1780315,
   0.2245479,
   0.2819753,
   0.3525358,
   0.4388188,
   0.5438224,
   0.6709944,
   0.8242722,
   1.00812,
   1.227563,
   1.488214,
   1.796292,
   2.15863,
   2.582674,
   3.076456,
   3.648563,
   4.308072,
   5.064469,
   5.927544,
   6.907257,
   8.013576,
   9.256292,
   10.6448,
   12.18788,
   13.8934,
   15.76809,
   17.81719,
   20.04423,
   22.45068,
   25.03569,
   27.79583,
   30.72483,
   33.81344,
   37.04922,
   40.4165,
   43.89634,
   47.46656,
   51.10193,
   54.77432,
   58.45329,
   62.10762,
   65.71204,
   69.27459,
   72.93324,
   77.23827,
   83.80933,
   89.01752,
   96.4746,
   107.2058,
   122.4633,
   132.2251,
   143.6483,
   156.9058,
   172.1555,
   189.5317,
   209.1343,
   231.0187,
   255.1856,
   281.571,
   310.0381,
   340.3711,
   372.2716,
   506.7936,
   539.3747,
   570.2641,
   598.7981,
   624.3333,
   646.2705,
   664.078,
   677.3131,
   685.6409,
   688.8478,
   686.851,
   679.7021,
   667.5847,
   650.8068,
   629.7873,
   605.0391,
   577.1476,
   546.7481,
   514.5017,
   447.1004,
   379.8911,
   347.677,
   316.9491,
   288.0249,
   261.1394,
   236.4473,
   214.0288,
   193.8976,
   176.0101,
   160.2758,
   146.5675,
   134.7319,
   124.5989,
   108.7245,
   97.53425,
   89.75317,
   84.32776,
   80.44916,
   75.18908,
   71.28492,
   67.70221,
   64.12683,
   60.49828,
   56.82933,
   53.14939,
   49.48973,
   45.87983,
   42.3466,
   38.91394,
   35.6026,
   32.4301,
   29.41065,
   26.55529,
   23.87192,
   21.36552,
   19.03836,
   16.89023,
   14.91872,
   13.1195,
   11.48665,
   10.01288,
   8.689896,
   8.689896};
   graph = new TGraph(139,sigWM_fx2,sigWM_fy2);
   graph->SetName("sigWM");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);
   graph->SetLineColor(2);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_sigWM2 = new TH1F("Graph_sigWM2","Projection of totalPdf",139,293.5,611.5);
   Graph_sigWM2->SetMinimum(0);
   Graph_sigWM2->SetMaximum(757.7321);
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
   
   Double_t bkg_fx3[103] = {
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
   574.4,
   577.05,
   579.7,
   581.025,
   582.35,
   585,
   585};
   Double_t bkg_fy3[103] = {
   69.56741,
   77.08284,
   84.3515,
   91.37584,
   98.15828,
   104.7013,
   111.0072,
   117.0785,
   122.9177,
   128.5271,
   133.9092,
   139.0664,
   144.0011,
   148.7159,
   153.213,
   157.4949,
   161.5642,
   165.4231,
   169.0741,
   172.5197,
   175.7622,
   178.8042,
   181.648,
   184.2961,
   186.7509,
   189.0148,
   191.0903,
   192.9797,
   194.6856,
   196.2104,
   197.5564,
   198.7261,
   199.722,
   200.5464,
   201.2018,
   201.6907,
   202.0154,
   202.1784,
   202.1821,
   202.029,
   201.7214,
   201.2619,
   200.6528,
   199.8966,
   198.9956,
   197.9524,
   196.7693,
   195.4489,
   193.9934,
   192.4054,
   190.6873,
   188.8414,
   186.8703,
   184.7764,
   182.5621,
   180.2298,
   177.7819,
   175.221,
   172.5493,
   169.7694,
   166.8837,
   163.8945,
   160.8045,
   157.6158,
   154.3311,
   150.9527,
   147.483,
   143.9245,
   140.2797,
   136.5508,
   132.7405,
   128.8511,
   124.8849,
   120.8446,
   116.7324,
   112.5509,
   108.3024,
   103.9894,
   99.6143,
   95.17955,
   90.68757,
   86.14079,
   81.54164,
   76.89255,
   72.19595,
   67.45427,
   62.66994,
   57.84539,
   52.98305,
   48.08535,
   43.15472,
   38.19358,
   33.20438,
   28.18954,
   23.15148,
   18.09264,
   13.01545,
   7.92234,
   2.815737,
   0.2581347,
   0,
   0,
   0};
   graph = new TGraph(103,bkg_fx3,bkg_fy3);
   graph->SetName("bkg");
   graph->SetTitle("Projection of totalPdf");
   graph->SetFillColor(1);
   graph->SetLineColor(3);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_bkg3 = new TH1F("Graph_bkg3","Projection of totalPdf",103,293.5,611.5);
   Graph_bkg3->SetMinimum(0);
   Graph_bkg3->SetMaximum(222.4003);
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
   entry=leg->AddEntry("sigWM","K_{S} (dbl Gaus)","l");
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
   
   TH1D *frame_49add50__4 = new TH1D("frame_49add50__4","A RooPlot of \"m(#pi p#rightarrow#pi)\"",100,300,700);
   frame_49add50__4->SetBinContent(1,913.5);
   frame_49add50__4->SetMaximum(913.5);
   frame_49add50__4->SetEntries(1);
   frame_49add50__4->SetDirectory(0);
   frame_49add50__4->SetStats(0);
   frame_49add50__4->SetLineWidth(2);
   frame_49add50__4->SetMarkerStyle(20);
   frame_49add50__4->GetXaxis()->SetTitle("m(#pi p#rightarrow#pi) (MeV)");
   frame_49add50__4->GetXaxis()->SetNdivisions(505);
   frame_49add50__4->GetXaxis()->SetLabelFont(132);
   frame_49add50__4->GetXaxis()->SetLabelOffset(0.01);
   frame_49add50__4->GetXaxis()->SetLabelSize(0.06);
   frame_49add50__4->GetXaxis()->SetTitleSize(0.072);
   frame_49add50__4->GetXaxis()->SetTitleOffset(0.95);
   frame_49add50__4->GetXaxis()->SetTitleFont(132);
   frame_49add50__4->GetYaxis()->SetTitle("Events/(5 MeV)");
   frame_49add50__4->GetYaxis()->SetLabelFont(132);
   frame_49add50__4->GetYaxis()->SetLabelOffset(0.01);
   frame_49add50__4->GetYaxis()->SetLabelSize(0.06);
   frame_49add50__4->GetYaxis()->SetTitleSize(0.072);
   frame_49add50__4->GetYaxis()->SetTitleOffset(0.95);
   frame_49add50__4->GetYaxis()->SetTitleFont(132);
   frame_49add50__4->GetZaxis()->SetLabelFont(132);
   frame_49add50__4->GetZaxis()->SetLabelSize(0.06);
   frame_49add50__4->GetZaxis()->SetTitleSize(0.072);
   frame_49add50__4->GetZaxis()->SetTitleOffset(1.2);
   frame_49add50__4->GetZaxis()->SetTitleFont(132);
   frame_49add50__4->Draw("AXISSAME");
   pad1->Modified();
   c1->cd();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
