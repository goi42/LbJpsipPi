//-----------------------------------------------------------------------------
// Implementation file for class : fit_mass
//
// 2015-10-23 : Michael Wilkinson
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
void fit_Lbmass(){
  using namespace RooFit;
  //open file and histograms, assign variables
  TFile *f = TFile::Open("histos.root","read");
  TH1F *hmass = (TH1F*)f->Get("cutmassLb");
  TH1F *hmassLL = (TH1F*)f->Get("cutmassLb2");
  TH1F *hmassDD = (TH1F*)f->Get("cutmassLb3");
  RooRealVar mass("mass","m(#Lambda_{b}^{0}) with Liming's cuts and without KS cut",4100,6100);
  RooDataHist data("data","mass data",mass,hmass);

  //Construct PDF model
  //Double Crystal Ball
  RooRealVar meanCB1("meanCB1","mean of Crystal Ball",5600,4100,6100);
  RooRealVar sigmaCB1("sigmaCB1","sigma of Crystal Ball",1);
  RooRealVar alphaCB1("alphaCB1","alpha of Crystal Ball",1);
  RooRealVar nCB1("nCB1","n of Crystal Ball",1);
  RooCBShape CB1("CB1","Crystal Ball function",mass,meanCB1,sigmaCB1,alphaCB1,nCB1);
  RooRealVar meanCB2("meanCB2","mean of Crystal Ball",5600,4100,6100);
  RooRealVar sigmaCB2("sigmaCB2","sigma of Crystal Ball",1);
  RooRealVar alphaCB2("alphaCB2","alpha of Crystal Ball",1);
  RooRealVar nCB2("nCB2","n of Crystal Ball",1);
  RooCBShape CB2("CB2","Crystal Ball function",mass,meanCB2,sigmaCB2,alphaCB2,nCB2);
  RooRealVar fCB1("fCB1","fraction of CB that is CB1",0.5,0.,1.);
  RooAddPdf CB("CB","#Lambda_{b} double Crystal Ball signal",RooArgList(CB1,CB2),fCB1);
  double Lbmasshi = 5620;
  double Lbmasslo = 5575;

  //perform fits
  CB.fitTo(data, Range(Lbmasslo,Lbmasshi));
  
  //plot PDF and data
  RooPlot *massframe = mass.frame();
  data.plotOn(massframe);
  CB.plotOn(massframe, Range(Lbmasslo,Lbmasshi));
  massframe->Draw();

  //Print final values of parameters
  meanCB1.Print();
  sigmaCB1.Print();
  alphaCB1.Print();
  nCB1.Print();
  meanCB2.Print();
  sigmaCB2.Print();
  alphaCB2.Print();
  nCB2.Print();
  fCB1.Print();
}
