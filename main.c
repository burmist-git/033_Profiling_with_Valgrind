#include <iostream>
#include <valgrind/callgrind.h>

void log_gaussian1();
void log_gaussian2();
void log_gaussian3();

int main(){
  CALLGRIND_START_INSTRUMENTATION;
  CALLGRIND_TOGGLE_COLLECT;
  log_gaussian1();
  CALLGRIND_TOGGLE_COLLECT;
  CALLGRIND_STOP_INSTRUMENTATION;
  log_gaussian2();
  log_gaussian3();
  return 0;
}

void log_gaussian1(){
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int k = 0;
  double sum = 0.0;
  for(i = 0;i<100;i++)
    for(j = 0;j<100;j++)
      for(k = 0;k<100;k++)
	sum += 1.0;
  std::cout<<sum<<std::endl;
}

void log_gaussian2(){
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int k = 0;
  double sum = 0.0;
  for(i = 0;i<1000;i++)
    for(j = 0;j<1000;j++)
      for(k = 0;k<100;k++)
	sum += 1.0;
  std::cout<<sum<<std::endl;
}

void log_gaussian3(){
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int k = 0;
  double sum = 0.0;
  for(i = 0;i<1000;i++)
    for(j = 0;j<1000;j++)
      for(k = 0;k<1000;k++)
	sum += 1.0;
  std::cout<<sum<<std::endl;
}
