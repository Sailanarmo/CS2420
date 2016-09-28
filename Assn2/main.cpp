#include <iostream>
#include <fstream>

#include "TreeStarter.hpp"

int main()
{

    std::ifstream inf("test.txt");
    if(!inf) std::cout <<"PLS";

    Tree tree;
    tree.preorderBuild(inf);
    std::cout << tree.printTree() << std::endl;

    return 0;
}
