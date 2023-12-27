#include"../Headerdatei/Bachelorarbeit.hpp"
#include<random>
#include<vector>
#include<cmath>
#include<iostream>
#include<fstream>

int main(){/*
    int seed = 123121;
    std::mt19937 engine(seed); //engine
    int sweep_length = 10000; 
    int L = 10 ; // L is length of lattice
    //std::vector<double> Energy;
    //std::vector<double> Spin_avg;
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,0));
    //random_2D_Spin(Spin_2D,engine,L);

     std::ofstream output_file;  output_file.open("./data/Spin_L10_nearTc.txt");
     //std::ofstream output_file2; 
     //output_file2.open("./data/Energy_L10.txt");
        
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
    for(double B = 0.423;B <=0.465;B +=0.001){
    //for(double B = 0.2;B <=2;B +=0.05){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        //output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=2000){
            output_file<< std::abs(mean(Spin_2D))<< " ";
            //output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        //output_file2<<"\n";
   }

    output_file.close(); 
    //output_file2.close(); 
    std::cout<<"Done"<<std::endl; 

     L = 20 ; // L is length of lattice
     
     
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,0));
    //random_2D_Spin(Spin_2D,engine,L);

    output_file.open("./data/Spin_L20_nearTc.txt");
    //output_file2.open("./data/Energy_L20.txt");
        
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
    for(double B = 0.423;B <=0.465;B +=0.001){
     //for(double B = 0.2;B <=2;B +=0.05){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        //output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=2000){
            output_file<< std::abs(mean(Spin_2D))<< " ";
            //output_file2<< E<< " ";
            }
            
            }
        output_file<<"\n";
        //output_file2<<"\n";
   }

    output_file.close(); 
    //output_file2.close(); 
    std::cout<<"Done"<<std::endl; 
     L = 30 ; // L is length of lattice
    
    
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,0));
    //random_2D_Spin(Spin_2D,engine,L);

     output_file.open("./data/Spin_L30_nearTc.txt");
     //output_file2.open("./data/Energy_L30.txt");
        
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
    for(double B = 0.423;B <=0.465;B +=0.001){
     //for(double B = 0.2;B <=2;B +=0.05){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        //output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=2000){
            output_file<< std::abs(mean(Spin_2D))<< " ";
            //output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        //output_file2<<"\n";
   }

    output_file.close(); 
    //output_file2.close(); 
    std::cout<<"Done"<<std::endl; 

     L = 40 ; // L is length of lattice
    
    
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,0));
    //random_2D_Spin(Spin_2D,engine,L);

     output_file.open("./data/Spin_L40_nearTc.txt");
     //output_file2.open("./data/Energy_L40.txt");
        
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
    for(double B = 0.423;B <=0.465;B +=0.001){
     //for(double B = 0.2;B <=2;B +=0.05){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        //output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=2000){
            output_file<< std::abs(mean(Spin_2D))<< " ";
            //output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        //output_file2<<"\n";
   }

    output_file.close(); 
    //output_file2.close(); 
    std::cout<<"Done"<<std::endl;

    L = 50 ; // L is length of lattice
    
    
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,0));
    //random_2D_Spin(Spin_2D,engine,L);

     output_file.open("./data/Spin_L50_nearTc.txt");
     //output_file2.open("./data/Energy_L50.txt");
        
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
    for(double B = 0.423;B <=0.465;B +=0.001){
     //for(double B = 0.2;B <=2;B +=0.05){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        //output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=2000){
            output_file<< std::abs(mean(Spin_2D))<< " ";
            //output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        //output_file2<<"\n";
   }

    output_file.close(); 
    //output_file2.close(); 
    std::cout<<"Done"<<std::endl; 

     L = 60 ; // L is length of lattice
    
    
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,0));
    //random_2D_Spin(Spin_2D,engine,L);

     output_file.open("./data/Spin_L60_nearTc.txt");
     //output_file2.open("./data/Energy_L60.txt");
        
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
    for(double B = 0.423;B <=0.465;B +=0.001){
     //for(double B = 0.2;B <=2;B +=0.05){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        //output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=2000){
            output_file<< std::abs(mean(Spin_2D))<< " ";
            //output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        //output_file2<<"\n";
   }

    output_file.close(); 
    //output_file2.close(); 
    std::cout<<"Done"<<std::endl; 

    return 0;*/

    size_t seed = 12312561;
    std::mt19937 engine(seed); //engine
    int sweep_length = 1000; 
    int L = 500 ; // L is length of lattice
    //std::vector<double> Energy;
    //std::vector<double> Spin_avg;
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,0));
    //random_2D_Spin(Spin_2D,engine,L);

     std::ofstream output_file;  output_file.open("./data/sim_lol2.txt");
     //std::ofstream output_file2; 
     //output_file2.open("./data/Energy_L10.txt");
        
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
    //for(double B = 0.423;B <=0.465;B +=0.001){
    for(double B = 0.2;B <=2;B +=0.05){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        //output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=0){
            output_file<< std::abs(mean(Spin_2D))<< " ";
            //output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        //output_file2<<"\n";
   }

    output_file.close(); 
    //output_file2.close(); 
    std::cout<<"Done"<<std::endl; 


    }

    