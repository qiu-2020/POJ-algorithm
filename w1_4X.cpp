#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

void SetBit(char& c,int i,int v){
    if(v) c |= (1 << i);
    else c &= ~(1 << i);
}
int GetBit(char c,int i){
    return (c >> i) & 1;
}
void Flip(char& c,int i){
    c ^= (1 << i);
}

void Print(char* c){
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 6;j++){
            std::cout<<GetBit(c[i],j)<<' ';
        }
        std::cout<<std::endl;
    }
}

int main(){
    char oriLight[5];
    char lights[5];
    char result[5];
    char switchs;
    int T;
//    std::cin>>T;
//    for(int t = 1;t <= T;t++){
        memset(oriLight,0,sizeof(oriLight));
        for(int i = 0;i < 5;i++){
            for(int j = 0;j < 6;j++){
                int bit;
                std::cin>>bit;
                SetBit(oriLight[i],(char)j,bit);
            }
        }
        for(int i = 0;i < 64;i++){ //表示第一行按下那些灯
            memcpy(lights,oriLight,sizeof(oriLight));
            switchs = i;
            for(int j = 0;j < 5;j++){//依次按下每一行
                result[j] = switchs;
                for(int k = 0;k < 6;k++){//每一行的每
                    if(GetBit(switchs,k)){
                        Flip(lights[j],k);
                        if(k < 5) Flip(lights[j],k + 1);
                        if(k > 0) Flip(lights[j],k - 1);
                    }
                }
                if(j < 4)
                    lights[j + 1] ^= switchs;
                switchs = lights[j];
            }
            if(lights[4] == 0){
                Print(result);
                break;
            }
        }
//    }




    return 0;
}