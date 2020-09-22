#include "allocations.h"

point3d * allocate_point3d(point3d * a, int a_dim){
  if((a = (point3d *)malloc(a_dim*sizeof(point3d)))==NULL){
      printf("Malloc to a point3d * failed.\n");
      exit(EXIT_FAILURE);
    }
  return a;
}

double * allocate_double(double *a, int a_dim){
  if((a= (double *)malloc(a_dim*sizeof(double)))==NULL){
    printf("Malloc to a double * failed.\n");
    exit(EXIT_FAILURE);
  }
  return a;
}
void allocate_memory_c_w() {
  int i, j, k;
  printf("I'm allocating the c's.\n");
  /* Allocation of the c's */
  c = allocate_point3d(c, vel_num);
  printf("I'm allocating the w's.\n");
  /* Allocation of the w's */
  w = allocate_double(w, vel_num);
  /* Definition of c's and w's */
  for (i=0;i<vel_num;i++)
    c[i] = (point3d){0.,0.,0.};
  for (i=0; i<vel_num; i++){
    if(i<7){
      w[i] = 1./18.;
    } else {
      w[i] = 1./36.;
    };
    if(i==1||i==7||i==9||i==13||i==15){
      c[i].x = +1;
      c[i+1].x = -1.;
    }
    if (i==3||i==7||i==11||i==14||i==17){
      c[i].y = 1.;
      if (i!=12)
	c[i+1].y= -1.;
      else
	c[i-1].y= -1;
    }
    if (i==5||i==9||i==11||i==16||i==18){
      c[i].z = 1.;
      if(i!=16 && i!=18)
	c[i+1].z = -1.;
      else
	c[i-1].z = -1.;
    }
  }
  w[0] = 1./3.;
}

void allocate_memory_fs(){
  int dim_f = vel_num*lattice_nx*lattice_ny*lattice_nz;
  printf("I'm allocating the f's.\n");
  /* Allocation of the f's*/
  f = allocate_double(f, dim_f);
  printf("I'm allocating the f_eq's.\n");
  f_eq = allocate_double(f_eq, dim_f);
  printf("I'm allocating the fnew's.\n");
  fnew = allocate_double(f_eq, dim_f);
  printf("I'm allocating the ftemp's.\n");
  ftemp = allocate_double(ftemp, dim_f);
}

void allocate_memory_rho(){
  int dim_3 = lattice_nx*lattice_ny*lattice_nz;
  printf("I'm allocating the rho.\n");
  rho = allocate_double(rho, dim_3);
}

void allocate_memory_u(){
  int dim_3 = lattice_nx*lattice_ny*lattice_nz;
  printf("I'm allocating the u's.\n");
  u = allocate_point3d(u, dim_3);
}
