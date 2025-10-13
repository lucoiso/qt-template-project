# Copyright Notices: [...]

# ----------- Global Definitions -----------
SET(LIBRARY_NAME Application)


# ------------- Configuration --------------
LU_ADD_QML_LIBRARY(TARGET ${LIBRARY_NAME}
        TYPE SHARED
        QT_COMPONENTS
            Core
            Gui
            Quick
            QuickControls2
        LINK_LIBRARIES
            UserInterfaceplugin
)