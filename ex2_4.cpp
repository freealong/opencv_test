/*
 * ex2_4.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: yongqi
 */

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

void onTrackbarSlide(int pos, void* p) {
  VideoCapture* cap = (VideoCapture*)p;
  cap->set(CV_CAP_PROP_POS_FRAMES, pos);
}

int ex2_4(int argc, char** argv) {
  int g_slider_position = 0;
  int g_run = 1, g_dontset = 0;
  VideoCapture g_cap;

  namedWindow("example", WINDOW_AUTOSIZE);
  g_cap.open(string(argv[1]));
  int frames = (int)g_cap.get(CV_CAP_PROP_FRAME_COUNT);
  int tmpw = (int)g_cap.get(CV_CAP_PROP_FRAME_WIDTH);
  int tmph = (int)g_cap.get(CV_CAP_PROP_FRAME_HEIGHT);
  cout << "Video has " << frames << "frames of dimensions ("
      << tmpw << ", " << ")." << endl;
  createTrackbar("Position", "example", &g_slider_position, frames,
                 onTrackbarSlide, &g_cap);
  Mat frame;
  while (true) {
    if (g_run != 0) {
      g_cap >> frame;
      if (!frame.data) break;
      int current_pos = (int)g_cap.get(CV_CAP_PROP_POS_FRAMES);
      g_dontset = 1;
      setTrackbarPos("Position", "example", current_pos);
      imshow("example", frame);
      g_run -= 1;
    }
    char c = (char)waitKey(10);
    if (c == 's') {
      g_run = 1;
      cout << "Single step, run = " << g_run << endl;
    }
    if (c == 'r') {
      g_run = -1;
      cout << "Run mode, run = " << g_run << endl;
    }
    if (c == 27)
      break;
  }
  return 0;
}
