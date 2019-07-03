cmake_minimum_required(VERSION 3.14)

SET(detour_SRCS
        cn_tursom_unsafe_NetUtils.cpp
        net.cpp
        )

SET(detour_HDRS
        cn_tursom_unsafe_NetUtils.h
        net.h
        )

INCLUDE_DIRECTORIES(Include)

ADD_LIBRARY(NativeKotlinServer SHARED ${detour_SRCS} ${detour_HDRS})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -I /usr/lib/jvm/java-8-openjdk/include/ -I /usr/lib/jvm/java-8-openjdk/include/linux")