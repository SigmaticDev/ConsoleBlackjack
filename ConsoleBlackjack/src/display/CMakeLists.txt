set(LIBRARY_SOURCES
	"ConsoleColor.cpp"
	"StyledChar.cpp"
	"CharMap.cpp")

set(LIBRARY_HEADERS
	"ConsoleColor.h"
	"StyledChar.h"
	"CharMap.h")

add_library(${DISPLAY_LIB_NAME} STATIC
	${LIBRARY_SOURCES}
	${LIBRARY_HEADERS}
)

target_include_directories(${DISPLAY_LIB_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)