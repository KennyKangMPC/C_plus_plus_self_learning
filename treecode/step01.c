#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int N = 10;
  float x[N], y[N], z[N], m[N];
// Initialize
  for( int i=0; i<N; i++ ) {
    x[i] = rand() / (1. + RAND_MAX);
    y[i] = rand() / (1. + RAND_MAX);
    z[i] = rand() / (1. + RAND_MAX);
    m[i] = 1.0 / N;
  }
// Direct summation
  float dx,dy,dz,r,eps2=0.0001;
  for( int i=0; i<N; i++ ) {
    float p = -m[i] / sqrtf(eps2);
    for( int j=0; j<N; j++ ) {
      dx = x[i] - x[j];
      dy = y[i] - y[j];
      dz = z[i] - z[j];
      r = sqrtf(dx * dx + dy * dy + dz * dz + eps2);
      p += m[j] / r;
    }
    printf("%d %f\n",i,p);
  }

}