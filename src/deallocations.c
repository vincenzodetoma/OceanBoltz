#include "deallocations.h"

void deallocations_c_w(point3d * c, double *w){
  free(c);
  free(w);
  printf("c's and w's deallocated.\n");
}

void deallocations_fs(double *f, double *f_eq, double *fnew){
  free(f);
  free(f_eq);
  free(fnew);
  printf("f's deallocated.\n");
}

void deallocations_u(point3d *u){
  free(u);
  printf("u's deallocated.\n");
}

void deallocations_rho(double *rho){
  free(rho);
  printf("rho deallocated.\n");
}
