#pragma once
#include <vector>

class Annealing_simulation_algorithm 
	{
	   std::pair<double,double> interval;

	   std::pair<double,double> temperature;
	   std::pair<double,double> AdditionalTemperature;

	   std::pair<double,double> best_point;

       public:

	   Annealing_simulation_algorithm(std::pair<double,double> Segment,std::pair<double,double> TemperatureIntreval):interval(Segment),AdditionalTemperature(TemperatureIntreval),temperature(TemperatureIntreval) {}
	   
	   void decreaseT(std::pair<double,double> &);

	   void test();
	   void pass(double(*)(double));
	   void resetT();

	   void show(const std::pair<double,double>,const int);
	};