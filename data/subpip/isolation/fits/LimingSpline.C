#include "LimingSpline.h"
RooDalitzAmplitude::RooDalitzAmplitude(const RooDalitzAmplitude& other) :  
  _sa3(other._sa3),_sp3(other._sp3)
{}
void RooDalitzAmplitude::MakeSpline(RooArgList ires) const
{
  double x[NSP], y[NSP], z[NSP];
  double re[NSP], im[NSP];
  double a[NSP], ph[NSP];
  int nsp = ires.getSize()/3-1;
  for(int i=0; i<nsp; ++i) {
    x[i] = ((RooAbsReal&)ires[(i+1)*3+2]).getVal();
    re[i] = ((RooAbsReal&)ires[(i+1)*3]).getVal();  
    im[i] = ((RooAbsReal&)ires[(i+1)*3+1]).getVal();  
    //    re[i] = a[i]*cos(ph[i]);
    //    im[i] = a[i]*sin(ph[i]);
  }
  double xmin(2*m_pi), xmax(dlz_hy);
  _sa3 = TSpline3("_sa3",x,re, nsp, "", xmin, xmax);
  _sp3 = TSpline3("_sp3",x,im, nsp, "", xmin, xmax);
}

void RooDalitzAmplitude::spline(double mpp, double &r_ampl, double &i_ampl) const
{
  r_ampl = 0;
  i_ampl = 0;
  double asp = _sa3.Eval(mpp);
  double psp = _sp3.Eval(mpp);  
  //  std::cout << "Spline called2" << asp << " " << psp  << std::endl;  
  r_ampl = asp;//asp*cos(psp);
  i_ampl = psp;//asp*sin(psp);
  return;
}
