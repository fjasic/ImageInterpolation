
#ifndef IMAGEINTERPOLATION_H_
#define IMAGEINTERPOLATION_H_

#include <QString>
#include <QVector>
#include <QImage>

int divisibleByN(int sizeNum, int n);

uchar cubicInterpolate(uchar p[4], double x);

char cubicInterpolate(char p[4], double x);

void sampleAndHold(const uchar input[], int xSize, int ySize, uchar output[], int newXSize, int newYSize);

void bilinearInterpolate(const uchar input[], int xSize, int ySize, uchar output[], int newXSize, int newYSize);

void bicubicInterpolate(const uchar input[], int xSize, int ySize, uchar output[], int newXSize, int newYSize);

void imageSwirl(const uchar input[], int xSize, int ySize, uchar output[], int m, int n, double k1, double k2);

void imageSwirlBilinear(const uchar input[], int xSize, int ySize, uchar output[], int m, int n,double k1,double k2);

#endif // IMAGEINTERPOLATION_H_
