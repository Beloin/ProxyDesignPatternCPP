//
// Created by beloin on 25/04/2022.
//

#ifndef PROXY_HTTPREQUESTERPROXY_H
#define PROXY_HTTPREQUESTERPROXY_H


#include "CachedItem.h"
#include "HTTPRequester.h"

class HTTPRequesterProxy : public HttpRequest {

private:
    int maxSize;
    int currentHeap = 0;
    // Expiration Time in seconds
    int expirationTime = 1;
    CachedItem<HTTPRequester>** requesters;
    void addItem(HTTPRequester *httpRequester);
    HTTPRequester &getHeapItem();
    HTTPRequester &getRequester();


public:
    void makeRequest(string url, string body, string method) override;
    // looks like ObjectPool
    explicit HTTPRequesterProxy(int maxSize);

    bool isEmpty();
    bool isFull();

    void clearCache(long ts);
};


#endif //PROXY_HTTPREQUESTERPROXY_H
