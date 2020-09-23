#include "calc_vel_den.h"

double * calc_den(double *rho, const double *f){
  int v, i, j, k, idxf, idxv;
  rho = vanish_rho(rho);
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
  return rho;
}

point3d * calc_vel(point3d *u, const double *rho, const point3d *c, const double *f){
  int v,i,j,k, idxf, idxv;
  u = vanish_u(u);
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
  return u;
}

double * vanish_rho(double *rho){
  int i, j, k, idxv;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxv = IDX3(i,j,k);
	rho[idxv] = 0.;
      }
    }
  }
  return rho;
}

point3d * vanish_u(point3d *u){
  int v,i,j,k, idxv;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxv = IDX3(i,j,k);
	u[idxv] = (point3d){0.,0.,0.};
      }
    }
  }
  return u;
}
