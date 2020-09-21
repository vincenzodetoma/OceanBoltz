#include "collide_stream.h"

void collide(){
  int v,i,j,k, idxf;
  for(v=0;v<vel_num;v++){
    for(i=0;i<lattice_nx;i++){
      for (j=0;j<lattice_ny;j++){
	for (k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  f[idxf] -= (time_step_dt / tau) * (f[idxf] - f_eq[idxf]);
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
	  if(idxt < vel_num*lattice_nx*lattice_ny*lattice_nz){
	    f[idxt] = f[idxf];
	  } else {
	    f[idxt - vel_num*lattice_nx*lattice_ny * lattice_nz] = f[idxf];
	  }
	}
      }
    }
  }
}
