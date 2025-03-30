# CMakeList.txt : CMake project for ConsoleBlackjack, include source and define
# project specific logic here.
#

set(EXECUTABLE_NAME  "ConsoleBlackjack")
set(CARDS_LIB_NAME	 "CBJCards")
set(DISPLAY_LIB_NAME "CBJDisplay")
set(GAME_LIB_NAME	 "CBJGame")

add_subdirectory("src")
add_subdirectory("app")

# TODO: Add tests and install targets if needed.
