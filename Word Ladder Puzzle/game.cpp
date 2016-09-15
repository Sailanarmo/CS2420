#include "game.hpp"

void Game::play(std::string f, std::string e){
    
    if(f.size() != e.size()){
	throw std::domain_error("Words are not the same length, can't make a word ladder.");
    }

    queue.clear();
    
    if(!checkWord(dictionary, f)){
	throw std::domain_error("First word is not a valid word.");
    }
    if(!checkWord(dictionary, e)){
	throw std::domain_error("Last word is not a valid word.");
    }

    fin = e;

    std::vector<std::string> begin;
    begin.push_back(f);
    queue.push_back(begin);

    while(!oneAway(queue.popOff()))[]

    std::cout << "The words from " << f << " to " << e << " lists out:" <<std::endl;
    std::cout << queue.pushOff() << std::endl;

}

void Game::import(std::string file){

    std::ifstream fin(file);
    std::string word;

    while (!fin.eof()){
	fin >> word;
	dictionary.push_back(word);
    }
}

bool Game::checkWord(std::vector<std::string> & dictionary, std::string target){
    auto results = recurSearch(dictionary, target, 0, dictionary.size() - 1);
    if (result >= 0){
	if(words.size() >= dictionary.size()){
	    words.erase(words.begin() + result);
	}
	return true;
    }
    return false;
} 
    
template<typename T>
int Game::recurSearch(std::vector<T> dictionary, T target, int start, int end){

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

bool Game::oneAway(std::vector<std::string> target){

    for(int i = 0; i < target.back().size(); ++i){
	auto next = target.back();
	for (int j = 97; j <= 122; ++j){
	    auto nextLadder = target;
	    next[i] = static_cast<char>(j);
	    if(checkWord(words, next)){
		nextLadder.push_back(next);
		queue.push_back(next);

		if(next == fin){
		    return true;
		}
	    }
	}
    }
    return false;
}
