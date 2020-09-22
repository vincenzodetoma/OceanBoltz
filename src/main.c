/* The velocity set used is D3Q19 for now */
#include "main.h"

int main(int argc, char **argv){
  int t, numsteps;
  int i, j, k, q;
  int nc_id_rho, nc_id_rho_t;
  check_data_sizes();
  read_params();
  check_initparams();
  allocate_memory_c_w();
  check_symmetry();
  tau = kin_vis/sq_cs + 2. / time_step_dt;
  numsteps = (int)(time_end / time_step_dt);
  printf("Tau is equal to: %lf, number of steps: %d\n", tau, numsteps);
  allocate_memory_fs();
  allocate_memory_rho();
  allocate_memory_u();
  init_rho();
  nc_id_rho = write_double(rho, t, "density.nc", "rho", nc_id_rho);
  init_u();
  f_eq = calc_feq(w,c,rho,u);
  init_fs(f_eq);
  for (t=0;t<numsteps;t++){
    calc_vel();
    calc_den();
    f_eq = calc_feq(w,c,rho,u);
    collide();
    stream();
    swap();
    nc_id_rho_t = write_double(rho, t, "density_t.nc", "rho", nc_id_rho_t);
    printf("rho at time %d:\n", t);
    print_scal(rho);
    printf("vel at time %d:\n", t);
    print_vec(u);
  }
  //printf("Printing rho calculated from initial f's:\n");
  //print_scal(rho);
  //printf("Printing u's calculated from inital f's:\n");
  //print_vec(u);
  deallocations_c_w();
  deallocations_fs();
  deallocations_rho();
  deallocations_u();
  printf("Program ended.\n");
  return EXIT_SUCCESS;
}
