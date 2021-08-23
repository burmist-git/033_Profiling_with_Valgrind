#include <iostream>

int main () {
  int i=5, j=6, k;
  long l=10, m=5, n;
  k=GetMax<int>(i,j);
  n=GetMax<long>(l,m);
  std::cout << k << endl;
  std::cout << n << endl;
  return 0;
}
