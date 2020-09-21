#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdlib.h>
#include "my_reads.h"
#include "gvars.h"
#include "allocations.h"
#include "deallocations.h"
#include "checks.h"
#include "init.h"
#include "calc_vel_den.h"
#include "prints.h"
#include "collide_stream.h"
#include "time.h"

#define IDX4(v,i,j,k) (v*lattice_nx*lattice_ny*lattice_nz + i*lattice_ny*lattice_nz + j*lattice_nz + k)
#define IDX3(i,j,k) (i*lattice_ny*lattice_nz + j*lattice_nz + k)
#define IDXV(v,i,j,k) (v*lattice_nx*lattice_ny*lattice_nz)
#define IDXT(v,i,j,k) (v*lattice_nx*lattice_ny*lattice_nz + (i + (int)c[v].x*time_step_dt)*lattice_ny*lattice_nz + (j + (int)(c[v].y))*lattice_nz + (k + (int)c[v].z*time_step_dt))

#endif
