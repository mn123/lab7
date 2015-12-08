#include <iostream>
#include <cmath>

using namespace std;

void func(double* const k, const double* const y, const double eta);

int main(){
  const double dx=0.001;
  const int xEnd=100, N = xEnd/dx;
  double x=0, eta=0.5, y[2], k1[2], k2[2], k3[2], ytemp1[2], ytemp2[2];
  
  y[0] = 1e-5; // psi
  y[1] = sqrt(eta)*y[0]; //d(psi)/dx
  
  for(int i=0; i<N; i++){
    x += dx;
   
    func(k1,y,eta);
    
    ytemp1[0]=y[0]+dx/2*k1[0];
    ytemp1[1]=y[1]+dx/2*k1[1];
    func(k2,ytemp1,eta);
    
    ytemp2[0]=y[0]+dx*(2*k2[0]-k1[0]);
    ytemp2[1]=y[1]+dx*(2*k2[1]-k1[1]);
    func(k3,ytemp2,eta);
    
    y[0] += dx/6*(k1[0]+4*k2[0]+k3[0]);
    y[1] += dx/6*(k1[1]+4*k2[1]+k3[1]);
    
    cout << x << "\t" << y[0] << "\t" << y[1] << endl;
    
  }  
  
 
  return 0;
}

void func(double* const k, const double* const y, const double eta){
  k[0] = y[1];
  k[1] = (eta-y[0]*y[0])*y[0];  
}