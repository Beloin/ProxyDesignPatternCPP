//
// Created by beloin on 25/04/2022.
//

#ifndef PROXY_HTTPREQUEST_H
#define PROXY_HTTPREQUEST_H
#include "string"

using namespace std;

class HttpRequest {

public:
    virtual void makeRequest(string url, string body, string method) = 0;
};


#endif //PROXY_HTTPREQUEST_H
