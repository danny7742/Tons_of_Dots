#include <iostream>
#include <cstdio>
#include <stack>
#include <opencv2/opencv.hpp>
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

// 우측최상단 (0,0)일 경우
offsets Move[8] = {
	{ -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 },
	{ 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }
};



/* void trace_line(element start, int edged_mat[][], bool mark[][]) {

	stack <element> pstack;

	int i, j, row, col, nextRow, nextCol, dir, found = false;
	element position;

	while (pstack.size()-1 > -1 && !found) {
		position = pstack.top();
		pstack.pop();
		row = position.row;
		col = position.col;
		dir = position.dir;

		while (dir < 8 && !found) {
			nextRow = row + Move[dir].vert;
			nextCol = col + Move[dir].horiz;

			// 시작점으로 다시 돌아왔을 때
			if (nextRow == start.row && nextCol == start.col) {
				if (edged_mat[nextRow][nextCol] == true)
					found = true;
				else
					break;
				
			}
			else if (edged_mat[nextRow][nextCol] = true && mark[nextRow][nextCol] == false) {

				mark[nextRow][nextCol] = true;
				position.row = row;
				position.col = col;
				position.dir = ++dir;

				pstack.push(position);

				row = nextRow;
				col = nextCol;
				dir = 0;
			}
			else ++dir;

		}
	}

}
*/

int main()
{
	cv::Mat origin;
	origin = cv::imread("example7.jpg", CV_LOAD_IMAGE_COLOR);

	Mat result;
	result = cv::imread("example7.jpg", CV_LOAD_IMAGE_COLOR);



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
		memset(edged_mat[i], 0, sizeof(int)*width); // 메모리 공간을 0으로 초기화 
	}

	bool ** mark = new bool*[height];
	for (int i = 0; i < height; ++i) {
		mark[i] = new bool[width];
		memset(mark[i], false, sizeof(bool)*width); // 메모리 공간을 false으로 초기화 
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (origin.at<Vec3b>(i, j)[0] < 10 && origin.at<Vec3b>(i, j)[1] < 10 && origin.at<Vec3b>(i, j)[2] < 10)
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

	cv::namedWindow("EXAMPLE01", CV_WINDOW_AUTOSIZE);


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


	stack <element> pstack;

	int i, j, y, x, nextY, nextX, dir, found = false;
	int count;
	element position;

	pstack.push(start);
	
	while (pstack.size() > 0 && found == false) {
		position = pstack.top();
		pstack.pop();
		y = position.y;
		x = position.x;
		dir = position.dir;
		count = position.count;

		while (count < 9 && !found) {
			dir = dir % 8;
			nextX = x + Move[dir].horiz;
			nextY = y + Move[dir].vert;
			

			// 시작점으로 다시 돌아왔을 때
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
				
				pstack.push(position);

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

/*	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			origin.at<Vec3b>(i, j)[0] = 255;
			origin.at<Vec3b>(i, j)[1] = 255;
			origin.at<Vec3b>(i, j)[2] = 255;
		}
	}

*/
	element e;
	cout << pstack.size() << endl;

	int dotcnt = 0;
	while (pstack.size() > 0) {
		e = pstack.top();
		pstack.pop();
		if (dotcnt % 10 == 0) {
			result.at<Vec3b>(e.y, e.x)[0] = 0;
			result.at<Vec3b>(e.y, e.x)[1] = 0;
			result.at<Vec3b>(e.y, e.x)[2] = 0;
		}
		cout << "(" << e.y << "," << e.x << ")" << endl;
		dotcnt++;
	}



	 cv::imshow("EXAMPLE01", result);
	cv::waitKey(0);
	cv::destroyWindow("EXAMPLE01");
	return 0;
}
