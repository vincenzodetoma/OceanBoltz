#include "deallocations.h"

void deallocations_c_w(){
  free(c);
  free(w);
  printf("c's and w's deallocated.\n");
}

void deallocations_fs(){
  free(f);
  printf("f's deallocated.\n");
}

void deallocations_u(){
  free(u);
  printf("u's deallocated.\n");
}

void deallocations_rho(){
  free(rho);
  printf("rho deallocated.\n");
}
