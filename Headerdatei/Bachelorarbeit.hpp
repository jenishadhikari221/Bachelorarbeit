#pragma once
#include<vector>
void random_number_generator(std::vector<double> &random_number,const int & seed, const int & len);
void random_1D_Spin(std::vector<int>& Spin_1D, const int& seed,const int & N);
void random_2D_Spin(std::vector<std::vector<int>>& Spin_2D, const int& seed,const int& N);
void spin_configuration(const int & N, std::vector<std::vector<int>>& Spin_config, std::vector<int>& current_spin,const int& index);
double Energy_sum_2D(const std::vector<std::vector<int>>& Spin_config); // take 2D-Vector and compute energy
double Energy_sum_1D(std::vector<int>& Spin_config); // take 2D-Vector and compute energy
int delta_E_1D(const std::vector<int>& Spin_1D,const int & i);
int delta_E_2D(const std::vector<std::vector<int>>& Spin_2D,const int & i, const int & j);
void Ising_1D_Sweep(std::vector<int> & Spin_1D,std::vector<double>& Energy,std::vector<int>& Spin_total,const int & seed,const int & L,const double & B = 1.0);
int vector_1D_sum(const std::vector<int>& Spin_1D);
void Ising_2D_Sweep(std::vector<std::vector<int>>& Spin_2D,std::vector<double>& Energy,std::vector<int>& Spin_total,const int & seed,const int & L,const double & B,const bool& namimate);
void Ising_2D_Sweep(std::vector<std::vector<int>>& Spin_2D,std::vector<double>& Energy,std::vector<int>& Spin_total,const int & seed,const int & L,const double & B );
int vector_2D_sum(const std::vector<std::vector<int>> & Spin_2D,std::vector<float> & z);
int vector_2D_sum(const std::vector<std::vector<int>> & Spin_2D); // ueberladen
