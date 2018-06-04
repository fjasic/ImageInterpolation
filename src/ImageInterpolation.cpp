#include "ImageInterpolation.h"
#include "ColorSpaces.h"
#include <math.h>
#include "ImageFilter.h"

#define PI 3.141592653589793238462643383279502884L


int divisibleByN(int sizeNum, int n) {
	return sizeNum % n == 0 ? sizeNum : sizeNum + (n - (sizeNum % n));
}

void sampleAndHold(const uchar input[], int xSize, int ySize, uchar output[], int newXSize, int newYSize)
{
	/* TO DO */

	//Output buffer
	//double *output_RGB = new double[newXSize * newYSize];

	//Scaling factors
	const double F_horizontal = (double)newXSize / xSize;
	const double F_vertical = (double)newYSize / ySize;

	uchar R, G, B;
	for (int i = 0; i < newXSize; i++)
	{
		for (int j = 0; j < newYSize; j++)
		{
			int ii;
			int jj;

			ii = (i - 1) / F_horizontal;
			jj = (j - 1) / F_vertical;

			if (ii < xSize - 1)
				ii = (i - 1) / F_horizontal + 1;

			if (jj < ySize - 1)
				jj = (j - 1) / F_vertical + 1;

			R = input[jj * 3 * xSize + ii * 3];
			G = input[jj * 3 * xSize + ii * 3 + 1];
			B = input[jj * 3 * xSize + ii * 3 + 2];

			output[j * 3 * newXSize + i * 3] = R;
			output[j * 3 * newXSize + i * 3 + 1] = G;
			output[j * 3 * newXSize + i * 3 + 2] = B;
		}
	}

	
}

void bilinearInterpolate(const uchar input[], int xSize, int ySize, uchar output[], int newXSize, int newYSize)
{
	/* TO DO */

	//Scaling factors
	const double F_horizontal = (double)newXSize / xSize;
	const double F_vertical = (double)newYSize / ySize;

	uchar R, G, B;
	for (int i = 0; i < newXSize; i++)
	{
		for (int j = 0; j < newYSize; j++)
		{
			double a = i / F_horizontal - floor(i / F_horizontal);
			double b = j / F_vertical - floor(j / F_vertical);

			int ii = i / F_horizontal;
			int jj = j / F_vertical;

			int iii = ii, jjj = jj;
			if (ii < xSize - 1)
				iii = ii + 1;
			if (jj < ySize - 1)
				jjj = jj + 1;

			R = (1 - a) * (1 - b) * input[jj * xSize * 3 + ii * 3] + a * (1 - b) *input[jj * xSize * 3 + (iii) * 3] + (1 - a) * b * input[(jjj)* xSize * 3 + ii * 3] + a * b * input[(jjj)* xSize * 3 + (iii) * 3];
			G = (1 - a) * (1 - b) * input[jj * xSize * 3 + ii * 3 + 1] + a * (1 - b) *input[jj * xSize * 3 + (iii) * 3 + 1] + (1 - a) * b * input[(jjj)* xSize * 3 + ii * 3 + 1] + a * b * input[(jjj)* xSize * 3 + (iii) * 3 + 1];
			B = (1 - a) * (1 - b) * input[jj * xSize * 3 + ii * 3 + 2] + a * (1 - b) *input[jj * xSize * 3 + (iii) * 3 + 2] + (1 - a) * b * input[(jjj)* xSize * 3 + ii * 3 + 2] + a * b * input[(jjj)* xSize * 3 + (iii) * 3 + 2];

			output[j * 3 * newXSize + i * 3] = R;
			output[j * 3 * newXSize + i * 3 + 1] = G;
			output[j * 3 * newXSize + i * 3 + 2] = B;
		}
	}
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
	}
	else if (retVal < -127) {
		retVal = -127;
	}

	return (char)retVal;
}

void bicubicInterpolate(const uchar input[], int xSize, int ySize, uchar output[], int newXSize, int newYSize)
{
	/* TO DO */
	uchar R, G, B;


	uchar *B_buff = new uchar[xSize * ySize];
	uchar *R_buff = new uchar[xSize * ySize];
	uchar *G_buff = new uchar[xSize * ySize];

	for (int i = 0; i < xSize; i++) {
		for (int j = 0; j < ySize; j+=3) { 
			R_buff[j * xSize + i] =  input[j * xSize + i];
			G_buff[j  * xSize + i + 1] = input[j * xSize + i + 1];
			B_buff[j  * xSize + i + 2] = input[j * xSize + i + 2];
		}
	}
	uchar *R_output = new uchar[newXSize * newYSize];
	uchar *G_output = new uchar[newXSize * newYSize];
	uchar *B_output = new uchar[newXSize * newYSize];

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



	for (int i = 0; i < newXSize; i++) {
		for (int j = 0; j < newYSize; j++) {
			double b = i / F_horizontal - floor(i / F_horizontal);
			double a = j / F_vertical - floor(j / F_vertical);

			int new_x = j / F_vertical;
			int new_y = i / F_horizontal;

			int v = 0;
			for (int h = new_x - 1; h < new_x + 3; h++, v++) {
				R_horizontal[0] = R_extnd[h * (ySize + 4) + new_y - 1];
				R_horizontal[1] = R_extnd[h * (ySize + 4) + new_y];
				R_horizontal[2] = R_extnd[h * (ySize + 4) + new_y + 1];
				R_horizontal[3] = R_extnd[h * (ySize + 4) + new_y + 2];

				G_horizontal[0] = G_extnd[h * (ySize + 4) + new_y - 1];
				G_horizontal[1] = G_extnd[h * (ySize + 4) + new_y];
				G_horizontal[2] = G_extnd[h * (ySize + 4) + new_y + 1];
				G_horizontal[3] = G_extnd[h * (ySize + 4) + new_y + 2];

				B_horizontal[0] = B_extnd[h * (ySize + 4) + new_y - 1];
				B_horizontal[1] = B_extnd[h * (ySize + 4) + new_y];
				B_horizontal[2] = B_extnd[h * (ySize + 4) + new_y + 1];
				B_horizontal[3] = B_extnd[h * (ySize + 4) + new_y + 2];

				R_vertical[v] = cubicInterpolate(R_horizontal, b);
				G_vertical[v] = cubicInterpolate(G_horizontal, b);
				B_vertical[v] = cubicInterpolate(B_horizontal, b);
			}

			R = cubicInterpolate(R_vertical, a);
			G = cubicInterpolate(G_vertical, a);
			B = cubicInterpolate(B_vertical, a);

			output[j * 3 * newXSize + i * 3] = R;
			output[j * 3 * newXSize + i * 3 + 1] = G;
			output[j * 3 * newXSize + i * 3 + 2] = B;
		}
	}
}

void imageSwirl(const uchar input[], int xSize, int ySize, uchar output[], int m, int n, double k1,double k2)
{
	/* TO DO */
	uchar R, G, B;

	for (int i = 0; i < xSize; i++) {
		for (int j = 0; j < ySize; j++) {// i mi je X , j mi je Y ,ii mi je novoX ,jj mi je novoY
			int ii = i + k1*xSize*sin((2*PI*j)/(ySize*k2));
			int jj = j;
			if (ii >= 0 && ii < xSize && jj >= 0 && jj < ySize) {
				R = input[ii * 3 + jj * xSize * 3];
				G = input[ii * 3 + 1 + jj * xSize * 3];
				B = input[ii * 3 + 2 + jj * xSize * 3];
				output[j * 3 * xSize + i * 3] = R;
				output[j * 3 * xSize + i * 3 + 1] = G;
				output[j * 3 * xSize + i * 3 + 2] = B;
			}
			else {
				R = 0;
				G = 0;
				B = 0;
				output[j * 3 * xSize + i * 3] = R;
				output[j * 3 * xSize + i * 3 + 1] = G;
				output[j * 3 * xSize + i * 3 + 2] = B;
			}
		}
	}
}

void imageSwirlBilinear(const uchar input[], int xSize, int ySize, uchar output[], int m, int n, double k1,double k2)
{
	/* TO DO */
	uchar R, G, B;

	for (int i = 0; i < xSize; i++) {
		for (int j = 0; j < ySize; j++) {
		

			double di = i - m;
			double dj = j - n;
			int disI = i + k1*xSize*sin((2 * PI*j) / (ySize*k2));
			int disJ = j;
			int newI = floor(disI);
			int newJ = floor(disJ);
			double a = disJ - newJ;
			double b = disI - newI;



			if (newI >= 0 && (newI + 1) < xSize && newJ >= 0 && (newJ + 1) < ySize) {
				R = (1 - a) * (1 - b) * input[newJ * xSize * 3 + newI * 3] + a * (1 - b) *input[(newJ + 1) * xSize * 3 + newI * 3] + (1 - a) * b * input[newJ* xSize * 3 + (newI + 1) * 3] + a * b * input[(newJ + 1)* xSize * 3 + (newI + 1) * 3];
				G = (1 - a) * (1 - b) * input[newJ * xSize * 3 + 1 + newI * 3] + a * (1 - b) *input[(newJ + 1) * xSize * 3 + 1 + newI * 3] + (1 - a) * b * input[newJ* xSize * 3 + 1 + (newI + 1) * 3] + a * b * input[(newJ + 1)* xSize * 3 + 1 + (newI + 1) * 3];
				B = (1 - a) * (1 - b) * input[newJ * xSize * 3 + 2 + newI * 3] + a * (1 - b) *input[(newJ + 1) * xSize * 3 + 2 + newI * 3] + (1 - a) * b * input[newJ* xSize * 3 + 2 + (newI + 1) * 3] + a * b * input[(newJ + 1)* xSize * 3 + 2 + (newI + 1) * 3];
				output[j * 3 * xSize + i * 3] = R;
				output[j * 3 * xSize + i * 3 + 1] = G;
				output[j * 3 * xSize + i * 3 + 2] = B;
			}
			else {
				R = 0;
				G = 0;
				B = 0;
				output[j * 3 * xSize + i * 3] = R;
				output[j * 3 * xSize + i * 3 + 1] = G;
				output[j * 3 * xSize + i * 3 + 2] = B;
			}
		}
	}
}
