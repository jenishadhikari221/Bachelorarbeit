#include"../Headerdatei/Bachelorarbeit.hpp"
#include<random>
#include<vector>
#include<cmath>
#include<iostream>
#include<fstream>

int main(){
    int seed = 123121;
    std::mt19937 engine(seed); //engine

    int L = 20 ; // L is length of lattice
    int sweep_length = 70000;
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,0));
    //random_2D_Spin(Spin_2D,engine,L);
    std::vector<double> Energy;
    std::vector<double> Spin_avg;  

    std::ofstream output_file;
    output_file.open("./build/simulation27.txt");
    double var=0;    
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
   //for(double B = 0.2;B <=2;B +=0.05){
        double E = 0;
        E = Energy_sum_2D(Spin_2D);

        double B = 0.5;
        for(int i = 0;i<sweep_length;i++){ 

            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=10000){
            //Energy.push_back(E);
            Spin_avg.push_back(std::abs(mean(Spin_2D))); 
            }
            // output_file<<mean(Spin_avg)<<"\n";
            }
        /*
        output_file<<1/B<<" "<<binder_cumulant(Spin_avg) <<std::endl;
        Spin_avg.clear(); 
 
   }  */  

        Energy = data_blocking(Spin_avg,1000);
        for(auto & in :Energy){
            output_file<<in<<'\n';
        }
            
        /*
        double autocorr_spin = autocorr(Spin_avg,0);
        //double autocorr_Energy = autocorrelation(Energy,0);
        double spin_corr;
        double energy_corr;
        

        for(int i =0; i<Spin_avg.size()-1;i++){
            Energy.push_back(Spin_avg[i]);
            spin_corr = autocorr(Spin_avg,i);           
            output_file<<spin_corr/autocorr_spin<<" "<<Spin_avg[i]<<" "<<mean(Energy)<<std::endl;

        }
     
        var = variance(Energy);
        var = var*B*B;
        output_file<<1/B<<" "<<var<<" "<<mean(Spin_avg)<<std::endl;
        Energy.clear(); 
       Spin_avg.clear(); 
   } //*/
    
    
    output_file.close(); 
    std::cout<<"Done"<<std::endl;   




    

    return 0;


    }

    