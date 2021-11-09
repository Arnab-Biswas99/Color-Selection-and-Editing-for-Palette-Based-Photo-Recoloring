#include <opencv2\opencv.hpp>
#include <opencv2\photo.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <math.h>
#include <cmath>
#include <algorithm>
using namespace cv;
using namespace std;


int main()
{
	Mat img = imread("C:/opencv/2.png", -1);
	Mat img1 = imread("C:/opencv/1.png", -1);
	vector<vector<float>> vec(img.rows, vector<float>(img.cols, 0));
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			float d = 255 * (1.0);
			vec[i][j] = img1.at<uchar>(i, j) / d;
		}
	}
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			img.at<Vec3b>(i, j) = img.at<Vec3b>(i, j) * vec[i][j];
		}
	}
	imshow("J", img);
	imwrite("C:/opencv/3.png", img);
	waitKey();
	return 0;
}