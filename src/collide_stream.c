#include "collide_stream.h"

void collide(){
  int v, i, j, k, idxf, idxt;
  for (v=0;v<vel_num;v++){
    for(i=0;i<lattice_nx;i++){
      for (j=0;j<lattice_ny;j++){
	for (k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  ftemp[idxf] = f[idxf] - (time_step_dt / tau) * (f[idxf] - f_eq[idxf]);
	}
      }
    }
  }
}

void stream(){
  int v, i, j, k, idxf, idxt;
  for (v=0;v<vel_num;v++){
    for(i=0;i<lattice_nx;i++){
      for (j=0;j<lattice_ny;j++){
	for (k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  idxt = IDXT(v,i,j,k);
	  fnew[idxt] = ftemp[idxf];
	}
      }
    }
  }
}

void swap(){
  int v, i, j, k, idxf, idxt;
  for (v=0;v<vel_num;v++){
    for(i=0;i<lattice_nx;i++){
      for (j=0;j<lattice_ny;j++){
	for (k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  fnew[idxf] = f[idxf];
	}
      }
    }
  }	  
}
