set(LIBRARY_SOURCES
	"Player.cpp"
	"ScorerImpl.cpp"
	"ScorerInterface.cpp"
)

set(LIBRARY_HEADERS
	"Player.h"
	"ScorerImpl.h"
	"ScorerInterface.h"
)

add_library(${GAME_LIB_NAME} STATIC
	${LIBRARY_SOURCES}
	${LIBRARY_HEADERS}
)

target_include_directories(${GAME_LIB_NAME} PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(${GAME_LIB_NAME} PUBLIC
	${CARDS_LIB_NAME}
)