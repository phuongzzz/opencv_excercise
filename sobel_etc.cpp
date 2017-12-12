#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int
main (int argc, char *argv[])
{
  cv::Mat src_img = cv::imread("../../image/lenna.png", 0);
  if(src_img.empty()) return -1;

  // Sobel
  cv::Mat tmp_img;
  cv::Mat sobel_img;
  cv::Sobel(src_img, tmp_img, CV_32F, 1, 1);
  cv::convertScaleAbs(tmp_img, sobel_img, 1, 0);

  // Canny
  cv::Mat canny_img;
  cv::Canny(src_img, canny_img, 50, 200);

  cv::namedWindow("Original(Grayscale)", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  cv::namedWindow("Sobel", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  cv::namedWindow("Laplacian", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  cv::namedWindow("Canny", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  cv::imshow("Original(Grayscale)", src_img);
  cv::imshow("Sobel", sobel_img);
  cv::imshow("Laplacian", laplacian_img);
  cv::imshow("Canny", canny_img);
  cv::waitKey(0);
}
