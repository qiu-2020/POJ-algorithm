//############################################
// http://bailian.openjudge.cn/practice/1013/
//############################################

#include <iostream>
#include <cstring>
#include <cstdlib>

char Left[3][7];
char Right[3][7];
char result[3][7];
bool isFake(char c,bool light){//light==true 表示假币轻
    int i = 0;
    for(i = 0;i < 3;i++){
        if (!strchr(Left[i],c) &&  !strchr(Right[i],c))
            continue;
        else break;    
    }
    if(i == 3) return false;
    for(i = 0;i < 3;i++){
        // if(strchr(Left[i],c) && result[i][0] == 'e' || strchr(Right[i],c) && result[i][0] == 'e')  
        //     return false;
        // else if(strchr(Right[i],c) && result[i][0] == 'd' && light || strchr(Right[i],c) && result[i][0] == 'u' && !light)  continue;  
        // else if(!strchr(Left[i],c) && result[i][0] != 'e')
        //     return false;    
        if(result[i][0] == 'e'){
            if(strchr(Left[i],c) || strchr(Right[i],c))
                return false;    
        }
        else if(result[i][0] == 'u'){
            if(strchr(Left[i],c) && light || strchr(Right[i],c) && !light)
                return false;
            else if(!strchr(Left[i],c) && !strchr(Right[i],c))    
                return false;
        }
        else if(result[i][0] == 'd'){
            if(strchr(Right[i],c) && light || strchr(Left[i],c) && !light)
                return false;
            else if(!strchr(Left[i],c) && !strchr(Right[i],c))   
                return false; 
        }
    }

    return true;
}


int main(){
    int n;
    std::cin>>n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 3;j++){
            std::cin>>Left[j]>>Right[j]>>result[j];
        }
        for(char k = 'A';k <= 'L';k++){
            if(isFake(k,true)) std::cout<<k<<" is the counterfeit coin and it is light."<<std::endl;
            else if(isFake(k,false)) std::cout<<k<<" is the counterfeit coin and it is heavy."<<std::endl;
        }
    }


    return 0;
}
