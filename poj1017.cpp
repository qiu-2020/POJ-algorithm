#include <iostream>


int main(){
    int K1,K2,K3,K4,K5,K6;
    std::cin>>K1>>K2>>K3>>K4>>K5>>K6;
    //39 5 101 1 1 1 #31
    //38 5 101 1 1 1 #29
    while(K1 || K2 || K3 || K4 || K5 || K6){
        int count = 0;
        count += K6; count += K5; count += K4; count += K3 / 4;
        if(K3 % 4) count += 1;
        int space_1,space_2;
        space_1 = K5 * (36 - 25) + K4 * (20);
        if(K3 % 4) space_1 += 9 * (4 - (K3 % 4));
        space_2 = K4 * 5;
        if(K3 % 4 == 1) space_2 += 5;
        else if(K3 % 4 == 2) space_2 += 3;
        else if(K3 % 4 == 3) space_2 += 1;

        if(space_2 >= K2){
            space_2 -= K2;
            space_1 -= K2 * 4;
        }
        else{
            K2 -= space_2;
            space_1 -= space_2 * 4;
            count += K2 / 9;
            if(K2 % 9){
                count++;
                space_1 += 4 * (9 - (K2 % 9));
            }
        }
        if(space_1 < K1){
            K1 -= space_1;
            count += K1 / 36;
            if(K1 % 36) count++;
        }
        std::cout<<count<<std::endl;
        std::cin>>K1>>K2>>K3>>K4>>K5>>K6;
    }



    return 0;
}