#!/usr/bin
mpic++ -fopenmp -O3 main.cpp
time mpirun -np 4 ./a.out
