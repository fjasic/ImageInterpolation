
#include "ImageProcessing.h"
#include "ImageInterpolation.h"

#include <QDebug>

void imageProcessingFun(const QString& progName, QImage* const outImgs, const QImage* const inImgs, const QVector<double>& params) 
{
	int X_SIZE = inImgs->width();
	int Y_SIZE = inImgs->height();

	int X_SIZE_NEW;
	int Y_SIZE_NEW;

	/* NOTE: Calculate output image resolution and construct output image object */

	if (progName != "Swirl" && progName != "Swirl Bilinear") {
		X_SIZE_NEW = divisibleByN(X_SIZE * params[1], 4);
		Y_SIZE_NEW = divisibleByN(Y_SIZE * params[0], 4);

		new (outImgs) QImage(X_SIZE_NEW, Y_SIZE_NEW, inImgs->format());
	}
	else {
		new (outImgs) QImage(X_SIZE, Y_SIZE, inImgs->format());
	}

	if(progName == "Sample and hold") 
	{	
		/* Input image data in RGB format can be obtained with inImgs->bits() */
		/* Vertical scale factor is params[0] */
		/* Horizontal scale factor is params[1] */

		/* TO DO: Calculate output image resolution and construct output image object */

		/* TO DO: Perform Sample and hold interpolation  */

		sampleAndHold(inImgs->bits(), X_SIZE, Y_SIZE, outImgs->bits(), X_SIZE_NEW, Y_SIZE_NEW);
	}
	else if (progName == "Bilinear") 
	{
		/* Input image data in RGB format can be obtained with inImgs->bits() */
		/* Vertical scale factor is params[0] */
		/* Horizontal scale factor is params[1] */

		/* TO DO: Calculate output image resolution and construct output image object */

		/* TO DO: Perform Bilinear interpolation  */

		bilinearInterpolate(inImgs->bits(), X_SIZE, Y_SIZE, outImgs->bits(), X_SIZE_NEW, Y_SIZE_NEW);
	}
	else if (progName == "Bicubic")
	{
		/* Input image data in RGB format can be obtained with inImgs->bits() */
		/* Vertical scale factor is params[0] */
		/* Horizontal scale factor is params[1] */

		/* TO DO: Calculate output image resolution and construct output image object */

		/* TO DO: Perform Bilinear interpolation  */

		bicubicInterpolate(inImgs->bits(), X_SIZE, Y_SIZE, outImgs->bits(), X_SIZE_NEW, Y_SIZE_NEW);
	}
	else if(progName == "Swirl") 
	{	
		/* Input image data in RGB format can be obtained with inImgs->bits() */
		/* k1 factor is params[0]*/
		/* Center of rotation coordinates are (XSIZE/2, YSIZE/2) */

		/* TO DO: Construct output image object */

		/* TO DO: Perform image rotation */
	
	}
	else if (progName == "Swirl Bilinear") 
	{
		/* Input image data in RGB format can be obtained with inImgs->bits() */
		/* k1 factor is params[0]*/
		/* Center of rotation coordinates are (XSIZE/2, YSIZE/2) */

		/* TO DO: Construct output image object */

		/* TO DO: Perform image rotation with bilinear interpolation */
	}

}

