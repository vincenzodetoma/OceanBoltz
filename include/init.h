#ifndef init_h
#define init_h
#include "main.h"

double * init_rho(double *,const double);
point3d * init_u(point3d *);
double *init_fs(double *, const double *);
double scal_prod(point3d, point3d);
double * calc_feq(const double *, const point3d *, const double *, const point3d *);
double * calc_g_force(double *, const double);
#endif
