#include <opencv2\opencv.hpp>
#include <opencv2\photo.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <math.h>
#include <cmath>
#include <algorithm>
#include<vector>
#include<set>
#include <unordered_set>
using namespace cv;
using namespace std;

void gammaCorrection(const Mat& src, Mat& dst, const float gamma)
{
    float invGamma = 1 / gamma;

    Mat table(1, 256, CV_8U);
    uchar* p = table.ptr();
    for (int i = 0; i < 256; ++i) {
        p[i] = (uchar)(pow(i / 255.0, invGamma) * 255);
    }

    LUT(src, table, dst);
}

int main()
{
    Mat img = imread("C://opencv/carrom_s.png", -1);
    Mat gammaImg;
    gammaCorrection(img, gammaImg, 5);

    imshow("Original image", img);
    imshow("Gamma corrected image", gammaImg);
    waitKey(0);
    imwrite("C://opencv/carrom_s.png", gammaImg);
    return 0;
}