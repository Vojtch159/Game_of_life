#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> x {
        {"  ", "  ", "  ", "  ", "  "},
        {"  ", "+", "+", "+", "  "},
        {"  ", "  ", "+", "+", "  "},
        {"  ", "+", "  ", "+", "  "},
        {"  ", "  ", "  ", "  ", "  "},
    };

void update_field(int y){
        for(int i{0}; i < y; i++){
            for(int j{0}; j < y; j++){
                std::cout << x[j][i];
            }
            std::cout << std::endl;
        }
}

void calculate_field(int y) {
    for(int i{1}; i < y-2; i++){
            for(int j{1}; j < y-2; j++){
                int g; 
                if(x[j+1][i] == "+")
                    g++;
                if(x[j+1][i+1] == "+")
                    g++;
                if(x[j][i+1] == "+")
                    g++;
                if(x[j-1][i] == "+")
                    g++;
                if(x[j-1][i-1] == "+")
                    g++;
                if(x[j][i-1] == "+")
                    g++;                
                if(x[j][i] == "+"){
                    if(g < 2)
                        x[j][i] = "  ";
                    if(g >= 2 && g < 4)
                        x[j][i] = "+" ;  
                    if(g > 3)
                        x[j][i] = "  " ;     
                }else{
                   if(g > 3)
                        x[j][i] = "+" ;     
                }
            }
        }
    update_field(y);
}


int main(){

    int y = 5;
    update_field(y);

    while(true){
        calculate_field(y);
        usleep(500000);
        system("clear");
    }
    return 0;
}