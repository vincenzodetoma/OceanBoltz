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
  w[0] = 8./27.;
  w[1] = 2./27.;
  w[2] = 2./27.;
  w[3] = 2./27.;
  w[4] = 2./27.;
  w[5] = 2./27.;
  w[6] = 2./27.;
  w[7] = 1./54.;
  w[8] = 1./54.;
  w[9] = 1./54.;
  w[10] = 1./54.;
  w[11] = 1./54.;
  w[12] = 1./54.;
  w[13] = 1./54.;
  w[14] = 1./54.;
  w[15] = 1./54.;
  w[16] = 1./54.;
  w[17] = 1./54.;
  w[18] = 1./54.;
  w[19] = 1./216.;
  w[20] = 1./216.;
  w[21] = 1./216.;
  w[22] = 1./216.;
  w[23] = 1./216.;
  w[24] = 1./216.;
  w[25] = 1./216.;
  w[26] = 1./216.;
  c[0] = (point3d) {0.,0.,0.};
  c[1] = (point3d) {+1.,0.,0.};
  c[2] = (point3d) {-1.,0.,0.};
  c[3] = (point3d) {0.,+1.,0.};
  c[4] = (point3d) {0.,-1.,0.};
  c[5] = (point3d) {0.,0.,+1.};
  c[6] = (point3d) {0.,0.,-1.};
  c[7] = (point3d) {+1.,+1.,0.};
  c[8] = (point3d) {-1.,-1.,0.};
  c[9] = (point3d) {+1.,0.,+1.};
  c[10] = (point3d) {-1.,0.,-1.};
  c[11] = (point3d) {0.,+1.,+1.};
  c[12] = (point3d) {0.,-1.,-1.};
  c[13] = (point3d) {+1.,-1.,0.};
  c[14] = (point3d) {-1.,+1.,0.};
  c[15] = (point3d) {+1.,0.,-1.};
  c[16] = (point3d) {-1.,0.,+1.};
  c[17] = (point3d) {0.,+1.,-1.};
  c[18] = (point3d) {0.,-1.,+1.};
  c[19] = (point3d) {+1.,+1.,+1.};
  c[20] = (point3d) {-1.,-1.,-1.};
  c[21] = (point3d) {+1.,+1.,-1.};
  c[22] = (point3d) {-1.,-1.,+1.};
  c[23] = (point3d) {+1.,-1.,+1.};
  c[24] = (point3d) {-1.,+1.,-1.};
  c[25] = (point3d) {-1.,+1.,+1.};
  c[26] = (point3d) {+1.,-1.,-1.};
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
