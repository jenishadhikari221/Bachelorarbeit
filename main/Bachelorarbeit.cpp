#include"../Headerdatei/Bachelorarbeit.hpp"
#include"../Headerdatei/matplotlibcpp.h"
#include<random>
#include<vector>
#include<cmath>
#include<iostream>
#include<fstream>
#include<iterator>

namespace plt = matplotlibcpp;

int main(){
    int seed = 1221221;
    //int len = 10000;

    /* //This portion is to generate random number and plot

    std::vector<double> random_number;
    random_number_generator(random_number,seed,len);

    std::ofstream output_file("./build/random_num_list.txt");

    std::ostream_iterator<double> output_iterator(output_file, "\n");
    std::copy(random_number.begin(), random_number.end(), output_iterator);
    std::cout<<"done\n";
    return 0;
    

    
    /* /int N = L*L; // N represent area of lattice, or total number of spin-system

    
      // This portion is to calculate exact Energy of 2D-Spin configuration
      int L = 4;
      int N = L*L;
    std::vector<std::vector<int>> all_possible_spin; // all possible spin configuration will be saved  in 1D-array
    std::vector<int> current_spin_config(N,0);
    spin_configuration(N,all_possible_spin,current_spin_config,0); // all_possible_spin will get 2^N spin configuration
    std::vector<std::vector<std::vector<int>>>      // Frro here 
    all_possible_spin_matrix(all_possible_spin.size(), //
    std::vector<std::vector<int>>(L,std::vector<int>(L,0))); // to here is a one line code

    for(int i = 0;i<all_possible_spin.size();i++ ){ // take 1D Spin array amd make 2D-Spin Matrix.
        int l = 0;
        for(int j = 0 ; j<L;j++){
            for(int k = 0 ; k<L;k++){
                all_possible_spin_matrix[i][j][k] = all_possible_spin[i][l++];
            }
        }
    }

    std::ofstream output_file;
    output_file.open("./build/Boltzman_verteilung_4x4_Mat.txt");
    for( int m = 0; m<all_possible_spin_matrix.size();m++){
       output_file<<Energy_sum_2D(all_possible_spin_matrix[m])<<std::endl;
    }
    output_file.close(); 

    /* 1D Ising Sweep
    int sweep_length = 10000;

    std::vector<int> Spin_1D;
    std::vector<double> Energy;
    std::vector<int> Spin_total;
    random_1D_Spin(Spin_1D,seed,L);
    Ising_1D_Sweep(Spin_1D,Energy,Spin_total,seed,sweep_length);

    std::ofstream output_file;
    output_file.open("./build/Energy.txt");
    for( int m = 0; m<Energy.size();m++){
       output_file<<Energy[m]<<" "<< Spin_total[m]<<std::endl;
    }
    output_file.close();  */

     //  2D Ising Sweep
    int L = 50; // L is length of lattice
    int sweep_length = 1000000;
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,0));
    std::vector<double> Energy;
    std::vector<int> Spin_total;
    std::vector<double> avg_spin;
    std::vector<double> avg_energy;
    std::vector<double> temperature;

    double spin_avg;
    random_2D_Spin(Spin_2D,seed,L);
   
    
    for(double B = 0.1;B <=2;B +=0.05){

        Ising_2D_Sweep(Spin_2D,Energy,Spin_total,seed,sweep_length,B);
        std::vector<int> temp(Spin_total.end()-3000,Spin_total.end());

        spin_avg = vector_1D_sum(temp);
        spin_avg = double(spin_avg)/(L*L*temp.size());
        
        avg_spin.push_back(spin_avg);
        temperature.push_back(B); 
                
        Spin_total.clear(); Energy.clear();
    }
    
    

    std::ofstream output_file;
    output_file.open("./build/firstsimulation.txt");
    for( int m = 0; m<avg_spin.size();m++){
       output_file<<temperature[m]<<" "<< avg_spin[m]<<std::endl;
    }
    output_file.close();  
    std::cout<<"Done"<<std::endl;    // */




    

    return 0;

    


}