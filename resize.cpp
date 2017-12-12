#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
  // cv::Mat src_img = cv::imread("../../image/lenna.png", 1);
  Mat src_img = imread( argv[1], 1 );
  if(src_img.empty()) return -1;
  Mat dst_img1;
  Mat dst_img2(src_img.rows*0.5, src_img.cols*2.0, src_img.type());

  // INTER_LINER（バイリニア補間）でのサイズ変更
  resize(src_img, dst_img1, cv::Size(), 0.5, 0.5);
  // INTER_CUBIC（バイキュービック補間）でのサイズ変更
  resize(src_img, dst_img2, dst_img2.size(), cv::INTER_CUBIC);

  namedWindow("resize image1", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  namedWindow("resize image2", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  cv::imshow("resize image1", dst_img1);
  cv::imshow("resize image2", dst_img2);
  cv::waitKey(0);
}
