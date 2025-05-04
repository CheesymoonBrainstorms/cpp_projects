#include <cctype>
#include <iostream>
#include <string>

#define CLEAR_SCR "\033[2J"
#define flush() fflush(0)

using std::cin;
using std::cout;
using std::getline;
using std::string;

const string ROCK_STR = " Rock";
const string PAPER_STR = " Paper";
const string SCISSORS_STR = " Scissors";
enum Player { USER, BOT };
enum Choice { ROCK, PAPER, SCISSORS, MISTAKE };

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

  // playRound();

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
}
