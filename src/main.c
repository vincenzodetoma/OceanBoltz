#include "main.h"

int main(int argc, char **argv){
  int i;
  read_params();
  printf("initial values are: \n lattice_nx= %d,\n lattice_ny= %d,\n lattice_nz= %d,\n time_step_dt= %lf,\n time_end= %lf,\n kin_vis= %lf,\n const_den= %lf,\n",
	 lattice_nx, lattice_ny, lattice_nz, time_step_dt, time_end, kin_vis, const_den);
  return EXIT_SUCCESS;
}
