#include "game.hpp"

template<typename T>
int Game::search(std::vector<T> dictionary, T target, int start, int end){

    if(start > end){
	return -1;
    }

    auto mid = (start + end) / 2;

    if(target == dictionary[mid]){
	return mid;
    }
    else if(target < dictionary[mid])
	return search(dictionary, target, start, mid -1);
    }
    else {
	return search(dictionary, target, mid+1, end);
    }
}
