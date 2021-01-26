#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>

void update_field(std::vector<std::vector<std::string>> x, int y){
        for(int i{0}; i < y; i++){
            for(int j{0}; j < y; j++){
                std::cout << x[j][i];
            }
            std::cout << std::endl;
        }
}

std::vector<std::vector<std::string>> calculate_field(std::vector<std::vector<std::string>> x, int y) {
    for(int i{0}; i < y; i++){
            for(int j{0}; j < y; j++){
                //need to check how many cells are alive around the current cell, but dk how so i'm fucked :)
            }
        }
    return x;
}


int main(){

    int y = 5;
    std::vector<std::vector<std::string>> field {
        {"+", "  ", "  ", "  ", "  "},
        {"  ", "+", "+", "  ", "  "},
        {"  ", "  ", "  ", "+", "+"},
        {"  ", "  ", "  ", "+", "+"},
        {"  ", "  ", "  ", "  ", "+"},
    };
    update_field(field, y);
    while(true){
        update_field(calculate_field(field, y), y);
        usleep(500000);
        system("clear");
    }
    return 0;
}

