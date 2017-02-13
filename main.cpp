#include "global.hpp"
#include "pre_process/initialization.hpp"
#include "pre_process/airfoil.hpp"
#include "o_grid/o_grid_main.hpp"
#include "c_grid/c_grid_main.hpp"

int main() {
	Parameters pars;
	Airfoil_Parameters airfoil_pars;

	Initialization init(pars);
	Airfoil airfoil(pars, airfoil_pars);

	//calculate the grid depends on the input.
	//grid_type = 0 -> O grid; grid_type = 1 -> C grid.
	if (pars.grid_type == 0) {

		O_Grid_Main o_grid(airfoil_pars, pars);
	
	} else if (pars.grid_type == 1) {
	
	} else {
		std::cout << "grid type is wrong, please change grid type and run again.";
	}
	


}
