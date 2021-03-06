#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <iostream>
#include <cmath>
#include <vector>

struct Parameters {

	int max_xi_nodes; //xi means x in computational domain
	int max_eta_nodes;	//eta means y in computational domain
	int xi_stretch_type;
	int eta_stretch_type;
	int grid_type;		//0 = O grid; 1 = C grid
};

struct Airfoil_Parameters {
	
	int airfoil_nodes;
	std::vector<double> x;
	std::vector<double> y;
	std::vector<double> s;
	std::vector<double> sigma;	//parameterized s
};

struct Grid_Parameters {

	std::vector<double> x_xi_outer_boundary;
	std::vector<double> y_xi_outer_boundary;
	std::vector<double> x_xi_inner_boundary;
	std::vector<double> y_xi_inner_boundary;

	std::vector<double> x_eta_upper_boundary;
	std::vector<double> y_eta_upper_boundary;
	std::vector<double> x_eta_lower_boundary;
	std::vector<double> y_eta_lower_boundary;

	std::vector<std::vector<double>> x;
	std::vector<std::vector<double>> y;

	//mesh quality parameters
	std::vector<std::vector<double>> cell_aspect_ratio;
	std::vector<std::vector<double>> cell_skewness;
	std::vector<std::vector<double>> cell_area;
	
};

struct Grid_Computation_Parameters {

	std::vector<double> xi_upper;
	std::vector<double> xi_lower;
	std::vector<double> eta_left;
	std::vector<double> eta_right;

	std::vector<std::vector<double>> grid_correction_factor;
	std::vector<std::vector<double>> xi;	//x computational domain
	std::vector<std::vector<double>> eta;	//y computational domain

};

#endif
