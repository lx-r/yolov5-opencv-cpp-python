#ifndef __DETECTOR_H__
#define __DETECTOR_H__

#include <fstream>
#include <opencv2/opencv.hpp>

namespace xx_det {

    const std::vector<cv::Scalar> colors = {cv::Scalar(255, 255, 0), cv::Scalar(0, 255, 0), cv::Scalar(0, 255, 255), cv::Scalar(255, 0, 0)};

    const float INPUT_WIDTH = 640.0;
    const float INPUT_HEIGHT = 640.0;
    const float SCORE_THRESHOLD = 0.2;
    const float NMS_THRESHOLD = 0.4;
    const float CONFIDENCE_THRESHOLD = 0.4;

    struct Detection
    {
        int class_id;
        float confidence;
        cv::Rect box;
    };

}

#endif