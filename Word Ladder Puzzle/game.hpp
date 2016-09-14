#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>

#include "linkedlist.hpp"


class Game{

public:
    Game(std::string file); 
    
    void listWords();
    void play(std::string, std::string);
    template<typename T>
        int search(std::vector<T> &, T, int, int);

private:

    LinkedList<std::vector<std::string>> queue;
    std::string fin;
    std::vector<std::string> dictionary;
    std::vector<std::string> word;

}; 




#endif
