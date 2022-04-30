//
// Created by beloin on 25/04/2022.
//

#ifndef PROXY_HTTPREQUESTER_H
#define PROXY_HTTPREQUESTER_H


#include "HttpRequest.h"

class HTTPRequester : public HttpRequest {

private:
    // Which means 100x100x100
    int defaultSize = 100;
    double ***veryHeavyMatrix;

public:
    explicit HTTPRequester(double sizeMultiplier);
    void makeRequest(string url, string body, string method) override;
};


#endif //PROXY_HTTPREQUESTER_H
