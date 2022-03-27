#ifndef __TRACKER_H__
#define __TRACKER_H__

#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <Detector.h>

using namespace xx_det;

namespace xx_tracker 
{
    struct Instance
    {
        int circleCenter[2]; // center_x, center_y
        int connectorBox[4]; // x1, y1, x2, y2 (pixel coordinates)
        int pcbBox[4]; // x1, y1, x2, y2 (pixel coordinates)
        cv::Mat imgPatch;
        int unmatchCnt; // unmatched times, to judge whether a pcb had left
        int errorCnt; // error category times checked for one pcb
    };
    
    enum TrackState {
        TS_NONE = 0,
        Tentative,
        Confirmed,
        Deleted
    };

    class Tracker
    {
        public:

            Tracker(int displaceThresh = 30, 
                    int errorCntThresh = 3,
                    float resembleThesh = 0.8);
            ~Tracker(void);

            void updateInstances(std::vector<Detection>& detections, cv::Mat &src);
            std::vector<Detection> getNewestInstances(void);
            void clearLeftInstances(void);

        private:
            /**
             * https://zh.wikipedia.org/wiki/%E4%BD%99%E5%BC%A6%E7%9B%B8%E4%BC%BC%E6%80%A7
             * */
            float cosineSimilarity(const cv::Mat& descr1, const cv::Mat& descr2);

            int displaceThresh;
            int errorCntThresh;
            float resembleThesh;
            std::vector<Instance> instances;
    };

}

#endif 