#include <stdio.h>
#include <stdlib.h>

int const NCRIT = 10;

struct cell {
  int nleaf, nchild, leaf[NCRIT];
  float xc, yc, zc, r;
  cell *parent, *child[8];
};

void initialize(cell *C) {
  C->nleaf = C->nchild = 0;
  C->parent = NULL;
  for( int c=0; c<8; c++ ) C->child[c] = NULL;
}

void add_child(int octant, cell *C, cell *&CN) {
  ++CN;
  initialize(CN);
  CN->r  = C->r/2;
  CN->xc = C->xc + CN->r * ((octant & 1) * 2 - 1);
  CN->yc = C->yc + CN->r * ((octant & 2) - 1    );
  CN->zc = C->zc + CN->r * ((octant & 4) / 2 - 1);
  CN->parent = C;
  C->child[octant] = CN;
  C->nchild |= (1 << octant);
}

void split_cell(float *x, float *y, float *z, cell *C, cell *&CN) {
  for( int i=0; i<NCRIT; i++ ) {                             
    int l = C->leaf[i];
    int octant = (x[l] > C->xc) + ((y[l] > C->yc) << 1) + ((z[l] > C->zc) << 2);
    if( !(C->nchild & (1 << octant)) ) add_child(octant,C,CN);
    cell *CC = C->child[octant];
    CC->leaf[CC->nleaf++] = l;
    if( CC->nleaf >= NCRIT ) split_cell(x,y,z,CC,CN);
  } 
}

void traverse(cell *C, int &cells, int &leafs) {
  if( C->nleaf >= NCRIT ) {
    for( int c=0; c<8; c++ )
      if( C->nchild & (1 << c) ) traverse(C->child[c],cells,leafs);
  } else {
    for( int l=0; l<C->nleaf; l++ ) {
      printf("%2d %2d %2d\n",cells,leafs,C->leaf[l]);
      leafs++;
    }
    cells++;
  }
}

int main() {
  int N = 50;
  float x[N], y[N], z[N];
// Initialize
  for( int i=0; i<N; i++ ) {
    x[i] = rand() / (1. + RAND_MAX);
    y[i] = rand() / (1. + RAND_MAX);
    z[i] = rand() / (1. + RAND_MAX);
  }
// Set root cell
  cell C0[N];
  initialize(C0);
  C0->xc = C0->yc = C0->zc = C0->r = 0.5;
// Build tree
  cell *CN = C0;
  for( int i=0; i<N; i++ ) {
    cell *C = C0;
    while( C->nleaf >= NCRIT ) {
      C->nleaf++;
      int octant = (x[i] > C->xc) + ((y[i] > C->yc) << 1) + ((z[i] > C->zc) << 2);
      if( !(C->nchild & (1 << octant)) ) add_child(octant,C,CN);
      C = C->child[octant];
    }
    C->leaf[C->nleaf++] = i;
    if( C->nleaf >= NCRIT ) split_cell(x,y,z,C,CN);
  }
  int cells=0,leafs=0;
  traverse(C0,cells,leafs);
}
