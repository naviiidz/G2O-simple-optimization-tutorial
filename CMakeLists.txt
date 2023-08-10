cmake_minimum_required(VERSION 3.5)
project(g2o_handson)

# Set OpenGL preference to suppress the warning
set(OpenGL_GL_PREFERENCE "GLVND")

# Point CMake to the directory containing the installed g2oConfig.cmake
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/cmake/g2o")

# Find g2o using the provided config file
find_package(g2o CONFIG REQUIRED)

# Add your executables
add_executable(simple_optimize simple_optimize.cpp)
add_executable(test test.cpp)

# Set output names
set_target_properties(simple_optimize PROPERTIES OUTPUT_NAME simple_optimize)
set_target_properties(test PROPERTIES OUTPUT_NAME test)

# Link against g2o libraries for simple_optimize
target_link_libraries(simple_optimize 
    g2o::core 
    g2o::solver_eigen 
    g2o::types_slam2d
    g2o::types_slam3d
    # ... add other necessary g2o targets if needed
)

# Link against g2o libraries for test
target_link_libraries(test 
    g2o::core 
    g2o::solver_eigen 
    g2o::types_slam2d
    g2o::types_slam3d
    # ... add other necessary g2o targets if needed
)
