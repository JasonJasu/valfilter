#include "text_utils.h"
#include "random_utils.h"

std::vector<std::string> zeroWidthChars = {
  "\u200B", //zwsp
  "\u200C", //zwnj
  "\u200D", //zwj
  "\u2060", //wj
  "\uFEFF"  //zwnbsp
};

std::vector<std::string> invisibleChars = { //atleast in val.
  "\u15AF", //b
  "\U0001D5BC", //c
  "\U0001D5BF", //f
  "\U0001D5C7", //n
  "\U0001D5CE", //u
};

std::string randomPickChar(const std::vector<std::string>& charVector) {
  std::uniform_int_distribution<int> dist(0, charVector.size() - 1);
  return charVector[dist(def_rng)];
}

void insertActor(char letter, int repetitions, std::string& result) {
  result += letter;
  for (int i = 1; i <= repetitions; i++) {
    if (randBool(def_rng) || repetitions == 1) result += randomPickChar(invisibleChars);
    if (randBool(def_rng) && repetitions >= 2) result += randomPickChar(zeroWidthChars);
  }
}
