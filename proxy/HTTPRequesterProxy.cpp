//
// Created by beloin on 25/04/2022.
//

#include <chrono>
#include "iostream"
#include "HTTPRequesterProxy.h"

using namespace std;

HTTPRequesterProxy::HTTPRequesterProxy(int maxSize) {
    this->maxSize = maxSize;
    this->requesters = (CachedItem<HTTPRequester>**)
            malloc(sizeof (CachedItem<HTTPRequester>*)*maxSize);
}


void HTTPRequesterProxy::makeRequest(string url, string body, string method) {
    // Get one requester and request
    HTTPRequester *rq = &getRequester();
    return rq->makeRequest(url, body, method);
}

bool HTTPRequesterProxy::isEmpty() {
    return this->currentHeap == 0;
}

bool HTTPRequesterProxy::isFull() {
    return currentHeap == maxSize - 1;
}

void HTTPRequesterProxy::addItem(HTTPRequester *httpRequester) {
    if (isFull()) return;
    // Raise time to have longer cache item
    long ctms = chrono::system_clock::now().time_since_epoch().count();
    ctms+= expirationTime;

    if (this->currentHeap < maxSize) {
        currentHeap++;
        this->requesters[currentHeap] = new CachedItem<HTTPRequester>(httpRequester, ctms);
    }
}

// check which is better
//void HTTPRequesterProxy::getHeapItem(HTTPRequester *rq) {
//    *rq = requesters[currentHeap].getCachedInstance();
//}

//HTTPRequester * HTTPRequesterProxy::getHeapItem() {
//    return &requesters[currentHeap].getCachedInstance();
//}

HTTPRequester &HTTPRequesterProxy::getHeapItem() {
    return requesters[currentHeap]->getCachedInstance();
}

HTTPRequester &HTTPRequesterProxy::getRequester() {
    // In order to make full effective use of the Design Pattern, this part should be an ObjectPool.
    if (!isFull()) {
        auto *rq = new HTTPRequester(2);
        this->addItem(rq);
    }

    return this->getHeapItem();
}

void HTTPRequesterProxy::clearCache(long ts) {
//    for (int i = 0; i < currentHeap; ++i) {
//        auto c = this->requesters[i];
//        if (c->isExpired(ts)) {
//            cout << "Cleaning: " << "THIS WILL BE DELETED" << endl;
//            delete &c->getCachedInstance();
//            delete c;
//        }
//    }
    // Fix array
}

