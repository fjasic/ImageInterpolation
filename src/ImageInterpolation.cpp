#include "ImageInterpolation.h"
#include "ImageFilter.h"
#include "ColorSpaces.h"
#include <math.h>
#define PI 3.141592653589793238462643383279502884L

void sampleAndHold(const uchar input[], int xSize, int ySize, uchar output[], int newXSize, int newYSize)
{
	/* DONE */
	uchar R, G, B;
	uchar *R_buff= new uchar[xSize * ySize];
	uchar *G_buff= new uchar[xSize * ySize];
	uchar *B_buff= new uchar[xSize * ySize];

	uchar *R_output= new uchar[xSize * ySize];
	uchar *G_output= new uchar[xSize * ySize];
	uchar *B_output= new uchar[xSize * ySize];

	//Scaling factors
	const double F_horizontal = (double) newXSize / xSize;
	const double F_vertical = (double) newYSize / ySize;

	//Sample and hold algorithm
	for (int i = 0; i < newXSize; i++) {
		for (int j = 0; j < newYSize; j++) {
			R = rgbImg[j*3*x+i*3];
			G = rgbImg[j*3*x+i*3 + 1];
			B = rgbImg[j*3*x+i*3 + 2];

			int ii;
			int jj;

			ii = (i - 1) / F_vertical;
			jj = (j - 1) / F_horizontal;

			if (ii < ySize - 1)
				ii = (i - 1) / F_vertical + 1;

			if (jj < xSize - 1)
				jj = (j - 1) / F_horizontal + 1;

			R_output[j * 3 * newXSize + i] = R*R_buff[jj * 3 *xSize + ii];
			G_output[j * 3 * newXSize + i] = G*G_buff[jj * 3 *xSize + ii];
			B_output[j * 3 * newXSize + i] = B*B_buff[jj * 3 *xSize + ii];

		}
	}

	delete[] R_buff;
	delete[] G_buff;
	delete[] B_buff;
	delete[] R_output;
	delete[] G_output;
	delete[] B_output;
	
}

void bilinearInterpolate(const uchar input[], int xSize, int ySize, uchar output[], int newXSize, int newYSize)
{
	/* DONE */
	uchar R, G, B;
	uchar *R_buff= new uchar[xSize * ySize];
	uchar *G_buff= new uchar[xSize * ySize];
	uchar *B_buff= new uchar[xSize * ySize];

	uchar *R_output= new uchar[xSize * ySize];
	uchar *G_output= new uchar[xSize * ySize];
	uchar *B_output= new uchar[xSize * ySize];

	//Scaling factors
	const double F_horizontal = (double) newXSize / xSize;
	const double F_vertical = (double) newYSize / ySize;

	for (int i = 0; i < newXSize; i++) {				//horizontal
		for (int j = 0; j < newYSize; j++) {			//vertical
			R = rgbImg[j*3*x+i*3];
			G = rgbImg[j*3*x+i*3 + 1];
			B = rgbImg[j*3*x+i*3 + 2];
			double a = i / F_horizontal - floor(i / F_horizontal);
			double b = j / F_vertical - floor(j / F_vertical);

			int ii = i / F_horizontal;
			int jj = j / F_vertical;

			int iii = ii, jjj = jj;
			if (ii < xSize - 1)
				iii = ii + 1;
			if (jj < ySize - 1)
				jjj = jj + 1;

			R_output[j * 3 * newXSize + i] = (1 - a) * (1 - b) * R*R_buff[jj * 3 *xSize + ii] + a * (1 - b) *R*R_buff[jj * 3*xSize + (iii)]
				+ (1 - a) * b *R* R_buff[(jjj) * 3*xSize + ii] + a * b * R*R_buff[(jjj) * 3*xSize + (iii)];

			G_output[j * 3 * newXSize + i] = (1 - a) * (1 - b) * G*G_buff[jj * 3 *xSize + ii] + a * (1 - b) *G*G_buff[jj * 3*xSize + (iii)]
				+ (1 - a) * b *G* G_buff[(jjj) * 3*xSize + ii] + a * b *G* G_buff[(jjj) * 3*xSize + (iii)];

			B_output[j * 3 * newXSize + i] = (1 - a) * (1 - b) * B*B_buff[jj * 3 *xSize + ii] + a * (1 - b) *B*B_buff[jj * 3*xSize + (iii)]
				+ (1 - a) * b *B* B_buff[(jjj) * 3*xSize + ii] + a * b * B*B_buff[(jjj) * 3*xSize + (iii)];
		}
	}

	delete[] R_buff;
	delete[] G_buff;
	delete[] B_buff;
	delete[] R_output;
	delete[] G_output;
	delete[] B_output;
}

/* A help function for bicubic interpolation. Works for unsigned char */
uchar cubicInterpolate(uchar p[4], double x) {
	return p[1] + 0.5 * x*(p[2] - p[0] + x*(2.0*p[0] - 5.0*p[1] + 4.0*p[2] - p[3] + x*(3.0*(p[1] - p[2]) + p[3] - p[0])));
}

/* A help function for bicubic interpolation. Works for signed chars*/
char cubicInterpolate(char p[4], double x) {
	int retVal = p[1] + 0.5 * x*(p[2] - p[0] + x*(2.0*p[0] - 5.0*p[1] + 4.0*p[2] - p[3] + x*(3.0*(p[1] - p[2]) + p[3] - p[0])));

	if (retVal > 127) {
		retVal = 127;
	} else if (retVal < -127) {
		retVal = -127;
	}

	return (char) retVal;
}

void bicubicInterpolate(const uchar input[], int xSize, int ySize, uchar output[], int newXSize, int newYSize)
{
	/* DONE */
	uchar R, G, B;
	uchar *R_buff= new uchar[xSize * ySize];
	uchar *G_buff= new uchar[xSize * ySize];
	uchar *B_buff= new uchar[xSize * ySize];

	uchar *R_output= new uchar[xSize * ySize];
	uchar *G_output= new uchar[xSize * ySize];
	uchar *B_output= new uchar[xSize * ySize];

	//Buffers for single cubic interpolation
	uchar *R_horizontal = new uchar[4];
	uchar *G_horizontal = new uchar[4];
	uchar *B_horizontal = new uchar[4];

	uchar *R_vertical = new uchar[4];
	uchar *G_vertical = new uchar[4];
	uchar *B_vertical = new uchar[4];

	//Scaling factors
	const double F_horizontal = (double)newXSize / xSize;
	const double F_vertical = (double)newYSize / ySize;

	//Extended buffers for correct pixel calculation
	uchar *R_extnd = new uchar[(xSize + 4) * (ySize + 4)];
	uchar *G_extnd = new uchar[(xSize + 4) * (ySize + 4)];
	uchar *B_extnd = new uchar[(xSize + 4) * (ySize + 4)];

	extendBorders(R_buff, xSize, ySize, R_extnd, 2);
	extendBorders(G_buff, xSize, ySize, G_extnd, 2);
	extendBorders(B_buff, xSize, ySize, B_extnd, 2);

	for (int i = 0; i < newYSize; i++) {
		for (int j = 0; j < newXSize; j++) {
			R = rgbImg[i*3*x+j*3];
			G = rgbImg[i*3*x+j*3 + 1];
			B = rgbImg[i*3*x+j*3 + 2];

			double b = i / F_vertical - floor(i / F_vertical);
			double a = j / F_horizontal - floor(j / F_horizontal);

			int new_x = j / F_horizontal;
			int new_y = i / F_vertical;

			int v = 0;
			for (int h = new_y - 1; h < new_y + 3; h++, v++) {
				R_horizontal[0] = R_extnd[h * (xSize + 4) + new_x - 1];
				R_horizontal[1] = R_extnd[h * (xSize + 4) + new_x];
				R_horizontal[2] = R_extnd[h * (xSize + 4) + new_x + 1];
				R_horizontal[3] = R_extnd[h * (xSize + 4) + new_x + 2];

				G_horizontal[0] = G_extnd[h * (xSize + 4) + new_x - 1];
				G_horizontal[1] = G_extnd[h * (xSize + 4) + new_x];
				G_horizontal[2] = G_extnd[h * (xSize + 4) + new_x + 1];
				G_horizontal[3] = G_extnd[h * (xSize + 4) + new_x + 2];

				B_horizontal[0] = B_extnd[h * (xSize + 4) + new_x - 1];
				B_horizontal[1] = B_extnd[h * (xSize + 4) + new_x];
				B_horizontal[2] = B_extnd[h * (xSize + 4) + new_x + 1];
				B_horizontal[3] = B_extnd[h * (xSize + 4) + new_x + 2];

				R_vertical[v] = cubicInterpolate(R_horizontal, a);
				G_vertical[v] = cubicInterpolate(G_horizontal, a);
				B_vertical[v] = cubicInterpolate(B_horizontal, a);

			}

			R_output[i * 3*newXSize + j] = cubicInterpolate(R_vertical, b);
			G_output[i * 3*newXSize + j] = cubicInterpolate(G_vertical, b);
			B_output[i * 3*newXSize + j] = cubicInterpolate(B_vertical, b);

		}
	}

	delete[] R_extnd;
	delete[] G_extnd;
	delete[] B_extnd;

	delete[] R_vertical;
	delete[] G_vertical;
	delete[] B_vertical;

	delete[] R_horizontal;
	delete[] G_horizontal;
	delete[] B_horizontal;

	delete[] R_output;
	delete[] G_output;
	delete[] B_output;	
}
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
void imageTransform(const uchar input[], int xSize, int ySize, uchar output[], double k1, double k2)
{
	/* TO DO */

	uchar R, G, B;
	uchar *R_buff= new uchar[xSize * ySize];
	uchar *G_buff= new uchar[xSize * ySize];
	uchar *B_buff= new uchar[xSize * ySize];

	uchar *R_output= new uchar[xSize * ySize];
	uchar *G_output= new uchar[xSize * ySize];
	uchar *B_output= new uchar[xSize * ySize];

	for (int i = 0; i < ySize; i++) {//vertical
		for (int j = 0; j < xSize; j++) {//horizontal
			R = rgbImg[i*3*x+j*3];
			G = rgbImg[i*3*x+j*3 + 1];
			B = rgbImg[i*3*x+j*3 + 2];

			int new_X = (int)(j + k1 * xSize * sin(2* PI* j / (ySize * k2)));

			if (new_X < 0 || new_X > xSize - 1) {
				R_output[i * 3*xSize + j] = 0;
				G_output[i * 3*xSize + j] = 0;
				B_output[i * 3*xSize + j] = 0;

			}
			else {
				R_output[i * 3*xSize + j] = R*R_buff[i * 3*xSize + new_X];
				G_output[i * 3*xSize + j] = G*G_buff[i * 3*xSize + new_X];
				B_output[i * 3*xSize + j] = B*B_buff[i * 3*xSize + new_X];

			}
		}
	}
	
	delete[] R_buff;
	delete[] G_buff;
	delete[] B_buff;
	delete[] R_output;
	delete[] G_output;
	delete[] B_output;
}
}

void imageTransformBilinear(const uchar input[], int xSize, int ySize, uchar output[], double k1, double k2)
{
	/* TO DO */
	uchar R, G, B;
	uchar *R_buff= new uchar[xSize * ySize];
	uchar *G_buff= new uchar[xSize * ySize];
	uchar *B_buff= new uchar[xSize * ySize];

	uchar *R_output= new uchar[xSize * ySize];
	uchar *G_output= new uchar[xSize * ySize];
	uchar *B_output= new uchar[xSize * ySize];

	uchar *R_extnd = new uchar[(xSize + 2) * (ySize + 2)];
	uchar *G_extnd = new uchar[(xSize + 2) * (ySize + 2)];
	uchar *B_extnd = new uchar[(xSize + 2) * (ySize + 2)];

	//Extending borders for exgde portection
	extendBorders(R_buff, xSize, ySize, R_extnd, 1);
	extendBorders(G_buff, xSize, ySize, G_extnd, 1);
	extendBorders(B_buff, xSize, ySize, B_extnd, 1);


	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			
			double new_X = (j + k1 * xSize * sin(2* PI* j / (ySize * k2)));

			int first_X = floor(new_X);
			int first_Y = floor(i);

			int second_X = first_X + 1;
			int second_Y = first_Y + 1;

			double a = i - first_Y;
			double b = new_X - first_X;

			if (first_X < 0 || first_X > xSize - 1 || first_Y < 0 || first_Y > ySize - 1) {
				R_output[i * 3*xSize + j] = 0;
				G_output[i * 3*xSize + j] = 0;
				B_output[i * 3*xSize + j] = 0;
			}
			else {
				R_output[i * 3*xSize + j] = (1 - a) * (1 - b) *R* R_extnd[first_Y * (xSize + 2) + first_X]
					+ (1 - a) * b * R*R_extnd[first_Y * (xSize + 2) + second_X]
					+ a * (1 - b) *R* R_extnd[second_Y * (xSize + 2) + first_X]
					+ a * b *R* R_extnd[second_Y * (xSize + 2) + second_X];

				G_output[i * 3*xSize + j] = (1 - a) * (1 - b) *G* G_extnd[first_Y * (xSize + 2) + first_X]
					+ (1 - a) * b *G* G_extnd[first_Y * (xSize + 2) + second_X]
					+ a * (1 - b) *G* G_extnd[second_Y * (xSize + 2) + first_X]
					+ a * b * G*G_extnd[second_Y * (xSize + 2) + second_X];

				B_output[i * 3*xSize + j] = (1 - a) * (1 - b) *B* B_extnd[first_Y * (xSize + 2) + first_X]
					+ (1 - a) * b * B*B_extnd[first_Y * (xSize + 2) + second_X]
					+ a * (1 - b) * B*B_extnd[second_Y * (xSize + 2) + first_X]
					+ a * b *B* B_extnd[second_Y * (xSize + 2) + second_X];
			}
		}
	}

	delete[] R_buff;
	delete[] R_output;
	delete[] G_buff;
	delete[] G_output;
	delete[] B_buff;
	delete[] B_output;

}