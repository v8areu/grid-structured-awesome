#include "../global.hpp"
#include "grid_process.hpp"
#include "../pre_process/airfoil.hpp"
#include "../math_libs/spline.h"

Grid_Process::Grid_Process(Airfoil_Parameters airfoil_pars, Parameters pars) {

	//make local vars
	airfoil_x	=	airfoil_pars.x;
	airfoil_y	=	airfoil_pars.y;

}

//airfoil spline interpolation
Airfoil_Parameters Grid_Process::grid_airfoil_interpolation(int airfoil_nodes, int xi_stretch_type) {
	
	Airfoil_Parameters airfoil_pars_new;
	tk::spline lower_spline;		//from spline.h
	tk::spline upper_spline;		//from spline.h

	//divide x into upper and lower spline (in increasing way!)
	std::vector<double> upper_x((airfoil_x.size()-1)/2 + 1);
	std::vector<double> lower_x((airfoil_x.size()-1)/2 + 1);
	std::vector<double> upper_y((airfoil_y.size()-1)/2 + 1);
	std::vector<double> lower_y((airfoil_y.size()-1)/2 + 1);

	for (auto i = 0; i < (airfoil_x.size()-1)/2 + 1; i++) {
		lower_x[i]	=	airfoil_x[(airfoil_x.size()-1)/2 - i];
		upper_x[i]	=	airfoil_x[(airfoil_x.size()-1)/2 + i];
		lower_y[i]	=	airfoil_y[(airfoil_y.size()-1)/2 - i];
		upper_y[i]	=	airfoil_y[(airfoil_y.size()-1)/2 + i];
	}

	//interpolate process
	lower_spline.set_points(lower_x, lower_y);
	upper_spline.set_points(upper_x, upper_y);

	//looping through the airfoil nodes
	std::vector<double> temp_lower_x((airfoil_nodes+1)/2);
	std::vector<double> temp_upper_x((airfoil_nodes+1)/2);
	std::vector<double> temp_lower_y((airfoil_nodes+1)/2);
	std::vector<double> temp_upper_y((airfoil_nodes+1)/2);

	for (auto i = 0; i < (airfoil_nodes+1)/2; i++) {
		temp_lower_x[i]	=	grid_stretching_equal(2*i, airfoil_nodes);
		temp_upper_x[i]	=	grid_stretching_equal(2*i, airfoil_nodes);
		
		//y
		temp_lower_y[i]	=	lower_spline(temp_lower_x[i]);
		temp_upper_y[i]	=	upper_spline(temp_upper_x[i]);
	}

	//combine the upper and lower in the same manner as before
	std::vector<double> temp_x(airfoil_nodes);
	std::vector<double> temp_y(airfoil_nodes);


	for (auto i = 0; i < airfoil_nodes; i++) {
		if (i < (airfoil_nodes+1)/2 - 1)  {
			temp_x[i]	=	temp_lower_x[temp_lower_x.size() - 1 - i];
			temp_y[i]	=	temp_lower_y[temp_lower_y.size() - 1 - i];
		} else if (i > (airfoil_nodes+1)/2 - 1) {
			temp_x[i]	=	temp_upper_x[i - (airfoil_nodes+1)/2 + 1];
			temp_y[i]	=	temp_upper_y[i - (airfoil_nodes+1)/2 + 1];
		} else {
			temp_x[i]	=	temp_lower_x[0];
			temp_y[i]	=	temp_lower_y[0];
		}

	}

	airfoil_pars_new.x	=	temp_x;
	airfoil_pars_new.y	=	temp_y;

	return airfoil_pars_new;
}

double Grid_Process::grid_stretching_equal(double i, double N) {

	return static_cast<double>(i)/(static_cast<double>(N) - 1);	

}

Grid_Process::Grid_Algebra_Process::Grid_Algebra_Process() {

	std::cout <<"HEY HO\n";
	std::cout << " HAHAHAH \n";

}
