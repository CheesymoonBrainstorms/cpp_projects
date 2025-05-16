#include "colored_text.h"
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>

#define CLEAR_SCR "\033[H\033[J"
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
int userScore;
int botScore;
Choice usrChoice;
Choice botChoice;
Player roundWinner;

namespace debug {
void WARN(string message) {
  cout << BYEL << "\nWARNING: " << YEL << message << RESET << "\n";
}
void ERR(string message, int status = 1) {
  cout << BRED << "\nERROR: " << RED << message << RESET << "\n";
  exit(status);
}

} // namespace debug

void sleep(int milliseconds) {
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
int randomInt() {
  unsigned int seed =
      std::chrono::high_resolution_clock::now().time_since_epoch().count();
  srand(static_cast<unsigned int>(seed));
  return rand();
}

string getWinner();
string getStrChoice(Choice choice);
string strToLower(string str);
void identifyChoice(char c, Choice *usrChoice);
bool booleanPrompt(string question);
void countdown() {
  cout << CLEAR_SCR;
  flush();
  sleep(500);
  cout << "\rGet Ready!";
  flush();
  sleep(500);
  cout << "\r          ";
  flush();
  sleep(500);
  cout << "\r3";
  flush();
  sleep(500);
  cout << "\r2";
  flush();
  sleep(500);
  cout << "\r1";
  flush();
  sleep(500);
  cout << "\r";
  flush();
}
void playRound(int round);

string startingMessage =
    "Welcome to my Command-Line Rock Paper Scissors game!\n\nBefore the game "
    "starts, you need to know how the game works.\nWell, you only need to know "
    "the keys you need to press.\nSo this is all you need to know:\n"
    "\t- For  Rock press \"R\" or \"1\",\n\t- For  Paper press \"P\" or "
    "\"2\",\n\t- For  Scissors press \"S\" or \"3\"\n\n\n";

int main(int argc, char *argv[]) {

  cout << CLEAR_SCR << startingMessage;
  if (!booleanPrompt("Ready to begin?")) {
    return 0;
  }
  cout << CLEAR_SCR;

  countdown();

  playRound(1);

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
  case 'r':
    *usrChoice = ROCK;
    break;
  case '2':
  case 'p':
    *usrChoice = PAPER;
    break;
  case '3':
  case 's':
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

void playRound(int round) {
  cout << "So, what's it gonna be? [R/P/S]: ";
  string userInp;
  getline(cin, userInp);
  identifyChoice(userInp[0], &usrChoice);

  botChoice = static_cast<Choice>(randomInt() % 3);

  if (usrChoice == botChoice) {
    roundWinner = DRAW;
  }
  if (usrChoice == MISTAKE) {
    roundWinner = BOT;
  }
  if (botChoice == ROCK) {
    if (usrChoice == PAPER) {
      roundWinner = USER;
    }
    if (usrChoice == SCISSORS) {
      roundWinner = BOT;
    }
  }
  if (botChoice == PAPER) {
    if (usrChoice == SCISSORS) {
      roundWinner = USER;
    }
    if (usrChoice == ROCK) {
      roundWinner = BOT;
    }
  }
  if (botChoice == SCISSORS) {
    if (usrChoice == ROCK) {
      roundWinner = USER;
    }
    if (usrChoice == PAPER) {
      roundWinner = BOT;
    }
  }
  cout << "User chose " << getStrChoice(usrChoice) << " and Bot chose "
       << getStrChoice(botChoice) << "\nSo, " << getWinner() << " wins!\n";
}

string getWinner() {
  switch (roundWinner) {
  case USER:
    return "USER";
  case BOT:
    return "BOT";
  case DRAW:
    return "DRAW";
  }
  debug::ERR("Unexpected roundWinner value");
  return ""; // To avoid compiler warning
}

string getStrChoice(Choice choice) {
  switch (choice) {
  case ROCK:
    return ROCK_STR;
  case PAPER:
    return PAPER_STR;
  case SCISSORS:
    return SCISSORS_STR;
  case MISTAKE:
    return "NOTHING";
  }
  debug::ERR("Unexpected Choice value");
  return ""; // To avoid compiler warning
}
