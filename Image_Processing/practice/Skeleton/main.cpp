//
//  main.cpp
//  SkeletonExtraction
//
//  Created by Wonmin Cho on 22/06/2019.
//  Copyright © 2019 Wonmin Cho. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{

  vector<cv::Mat> AList;
  vector<cv::Mat> TList;
  vector<cv::Mat> SList;

  AList[0] = 255 - cv::imread("images/sk1.png", 0);

  cv::Mat kernel = cv::Mat(5, 5, CV_8U);

  cv::morphologyEx(AList[0], TList[0], cv::MORPH_OPEN, cv::Mat(15, 15, CV_8U));
  cv::bitwise_and(~TList[0], AList[0], SList[0]);

  for (int i = 1; i < 10; i++)
  {
    cv::erode(AList[i - 1], AList[i], kernel);
    cv::morphologyEx(AList[i], TList[i], cv::MORPH_OPEN, cv::Mat(15, 15, CV_8U));
    cv::bitwise_and(~TList[i], AList[i], SList[i]);
  }

  cv::imshow("S1", SList[9]);
  cv::waitKey();

  return 0;
}
