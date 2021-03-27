add_executable(test-${PROJECT_NAME}-cpu test_cpu/main.cpp)
target_link_libraries(test-${PROJECT_NAME}-cpu ${OpenCV_LIBS})

add_executable(test-${PROJECT_NAME}-gpu test_gpu/main.cpp)
target_link_libraries(test-${PROJECT_NAME}-gpu ${OpenCV_LIBS})

add_executable(test-${PROJECT_NAME}-builtin_return_address test_builtin_return_address/main.cpp)
