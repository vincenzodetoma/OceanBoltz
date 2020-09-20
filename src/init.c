#include "init.h"

void init_rho(){
  int i, j, k, idxrho;
  rho_0=1;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxrho = IDX3(i,j,k);
	rho[idxrho] = rho_0;
	printf("rho[%d][%d][%d] = %lf\n", i,j,k,rho[idxrho]);
      }
    }
  }
}

void init_u(){
  int i, j, k, idxu;
  rho_0=1;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxu = IDX3(i,j,k);
	u[idxu] = (point3d){0.,0.,0.};
	printf("u[%d][%d][%d].x = (%lf,%lf, %lf) \t\n", i,j,k,u[idxu].x, u[idxu].y, u[idxu].z);
      }
    }
  }
}

void init_fs(){

}
