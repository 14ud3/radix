//
// Created by Ignas Laude on 7/5/21.
//

#ifndef RADIX_RADIXITERATOR_H
#define RADIX_RADIXITERATOR_H

#include "../module/triemplate/include/Iterator.h"

template<typename T>
class RadixIterator {
public:
    static const uint16_t S = 26;
    using K                     = std::string;
    using iterator_category     = std::forward_iterator_tag;
    using value_type            = Node<K,T,S>;
    using difference_type       = std::ptrdiff_t;
    using pointer               = Node<K,T,S>*;
    using reference             = Node<K,T,S>&;

    explicit RadixIterator() = delete;

    explicit RadixIterator(Iterator<K,T,S>& wrapped);
    RadixIterator(Iterator<K,T,S>&& wrapped);

    // copy ctor
    explicit RadixIterator(const RadixIterator &rhs);
    explicit RadixIterator(const RadixIterator &&rhs);

    // dtor
    ~RadixIterator() = default;


/////////////////////////////////////////////////////////////////////////
/// ACCESSORS

    /**
     * @return the pair being pointed to by this
     */
    std::pair<const K, T&> operator*();

    /**
     * @return a pointer to the node pointed to by this
     */
    std::pair<const K, T&> operator->();

    /**
     * @return a pointer to the node pointed to by this
     */
    Node<K,T,S>* &get();

/////////////////////////////////////////////////////////////////////////
/// MODIFIERS

    /**
     * swaps all values between *this and rhs
     * @param rhs the object being swapped with *this
     */
    void swap(RadixIterator& rhs);

    /**
     * assignment operator
     * @param rhs the object *this is being assigned to
     * @return *this after assignment
     */
    RadixIterator &operator=(const RadixIterator &rhs);
    RadixIterator &operator=(const RadixIterator &&rhs);

    /**
     * prefix increments Iterator to next value
     * @return this after increment
     */
    RadixIterator &operator++();

    /**
     * postfix increments Iterator to next value
     * @param rhs - the Iterator being on the right side of the ++ operator
     * @return the Iterator prior to the increment
     */
    RadixIterator operator++(int);

    /**
     * prefix decrements the Iterator
     * @return the decremented Iterator
     */
    // Iterator &operator--();

    /**
     * postfix decrements the Iterator
     * @param rhs - the Iterator being on the right side of the -- operator
     * @return
     */
    // Iterator operator--(int);


/////////////////////////////////////////////////////////////////////////
/// COMPARERS

    /**
     * compares equivalence
     * @param rhs - the other Iterator being compared to this
     * @return
     */
    bool operator==(const RadixIterator &rhs) const;

    /**
     * compares equivalence
     * @param rhs - the other Iterator being compared to this
     * @return
     */
    bool operator!=(const RadixIterator &rhs) const;

private:

    Iterator<K,T,S> baseIter_;

    std::string getWord();

};

#include "../src/RadixIterator.cpp"

#endif //RADIX_RADIXITERATOR_H
