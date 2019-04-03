//
//  main.cpp
//  Histogram
//
//  Created by Wonmin Cho on 03/04/2019.
//  Copyright © 2019 Wonmin Cho. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

cv::Mat equalizeHistogram(cv::Mat src) {
    
    cv::Mat res(src.rows, src.cols, CV_8U);
    int pdf[255] = {0};
    int cdf[255] = {0};
    int tmp = 0;
    
    for (int i=0; i<src.rows; i++) {
        for (int j=0; j<src.cols; j++) {
            int val = src.at<uchar>(i,j);
            pdf[val] = pdf[val]?pdf[val]+1:1;
        }
    }
    
    for (int i=1; i<255; i++) {
        tmp += pdf[i-1];
        cdf[i] = tmp;
    }

    for (int i=0; i<src.rows; i++) {
        for (int j=0; j<src.cols; j++) {
            int val = src.at<uchar>(i,j);
            res.at<uchar>(i,j) = uchar(float(cdf[val])/float(tmp)*255.0);
        }
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    cv::Mat src = cv::imread("/Users/wonmin/workspace/opencv/Tem.jpg", 0);
    cv::Mat out = equalizeHistogram(src);
    
    cv::imshow("origin", src);
    cv::waitKey();
    cv::imshow("my equalize historgam", out);
    cv::waitKey();
    
//    cv::equalizeHist(src, src);
//    cv::imshow("opencv equalizeHist", src);
//    cv::waitKey(0);
    
    return 0;
}
