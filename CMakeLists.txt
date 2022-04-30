cmake_minimum_required(VERSION 3.10)
project(proxy)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proxy
        main.cpp
        proxy/HTTPRequester.cpp
        proxy/HTTPRequester.h
        proxy/HttpRequest.h
        proxy/CachedItem.h
        proxy/CachedItem.cpp
        proxy/HTTPRequesterProxy.cpp
        proxy/HTTPRequesterProxy.h
        )
