# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD			23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS		OFF)
set(CMAKE_CXX_FLAGS             "/utf-8")

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    string(CONCAT CMAKE_MSVC_DEBUG_INFORMATION_FORMAT
        "$<IF:"
            "$<AND:"
                "$<C_COMPILER_ID:MSVC>,"
                "$<CXX_COMPILER_ID:MSVC>"
            ">,"
            "$<"
                "$<CONFIG:"
                    "Debug,"
                    "RelWithDebInfo"
                ">:EditAndContinue>,"
            "$<"
                "$<CONFIG:"
                    "Debug,"
                    "RelWithDebInfo"
                ">:ProgramDatabase"
            ">"
        ">"
    )
endif()

option(ENABLE_TESTS
    "Enable testing framework"
    OFF
)

option(ENABLE_DOCS
    "Enable documentation generation with Doxygen"
    ON
)

set(PROJ_DESC "\
A Game of Blackjack playable in the console. This project is also meant to be \
a means of practicing some programming fundamentals - specifically the use of \
the C++ Standard Library and the management of projects with CMake.\
")

project("ConsoleBlackjack" 
	VERSION 0.0.0 
	DESCRIPTION "${PROJ_DESC}"
	LANGUAGES CXX
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/${CMAKE_PROJECT_NAME}/cmake/")
include(docs)

# Include sub-projects.
add_subdirectory ("${CMAKE_PROJECT_NAME}")

if(ENABLE_DOCS)
	generate_docs()
endif()

message(STATUS "ENABLE_DOCS : ${ENABLE_DOCS}")
