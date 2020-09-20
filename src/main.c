/* The velocity set used is D3Q19 for now */
#include "main.h"

int main(int argc, char **argv){
  int i, j, k, q;
  check_data_sizes();
  read_params();
  check_initparams();
  allocate_memory_c_w();
  check_symmetry();
  allocate_memory_fs();
  allocate_memory_rho();
  allocate_memory_u();
  init_rho();
  init_u();
  deallocations_c_w();
  deallocations_fs();
  deallocations_rho();
  deallocations_u();
  return EXIT_SUCCESS;
}
