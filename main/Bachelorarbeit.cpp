#include"../Headerdatei/Bachelorarbeit.hpp"
#include<random>
#include<vector>
#include<cmath>
#include<iostream>
#include<fstream>
#include<iterator>


int main(){
    int seed = 1211;
    //std::mt19937 random_num(seed); // take a seed and generate random number // take random_num as an argu.

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
    int L = 5; // L is length of lattice
    int sweep_length = 5000;
    int A = 0;
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,0));
  
    //int N =0;

    std::vector<double> Energy;
    std::vector<double> Spin_avg;
    random_2D_Spin(Spin_2D,seed+121,L);
    std::ofstream output_file;
    
    output_file.open("./build/autocorrelation9.txt");


    /*
        for(int i = 0;i<sweep_length;i++){       

            Ising_2D_Sweep(Spin_2D,A,seed+i,0.41,E);
            
            output_file<< E<<std::endl; 

        }
    */
   
    
    for(double B = 0.2;B <=4;B +=0.05){
        double var=0;
        double var2=0;

        double E = 0;

     for(int i = 0;i<sweep_length;i++){  
        Ising_2D_Sweep(Spin_2D,A,seed+(i*2+1)*(B*100),B,E);
        if(i>1000)
        {

            Energy.push_back(Energy_sum_2D(Spin_2D));
            Spin_avg.push_back(vector_2D_sum(Spin_2D));
        }
        
    }
        var = variance_1D_vektor(Energy);
        var2 = variance_1D_vektor2(Energy);
        var = var*B*B;
        var2 = var2*B*B;

        output_file<<1/B<<" "<< mean_1D_vektor(Spin_avg)<<" "<<var<<" "<< var2<<std::endl;

    }
    
    
    
    
    
    output_file.close();  
    std::cout<<"Done"<<std::endl;   //  */




    

    return 0;

    


}