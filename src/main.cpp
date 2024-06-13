#include "TypingTutor.h"
#include "Utils.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Initialize random seed

    TypingTutor tutor;
    tutor.showWelcomeMessage();

    while (true) {
        tutor.showMainMenu();
        char choice = getChoice();

        if (choice == '1') {
            tutor.startPractice();
        } else if (choice == '2') {
            tutor.startTypingTest();
        } else if (choice == '3') {
            tutor.showInstructions();
        } else if (choice == '4') {
            tutor.quitTutor();
        } else {
            std::cout << "Invalid choice! Please select again." << std::endl;
        }
    }

    return 0;
}
