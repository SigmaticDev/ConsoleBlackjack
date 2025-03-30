set(LIBRARY_SOURCES
	"Card.cpp"
	"Deck.cpp"
	"Hand.cpp"
)

set(LIBRARY_HEADERS
	"Card.h"
	"Deck.h"
	"Hand.h"
)

add_library(${CARDS_LIB_NAME} STATIC
	${LIBRARY_SOURCES}
	${LIBRARY_HEADERS}
)

target_include_directories(${CARDS_LIB_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)