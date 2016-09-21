/*
 * ex2-3.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: yongqi
 */

#include "ex.hpp"

#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int ex2_3(int argc, char** argv) {
  namedWindow("example", WINDOW_AUTOSIZE);
  VideoCapture cap;
  cap.open(string(argv[1]));
  Mat frame;
  while (true) {
    cap >> frame;
    if (!frame.data) {
      cout << "load frame failed" << endl;
      break;
    }
    imshow("example", frame);
    if (waitKey(33) >= 0) break; // has key pressed in 33ms then break
  }
  return 0;
}
