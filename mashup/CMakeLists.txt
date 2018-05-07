cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(SOURCES sim.cpp I_direction.cpp I_drop.cpp I_flip.cpp I_mark.cpp I_unmark.cpp I_move.cpp I_pickup.cpp I_sense.cpp I_turn.cpp program.cpp Cell.cpp world.cpp bug.cpp exception.cpp tokenizer.cpp adjacent_cell.cpp checkforbugs.cpp marker.cpp assembler.cpp)

add_executable(my_project_executable ${SOURCES}) 

