#include <stdlib.h>
#include <opencv2/imgproc.hpp>
#include <stdio.h>

using namespace cv;
using namespace std;
int zer[5][3] = { { 1,1,1 },{ 1,0,1 },{ 1,0,1 },{ 1,0,1 },{ 1,1,1 } };
int one[5][3] = { { 0,0,1 },{ 0,0,1 },{ 0,0,1 },{ 0,0,1 },{ 0,0,1 } };
int two[5][3] = { { 1,1,1 },{ 0,0,1 },{ 1,1,1 },{ 1,0,0 },{ 1,1,1 } };
int three[5][3] = { { 1,1,1 },{ 0,0,1 },{ 1,1,1 },{ 0,0,1 },{ 1,1,1 } };
int four[5][3] = { { 1,0,1 },{ 1,0,1 },{ 1,1,1 },{ 0,0,1 },{ 0,0,1 } };
int five[5][3] = { { 1,1,1 },{ 1,0,0 },{ 1,1,1 },{ 0,0,1 },{ 1,1,1 } };
int six[5][3] = { { 1,0,0 },{ 1,0,0 },{ 1,1,1 },{ 1,0,1 },{ 1,1,1 } };
int seven[5][3] = { { 1,1,1 },{ 1,0,1 },{ 1,0,1 },{ 0,0,1 },{ 0,0,1 } };
int eight[5][3] = { { 1,1,1 },{ 1,0,1 },{ 1,1,1 },{ 1,0,1 },{ 1,1,1 } };
int nine[5][3] = { { 1,1,1 },{ 1,0,1 },{ 1,1,1 },{ 0,0,1 },{ 0,0,1 } };

//erode function
Mat edgecol(Mat  img) {
	Mat edgeco = img.clone();
	for (int x = 1; x < img.size().height - 1; x++) {
		for (int y = 1; y < img.size().width - 1; y++) {
			if (img.at<Vec3b>(x, y)[0] == 0) {
				edgeco.at<Vec3b>(x, y)[0] = 0;
				edgeco.at<Vec3b>(x, y)[1] = 0;
				edgeco.at<Vec3b>(x, y)[2] = 0;
				edgeco.at<Vec3b>(x, y - 1)[0] = 0;
				edgeco.at<Vec3b>(x, y - 1)[1] = 0;
				edgeco.at<Vec3b>(x, y - 1)[2] = 0;
				edgeco.at<Vec3b>(x - 1, y)[0] = 0;
				edgeco.at<Vec3b>(x - 1, y)[1] = 0;
				edgeco.at<Vec3b>(x - 1, y)[2] = 0;
				edgeco.at<Vec3b>(x, y + 1)[0] = 0;
				edgeco.at<Vec3b>(x, y + 1)[1] = 0;
				edgeco.at<Vec3b>(x, y + 1)[2] = 0;
				edgeco.at<Vec3b>(x + 1, y)[0] = 0;
				edgeco.at<Vec3b>(x + 1, y)[1] = 0;
				edgeco.at<Vec3b>(x + 1, y)[2] = 0;

			}
		}
	}
	return edgeco;
}
//index function. x & y is first pixel the number starts,(left down) index is indexing number
Mat indexing(Mat img, int index, int x, int y) {
	char number[3];
	int count = 0;
	itoa(index, number, 10);
	for (int i = 0; number[i] != NULL; i++) {
		count++;
	}
	char indexes[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int newx = x;
	for (int i = 0; i < count; i++) {
		if (number[i] == indexes[0]) {
			for (int xindex = 0; xindex < 3; xindex++) {
				for (int yindex = 0; yindex < 5; yindex++) {
					for (int xcol = newx + ((xindex) * 3); xcol < newx + ((xindex) * 3) + 3; xcol++) {
						for (int ycol = y + ((yindex) * 3); ycol < y + ((yindex) * 3) + 3; ycol++) {
							img.at<Vec3b>(ycol, xcol)[0] = 255 - 255 * zer[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[1] = 255 - 255 * zer[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[2] = 255 - 255 * zer[yindex][xindex];
						}
					}
				}
			}
		}
		else if (number[i] == indexes[1]) {
			for (int xindex = 0; xindex < 3; xindex++) {
				for (int yindex = 0; yindex < 5; yindex++) {
					for (int xcol = newx + ((xindex) * 3); xcol < newx + ((xindex) * 3) + 3; xcol++) {
						for (int ycol = y + ((yindex) * 3); ycol < y + ((yindex) * 3) + 3; ycol++) {
							img.at<Vec3b>(ycol, xcol)[0] = 255 - 255 * one[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[1] = 255 - 255 * one[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[2] = 255 - 255 * one[yindex][xindex];
						}
					}
				}
			}
		}
		else if (number[i] == indexes[2]) {
			for (int xindex = 0; xindex < 3; xindex++) {
				for (int yindex = 0; yindex < 5; yindex++) {
					for (int xcol = newx + ((xindex) * 3); xcol < newx + ((xindex) * 3) + 3; xcol++) {
						for (int ycol = y + ((yindex) * 3); ycol < y + ((yindex) * 3) + 3; ycol++) {
							img.at<Vec3b>(ycol, xcol)[0] = 255 - 255 * two[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[1] = 255 - 255 * two[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[2] = 255 - 255 * two[yindex][xindex];
						}
					}
				}
			}
		}
		else if (number[i] == indexes[3]) {
			for (int xindex = 0; xindex < 3; xindex++) {
				for (int yindex = 0; yindex < 5; yindex++) {
					for (int xcol = newx + ((xindex) * 3); xcol < newx + ((xindex) * 3) + 3; xcol++) {
						for (int ycol = y + ((yindex) * 3); ycol < y + ((yindex) * 3) + 3; ycol++) {
							img.at<Vec3b>(ycol, xcol)[0] = 255 - 255 * three[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[1] = 255 - 255 * three[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[2] = 255 - 255 * three[yindex][xindex];
						}
					}
				}
			}
		}
		else if (number[i] == indexes[3]) {
			for (int xindex = 0; xindex < 3; xindex++) {
				for (int yindex = 0; yindex < 5; yindex++) {
					for (int xcol = newx + ((xindex) * 3); xcol < newx + ((xindex) * 3) + 3; xcol++) {
						for (int ycol = y + ((yindex) * 3); ycol < y + ((yindex) * 3) + 3; ycol++) {
							img.at<Vec3b>(ycol, xcol)[0] = 255 - 255 * four[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[1] = 255 - 255 * four[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[2] = 255 - 255 * four[yindex][xindex];
						}
					}
				}
			}
		}
		else if (number[i] == indexes[5]) {
			for (int xindex = 0; xindex < 3; xindex++) {
				for (int yindex = 0; yindex < 5; yindex++) {
					for (int xcol = newx + ((xindex) * 3); xcol < newx + ((xindex) * 3) + 3; xcol++) {
						for (int ycol = y + ((yindex) * 3); ycol < y + ((yindex) * 3) + 3; ycol++) {
							img.at<Vec3b>(ycol, xcol)[0] = 255 - 255 * five[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[1] = 255 - 255 * five[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[2] = 255 - 255 * five[yindex][xindex];
						}
					}
				}
			}
		}
		else if (number[i] == indexes[3]) {
			for (int xindex = 0; xindex < 3; xindex++) {
				for (int yindex = 0; yindex < 5; yindex++) {
					for (int xcol = newx + ((xindex) * 3); xcol < newx + ((xindex) * 3) + 3; xcol++) {
						for (int ycol = y + ((yindex) * 3); ycol < y + ((yindex) * 3) + 3; ycol++) {
							img.at<Vec3b>(ycol, xcol)[0] = 255 - 255 * six[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[1] = 255 - 255 * six[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[2] = 255 - 255 * six[yindex][xindex];
						}
					}
				}
			}
		}
		else if (number[i] == indexes[7]) {
			for (int xindex = 0; xindex < 3; xindex++) {
				for (int yindex = 0; yindex < 5; yindex++) {
					for (int xcol = newx + ((xindex) * 3); xcol < newx + ((xindex) * 3) + 3; xcol++) {
						for (int ycol = y + ((yindex) * 3); ycol < y + ((yindex) * 3) + 3; ycol++) {
							img.at<Vec3b>(ycol, xcol)[0] = 255 - 255 * seven[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[1] = 255 - 255 * seven[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[2] = 255 - 255 * seven[yindex][xindex];
						}
					}
				}
			}
		}
		else if (number[i] == indexes[8]) {
			for (int xindex = 0; xindex < 3; xindex++) {
				for (int yindex = 0; yindex < 5; yindex++) {
					for (int xcol = newx + ((xindex) * 3); xcol < newx + ((xindex) * 3) + 3; xcol++) {
						for (int ycol = y + ((yindex) * 3); ycol < y + ((yindex) * 3) + 3; ycol++) {
							img.at<Vec3b>(ycol, xcol)[0] = 255 - 255 * eight[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[1] = 255 - 255 * eight[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[2] = 255 - 255 * eight[yindex][xindex];
						}
					}
				}
			}
		}
		else if (number[i] == indexes[9]) {
			for (int xindex = 0; xindex < 3; xindex++) {
				for (int yindex = 0; yindex < 5; yindex++) {
					for (int xcol = newx + ((xindex) * 3); xcol < newx + ((xindex) * 3) + 3; xcol++) {
						for (int ycol = y + ((yindex) * 3); ycol < y + ((yindex) * 3) + 3; ycol++) {
							img.at<Vec3b>(ycol, xcol)[0] = 255 - 255 * nine[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[1] = 255 - 255 * nine[yindex][xindex];
							img.at<Vec3b>(ycol, xcol)[2] = 255 - 255 * nine[yindex][xindex];
						}
					}
				}
			}
		}
		newx = newx + 12;
	}
	return img;
}
Mat grayscale(Mat img) {
	Mat retmat;
	retmat = img.clone();
	for (int x = 0; x < img.size().width; x++) {
		for (int y = 0; y < img.size().height; y++) {
			retmat.at<Vec3b>(y, x)[0] = (retmat.at<Vec3b>(y, x)[0] + retmat.at<Vec3b>(y, x)[1] + retmat.at<Vec3b>(y, x)[2]) / 3;
			retmat.at<Vec3b>(y, x)[1] = (retmat.at<Vec3b>(y, x)[0] + retmat.at<Vec3b>(y, x)[1] + retmat.at<Vec3b>(y, x)[2]) / 3;
			retmat.at<Vec3b>(y, x)[2] = (retmat.at<Vec3b>(y, x)[0] + retmat.at<Vec3b>(y, x)[1] + retmat.at<Vec3b>(y, x)[2]) / 3;
		}
	}
	return retmat;
}

Mat edge_detect(Mat grays, Mat labelbycol) {

	signed long sumred;
	signed long sumgreen;
	signed long sumblue;
	signed long sumredh = 0;
	signed long sumgreenh = 0;
	signed long sumblueh = 0;
	signed long sumredv = 0;
	signed long sumgreenv = 0;
	signed long sumbluev = 0;
	signed long sumredd = 0;
	signed long sumgreend = 0;
	signed long sumblued = 0;
	signed long sumreddd = 0;
	signed long sumgreendd = 0;
	signed long sumbluedd = 0;
	vector<pair<int, int>> fordots;
	int horizontal[9] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };
	int vertical[9] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
	int diagonal1[9] = { 0, 1, 2, -1, 0, 1, -2, -1, 0 };
	int diagonal2[9] = { -2, -1, 0, -1, 0, 1, 0, 1, 2 };
	int i = 0;
	for (int x = 1; x < (grays.size().width - 1); x++) {
		for (int y = 1; y < (grays.size().height - 1); y++) {
			for (int w = y - 1; w < y + 2; w++) {
				for (int v = x - 1; v < x + 2; v++) {
					sumredh += grays.at<Vec3b>(w, v)[0] * horizontal[i];
					sumredv += grays.at<Vec3b>(w, v)[0] * vertical[i];
					sumredd += grays.at<Vec3b>(w, v)[0] * diagonal1[i];
					sumreddd += grays.at<Vec3b>(w, v)[0] * diagonal2[i];
					i++;
				}
			}
			if (sumredh > 50) {
				labelbycol.at<Vec3b>(y, x)[0] = 0;
				labelbycol.at<Vec3b>(y, x)[1] = 0;
				labelbycol.at<Vec3b>(y, x)[2] = 0;
				pair <int, int> p1(y, x);
				fordots.push_back(p1);

			}
			else if (sumredv > 50) {
				labelbycol.at<Vec3b>(y, x)[0] = 0;
				labelbycol.at<Vec3b>(y, x)[1] = 0;
				labelbycol.at<Vec3b>(y, x)[2] = 0;
				pair <int, int> p1(y, x);
				fordots.push_back(p1);
			}
			else if (sumredd > 50) {
				labelbycol.at<Vec3b>(y, x)[0] = 0;
				labelbycol.at<Vec3b>(y, x)[1] = 0;
				labelbycol.at<Vec3b>(y, x)[2] = 0;
				pair <int, int> p1(y, x);
				fordots.push_back(p1);

			}
			else if (sumreddd > 50) {
				labelbycol.at<Vec3b>(y, x)[0] = 0;
				labelbycol.at<Vec3b>(y, x)[1] = 0;
				labelbycol.at<Vec3b>(y, x)[2] = 0;
				pair <int, int> p1(y, x);
				fordots.push_back(p1);
			}
			else {
				labelbycol.at<Vec3b>(y, x)[0] = 255;
				labelbycol.at<Vec3b>(y, x)[1] = 255;
				labelbycol.at<Vec3b>(y, x)[2] = 255;
			}
			sumredh = 0;
			sumblueh = 0;
			sumgreenh = 0;
			sumredv = 0;
			sumbluev = 0;
			sumgreenv = 0;
			sumredd = 0;
			sumblued = 0;
			sumgreend = 0;
			sumreddd = 0;
			sumbluedd = 0;
			sumgreendd = 0;
			i = 0;
		}
	}
	return labelbycol;
}
Mat blur(Mat img) {
	int MaskGaussian[3][3] = { { 1,2,1 },
	{ 2,4,2 },
	{ 1,2,1 } };
	int heightm1 = img.size().height - 1;
	int widthm1 = img.size().width - 1;
	int mr, mc;
	int newValue0;
	int newValue1;
	int newValue2;
	Mat buffer;
	buffer = img.clone();
	for (int y = 0; y < img.size().height; y++) {
		for (int x = 0; x < img.size().width; x++) {
			buffer.at<Vec3b>(y, x)[0] = 0;
			buffer.at<Vec3b>(y, x)[1] = 0;
			buffer.at<Vec3b>(y, x)[2] = 0;
		}
	}

	for (int y = 1; y<heightm1; y++)
	{
		for (int x = 1; x<widthm1; x++)
		{
			newValue0 = 0;
			newValue1 = 0;
			newValue2 = 0;
			for (mr = 0; mr < 3; mr++) {
				for (mc = 0; mc < 3; mc++) {
					newValue0 += (MaskGaussian[mr][mc] * img.at<Vec3b>(y + mr - 1, x + mc - 1)[0]);
					newValue1 += (MaskGaussian[mr][mc] * img.at<Vec3b>(y + mr - 1, x + mc - 1)[1]);
					newValue2 += (MaskGaussian[mr][mc] * img.at<Vec3b>(y + mr - 1, x + mc - 1)[2]);
				}
			}
			newValue0 /= 20;
			newValue1 /= 20;
			newValue2 /= 20;
			buffer.at<Vec3b>(y, x)[0] = newValue0;
			buffer.at<Vec3b>(y, x)[1] = newValue1;
			buffer.at<Vec3b>(y, x)[2] = newValue2;
		}
	}
	return buffer;
}
Mat collection(Mat img) {
	Mat gray;
	Mat edge;
	Mat labelbycol;
	Mat grays;
	Mat exbg;
	Mat gaus;
	grays = grayscale(img);
	edge = grays.clone();
	gaus = blur(grays);
	int count = 0;
	// edge function
	edge = edge_detect(gaus, edge);
	Mat edgesomething = edgecol(edge); //erode
	Mat edgetwice = edgecol(edgesomething); // erode twice
	return edgetwice;
}