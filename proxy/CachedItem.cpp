//
// Created by beloin on 25/04/2022.
//

#include "CachedItem.h"
#include "HTTPRequester.h"


template<typename T>
T &CachedItem<T>::getCachedInstance() {
    return *item;
}

template<typename T>
CachedItem<T>::CachedItem(T *item, long ts) {
    this->item = item;
    this->timestamp = ts;
}

template<typename T>
bool CachedItem<T>::isExpired(long ts) {
    return ts > timestamp;
}

template class CachedItem<HTTPRequester>;