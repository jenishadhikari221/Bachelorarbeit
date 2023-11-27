#include"../Headerdatei/Bachelorarbeit.hpp"
#include"../Headerdatei/matplotlibcpp.h"
#include<random>
#include<cmath>
#include<iostream>
namespace plt = matplotlibcpp;

void random_1D_Spin(std::vector<int>& Spin_1D, const int& seed,const int & N){
    std::mt19937 random_num(seed); 
    std::uniform_real_distribution<> dis(0, 1);
    double random;
        for (int j = 0; j <N; j++)
        {
            random = dis(random_num);
            if(random>= 0.5){
                Spin_1D.push_back(1);
            }
            else{
                Spin_1D.push_back(-1);
            }
               
          }

}

void random_2D_Spin(std::vector<std::vector<int>>& Spin_2D, const int& seed,const int & N)
{
    std::mt19937 random_num(seed); 
    std::uniform_real_distribution<> dis(0, 1);
    double random;
     
     for (int i = 0; i <N; i++)
     {
          for (int j = 0; j<N; j++)
          {
            random = dis(random_num);
            if(random>= 0.25){
                Spin_2D[i][j] = 1;
            }
            else{
                Spin_2D[i][j] = -1;
            }
               
          }
     }
}


void random_number_generator(std::vector<double> &random_number,const int & seed, const int & len){
    std::mt19937 random_num(seed); // take a seed and generate random number
    std::uniform_real_distribution<> dis(0, 1); // distribute uniformly in interval 0 and 1

    for(int i = 0; i<=len;i++){
        random_number.push_back(dis(random_num)); // creat array of uniformly dis. random number
    }

}
// compute up to 3 or 4

void spin_configuration(const int & N, std::vector<std::vector<int>>& Spin_config, std::vector<int>& current_spin,const int& index){
    if(index == N){
        Spin_config.push_back(current_spin);
        return ;
        }
    for(const int & spin:{1,-1}){
        current_spin[index] = spin;
        spin_configuration(N,Spin_config,current_spin,index+1);
        }
    }

    double Energy_sum_2D(const std::vector<std::vector<int>>& Spin_config){
        double Energy = 0;
        int N = Spin_config.size();
        for(int i = 0 ; i<N;i++){
            for(int j = 0 ; j <N;j++){
                Energy += Spin_config[i][j]*(Spin_config[(i-1+N)%N][j] + Spin_config[(i+1+N)%N][j] + Spin_config[i][(j-1+N)%N]+ Spin_config[i][(j+1+N)%N]);
            }
        }
        return -1*Energy;
    }

    double Energy_sum_1D(std::vector<int>& Spin_config){
        double Energy = 0;
        int N = Spin_config.size();
        for(int i = 0 ; i<N;i++){
            Energy += Spin_config[(i+N-1)%N]*Spin_config[i] + Spin_config[(i+N+1)%N]*Spin_config[i];
        }
        return std::exp(-Energy);
    }

int delta_E_1D(const std::vector<int>& Spin_1D,const int & i){ 
    int N = Spin_1D.size();
    int dE = 2*Spin_1D[i]*(Spin_1D[(i+1+N)%N]+Spin_1D[(i-1+N)%N]);
    return dE;
}

int delta_E_2D(const std::vector<std::vector<int>>& Spin_2D,const int & i,const int & j){
    int N = Spin_2D.size();
    int dE;
    dE = 2*Spin_2D[i][j]*(Spin_2D[i][(j-1+N)%N]+Spin_2D[(i+1+N)%N][j]+Spin_2D[i][(j+1)%N]+Spin_2D[(i-1+N)%N][j]);
    return dE;
}

int vector_1D_sum(const std::vector<int>& Spin_1D){
    int sum = 0;
    for(const int s :Spin_1D){
        sum +=s;
    }
    return sum;
}
int vector_2D_sum(const std::vector<std::vector<int>> & Spin_2D){
    int sum = 0;
    int N = Spin_2D.size();
    for(auto spin:Spin_2D){
        sum +=vector_1D_sum(spin);
    }
    return sum;
}

int vector_2D_sum(const std::vector<std::vector<int>> & Spin_2D,std::vector<float> & z){
    int sum = 0;
    int N = Spin_2D.size();
    for(int i = 0;i<N;i++){
        for(int j = 0; j<N;j++){
            sum += Spin_2D[i][j];
            z.at(N*i+j) = Spin_2D[i][j];
        }
    }
    return sum;
}

void Ising_1D_Sweep(std::vector<int> & Spin_1D,std::vector<double>& Energy,std::vector<int>& Spin_total,const int & seed,const int & L,const double & B){
    int N = Spin_1D.size();
    std::mt19937 random_num(seed); // take a seed and generate random number
    std::uniform_int_distribution<> dis(0, N-1);
    std::uniform_real_distribution<> real_dis(0,1);
    int I;
    double dE;
    for(int i =0;i<L;i++){
        I = dis(random_num);
        dE = delta_E_1D(Spin_1D,I);
        if(real_dis(random_num)<std::exp(-B*dE)){
            Spin_1D[I] = -1*Spin_1D[I];
            Energy.push_back(dE);
            Spin_total.push_back(vector_1D_sum(Spin_1D));
        }

    }
}
void Ising_2D_Sweep(std::vector<std::vector<int>>& Spin_2D,std::vector<double>& Energy,std::vector<int>& Spin_total,const int & seed,const int & L,const double & B,const bool& namimate){
    int N = Spin_2D.size();
    std::mt19937 random_num(seed); // take a seed and generate random number
    std::uniform_int_distribution<> dis(0, N-1);
    std::uniform_real_distribution<> real_dis(0,1);
    std::vector<float> z(N*N);
    int I_1,I_2;
    
    double dE;
    double energy = Energy_sum_2D(Spin_2D);
    #pragma omp parallel
    for(int i =0;i<L;i++){
        I_1 = dis(random_num);
        I_2 = dis(random_num);

        dE = delta_E_2D(Spin_2D,I_1,I_2);
        if(dE<0){
            Spin_2D[I_1][I_2] = -1*Spin_2D[I_1][I_2];
            energy +=dE;
            Energy.push_back(energy);
            Spin_total.push_back(vector_2D_sum(Spin_2D,z));
        
        }
        
         else if(real_dis(random_num)<std::exp(-B*dE)){
            Spin_2D[I_1][I_2] = -1*Spin_2D[I_1][I_2];
            energy +=dE;
            Energy.push_back(energy);
            Spin_total.push_back(vector_2D_sum(Spin_2D,z));
        
        }
        int a = L/60;

        if(namimate == true && (i %a==0)){
            const float* zptr = &(z[0]);
             const int colors = 1;
            plt::clf();
            plt::imshow(zptr, N, N, colors);
            plt::pause(0.001);

        }

    }
    //plt::save("./build/finalspin.png");
}

void Ising_2D_Sweep(std::vector<std::vector<int>>& Spin_2D,std::vector<double>& Energy,std::vector<int>& Spin_total,const int & seed,const int & L,const double & B){
    int N = Spin_2D.size();
    std::mt19937 random_num(seed); // take a seed and generate random number
    std::uniform_int_distribution<> dis(0, N-1);
    std::uniform_real_distribution<> real_dis(0,1);
    int I_1,I_2;
    
    int dE;
    double energy = Energy_sum_2D(Spin_2D);
    #pragma omp parallel
    for(int i =0;i<L;i++){
        I_1 = dis(random_num);
        I_2 = dis(random_num);

        dE = delta_E_2D(Spin_2D,I_1,I_2);
        if(dE<=0){
            Spin_2D[I_1][I_2] = -1*Spin_2D[I_1][I_2];
            energy +=dE;
            Energy.push_back(energy);
            Spin_total.push_back(vector_2D_sum(Spin_2D));
        
        }
         
        else if(real_dis(random_num)<std::exp(-B*dE)){
            Spin_2D[I_1][I_2] = -1*Spin_2D[I_1][I_2];
            energy +=dE;
            Energy.push_back(energy);
            Spin_total.push_back(vector_2D_sum(Spin_2D));
        
        }

    }
}




