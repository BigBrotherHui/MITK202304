/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef RefineImageInteractor_h
#define RefineImageInteractor_h

#include <mitkDataInteractor.h>
#include <itkIndex.h>

#include "MitkRefineModuleExports.h"

// See ExampleImageFilter.h for details on typical class declarations
// in MITK. The actual functionality of this class is commented in its
// implementation file.

class MITKREFINEMODULE_EXPORT RefineImageInteractor final : public mitk::DataInteractor
{
public:
  mitkClassMacro(RefineImageInteractor, DataInteractor)
  itkFactorylessNewMacro(Self)

private: 
	RefineImageInteractor();
  ~RefineImageInteractor();

  void ConnectActionsAndFunctions() override;
  void DataNodeChanged() override;

  void Paint(mitk::StateMachineAction* action, mitk::InteractionEvent* event);

  itk::Index<3> m_LastPixelIndex;
};

#endif
