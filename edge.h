#pragma once
#include "edge.cpp"

Mat edge_detect(Mat grays, Mat labelbycol);
Mat grayscale(Mat img);
Mat indexing(Mat img, int index, int x, int y);
Mat edgecol(Mat  img);
float distance(int x, int y, int i, int j);
double gaussian(float x, double sigma);
void applyBilateralFilter(Mat source, Mat filteredImage, int x, int y, int diameter, double sigmaI, double sigmaS);
Mat bilateralFilterOwn(Mat source, int diameter, double sigmaI, double sigmaS);
Mat collection(Mat img);