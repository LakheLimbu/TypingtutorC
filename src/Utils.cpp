#include "Utils.h"
#include <iostream>
#include <sstream>
#include <iterator>

char getChoice() {
    char choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining input
    return choice;
}

int countWords(const std::string& sentence) {
    std::istringstream stream(sentence);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}
