//
// Created by beloin on 25/04/2022.
//

#ifndef PROXY_PROXY_H
#define PROXY_PROXY_H

template<typename T>
class CachedItem {

private:
    long timestamp{};
    T *item;

public:
    T& getCachedInstance();
    bool isExpired(long ts);
    CachedItem<T>(T *item, long ts);
};


#endif //PROXY_PROXY_H
