#include "game.hpp"



void Game::play(std::string f, std::string e) {

    if (f.size() != e.size()) {
        throw std::domain_error("Words are not the same length, can't make a word ladder.");
    }
    std::cout << "looking " << f << " " << e << std::endl;
    queue.clear();
    deleteWords(f.size());

    if (!checkWord(dictionary, f)) {
        throw std::domain_error("First word is not a valid word.");
    }

    if (!checkWord(dictionary, e)) {
        throw std::domain_error("Last word is not a valid word.");
    }


    fin = e;

    std::vector<std::string> begin;
    begin.push_back(f);
    queue.push_Back(begin);

    while (!oneAway(queue.pop())){}

            std::cout << "The words from " << f << " to " << e << " lists out:" << queue.back().size() << std::endl;
            std::cout << queue.back() << std::endl;
}

void Game::import(std::string file) {

    std::ifstream fin(file);
    std::string word;
    if(!fin)
    std::cout << "bad file" << std::endl;
    while (!fin.eof()) {
        fin >> word;
        dictionary.push_back(word);
    }
    std::cout << "Dictionary imported: " << dictionary.size() << std::endl;
}

bool Game::checkWord(std::vector<std::string> &dictionary, std::string target) {
    auto results = recurSearch(dictionary, target, 0, dictionary.size() - 1);
    if (results >= 0) {
        if (words.size() >= dictionary.size()) {
            words.erase(words.begin() + results);
        }
        return true;
    }
    return false;
}

template<typename T>
int Game::recurSearch(std::vector<T> &dictionary, T target, int start, int end) {

    if (start > end) {
        return - 1;
    }

    auto mid = (start + end) / 2;

    if (target == dictionary[mid]) {
        return mid;
    }
    else if (target < dictionary[mid]) {
        return recurSearch(dictionary, target, start, mid - 1);
    }
    else {
        return recurSearch(dictionary, target, mid + 1, end);
    }
}

bool Game::oneAway(std::vector<std::string> target) {
    for (auto i = 0u; i < target.back().size(); ++i) {
        auto next = target.back();
        for (int j = 'a'; j <= 'z'; ++j) {
            auto nextLadder = target;
            next[i] = static_cast<char>(j);
            if (checkWord(words, next)){
              //  std::cout << next << " ";
                nextLadder.push_back(next);
                queue.push_Back(nextLadder);

                if (next == fin) {
                    //std::cout << "found it!" << next << std::endl;
                    return true;
                }
            }
        }
        //std::cout << std::endl;
    }
    return false;
}

void Game::deleteWords(int size) {
    words.clear();
    for (auto && e: dictionary){
        if(e.size() == size){
            words.push_back(e);
        }
    }
}
