#include "write_nc.h"
#define ERRCODE -8
#define ERR(e) {printf("Error: %s\n", nc_strerror(e)); exit(ERRCODE);}

int write_double(const double *a, const int t, const char * filename, const char * vname, int ncid){
  int xdim_id, ydim_id, zdim_id, tdim_id, varid;
  int dimids[4];
  int i, j, k, idxrho, retval;
  double data[lattice_nx][lattice_ny][lattice_nz];
  size_t start[4], count[4];
  /*Opening the nc_file*/
  if((retval=nc_create(filename, NC_CLOBBER, &ncid)))
    ERR(retval);
  /*Create dims*/
  if((retval=nc_def_dim(ncid, "t", NC_UNLIMITED, &tdim_id)))
    ERR(retval);
  if((retval=nc_def_dim(ncid, "x", lattice_nx, &xdim_id)))
    ERR(retval);
  if((retval=nc_def_dim(ncid, "y", lattice_ny, &ydim_id)))
    ERR(retval);
  if((retval=nc_def_dim(ncid, "z", lattice_nz, &zdim_id)))
    ERR(retval);
  /* Collect dimensions ids */
  dimids[0] = tdim_id;
  dimids[1] = xdim_id;
  dimids[2] = ydim_id;
  dimids[3] = zdim_id;
  count[0] = 1;
  count[1] = lattice_nx;
  count[2] = lattice_ny;
  count[3] = lattice_nz;
  start[1] = 0;
  start[2] = 0;
  start[3] = 0;
  /* define the variable */
  if((retval = nc_def_var(ncid, vname, NC_DOUBLE, 4, dimids, &varid)))
    ERR(retval);
  if ((retval = nc_enddef(ncid)))
    ERR(retval);
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
	idxrho = IDX3(i,j,k);
	data[i][j][k] = a[idxrho];
      }
    }
  }
  start[0] = 0;
  if ((retval = nc_put_vara_double(ncid, varid, start, count, &data[0][0][0])))
    ERR(retval);
  if((retval=nc_close(ncid)))
    ERR(retval);
  printf("**** SUCCESS to write file %s ****\n", filename);
  return ncid;
}

int write_point3d(const point3d *a, const int t, const char * filename, const char * vname, int ncid){
  int xdim_id, ydim_id, zdim_id, tdim_id, varid;
  int dimids[4];
  int i, j, k, idxrho, retval;
  double data[lattice_nx][lattice_ny][lattice_nz];
  size_t start[4], count[4];
  /*Opening the nc_file*/
  if((retval=nc_create(filename, NC_CLOBBER, &ncid)))
    ERR(retval);
  /*Create dims*/
  if((retval=nc_def_dim(ncid, "t", NC_UNLIMITED, &tdim_id)))
    ERR(retval);
  if((retval=nc_def_dim(ncid, "x", lattice_nx, &xdim_id)))
    ERR(retval);
  if((retval=nc_def_dim(ncid, "y", lattice_ny, &ydim_id)))
    ERR(retval);
  if((retval=nc_def_dim(ncid, "z", lattice_nz, &zdim_id)))
    ERR(retval);
  /* Collect dimensions ids */
  dimids[0] = tdim_id;
  dimids[1] = xdim_id;
  dimids[2] = ydim_id;
  dimids[3] = zdim_id;
  count[0] = 1;
  count[1] = lattice_nx;
  count[2] = lattice_ny;
  count[3] = lattice_nz;
  start[1] = 0;
  start[2] = 0;
  start[3] = 0;
  /* define the variable */
  if((retval = nc_def_var(ncid, vname, NC_DOUBLE, 4, dimids, &varid)))
    ERR(retval);
  if ((retval = nc_enddef(ncid)))
    ERR(retval);
  for (i=0;i<lattice_nx;i++){
    for (j=0;j<lattice_ny;j++){
      for (k=0;k<lattice_nz;k++){
        idxrho = IDX3(i,j,k);
        if (vname=="u") {
          data[i][j][k] = a[idxrho].x;
        } else if (vname=="v") {
          data[i][j][k] = a[idxrho].y;
        } else if (vname=="w") {
          data[i][j][k] = a[idxrho].z;
        }
      }
    }
  }
  start[0] = 0;
  if ((retval = nc_put_vara_double(ncid, varid, start, count, &data[0][0][0])))
    ERR(retval);
  if((retval=nc_close(ncid)))
    ERR(retval);
  printf("**** SUCCESS to write file %s ****\n", filename);
  return ncid;
}

