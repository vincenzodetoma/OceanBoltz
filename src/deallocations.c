#include "deallocations.h"

void deallocations_c_w(){
  free(c);
  free(w);
  printf("c's and w's deallocated.\n");
}

void deallocations_fs(){
  int i, j, k, l;
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
  printf("f's deallocated.\n");
}
