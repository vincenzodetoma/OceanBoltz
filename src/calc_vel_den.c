#include "calc_vel_den.h"

void calc_den(){
  int v, i, j, k;
  for (v=0;v<vel_num;v++){
    for (i=0;i<lattice_nx;i++){
      for (j=0;j<lattice_ny;j++){
	for (k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  idxv = IDX3(i,j,k);
	  rho[idxv] += f[idxf];
	}
      }
    }
  }
}

void calc_vel(){
  int v,i,j,k;
    for (v=0;v<vel_num;v++){
    for (i=0;i<lattice_nx;i++){
      for (j=0;j<lattice_ny;j++){
	for (k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  idxv = IDX3(i,j,k);
	  u[idxv].x += c[v].x*f[idxf];
	  u[idxv].y += c[v].y*f[idxf];
	  u[idxv].z += c[v].z*f[idxf];
	}
      }
    }
  }
}