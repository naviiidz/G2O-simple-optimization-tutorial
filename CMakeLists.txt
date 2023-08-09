add_executable(simple_optimize
  simple_optimize.cpp
)
add_executable(test
  test.cpp
)


set_target_properties(simple_optimize PROPERTIES OUTPUT_NAME simple_optimize)
set_target_properties(test PROPERTIES OUTPUT_NAME test)

target_link_libraries(simple_optimize core solver_eigen)
target_link_libraries(simple_optimize types_slam2d)
target_link_libraries(simple_optimize types_slam3d)

target_link_libraries(test core solver_eigen)
target_link_libraries(test types_slam2d)
target_link_libraries(test types_slam3d)
