add_library (nqueens n_queens.cpp)

install (FILES n_queens.h DESTINATION include)
install (TARGETS nqueens DESTINATION lib)

add_executable(queens_exe main.cpp)
target_link_libraries(queens_exe nqueens)
