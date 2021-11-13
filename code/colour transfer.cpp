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

vector<int>colour_name(Mat HSV_pallet)
{
    map<int, int>m;
    for (int i = 0; i < HSV_pallet.rows; i++)
    {
        for (int j = 0; j < HSV_pallet.cols; j++)
        {
            int p = HSV_pallet.at<Vec3b>(i, j)[0];
            if (m.find(p) == m.end())
            {
                m.insert(make_pair(p, 1));
            }
            else m[p]++;
        }
    }

    vector<pair<int, int>>v;
    for (auto& it : m) {
        v.push_back(make_pair(it.second, it.first));
    }
    sort(v.begin(), v.end());
    vector<int>vec;
    int size = v.size();
    for (int i = v.size() - 1; i >= v.size() - 5; i--)
    {
        vec.push_back(v[i].second);
    }
    return vec;
}

Mat output2(Mat HSV_image, int sigma, vector<int>vec)
{
    Mat output;
    int d;
    cout << "what will be new colour?" << endl;
    cout << "1.Red" << endl;
    cout << "2.majenta" << endl;
    cout << "3.brown" << endl;
    cout << "4.light brown" << endl;
    cout << "5.cream" << endl;
    cout << "6.yellow" << endl;
    cout << "7.sea green" << endl;
    cout << "8.deep green" << endl;
    cout << "9.grey green" << endl;
    cout << "10.green" << endl;
    cout << "11.skyblue" << endl;
    cout << "12.blue" << endl;
    cout << "13.blue violet" << endl;
    cout << "14.violet" << endl;
    cout << "15.Pink" << endl;
    cin >> d;
    int c_j_next;
    if (d == 1) c_j_next = 0;
    else if (d == 2) c_j_next = 8;
    else if (d == 3) c_j_next = 13;
    else if (d == 4) c_j_next = 15;
    else if (d == 5) c_j_next = 18;
    else if (d == 6) c_j_next = 25;
    else if (d == 7) c_j_next = 40;
    else if (d == 8) c_j_next = 55;
    else if (d == 9) c_j_next = 68;
    else if (d == 10) c_j_next = 75;
    else if (d == 11) c_j_next = 85;
    else if (d == 12) c_j_next = 110;
    else if (d == 13) c_j_next = 129;
    else if (d == 14) c_j_next = 133;
    else if (d == 15) c_j_next = 145;
    for (int i = 0; i < HSV_image.rows; i++)
    {
        for (int j = 0; j < HSV_image.cols; j++)
        {
            int p = HSV_image.at<Vec3b>(i, j)[0];
            if ((p >= 12 and p <= 18))
            {
                int numa = 1, deno = 1;
                int e_j = (c_j_next - 0);
                float two_sigma = (float)(2 * sigma);
                for (int k = 0; k < 5; k++)
                {
                    float exp_numa = p - 0;
                    exp_numa = abs(exp_numa);
                    exp_numa = (-1) * exp_numa;
                    float w_i_j = exp(exp_numa / two_sigma);
                    numa = numa + w_i_j * e_j;
                    deno = deno + w_i_j;
                }

                HSV_image.at<Vec3b>(i, j)[0] = p + (numa / deno);
                //cout << p + 85 << endl;
            }
            /*else if ((p >= 158 and p <= 179))
            {
                HSV_image.at<Vec3b>(i, j)[0] = p +(c_j_next-179);
            }*/
        }
    }
    return output;
}

int find_distance(Mat HSV_pallet)
{
    map<int, int>m;
    for (int i = 0; i < HSV_pallet.rows; i++)
    {
        for (int j = 0; j < HSV_pallet.cols; j++)
        {
            int p = HSV_pallet.at<Vec3b>(i, j)[0];
            if (m.find(p) == m.end())
            {
                m.insert(make_pair(p, 1));
            }
            else m[p]++;
        }
    }

    vector<pair<int, int>>v;
    for (auto& it : m) {
        v.push_back(make_pair(it.second, it.first));
    }
    sort(v.begin(), v.end());
    vector<int>vec;
    int size = v.size();
    for (int i = v.size() - 1; i >= v.size() - 5; i--)
    {
        vec.push_back(v[i].second);
    }
    int s = 0;
    for (int i = 0; i < 4; i++)
    {
        int pallet_dist = abs((vec[i] * vec[i]) - (vec[i + 1] * vec[i + 1]));
        pallet_dist = sqrt(pallet_dist);
        s = s + pallet_dist;
    }
    int mean = s / 5;
    mean = mean * mean;
    return mean;
}

Mat output1(Mat HSV_image, int sigma, vector<int>vec)
{
    Mat output;
    int d;
    cout << "what will be new colour?" << endl;
    cout << "1.Red" << endl;
    cout << "2.majenta" << endl;
    cout << "3.brown" << endl;
    cout << "4.light brown" << endl;
    cout << "5.cream" << endl;
    cout << "6.yellow" << endl;
    cout << "7.sea green" << endl;
    cout << "8.deep green" << endl;
    cout << "9.grey green" << endl;
    cout << "10.green" << endl;
    cout << "11.skyblue" << endl;
    cout << "12.blue" << endl;
    cout << "13.blue violet" << endl;
    cout << "14.violet" << endl;
    cout << "15.Pink" << endl;
    cin >> d;
    int c_j_next;
    if (d == 1) c_j_next = 0;
    else if (d == 2) c_j_next = 8;
    else if (d == 3) c_j_next = 13;
    else if (d == 4) c_j_next = 15;
    else if (d == 5) c_j_next = 18;
    else if (d == 6) c_j_next = 25;
    else if (d == 7) c_j_next = 40;
    else if (d == 8) c_j_next = 55;
    else if (d == 9) c_j_next = 68;
    else if (d == 10) c_j_next = 75;
    else if (d == 11) c_j_next = 85;
    else if (d == 12) c_j_next = 110;
    else if (d == 13) c_j_next = 129;
    else if (d == 14) c_j_next = 133;
    else if (d == 15) c_j_next = 145;
    for (int i = 0; i < HSV_image.rows; i++)
    {
        for (int j = 0; j < HSV_image.cols; j++)
        {
            int p = HSV_image.at<Vec3b>(i, j)[0];
            int y_i, E_i;
            if (p >= 12 and p <= 18)
            {
                int numa = 0, deno = 0;
                for (int k = 0; k < 5; k++)
                {
                    int e_k = c_j_next - vec[k];
                    float two_sigma = (float)(2 * sigma);
                    float exp_numa = p - vec[k];
                    exp_numa = abs(exp_numa);
                    exp_numa = (-1) * exp_numa;
                    float w_i_j = exp(exp_numa / two_sigma);
                    numa = numa + w_i_j * e_k;
                    deno = deno + e_k;
                }
                E_i = numa / deno;
                y_i = p + E_i;
                HSV_image.at<Vec3b>(i, j)[0] = y_i;
            }
        }
    }
    return output;
}

int main()
{
    Mat image;
    image = imread("C://opencv/carrom.png", -1);	//reading file

    Mat HSV_image; 	//Mat object for storing data
    cvtColor(image, HSV_image, COLOR_BGR2HSV);
    Mat pallet = imread("C://opencv/pallet.jpeg", -1);
    Mat HSV_pallet; 	//Mat object for storing data
    cvtColor(pallet, HSV_pallet, COLOR_BGR2HSV);
    vector<int>vec = colour_name(HSV_pallet);
    int sigma = find_distance(HSV_pallet);
    unordered_set <string> s;
    for (int i = 0; i < 5; i++)
    {
        if ((vec[i] >= 0 and vec[i] <= 5) or (vec[i] >= 158 and vec[i] <= 179)) s.insert("red");
        else if (vec[i] >= 6 and vec[i] <= 11) s.insert("majenta");
        else if (vec[i] >= 12 and vec[i] <= 14) s.insert("brown");
        else if (vec[i] >= 15 and vec[i] <= 16) s.insert("light brown");
        else if (vec[i] >= 17 and vec[i] <= 20) s.insert("cream");
        else if (vec[i] >= 21 and vec[i] <= 29) s.insert("yellow");
        else if (vec[i] >= 30 and vec[i] <= 77) s.insert("green");
        else if (vec[i] >= 78 and vec[i] <= 93) s.insert("sky-blue");
        else if (vec[i] >= 94 and vec[i] <= 127) s.insert("blue");
        else if (vec[i] >= 128 and vec[i] <= 138) s.insert("violet");
        else if (vec[i] >= 139 and vec[i] <= 157) s.insert("pink");

    }
    unordered_set<string> ::iterator itr;
    int x = 1;
    /*for (itr = s.begin(); itr != s.end(); itr++) {
        cout << x << " " << (*itr) << endl;
        x++;
    }*/
    //cout << "Which colour do you want to change?" << endl;
    int c, d;
    //cin >> c;

    Mat output = image.clone();
    //output = output1(HSV_image, sigma, vec);
    output = output2(HSV_image, sigma, vec);
    cvtColor(HSV_image, output, COLOR_HSV2BGR);
    imshow("j", output);
    imwrite("C:/opencv/output.jpg", output);
    waitKey();
    return 0;
}
