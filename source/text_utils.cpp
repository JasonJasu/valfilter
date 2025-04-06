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
  //utf-16 fills two character space. bummer.
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

void insertActor(char letter, int strsize, std::string& result) {
  int repetition = 1;
  repetition = repDist(def_rng);
  if(strsize > 80) repetition = 1;

  result += letter;
  for(int i = 1; i <= repetition; i++) {
    if(randBool(def_rng) && repetition == 1) result += "\u15AF";
    if(randBool(def_rng) || repetition != 1) result += randomPickChar(invisibleChars);
    if(randBool(def_rng) && randBool(def_rng) && strsize <= 120) result += randomPickChar(zeroWidthChars);
  }
}
