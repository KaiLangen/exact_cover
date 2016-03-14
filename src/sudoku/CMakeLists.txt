add_library (sudoku eraser.cpp generator.cpp solver.cpp)

install (FILES eraser.h generator.h solver.h DESTINATION include)
install (TARGETS sudoku DESTINATION lib)

add_executable(sudoku_exe main.cpp)
target_link_libraries(sudoku_exe sudoku)
