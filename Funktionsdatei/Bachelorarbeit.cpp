#include"../Headerdatei/Bachelorarbeit.hpp"
#include<random>
#include<cmath>
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
          for (int j = 0; j <N; j++)
          {
            random = dis(random_num);
            if(random>= 0.5){
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
                
                Energy += Spin_config[i][j]*Spin_config[(i-1+N)%N][j] + 
                Spin_config[i][j]*Spin_config[(i+1+N)%N][j] +Spin_config[i][j]*Spin_config[i][(j-1+N)%N]+
                Spin_config[i][j]*Spin_config[i][(j+1+N)%N] ;
            }
        }
        return std::exp(Energy);
    }

    double Energy_sum_1D(std::vector<int>& Spin_config){
        double Energy = 0;
        int N = Spin_config.size();
        for(int i = 0 ; i<N;i++){
            Energy += Spin_config[(i+N-1)%N]*Spin_config[i] + Spin_config[(i+N+1)%N]*Spin_config[i];
        }
        return std::exp(-Energy);
    }
