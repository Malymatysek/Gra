make_minimum_required(VERSION 3.1)

project(ZadaniePraca)

set(CMAKE_CXX_STANDARD 11)

# Dodaj Google Test
# add_subdirectory(/path/to/googletest)
add_subdirectory(${CMAKE_SOURCE_DIR}/include/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Dodaj źródła i testy
add_executable(runTests_Lottery tests/Test_Lottery.cpp Lottery.cpp Lottery.h)

# add_executable(runTests_LogicGame tests/Test_LogicGame.cpp src/LogicGame.cpp )

# add_executable(runTests_Game tests/Test_Game.cpp src/Game.cpp )

# Linkowanie z Google Test
target_link_libraries(runTests_Lottery gtest gtest_main)
# target_link_libraries(runTests_LogicGame gtest gtest_main)
# target_link_libraries(runTests_Game gtest gtest_main)