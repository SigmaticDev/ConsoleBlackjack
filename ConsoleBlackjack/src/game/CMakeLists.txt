set(LIBRARY_SOURCES
	"Player.cpp"
)

set(LIBRARY_HEADERS
	"Player.h"
)

add_library(${GAME_LIB_NAME} STATIC
	${LIBRARY_SOURCES}
	${LIBRARY_HEADERS}
)

target_include_directories(${GAME_LIB_NAME} PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}"
)