#include "calc_vel_den.h"

void calc_den(){
  int v, i, j, k, idxf, idxv;
  vanish_rho();
  for (v=0;v<vel_num;v++){
    for (i=0;i<lattice_nx;i++){
      for (j=0;j<lattice_ny;j++){
	for (k=0;k<lattice_nz;k++){
	  idxf = IDXV(v,i,j,k);
	  idxv = IDX3(i,j,k);
	  rho[idxv] += f[idxf];
	}
      }
    }
  }
}

void calc_vel(){
  int v,i,j,k, idxf, idxv, sum_v;
  vanish_u();
  for (v=0;v<vel_num;v++){
    for (i=0;i<lattice_nx;i++){
      for (j=0;j<lattice_ny;j++){
	for (k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  sum_v = IDXV(v,i,j,k);
	  idxv = IDX3(i,j,k);
	  u[idxv].x += c[v].x*f[sum_v];
	  u[idxv].y += c[v].y*f[sum_v];
	  u[idxv].z += c[v].z*f[sum_v];
	}
      }
    }
  }
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxv = IDX3(i,j,k);
	u[idxv].x /= rho[idxv];
	u[idxv].y /= rho[idxv];
	u[idxv].z /= rho[idxv];
      }
    }
  }
}

void vanish_rho(){
  int i, j, k, idxv;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxv = IDX3(i,j,k);
	rho[idxv] = 0.;;
      }
    }
  }
}

void vanish_u(){
  int v,i,j,k, idxv;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxv = IDX3(i,j,k);
	u[idxv] = (point3d){0.,0.,0.};
      }
    }
  }
}
