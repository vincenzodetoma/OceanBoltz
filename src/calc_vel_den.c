#include "calc_vel_den.h"

double * calc_den(double *r, const double *fdist){
  int v, i, j, k, idxf, idxv;
  r = vanish_scalar(r);
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){	
        for (v=0;v<vel_num;v++){
	  idxf = IDX4(v,i,j,k);
	  idxv = IDX3(i,j,k);
	  r[idxv] += fdist[idxf];
	}
      }
    }
  }
  return r;
}

point3d * calc_vel(point3d *V, const double *r, const point3d *cis, const double *fdist, const double *force){
  int v,i,j,k, idxf, idxv;
  V = vanish_vector(V);
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
        for (v=0;v<vel_num;v++){
	  idxf = IDX4(v,i,j,k);
	  idxv = IDX3(i,j,k);
	  V[idxv].x += cis[v].x*fdist[idxf];
	  V[idxv].y += cis[v].y*fdist[idxf];
	  V[idxv].z += (cis[v].z*fdist[idxf] + force[idxv]*time_step_dt*0.5);
	}
      }
    }
  }
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxv = IDX3(i,j,k);
	V[idxv].x /= r[idxv];
	V[idxv].y /= r[idxv];
	V[idxv].z /= r[idxv];
      }
    }
  }
  return V;
}

double * vanish_scalar(double *s){
  int i, j, k, idxv;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxv = IDX3(i,j,k);
	s[idxv] = 0.;
      }
    }
  }
  return s;
}

point3d * vanish_vector(point3d *c){
  int v,i,j,k, idxv;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxv = IDX3(i,j,k);
	c[idxv] = (point3d){0.,0.,0.};
      }
    }
  }
  return c;
}
