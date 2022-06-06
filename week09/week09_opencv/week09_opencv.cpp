#include <opencv/highgui.h>
int main()
{
    IplImage * img = cvLoadImage("zrr.jpg");
    cvShowImage("week09", img);
    cvWaitKey();
}
