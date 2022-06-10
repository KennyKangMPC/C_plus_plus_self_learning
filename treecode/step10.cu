#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int   const THREADS = 8;
float const EPS2    = 0.0001;
__device__ __constant__ int constsDevc[2];

__global__ void multipole(float4 *targetGlob, float *multipGlob) {
  float R, R3, R5;
  float3 d;
  float4 target = targetGlob[blockIdx.x * THREADS + threadIdx.x];
  target.w = 0;
  d.x = target.x - multipGlob[0];
  d.y = target.y - multipGlob[1];
  d.z = target.z - multipGlob[2];
  R = rsqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
  R3 = R * R * R;
  R5 = R3 * R * R;
  target.w += multipGlob[ 3] * R;
  target.w += multipGlob[ 4] * (-d.x * R3);
  target.w += multipGlob[ 5] * (-d.y * R3);
  target.w += multipGlob[ 6] * (-d.z * R3);
  target.w += multipGlob[ 7] * (3 * d.x * d.x * R5 - 1 * R3);
  target.w += multipGlob[ 8] * (3 * d.y * d.y * R5 - 1 * R3);
  target.w += multipGlob[ 9] * (3 * d.z * d.z * R5 - 1 * R3);
  target.w += multipGlob[10] * (3 * d.x * d.y * R5);
  target.w += multipGlob[11] * (3 * d.y * d.z * R5);
  target.w += multipGlob[12] * (3 * d.z * d.x * R5);
  targetGlob[blockIdx.x * THREADS + threadIdx.x] = target;
}

int main() {
  int N = 33;
  int Nround = (N  / THREADS + 1) * THREADS;
  int Mround = (13 / THREADS + 1) * THREADS;
  int     constsHost[2] = {N, Nround};
  float4 *sourceHost, *sourceDevc;
  float4 *targetHost, *targetDevc;
  float  *multipHost, *multipDevc;
// Allocate memory on host and device
  sourceHost = (float4*)     malloc( Nround*sizeof(float4) );
  targetHost = (float4*)     malloc( Nround*sizeof(float4) );
  multipHost = (float *)     malloc( Mround*sizeof(float ) );
  cudaMalloc(  (void**) &sourceDevc, Nround*sizeof(float4) );
  cudaMalloc(  (void**) &targetDevc, Nround*sizeof(float4) );
  cudaMalloc(  (void**) &multipDevc, Mround*sizeof(float ) );
// Initialize
  for( int i=0; i<N; i++ ) {
    targetHost[i].x = -rand() / (1. + RAND_MAX);
    targetHost[i].y = -rand() / (1. + RAND_MAX);
    targetHost[i].z = -rand() / (1. + RAND_MAX);
    sourceHost[i].x =  rand() / (1. + RAND_MAX);
    sourceHost[i].y =  rand() / (1. + RAND_MAX);
    sourceHost[i].z =  rand() / (1. + RAND_MAX);
    sourceHost[i].w = 1.0 / N;
  }
  multipHost[0] = multipHost[1] = multipHost[2] = 0.5;
  for( int i=3; i<13; i++ ) multipHost[i] = 0;
  float dx,dy,dz;
  for( int j=0; j<N; j++ ) {
    dx = multipHost[0] - sourceHost[j].x;
    dy = multipHost[1] - sourceHost[j].y;
    dz = multipHost[2] - sourceHost[j].z;
    multipHost[ 3] += sourceHost[j].w;
    multipHost[ 4] += sourceHost[j].w * dx;
    multipHost[ 5] += sourceHost[j].w * dy;
    multipHost[ 6] += sourceHost[j].w * dz;
    multipHost[ 7] += sourceHost[j].w * dx * dx / 2;
    multipHost[ 8] += sourceHost[j].w * dy * dy / 2;
    multipHost[ 9] += sourceHost[j].w * dz * dz / 2;
    multipHost[10] += sourceHost[j].w * dx * dy / 2;
    multipHost[11] += sourceHost[j].w * dy * dz / 2;
    multipHost[12] += sourceHost[j].w * dz * dx / 2;
  }
// Direct summation on device
  cudaMemcpyToSymbol(constsDevc,constsHost,     2*sizeof(int   ));
  cudaMemcpy        (targetDevc,targetHost,Nround*sizeof(float4),cudaMemcpyHostToDevice);
  cudaMemcpy        (multipDevc,multipHost,Mround*sizeof(float ),cudaMemcpyHostToDevice);
  multipole<<< Nround/THREADS, THREADS >>>(targetDevc,multipDevc);
  cudaMemcpy        (targetHost,targetDevc,Nround*sizeof(float4),cudaMemcpyDeviceToHost);
// Direct summation on host
  float r;
  for( int i=0; i<N; i++ ) {
    float p = 0;
    for( int j=0; j<N; j++ ) {
      dx = targetHost[i].x - sourceHost[j].x;
      dy = targetHost[i].y - sourceHost[j].y;
      dz = targetHost[i].z - sourceHost[j].z;
      r = sqrtf(dx * dx + dy * dy + dz * dz + EPS2);
      p += sourceHost[j].w / r;
    }
    printf("%d %f %f\n",i,p,targetHost[i].w);
  }
}
