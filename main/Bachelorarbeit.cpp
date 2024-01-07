#include"../Headerdatei/Bachelorarbeit.hpp"
#include<random>
#include<vector>
#include<cmath>
#include<iostream>
#include<fstream>

int main(){
    size_t seed = 184469551615;
    std::mt19937 engine(seed); //engine
    int sweep_length = 7000; 
    int L = 10 ; 
    std::ofstream output_file;
    std::ofstream output_file2;
    /*
    std::ofstream output_file;  output_file.open("./data/Spin3D_L10.txt");
    std::ofstream output_file2; output_file2.open("./data/Energy3D_L10.txt");

    for(double B = 0.1;B <=5;B +=0.005){
    std::vector<std::vector<std::vector<int>>> Spin_3D(L,std::vector<std::vector<int>>(L,std::vector<int>(L,1)));
        double E = 0;
        E = Energy_sum_3D(Spin_3D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_3D_Sweep(Spin_3D,engine,B,E);
            if(i>=3000){
            output_file<< std::abs(mean(Spin_3D))<< " ";
            output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        output_file2<<"\n";
   }

    output_file.close(); 
    output_file2.close(); 
    std::cout<<"Done"<<std::endl; 

     L = 20 ;

    output_file.open("./data/Spin3D_L20.txt");
    output_file2.open("./data/Energy3D_L20.txt");

    for(double B = 0.1;B <=5;B +=0.005){
    std::vector<std::vector<std::vector<int>>> Spin_3D(L,std::vector<std::vector<int>>(L,std::vector<int>(L,1)));
        double E = 0;
        E = Energy_sum_3D(Spin_3D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_3D_Sweep(Spin_3D,engine,B,E);
            if(i>=3000){
            output_file<< std::abs(mean(Spin_3D))<< " ";
            output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        output_file2<<"\n";
   }

    output_file.close(); 
    output_file2.close(); 
    std::cout<<"Done"<<std::endl;

     L = 30 ;

    output_file.open("./data/Spin3D_L30.txt");
    output_file2.open("./data/Energy3D_L30.txt");

    for(double B = 0.1;B <=5;B +=0.005){
    std::vector<std::vector<std::vector<int>>> Spin_3D(L,std::vector<std::vector<int>>(L,std::vector<int>(L,1)));
        double E = 0;
        E = Energy_sum_3D(Spin_3D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_3D_Sweep(Spin_3D,engine,B,E);
            if(i>=3000){
            output_file<< std::abs(mean(Spin_3D))<< " ";
            output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        output_file2<<"\n";
   }

    output_file.close(); 
    output_file2.close(); 
    std::cout<<"Done"<<std::endl;

     L = 40 ;

    output_file.open("./data/Spin3D_L40.txt");
    output_file2.open("./data/Energy3D_L40.txt");

    for(double B = 0.1;B <=5;B +=0.005){
    std::vector<std::vector<std::vector<int>>> Spin_3D(L,std::vector<std::vector<int>>(L,std::vector<int>(L,1)));
        double E = 0;
        E = Energy_sum_3D(Spin_3D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_3D_Sweep(Spin_3D,engine,B,E);
            if(i>=3000){
            output_file<< std::abs(mean(Spin_3D))<< " ";
            output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        output_file2<<"\n";
   }

    output_file.close(); 
    output_file2.close(); 
    std::cout<<"Done"<<std::endl; 

     L = 50 ;

    output_file.open("./data/Spin3D_L50.txt");
    output_file2.open("./data/Energy3D_L50.txt");

    for(double B = 0.1;B <=5;B +=0.005){
    std::vector<std::vector<std::vector<int>>> Spin_3D(L,std::vector<std::vector<int>>(L,std::vector<int>(L,1)));
        double E = 0;
        E = Energy_sum_3D(Spin_3D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_3D_Sweep(Spin_3D,engine,B,E);
            if(i>=3000){
            output_file<< std::abs(mean(Spin_3D))<< " ";
            output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        output_file2<<"\n";
   }

    output_file.close(); 
    output_file2.close(); 
    std::cout<<"Done"<<std::endl; 
    */

     L = 60 ;

    output_file.open("./data/Spin3D_L60.txt");
    output_file2.open("./data/Energy3D_L60.txt");

    for(double B = 0.1;B <=5;B +=0.005){
    std::vector<std::vector<std::vector<int>>> Spin_3D(L,std::vector<std::vector<int>>(L,std::vector<int>(L,1)));
        double E = 0;
        E = Energy_sum_3D(Spin_3D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_3D_Sweep(Spin_3D,engine,B,E);
            if(i>=3000){
            output_file<< std::abs(mean(Spin_3D))<< " ";
            output_file2<< E << " ";
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

    