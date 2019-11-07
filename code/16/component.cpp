#include <hpx/hpx.hpp>
#include <iostream>
#include<hpx/hpx_main.hpp>

// Define a plain action

static void square(double a ){

std::cout << a * a << std::endl;

}

// Define
HPX_PLAIN_ACTION(square, square_action);

// Define a component

struct data_server
  : hpx::components::component_base<data_server>{

data_server(size_t size){

this->size = size;
this->data = std::shared_ptr<double[]>(new double[size]);

for(size_t i = 0 ; i < size ; i++)
	
	data.get()[i] = i ;
}

// Define the function to access the data

hpx::serialization::serialize_buffer<double> getData(){

   return hpx::serialization::serialize_buffer<double>(
      data.get(), size,
      hpx::serialization::serialize_buffer<double>::init_mode::reference);

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

// Registering the component
typedef hpx::components::component<data_server> 
    data_server_type;
HPX_REGISTER_COMPONENT(data_server_type, 
    data_server);
    
// Registering the component actions
typedef data_server::getData_action getData_action;
HPX_REGISTER_ACTION(getData_action);


typedef data_server::getSize_action getSize_action;
HPX_REGISTER_ACTION(getSize_action);


struct data
	: hpx::components::client_base<data,data_server>
{
	typedef hpx::components::client_base<data, data_server> base_type; 
	
       
	data(hpx::naming::id_type where,std::size_t size) : 
		 base_type(hpx::new_<data_server>(where,size)){}

	hpx::future<size_t> getSize(){

		return hpx::async(getSize_action(),get_id());
	}

	hpx::future<hpx::serialization::serialize_buffer<double>> getData(){

		return hpx::async(getData_action(),get_id());
	}
};

int main(){

// Generate the component
std::size_t size = 10;
data data_client = data(hpx::find_here(),10);


double * local_data = data_client.getData().get().data();

for(size_t i = 0; i < size; i++)
	std::cout << local_data[i] << std::endl;

// Call the function
square(10);


return EXIT_SUCCESS;

}

