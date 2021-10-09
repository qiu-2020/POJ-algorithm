#include <iostream>
#include <cmath>
int ItoBin(int n,int ans[]){
    int i = 0;
    while(n != 0){
        ans[i++] = n % 2;
        n /= 2;
    }
    return i - 1;
}

void pow_2(int n){
//    std::cout<<"2";
    int a[20];int bitnum = ItoBin(n,a);
    if(n == 1) std::cout<<"2";
    else if(n == 0) std::cout<<"2(0)";
    else{
        for(int j = bitnum;j >= 0;j--){
            if(a[j] == 1){
                if(j != bitnum) std::cout<<'+';
                if(j != 1 && j != 0) std::cout<<"2(";
                else std::cout<<"";
                pow_2(j);
                if(j != 1 && j!= 0) std::cout<<")";
                else std::cout<<"";
            }
        }
    } 
}


int main(){
    int n;
    std::cin>>n;
    pow_2(n);

    return 0;
}