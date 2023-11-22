#include"../Headerdatei/Bachelorarbeit.hpp"
#include<random>
#include<vector>
#include<cmath>
#include<iostream>
#include<fstream>
#include<iterator>

int main(){
    int seed = 214;
    int len = 100000;

    /* std::vector<double> random_number;
    random_number_generator(random_number,seed,len);

    std::ofstream output_file("./build/random_num_list.txt");

    std::ostream_iterator<double> output_iterator(output_file, "\n");
    std::copy(random_number.begin(), random_number.end(), output_iterator);
    std::cout<<"done\n";
    return 0;
    */

    int L = 5;
    int N = L*L;

    

    std::vector<std::vector<int>> all_possible_spin; // all possible spin configuration in 1D-array
    std::vector<int> current_spin_config(N,0);
    spin_configuration(N,all_possible_spin,current_spin_config,0);
    std::vector<std::vector<std::vector<int>>>      // Line 32 to 
    all_possible_spin_matrix(all_possible_spin.size(), //
    std::vector<std::vector<int>>(L,std::vector<int>(L,0))); // 34 is a one line.

    for(int i = 0;i<all_possible_spin.size();i++ ){
        int l = 0;
        for(int j = 0 ; j<L;j++){
            for(int k = 0 ; k<L;k++){
                all_possible_spin_matrix[i][j][k] = all_possible_spin[i][l++];
            }
        }
    }

    std::ofstream output_file;
    output_file.open("./build/Boltzman_verteilung_5x5_Mat.txt");
    for( int m = 0; m<all_possible_spin_matrix.size();m++){
       output_file<<Energy_sum(all_possible_spin_matrix[m])<<std::endl;
    }
    output_file.close();
    

    return 0;

    


}