#include <hpx/hpx_init.hpp>
#include <hpx/hpx.hpp>
#include <iostream>

// Define a plain action

static void square(double a ){

std::cout << a * a << std::endl;

}

// Define a component

struct data_server
  : hpx::components::component_base<data_server>{

data_server(size_t size){

this->size = size;
data = std::shared_ptr<double[]>(new double[size]);

for(size_t i = 0 ; i < size ; i++)
	
	data.get()[i] = i ;

}

// Define the function to access the data
double* getData(){

	return data.get();

}

// Define the action for remote access
HPX_DEFINE_COMPONENT_DIRECT_ACTION(data_server,
                     getData, getData_action);

size_t getSize(){

	return size;
}


// Define the action for remote access
HPX_DEFINE_COMPONENT_DIRECT_ACTION(data_server,
		     getSize, getSize_action);

private: 

std::shared_ptr<double[]> data;

size_t size;

};





HPX_PLAIN_ACTION(square, square_action);

int main(){

// Generate the component

data_server server = data_server(10);

double * local_data = server.getData();

for(size_t i = 0; i < server.getSize(); i++)
	std::cout << local_data[i] << std::endl;


// Call the function
square(10);


return EXIT_SUCCESS;

}

