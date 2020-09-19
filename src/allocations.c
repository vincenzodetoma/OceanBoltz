#include "allocations.h"

void allocate_memory() {
  int i, j, k;
  if ((f = (point3d ***)malloc(lattice_nx * sizeof(point3d **))) == NULL) {
    printf("first allocations of the f's failed.\n");
    exit(EXIT_FAILURE);
  }
  for (i=0;i<lattice_nx;i++) {
    if ((f[i] = (point3d **)malloc(lattice_ny * sizeof(point3d *)))==NULL){
      printf("second allocations of the f's failed.\n");
      exit(EXIT_FAILURE);
    }
    for (j=0;j<lattice_nz;j++) {
      if((f[i][j] = (point3d *)malloc(lattice_nz*sizeof(point3d)))==NULL){
	printf("third allocations of f's failed.\n");
	exit(EXIT_FAILURE);
      }
    }
  }
  //Initialize the field to zero
  for (i=0; i<lattice_nx; i++){
    for (j=0; j<lattice_ny; j++){
      for (k=0; k<lattice_nz; k++) {
	f[i][j][k].x = 0;
	f[i][j][k].y = 0;
	f[i][j][k].z = 0;
      }
    }
  }
}
