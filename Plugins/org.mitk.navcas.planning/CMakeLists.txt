project(org_mitk_navcas_planning)

mitk_create_plugin(
  EXPORT_DIRECTIVE PLANNING_EXPORTS
  EXPORTED_INCLUDE_SUFFIXES src
  MODULE_DEPENDS PRIVATE MitkQtWidgetsExt MitkGizmo MitkSegmentation MitkGraphicsLib MitkNodesManager MitkInteractors MitkCASWidgets
  PACKAGE_DEPENDS Qt5|Sql
)
