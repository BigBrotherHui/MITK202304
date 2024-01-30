/*===================================================================

navCAS navigation system

@author: Axel Mancino (axel.mancino@gmail.com)

===================================================================*/

#ifndef SurfaceFilter_h
#define SurfaceFilter_h

#include <mitkCommon.h>
#include <mitkImage.h>
#include <mitkSurface.h>

#include <MitkGraphicsLibExports.h>


class MITKGRAPHICSLIB_EXPORT SurfaceFilter
{

  mitkClassMacroNoParent(SurfaceFilter)
  //itkFactorylessNewMacro(Self)
public:
  SurfaceFilter();
  virtual ~SurfaceFilter();

  inline void SetInputImage(mitk::Image::Pointer im){mInputImage = im;}
  inline void SetThreshold(short th){mThreshold=th;}
  inline mitk::Surface::Pointer GetOutput(){return mOutputSurface;}
  void Update();


private:
  mitk::Image::Pointer                  mInputImage;
  mitk::Surface::Pointer                mOutputSurface;
  short                                 mThreshold;

};

#endif
