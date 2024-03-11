#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
using namespace cv;
using namespace std;
int main()
{
    Mat img(400, 500, CV_8UC3, Scalar(255, 255, 255));
    int fontFace = FONT_HERSHEY_SIMPLEX;
    double fontScale = 1;
    Scalar color(0, 0, 0);
    Point textOrg(100, 200);
    putText(img, "Praktika", textOrg, fontFace, fontScale, color, 2);
    rectangle(img, Rect(10, 10, 80, 80), Scalar(0, 255, 0), -1); 
    rectangle(img, Rect(img.cols - 90, 10, 80, 80), Scalar(0, 0, 0), 2); 
    Point2f center(50, img.rows - 30);
    Size2f size(40, 20);
    float angle = 0.0f; 
    Scalar color_ellipse(255, 0, 0); 
    ellipse(img, center, size, angle, 0, 360, color_ellipse, -1);
    Point center_circle(img.cols - 90, img.rows - 90);
    int radius = 40;
    circle(img, center_circle, radius, Scalar(0, 0, 255), -1); 
    Mat mask(img.rows, img.cols, CV_8UC1, Scalar(0));
    int radius1 = 50;
    int x = img.cols / 2;
    int y = img.rows / 2;
    circle(mask, Point(x, y), radius1, Scalar(255), -1);
    Mat masked_img;
    img.copyTo(masked_img, mask);
    Mat img1(img.rows / 2, img.cols / 2, img.type());
    Mat img2(img.rows / 2, img.cols / 2, img.type());
    Mat img3(img.rows / 2, img.cols / 2, img.type());
    Mat img4(img.rows / 2, img.cols / 2, img.type());
    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            if (i < img.rows / 2) 
            {
                if (j < img.cols / 2) 
                {
                    img1.at<Vec3b>(i, j) = img.at<Vec3b>(i, j);
                }
                else 
                {
                    img2.at<Vec3b>(i, j - img.cols / 2) = img.at<Vec3b>(i, j);
                }
            }
            else 
            {
                if (j < img.cols / 2) 
                {
                    img3.at<Vec3b>(i - img.rows / 2, j) = img.at<Vec3b>(i, j);
                }
                else 
                {
                    img4.at<Vec3b>(i - img.rows / 2, j - img.cols / 2) = img.at<Vec3b>(i, j);
                }
            }
        }
    }
    imshow("Praktika", img);
    imshow("Часть 1", img1);
    imshow("Часть 2", img2);
    imshow("Часть 3", img3);
    imshow("Часть 4", img4);
    imshow("Изображение с маской", masked_img);
    waitKey(0);
    return 0;
}