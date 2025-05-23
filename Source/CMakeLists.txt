# Copyright Notices: [...]

# -------------- Directories ---------------
ADD_SUBDIRECTORY(Application)
ADD_SUBDIRECTORY(UserInterface)
ADD_SUBDIRECTORY(TemplateLibrary)

IF ($ENV{BUILD_TESTS})
    ADD_SUBDIRECTORY(Tests)
ENDIF ($ENV{BUILD_TESTS})