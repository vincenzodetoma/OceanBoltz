/* The velocity set used is D3Q19 for now */
#include "main.h"

int main(int argc, char **argv){
  int i, j, k, q;
  check_data_sizes();
  read_params();
  check_initparams();
  allocate_memory();
  check_symmetry();
  init_rho();
  printf("I'm here in main.\n");
  deallocations();
  return EXIT_SUCCESS;
}
