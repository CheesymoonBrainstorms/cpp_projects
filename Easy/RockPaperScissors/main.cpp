#include <cctype>
#include <iostream>
#include <string>

#define CLEAR_SCR "\033[2J"
#define flush() fflush(0)

using std::cin;
using std::cout;
using std::getline;
using std::string;

string strToLower(string str) {
  for (char &c : str) {
    c = tolower(c);
  }
  return str;
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

string startingMessage =
    "Welcome to my Command-Line Rock Paper Scissors game!\n\nBefore the game "
    "starts, you need to know how the game works.\nWell, you only need to know "
    "the keys you need to press.\nSo this is all you need to know:\n"
    "\t- For  Rock press \"1\" or \"R\",\n\t- For  Paper press \"2\" or "
    "\"P\",\n\t- For  Scissors press \"3\" or \"S\"\n\n\n";

int main(int argc, char *argv[]) {
  cout << CLEAR_SCR << startingMessage;
  if (!booleanPrompt("Ready to begin?")) {
    return 0;
  }
  cout << CLEAR_SCR;
  return 0;
}
