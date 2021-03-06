#include <cxcore.h>
#include <cv.h>
#include <highgui.h>

int main(int argc, char *argv[])
{
  IplImage *img = cvLoadImage(argv[1], CV_LOAD_IMAGE_ANYCOLOR);
  IplImage *gray = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
  IplImage *bin = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);

  if( img == NULL ){
    fprintf(stderr, "no such file or directory\n");
    exit(-1);
  }

  cvCvtColor(img, gray, CV_RGB2GRAY);
  cvThreshold(gray, bin, 128, 255, CV_THRESH_BINARY|CV_THRESH_OTSU);

  cvSaveImage("Out.tif", bin);
  cvReleaseImage(&img); 
  cvReleaseImage(&bin);

  return 0;
}
