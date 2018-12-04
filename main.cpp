#include <iostream>
#include <cstdio>
#include <stack>
#include <deque>
#include <opencv2/opencv.hpp>
#include "edge.h"

using namespace std;
using namespace cv;


struct offsets {
	short int vert;
	short int horiz;
};

struct element {
	short int x;
	short int y;
	short int dir;
	int count;
};

enum {
	N = 0, NE, E, SE, S, SW, W, NW
};


offsets Move[8] = {
	{ -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 },
	{ 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }
};


int main()
{
	cv::Mat origin;
	origin = cv::imread("Ryan.jpg", CV_LOAD_IMAGE_COLOR);

	Mat result;
	result = cv::imread("Ryan.jpg", CV_LOAD_IMAGE_COLOR);

	result = collection(result);
	cv::imshow("EDGED", result);

	if (origin.empty())
	{
		std::cout << "[!] You can NOT see the cat!" << std::endl;
		return -1;
	}

	int width = origin.size().width;
	int height = origin.size().height;

	cout << "image :" << width << "x" << height << endl;

	int** edged_mat = new int*[height];
	for (int i = 0; i < height; ++i) {
		edged_mat[i] = new int[width];
		memset(edged_mat[i], 0, sizeof(int)*width); // �޸� ������ 0���� �ʱ�ȭ 
	}

	bool ** mark = new bool*[height];
	for (int i = 0; i < height; ++i) {
		mark[i] = new bool[width];
		memset(mark[i], false, sizeof(bool)*width); // �޸� ������ false���� �ʱ�ȭ 
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (result.at<Vec3b>(i, j)[0] < 10 && result.at<Vec3b>(i, j)[1] < 10 && result.at<Vec3b>(i, j)[2] < 10)
				edged_mat[i][j] = 1;
		}
	}

	/* for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if(edged_mat[i][j] == 1)
				cout << edged_mat[i][j] << " (" << j << ',' << i << ")" << endl;
		}
		cout << endl;
	}
	*/


	/*for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if(edged_mat[i][j] != 0)
				cout << "1";
		}
	}*/

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			result.at<Vec3b>(i, j)[0] = 255;
			result.at<Vec3b>(i, j)[1] = 255;
			result.at<Vec3b>(i, j)[2] = 255;
		}
	}

	element start;
	start.dir = 2;
	start.count = 0;
	bool isFind = false;
	/*cout << "start : (" << start.row << ',' << start.col << ")" << endl;*/


	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (edged_mat[i][j] == 1) {
				start.y = i;
				start.x = j;
				cout << "start point:" << start.y << ',' << start.x << endl;
				isFind = true;
				break;
			}
		}
		if (isFind == true)
			break;
	}


	deque <element> pstack;

	int i, j, y, x, nextY, nextX, dir, found = false;
	int count;
	element position;

	pstack.push_back(start);

	while (pstack.size() > 0 && found == false) {
		position = pstack.front();
		pstack.pop_back();
		y = position.y;
		x = position.x;
		dir = position.dir;
		count = position.count;

		while (count < 9 && !found) {
			dir = dir % 8;
			nextX = x + Move[dir].horiz;
			nextY = y + Move[dir].vert;


			if (nextX == start.x && nextY == start.y) {
				if (edged_mat[nextY][nextX] == 1)
					found = true;
				else
					break;

			}
			else if (edged_mat[nextY][nextX] == 1 && mark[nextY][nextX] == false) {

				mark[nextY][nextX] = true;
				position.y = y;
				position.x = x;
				position.dir = ++dir;
				position.count = ++count;

				pstack.push_back(position);

				/* element e = pstack.top();
				result.at<Vec3b>(e.y, e.x)[0] = 0;
				result.at<Vec3b>(e.y, e.x)[1] = 0;
				result.at<Vec3b>(e.y, e.x)[2] = 0;
				cv::imshow("EXAMPLE01", result);
				*/

				y = nextY;
				x = nextX;
				dir = (position.dir + 4) % 8;
				count = 0;
			}
			else {
				++dir;
				++count;
			}
		}

	}

	element e;
	cout << pstack.size() << endl;

	int dotcnt = 0;
	int indexcnt = 1;
	while (pstack.size() != dotcnt) {
		e = pstack[dotcnt];
		if (dotcnt % 50 == 0) {
			result.at<Vec3b>(e.y, e.x)[0] = 0;
			result.at<Vec3b>(e.y, e.x)[1] = 0;
			result.at<Vec3b>(e.y, e.x)[2] = 0;

		}
		// cout << "(" << e.y << "," << e.x << ")  " << endl;
		dotcnt++;
	}

	result = edgecol(result);
	result = edgecol(result);

	dotcnt = 0;
	while(pstack.size() != dotcnt) {
		e = pstack[dotcnt];
		if (dotcnt % 50 == 0) {
			indexing(result, indexcnt, e.x + 5, e.y);
			indexcnt++;
			cout << indexcnt << endl;
		}
		dotcnt++;
	}


	cv::imshow("ORIGINAL", origin);
	cv::imshow("RESULT", result);
	cv::waitKey(0);
	cv::destroyWindow("EXAMPLE01");
	return 0;
}
