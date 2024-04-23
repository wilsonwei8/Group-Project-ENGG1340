#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

// Color codes
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define ORANGE "\033[38;5;208m"
#define PURPLE "\033[38;5;135m"
#define GRAY "\033[38;5;242m"
#define PINK "\033[38;5;205m"

void introduction() {
  string title = R"(welcome to
  ______   ______   _______    ______   __    __   ______
 /      \ /      \ |       \  /      \ |  \  |  \ /      \
|  $$$$$$|  $$$$$$\| $$$$$$$\|  $$$$$$\| $$\ | $$|  $$$$$$
| $$     | $$  | $$| $$__/ $$| $$__| $$| $$$\| $$| $$ 
| $$| ___| $$  | $$| $$    $$| $$    $$| $$$$\ $$| $$|  ___
| $$| $$$| $$  | $$| $$$$$$$\| $$$$$$$$| $$\$$ $$| $$|  $$$|
| $$    $| $$__/ $$| $$__/ $$| $$  | $$| $$ \$$$$| $$     $|
 \$$    $ \$$    $$| $$    $$| $$  | $$| $$  \$$$ \$$     $/
  \$$$$$$  \$$$$$$  \$$$$$$$  \$$   \$$ \$$   \$$  \$$$$$$/ 
)"; 

    for (char& c : title) {
        if (c == '$') {
            cout << BOLD << GREEN << c << RESET;
            this_thread::sleep_for(milliseconds(5));
        }
        else if (c == '_' || c == '\\' || c == '/' || c == '|') {
            cout << BOLD << BLUE << c << RESET;
            this_thread::sleep_for(milliseconds(5));
        }
        else {
            cout << BOLD << RED << c << RESET;
            this_thread::sleep_for(milliseconds(5));
        }
    }
  this_thread::sleep_for(milliseconds(300));

  string text1 = "Here, you can choose to play with your friend. If you are confident enough, you can also challenge AI!";
  string text2 = "Before we start, are you familiar with the rules of Gobang, especially the balance breaker -- restricted hand? (Y or N)";

  for (char& c : text1) {
        cout << BOLD << c << RESET;
        this_thread::sleep_for(milliseconds(5));
  }
  cout << endl;
  for (char& c : text2) {
        cout << BOLD << c << RESET;
        this_thread::sleep_for(milliseconds(5));
  }

  string explain_rules;
  

  // if enter "Y"
  string text3 = "Well done! Let's start now!"; 
  // if enter "N".
  string text4 = "Okay, I'll explain the rule to you!";
  string text5 = R"(Players alternate turns placing a stone of their color on an empty intersection. Black plays first. The winner is the first player to form an unbroken line of five stones of their color horizontally, vertically, or diagonally.
  However, when playing the game, people found that the black side had a disproportionate advantage.
  To make the game fairer, a balance breaker -- restricted hand was introduced in this game. The black side cannot use Three-Three, Four-Four, or Long-Chain to win the game. If the black side moves a restricted hand, he will lose automatically.
  If you want to practice more, you can choose r to play residual situation!)";
  // else
  string text6 = "Sorry, please enter \"Y\" or \"N\": ";

  while (true) {
    cin >> explain_rules;
    if (explain_rules == "Y") {
      for (char& c : text3) {
        cout << BOLD << c << RESET;
        this_thread::sleep_for(milliseconds(5));
        }
      cout << endl;
      break;
    }
    else if (explain_rules == "N") {
      for (char& c : text4) {
        cout << BOLD << c << RESET;
        this_thread::sleep_for(milliseconds(5));
      }
      cout << endl;
      this_thread::sleep_for(milliseconds(100));
      for (char& c : text5) {
        cout << BOLD << c << RESET;
        this_thread::sleep_for(milliseconds(5));
      }
      cout << endl;
      break;
    }
    else {
      for (char& c : text6) {
        cout << BOLD << c << RESET;
        this_thread::sleep_for(milliseconds(5));
      }
    }
  }

  return 0;
}
