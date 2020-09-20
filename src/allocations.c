#include "allocations.h"

void allocate_memory_c_w() {
  int i, j, k;
  printf("I'm allocating the c's and w's\n");
  /* Allocation of the c's */
  if((c = (point3d*)malloc(vel_num*sizeof(point3d)))==NULL){
    printf("Malloc of c's failed\n");
    exit(EXIT_FAILURE);
  }
  /* Allocation of the w's */
  if((w = (double*)malloc(vel_num*sizeof(double)))==NULL) {
    printf("Calloc of w's failed\n");
    exit(EXIT_FAILURE);
  }
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
  printf("I'm allocating the f's.\n");
  /* Allocation of the f's*/ 
  if((f = (double*)malloc(vel_num*lattice_nx*lattice_ny*lattice_nz*sizeof(double)))==NULL){
    printf("Calloc of f's failed.\n");
    exit(EXIT_FAILURE);
  }
}

void allocate_memory_rho(){
  if((rho = (double *)malloc(lattice_nx*lattice_ny*lattice_nz*sizeof(double)))==NULL){
    printf("Allocation of rho failed.\n");
    exit(EXIT_FAILURE);
  }
}

void allocate_memory_u(){
  if((u=(point3d *)malloc(lattice_nx*lattice_ny*lattice_nz*sizeof(point3d *)))==NULL){
    printf("Allocation of velocities failed.\n");
    exit(EXIT_FAILURE);
  }
}
