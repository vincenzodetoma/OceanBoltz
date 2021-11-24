#include "collide_stream.h"
#include <math.h>

double * collide_and_stream(const double *f, const double fac, const double *f_eq, const point3d *c, bool coll){
  int v, i, j, k, idxf, idxt, ix, iy, iz, idxv;
  point3d next;
  double to_add;
  double *fnew = allocate_double(fnew, vel_num*lattice_nx*lattice_ny*lattice_nz);
  for(i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
        for (v=0;v<vel_num;v++){
	  idxf = IDX4(v,i,j,k);
          idxv = IDX3(i,j,k);
	  next = (point3d) {i*c[v].x, j*c[v].y, k*c[v].z};
	  if(coll==true){
	    to_add = f[idxf] - fac * (f[idxf] - f_eq[idxf]) + (1 - fac * 0.5)*w[v]*((c[v].z*g_force[idxv])/sq_cs + (c[v].z*scal_prod(c[v], u[idxv])*g_force[idxv] - sq_cs * u[idxv].z*g_force[idxv])) / (pow(sq_cs,2));
	  } else {
            printf("I'm streaming..\n");
	    to_add = f[idxf];
	  }
	  ix = (i + lattice_nx) % lattice_nx;
	  iy = (j + lattice_ny) % lattice_ny;
	  iz = (k + lattice_nz) % lattice_nz;
	  idxt = IDXT(v,ix,iy,iz);
	  fnew[idxt] += to_add;
	}
      }
    }
  }
  return fnew;
}
