//
// Created by Ignas Laude on 7/5/21.
//

#ifndef RADIX_RADIX_H
#define RADIX_RADIX_H

#include "../module/triemplate/include/triemplate.h"
#include "RadixIterator.h"
#include "Parameters.h"

template<typename T>
class Radix {
public:

    static const uint16_t S =                       26;
    typedef std::string                             key_type;
    typedef T                                       mapped_type;
    typedef Node<key_type,mapped_type,S>            Node;
    typedef Radix_Indexer<mapped_type>              key_indexer;
    typedef Radix_Eraser<mapped_type>               key_eraser;
    typedef RadixIterator<mapped_type>              iterator;

    // def ctor
    explicit Radix();

    // copy ctor
    explicit Radix(const Radix<T>& rhs);
    explicit Radix(const Radix<T>&& rhs);

    // dtor
    ~Radix() = default;

    // assignment
    Radix<T> &operator=(const Radix<T>& rhs);
    Radix<T> &operator=(const Radix<T>&& rhs);

//////////////////////////////////////////////////////
//// CAPACITY

    /**
     * checks whether the container is empty
     * @return - true if empty, false otherwise
     */
    bool empty() const noexcept;

    /**
     * returns the number of words in trie
     * @return - unsigned int for number of elements in trie
     */
    uint32_t size() const noexcept;

//////////////////////////////////////////////////////
//// MODIFIERS

    /**
     * clears the contents, ie if not already empty, deletes the contents of the trie
     */
    void clear() noexcept;

    /**
     * inserts article if not already present, and adds value at end of article's sequence
     * @param article - the key used to find value's target
     * @param value - the value being stored at element
     * @return - an iterator to the node that holds value
     */
    //region //insert();
    iterator insertOrAssign(std::pair<key_type,mapped_type>& p, Node* ancestor = nullptr);
    iterator insertOrAssign(std::pair<key_type,mapped_type>&& p, Node* ancestor = nullptr);

    iterator insertOrAssign(key_type article, mapped_type& value, Node* ancestor = nullptr);
    iterator insertOrAssign(key_type article, mapped_type&& value, Node* ancestor = nullptr);
    //endregion

    /**
     * erases article within trie
     * @param article - the key being deleted
     */
    void erase(key_type article,Node* ancestor = nullptr);

    /**
     * swaps the contents
     * @param rhs - the container to exchange the contents with
     */
    void swap(Radix& rhs) noexcept;

//////////////////////////////////////////////////////
//// LOOKUPS

    /**
     * finds the node that holds the values for the article
     * @param article - the article being searched for
     * @return - an iterator at the last node in sequence for the article, else returns .end()
     */
    iterator find(key_type article);

    /**
     * finds the last viable node in sequence for the article. The returned pair contains, first, a boolean which holds
     * the same value as the contains() function returns, and second, an iterator at the last viable node in sequence.
     *
     * Example: given 'LOOKUP' was inserted in a BTrie, scout('LOOK') will return pair<false,iterator(node('K'))>, and
     * scout('LOOKUP') will return pair<true,iterator(node('P'))> (where node(N) represents the node at N letter in the node
     * sequence)
     *
     * @param article - the article being searched for
     * @return - returns a pair of a boolean and an iterator at the last viable node for the article's node sequence
     */
    std::pair<bool,iterator> scout(key_type article,Node* ancestor = nullptr);

    /**
     * checks if the container contains element
     * @param element - the key being searched for
     * @return - true if in container, else false
     */
    bool contains(key_type article,Node* ancestor = nullptr);

//////////////////////////////////////////////////////
//// COMPARERS

    bool operator==(const Radix& rhs) const;
    bool operator!=(const Radix& rhs) const;

//////////////////////////////////////////////////////
//// ITERATORS

    iterator begin();

    iterator end();

private:

    triemplate<std::string,T,26> trie_;

};

#include "../src/Radix.cpp"

#endif //RADIX_RADIX_H
