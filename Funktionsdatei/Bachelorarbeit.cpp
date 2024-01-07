#include"../Headerdatei/Bachelorarbeit.hpp"
#include<random>

void random_number_generator(std::vector<double> &random_number,std::mt19937 & engine, const int & len){
    std::uniform_real_distribution<> dis(0, 1); // distribute uniformly in interval 0 and 1
    for(int i = 0; i<=len;i++){
        random_number.push_back(dis(engine)); // creat array of uniformly dis. random number
    }

}

void random_2D_Spin(std::vector<std::vector<int>>& Spin_2D,std::mt19937 & engine,const int & N){
    std::uniform_real_distribution<> dis(0, 1);
     for (int i = 0; i <N; i++) 
     {
          for (int j = 0; j<N; j++)
          {
            if(dis(engine)>= 0.5){
                Spin_2D[i][j] = 1;
            }
            else{
                Spin_2D[i][j] = -1;
            }
               
          }
     }
}

void random_3D_Spin(std::vector<std::vector<std::vector<int>>> & Spin_3D,std::mt19937 & engine,const int & N){
    std::uniform_real_distribution<> dis(0, 1);
     for (int i = 0; i <N; i++) 
     {
          for (int j = 0; j<N; j++)
          {
            for(int k = 0; k< N;k++){
                if(dis(engine)>= 0.5){
                Spin_3D[i][j][k] = 1;
            }
               else{
                Spin_3D[i][j][k] = -1;
            }
            }
               
          }
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
        return -0.5*Energy;
    }

double Energy_sum_3D(const std::vector<std::vector<std::vector<int>>> & Spin_3D){
        double Energy = 0;
        int N = Spin_3D.size();
        for(int i = 0 ; i<N;i++){
            for(int j = 0 ; j <N;j++){
                for( int k = 0; k<N ; k++){
                     Energy += 
                     Spin_3D[i][j][k]*(Spin_3D[(i-1+N)%N][j][k] 
                     + Spin_3D[(i+1+N)%N][j][k] + 
                     Spin_3D[i][(j-1+N)%N][k]+ 
                     Spin_3D[i][(j+1+N)%N][k]+
                     Spin_3D[i][j][(k+1+N)%N]+
                     Spin_3D[i][j][(k-1+N)%N]);

                }
            }
        }
        return -0.5*Energy;
    }

int delta_E_2D(const std::vector<std::vector<int>>& Spin_2D,const int & i,const int & j){
    int N = Spin_2D.size();
    int dE;
    dE = Spin_2D[i][j]*(Spin_2D[i][(j-1+N)%N]+Spin_2D[(i+1+N)%N][j]+Spin_2D[i][(j+1)%N]+Spin_2D[(i-1+N)%N][j]);
    return 2*dE;
}

int delta_E_3D(const std::vector<std::vector<std::vector<int>>> & Spin_3D,const int & i,const int & j,const int & k){
    int N = Spin_3D.size();
    int dE;
    dE = Spin_3D[i][j][k]*(Spin_3D[(i-1+N)%N][j][k] 
            + Spin_3D[(i+1+N)%N][j][k] + 
            Spin_3D[i][(j-1+N)%N][k]+ 
            Spin_3D[i][(j+1+N)%N][k]+
            Spin_3D[i][j][(k+1+N)%N]+
            Spin_3D[i][j][(k-1+N)%N]);
    return 2*dE;
}

int sum_vec(const std::vector<int>& Spin_1D){
    int sum = 0;
    for(const int &s :Spin_1D){
        sum +=s;
    }
    return sum;
}

double sum_vec(const std::vector<double>& Spin_1D){
    double sum = 0;
    for(const double &s :Spin_1D){
        sum +=s;
    }
    return sum;
}

double mean(const std::vector<double>& data){
    double S = 0;
    int N = data.size();
    for(const double & in :data ){
        S +=in;
    }
    return (double) S/N;
}
double mean(const std::vector<int>& data){
    int S = 0;
    int N = data.size();
    for(const int & in :data ){
        S +=in;
    }
    return (double) S/N;
}

double mean(const std::vector<std::vector<int>> & data){
    int sum = 0;
    int N = data.size();
    
    for(const auto & spin: data){
        for(const int & in :spin){
            sum += in;
        }
    }
    N = N*N;
    return (double) sum/N;
}

double mean(const std::vector<std::vector<std::vector<int>>> & data){
    int sum = 0;
    int N = data.size();
    
    for(const auto & spin: data){
        for(const auto & array :spin){
            for(const int & in : array){
                sum += in;
            }
        }
    }
    N = N*N*N;
    return (double) sum/N;
}

double meansquare(const std::vector<double>& data){
    double S = 0.0;
    int N = data.size();
    for(const double & in:data){
        S +=in*in;
    }
    return  (double) S/N;
}

double variance(const std::vector<double>& data){
    double var;
    double temp = mean(data);
    var = meansquare(data) - temp*temp;
    return var;

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

void Ising_2D_Sweep(std::vector<std::vector<int>>& Spin_2D,std::mt19937 &engine,const double & B,double& E){
    int N = Spin_2D.size();
    std::uniform_real_distribution<double> real_dis(0.,1.);
    int dE;
    
    for(int i =0;i<N;i++){
        for(int j = 0;j<N;j++){            
        dE = delta_E_2D(Spin_2D,i,j);
        if(dE<=0 || real_dis(engine)<std::exp(-B*dE))
        {
            Spin_2D[i][j] *= -1;
            E +=dE;
            } 
        }
        

    }
    
}

void Ising_3D_Sweep(std::vector<std::vector<std::vector<int>>> & Spin_3D,std::mt19937 &engine,const double & B,double& E){
    int N = Spin_3D.size();
    std::uniform_real_distribution<double> real_dis(0.,1.);
    int dE;
    
    for(int i =0;i<N;i++){
        for(int j = 0;j<N;j++){ 
            for(int k = 0;k<N;k++){           
                dE = delta_E_3D(Spin_3D,i,j,k);
                if(dE<=0 || real_dis(engine)<std::exp(-B*dE))
                {
                    Spin_3D[i][j][k] *= -1;
                    E +=dE;
                    } 
                }
        

        }   
    
    }
}

double autocorr(const std::vector<double> & data,const int & t){
    double m = mean(data);
    double sum2 =0;
    int indx = 0;    

    for(;indx<data.size()-t;indx++){
        sum2 += (data[indx]-m)*(data[indx+t]-m);
    }
    return (double) sum2;

}

double binder_cumulant(const std::vector<double> & data){
    double mean_sq = meansquare(data);
    int N = data.size();
    double fourth_mean = 0.0;
    for(const double & in:data){
        fourth_mean += pow(in,4);
    }
    fourth_mean = fourth_mean/N;
    return (double) 1-fourth_mean/(3*mean_sq*mean_sq);
}

std::vector<double> bootstrap(const std::vector<double> & data,std::mt19937 & enigne){
    int N = data.size();
    std::uniform_int_distribution<int> distrib(0,N-1);
    std::vector<double> result;
    int num_bootstrap = 1000;
    
    for(int i=0;i<=num_bootstrap;i++){
        int j = 0;
        double bootstrap_data = 0;
        for(;j<N;j++){
            bootstrap_data += data[distrib(enigne)];
        }
        result.push_back(bootstrap_data/j);
    }
    return result;
}

std::vector<double> data_blocking(const std::vector<double> & data,const int & block_length){
    int N = data.size();
    int l = N/block_length;
    std::vector<double> blocked_data;
    
    for(int i=1;i<=l;i++){
        double x_i = 0;
        for(int j = 1; j<=block_length;j++){
            x_i += data[(i-1)*block_length + j];
        }
        blocked_data.push_back(x_i/block_length);
    }
    return blocked_data;

}






