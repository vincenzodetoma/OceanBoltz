#include "deallocations.h"

void deallocations(){
  int i, j;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      free(f[i][j]);
    }
    free(f[i]);
  }
  free(f);
}
