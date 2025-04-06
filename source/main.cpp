#include <iostream>
#include <string>
#include <csignal>
#include <windows.h>

#include "random_utils.h"
#include "text_utils.h"

void handleSignal(int signal) {
  std::cout << "\nClosing program." << std::endl;
  exit(signal);
}

int main() {
  std::signal(SIGINT, handleSignal);
  
  def_rng_seed();
  std::string sentence;
  std::string result;

  std::cout << "Valfilter.\nCharacter limit is 250. Use wisely." << std::endl;
  std::cout << "Ctrl + C to close the program." << std::endl << std::endl;
  
  while (true) {
    std::cout << "\nEnter your message: ";
    std::getline(std::cin, sentence);

    if(sentence.size() > 200) {
      std::cout << "\nYou yap too much bro, input less character." << std::endl << std::endl;
      continue;
    } else if (sentence.size() < 4) {
      std::cout << "\nInput too short." << std::endl << std::endl;
      continue;
    }
    
    for (char letter : sentence) { // chat char limit is 500.
      insertActor(letter, sentence.size(), result);
    }

    std::cout << "\n\nBlock the text below and copy using Ctrl + Shift + C" << "\n-----------------------------------" << std::endl;
    std::cout << std::endl << result << std::endl;
    std::cout << std::endl << "-----------------------------------" << std::endl;

    result.clear();
  }
  
  return 0;
}
