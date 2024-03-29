#ifndef gvars_h
#define gvars_h
#include "main.h"

/* domain variables: spatial params */
int lattice_nx, lattice_ny, lattice_nz, vel_num;
/* domain variables: temporal params */
double time_step_dt, time_end;
/* constants of the simulation */
double kin_vis, rho_0, tau;

double sq_cs;

struct Point3d {
  double x;
  double y;
  double z;
};

typedef struct Point3d point3d;

double *w, *f, *rho, *f_eq, *fnew, *g_force;
point3d *c, *u;

#endif
