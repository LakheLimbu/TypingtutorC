#include "TypingTutor.h"
#include "Utils.h"
#include "TextSamples.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

TypingTutor::TypingTutor() {
    generateRandomSample();
}

void TypingTutor::showWelcomeMessage() const {
    std::cout << "WELCOME TO TYPING TUTOR" << std::endl;
    std::cout << "......................." << std::endl << std::endl;
    std::cout << "Practice typing common programming syntax and symbols." << std::endl;
    std::cout << "Improve your typing speed and accuracy." << std::endl;
}

void TypingTutor::showMainMenu() const {
    std::cout << "1. Start Practice" << std::endl;
    std::cout << "2. Start Typing Test" << std::endl;
    std::cout << "3. Instructions" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << "Select option: ";
}

void TypingTutor::startPractice() {
    generateRandomSample();
    std::cout << currentSample << std::endl;
    time_t start = time(nullptr);
    std::string input;
    std::getline(std::cin, input);
    time_t end = time(nullptr);
    double timeUsed = difftime(end, start);
    calculateMetrics(input, timeUsed);
}

void TypingTutor::startTypingTest() {
    generateRandomSample();
    std::cout << "Typing Test:" << std::endl;
    std::cout << currentSample << std::endl;
    time_t start = time(nullptr);
    std::string input;
    std::getline(std::cin, input);
    time_t end = time(nullptr);
    double timeUsed = difftime(end, start);
    calculateMetrics(input, timeUsed);
}

void TypingTutor::showInstructions() const {
    std::cout << "Instructions" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "1. Select 'Start Practice' to practice typing." << std::endl;
    std::cout << "2. Select 'Start Typing Test' to test your typing speed and accuracy." << std::endl;
    std::cout << "3. Follow the on-screen instructions and type the given text." << std::endl;
    std::cout << "4. Your speed will be calculated in words per minute (WPM) and accuracy will be displayed." << std::endl;
    std::cout << "Press any key to go back to the menu." << std::endl;
    std::cin.get(); // Wait for any key press
}

void TypingTutor::quitTutor() const {
    std::cout << "Thank you for using Typing Tutor. Goodbye!" << std::endl;
    exit(0);
}

void TypingTutor::generateRandomSample() {
    int total = sizeof(samples) / sizeof(samples[0]);
    int random = rand() % total;
    currentSample = samples[random];
}

void TypingTutor::calculateMetrics(const std::string& input, double timeUsed) const {
    int totalChars = currentSample.size();
    int correctChars = 0;
    for (size_t i = 0; i < input.size() && i < currentSample.size(); ++i) {
        if (input[i] == currentSample[i]) {
            correctChars++;
        }
    }
    double accuracy = (static_cast<double>(correctChars) / totalChars) * 100;
    int words = countWords(input);
    double wpm = (words / timeUsed) * 60;
    displayMetrics(timeUsed, wpm, accuracy);
}

void TypingTutor::displayMetrics(double timeUsed, double wpm, double accuracy) const {
    std::cout << "Time elapsed: " << timeUsed << " seconds" << std::endl;
    std::cout << "Your Speed: " << wpm << " WPM" << std::endl;
    std::cout << "Accuracy: " << accuracy << " %" << std::endl;
}
