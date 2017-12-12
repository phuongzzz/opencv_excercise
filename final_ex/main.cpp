#include <iostream>
#include <string>
#include "functions.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv){
  Mat image;

  image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

  if(!image.data){
    cout<<"Error loading image" << "\n";
    return -1;
  }

  // Mat blurredImage = gaussianBlur(image);
  // cin.get();

  // histogram(blurredImage);
  // cin.get();
}
