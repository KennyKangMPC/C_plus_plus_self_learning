#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int   const N       = 33;
int   const THREADS = 8;
float const EPS2    = 0.0001;

__global__ void direct(float4 *sourceGlob, float *targetGlob) {
  float3 d;
  __shared__ float4 sourceShrd[THREADS];
  float4 target = sourceGlob[blockIdx.x * THREADS + threadIdx.x];
  target.w *= -rsqrtf(EPS2);
  for( int iblok=0; iblok<(N-1)/THREADS; iblok++) {
    __syncthreads();
    sourceShrd[threadIdx.x] = sourceGlob[iblok * THREADS + threadIdx.x];
    __syncthreads();
    for( int i=0; i<THREADS; i++ ) {
      d.x = target.x - sourceShrd[i].x;
      d.y = target.y - sourceShrd[i].y;
      d.z = target.z - sourceShrd[i].z;
      target.w += sourceShrd[i].w * rsqrtf(d.x * d.x + d.y * d.y + d.z * d.z + EPS2);
    }
  }
  int iblok = (N-1)/THREADS;
  __syncthreads();
  sourceShrd[threadIdx.x] = sourceGlob[iblok * THREADS + threadIdx.x];
  __syncthreads();
  for( int i=0; i<N - (iblok * THREADS); i++ ) {
    d.x = target.x - sourceShrd[i].x;
    d.y = target.y - sourceShrd[i].y;
    d.z = target.z - sourceShrd[i].z;
    target.w += sourceShrd[i].w * rsqrtf(d.x * d.x + d.y * d.y + d.z * d.z + EPS2);
  }
  targetGlob[blockIdx.x * THREADS + threadIdx.x] = target.w;
}

int main() {
  int Nround = (N / THREADS + 1) * THREADS;
  float4 *sourceHost, *sourceDevc;
  float  *targetHost, *targetDevc;
// Allocate memory on host and device
  sourceHost = (float4*)     malloc( Nround*sizeof(float4) );
  targetHost = (float *)     malloc( Nround*sizeof(float ) );
  cudaMalloc(  (void**) &sourceDevc, Nround*sizeof(float4) );
  cudaMalloc(  (void**) &targetDevc, Nround*sizeof(float ) );
// Initialize
  for( int i=0; i<N; i++ ) {
    sourceHost[i].x = rand() / (1. + RAND_MAX);
    sourceHost[i].y = rand() / (1. + RAND_MAX);
    sourceHost[i].z = rand() / (1. + RAND_MAX);
    sourceHost[i].w = 1.0 / N;
  }
// Direct summation on device
  cudaMemcpy        (sourceDevc,sourceHost,Nround*sizeof(float4),cudaMemcpyHostToDevice);
  direct<<< Nround/THREADS, THREADS >>>(sourceDevc,targetDevc);
  cudaMemcpy        (targetHost,targetDevc,Nround*sizeof(float ),cudaMemcpyDeviceToHost);
// Direct summation on host
  float dx, dy, dz, r;
  for( int i=0; i<N; i++ ) {
    float p = - sourceHost[i].w / sqrtf(EPS2);
    for( int j=0; j<N; j++ ) {
      dx = sourceHost[i].x - sourceHost[j].x;
      dy = sourceHost[i].y - sourceHost[j].y;
      dz = sourceHost[i].z - sourceHost[j].z;
      r = sqrtf(dx * dx + dy * dy + dz * dz + EPS2);
      p += sourceHost[j].w / r;
    }
    printf("%d %f %f\n",i,p,targetHost[i]);
  }
}
