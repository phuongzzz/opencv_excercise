#include <iostream>
#include <string>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#pragma GCC diagnostic ignored "-Wwrite-strings"

using namespace std;
using namespace cv;

/*Tang cuong do tuong phan*/
void histogrameq_for_grayImg(Mat image);
void histogrameq_for_colorImg(Mat image);
/*nhan chap*/
void nhanchap(Mat image, int kernel_size);
/*Lam tron anh bang loc thong thap*/
void gaussian(Mat image);
void medianFilter(Mat image);
/*Phat hien canh bang loc thong cao*/
void laplace(Mat image);
void sobel(Mat image);
void canny(Mat image);
/*xu ly anh trong mien tan so*/
void dft(Mat image);
/*phan vung anh*/
void kmeans(Mat image);
void watershared(Mat image);
/*hau xu ly anh*/
void morphology(Mat image);
/*thoat chuong trinh*/
void exit();

int selection = 0;
int k = 0;

int main(int argc, char** argv) {
  Mat image;
  image = imread(argv[1]);
  if (!image.data)  { return -1; }

  while (k == 0) {
    selection = 0;
    cout << " Please choose from the following options: \n";
    cout << " 1. Increasing Constrast.\n";
    cout << " 2. Convolution.\n";
    cout << " 3. Smoothing image.\n";
    cout << " 4. Edge detection.\n";
    cout << " 5. Discrete Fourier Transform.\n";
    cout << " 6. Image Segmentation.\n";
    cout << " 7. Morphology.\n";
    // cout << " 8.Canny\n";
    // cout << " 9.DFT.\n";
    // cout << " 10.Kmeans.\n";
    // cout << " 11.Watershared.\n";
    // cout << " 12.Morphology.\n";
    cout << " 8. Exit.\n";
    cout << "Your selection:\t";
    cin >> selection;

  switch (selection) {
    case 1: {
      cout << "Chon phuong phap can lam" << endl;
      cout << "a. Histogram Equalize (for grayscale image)" << endl;
      cout << "b. Histogram Equalize (for color image)" << endl;
      cout << "Your selection: " << endl;
      char select_method;
      cin >> select_method;
      switch(select_method) {
        case 'a': {
          histogrameq_for_grayImg(image);
          break;
        }
        case 'b' : {
          histogrameq_for_colorImg(image);
          break;
        }
      }
      break;
    }
    case 2: {
      cout << "Convolution with 2D filter" << endl;
      cout << "Enter your desired kernel size: " << endl;
      int kernel_size;
      cin >> kernel_size;
      nhanchap(image, kernel_size);
      break;
    }
    case 3: {
      cout << "Smoothing image" << endl;
      cout << "Choose your desired method: " << endl;
      cout << "a. Using Gaussian Filter" << endl;
      cout << "b. Using Median Filter" << endl;
      char select_method;
      cin >> select_method;
      switch(select_method) {
        case 'a': {
          cout << "Using gaussian filter" << endl;
          gaussian(image);
          break;
        }
        case 'b': {
          cout << "Using median filter" << endl;
          medianFilter(image);
        }
      }
      break;
    }
    case 8: {
      exit();
      break;
    }
  }
}
 return 0;
}

void nhanchap(Mat image, int kernel_size) {
  cout << "Nhan Chap" << endl;
  Mat dst,kernel;
  /*
    Tao ma tran loc de nhan chap voi ma tran dau vao
    Cac phan tu cua ma tran deu bang nhau => tien hanh thao tac loc thong thap
  */
  kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);

  /*
    Ap dung nhan chap anh voi ma tran do
  */
  filter2D(image, dst, -1 , kernel, Point( -1, -1 ), 0, BORDER_DEFAULT );
  namedWindow( "nhan chap day ahihi", CV_WINDOW_AUTOSIZE );
  imshow( "nhan chap day ahihi", dst );
  waitKey(0);
}

void histogrameq_for_grayImg(Mat image){
  Mat image_dst;
  char* source_window = "Source image";
  char* equalized_window = "Equalized Image";

  cvtColor( image, image, CV_BGR2GRAY );

  equalizeHist( image, image_dst );

  namedWindow( source_window, CV_WINDOW_AUTOSIZE );
  namedWindow( equalized_window, CV_WINDOW_AUTOSIZE );

  imshow( source_window, image );
  imshow( equalized_window, image_dst );

  waitKey(0);
}

void histogrameq_for_colorImg(Mat image){
  Mat imageHsv, imageDst;
  cvtColor(image, imageHsv, CV_BGR2HSV);

  vector<Mat> hsvChannels;
  // Tách imageHsv thành 3 kênh màu
  split(imageHsv, hsvChannels);

  // Cân bằng histogram kênh màu v (Value)
  equalizeHist(hsvChannels[2], hsvChannels[2]);

  // Trộn ảnh
  merge(hsvChannels, imageHsv);

  // Chuyển đổi HSV sang RGB để hiển thị
  cvtColor(imageHsv, imageDst, CV_HSV2BGR);

  imshow("imageSrc", image);

  imshow("imageDst", imageDst);

  waitKey(0);
}

void gaussian(Mat image){
  Mat blurredImage;
  /*
    Ap dung bo loc Gauss
    Object Size bieu thi kich co cua bo loc (la gioi han cua viec lam mo anh)
  */
  GaussianBlur( image, blurredImage, Size( 9, 9 ), 1.0);
  imshow("Blurred Image" , blurredImage);
  waitKey(0);
}

void medianFilter(Mat image){
  //todo
}
void laplace(Mat image){
  //todo
}
void sobel(Mat image){
  //todo
}
void canny(Mat image) {
  //todo
}
void dft(Mat image) {
  //todo
}

void kmeans(Mat image) {
  //todo
}

void watershared(Mat image) {
  //todo
}

void morphology(Mat image) {
  //todo
}

void exit() {
  cout << endl;
  cout << "See you soon!\n";
  k = 1;
}
