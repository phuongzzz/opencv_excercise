#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat histogram(Mat imageSrc) {
  Mat imageHsv, imageDst;

  cvtColor(imageSrc, imageHsv, CV_BGR2HSV);

  vector<Mat> hsvChannels;
  // Tách imageHsv thành 3 kênh màu
  split(imageHsv, hsvChannels);

  // Cân bằng histogram kênh màu v (Value)
  equalizeHist(hsvChannels[2], hsvChannels[2]);

  // Trộn ảnh
  merge(hsvChannels, imageHsv);

  // Chuyển đổi HSV sang RGB để hiển thị
  cvtColor(imageHsv, imageDst, CV_HSV2BGR);

  imshow("imageSrc", imageSrc);
  cout << "enhancing constrast with equalize histogram for color image" << endl;
  imshow("imageDst", imageDst);

  waitKey(0);
  return imageDst;
}

Mat gaussianBlur (Mat imageSrc) {
  Mat blurredImage;
  GaussianBlur(imageSrc, blurredImage, Size( 9, 9 ), 1.0);
  imshow("Blurred Image" , blurredImage);
  cout << "Blurring with GaussianBlur" << endl;
  waitKey(0);
  return blurredImage;
}

Mat kmeans (Mat imageSrc) {
  Mat imageDst(imageSrc.size(), imageSrc.type());
  Mat points;
  imageSrc.convertTo(points, CV_32FC3);
  points = points.reshape(3, imageSrc.rows*imageSrc.cols);

  Mat_<int> clusters(points.size(), CV_32SC1);
  Mat centers;

  const int cluster = 5;
  kmeans(points, cluster, clusters, cvTermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1.0), 1, KMEANS_PP_CENTERS, centers);

  MatIterator_<Vec3b> itd = imageDst.begin<Vec3b>(),itd_end = imageDst.end<Vec3b>();
  for (int i = 0; itd != itd_end; ++itd, ++i) {
      Vec3f &color = centers.at<Vec3f>(clusters(i), 0);
      (*itd)[0] = saturate_cast<uchar>(color[0]);
      (*itd)[1] = saturate_cast<uchar>(color[1]);
      (*itd)[2] = saturate_cast<uchar>(color[2]);
  }
  imshow("Output", imageDst);
  waitKey(0);
  return imageDst;
}

Mat morphology_operations (Mat imageSrc) {
  int morph_size = 1;
  Mat element = getStructuringElement( MORPH_RECT, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
  // cout << element;

  Mat morphologyImage; // result matrix
    // Apply the specified morphology operation
  for (int i=1;i<10;i++){
    morphologyEx( imageSrc, morphologyImage, MORPH_TOPHAT, element, Point(-1,-1), i );
    //morphologyEx( src, dst, MORPH_TOPHAT, element ); // here iteration=1
    imshow("morphologyImage", morphologyImage);
    waitKey(3);
    }
  return morphologyImage;
}

int main(int argc, char** argv){
  Mat image;

  image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

  if(!image.data){
    cout<<"Error loading image" << "\n";
    return -1;
  }

  Mat blurredImage = gaussianBlur(image);
  cin.get();

  Mat historgramImage = histogram(blurredImage);
  cin.get();

  Mat kmeansImage = kmeans(historgramImage);
  cin.get();

  Mat morphologyImage = morphology_operations(kmeansImage);
  cin.get();

}
