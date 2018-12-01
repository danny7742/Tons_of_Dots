#pragma once
#include "edge.cpp"

Mat edge_detect(Mat grays, Mat labelbycol);
Mat grayscale(Mat img);
Mat indexing(Mat img, int index, int x, int y);
Mat edgecol(Mat  img);
Mat blur(Mat img);
Mat collection(Mat img);