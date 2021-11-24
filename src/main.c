/* The velocity set used is D3Q19 for now */
#include "main.h"

int main(int argc, char **argv){
  int t, numsteps;
  int v, i, j, k, idxf;
  int nc_id_rho, nc_id_rho_t, nc_id_u_t, nc_id_v_t, nc_id_w_t;
  double fac_f, g=-9.81, T;
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
  allocate_memory_rho();
  allocate_memory_g_force();
  allocate_memory_u();
  rho = init_rho(rho, rho_0);
  g_force = calc_g_force(rho, g);
  nc_id_rho = write_double(rho, t, "density.nc", "rho", nc_id_rho);
  u = init_u(u);
  f_eq = calc_feq(w,c,rho,u);
  f = init_fs(f, f_eq);
  printf("Initialized all.\n");
  on_off_collision=true;
  for (t=0;t<numsteps;t++){
    T = (double)i*time_step_dt;
    g_force = calc_g_force(rho, g);
    printf("%d\n", t);
    rho = calc_den(rho, f_eq);
    printf("calculated density\n");
    u = calc_vel(u, rho, c, f_eq, g_force);
    printf("calculated velocities\n");
    f_eq = calc_feq(w,c,rho,u);
    printf("calculated f_eq\n");
    char timestamp[20];
    sprintf(timestamp, "%04d", t);
    printf("%s\n", timestamp);
    char *outname_rho=concat("density.nc.", timestamp);
    char *outname_u=concat("u.nc.", timestamp);
    char *outname_v=concat("v.nc.", timestamp);
    char *outname_w=concat("w.nc.", timestamp);
    printf("%s\n", outname_rho);
    nc_id_rho_t = write_double(rho, T, outname_rho, "rho", nc_id_rho_t);
    nc_id_u_t = write_point3d(u, T, outname_u, "u", nc_id_u_t);
    nc_id_v_t = write_point3d(u, T, outname_v, "v", nc_id_v_t);
    nc_id_w_t = write_point3d(u, T, outname_w, "w", nc_id_w_t);
    free(outname_u);
    free(outname_v);
    free(outname_w);
    free(outname_rho);
    printf("writing out to disk...\n");
    fnew = collide_and_stream(f, fac_f, f_eq, c, on_off_collision);
    printf("Collision made, now propagation\n");
    for (v=0;v<vel_num;v++){
      for(i=0;i<lattice_nx;i++){
	for (j=0;j<lattice_ny;j++){
	  for (k=0;k<lattice_nz;k++){
	    idxf = IDX4(v,i,j,k);
            //printf("%d, %d, %d, %d, %lf, %lf\n", v,i,j,k,f[idxf], fnew[idxf]);
	    f[idxf] = fnew[idxf];
	  }
	}
      }
    }
    printf("Loop finished\n");
    //printf("rho at time %d:\n", t);
    //print_scal(rho);
    //printf("vel at time %d:\n", t);
    //print_vec(u);
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

