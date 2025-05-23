# Copyright Notices: [...]

# ----------- Global Definitions -----------
SET(LIBRARY_NAME ApplicationUnit)

# ------------- Library Setup --------------
SET(PRIVATE_MODULES_BASE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Source)
SET(PUBLIC_MODULES_BASE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Include/${LIBRARY_NAME})

FILE(GLOB_RECURSE PRIVATE_MODULES "${PRIVATE_MODULES_BASE_DIRECTORY}/*.cpp")
FILE(GLOB_RECURSE PUBLIC_MODULES "${PUBLIC_MODULES_BASE_DIRECTORY}/*.hpp")

ADD_EXECUTABLE(${LIBRARY_NAME} ${PRIVATE_MODULES} ${PUBLIC_MODULES})
SET_TARGET_PROPERTIES(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)

TARGET_INCLUDE_DIRECTORIES(${LIBRARY_NAME} PRIVATE
        ${PRIVATE_MODULES_BASE_DIRECTORY}
        ${PUBLIC_MODULES_BASE_DIRECTORY}
)

TARGET_COMPILE_DEFINITIONS(${LIBRARY_NAME} PRIVATE BUILD_DLL)

FIND_PACKAGE(Catch2 REQUIRED CONFIG)
FIND_PACKAGE(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Quick QuickControls2)

TARGET_LINK_LIBRARIES(${LIBRARY_NAME} PUBLIC
        Catch2::Catch2WithMain

        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Quick
        Qt${QT_VERSION_MAJOR}::QuickControls2
        
        UserInterfaceplugin
)

ADD_CUSTOM_COMMAND(TARGET ${LIBRARY_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:${LIBRARY_NAME}> $<TARGET_FILE_DIR:${LIBRARY_NAME}>
        COMMAND_EXPAND_LISTS
)