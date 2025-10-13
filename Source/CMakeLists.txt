# Copyright Notices: [...]

# ----------- Global Definitions -----------
INCLUDE(GNUInstallDirs)


# -------------- Directories ---------------
ADD_SUBDIRECTORY(Main)
ADD_SUBDIRECTORY(Application)
ADD_SUBDIRECTORY(UserInterface)
ADD_SUBDIRECTORY(TemplateLibrary)

IF ($ENV{BUILD_TESTS})
    # ADD_SUBDIRECTORY(Tests) TODO : Catch2 & Google Benchmark were removed. Re-Add using Qt.
ENDIF ($ENV{BUILD_TESTS})