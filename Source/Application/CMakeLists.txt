# Copyright Notices: [...]

# ----------- Global Definitions -----------
SET(LIBRARY_NAME ${PROJECT_NAME})

# ------------- Library Setup --------------
FIND_PACKAGE(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Quick QuickControls2)

QT_ADD_EXECUTABLE(${LIBRARY_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/Source/Main.cpp)

QT_ADD_QML_MODULE(${LIBRARY_NAME}
        URI ${LIBRARY_NAME}
        VERSION 1.0
        QML_FILES Source/MainWindow.qml
        NO_PLUGIN
        RESOURCE_PREFIX /
)

TARGET_LINK_LIBRARIES(${LIBRARY_NAME} PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Quick
        Qt${QT_VERSION_MAJOR}::QuickControls2

        UserInterfaceplugin
)

SET_TARGET_PROPERTIES(${LIBRARY_NAME} PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER com.example.${LIBRARY_NAME}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

QT_GENERATE_DEPLOY_QML_APP_SCRIPT(
        TARGET ${LIBRARY_NAME}
        OUTPUT_SCRIPT QT_DEPLOY_SCRIPT
        NO_UNSUPPORTED_PLATFORM_ERROR
        NO_TRANSLATIONS
)
INSTALL(SCRIPT ${QT_DEPLOY_SCRIPT})

ADD_CUSTOM_COMMAND(TARGET ${LIBRARY_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:${LIBRARY_NAME}> $<TARGET_FILE_DIR:${LIBRARY_NAME}>
        COMMAND_EXPAND_LISTS
)