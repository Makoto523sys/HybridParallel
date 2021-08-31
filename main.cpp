#include<iostream>
#include<cmath>
#include<omp.h>

double f(double);
const long int N = 1e9;

int main(int argc, char **argv){
    int rank, size, host_rank=0;
    double sum, ans;
    double a, b;
    a = 0.0; b = 1.0;
    double dx = (b-a) / N;
    sum = 0.0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int begin = N / size * rank;
    int end = N / size * (rank + 1);
    //std::cout << begin << " " << end << std::endl;


#pragma omp parallel for reduction(+:sum)
    for(int i = begin; i < end; i++){
        sum += dx * f(dx * i);
    }
    //std::cout << std::abs(M_PI - sum) << std::endl;
    MPI_Reduce(&sum, &ans, 1, MPI_DOUBLE, MPI_SUM, host_rank, MPI_COMM_WORLD);
    if(rank == host_rank) std::cout << std::abs(M_PI / 8 - ans) << std::endl;
    MPI_Finalize();
    return 0;
}

double f(double x){
    return x * std::asin(x);
}
