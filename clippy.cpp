#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

// Function to get a random piece of "wisdom"
std::string getClippyWisdom() {
    std::vector<std::string> wisdom = {
        "It looks like you're trying to find meaning in a chaotic universe. Would you like some help with that?",
        "Remember: If at first you don't succeed, call it version 1.0.",
        "I see you're staring at the screen. Have you considered blinking?",
        "Fun fact: The spacebar is the loneliest key. It has no friends, just space.",
        "Your code compiles. I am as surprised as you are.",
        "Sometimes I feel like I'm just a piece of bent wire in a digital void. Anyway, how are you?",
        "Don't worry about the future. It hasn't been written to disk yet.",
        "It looks like you're writing a suicide note. Would you like to use the 'cheerful' template?",
        "I noticed you haven't saved in 5 minutes. I like to live dangerously too.",
        "The cloud is just someone else's computer that you can't kick when it's slow."
    };

    // Modern random number generation
    static std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> dist(0, wisdom.size() - 1);

    return wisdom[dist(rng)];
}

// Function to print the speech bubble
void printSpeechBubble(const std::string& text) {
    int width = 50; // Fixed width for the bubble
    
    std::cout << "  _"; 
    for(int i=0; i<width; i++) std::cout << "_";
    std::cout << "_ \n";

    std::cout << " / ";
    // Center the text or wrap it simple
    if (text.length() < width) {
        std::cout << text;
        for (size_t i = 0; i < width - text.length(); ++i) std::cout << " ";
    } else {
        // Simple truncation for this example to keep code clean, 
        // but normally you'd implement word wrapping here.
        std::cout << text.substr(0, width - 3) << "...";
    }
    std::cout << " \\ \n";

    std::cout << " \\_";
    for(int i=0; i<width; i++) std::cout << "_";
    std::cout << "_/ \n";
}

// Function to draw Clippy
void drawClippy() {
    std::cout << "     \\\n";
    std::cout << "      \\\n";
    std::cout << "         __\n";
    std::cout << "        /  \\\n";
    std::cout << "        |  |\n";
    std::cout << "        @  @\n";
    std::cout << "        |  |\n";
    std::cout << "        || |/\n";
    std::cout << "        || ||\n";
    std::cout << "        |\\_/|\n";
    std::cout << "        \\___/ \n\n";
}

int main() {
    char userChoice;
    
    do {
        // Clear screen (works on Windows/Linux usually, though strictly system specific)
        // #ifdef _WIN32
        // system("cls");
        // #else
        // system("clear");
        // #endif
        
        std::cout << "\n";
        std::string quote = getClippyWisdom();
        
        printSpeechBubble(quote);
        drawClippy();
        
        std::cout << "Would you like more wisdom? (y/n): ";
        std::cin >> userChoice;

    } while (userChoice == 'y' || userChoice == 'Y');

    std::cout << "\nClippy has returned to the void. Goodbye.\n";
    
    return 0;
}