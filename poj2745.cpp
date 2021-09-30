#include <iostream>
#include <sstream>

char n1[11] = {"---- -----"};//第一划
char n2[11] = {"||  ||| ||"};
char n3[11] = {"| |||  |||"};
char n4[11] = {"  ----- --"};
char n5[11] = {"|||   | | "};
char n6[11] = {"|  |||||||"};
char n7[11] = {"- -- -- --"};

int main(){
    std::stringstream ss;
    int s,n;
    std::string ans;
    while(true){
        std::cin>>s>>n; ss << n; ans = ss.str();
        if(!(s || n)) break;
        else{
            // itoa(n,ans,10);
            // for(int i = 0;i < 7;i++){
            for(int j = 0;j < ans.size();j++){
                //第一划
                std::cout<<' '; 
                for(int k = 0;k < s;k++){
                    std::cout<<n1[ans[j] - '0'];
                }
                if(j == ans.size() - 1)
                    std::cout<<std::endl;
                else
                    std::cout<<' ';    
            }
            for(int j = 0;j < s;j++){
                for(int k = 0;k < ans.size();k++){
                    //第二划
                    std::cout<<n2[ans[k] - '0'];
                    for(int l = 0;l < s;l++)
                        std::cout<<' ';     
                    //第三划
                    std::cout<<n3[ans[k] - '0'];
                    if(k != ans.size() - 1)
                        std::cout<<' ';   
                    if(k == ans.size() - 1)
                        std::cout<<std::endl;    
                }
            }
            for(int j = 0;j < ans.size();j++){
                //第四划
                std::cout<<' ';  
                for(int k = 0;k < s;k++){
                    std::cout<<n4[ans[j] - '0'];
                }
                if(j == ans.size() - 1)
                    std::cout<<std::endl;
                else
                    std::cout<<' ';    
            }    
            for(int j = 0;j < s;j++){
                for(int k = 0;k < ans.size();k++){
                    //第二划
                    std::cout<<n5[ans[k] - '0'];
                    for(int l = 0;l < s;l++)
                        std::cout<<' ';     
                    //第三划
                    std::cout<<n6[ans[k] - '0'];
                    if(k != ans.size() - 1)
                        std::cout<<' ';   
                    if(k == ans.size() - 1)
                        std::cout<<std::endl;    
                }
            }
            for(int j = 0;j < ans.size();j++){
                //第四划
                std::cout<<' ';  
                for(int k = 0;k < s;k++){
                    std::cout<<n7[ans[j] - '0'];
                }
                if(j == ans.size() - 1)
                    std::cout<<std::endl;
                else
                    std::cout<<' ';    
            }    
            //}   

            std::cout<<std::endl; 
        }
    }


    return 0;
}