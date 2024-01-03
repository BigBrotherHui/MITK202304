/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef THA3DIMAGEGENERATOR_H
#define THA3DIMAGEGENERATOR_H

#include <mitkImageToImageFilter.h>

// The following header file is generated by CMake and thus it's located in
// the build directory. It provides an export macro for classes and functions
// that you want to be part of the public interface of your module.
#include <MitkLancetIGTExports.h>

#include "mitkDataNode.h"
#include "mitkPointSet.h"
#include "mitkSurface.h"

namespace lancet
{
	/**Documentation
	  * \brief 
	  *
	  * \ingroup IGT
	  */
	class MITKLANCETIGT_EXPORT Tha3DImageGenerator : public itk::DataObject
	{

		// The purpose of this object is to generate a 3D mitk::Image for DRR generation.
		// This 3D image is synthesized with the following components:
		// - the image of pure pelvis
		// - the image of pure right femur
		// - the image of pure left femur
		// - the surface of the cup
		// - the surface of the liner
		// - the surface of the stem
		// - the surface of the ballhead

	public:
		mitkClassMacroItkParent(Tha3DImageGenerator, itk::DataObject);
		itkFactorylessNewMacro(Self)
		itkCloneMacro(Self)

			itkSetMacro(PelvisImage, mitk::Image::Pointer)
			itkGetMacro(PelvisImage, mitk::Image::Pointer)
			itkSetMacro(FemurImage_R, mitk::Image::Pointer)
			itkGetMacro(FemurImage_R, mitk::Image::Pointer)
			itkSetMacro(FemurImage_L, mitk::Image::Pointer)
			itkGetMacro(FemurImage_L, mitk::Image::Pointer)

			itkGetMacro(CupSurface, mitk::Surface::Pointer)
			itkSetMacro(CupSurface, mitk::Surface::Pointer)
			itkGetMacro(LinerSurface, mitk::Surface::Pointer)
			itkSetMacro(LinerSurface, mitk::Surface::Pointer)
			itkGetMacro(StemSurface, mitk::Surface::Pointer)
			itkSetMacro(StemSurface, mitk::Surface::Pointer)
			itkGetMacro(BallHeadSurface, mitk::Surface::Pointer)
			itkSetMacro(BallHeadSurface, mitk::Surface::Pointer)

		mitk::Image::Pointer m_PelvisImage;
		mitk::Image::Pointer m_FemurImage_R;
		mitk::Image::Pointer m_FemurImage_L;
		mitk::Surface::Pointer  m_CupSurface;
		mitk::Surface::Pointer  m_LinerSurface;
		mitk::Surface::Pointer  m_StemSurface;
		mitk::Surface::Pointer  m_BallHeadSurface;

		mitk::Image::Pointer Generate3Dimage();

	protected:
		Tha3DImageGenerator();
		Tha3DImageGenerator(const Tha3DImageGenerator& other);
		~Tha3DImageGenerator() override;

		/*
		 * Generate an image that is the same size as the bounding box of the inputSurface, 
		 * the inside-surface voxel value is StencilValue,
		 * the outside-surface voxel value is 0
		 */
		mitk::Image::Pointer GetStenciledImage(mitk::Surface::Pointer inputSurface, short StencilValue);

		/*
		 * Generate a new image based on the input,
		 * the voxel value outside the 2 thresholds are set as 0
		 * 2 filters applied in the function: thresholdFilter and multiplyFilter
		 */
		mitk::Image::Pointer GetThresholdedImage(mitk::Image::Pointer inputImage, int lowerBound, int upperBound);

		/*
		 * Generate a new image by adding the smaller image to the larger image
		 * 2 filters applied in the function: resampleFilter & addFilter
		 */
		mitk::Image::Pointer AddImage(mitk::Image::Pointer largerImage, mitk::Image::Pointer smallerImage);

		mitk::Image::Pointer AddSameSizeImage(mitk::Image::Pointer image_0, mitk::Image::Pointer image_1);

		bool GetImapntsAvailablity();

		bool GetBoneAvailablity();

	};
}

#endif
