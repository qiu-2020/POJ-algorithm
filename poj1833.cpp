#include <iostream>
#include <algorithm>

int array[1024];
bool flag = false;
int n;

bool myCompare(int a,int b){
    return a > b;
}

void nextPermutation(void){
    for(int i = n - 1;i > 0;i--){
        if(array[i] > array[i - 1]){
            flag = true;
            int tmp = array[i];
            int tmp_i = i ;
            for(int j = i;j < n;j++){
                if(array[j] < tmp && array[j] > array[i - 1]){
                    tmp = array[j];
                    tmp_i = j;                    
                }
            }
            std::swap(array[tmp_i],array[i - 1]);
            std::sort(array + i,array + n);
            break;
        }
    }
    if(!flag){
        std::sort(array,array + n);
    } 
}

int main(){
    int m,k;
    std::cin>>m;
    for(int i = 0;i < m;i++){
        std::cin>>n>>k;
        for(int j = 0;j < n;j++)
            std::cin>>array[j];
        
        for(int j = 0;j < k;j++){
            nextPermutation();
        }    
        for(int j = 0;j < n;j++){
            std::cout<<array[j]<<' ';
        }
        std::cout<<std::endl;
    }


    return 0;
}