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
    int input = 100;

	//cv::UMat umat(512, 512, CV_32FC3, cv::Scalar(1.0f));
	cv::UMat umat(360, 480, CV_32FC3, cv::Scalar(1.0f));

	// no cv setTo
	//cv::UMat umat(360, 480, CV_32FC3);

#if 0
    std::string source((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    cv::ocl::ProgramSource programSource(source.c_str());

    cv::ocl::Program program;
    std::string buildOption = cv::format("-D TIMES=%d", 1000);
    std::string errmsg;
    program.create(programSource, buildOption, errmsg);

	cv::ocl::Kernel kernel("hello_world" ,program);
    kernel.set(0, input);
    kernel.set(1, umat);

    //size_t global_size[] = {8, 8};
    //size_t local_size[]  = {4, 2};
    size_t global_size[] = {64, 64};
    size_t local_size[]  = {8, 16};
    bool success = kernel.run(2, global_size, local_size, true);
    //bool success = kernel.run(2, global_size, local_size, false);
    if(success) {
        std::cout << "Running OpenCL kernel successfully." << std::endl;
    } else {
        std::cout << "Running OpenCL kernel failed." << std::endl;
    }
#endif
}

void test_opencv_opencl() {
	std::cout << "[enter] " << __func__ << std::endl;

	read_opencl_file();
}

int main() {
	//for(int i=0; i<100*1000; ++i)
		test_opencv_opencl();

	return 0;
}
