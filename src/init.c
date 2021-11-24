#include "init.h"
#include <math.h>

#define twopi 2*M_PI

double * init_rho(double *rho, const double rho_0){
  int i, j, k, idxrho;
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
  return rho;
}

point3d * init_u(point3d *u){
  int seed;
  int i, j, k, idxu;
  double rx, ry, rz;
  seed = time(NULL);
  srand48(seed);
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxu = IDX3(i,j,k);
	rx = (double) lrand48() / RAND_MAX;
	ry = (double) lrand48() / RAND_MAX;
	rz = (double) lrand48() / RAND_MAX;
	//u[idxu] = (point3d){rx,ry,rz};
	u[idxu] = (point3d){0.,0.,0.};
      }
    }
  }
  //printf("Printing init u:\n");
  //print_vec(u);
  return u;
}

double * init_fs(double *f, const double *init){
  int v,i,j,k, idxf;
  printf("printing init f's:\n");
  for(v=0;v<vel_num;v++){
    for(i=0;i<lattice_nx;i++){
      for(j=0;j<lattice_ny;j++){
	for(k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  f[idxf] = init[idxf];
	}
      }
    }
  }
  //print_fs(f);
  return f;
}

double scal_prod (point3d a, point3d b){
  double scal = a.x*b.x + a.y*b.y + a.z*b.z;
  return scal;
}

double * calc_feq(const double *w, const point3d *c, const double *rho, const point3d* u){
  int v,i,j,k, idxf, idxv;
  double to_add;
  double inv_cs2 = 1/sq_cs, inv_cs4 = pow(inv_cs2, 2);
  double *to_return = allocate_double(to_return, vel_num*lattice_nx*lattice_ny*lattice_nz);
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	for (v=0;v<vel_num;v++){
	  idxf = IDX4(v,i,j,k);
	  idxv = IDX3(i,j,k);
	  to_add = w[v]*rho[idxv]*(1
				   + ((scal_prod(u[idxv], c[v]))*inv_cs2)
				   + ((pow(scal_prod(u[idxv], c[v]),2))*inv_cs4*0.5)
				   - (scal_prod(u[idxv],u[idxv])*inv_cs2*0.5));
	  to_return[idxf] = to_add;
	}
      }
    }
  }
  return to_return;
}
