#include "prints.h"

void print_scal(const double *scal){
  int i,j,k, idx3d;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idx3d = IDX3(i,j,k);
	printf("array[%d][%d][%d] = %lf\n", i,j,k,scal[idx3d]);
      }
    }
  }
}

void print_vec(const point3d *u){
  int i,j,k, idx3d;
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idx3d = IDX3(i,j,k);
	printf("array[%d][%d][%d] = (%lf, %lf, %lf)\n", i,j,k,
	       u[idx3d].x,u[idx3d].y,u[idx3d].z);
      }
    }
  }
}

void print_fs(const double *p){
  int v,i,j,k,idxf;
  for (v=0;v<vel_num;v++){
    for (i=0;i<lattice_nx;i++){
      for (j=0;j<lattice_ny;j++){
	for (k=0;k<lattice_nz;k++){
	  idxf = IDX4(v,i,j,k);
	  printf("array[%d][%d][%d][%d] = %lf\n", v,i,j,k, p[idxf]);
	}
      }
    }
  }
}

void print_cs(const point3d *a){
  int i;
  for (i=0; i<vel_num;i++){
    printf("array[%d] = (%lf, %lf, %lf)\n", i, a[i].x, a[i].y, a[i].z);
  }
}

void print_w(const double *d){
  int i;
  for (i=0;i<vel_num;i++){
    printf("array[%d] = %lf\n", i, d[i]);
  }
}

char* concat(const char *s1, const char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1); // +1 to copy the null-terminator
    return result;
}

