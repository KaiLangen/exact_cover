#Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(queens_tests nq_test.cpp)
target_link_libraries(queens_tests nqueens ${GTEST_LIBRARIES} pthread)

add_test(nqueens queens_tests)
