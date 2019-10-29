#include "Annealing_simulation_algorithm.hpp"

int main()
  {
	Annealing_simulation_algorithm B(std::make_pair(-2.0,4.0),std::make_pair(0.1,10000.));
	B.test();
    return 0;
  }
