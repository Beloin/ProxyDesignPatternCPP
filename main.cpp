//
// Created by beloin on 25/04/2022.
//

#include <ctime>
#include <cmath>
#include <utility>
#include <sstream>
#include "iostream"
#include "proxy/HTTPRequester.h"
#include "chrono"
#include "proxy/HTTPRequesterProxy.h"
#include "thread"

using namespace std;
using namespace std::chrono_literals;

void makeReq(HttpRequest *rq, string method) {
    rq->makeRequest("http://localhost:8080/api", R"({ "head": "raw" })", std::move(method));
}

void clearCache(HTTPRequesterProxy *p) {
    cout << "Starting Cleaning Cache\n";
    long tm = chrono::system_clock::now().time_since_epoch().count();
    p->clearCache(tm);
}

int main() {
    srand(time(nullptr));

    auto *proxy = new HTTPRequesterProxy(10);

    makeReq(proxy, "POST");
    makeReq(proxy, "GET");
    makeReq(proxy, "PUT");

    this_thread::sleep_for(2000ms);
    clearCache(proxy);

    return 0;
}