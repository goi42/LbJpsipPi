#include <cmath>
#include <vector>
#include <map>
#include <iostream>
#include <TMatrixD.h>
//---------useful matrix functions defined by me-------------//
double Trace(TMatrixD in){
  if(in.GetNrows()!=in.GetNcols()){
    cout<<"Trace only works on square matrices!"<<endl;
    exit(EXIT_FAILURE);
  }
  double out=0;
  for(int i=0; i<in.GetNrows(); i++)
    for(int j=0; j<in.GetNcols(); j++)
      if(i==j) out+=in[i][j];
  return out;
}
TMatrixD Transpose(TMatrixD in){
  TMatrixD out(in.GetNcols(),in.GetNrows());
  out.Transpose(in);
  return out;
}
//----------end matrix functions----------------------------//
//----------declarations------------------------------------//
int SWITCH=3; //3 for Fig. 3 4 for Fig. 4
double PAR[] = {0.0401445, 1.87719, 0.530877, -0.251579, 5.65448, 
		0.132386, -1.56158, 5.95771, 0.697887, 1.26759, 2.87638, -1.65421, 
		1.13512, 0.298039, -3.30635, -1.53112, 0.270024, 
		0.27917, -1.37604, -1.54434};
double Mai[] = {0.49368, 0.49761, 0.13498, 0.13498, 0.13957, 0.13957, 0.54786, 
		0.54786, 0.49368, 0.49761};
double mai[] = {0.93827, 0.93956, 1.11568, 1.19264, 1.18937, 1.19745, 1.11568, 
		1.19264, 1.32171, 1.31486};
double Mai0x[] = {(Mai[0] + Mai[1])/2, (Mai[0] + Mai[1])/
		  2, (Mai[3] + Mai[4] + Mai[5])/
		  3, (Mai[3] + Mai[4] + Mai[5])/
		  3, (Mai[3] + Mai[4] + Mai[5])/
		  3, (Mai[3] + Mai[4] + Mai[5])/3, Mai[6], 
		  Mai[7], (Mai[0] + Mai[1])/2, (Mai[0] + Mai[1])/2};
double mai0x[] = {(mai[0] + mai[1])/2, (mai[0] + mai[1])/2, 
		  mai[2], (mai[3] + mai[4] + mai[5])/
		  3, (mai[3] + mai[4] + mai[5])/
		  3, (mai[3] + mai[4] + mai[5])/3, 
		  mai[6], (mai[3] + mai[4] + mai[5])/
		  3, (mai[9] + mai[8])/2, (mai[9] + mai[8])/2};
const int Channels = 10;
TMatrixD mbn(Channels,Channels);//mbn = Chop[DiagonalMatrix[Table[mai[[i]], {i, 1, Channels}]]];
TMatrixD mmn(Channels,Channels);//mmn = Chop[DiagonalMatrix[Table[Mai[[i]], {i, 1, Channels}]]];
double fmespi = 0.09240, fmesk = 0.1130, fmeseta = 1.30*fmespi;
TMatrixD fmes(Channels,Channels);//fmes = Chop[DiagonalMatrix[Table[{fmesk, fmesk, fmespi, fmespi, fmespi, fmespi, fmeseta,fmeseta, fmesk, fmesk}[[i]], {i, 1, Channels}]]];
TMatrixD eins(Channels,Channels);//eins = IdentityMatrix[Channels];
TMatrixD null(Channels,Channels);//null = 0*eins;
TMatrixD im(Channels,Channels);//im = null;
TMatrixD ib(Channels,Channels);//ib = null;
  
double mu = (1/2)*(Mai[0]*Mai[0] - Mai[1]*Mai[1] + Mai[2]*Mai[2]);
double md = (1/2)*(Mai[1]*Mai[1] - Mai[0]*Mai[0] + Mai[2]*Mai[2]);
double ms = (1/2)*(Mai[0]*Mai[0] + Mai[1]*Mai[1] - Mai[2]*Mai[2]);
TMatrixD Mquark(3,3),l1(3,3),l2(3,3),l3(3,3),l4(3,3),l5(3,3),l6(3,3),l7(3,3),l8(3,3);
double Pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745;
double wd4 = 0/(16*Pi*Pi);

map<string,TMatrixD > fm;
map<string,TMatrixD > fb;

string mlist[] = {"Kminus","Kbar0","Pi0","Pi0","Piminus","Piplus","Eta","Eta","Kplus","K0"};
string blist[] = {"proton","neutron","lambda","sigma0","sigmaplus","sigmaminus","lambda","sigma0","cascademinus","cascadenull"};
double spurWT(TMatrixD lb,TMatrixD lj,TMatrixD li,TMatrixD la){
  return Trace(Transpose(lb)*((Transpose(lj)*li - li*Transpose(lj))*la - la*(Transpose(lj)*li - li*Transpose(lj))));
}
double spurg1(TMatrixD lb,TMatrixD lj,TMatrixD li,TMatrixD la){
  return Trace(Transpose(lb)*(Transpose(lj)*(li*la - la*li) - (li*la - la*li)*Transpose(lj))) + Trace(Transpose(lb)*(li*(Transpose(lj)*la - la*Transpose(lj)) - (Transpose(lj)*la - la*Transpose(lj))*li));
}
double spurg2(TMatrixD lb,TMatrixD lj,TMatrixD li,TMatrixD la){
  return Trace(Transpose(lb)*(Transpose(lj)*(li*la + la*li) - (li*la + la*li)*Transpose(lj))) + Trace(Transpose(lb)*(li*(Transpose(lj)*la + la*Transpose(lj)) - (Transpose(lj)*la + la*Transpose(lj))*li)); 
}
double spurg3(TMatrixD lb,TMatrixD lj,TMatrixD li,TMatrixD la){
  return Trace(Transpose(lb)*(Transpose(lj)*(li*la + la*li) + (li*la + la*li)*Transpose(lj))) + Trace(Transpose(lb)*(li*(Transpose(lj)*la + la*Transpose(lj)) + (Transpose(lj)*la + la*Transpose(lj))*li)); 
}
double spurg4(TMatrixD lb,TMatrixD lj,TMatrixD li,TMatrixD la){
  return 2*Trace(Transpose(lb)*la)*Trace(Transpose(lj)*li); 
}
double spurg5(TMatrixD lb,TMatrixD lj,TMatrixD li,TMatrixD la){
  return Trace(Transpose(lb)*((Transpose(lj)*li - li*Transpose(lj))*la - la*(Transpose(lj)*li - li*Transpose(lj)))); 
}
double spurg6(TMatrixD lb,TMatrixD lj,TMatrixD li,TMatrixD la){
  return Trace(Transpose(lb)*((Transpose(lj)*li - li*Transpose(lj))*la + la*(Transpose(lj)*li - li*Transpose(lj)))); 
}
double spurg7(TMatrixD lb,TMatrixD lj,TMatrixD li,TMatrixD la){
  return (1/2)*(Trace(Transpose(lb)*Transpose(lj))*Trace(li*la) - Trace(Transpose(lb)*li)*Trace(Transpose(lj)*la)); 
}
double spurgnull(TMatrixD lb,TMatrixD lj,TMatrixD li,TMatrixD la,TMatrixD Mquark){
  return Trace(Transpose(lb)*la)*Trace((Transpose(lj)*li + li*Transpose(lj))*Mquark); 
}
TMatrixD helpgDF(TMatrixD lb,TMatrixD lj,TMatrixD li,TMatrixD la,TMatrixD Mquark){
  TMatrixD out1 = (Transpose(lj)*li + li*Transpose(lj))*Mquark;
  TMatrixD out2 = Mquark*(Transpose(lj)*li + li*Transpose(lj));
  TMatrixD out3 = Transpose(lj)*Mquark*li;
  out3*=2;
  TMatrixD out4 = li*Mquark*Transpose(lj);
  out4*=2;
  return out1 + out2 + out3 + out4; 
}
double spurgD(TMatrixD lb,TMatrixD lj,TMatrixD li,TMatrixD la,TMatrixD Mquark){
  return Trace(Transpose(lb)*(helpgDF(lb, lj, li, la, Mquark)*la + la*helpgDF(lb, lj, li, la, Mquark))); 
}
double spurgF(TMatrixD lb,TMatrixD lj,TMatrixD li,TMatrixD la,TMatrixD Mquark){
  return Trace(Transpose(lb)*(helpgDF(lb, lj, li, la, Mquark)*la - la*helpgDF(lb, lj, li, la, Mquark))); 
}
TMatrixD spurWTmatrix(Channels,Channels);
TMatrixD spurn(Channels,Channels);
TMatrixD g(Channels,Channels);//g = -(1/4)*Chop[((Inverse[fmes]).spurn.(Inverse[fmes]))];
double fpi = 0.1;
TMatrixD spurg1matrix(Channels,Channels); 
TMatrixD spurg2matrix(Channels,Channels); 
TMatrixD spurg3matrix(Channels,Channels); 
TMatrixD spurg4matrix(Channels,Channels); 
TMatrixD spurg5matrix(Channels,Channels);
TMatrixD spurg6matrix(Channels,Channels);
TMatrixD spurg7matrix(Channels,Channels);
TMatrixD spurgnullmatrix(Channels,Channels);
TMatrixD spurgDmatrix(Channels,Channels);
TMatrixD spurgFmatrix(Channels,Channels);
TMatrixD spurg8matrix(Channels,Channels);
TMatrixD spurg9matrix(Channels,Channels);
TMatrixD spurg10matrix(Channels,Channels);
TMatrixD spurg11matrix(Channels,Channels);
//----------------------end declarations---------------------//
void fillthings(){
  if(SWITCH == 4){std::copy(Mai0x,Mai0x + 10,Mai); std::copy(mai0x,mai0x+10,mai);}//decide which set to use

  for(int i=0; i<Channels; i++) for(int j=0; j<Channels; j++){
      null[i][j]=0; im[i][j]=0; ib[i][j]=0;
      if(i==j){
	eins[i][j]=1;
	if(std::abs(mai[i])>=(1*10^(-10))){ mbn[i][j]=mai[i];
	}else{ mbn[i][j]=0;}
	if(std::abs(Mai[i])>=(1*10^(-10))){ mmn[i][j]=Mai[i];
	}else{ mmn[i][j]=0;}
	if((i>=0 && i<2)||(i>=8 && i<10)){ fmes[i][j]=fmesk;
	}else if(i>=2 && i<6){ fmes[i][j]=fmespi;
	}else if(i>=6 && i<8){ fmes[i][j]=fmeseta;}
      }else{
	mbn[i][j]=0; mmn[i][j]=0; fmes[i][j]=0; eins[i][j]=0;
      }
    }

  for(int i=0; i<Mquark.GetNrows(); i++) for(int j=0; j<Mquark.GetNcols(); j++){
      if(i==j){
	if(i==0) Mquark[i][j] = mu;
	if(i==1) Mquark[i][j] = md;
	if(i==2) Mquark[i][j] = ms;
      }else Mquark[i][j]=0;
    }

  l1[0][0]=(1/sqrt(2)); l1[0][1]=0;            l1[0][2]=0;
  l1[1][0]=0;           l1[1][1]=(-1/sqrt(2)); l1[1][2]=0;
  l1[2][0]=0;           l1[2][1]=0;            l1[2][2]=0;

  l2[0][0]=(1/sqrt(6)); l2[0][1]=0;            l2[0][2]=0;
  l2[1][0]=0;           l2[1][1]=(1/sqrt(6));  l2[1][2]=0;
  l2[2][0]=0;           l2[2][1]=0;            l2[2][2]=(-2/sqrt(6));

  l3[0][0]=0;           l3[0][1]=1;            l3[0][2]=0;
  l3[1][0]=0;           l3[1][1]=0;            l3[1][2]=0;
  l3[2][0]=0;           l3[2][1]=0;            l3[2][2]=0;

  l4[0][0]=0;           l4[0][1]=0;            l4[0][2]=0;
  l4[1][0]=1;           l4[1][1]=0;            l4[1][2]=0;
  l4[2][0]=0;           l4[2][1]=0;            l4[2][2]=0;

  l5[0][0]=0;           l5[0][1]=0;            l5[0][2]=1;
  l5[1][0]=0;           l5[1][1]=0;            l5[1][2]=0;
  l5[2][0]=0;           l5[2][1]=0;            l5[2][2]=0;

  l6[0][0]=0;           l6[0][1]=0;            l6[0][2]=0;
  l6[1][0]=0;           l6[1][1]=0;            l6[1][2]=1;
  l6[2][0]=0;           l6[2][1]=0;            l6[2][2]=0;

  l7[0][0]=0;           l7[0][1]=0;            l7[0][2]=0;
  l7[1][0]=0;           l7[1][1]=0;            l7[1][2]=0;
  l7[2][0]=0;           l7[2][1]=1;            l7[2][2]=0;

  l8[0][0]=0;           l8[0][1]=0;            l8[0][2]=0;
  l8[1][0]=0;           l8[1][1]=0;            l8[1][2]=0;
  l8[2][0]=1;           l8[2][1]=0;            l8[2][2]=0;
  fm = {{"Pi0",l1},{"Pi0",l1},{"Piplus",l3},{"Eta",l2},{"Kplus",l5},{"K0",l6},{"Kbar0",l7},{"Kminus",l8},{"Piminus",l4}};
  fb = {{"proton",l5},{"neutron",l6},{"lambda",l2},{"sigma0",l1},{"sigmaplus",l3},{"sigmaminus",l4},{"cascademinus",l8},{"cascadenull",l7}};

  for(int i=0; i<Channels; i++)
    for(int j=0; j<Channels; j++)
      spurWTmatrix[i][j] = spurWT(fb[blist[i]],fm[mlist[i]],fm[mlist[j]],fb[blist[j]]);
  spurn = spurWTmatrix;
  
  g = fmes.Invert()*spurn*fmes.Invert();
  g *= (-1/4);
  for(int i=0; i<Channels; i++)
    for(int j=0; j<Channels; j++)
      if(std::abs(g[i][j])<(1*10^(-10))) g[i][j]=0;


  for(int i=0; i<Channels; i++)
    for(int j=0; j<Channels; j++){
      spurg1matrix[i][j] = spurg1(fb[blist[i]],fm[mlist[i]],fm[mlist[j]],fb[blist[j]]);
      spurg2matrix[i][j] = spurg2(fb[blist[i]],fm[mlist[i]],fm[mlist[j]],fb[blist[j]]);
      spurg3matrix[i][j] = spurg3(fb[blist[i]],fm[mlist[i]],fm[mlist[j]],fb[blist[j]]);
      spurg4matrix[i][j] = spurg4(fb[blist[i]],fm[mlist[i]],fm[mlist[j]],fb[blist[j]]);
      spurg5matrix[i][j] = spurg5(fb[blist[i]],fm[mlist[i]],fm[mlist[j]],fb[blist[j]]);
      spurg6matrix[i][j] = spurg6(fb[blist[i]],fm[mlist[i]],fm[mlist[j]],fb[blist[j]]);
      spurg7matrix[i][j] = spurg7(fb[blist[i]],fm[mlist[i]],fm[mlist[j]],fb[blist[j]]);
      spurgnullmatrix[i][j] = spurgnull(fb[blist[i]],fm[mlist[i]],fm[mlist[j]],fb[blist[j]],Mquark);
      spurgDmatrix[i][j] = spurgD(fb[blist[i]],fm[mlist[i]],fm[mlist[j]],fb[blist[j]],Mquark);
      spurgFmatrix[i][j] = spurgF(fb[blist[i]],fm[mlist[i]],fm[mlist[j]],fb[blist[j]],Mquark);
    }
  spurg8matrix  = spurg1matrix;
  spurg9matrix  = spurg2matrix;
  spurg10matrix = spurg3matrix;
  spurg11matrix = spurg4matrix;
}
void BONN(){
  fillthings();


}