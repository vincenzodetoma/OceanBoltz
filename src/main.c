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
  init_fs();
  calc_den();
  calc_vel();
  printf("Printing rho calculated from initial f's:\n");
  print_scal(rho);
  printf("Printing u's calculated from inital f's:\n");
  print_vec(u);
  deallocations_c_w();
  deallocations_fs();
  deallocations_rho();
  deallocations_u();
  printf("Program ended.\n");
  return EXIT_SUCCESS;
}
