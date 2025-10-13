# Copyright Notices: [...]

# ----------- Global Definitions -----------
SET(LIBRARY_NAME ${PROJECT_NAME})


# ------------- Configuration --------------
LU_ADD_EXECUTABLE(TARGET ${LIBRARY_NAME}
    LINK_LIBRARIES Application
)