#pragma once
#include<vector>
void random_number_generator(std::vector<double> &random_number,const int & seed, const int & len);
void random_1D_Spin(std::vector<int>& Spin_1D, const int& seed,const int & N);
void random_2D_Spin(std::vector<std::vector<int>>& Spin_2D, const int& seed);
void spin_configuration(const int & N, std::vector<std::vector<int>>& Spin_config, std::vector<int>& current_spin,const int& index);
double Energy_sum_2D(const std::vector<std::vector<int>>& Spin_config); // take 2D-Vector and compute energy
double Energy_sum_1D(std::vector<int>& Spin_config); // take 2D-Vector and compute energy