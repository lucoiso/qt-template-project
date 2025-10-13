# Copyright Notices: [...]

# ----------- Global Definitions -----------
INCLUDE(GNUInstallDirs)


# -------------- Directories ---------------
ADD_SUBDIRECTORY(Core)
ADD_SUBDIRECTORY(Modules)

IF ($ENV{BUILD_TESTS})
    ADD_SUBDIRECTORY(Tests)
ENDIF ($ENV{BUILD_TESTS})