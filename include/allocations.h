#ifndef allocations_h
#define allocations_h
#include "main.h"

point3d * allocate_point3d(point3d *, int);
double * allocate_double(double *, int);
void allocate_memory_c_w();
void allocate_memory_fs();
void allocate_memory_rho();
void allocate_memory_u();

#endif
