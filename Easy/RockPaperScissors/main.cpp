#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>

#define CLEAR_SCR "\033[2J"
#define flush() fflush(0)

using std::cin;
using std::cout;
using std::getline;
using std::string;

const string ROCK_STR = " Rock";
const string PAPER_STR = " Paper";
const string SCISSORS_STR = " Scissors";
enum Player { USER, BOT, DRAW };
enum Choice { ROCK, PAPER, SCISSORS, MISTAKE };

void sleep(int milliseconds) {
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
int randomInt() {
  unsigned int seed =
      std::chrono::high_resolution_clock::now().time_since_epoch().count();
  srand(static_cast<unsigned int>(seed));
  return rand();
}
string strToLower(string str);
void identifyChoice(char c, Choice *usrChoice);
bool booleanPrompt(string question);
Player playRound();

string startingMessage =
    "Welcome to my Command-Line Rock Paper Scissors game!\n\nBefore the game "
    "starts, you need to know how the game works.\nWell, you only need to know "
    "the keys you need to press.\nSo this is all you need to know:\n"
    "\t- For  Rock press \"1\" or \"R\",\n\t- For  Paper press \"2\" or "
    "\"P\",\n\t- For  Scissors press \"3\" or \"S\"\n\n\n";
int userScore;
int botScore;

int main(int argc, char *argv[]) {

  cout << CLEAR_SCR << startingMessage;
  if (!booleanPrompt("Ready to begin?")) {
    return 0;
  }
  cout << CLEAR_SCR;

  // Debug stuff
  switch (playRound()) {
  case USER:
    cout << "USER";
    break;
  case BOT:
    cout << "BOT";
    break;
  case DRAW:
    cout << "DRAW";
    break;
  }
  srand(3);
  cout << "\n" << rand();

  return 0;
}

string strToLower(string str) {
  for (char &c : str) {
    c = tolower(c);
  }
  return str;
}

void identifyChoice(char c, Choice *usrChoice) {
  switch (tolower(c)) {
  case '1':
  case 'a':
    *usrChoice = ROCK;
    break;
  case '2':
  case 'b':
    *usrChoice = PAPER;
    break;
  case '3':
  case 'c':
    *usrChoice = SCISSORS;
    break;
  default:
    *usrChoice = MISTAKE;
    break;
  }
}

bool booleanPrompt(string question) {
  string answer;
  while (true) {
    cout << question << " [y/n]: ";
    getline(cin, answer);
    answer = strToLower(answer);

    if (answer == "n") {
      return false;
    } else if (answer == "y") {
      return true;
    }
  }
}

Player playRound() {
  Choice usrChoice;
  Choice botChoice;
  cout << "So, what's it gonna be? [1/2/3]: ";
  string userInp;
  getline(cin, userInp);
  identifyChoice(userInp[0], &usrChoice);

  botChoice = static_cast<Choice>(randomInt() % 3);

  if (usrChoice == botChoice) {
    return DRAW;
  }
  if (usrChoice == MISTAKE) {
    return BOT;
  }
  if (botChoice == ROCK) {
    if (usrChoice == PAPER) {
      return USER;
    }
    if (usrChoice == SCISSORS) {
      return BOT;
    }
  }
  if (botChoice == PAPER) {
    if (usrChoice == SCISSORS) {
      return USER;
    }
    if (usrChoice == ROCK) {
      return BOT;
    }
  }
  if (botChoice == SCISSORS) {
    if (usrChoice == ROCK) {
      return USER;
    }
    if (usrChoice == PAPER) {
      return BOT;
    }
  }
  /// return DRAW; // In case that something goes wrong
}
