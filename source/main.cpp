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
  std::string sentence;
  std::string result;

  std::cout << "Valfilter\nCharacter limit is 200. Use wisely." << std::endl;
  std::cout << "Ctrl + C to close the program." << std::endl;
  
  while (true) {
    std::cout << "\n\nEnter your message: ";
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

    clipboardCopy(utf8to16(result));

    std::cout << "\nText copied to the clipboard. Paste it to your chat." << std::endl;

    /*std::cout << "\nif it dont work : Block-copy this with Ctrl + Shift + C" << "\n-----------------------------------" << std::endl;*/
    /*std::cout << result << std::endl;*/
    /*std::cout << "-----------------------------------" << std::endl;*/

    result.clear();
  }
  
  return 0;
}
