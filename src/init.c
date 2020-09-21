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
      }
    }
  }
  //printf("Printing init rho:\n");
  //print_scal(rho);
}

void init_u(){
  int i, j, k, idxu;
  double rx, ry, rz;
  int seed = time(NULL);
  srand48(seed);
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxu = IDX3(i,j,k);
	rx = (double)lrand48() / RAND_MAX;
	ry = (double)lrand48() / RAND_MAX;
	rz = (double)lrand48() / RAND_MAX;
	u[idxu] = (point3d){rx,ry,rz};
      }
    }
  }
  //printf("Printing init u:\n");
  //print_vec(u);
}

void init_fs(){
  int v,i,j,k, idxf;
  f_eq = calc_feq(w,c,rho,u);
  for(v=0;v<vel_num;v++){
    for(i=0;i<lattice_nx;i++){
      for(j=0;j<lattice_ny;j++){
	for(k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  f[idxf] = f_eq[idxf];
	}
      }
    }
  }
  //printf("printing init f's:\n");
  //print_fs(f);
}

double scal_prod (point3d a, point3d b){
  double scal = a.x*b.x + a.y*b.y + a.z*b.z;
  return scal;
}

double * calc_feq(double *w, point3d *c, double *rho, point3d* u){
  int v,i,j,k, idxf, idxv;
  for (v=0;v<vel_num;v++){
    for (i=0;i<lattice_nx;i++){
      for (j=0;j<lattice_ny;j++){
	for (k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  idxv = IDX3(i,j,k);
	  f_eq[idxf] = 0.;
	  f_eq[idxf] = w[v]*rho[idxv]*(1
				    + ((scal_prod(u[idxv], c[v])))/sq_cs
				    + ((pow(scal_prod(u[idxv], c[v]),2))/(pow(sq_cs,2)))
				    - ((scal_prod(u[idxv],u[idxv])/(2*sq_cs))));
	}
      }
    }
  }
  return f_eq;
}
