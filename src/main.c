#include "main.h"

int main(int argc, char **argv){
  int i, j, k;
  read_params();
  printf("initial values are: \n lattice_nx= %d,\n lattice_ny= %d,\n lattice_nz= %d,\n time_step_dt= %lf,\n time_end= %lf,\n kin_vis= %lf,\n const_den= %lf,\n",
	 lattice_nx, lattice_ny, lattice_nz, time_step_dt, time_end, kin_vis, const_den);
  allocate_memory();
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz; k++){
	printf("f[%d][%d][%d] = (%lf, %lf, %lf)\n",
	       i, j, k, f[i][j][k].x, f[i][j][k].y, f[i][j][k].z);
      }
    }
  }
  deallocations();
  return EXIT_SUCCESS;
}
