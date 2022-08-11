//
// Created by Ignas Laude on 7/5/21.
//

#ifndef RADIX_RADIXITERATOR_CPP
#define RADIX_RADIXITERATOR_CPP

#include "../include/RadixIterator.h"

template<typename T>
RadixIterator<T>::RadixIterator(Iterator<K, T, S> &wrapped) : baseIter_(wrapped) {}

template<typename T>
RadixIterator<T>::RadixIterator(Iterator<K, T, S> &&wrapped) : baseIter_(wrapped) {}

template<typename T>
RadixIterator<T>::RadixIterator(const RadixIterator &rhs) : baseIter_(rhs.baseIter_) {}

template<typename T>
RadixIterator<T>::RadixIterator(const RadixIterator &&rhs) : baseIter_(rhs.baseIter_) {}

template<typename T>
std::pair<const typename RadixIterator<T>::K, T&> RadixIterator<T>::operator*() {
    const std::string val(getWord());
    return std::pair<const std::string, T &>(val,*(get()->value_));
}

template<typename T>
std::pair<const typename RadixIterator<T>::K, T&> RadixIterator<T>::operator->() {
    const std::string val(getWord());
    return std::pair<const std::string, T &>(val,*(get()->value_));
}

template<typename T>
Node<typename RadixIterator<T>::K, T, RadixIterator<T>::S> *&RadixIterator<T>::get() {
    return baseIter_.get();
}

template<typename T>
void RadixIterator<T>::swap(RadixIterator &rhs) {
    baseIter_.swap(rhs.baseIter_);
}

template<typename T>
RadixIterator<T> &RadixIterator<T>::operator=(const RadixIterator &rhs) {
    if (this != &rhs) {
        RadixIterator ph(rhs);
        this->swap(ph);
    }
    return *this;
}

template<typename T>
RadixIterator<T> &RadixIterator<T>::operator=(const RadixIterator &&rhs) {
    return *this = rhs;
}

template<typename T>
RadixIterator<T> &RadixIterator<T>::operator++() {
    do {
        if (baseIter_.getIndex() >= S)
            break;
        ++baseIter_;
    }
    while (!baseIter_.isArticleEnd());

    return *this;
}

template<typename T>
RadixIterator<T> RadixIterator<T>::operator++(int) {
    auto it(*this);
    ++(*this);
    return it;
}

template<typename T>
bool RadixIterator<T>::operator==(const RadixIterator &rhs) const {
    return this == &rhs || baseIter_ == rhs.baseIter_;
}

template<typename T>
bool RadixIterator<T>::operator!=(const RadixIterator &rhs) const {
    return !(*this == rhs);
}

template<typename T>
std::string RadixIterator<T>::getWord() {
    auto it(baseIter_);
    std::string s;
    while (it.get()->parent_ != nullptr) {
        s = it.first() + s;
        it.moveUp();
    }
    return s;
}

#endif // RADIX_RADIXITERATOR_CPP
