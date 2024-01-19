# Copyright Notices: [...]

# ----------- Global Definitions -----------
SET(LIBRARY_NAME UserInterface)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

# ---------------- Qt Setup ----------------
FIND_PACKAGE(Qt6 REQUIRED COMPONENTS Qml)

SET(QML_FILES
        MainWindow.qml
)

QT_ADD_LIBRARY(${LIBRARY_NAME} STATIC)

QT_ADD_QML_MODULE(${LIBRARY_NAME}
        URI ${LIBRARY_NAME}
        VERSION 1.0
        QML_FILES ${QML_FILES}
        RESOURCE_PREFIX /
)

TARGET_LINK_LIBRARIES(${LIBRARY_NAME} PRIVATE
        Qt6::Qml
)
