#include"../Headerdatei/Bachelorarbeit.hpp"
#include<random>
#include<vector>
#include<cmath>
#include<iostream>
#include<fstream>

int main(){
    size_t seed = 184469551615;
    std::mt19937 engine(seed); //engine
    int sweep_length = 20000; 
    int L = 10 ; // L is length of lattice
    //std::vector<double> Energy;
    //std::vector<double> Spin_avg;
    //std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,0));
    //random_2D_Spin(Spin_2D,engine,L);

    std::ofstream output_file;  output_file.open("./data/Spin_nearTc_L10.txt");
    std::ofstream output_file2; output_file2.open("./data/Energy_nearTc_L10.txt");
    std::vector<double> Beta = {0.4385 , 0.43864, 0.43879, 0.43893, 0.43907, 0.43921, 0.43936,
       0.4395 , 0.43964, 0.43979, 0.43993, 0.44007, 0.44021, 0.44036,
       0.4405};
    for( double & B : Beta){
    //for(double B = 0.2;B <=2;B +=0.05){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=2000){
            output_file<< std::abs(mean(Spin_2D))<< " ";
            output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        output_file2<<"\n";
   }

    output_file.close(); 
    output_file2.close(); 
    std::cout<<"Done"<<std::endl; 

     L = 20 ; // L is length of lattice
     

    output_file.open("./data/Spin_nearTc_L20.txt");
    output_file2.open("./data/Energy_nearTc_L20.txt");
        
    for( double & B : Beta){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=2000){
            output_file<< std::abs(mean(Spin_2D))<< " ";
            output_file2<< E<< " ";
            }
            
            }
        output_file<<"\n";
        output_file2<<"\n";
   }

    output_file.close(); 
    output_file2.close(); 
    std::cout<<"Done"<<std::endl; 
     L = 30 ; 

     output_file.open("./data/Spin_nearTc_L30.txt");
     output_file2.open("./data/Energy_nearTc_L30.txt");
    for( double & B : Beta){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=2000){
            output_file<< std::abs(mean(Spin_2D))<< " ";
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

     output_file.open("./data/Spin_nearTc_L40.txt");
     output_file2.open("./data/Energy_nearTc_L40.txt");
        
    for( double & B : Beta){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=2000){
            output_file<< std::abs(mean(Spin_2D))<< " ";
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

     output_file.open("./data/Spin_nearTc_L50.txt");
     output_file2.open("./data/Energy_nearTc_L50.txt");

    for( double & B : Beta){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=2000){
            output_file<< std::abs(mean(Spin_2D))<< " ";
            output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        output_file2<<"\n";
   }

    output_file.close(); 
    output_file2.close(); 
    std::cout<<"Done"<<std::endl; 

     L = 60 ; 
     output_file.open("./data/Spin_nearTc_L60.txt");
     output_file2.open("./data/Energy_nearTc_L60.txt");
        
    for( double & B : Beta){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=2000){
            output_file<< std::abs(mean(Spin_2D))<< " ";
            output_file2<< E << " ";
            }
            
            }
        output_file<<"\n";
        output_file2<<"\n";
   }

    output_file.close(); 
    output_file2.close(); 
    std::cout<<"Done"<<std::endl; 

    
    L = 100 ; 

    output_file.open("./data/Spin_nearTc_L100.txt");
    output_file2.open("./data/Energy_nearTc_L100.txt");
    for( double & B : Beta){
    std::vector<std::vector<int>> Spin_2D(L,std::vector<int>(L,1));
        double E = 0;
        E = Energy_sum_2D(Spin_2D);
        output_file<< B << " ";
        output_file2<< B << " ";
        //double B = 0.44;
        for(int i = 0;i<sweep_length;i++){
            Ising_2D_Sweep(Spin_2D,engine,B,E);
            if(i>=2000){
            output_file<< std::abs(mean(Spin_2D))<< " ";
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

    