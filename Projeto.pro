QT       += core
QT       -= gui

TARGET = OpenCV-Ex1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

win32 {
    INCLUDEPATH += C:/opencv-3.4.1-build/install/include

    LIBS += -LC:/opencv-3.4.1-build/install/x64/mingw/lib \
        -llibopencv_core341 \
        -llibopencv_highgui341 \
        -llibopencv_imgproc341 \
        -llibopencv_features2d341 \
        -llibopencv_calib3d341 \
        -llibopencv_ml341 \
        -llibopencv_features2d341 \
        -llibopencv_videoio341
}

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv

}
