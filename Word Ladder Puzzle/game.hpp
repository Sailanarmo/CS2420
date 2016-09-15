#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "linkedlist.hpp"


class Game{

public:
    Game(std::string file) { import(file);}

    void play(std::string, std::string);

private:

    LinkedList<std::vector<std::string>> queue;
    std::string fin;
    std::vector<std::string> dictionary;
    std::vector<std::string> words;

    template<typename T>
    int recurSearch(std::vector<T> &, T, int, int);

    void import(std::string file);
    void deleteWords(int);
    bool checkWord(std::vector<std::string> &, std::string);
    bool oneAway(std::vector<std::string>);
};

template<typename T>
std::ostream& operator<< (std::ostream& o, std::vector<T> const & v){
    for (auto & e : v){
        o << e << std::endl;
    }
    return o;
}

#endif
