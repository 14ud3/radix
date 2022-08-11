//
// Created by Ignas Laude on 7/5/21.
//

#ifndef RADIX_RADIX_CPP
#define RADIX_RADIXT_CPP

#include "../include/Radix.h"

template<typename T>
radix<T>::radix() : trie_() {}

template<typename T>
radix<T>::radix(const radix<T> &rhs) : trie_(rhs.trie_) {}

template<typename T>
radix<T>::radix(const radix<T> &&rhs) : trie_(rhs.trie_) {}

template<typename T>
radix<T> &radix<T>::operator=(const radix<T> &rhs) {
    if (this != &rhs) {
        radix<T> ph(rhs);
        this->swap(ph);
    }
    return *this;
}

template<typename T>
radix<T> &radix<T>::operator=(const radix<T> &&rhs) {
    return *this = rhs;
}

template<typename T>
bool radix<T>::empty() const noexcept {
    return trie_.empty();
}

template<typename T>
uint32_t radix<T>::size() const noexcept {
    return trie_.size();
}

template<typename T>
void radix<T>::clear() noexcept {
    trie_.clear();
}

template<typename T>
typename radix<T>::iterator radix<T>::insertOrAssign(std::pair<key_type, mapped_type> &p, Node *ancestor) {
    return insertOrAssign(p.first,p.second,ancestor);
}

template<typename T>
typename radix<T>::iterator radix<T>::insertOrAssign(std::pair<key_type, mapped_type> &&p, Node *ancestor) {
    return insertOrAssign(p.first,p.second,ancestor);
}

template<typename T>
typename radix<T>::iterator radix<T>::insertOrAssign(key_type article, mapped_type &value, Node *ancestor) {
    return iterator(trie_.insertOrAssign(article,value,ancestor));
}

template<typename T>
typename radix<T>::iterator radix<T>::insertOrAssign(key_type article, mapped_type &&value, Node *ancestor) {
    return insertOrAssign(article,value,ancestor);
}

template<typename T>
void radix<T>::erase(key_type article, Node *ancestor) {
    trie_.erase(article,ancestor);
}

template<typename T>
void radix<T>::swap(radix &rhs) noexcept {
    trie_.swap(rhs.trie_);
}

template<typename T>
typename radix<T>::iterator radix<T>::find(key_type article) {
    return iterator(trie_.find(article));
}

template<typename T>
std::pair<bool, typename radix<T>::iterator> radix<T>::scout(radix::key_type article, Node *ancestor) {
    return trie_.scout(article,ancestor);
}

template<typename T>
bool radix<T>::contains(radix::key_type article, Node *ancestor) {
    return trie_.contains(article,ancestor);
}

template<typename T>
bool radix<T>::operator==(const radix &rhs) const {
    return trie_ == rhs.trie_;
}

template<typename T>
bool radix<T>::operator!=(const radix &rhs) const {
    return !(*this == rhs);
}

template<typename T>
typename radix<T>::iterator radix<T>::begin() {
    return iterator(trie_.begin());
}

template<typename T>
typename radix<T>::iterator radix<T>::end() {
    return iterator(trie_.end());
}

#endif //RADIX_RADIX_CPP
