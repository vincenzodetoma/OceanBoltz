#ifndef calc_vel_den_h
#define calc_vel_den_h

#include "main.h"

double * calc_den(double *, const double *);
point3d * calc_vel(point3d *, const double *, const point3d *, const double *, const double *);
double * vanish_scalar(double *);
point3d * vanish_u(point3d *);
#endif
