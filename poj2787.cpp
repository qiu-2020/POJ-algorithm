#include <iostream>

bool isZero(double n){
    if(n < 1e-5 && n > -1e-5) return true;
    else return false;
}

float count_24(int n,double* num){
    if(n == 1){
        if(isZero(num[0] - 24)) return true;
        else return false;
    }
    else{
        double tmp[5];
        for(int i = 0;i < n - 1;i++){
            for(int j = i + 1;j < n;j++){
                int m = 0;
                for(int k = 0;k < n;k++){
                    if(k != i && k != j)
                        tmp[m++] = num[k];
                }
                tmp[m] = num[i] + num[j];
                if(count_24(n - 1,tmp)) return true;
                tmp[m] = num[i] - num[j];
                if(count_24(n - 1,tmp)) return true;
                tmp[m] = num[j] - num[i];
                if(count_24(n - 1,tmp)) return true;
                tmp[m] = num[i] * num[j];
                if(count_24(n - 1,tmp)) return true;
                if(!isZero(num[j])){
                    tmp[m] = num[i] / num[j];
                    if(count_24(n - 1,tmp)) return true;
                }
                if(!isZero(num[i])){
                    tmp[m] = num[j] / num[i];
                    if(count_24(n - 1,tmp)) return true;
                }              
            }
        }//for(int i = 0;i < n - 1;i++){
        return false;    
    }
}    

int main(){
    double num[5] = {0};
    for(int i = 0;i < 4;i++){
        std::cin>>num[i];
    }
    while(num[0] || num[1] || num[2] || num[3]){
        if(count_24(4,num))
            std::cout<<"YES"<<std::endl;
        else
            std::cout<<"NO"<<std::endl;
        for(int i = 0;i < 4;i++){
            std::cin>>num[i];
        }   
    }

    return 0;
}