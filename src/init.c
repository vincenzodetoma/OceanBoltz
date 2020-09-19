#include "init.h"

void init_rho(){
  int i, j, k;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	rho[i][j][k] = 1.;
	printf("%d, %d, %d\n", i,j,k);
      }
    }
  }
}
