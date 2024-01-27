mitk_create_module(Interactors
  INCLUDE_DIRS PRIVATE src
  DEPENDS PUBLIC MitkCore MitkGraphicsLib
  PACKAGE_DEPENDS VTK ITK Qt5|Core
  WARNINGS_NO_ERRORS
)
