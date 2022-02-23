#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
  Mat main_image,watermark, watermarked_image;
  string file;
  double alpha,beta;
  /* Enter path of the file if file is not in the directory of the project */
  cout << "\nEnter name of a main image file with extension: ";
  /* cin function cannot read space. Hence we have used getline function here. */
  getline(cin, file);
  /* imread() is used to read an image */
  main_image = imread(file);
  /* Checking if main_image object contains an image */
  if (main_image.data==0)
  {
    cout << "\n\nError..!!\n";
    cout << "\nCheck=>";
    cout << "\n1. Desired image is in the folder of the project";
    cout << "\n2. You have mentioned extension of an image file\n";
    exit(0);
  }

  //resizeing 
  Mat resized_img;
  int nwidth = 800;
  int nheight = 600; 

  resize(main_image, resized_img, Size(nwidth,nheight), INTER_LINEAR);
  watermark = imread("w.png");

  /* alpha denotes the opacity of the watermark and beta denotes the opacity of the main_image. You can choose alpha and beta values as per your choice but make sure that the sum of alpha and beta is 1. Here we have used alpha as 0.1 and beta as 0.9 */
  alpha = 0.1;
  beta = 1 - alpha;
  /* Here we are merging 'main_image' and 'watermark' and output will be stored in 'watermarked_image' */
  addWeighted(watermark, alpha, resized_img, beta, 0.0, watermarked_image);
  /* namedWindow() is used to create a window with the mentioned name. In our case, window name is 'Watermarked image' */
  namedWindow("Watermarked image", WINDOW_AUTOSIZE);
  /* imshow() is used to display an image */
  imshow("Watermarked image", watermarked_image);
  /* Press esc to exit */
  if (waitKey(0) == 27)
  {
    exit(0);
  }
  /* when everything done, close all windows */
  destroyAllWindows();
}