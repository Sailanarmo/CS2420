#include <iostream>
#include <exception>

#include "game.hpp"

int main(){

    Game game("dictionary.txt");

    try{
        game.play("fast", "slow");
    }
    catch(std::exception & e){
        std::cerr << e.what() << std::endl;
    }
}
