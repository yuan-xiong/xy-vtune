#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/core/ocl.hpp>

void read_opencl_file() {
	//std::cout << "[enter] " << __func__ << std::endl;

    std::string file = "../../src/test_gpu/hello_world.cl";
    std::ifstream ifs(file);
    if(ifs.fail()) {
        std::cout << "Failed to load OpenCL file:\t" << file << std::endl;
        return;
    } else {
        std::cout << "Succeeded to load OpenCL file:\t" << file << std::endl;
	}
}

void test_opencv_opencl() {
	std::cout << "[enter] " << __func__ << std::endl;

	read_opencl_file();
}

int main() {
	for(int i=0; i<100*1000; ++i)
		test_opencv_opencl();

	return 0;
}
