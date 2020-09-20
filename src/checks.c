#include "checks.h"

void check_initparams(){
  printf("initial values are: \n lattice_nx= %d,\n lattice_ny= %d,\n lattice_nz= %d,\n vel_num= %d,\n time_step_dt= %lf,\n time_end= %lf,\n kin_vis= %lf,\n const_den= %lf,\n",
	 lattice_nx, lattice_ny, lattice_nz, vel_num, time_step_dt, time_end, kin_vis, const_den);
}

void check_symmetry() {
    int i, j, k;
    double sum_w, sum_wcc_xx, sum_wcc_xy;
    point3d sum_wc;
    printf("Printing w's:\n");
    print_w(w);
    printf("Printing c's:\n");
    print_cs(c);
    sum_w=0;
    sum_wc=(point3d){0., 0., 0.};
    sum_wcc_xx=0.;
    sum_wcc_xy=0.;
    for (i=0;i<vel_num;i++){
      sum_w += w[i];
      sum_wc.x += w[i]*c[i].x;
      sum_wc.y += w[i]*c[i].y;
      sum_wc.z += w[i]*c[i].z;
      sum_wcc_xx += w[i]*c[i].x*c[i].x;
      sum_wcc_xy += w[i]*c[i].x*c[i].y;
    }
    printf("checking w's sum, wc's sum, and wcc along xx and xy: %lf, %lf, %lf, %lf, %lf, %lf\n",
	   sum_w, sum_wc.x, sum_wc.y, sum_wc.z, sum_wcc_xx, sum_wcc_xy);
    sq_cs = sum_wcc_xx;
}

void check_data_sizes(){
  printf("Find boring? Still you have sizeof(double): %ld\n", sizeof(double));
}
