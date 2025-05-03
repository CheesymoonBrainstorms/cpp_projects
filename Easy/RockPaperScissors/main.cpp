#include <iostream>
#include <string>

#define CLEAR_SCR "\033[2J"

std::string startingMessage =
    "Welcome to my Command-Line Rock Paper Scissors game!\n\nBefore the game "
    "starts, you need to know how the game works.\nWell, you only need to know "
    "the keys you need to press.\nSo this is all you need to know:\n"
    "\t- For  Rock press \"1\" or \"R\",\n\t- For  Paper press \"2\" or "
    "\"P\",\n\t- For  Scissors press \"3\" or \"S\"\n\n\n";

int main(int argc, char *argv[]) {
  std::cout << CLEAR_SCR << startingMessage;
  return 0;
}
