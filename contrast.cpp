//DUNG LINEAR TRANSFORM (GIAN HISTORGRAM)
#include <stdio.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

int main(int argc, char** argv)
{
  Mat image = imread( argv[1] );
  Mat imageDst = image.clone();
  if (!image.data)
  {
    printf("Could not open or find the image\n");
    return -1;
  }

#define NUMBER_CHANNEL_RGB_COLOR_MODEL 3
  double contrast = 2.0; // A
  int brightness = 30; // B
  for (int indexRow = 0; indexRow < image.rows; indexRow++) {
    for (int indexCol = 0; indexCol < image.cols; indexCol++) {
      for (int channel = 0; channel < NUMBER_CHANNEL_RGB_COLOR_MODEL; channel++) {
        imageDst.at<Vec3b>(indexRow, indexCol)[channel] = saturate_cast<uchar>
          (contrast*(imageDst.at<Vec3b>(indexRow, indexCol)[channel]) + brightness);
      }
    }
  }
  /*
    cong thuc thay doi do sang cua anh : G(x,y) = A*F(x, y) + B
    F(x,y): gia tri pixel cua anh chua duoc xu ly
    G(x,y): gia tri pixel cua anh da duoc xu ly
    A: dac trung cho su tuong phan cua G va F: G/F = A
    B: luong sang thay doi
  */

  imshow("Before", image);
  imshow("After", imageDst);

  // Wait input and exit
  waitKey(0);

  return 0;
}
