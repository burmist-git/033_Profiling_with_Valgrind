#pragma once

void log_gaussian(const auto (&x), const auto (&mean), const auto (&sigma), auto (&log_pdf));
double sum(const auto (&log_pdf));
double sum1();
template <class T>
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}
