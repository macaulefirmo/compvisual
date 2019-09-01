#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

    // Abre o vídeo
    VideoCapture video("video01.mp4");
    if(!video.isOpened()) {

        cout << "ERRO - Nao foi possivel abrir o video!\n" << endl;
        return -1;
    }

    // Salva um novo vídeo como saída
    // int frame_width = video.get(CV_CAP_PROP_FRAME_WIDTH);
    // int frame_height = video.get(CV_CAP_PROP_FRAME_HEIGHT);
    // VideoWriter video_write("output.avi", CV_FOURCC('M','J','P','G'), 10, Size(frame_width,frame_height));

    Mat frame1, frame2, temp, result;
    int countFrame = 0;

    Mat gray, cimg, img, edges;
    vector<Vec3f> circles;
    double p1, p2;
    int initThresh;
    const int maxThresh = 200;

    while (true) {

        // Obtem o frame atual
        video >> frame1;

        if (frame1.empty()) {
            break;
        }

        countFrame++;
        cout << "Frame " << countFrame << endl;

        // Na primeira iteração, frame2 é vazio
        if(!frame2.empty()) {

            // Subtrai o frame 1 do frame 2
            absdiff(frame1, frame2, temp);

//            p1 = initThresh;
//            p2 = initThresh * 0.4;

//            cvtColor(temp, result, COLOR_BGR2GRAY);
//            cvtColor(temp, result, COLOR_BGR2HSV);
//            threshold(temp, result, 25, 255, THRESH_BINARY);
//            HoughCircles(temp, circles, HOUGH_GRADIENT, 1, cimg.rows/64, p1, p2, 25, 50);

            // Exibe o frame na tela
            imshow("Projeto", result);
        }

        // Copia o frame2 para o frame1
        frame1.copyTo(frame2);

        // Grava o vídeo no arquivo de saída
        // video_write.write(frame);

        waitKey(30);
    }

    return 0;
}


