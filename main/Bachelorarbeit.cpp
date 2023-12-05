#include"../Headerdatei/Bachelorarbeit.hpp"
#include<random>
#include<vector>
#include<cmath>
#include<iostream>
#include<fstream>
#include<iterator>


int main(){
    int seed = 123121;
    int L = 40 ; // L is length of lattice
    int sweep_length = 5000;
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));

    std::vector<double> Energy;
    std::vector<double> Spin_avg;
    
    std::ofstream output_file;
    output_file.open("./build/simulation7.txt");
    //random_2D_Spin(Spin_2D,seed+121,L);
    std::mt19937 engine(seed); //engine
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
    double var=0;
    for(double B = 0.2;B <=2;B +=0.05){
        
        //double B = 0.42;
        for(int i = 0;i<sweep_length;i++){ 

            Ising_2D_Sweep(Spin_2D,engine,B);
            if(i>2000){
            //Energy.push_back(Energy_sum_2D(Spin_2D));
            Spin_avg.push_back(std::abs(vector_2D_sum(Spin_2D))); 
            }
            //output_file<<Energy_sum_2D(Spin_2D)<< " " << vector_2D_sum(Spin_2D)<<std::endl;
            }

     
        //var = variance_1D_vektor(Energy);
        var = var*B*B;
        output_file<<1/B<<" "<<var<<" "<<mean_1D_vektor(Spin_avg)<<std::endl;
       Energy.clear(); 
       Spin_avg.clear();
    }
    
    output_file.close(); 
    std::cout<<"Done"<<std::endl;   //




    

    return 0;


    }

    