function(generate_docs)
    find_package(Doxygen REQUIRED 
        OPTIONAL_COMPONENTS dot
    )

    set(PKG_FOUND_MSG_1 "The package Doxygen")
    set(PKG_FOUND_MSG_2 " has been ")
    set(PKG_FOUND_MSG_3 "found! Generating Documentation...")

    set(DOXYGEN_HAVE_DOT "NO")
    set(DOT_EXECUTABLE "")

    if(TARGET Doxygen::dot)
        set(PKG_FOUND_MSG_1 "The packages Doxygen")
        set(PKG_FOUND_MSG_2 " and Dot have been ")
        set(DOXYGEN_HAVE_DOT "YES")
        get_target_property(DOT_EXECUTABLE Doxygen::dot IMPORTED_LOCATION)
    endif()

    string(CONCAT PKG_FOUND_MSG
        "${PKG_FOUND_MSG_1}"
        "${PKG_FOUND_MSG_2}"
        "${PKG_FOUND_MSG_3}"
    )

    message(STATUS "${PKG_FOUND_MSG}")

    set(DOCS_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/docs/")

    set(PROJ_LOGO_PATH
        "${CMAKE_SOURCE_DIR}/${CMAKE_PROJECT_NAME}/res/${CMAKE_PROJECT_NAME}Logo.png"
    )

    set(PROJ_ICON_PATH
        "${CMAKE_SOURCE_DIR}/${CMAKE_PROJECT_NAME}/res/${CMAKE_PROJECT_NAME}Icon.png"
    )

    set(DOCS_INPUT_DIR
        "${CMAKE_SOURCE_DIR}/${CMAKE_PROJECT_NAME}"
    )

    message(STATUS "Configuring Doxyfile input...")

    set(DOXYFILE_IN "${DOCS_INPUT_DIR}/docs/Doxyfile.in")
    set(DOXYFILE_OUT "${CMAKE_SOURCE_DIR}/docs/Doxyfile")

    configure_file(
        "${DOXYFILE_IN}"
        "${DOXYFILE_OUT}"
    )

    get_target_property(DOXYGEN_EXECUTABLE Doxygen::doxygen IMPORTED_LOCATION)

    add_custom_target(docs
        COMMAND ${CMAKE_COMMAND} -E rm -rf "${DOCS_OUTPUT_DIR}/html"
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
        COMMENT "Generating documentation!"
    )
    
endfunction(generate_docs)