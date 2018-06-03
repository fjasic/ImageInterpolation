#include "ImageProcessing.h"
#include "ColorSpaces.h"
#include "ImageFilter.h"
#include "NoiseReduction.h"
#include "ImageInterpolation.h"
#include <math.h>

#include <QDebug>

int round_by(int x, int y) {
	return (x + y - 1) & ~(y - 1);
}

void imageProcessingFun(const QString& progName, QImage* const outImgs, const QImage* const inImgs, const QVector<double>& params) 
{
	int X_SIZE = inImgs->width();
	int Y_SIZE = inImgs->height();

	/* NOTE: Calculate output image resolution and construct output image object */

	if(progName == "Sample and hold") 
	{	
		/* Input image data in RGB format can be obtained with inImgs->bits() */
		/* Vertical scale factor is params[0] */
		/* Horizontal scale factor is params[1] */

		/* TO DO: Calculate output image resolution and construct output image object */

		/* TO DO: Perform Sample and hold interpolation  */
		double vertical_factor = params[0], horizontal_factor = params[1];
		int newX_SIZE = round_by(horizontal_factor * X_SIZE , 4);
		int newY_SIZE = round_by(vertical_factor * Y_SIZE , 4);

		/* Create empty output image */
		*outImgs = *(new QImage(newX_SIZE, newY_SIZE, inImgs->format()));

		sampleAndHold(inImgs->bits() , X_SIZE , Y_SIZE , outImgs->bits() , newX_SIZE , newY_SIZE);


	}
	else if (progName == "Bilinear") 
	{
		/* Input image data in RGB format can be obtained with inImgs->bits() */
		/* Vertical scale factor is params[0] */
		/* Horizontal scale factor is params[1] */

		/* TO DO: Calculate output image resolution and construct output image object */

		/* TO DO: Perform Bilinear interpolation  */
		double vertical_factor = params[0], horizontal_factor = params[1];
		int newX_SIZE = round_by(horizontal_factor * X_SIZE, 4);
		int newY_SIZE = round_by(vertical_factor * Y_SIZE, 4);

		/* Create empty output image */
		*outImgs = *(new QImage(newX_SIZE, newY_SIZE, inImgs->format()));

		/* Perform Bilinear interpolation  */
		bilinearInterpolate(inImgs->bits(), X_SIZE, Y_SIZE, outImgs->bits(), newX_SIZE, newY_SIZE);
	}

	else if (progName == "Bicubic")
	{
		double vertical_factor = params[0], horizontal_factor = params[1];
		int newX_SIZE = round_by(horizontal_factor * X_SIZE, 4);
		int newY_SIZE = round_by(vertical_factor * Y_SIZE, 4);

		/* Create empty output image */
		*outImgs = *(new QImage(newX_SIZE, newY_SIZE, inImgs->format())); 

		/* Perform Bicubic interpolation  */
		bicubicInterpolate(inImgs->bits(), X_SIZE, Y_SIZE, outImgs->bits(), newX_SIZE, newY_SIZE);
	}
		
	else if(progName == "Transform") 
	{	
		/* Input image data in RGB format can be obtained with inImgs->bits() */
		/* k1 and k2 parameters are given as params[0] and params[1]*/

		/* TO DO: Construct output image object */
		*outImgs = *(new QImage(X_SIZE, Y_SIZE, inImgs->format()));
		/* TO DO: Perform image transformation */
		imageTransform(inImgs->bits(), X_SIZE, Y_SIZE, outImgs->bits(), params[0],params[1]);
	}
	else if (progName == "Transform Bilinear") 
	{
		/* Input image data in RGB format can be obtained with inImgs->bits() */
		/* k1 and k2 parameters are given as params[0] and params[1]*/
		
		/* TO DO: Construct output image object */
		*outImgs = *(new QImage(X_SIZE, Y_SIZE, inImgs->format()));
		/* TO DO: Perform image transformation with bilinear interpolation */
		imageTransformBilinear(inImgs->bits(), X_SIZE, Y_SIZE, outImgs->bits(), params[0],params[1]);

	}

}

