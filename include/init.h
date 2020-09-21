#ifndef init_h
#define init_h
#include "main.h"

void init_rho();
void init_u();
void init_fs();
double scal_prod(point3d, point3d);
double * calc_feq(double *, point3d *, double *, point3d *);

#endif
