PROJECT(main)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

find_package(OpenCV REQUIRED)

aux_source_directory(. DIR_SRCS)
ADD_EXECUTABLE(main ${DIR_SRCS})
target_link_libraries(main ${OpenCV_LIBS})