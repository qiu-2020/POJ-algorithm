#include <iostream>
#include <cstdlib>
#include <cstring>

int GetBit(char& c,int i){
    return 1  & (c >> i);
}

void SetBit(char& c,int i,int v){
    if(v) c |= (1 << i);
    else c &= ~(1 << i);
}

void Flip(char& c,int i){
    c ^= (1 << i);
}

void output(char* c){
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 6;j++){
            std::cout<<GetBit(c[i],j)<<' ';
        }
        std::cout<<std::endl;
    }
}

int main(){
    char oriLight[5];
    char Lights[5];
    char result[5];
    char switchs;
    int bit;
    memset(oriLight,0,sizeof(oriLight));
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 6;j++){
            std::cin>>bit;
            SetBit(oriLight[i],j,bit);
        }
    }

    for(int i = 0;i < 64;i++){
        switchs = i;
        // for(int t = 0;t < 5;t++)
        //     Lights[t] = oriLight[t]; 
        memcpy(Lights,oriLight,sizeof(oriLight));
        for(int j = 0;j < 5;j++){
            result[j] = switchs;
            for(int k = 0;k < 6;k++){
                if(GetBit(switchs,k)){
                    Flip(Lights[j],k);
                    if(k > 0) Flip(Lights[j],k - 1);
                    if(k < 5) Flip(Lights[j],k + 1); 
                }
            }
            if(j < 4)
                Lights[j + 1] ^= switchs;
            switchs = Lights[j];    
        }
        if(Lights[4] == 0){
            output(result);
            break;
        }
    }

    return 0;
}