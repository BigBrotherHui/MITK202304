/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/

#ifndef mitkOverwriteSliceImageFilter_h_Included
#define mitkOverwriteSliceImageFilter_h_Included

#include "mitkCommon.h"
#include "mitkImageToImageFilter.h"
#include "MitkAlgorithmsExtExports.h"

#include <itkImage.h>

namespace mitk
{
  class MITKALGORITHMSEXT_EXPORT OverwriteSliceImageFilter : public ImageToImageFilter
  {
  public:
    mitkClassMacro(OverwriteSliceImageFilter, ImageToImageFilter);
    itkFactorylessNewMacro(Self) itkCloneMacro(Self)

      
      itkSetMacro(SliceIndex, unsigned int);
    itkGetConstMacro(SliceIndex, unsigned int);

    itkSetMacro(SliceDimension, unsigned int);
    itkGetConstMacro(SliceDimension, unsigned int);

    itkSetMacro(TimeStep, unsigned int);
    itkGetConstMacro(TimeStep, unsigned int);

    itkSetMacro(CreateUndoInformation, bool);
    itkGetConstMacro(CreateUndoInformation, bool);

    itkSetObjectMacro(SliceImage, Image);
    const Image *GetSliceImage() { return m_SliceImage.GetPointer(); }
    const Image *GetLastDifferenceImage() { return m_SliceDifferenceImage.GetPointer(); }
  protected:
    OverwriteSliceImageFilter(); // purposely hidden
    virtual ~OverwriteSliceImageFilter();

    virtual void GenerateData() override;

    template <typename TPixel, unsigned int VImageDimension>
    void ItkImageSwitch(itk::Image<TPixel, VImageDimension> *image);

    template <typename TPixel1, unsigned int VImageDimension1, typename TPixel2, unsigned int VImageDimension2>
    void ItkImageProcessing(const itk::Image<TPixel1, VImageDimension1> *itkImage1,
                            itk::Image<TPixel2, VImageDimension2> *itkImage2);

    std::string EventDescription(unsigned int sliceDimension, unsigned int sliceIndex, unsigned int timeStep);

    Image::ConstPointer m_SliceImage;
    Image::Pointer m_SliceDifferenceImage;

    unsigned int m_SliceIndex;
    unsigned int m_SliceDimension;
    unsigned int m_TimeStep;
    unsigned int m_Dimension0;
    unsigned int m_Dimension1;

    bool m_CreateUndoInformation;
  };

} // namespace

#endif
