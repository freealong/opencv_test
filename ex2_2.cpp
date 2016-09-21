/*
 * ex2_2.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: yongqi
 */

#include "ex.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int ex2_2(int argc, char** argv) {
  Mat img = imread(argv[1], -1);
  if (img.empty()) return -1;
  namedWindow("Example", WINDOW_AUTOSIZE);
  imshow("Example", img);
  waitKey(0);
  destroyWindow("Example");
  return 0;
}
