#include"../Headerdatei/Bachelorarbeit.hpp"
#include<random>
#include<vector>
#include<cmath>
#include<iostream>
#include<fstream>

int main(){
    std::random_device device; // Random Seed
    std::mt19937 engine(device()); // generate random number
    int sweep_length = 7e4;  // Number of sweeps
    int L; std::cin>>L; // System length

    std::ofstream output_file; // Store Spins
    std::ofstream output_file2; // Store Energy

    // std::vector<std::vector<std::vector<int>>> Spin_3D(L,std::vector<std::vector<int>>(L,std::vector<int>(L,1))); // 3D- Spin Lattice
   
    std::vector<double> beta={0.22123894, 0.22134819, 0.22145745, 0.2215667 , 0.22167595,
       0.22178521, 0.22189446, 0.22200371, 0.22211297, 0.22222222}; // Store value of beta
       
    output_file.open("./data/spin_3dnochgenau"+ std::to_string(L)+".txt");
    output_file2.open("./data/energy_3dnochgenau"+ std::to_string(L)+".txt");
   
    for(auto & B:beta){
     //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
    std::vector<std::vector<std::vector<int>>> Spin_3D(L,std::vector<std::vector<int>>(L,std::vector<int>(L,1)));
        double E = 0;
        E = Energy_sum_3D(Spin_3D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_3D_Sweep(Spin_3D,engine,B,E);
            if(i>=5000){
            output_file<< std::abs(mean(Spin_3D))<< " "; // calculate and store normalised spin sum
            output_file2<< E << " "; // Store Energy in sweeps/ state
            } 
            
            }
        output_file<<"\n";
        output_file2<<"\n";
   }

    output_file.close(); 
    output_file2.close(); 
    std::cout<<"Done"<<std::endl; 

   return 0;

    }

    