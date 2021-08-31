#include <math.h>
#include <vector>
#include "log_gaussian_lib.h"

const unsigned int xDim = 196;
const unsigned int yDim = 609;
const unsigned int zDim = 38;
//const unsigned int xDim = 10;
//const unsigned int yDim = 10;
//const unsigned int zDim = 3;
void log_gaussian(const auto (&x), const auto (&mean), const auto (&sigma), auto (&log_pdf)){
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int k = 0;
  for(i = 0;i<xDim;i++)
    for(j = 0;j<yDim;j++)
      for(k = 0;k<zDim;k++)
	log_pdf[i][j][k] = -(x[i][j][0] - mean[i][j][k])*(x[i][j][0] - mean[i][j][k])/2.0/sigma[i][j][k]/sigma[i][j][k] - log(sqrt(2*3.141592653589793)*sigma[i][j][k]);
}

void log_gaussian_ref(const std::vector<std::vector<std::vector<double>>> (&x), const std::vector<std::vector<std::vector<double>>> (&mean),
		      const std::vector<std::vector<std::vector<double>>> (&sigma), std::vector<std::vector<std::vector<double>>> (&log_pdf)){
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int k = 0;
  for(i = 0;i<xDim;i++)
    for(j = 0;j<yDim;j++)
      for(k = 0;k<zDim;k++)
	log_pdf[i][j][k] = -(x[i][j][0] - mean[i][j][k])*(x[i][j][0] - mean[i][j][k])/2.0/sigma[i][j][k]/sigma[i][j][k] - log(sqrt(2*3.141592653589793)*sigma[i][j][k]);
}

double sum(const auto (&log_pdf)){
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int k = 0;
  double sum = 0.0;
  for(i = 0;i<xDim;i++)
    for(j = 0;j<yDim;j++)
      for(k = 0;k<zDim;k++)
	sum = sum + log_pdf[i][j][k];
  return sum;
}

double sum1(){
  return 0.0;
}
