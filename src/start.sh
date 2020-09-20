#!/bin/bash
current_dir=$PWD
echo "Working in directory: " ${current_dir}
cd ${current_dir}
make clean
make 
./OceanBoltz
