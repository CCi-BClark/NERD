
if (CMAKE_VERSION VERSION_LESS 2.8.3)
    message(FATAL_ERROR "Qt 5 requires at least CMake version 2.8.3")
endif()

get_filename_component(_qt5QSystemHotkey_install_prefix "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

# For backwards compatibility only. Use Qt5QSystemHotkey_VERSION instead.
set(Qt5QSystemHotkey_VERSION_STRING 0.1.0)

set(Qt5QSystemHotkey_LIBRARIES Qt5::QSystemHotkey)

macro(_qt5_QSystemHotkey_check_file_exists file)
    if(NOT EXISTS "${file}" )
        message(FATAL_ERROR "The imported target \"Qt5::QSystemHotkey\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
endmacro()


macro(_populate_QSystemHotkey_target_properties Configuration LIB_LOCATION IMPLIB_LOCATION)
    set_property(TARGET Qt5::QSystemHotkey APPEND PROPERTY IMPORTED_CONFIGURATIONS ${Configuration})

    set(imported_location "${_qt5QSystemHotkey_install_prefix}/lib/${LIB_LOCATION}")
    _qt5_QSystemHotkey_check_file_exists(${imported_location})
    set_target_properties(Qt5::QSystemHotkey PROPERTIES
        "IMPORTED_LINK_INTERFACE_LIBRARIES_${Configuration}" "${_Qt5QSystemHotkey_LIB_DEPENDENCIES}"
        "IMPORTED_LOCATION_${Configuration}" ${imported_location}
    )

    set(imported_implib "${_qt5QSystemHotkey_install_prefix}/lib/${IMPLIB_LOCATION}")
    _qt5_QSystemHotkey_check_file_exists(${imported_implib})
    if(NOT "${IMPLIB_LOCATION}" STREQUAL "")
        set_target_properties(Qt5::QSystemHotkey PROPERTIES
        "IMPORTED_IMPLIB_${Configuration}" ${imported_implib}
        )
    endif()
endmacro()

if (NOT TARGET Qt5::QSystemHotkey)

    set(_Qt5QSystemHotkey_OWN_INCLUDE_DIRS "${_qt5QSystemHotkey_install_prefix}/include/" "${_qt5QSystemHotkey_install_prefix}/include/QSystemHotkey")
    set(Qt5QSystemHotkey_PRIVATE_INCLUDE_DIRS)

    foreach(_dir ${_Qt5QSystemHotkey_OWN_INCLUDE_DIRS})
        _qt5_QSystemHotkey_check_file_exists(${_dir})
    endforeach()

    # Only check existence of private includes if the Private component is
    # specified.
    list(FIND Qt5QSystemHotkey_FIND_COMPONENTS Private _check_private)
    if (NOT _check_private STREQUAL -1)
        foreach(_dir ${Qt5QSystemHotkey_PRIVATE_INCLUDE_DIRS})
            _qt5_QSystemHotkey_check_file_exists(${_dir})
        endforeach()
    endif()

    set(Qt5QSystemHotkey_INCLUDE_DIRS ${_Qt5QSystemHotkey_OWN_INCLUDE_DIRS})

    set(Qt5QSystemHotkey_DEFINITIONS -DQT_SYSTEMHOTKEY_LIB)
    set(Qt5QSystemHotkey_COMPILE_DEFINITIONS QT_SYSTEMHOTKEY_LIB)

    set(_Qt5QSystemHotkey_MODULE_DEPENDENCIES "Gui;Core")

    set(_Qt5QSystemHotkey_FIND_DEPENDENCIES_REQUIRED)
    if (Qt5QSystemHotkey_FIND_REQUIRED)
        set(_Qt5QSystemHotkey_FIND_DEPENDENCIES_REQUIRED REQUIRED)
    endif()
    set(_Qt5QSystemHotkey_FIND_DEPENDENCIES_QUIET)
    if (Qt5QSystemHotkey_FIND_QUIETLY)
        set(_Qt5QSystemHotkey_DEPENDENCIES_FIND_QUIET QUIET)
    endif()
    set(_Qt5QSystemHotkey_FIND_VERSION_EXACT)
    if (Qt5QSystemHotkey_FIND_VERSION_EXACT)
        set(_Qt5QSystemHotkey_FIND_VERSION_EXACT EXACT)
    endif()

    foreach(_module_dep ${_Qt5QSystemHotkey_MODULE_DEPENDENCIES})
        if (NOT Qt5${_module_dep}_FOUND)
            find_package(Qt5${_module_dep}
                0.1.0 ${_Qt5QSystemHotkey_FIND_VERSION_EXACT}
                ${_Qt5QSystemHotkey_DEPENDENCIES_FIND_QUIET}
                ${_Qt5QSystemHotkey_FIND_DEPENDENCIES_REQUIRED}
                PATHS "${CMAKE_CURRENT_LIST_DIR}/.." NO_DEFAULT_PATH
            )
        endif()

        if (NOT Qt5${_module_dep}_FOUND)
            set(Qt5QSystemHotkey_FOUND False)
            return()
        endif()

        list(APPEND Qt5QSystemHotkey_INCLUDE_DIRS "${Qt5${_module_dep}_INCLUDE_DIRS}")
        list(APPEND Qt5QSystemHotkey_PRIVATE_INCLUDE_DIRS "${Qt5${_module_dep}_PRIVATE_INCLUDE_DIRS}")
        list(APPEND Qt5QSystemHotkey_DEFINITIONS ${Qt5${_module_dep}_DEFINITIONS})
        list(APPEND Qt5QSystemHotkey_COMPILE_DEFINITIONS ${Qt5${_module_dep}_COMPILE_DEFINITIONS})
        list(APPEND Qt5QSystemHotkey_EXECUTABLE_COMPILE_FLAGS ${Qt5${_module_dep}_EXECUTABLE_COMPILE_FLAGS})
    endforeach()
    list(REMOVE_DUPLICATES Qt5QSystemHotkey_INCLUDE_DIRS)
    list(REMOVE_DUPLICATES Qt5QSystemHotkey_PRIVATE_INCLUDE_DIRS)
    list(REMOVE_DUPLICATES Qt5QSystemHotkey_DEFINITIONS)
    list(REMOVE_DUPLICATES Qt5QSystemHotkey_COMPILE_DEFINITIONS)
    if (Qt5QSystemHotkey_EXECUTABLE_COMPILE_FLAGS)
        list(REMOVE_DUPLICATES Qt5QSystemHotkey_EXECUTABLE_COMPILE_FLAGS)
    endif()

    set(_Qt5QSystemHotkey_LIB_DEPENDENCIES "Qt5::Gui;Qt5::Core")

    add_library(Qt5::QSystemHotkey SHARED IMPORTED)

    set_property(TARGET Qt5::QSystemHotkey PROPERTY
      INTERFACE_INCLUDE_DIRECTORIES ${_Qt5QSystemHotkey_OWN_INCLUDE_DIRS})
    set_property(TARGET Qt5::QSystemHotkey PROPERTY
      INTERFACE_COMPILE_DEFINITIONS QT_SYSTEMHOTKEY_LIB)

    _populate_QSystemHotkey_target_properties(RELEASE "Qt0QSystemHotkey.dll" "libQt0QSystemHotkey.a" )



    _populate_QSystemHotkey_target_properties(DEBUG "Qt0QSystemHotkeyd.dll" "libQt0QSystemHotkeyd.a" )





_qt5_QSystemHotkey_check_file_exists("${CMAKE_CURRENT_LIST_DIR}/Qt5QSystemHotkeyConfigVersion.cmake")

endif()
