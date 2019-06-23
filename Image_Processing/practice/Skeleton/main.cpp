//
//  main.cpp
//  SkeletonExtraction
//
//  Created by Wonmin Cho on 22/06/2019.
//  Copyright © 2019 Wonmin Cho. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, const char *argv[])
{

  cv::Mat img = cv::imread("images/sk3.png", 0);
  img = 255 - img;
  cv::threshold(img, img, 127, 255, cv::THRESH_BINARY);

  cv::Mat skel(img.size(), CV_8UC1, cv::Scalar(0));
  cv::Mat temp(img.size(), CV_8UC1);
  cv::Mat eroded;
  cv::Mat element = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(3, 3));

  bool done;

  do
  {
    cv::morphologyEx(img, temp, cv::MORPH_OPEN, element);
    cv::bitwise_not(temp, temp);
    cv::bitwise_and(img, temp, temp);
    cv::bitwise_or(skel, temp, skel);
    cv::erode(img, img, element);

    double max;
    cv::minMaxLoc(img, 0, &max);
    done = (max == 0);
  } while (!done);

  cv::imshow("skel", skel);
  cv::waitKey();

  return 0;
}
