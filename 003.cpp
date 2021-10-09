#include <iostream>
#include <cstring>

char str[27];
char ans[27];
bool flag[27] = {0};
int len;
void permutation(int n){//生成从n到结尾的全排列
    // if(n == len - 1){
    //     std::cout<<str<<std::endl;
    // }
    // else{
    //     for(int i = n;i < len;i++){
    //         std::swap(str[i],str[n]);
    //         permutation(n + 1);
    //         std::swap(str[i],str[n]);
    //     }
    // }
    if(n == len){
        ans[len] = 0;
        std::cout<<ans<<std::endl;
    }
    else{
        for(int i = 0;i < len;i++){
            if(!flag[i]){
                ans[n] = str[i]; 
                flag[i] = true;
                permutation(n + 1);
                flag[i] = false;
            }
        }
    }

}

int main(){
    std::cin>>str;
    len = strlen(str);
    for(int i = 0;i < len;i++)
        flag[i] = false;
    permutation(0);


    return 0;
}