#include <iostream>
#include <string>
#include <csignal>

#include "random_utils.h"
#include "text_utils.h"

void handleSignal(int signal) {
  std::cout << "\nClosing program." << std::endl;
  exit(signal);
}

int main() {
  std::signal(SIGINT, handleSignal);
  
  def_rng_seed();
  std::string result;
  std::string sentence;
  
  while (true) {
    int repetitions;
    std::cout << "\nEnter your message: ";
    std::getline(std::cin, sentence);

    if(sentence.size() > 250) {
      std::cout << "\nYou yap too much bro, input less character." << std::endl << std::endl;
      continue;
    } else if (sentence.size() >= 120) {
      repetitions = 1;
    } else if (sentence.size() < 4) {
      std::cout << "\nInput too short." << std::endl << std::endl;
      continue;
    }
    
    for (char letter : sentence) { // chat char limit is 500.
      if(repetitions != 1) repetitions = repDist(def_rng);
      insertActor(letter, repetitions, result);
    }
    
    std::cout << std::endl << result << std::endl << std::endl;
    repetitions = 0;
    result.clear();
  }
  
  return 0;
}
