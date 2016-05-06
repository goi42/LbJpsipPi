#ifndef __save_plot_fit_mass_C_INCLUDED__
#define __save_plot_fit_mass_C_INCLUDED__
void save_plot_fit_mass(TString fileN, RooRealVar *mass, RooDataSet *data, RooAddPdf totalPdf, RooArgList shapes, RooArgList yields){
  TString placeholder;//to add strings before using them, e.g., for saving text files
  //stuff to hold info
  ofstream textfile;//create text file to hold data
  placeholder = "plots/fit"+fileN+".txt";
  textfile.open(placeholder);
  TString outputtext;//for useful text

  //make frame
  RooPlot *framex = mass->frame();
  framex->GetYaxis()->SetTitle("Events/(5 MeV)");
  //plot data
  data->plotOn(framex,Name("Hist"),MarkerColor(kBlack),LineColor(kBlack),DataError(RooAbsData::SumW2));
  //plot totalPdf
  totalPdf.plotOn(framex,Name("curvetot"),LineColor(kBlue));
  //create legend
  // TLegend *leg = new TLegend(0.2, 0.02, .4, .42);  
  TLegend *leg = new TLegend(0.75, 0.02, 1, .42);  
  leg->SetTextSize(0.06);
  leg->AddEntry(framex->findObject("curvetot"),"Total PDF","l");
  //iterate over totalPdf components
  RooArgSet* totalPdfComponents = totalPdf.getComponents();
  TIterator* itertPC = totalPdfComponents->createIterator();
  RooAddPdf* vartPC = (RooAddPdf*) itertPC->Next();
  vartPC = (RooAddPdf*) itertPC->Next();//skip totalPdf itself in iterator
  int i=0;//color index
  while(vartPC){//loop over compotents of totalPdf
    TString vartPCtitle = vartPC->GetTitle();
    TIterator* itercompPars;//forward declare so it persists outside the if statement
    RooRealVar* varcompPars;
    if(!(vartPCtitle.Contains(":")||vartPCtitle.Contains("@"))){//only for non-sub-shapes
      RooArgSet* compPars = vartPC->getParameters(data);//set of the parameters of the component the loop is on
      itercompPars = compPars->createIterator();
      varcompPars = (RooRealVar*) itercompPars->Next();
    
      while(varcompPars){//write and print mean, sig, etc. of sub-shapes
        TString vartitle = varcompPars->GetTitle();
        double varval = varcompPars->getVal();
        TString varvalstring = Form("%f",varval);
        double hi = varcompPars->getErrorHi();
        
        TString varerrorstring = "[exact]";
        if(hi!=-1){
          double lo = varcompPars->getErrorLo();
          double varerror = TMath::Max(fabs(lo),hi);
          varerrorstring = Form("%E",varerror);
        }
        
        outputtext = vartitle+" = "+varvalstring+" +/- "+varerrorstring;
        textfile<<outputtext<<endl;
        cout<<outputtext<<endl;
        
        varcompPars = (RooRealVar*) itercompPars->Next(); 
      }
      //plot sub-shapes and add to legend
      while(i==0||i==10||i==4||i==1||i==5||(i>=10&&i<=27))i++;//avoid white and blue and black and yellow and horribleness
      totalPdf.plotOn(framex,Name(vartPC->GetName()),LineStyle(kDashed),LineColor(i),Components(vartPC->GetName()));
      leg->AddEntry(framex->findObject(vartPC->GetName()),vartPCtitle,"l");
      i++;
    }
    vartPC = (RooAddPdf*) itertPC->Next();
    itercompPars->Reset();//make sure it's ready for the next vartPC
  }
  
  // Calculate chi2/ndf
  RooArgSet *floatpar = totalPdf.getParameters(data);
  int floatpars = (floatpar->selectByAttrib("Constant",kFALSE))->getSize();
  Double_t chi2 = framex->chiSquare("curvetot","Hist",floatpars);
  TString chi2string = Form("%f",chi2);
  //create text box to list important parameters on the plot
  // TPaveText* txt = new TPaveText(0.1,0.5,0.7,0.9,"NBNDC");
  // txt->SetTextSize(0.06);
  // txt->SetTextColor(kBlack);
  // txt->SetBorderSize(0);
  // txt->SetFillColor(0);
  // txt->SetFillStyle(0);
  outputtext = "#chi^{2}/N_{DoF} = "+chi2string;
  cout<<outputtext<<endl;
  textfile<<outputtext<<endl;
  // txt->AddText(outputtext);
  
  // Print stuff
  TIterator* iteryields =  yields.createIterator();
  RooRealVar* varyields = (RooRealVar*) iteryields->Next();//only inherits things from TObject unless class specified
  vector<double> Y, E;//holds yields and associated errors
  vector<TString> YS, ES;//holds strings of the corresponding yields
  int j=0;//count vector position
  int jS=0, jL=0;//these hold the position of the S and L results;initialized in case there is no nsigS or nsigL
  while(varyields){//loop over yields
    TString varname = varyields->GetName();
    TString vartitle = varyields->GetTitle();
    double varval = varyields->getVal();
    Y.push_back(varval);
    double lo = varyields->getErrorLo();
    double hi = varyields->getErrorHi();
    E.push_back(TMath::Max(fabs(lo),hi));
    YS.push_back(Form("%f",Y[j]));
    ES.push_back(Form("%f",E[j]));
    
    if(varname=="nsigS") jS=j;
    if(varname=="nsigL") jL=j;
    
    outputtext = vartitle+" = "+YS[j]+" +/- "+ES[j];
    cout<<outputtext<<endl;
    textfile<<outputtext<<endl;
    //txt->AddText(outputtext);
    
    varyields = (RooRealVar*) iteryields->Next();
    j++;
  }
  //S/L
  double result = Y[jS]/Y[jL];
  double E_result = TMath::Abs(result)*sqrt(pow(E[jS]/Y[jS],2)+pow(E[jL]/Y[jL],2));
  TString resultstring = Form("%E",result);
  TString E_resultstring = Form("%E",E_result);
  outputtext = "Y_{#Sigma^{0}}/Y_{#Lambda} = "+resultstring+" +/- "+E_resultstring;
  cout<<outputtext<<endl;
  textfile<<outputtext<<endl;
  //txt->AddText(outputtext);
  double resultlimit = (Y[jS]+E[jS])/(Y[jL]-E[jL]);
  outputtext = Form("%E",resultlimit);
  outputtext = "limit = "+outputtext;
  cout<<outputtext<<endl;
  textfile<<outputtext<<endl;
  //txt->AddText(outputtext);
  double resultlimit_90cl = 1.6*(Y[jS]+E[jS])/(Y[jL]-E[jL]);
  outputtext = Form("%E",resultlimit_90cl);
  outputtext = "limit at 90% confidence level = "+outputtext;
  cout<<outputtext<<endl;
  textfile<<outputtext<<endl;
  //txt->AddText(outputtext);
  
  // Create canvas and pads, set style
  TCanvas *c1 = new TCanvas("c1","data fits",1200,800);
  TPad *pad1 = new TPad("pad1","pad1",0.0,0.3,1.0,1.0);
  TPad *pad2 = new TPad("pad2","pad2",0.0,0.0,1.0,0.3);
  pad1->SetBottomMargin(0);
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.5);
  pad2->SetBorderMode(0);
  pad1->SetBorderMode(0);
  c1->SetBorderMode(0);
  pad2->Draw();
  pad1->Draw();
  pad1->cd();
  framex->SetMinimum(1);
  framex->SetMaximum(7500);
  
  framex->addObject(leg);//add legend to frame
  //framex->addObject(txt);//add text to frame

  gPad->SetTopMargin(0.06);
  pad1->SetLogy();
  // pad1->Range(4100,0,6100,0.0005);
  pad1->Update();
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

  c1->cd();

  placeholder = "plots/fit"+fileN+".eps";
  c1->Print(placeholder);
  placeholder = "plots/fit"+fileN+".C";
  c1->SaveAs(placeholder);
  textfile.close();

}
#endif
