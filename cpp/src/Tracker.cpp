#include <Tracker.h>

using namespace xx_tracker;

Tracker::Tracker(int displaceThresh, int errorCntThresh, float resembleThesh)
{
    std::cout << "Tracker: " << displaceThresh << std::endl;
    this->displaceThresh = displaceThresh;
    this->errorCntThresh = errorCntThresh;
    this->resembleThesh = resembleThesh;
}

Tracker::~Tracker(void)
{

}

void Tracker::updateInstances(std::vector<Detection>& detections, cv::Mat &src)
{
    for(auto det : detections)
    {
        cv::Mat imgPatch = src(det.box);
        std::cout << "cosine similirity: " << this->cosineSimilarity(imgPatch, imgPatch) << std::endl;
    }
    
}


void Tracker::clearLeftInstances(void) 
{

}

float Tracker::cosineSimilarity(const cv::Mat& descr1, const cv::Mat& descr2)
{
    CV_Assert(!descr1.empty());
    CV_Assert(!descr2.empty());
    CV_Assert(descr1.size() == descr2.size());

    double xy = descr1.dot(descr2);
    double xx = descr1.dot(descr1);
    double yy = descr2.dot(descr2);
    double norm = sqrt(xx * yy) + 1e-6;
    return static_cast<float>(xy / norm);
}