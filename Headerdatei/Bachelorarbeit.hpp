#pragma once
#include<vector>
#include<random>
void random_number_generator(std::vector<double> &random_number,std::mt19937 & engine, const int & len);
void random_2D_Spin(std::vector<std::vector<int>>& Spin_2D,std::mt19937 & engine,const int & N);
void random_3D_Spin(std::vector<std::vector<std::vector<int>>> & Spin_3D,std::mt19937 & engine,const int & N);
double Energy_sum_2D(const std::vector<std::vector<int>>& Spin_config);
double Energy_sum_3D(const std::vector<std::vector<std::vector<int>>> & Spin_3D);
int delta_E_2D(const std::vector<std::vector<int>>& Spin_2D,const int & i,const int & j);
int delta_E_3D(const std::vector<std::vector<std::vector<int>>> & Spin_3D,const int & i,const int & j,const int & k);
int sum_vec(const std::vector<int>& Spin_1D);
double sum_vec(const std::vector<double>& Spin_1D);
double mean(const std::vector<double>& data);
double mean(const std::vector<int>& data);
double mean(const std::vector<std::vector<int>> & data);
double mean(const std::vector<std::vector<std::vector<int>>> & data);
double meansquare(const std::vector<double>& data);
double variance(const std::vector<double>& data);
void Ising_2D_Sweep(std::vector<std::vector<int>>& Spin_2D,std::mt19937 &engine,const double & B,double& E);
void Ising_3D_Sweep(std::vector<std::vector<std::vector<int>>> & Spin_3D,std::mt19937 &engine,const double & B,double& E);
double autocorr(const std::vector<double> & data,const int & t);
int vector_2D_sum(const std::vector<std::vector<int>> & Spin_2D,std::vector<float> & z);
double binder_cumulant(const std::vector<double> & data);
std::vector<double> bootstrap(const std::vector<double> & data,std::mt19937 & enigne);
std::vector<double> data_blocking(const std::vector<double> & data,const int & block_length);
