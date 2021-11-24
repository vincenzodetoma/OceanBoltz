#!/bin/bash
current_dir=$PWD
echo "Working in directory: " ${current_dir}
cd ${current_dir}
make clean
make 
./OceanBoltz
cdo mergetime density.nc.* density_t.nc
cdo mergetime u.nc.* u_t.nc
cdo mergetime v.nc.* v_t.nc
cdo mergetime w.nc.* w_t.nc
cdo merge density_t.nc u_t.nc v_t.nc w_t.nc output.nc
rm -rf *.nc.* density_t.nc u_t.nc v_t.nc w_t.nc
