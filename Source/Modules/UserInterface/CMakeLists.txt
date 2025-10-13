# Copyright Notices: [...]

# ----------- Global Definitions -----------
SET(LIBRARY_NAME UserInterface)


# ------------- Configuration --------------
LU_ADD_QML_LIBRARY(TARGET ${LIBRARY_NAME}
        TYPE STATIC
        QT_COMPONENTS
            Core
            Qml
        LINK_LIBRARIES
            TemplateLibrary
        QML_CPP_SUBDIR
            Components
)