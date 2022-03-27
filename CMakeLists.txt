cmake_minimum_required(VERSION 3.16)
project(LearnOpenCv)

set(CMAKE_CXX_STANDARD 11)

set( CMAKE_CXX_FLAGS "-std=c++11")

set(OpenCV_DIR /home/lx/opencv/build)
find_package( OpenCV 4 REQUIRED )
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

SET(SRC "cpp/src")
SET(INC "cpp/inc")

INCLUDE_DIRECTORIES(${INC})
set(MAIN ON)
if(MAIN)
    add_executable(yolo ${SRC}/Detector.cpp ${SRC}/Tracker.cpp)
    TARGET_LINK_LIBRARIES(yolo ${OpenCV_LIBS})
endif(MAIN)
