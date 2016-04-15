using namespace RooFit;

void fit_mass() {
  gROOT->SetBatch(kTRUE);
  
  //gROOT->ProcessLine(".x ../lhcbStyle.C");

  //set canvas style
  //gSystem->Load("libRooFit.so");
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetTextSize(0.3);

  //open file and get histogram
  TFile *inHistos;
  TH1F * h100;
  inHistos = new TFile("output/histos.root", "READ");
  h100 = (TH1F*)inHistos->Get("cutmassLb7");

  double massLb = 5500;
  double massLbmin = 5300;
  double massLbmax = 5650;

  RooRealVar *mass = new RooRealVar("mass","m(#Lambda_{b})",massLb,"MeV");
  RooDataHist *data = new RooDataHist("data","1D",RooArgList(*mass),h100);  

  //Construct Pdf Model
  double sigmin = 0;
  double sigmax = 1000;
  double amin = -100;
  double amax = -amin;
  double nmin = 0;
  double nmax = 1000;

  RooRealVar meanCB1("meanCB1","meanCB1",massLb,massLbmin,massLbmax);
  RooRealVar sigCB1("sigCB1","sigCB1",95.8761,sigmin,sigmax);
  RooRealVar aCB1("aCB1","aCB1",1,amin,amax);
  RooRealVar nCB1("nCB1","nCB1",5,nmin,nmax);
  RooRealVar meanCB2("meanCB2","meanCB2",massLb,massLbmin,massLbmax);
  RooRealVar sigCB2("sigCB2","sigCB2",1,sigmin,sigmax);
  RooRealVar aCB2("aCB2","aCB2",1,amin,amax);
  RooRealVar nCB2("nCB2","nCB2",5,nmin,nmax);
  RooRealVar mean1("mean1","mean1",massLb,massLbmin,massLbmax);
  RooRealVar sig1("sig1","sig1",105.228,sigmin,sigmax);
  RooRealVar mean2("mean2","mean2",massLb,massLbmin,massLbmax);
  RooRealVar sig2("sig2","sig2",149.45,sigmin,sigmax);
  RooRealVar mean3("mean3","mean3",massLb,massLbmin,massLbmax);
  RooRealVar sig3("sig3","sig3",65.3598,sigmin,sigmax);
  RooRealVar mean4("mean4","mean4",massLb,massLbmin,massLbmax);
  RooRealVar sig4("sig4","sig4",6,sigmin,sigmax);
  RooRealVar m1("m1","m1",2,0,100);
  RooRealVar c1("c1","c1",1,-100,100);
  RooRealVar p1("p1","p1",1,-100,100);
  
  RooCBShape CB1("CB1","CB1",*mass,meanCB1,sigCB1,aCB1,nCB1);
  RooCBShape CB2("CB2","CB2",*mass,meanCB2,sigCB2,aCB2,nCB2);
  RooGaussian gau1("gau1","gau1",*mass,mean1,sig1);
  RooGaussian gau2("gau2","gau2",*mass,mean2,sig2);
  RooGaussian gau3("gau3","gau3",*mass,mean3,sig3);
  RooGaussian gau4("gau4","gau4",*mass,mean4,sig4);
  RooArgusBG arg1("arg1","argus 1",*mass,m1,c1,p1);
  RooRealVar fCB1("fCB1","CB1_frac",0.1,0,1);
  RooRealVar fCB2("fCB2","CB2_frac",0.1,0,1);
  RooRealVar f1("f1","gau1_frac",0.1,0,1);
  RooRealVar f2("f2","gau2_frac",0.1,0,1);
  RooRealVar f3("f3","gau3_frac",0.1,0,1);
  //  RooAddPdf sig("sig","sig",RooArgList(gau1,gau2,gau3,gau4),RooArgList(f1,f2,f3));
  RooRealVar s11("s11","s11",0,-100,100);
  RooRealVar s12("s12","s12",0,-100,100);
  RooRealVar s13("s13","s13",0,-100,100);
  RooRealVar s14("s14","s14",0,-100,100);
  RooRealVar s15("s15","s15",0,-100,100);
  RooRealVar s16("s16","s16",0,-100,100);
  // RooRealVar s17("s17","s17",0,-100,100);
  // RooRealVar s18("s18","s18",0,-100,100);
  // RooRealVar s19("s19","s19",0,-100,100);
  // RooRealVar s110("s110","s110",0,-100,100);
  // RooRealVar s111("s111","s111",0,-100,100);
  // RooRealVar s112("s112","s112",0,-100,100);
  // RooRealVar s113("s113","s113",0,-100,100);
  // RooRealVar s114("s114","s114",0,-100,100);
  // RooRealVar s115("s115","s115",0,-100,100);
  // RooRealVar s116("s116","s116",0,-100,100);
  RooRealVar s21("s21","s21",0,-100,100);
  RooRealVar s22("s22","s22",0,-100,100);
  RooRealVar s23("s23","s23",0,-100,100);
  RooRealVar s24("s24","s24",0,-100,100);
  RooRealVar s25("s25","s25",0,-100,100);
  RooRealVar s26("s26","s26",0,-100,100);
  // RooRealVar s27("s27","s27",0,-100,100);
  // RooRealVar s28("s28","s28",0,-100,100);
  // RooRealVar s29("s29","s29",0,-100,100);
  // RooRealVar s210("s210","s210",0,-100,100);
  // RooRealVar s211("s211","s211",0,-100,100);
  // RooRealVar s212("s212","s212",0,-100,100);
  // RooRealVar s213("s213","s213",0,-100,100);
  // RooRealVar s214("s214","s214",0,-100,100);
  // RooRealVar s215("s215","s215",0,-100,100);
  // RooRealVar s216("s216","s216",0,-100,100);
  RooChebychev sigC1("sigC1","sigC1", *mass, RooArgList(s11,s12,s13,s14,s15,s16));
  RooChebychev sigC2("sigC2","sigC2", *mass, RooArgList(s21,s22,s23,s24,s25,s26));
  RooRealVar fC1("fC1","sigC1_frac",0.1,0,1);
  RooAddPdf sig("sig","sig",RooArgList(sigC1,sigC2),RooArgList(fC1));

  //Poly func BKG mass
  RooRealVar b1("b1","b1",-3.0021e-01,-3,3);
  RooRealVar b2("b2","b2",-3.0021e-01,-3,3);
  RooArgList bList(b1);
  RooChebychev bkg("bkg","bkg", *mass, bList);
  
  /////
  
  RooRealVar nbkg("N_{bkg}","N_{bkg}",100,0,100000000);
  RooRealVar nsig("N_{sig}","N_{sig}",100,0,100000000);
        
  RooArgList shapes;
  RooArgList yields;
  
  shapes.add(sig);   yields.add(nsig);
  shapes.add(bkg);   yields.add(nbkg);
  
  RooAddPdf totalPdf("totalPdf","totalPdf",shapes,yields);
  //  totalPdf.fitTo(*data,Extended(kTRUE),Save(kTRUE));
  RooAbsReal * nll = totalPdf.createNLL(*data,Extended(kTRUE),Save(kTRUE));
  RooMinuit m(*nll);
  m.setVerbose(kFALSE);
  m.migrad();
  m.minos();        
        
  RooPlot *framex = mass->frame();
  data->plotOn(framex,Name("Hist"),MarkerColor(kBlack),LineColor(kBlack),DataError(RooAbsData::SumW2));
  totalPdf.plotOn(framex,Name("curvetot"),LineColor(kBlue));
  totalPdf.plotOn(framex,Name("signal"),LineStyle(kDashed),LineColor(kGreen),Components(sig)); 
  totalPdf.plotOn(framex,Name("signal: Chebychev 1"),LineStyle(kDashed),LineColor(kCyan+1),Components(sigC1));
  totalPdf.plotOn(framex,Name("signal: Chebychev 2"),LineStyle(kDashed),LineColor(kCyan+2),Components(sigC2));
  totalPdf.plotOn(framex,Name("curvebkg"),LineStyle(kDashed),LineColor(kRed),Components(RooArgSet(bkg)));  

  TLegend *leg = new TLegend(0.84, 0.84, .99, .95);
  leg->AddEntry(framex->findObject("curvetot"),"Total PDF","l");
  leg->AddEntry(framex->findObject("signal"),"Total Signal","l");
  // leg->AddEntry(framex->findObject("signal: CB1"),"Signal: Crystal Ball1","l");
  // leg->AddEntry(framex->findObject("signal: CB2"),"Signal: Crystal Ball2","l");
  // leg->AddEntry(framex->findObject("signal: gau1"),"Signal: Gaussian1","l");
  // leg->AddEntry(framex->findObject("signal: gau2"),"Signal: Gaussian2","l");
  // leg->AddEntry(framex->findObject("signal: gau3"),"Signal: Gaussian3","l");
  // leg->AddEntry(framex->findObject("signal: gau4"),"Signal: Gaussian4","l");
  // leg->AddEntry(framex->findObject("signal: arg1"),"Signal: Argus","l");
  leg->AddEntry(framex->findObject("signal: Chebychev 1"),"Signal: Chebychev 1","l");
  leg->AddEntry(framex->findObject("signal: Chebychev 2"),"Signal: Chebychev 2","l");
  leg->AddEntry(framex->findObject("curvebkg"),"Background","l");
  
  // Calculate chi2/ndf
  RooArgSet *floatpar = totalPdf.getParameters(data);
  int floatpars = (floatpar->selectByAttrib("Constant",kFALSE))->getSize();
  Double_t chi2 = framex->chiSquare("curvetot","Hist",floatpars);
  TString chi2string = Form("%f",chi2);
  
  TCanvas *can1 = new TCanvas("can1","can1",1200,800);
  TPad *pad1 = new TPad("pad1","pad1",0.0,0.3,1.0,1.0);
  TPad *pad2 = new TPad("pad2","pad2",0.0,0.0,1.0,0.3);
  pad1->SetBottomMargin(0);
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.5);
  pad2->SetBorderMode(0);
  pad1->SetBorderMode(0);
  can1->SetBorderMode(0);
  pad1->Draw();
  pad2->Draw();
  pad1->cd();
  //pad1->SetLogy();
  framex->SetMinimum(0.0001);

  framex->addObject(leg);//add legend to frame
  
  double Y_nsig = nsig.getVal();
  double E_nsig = TMath::Max(fabs(nsig.getErrorLo()),nsig.getErrorHi()); 
  TString Y_nsigstring = Form("%f",Y_nsig);
  TString E_nsigstring = Form("%f",E_nsig);
  
  double Y_nbkg = nbkg.getVal();
  double E_nbkg = TMath::Max(fabs(nbkg.getErrorLo()),nbkg.getErrorHi());

  //list important parameters on the plot
  TPaveText* txt = new TPaveText(0.1,0.5,0.7,0.9,"BRNDC");
  txt->SetTextSize(0.04);
  txt->SetTextColor(kBlack);
  txt->SetBorderSize(0);
  txt->SetFillColor(0);
  txt->SetFillStyle(0);
  txt->AddText("#chi^{2}/N_{DoF} = "+chi2string);  
  txt->AddText("Yield #Sigma^{0} = "+Y_nsigstring+" +/- "+E_nsigstring);
  framex->addObject(txt);

  gPad->SetTopMargin(0.06);
  framex->Draw();

  // Pull distribution
  RooPlot *framex2 = mass->frame();
  RooHist* hpull = framex->pullHist("Hist","curvetot");
  framex2->addPlotable(hpull,"P");
  hpull->SetLineColor(kBlack);
  hpull->SetMarkerColor(kBlack);
  framex2->SetTitle(0);
  framex2->GetYaxis()->SetTitle("Pull");
  framex2->GetYaxis()->SetTitleSize(0.15);
  framex2->GetYaxis()->SetLabelSize(0.15);
  framex2->GetXaxis()->SetTitleSize(0.2);
  framex2->GetXaxis()->SetLabelSize(0.15);
  framex2->GetYaxis()->CenterTitle();
  framex2->GetYaxis()->SetTitleOffset(0.45);
  framex2->GetXaxis()->SetTitleOffset(1.1);
  framex2->GetYaxis()->SetNdivisions(505);
  framex2->GetYaxis()->SetRangeUser(-8.8,8.8);
  pad2->cd();
  framex2->Draw();

  std::cout << "chi2/nDoF: " << chi2 << endl;
  std::cout << "nsig: " << Y_nsig << " +/- " <<E_nsig<<endl;
  std::cout << "nbkg: " << Y_nbkg << " +/- " <<E_nbkg<<endl;
  // std::cout << "rsig: " << rsig.getVal() <<endl;
  // std::cout << "delm: " << delm.getVal() <<endl;
  // std::cout << "meanCB1: " << meanCB1.getVal() <<endl;
  // std::cout << "meanCB2: " << meanCB2.getVal() <<endl;
  // std::cout << "mean1: " << mean1.getVal() <<endl;
  // std::cout << "mean2: " << mean2.getVal() <<endl;  
  // std::cout << "mean3: " << mean3.getVal() <<endl;  
  // std::cout << "mean4: " << mean4.getVal() <<endl;  
  // std::cout << "sigCB1: " << sigCB1.getVal() <<endl;
  // std::cout << "sigCB2: " << sigCB2.getVal() <<endl;
  // std::cout << "sig1: " << sig1.getVal() <<endl;
  // std::cout << "sig2: " << sig2.getVal() <<endl;
  // std::cout << "sig3: " << sig3.getVal() <<endl;
  // std::cout << "sig4: " << sig4.getVal() <<endl;
  // std::cout << "aCB1: " << aCB1.getVal() <<endl;
  // std::cout << "aCB2: " << aCB2.getVal() <<endl;
  // std::cout << "nCB1: " << nCB1.getVal() <<endl;
  // std::cout << "nCB2: " << nCB2.getVal() <<endl;
  // std::cout << "m1: " << m1.getVal() <<endl;
  // std::cout << "c1: " << c1.getVal() <<endl;
  // std::cout << "p1: " << p1.getVal() <<endl;
  // std::cout << "fCB1: " << fCB1.getVal() <<endl;
  // std::cout << "fCB2: " << fCB2.getVal() <<endl;
  // std::cout << "f1: " << f1.getVal() <<endl;
  // std::cout << "f2: " << f2.getVal() <<endl;
  // std::cout << "f3: " << f3.getVal() <<endl;
  std::cout << "b1: " << b1.getVal() <<endl;
  std::cout << "s11: " << s11.getVal() <<endl;
  std::cout << "s12: " << s12.getVal() <<endl;
  std::cout << "s13: " << s13.getVal() <<endl;
  std::cout << "s14: " << s14.getVal() <<endl;
  std::cout << "s21: " << s21.getVal() <<endl;
  std::cout << "s22: " << s22.getVal() <<endl;
  std::cout << "s23: " << s23.getVal() <<endl;
  std::cout << "s24: " << s24.getVal() <<endl;
  //std::cout << "b2: " << b2.getVal() <<endl;
  
  can1->Print("output/fit_2Cheb6.pdf");
  can1->SaveAs("output/fit_2Cheb6.C");
  
  gROOT->SetBatch(kFALSE);
}
