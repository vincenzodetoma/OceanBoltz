#include "deallocations.h"

void deallocations(){
  int i, j, k, l;
  free(c);
  free(w);
  printf("I'm here in dealloc.\n");
  for(i=0; i<vel_num; i++){
    for(j=0; j<lattice_nx; j++){
      for (k=0;k<lattice_ny;k++){
	printf("%d, %d, %d\n", i,j,k);
	free(f[i][j][k]);
      }
      free(f[i][j]);
    }
    free(f[i]);
  }
  free(f);
}
