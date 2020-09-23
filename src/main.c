/* The velocity set used is D3Q19 for now */
#include "main.h"

int main(int argc, char **argv){
  int t, numsteps;
  int i, j, k, q;
  int nc_id_rho, nc_id_rho_t;
  double fac_f;
  bool on_off_collision;
  check_data_sizes();
  read_params();
  check_initparams();
  allocate_memory_c_w();
  check_symmetry(c, w);
  tau = kin_vis/sq_cs + 2. / time_step_dt;
  fac_f = time_step_dt/tau;
  numsteps = (int)(time_end / time_step_dt);
  printf("Tau is equal to: %lf, number of steps: %d\n", tau, numsteps);
  allocate_memory_fs(f, f_eq, fnew);
  allocate_memory_rho(rho);
  allocate_memory_u(u);
  init_rho(rho, rho_0);
  nc_id_rho = write_double(rho, t, "density.nc", "rho", nc_id_rho);
  init_u(u);
  f_eq = calc_feq(w,c,rho,u);
  init_fs(f, fnew, f_eq);
  on_off_collision=false;
  collide_and_stream(fnew, f, fac_f, f_eq, c, on_off_collision);
  //on_off_collision=true;
  for (t=0;t<numsteps;t++){
    calc_vel(u, rho, c, f);
    calc_den(rho, f);
    f_eq = calc_feq(w,c,rho,u);
    collide_and_stream(fnew, f, fac_f, f_eq, c, on_off_collision);
    swap(f, fnew);
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
  deallocations_c_w(c,w);
  deallocations_fs(f, f_eq, fnew);
  deallocations_rho(rho);
  deallocations_u(u);
  printf("Program ended.\n");
  return EXIT_SUCCESS;
}
