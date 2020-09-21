#include "init.h"
#include <math.h>

#define inv2pi 1/(2*M_PI)

void init_rho(){
  int i, j, k, idxrho;
  double r, min=0.5, max=1.;
  int seed = time(NULL);
  srand48(seed);
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxrho = IDX3(i,j,k);
	r = ((double)lrand48() / RAND_MAX)*(max - min) + min;
	rho[idxrho] = r;
	//if((k<=(int)(lattice_nz*0.5))&&(j<=(int)(lattice_ny*0.5))){
	//rho[idxrho] = 0.5*rho_0;
	//}
      }
    }
  }
  printf("Printing init rho:\n");
  print_scal(rho);
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
	//u[idxu] = (point3d){rx,ry,rz};
	u[idxu] = (point3d){0.,0.,0.};
      }
    }
  }
  printf("Printing init u:\n");
  print_vec(u);
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
	  fnew[idxf] = 0.;
	  ftemp[idxf] = 0.;
	}
      }
    }
  }
  printf("printing init f's:\n");
  print_fs(f);
}

double scal_prod (point3d a, point3d b){
  double scal = a.x*b.x + a.y*b.y + a.z*b.z;
  return scal;
}

double * calc_feq(double *w, point3d *c, double *rho, point3d* u){
  int v,i,j,k, idxf, idxv;
  double inv_cs2 = 1/sq_cs, inv_cs4 = pow(inv_cs2, 2);
  for (v=0;v<vel_num;v++){
    for (i=0;i<lattice_nx;i++){
      for (j=0;j<lattice_ny;j++){
	for (k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  idxv = IDX3(i,j,k);
	  f_eq[idxf] = w[v]*rho[idxv]*(1
				       + ((scal_prod(u[idxv], c[v]))*inv_cs2)
				       + ((pow(scal_prod(u[idxv], c[v]),2))*inv_cs4)
				       - (scal_prod(u[idxv],u[idxv])*inv_cs2*0.5));
	}
      }
    }
  }
  return f_eq;
}
