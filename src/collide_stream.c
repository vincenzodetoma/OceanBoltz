#include "collide_stream.h"
#include <math.h>

double * collide_and_stream(const double *f_old, const double fac, const double *f_equil, const point3d *ci, bool collis){
  int v, i, j, k, idxf, idxt, ix, iy, iz, idxv;
  point3d next;
  double to_add;
  double *f_new = allocate_double(f_new, vel_num*lattice_nx*lattice_ny*lattice_nz);
  for(i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
        for (v=0;v<vel_num;v++){
	  idxf = IDX4(v,i,j,k);
          idxv = IDX3(i,j,k);
	  next = (point3d) {i*ci[v].x, j*ci[v].y, k*ci[v].z};
	  if(collis==true){
	    to_add = f_old[idxf] - fac * (f_old[idxf] - f_equil[idxf]) + (1 - fac*0.5/time_step_dt)*g_force[idxv];
	  } else {
            printf("I'm streaming..\n");
	    to_add = f_old[idxf];
	  }
	  ix = (i + lattice_nx) % lattice_nx;
	  iy = (j + lattice_ny) % lattice_ny;
	  iz = (k + lattice_nz) % lattice_nz;
	  idxt = IDXT(v,ix,iy,iz);
	  f_new[idxt] += to_add;
	}
      }
    }
  }
  return f_new;
}
