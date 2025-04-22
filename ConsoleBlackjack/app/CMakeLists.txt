set(EXE_SOURCES
	"Main.cpp"
)

set(EXE_HEADERS
	"Main.h"
)

add_executable(${EXECUTABLE_NAME} 
	${EXE_SOURCES}
	${EXE_HEADERS}
)

target_include_directories(${EXECUTABLE_NAME} PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${EXECUTABLE_NAME} 
	${CARDS_LIB_NAME}
	${DISPLAY_LIB_NAME}
	${GAME_LIB_NAME}
)