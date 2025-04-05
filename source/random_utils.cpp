#include "random_utils.h"

std::mt19937 def_rng;
std::uniform_int_distribution<std::mt19937::result_type> repDist(2, 3); // actor repetition range || val character limit is 500.
std::uniform_int_distribution<std::mt19937::result_type> randBool(0, 1);

void def_rng_seed(int seed) {
  def_rng.seed(std::random_device{}());
  if (seed != 0) def_rng.seed(seed);
}
