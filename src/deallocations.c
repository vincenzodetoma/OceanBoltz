#include "deallocations.h"

void deallocations(){
  int i, j, k, l;
  free(c);
  free(w);
  printf("I'm here in dealloc.\n");
  for(i=0; i<lattice_nx; i++){
    for(j=0; j<lattice_ny; j++){
      for (k=0;k<lattice_nz;k++){
	printf("%d, %d, %d\n", i,j,k);
	free(f[i][j][k]);
      }
      free(f[i][j]);
    }
    free(f[i]);
  }
  free(f);
  for(i=0;i<lattice_nx;i++){
    for(j=0;j<lattice_ny;j++){
      free(rho[i][j]);
    }
    free(rho[i]);
  }
  free(rho);
}
