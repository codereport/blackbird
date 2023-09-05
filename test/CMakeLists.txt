set(EXE "test_exe")
add_executable(${EXE} test.cpp)
target_link_libraries(${EXE} PRIVATE blackbird)
