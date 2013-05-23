project(cpoo)

cmake_minimum_required(VERSION 2.4.0)

find_package( OpenCV REQUIRED )

if (USE_QT)
find_package(Qt4 REQUIRED) # find and setup Qt4 for this project
endif (USE_QT)



add_subdirectory(src)


