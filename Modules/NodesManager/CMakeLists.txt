mitk_create_module(NodesManager
  DEPENDS PUBLIC MitkCore MitkIGT MitkCASLib MitkGraphicsLib
  PACKAGE_DEPENDS VTK ITK Qt5|Core+Sql
  WARNINGS_NO_ERRORS
)

add_subdirectory(test)
