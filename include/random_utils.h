#ifndef RANDOM_UTILS_H
#define RANDOM_UTILS_H

#include <random>

extern std::mt19937 def_rng;
extern std::uniform_int_distribution<std::mt19937::result_type> repDist;
extern std::uniform_int_distribution<std::mt19937::result_type> randBool;

void def_rng_seed(int seed = 0);

#endif
