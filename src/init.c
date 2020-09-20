#include "init.h"
#include <math.h>

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
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxu = IDX3(i,j,k);
	u[idxu] = (point3d){0.,0.,0.};
	printf("u[%d][%d][%d] = (%lf,%lf, %lf) \t\n", i,j,k, u[idxu].x, u[idxu].y, u[idxu].z);
      }
    }
  }
}

void init_fs(){
  int v,i,j,k, idxf;
  calc_feq();
  for (v=0;v<vel_num;v++){
    for (i=0;i<lattice_nx;i++){
      for (j=0;j<lattice_ny;j++){
	for (k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  printf("f[%d][%d][%d][%d] = %lf\n", v,i,j,k, f[idxf]);
	}
      }
    }
  }
}

double scal_prod (point3d a, point3d b){
  double scal = a.x*b.x + a.y*b.y + a.z*b.z;
  return scal;
}

void calc_feq(){
  int v,i,j,k, idxf, idxv;
  for (v=0;v<vel_num;v++){
    for (i=0;i<lattice_nx;i++){
      for (j=0;j<lattice_ny;j++){
	for (k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  idxv = IDX3(i,j,k);
	  f[idxf] = w[v]*rho[idxv]*(1
				    + ((scal_prod(u[idxv], c[v])))/sq_cs
				    + ((pow(scal_prod(u[idxv], c[v]),2))/(pow(sq_cs,2)))
				    - ((scal_prod(u[idxv],u[idxv])/(2*sq_cs))));
	}
      }
    }
  }
}

void print_scal(double *scal){
  int i,j,k, idx3d;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idx3d = IDX3(i,j,k);
	printf("array[%d][%d][%d] = %lf\n", i,j,k,scal[idx3d]);
      }
    }
  }
}

void print_vec(point3d *u){
  int i,j,k, idx3d;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idx3d = IDX3(i,j,k);
	printf("array[%d][%d][%d] = (%lf, %lf, %lf)\n", i,j,k,
	       u[idx3d].x,u[idx3d].y,u[idx3d].z);
      }
    }
  }
}
