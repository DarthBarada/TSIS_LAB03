#include "Annealing_simulation_algorithm.hpp"
#include "MyFunction.hpp"

#include <random>

#include <iostream>
#include <iomanip>

inline void draw_shapka()
	 {
	    for (int temp_index = 0;temp_index<69;++temp_index) {std::cout<<"_";}
		    std::cout<<std::endl;
	 	std::cout<<std::left
		<<"| "<< std::setw(11)<<""           <<" || "<<std::setw(9) <<""         <<"|"<<std::setw(9)<<""         <<" || "<<std::setw(12)<<""            <<" | "<<std::setw(12)<<""            <<" |\n"
		<<"| "<< std::setw(11)<<" Iteration" <<" || "<<std::setw(9) <<"Tmax"     <<"|"<<std::setw(9)<<"Tmin"     <<" || "<<std::setw(12)<<"x"           <<" | "<<std::setw(12)<<"F(x)"        <<" |\n"
		<<"|_"<< std::setw(11)<<"___________"<<"_||_"<<std::setw(9) <<"_________"<<"|"<<std::setw(9)<<"_________"<<"_||_"<<std::setw(12)<<"____________"<<"_|_"<<std::setw(12)<<"____________"<<"_|\n";
	 }
inline void close_shapka()
	 {
		std::cout<<"|_"<< std::setw(11)<<"___________"<<"_||_"<<std::setw(9) <<"_________"<<"|"<<std::setw(9)<<"_________"<<"_||_"<<std::setw(12)<<"____________"<<"_|_"<<std::setw(12)<<"____________"<<"_|\n";
	 }

void Annealing_simulation_algorithm::resetT() 
	{
		temperature = AdditionalTemperature;
	}

void Annealing_simulation_algorithm::test()
  {
	std::cout<<"\nUnimodal function f(x)\n";
    pass(F);
	std::cout<<"\Multimodal function f(x)*sin(5x)\n";
    pass(F2);
  }

 void Annealing_simulation_algorithm::pass(double(*Function)(double)) 
    {
	  draw_shapka();
	  /// ---------- Инициализация генератора случайных цифр с плавающей точкой в промежутке ----------
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_real_distribution<double> dis(interval.first,interval.second);
      ///----------------------------------------------------------------------------------------------

	  std::pair <double,double> temp_point;
	  double delta = 0;
	  int iteration = 1;


	  temp_point.first = dis(gen);temp_point.second = Function(temp_point.first);

	  best_point = temp_point;

	  show(temp_point,iteration);
	  while (temperature.first < temperature.second) 
		  {
		    
             temp_point.first = dis(gen);temp_point.second = Function(temp_point.first);

			 delta = temp_point.second-best_point.second;

			  double P1 = exp((-delta)/temperature.second);
              double P2 = std::uniform_real_distribution<double>{0, 1}(gen);

			  if(delta <=0)
			     {
                  best_point = temp_point;
			     }
			  else if(P2 < P1)
			     {
				   best_point = temp_point;
			     }
             show(temp_point, iteration);
			 decreaseT(temperature);
			 ++iteration;
		  }

	  close_shapka();
	  std::cout<<"\nBest result: ["<<best_point.first<<", "<<best_point.second<<"]\n\n";

	  resetT();
	}

 void Annealing_simulation_algorithm::decreaseT(std::pair<double,double> &TemperatureInterval)
	 {
	   TemperatureInterval.second*=0.95;
	 }

void Annealing_simulation_algorithm::show(const std::pair<double,double> point, const int iteration)
	{
		std::cout<<"| "<< std::setw(11)<<iteration    <<std::fixed<<std::setprecision(3)<<" || "<<std::setw(9) <<temperature.second<<"|"<<std::setw(9)<<temperature.first<<" || "<<std::showpos<<std::setw(12)<<point.first<<" | "<<std::setw(12)<<point.second<<std::noshowpos<<" |\n";
	}