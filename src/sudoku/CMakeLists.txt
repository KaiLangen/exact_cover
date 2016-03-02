add_library (sudoku sudoku.cpp)

install (FILES sudoku.h DESTINATION include)
install (TARGETS sudoku DESTINATION lib)

add_executable(sudoku_exe main.cpp)
target_link_libraries(sudoku_exe sudoku)
