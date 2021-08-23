#include <time.h>
#include "TRandom3.h"
#include <math.h>
#include "log_gaussian_lib.h"

const unsigned int xDim = 196;
const unsigned int yDim = 609;
const unsigned int zDim = 38;
//const unsigned int xDim = 10;
//const unsigned int yDim = 10;
//const unsigned int zDim = 3;

int main(){
  TRandom3 *rnd = new TRandom3(1234567890);

  auto x = new double[xDim][yDim][1];
  auto mean = new double[xDim][yDim][zDim];
  auto sigma = new double[xDim][yDim][zDim];
  auto log_pdf = new double[xDim][yDim][zDim];
  
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int k = 0;
  unsigned int l = 0;
  //
  double x_mean = 3.0;
  double x_sigma = 1.0;
  double sigma_mean = 2.0;
  double sigma_sigma = 0.001;
  //
  for(i = 0;i<xDim;i++){
    for(j = 0;j<yDim;j++){
      x[i][j][0] = rnd->Gaus(x_mean,x_sigma);
      for(k = 0;k<zDim;k++){
	mean[i][j][k] = rnd->Gaus(x_mean,x_sigma);
	sigma[i][j][k] = rnd->Gaus(sigma_mean,sigma_sigma);
      }
    }
  }
  /*
  unsigned int n=10;
  double tottime = 0.0;
  for(l=0;l<n;l++){
    //clock_t tic = clock();
    log_gaussian(x, mean, sigma, log_pdf);
    //clock_t toc = clock();
    //tottime = tottime + (double)(toc - tic);
    printf("sum: %f \n", sum(log_pdf));
  }
  //printf("Elapsed: %f seconds\n", tottime / CLOCKS_PER_SEC / n);
  */
  return 0;
}
