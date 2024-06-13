#ifndef TYPINGTUTOR_H
#define TYPINGTUTOR_H

#include <string>

class TypingTutor {
public:
    TypingTutor();
    void showWelcomeMessage() const;
    void showMainMenu() const;
    void startPractice();
    void startTypingTest();
    void showInstructions() const;
    void quitTutor() const;

private:
    void generateRandomSample();
    void calculateMetrics(const std::string& input, double timeUsed) const;
    void displayMetrics(double timeUsed, double wpm, double accuracy) const;

    std::string currentSample;
    static const std::string samples[];
};

#endif // TYPINGTUTOR_H
