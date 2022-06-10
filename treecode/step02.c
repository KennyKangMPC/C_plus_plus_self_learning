#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int N = 10;
  float xi[N], yi[N], zi[N], pi[N];
  float xj[N], yj[N], zj[N], mj[N];
// Initialize
  for( int i=0; i<N; i++ ) {
    xi[i] = -rand() / (1. + RAND_MAX);
    yi[i] = -rand() / (1. + RAND_MAX);
    zi[i] = -rand() / (1. + RAND_MAX);
    xj[i] =  rand() / (1. + RAND_MAX);
    yj[i] =  rand() / (1. + RAND_MAX);
    zj[i] =  rand() / (1. + RAND_MAX);
    mj[i] = 1.0 / N;
  }
// Direct summation
  float dx, dy, dz, r, eps2=0.0001;
  for( int i=0; i<N; i++ ) {
    float p = 0;
    for( int j=0; j<N; j++ ) {
      dx = xi[i] - xj[j];
      dy = yi[i] - yj[j];
      dz = zi[i] - zj[j];
      r = sqrtf(dx * dx + dy * dy + dz * dz + eps2);
      p += mj[j] / r;
    }
    pi[i] = p;
  }
// Multipole expansion
  float xc=0.5, yc=0.5, zc=0.5;
  float multipole[10]={0,0,0,0,0,0,0,0,0,0};
  for( int j=0; j<N; j++ ) {
    dx = xc - xj[j];
    dy = yc - yj[j];
    dz = zc - zj[j];
    multipole[0] += mj[j];
    multipole[1] += mj[j] * dx;
    multipole[2] += mj[j] * dy;
    multipole[3] += mj[j] * dz;
    multipole[4] += mj[j] * dx * dx / 2;
    multipole[5] += mj[j] * dy * dy / 2;
    multipole[6] += mj[j] * dz * dz / 2;
    multipole[7] += mj[j] * dx * dy / 2;
    multipole[8] += mj[j] * dy * dz / 2;
    multipole[9] += mj[j] * dz * dx / 2;
  }
// Evaluate potential
  float X, Y, Z, R, R3, R5, err=0, rel=0;
  for( int i=0; i<N; i++ ) {
    float p = 0;
    X = xi[i] - xc;
    Y = yi[i] - yc;
    Z = zi[i] - zc;
    R = sqrtf(X * X + Y * Y + Z * Z);
    R3 = R * R * R;
    R5 = R3 * R * R;
    p += multipole[0] / R;
    p += multipole[1] * (-X / R3);
    p += multipole[2] * (-Y / R3);
    p += multipole[3] * (-Z / R3);
    p += multipole[4] * (3 * X * X / R5 - 1 / R3);
    p += multipole[5] * (3 * Y * Y / R5 - 1 / R3);
    p += multipole[6] * (3 * Z * Z / R5 - 1 / R3);
    p += multipole[7] * (3 * X * Y / R5);
    p += multipole[8] * (3 * Y * Z / R5);
    p += multipole[9] * (3 * Z * X / R5);
    err += (pi[i] - p) * (pi[i] - p);
    rel += pi[i] * pi[i];
    printf("%d %f %f\n",i,pi[i],p);
  }
  printf("error : %f\n",sqrtf(err/rel));
}
