//
// Created by Ignas Laude on 7/5/21.
//

#include <iostream>
#include <map>
#include "../include/radix.h"

template <typename T>
void run_standard_tests(radix<T> &trie, std::list<std::pair<std::string,T>>& inserts);

std::list<std::pair<std::string,char32_t>> generate_default_inputs(uint32_t num);

void run_default_tests();

void print_message(const std::string& s);

//region //STANDARD FUNCTION DECLARATION

//region //CONSTRUCTOR
template <typename T>
void constructor_default_tests();
template <typename T>
std::string constructor_default_empty();
template <typename T>
std::string constructor_default_beginIsEnd();
template <typename T>
std::string constructor_default_equalInstants();

//endregion

//region //COPY CONST
template <typename T>
void constructor_copy_tests(const std::list<std::pair<std::string,T>>& inserts);
template <typename T>
std::string constructor_copy_equal(radix<T>& og, uint32_t count);
template <typename T>
std::string constructor_copy_diffOGs(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string constructor_copy_notByRef(std::list<std::pair<std::string,T>> inserts);

//endregion

//region //ASSIGN
template <typename T>
void assignment_tests(const std::list<std::pair<std::string,T>>& inserts);
template <typename T>
std::string assign_diffOnesAndDiffOthers(const std::list<std::pair<std::string,T>>& inserts);
template <typename T>
std::string assign_oneEqualOther(radix<T>& one, radix<T>& other, uint32_t cnt);
template <typename T>
std::string assign_notByRef(const std::list<std::pair<std::string,T>>& inserts);
//endregion

//region //EMPTY
template <typename T>
void empty_tests(const std::list<std::pair<std::string,T>>& inserts);
template <typename T>
std::string empty_checksValid_cases(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string empty_checksValid(radix<T> &trie, bool isEmpty, uint32_t cnt);

//endregion

//region //SIZE
template <typename T>
void size_tests(const std::list<std::pair<std::string,T>>& inserts);
template <typename T>
std::string size_checksValid_cases(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string size_checkValid(radix<T> &trie, uint32_t correctCnt, uint32_t cnt);

//endregion

//region //CLEAR
template <typename T>
void clear_tests(const std::list<std::pair<std::string,T>>& inserts);
template <typename T>
std::string clear_diffCases(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string clear_properOut(radix<T> &trie, uint32_t cnt);
template <typename T>
std::string clear_multiple(const std::list<std::pair<std::string,T>>& inserts);
template <typename T>
std::string clear_empty_empty();
template <typename T>
std::string clear_filled_empty(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string clear_empty_filled(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string clear_filled_filled(std::list<std::pair<std::string,T>> inserts);

//endregion

//region //INSERT
template <typename T>
void insert_tests(const std::list<std::pair<std::string,T>>& inserts);
template <typename T>
std::string insert_pairTypeRef(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string insert_pairTypeRef_empty(std::pair<std::string,T> p);
template <typename T>
std::string insert_pairTypeRef_filled(radix<T> &trie, std::pair<std::string,T> p);

template <typename T>
std::string insert_pairTypeVal(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string insert_pairTypeVal_empty(std::pair<std::string,T> p);
template <typename T>
std::string insert_pairTypeVal_filled(radix<T> &trie, std::pair<std::string,T> p);

template <typename T>
std::string insert_typeRef(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string insert_typeRef_empty(std::pair<std::string,T> p);
template <typename T>
std::string insert_typeRef_filled(radix<T> &trie, std::pair<std::string,T> p);

template <typename T>
std::string insert_typeVal(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string insert_typeVal_empty(std::pair<std::string,T> p);
template <typename T>
std::string insert_typeVal_filled(radix<T> &trie, std::pair<std::string,T> p);

//endregion

//region //ERASE
template <typename T>
void erase_tests(const std::list<std::pair<std::string,T>>& inserts);
template <typename T>
std::string erase_key(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string erase_key_diffCases(radix<T> &trie, std::string key, bool validKey, uint32_t cnt);

//endregion

//region //SWAP
template <typename T>
void swap_tests(const std::list<std::pair<std::string,T>>& inserts);
template <typename T>
std::string swap_oneAndOther(radix<T> &one, radix<T> &other, uint32_t cnt);

//endregion

//region //FIND
template <typename T>
void find_tests(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string find_keyInTrie(radix<T> &trie, std::string key, bool valid, uint32_t cnt);

//endregion

//region //SCOUT
template <typename T>
void scout_tests(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string scout_keyInTrie(radix<T> &trie, std::string key, bool valid, uint32_t cnt);

//endregion

//region //CONTAINS
template <typename T>
void contains_tests(std::list<std::pair<std::string,T>> inserts);
template <typename T>
std::string contains_keyInTrie(radix<T> &trie, std::string key, bool valid, uint32_t cnt);

//endregion

//region //ITERATOR
void iterator_tests();
std::string iterator_empty();
std::string iterator_empty_beginIsEnd();
std::string iterator_filled_diffCases(radix<char32_t> &trie, std::map<std::string,char32_t> &map, int32_t cnt);

//endregion

//endregion

int main() {
    std::list<std::pair<std::string,bool>> list;
    list.push_front(std::pair<std::string,bool>("HELLO",true));
    list.push_front(std::pair<std::string,bool>("BEE",false));
    list.push_front(std::pair<std::string,bool>("BE",false));
    list.push_front(std::pair<std::string,bool>("BEE",true));
    list.push_front(std::pair<std::string,bool>("BIN",true));
    list.push_front(std::pair<std::string,bool>("HELL",false));
    list.push_front(std::pair<std::string,bool>("HI",true));
    list.push_front(std::pair<std::string,bool>("AY",false));
    list.push_front(std::pair<std::string,bool>("HEIGHTS",false));
    list.push_front(std::pair<std::string,bool>("HEIGHT",true));

    radix<bool> text_trie;

    std::cout << "TESTS:\n";
    run_standard_tests(text_trie,list);

    return 0;
}

template <typename T>
void run_standard_tests(radix<T>& trie, std::list<std::pair<std::string,T>>& inserts) {
    constructor_default_tests<T>();
    constructor_copy_tests<T>(inserts);
    assignment_tests<T>(inserts);
    empty_tests<T>(inserts);
    size_tests<T>(inserts);
    clear_tests<T>(inserts);
    insert_tests<T>(inserts);
    erase_tests<T>(inserts);
    swap_tests<T>(inserts);
    find_tests<T>(inserts);
    scout_tests<T>(inserts);
    contains_tests<T>(inserts);
}

std::list<std::pair<std::string,char32_t>> generate_default_inputs(uint32_t num) {
    std::list<std::pair<std::string,char32_t>> list;
    std::pair<std::string,char32_t> p;
    char32_t val('a');
    std::string ph;
    for (uint32_t i(0); i < num; ++i) {
        if (i % 2 == 0) { // if even
            p = std::pair<std::string,char32_t>(ph += val, char(val + i));
        }
        else {
            ph = ph.at(i % ph.size()) = val;
            p = std::pair<std::string,char32_t>(ph, char(val + i));
        }
        list.push_front(p);
    }
    return list;
}

void run_default_tests() {
    radix<char32_t> trie;
    std::list<std::pair<std::string,char32_t>> inputs(generate_default_inputs(25));

    run_standard_tests(trie,inputs);
    //int32_t,char32_t,2,Awful_Indexer<int32_t,char32_t,2>,Awful_KeyModif<int32_t,char32_t,2>,Awful_Eraser<int32_t,char32_t,2,Awful_Indexer<int32_t,char32_t,2>,Awful_KeyModif<int32_t,char32_t,2>>
    iterator_tests();
}

void print_message(const std::string& s) {
    if (s.empty()) {
        std::cout << "PASS" << std::endl;
    }
    else {
        std::cout << "FAIL" << std::endl << s;
    }
}

//region //FUNCTION DEFINITIONS
template <typename T>
void constructor_default_tests() {
    std::cout << "default constructor test(s): ";
    std::string s;

    s += constructor_default_empty<T>();
    s += constructor_default_beginIsEnd<T>();
    s += constructor_default_equalInstants<T>();

    print_message(s);
}
//region //DEF CONSTRUCTOR
template <typename T>
std::string constructor_default_empty() {
    std::string out("\t- is empty: ");
    try {
        radix<T> trie;
        return (!trie.empty()) ? out + "fail\n" : "";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename T>
std::string constructor_default_beginIsEnd() {
    std::string out("\t- begin()==end(): ");
    try {
        radix<T> trie;
        return (trie.begin() != trie.end()) ? out + "fail\n" : "";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename T>
std::string constructor_default_equalInstants() {
    std::string out("\t- def()==def(): ");
    try {
        radix<T> firstTrie;
        radix<T> secondTrie;
        out = (firstTrie != secondTrie) ? out + "fail -- != " : "";
        out = (firstTrie == secondTrie) ? "" : out + "fail -- == ";
        return (out.empty()) ? out : out + "\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename T>
void constructor_copy_tests(const std::list<std::pair<std::string,T>>& inserts) {
    std::cout << "copy constructor test(s): ";
    std::string s;

    s += constructor_copy_diffOGs<T>(inserts);
    s += constructor_copy_notByRef<T>(inserts);

    print_message(s);
}
//region //COPY CONSTRUCTOR
template <typename T>
std::string constructor_copy_equal(radix<T>& og, uint32_t count) {
    std::string out("\t- is equal(" + std::to_string(count) + "): ");
    try {
        radix<T> trie(og);
        return (trie == og) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename T>
std::string constructor_copy_diffOGs(std::list<std::pair<std::string,T>> inserts) {
    radix<T> tr_one; // empty
    radix<T> tr_two; // one item
    radix<T> tr_three; // three items

    int32_t ratio(int32_t(inserts.size() * 0.45));

    for (uint32_t i(0); i < ratio; ++i) {
        tr_two.insertOrAssign(inserts.front());
        inserts.pop_front();
    }

    while (!inserts.empty()) {
        tr_three.insertOrAssign(inserts.front());
        inserts.pop_front();
    }

    std::string out;

    out += constructor_copy_equal(tr_one, 1);
    out += constructor_copy_equal(tr_two, 2);
    out += constructor_copy_equal(tr_three, 3);

    return out;
}

template <typename T>
std::string constructor_copy_notByRef(std::list<std::pair<std::string,T>> inserts) {
    std::string out("\t- copy by value: ");
    try {
        int32_t ratio(int32_t(inserts.size() * 0.45));

        radix<T> trie_one;
        radix<T> trie_two(trie_one);

        for (uint32_t i(0); i < ratio; ++i) {
            trie_one.insertOrAssign(inserts.front());
            inserts.pop_front();
        }

        radix<T> trie_three;
        while (!inserts.empty()) {
            trie_three.insertOrAssign(inserts.front());
            inserts.pop_front();
        }
        radix<T> trie_four(trie_three);

        std::string moreOut;

        moreOut += ((trie_one != trie_two) ? "" : "fail -- inserted after copy; ");
        moreOut +=((trie_three == trie_four) ? "" : "fail -- inserted before copy");

        return (moreOut.empty() ? "" : out + moreOut + "\n");
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename T>
void assignment_tests(const std::list<std::pair<std::string,T>>& inserts) {
    std::cout << "assignment operator test(s): ";
    std::string s;

    s += assign_diffOnesAndDiffOthers<T>(inserts);
    s += assign_notByRef<T>(inserts);

    print_message(s);
}
//region //ASSIGNMENT
template <typename T>
std::string assign_diffOnesAndDiffOthers(const std::list<std::pair<std::string,T>>& inserts) {
    radix<T> trie_one, trie_two, trie_three, trie_four,
            trie_five, trie_six, trie_seven, trie_eight, trie_nine, trie_ten;

    std::string out;

    // empty to empty
    out += assign_oneEqualOther(trie_one,trie_two,1);

    // filled to empty
    std::list<std::pair<std::string,T>> ph_one(inserts);
    while (!ph_one.empty()) {
        trie_one.insertOrAssign(ph_one.front());
        ph_one.pop_front();
    }
    out += assign_oneEqualOther(trie_one,trie_two,2);

    // empty to filled
    std::list<std::pair<std::string,T>> ph_two(inserts);
    while (!ph_two.empty()) {
        trie_three.insertOrAssign(ph_two.front());
        ph_two.pop_front();
    }
    out += assign_oneEqualOther(trie_four,trie_three,3);

    // filled to filled (same size)
    int32_t ratio(int32_t(inserts.size() * 0.5));
    std::list<std::pair<std::string,T>> ph_three(inserts);
    for (uint32_t i(0); i < ratio; ++i) {
        trie_six.insertOrAssign(ph_three.front());
        ph_three.pop_front();
    }

    while (!ph_three.empty()) {
        trie_five.insertOrAssign(ph_three.front());
        ph_three.pop_front();
    }
    out += assign_oneEqualOther(trie_six,trie_five,4);

    // filled to filled (less to large -- ie 2 to 3)
    ratio = inserts.size() * 0.4;
    std::list<std::pair<std::string,T>> ph_four(inserts);
    for (uint32_t i(0); i < ratio; ++i) {
        trie_seven.insertOrAssign(ph_four.front());
        ph_four.pop_front();
    }

    while (!ph_four.empty()) {
        trie_eight.insertOrAssign(ph_four.front());
        ph_four.pop_front();
    }
    out += assign_oneEqualOther(trie_seven,trie_eight,5);

    // filled to filled (large to less -- ie 3 to 2)
    ratio = inserts.size() * 0.7;
    std::list<std::pair<std::string,T>> ph_five(inserts);
    for (uint32_t i(0); i < ratio; ++i) {
        trie_nine.insertOrAssign(ph_five.front());
        ph_five.pop_front();
    }

    while (!ph_five.empty()) {
        trie_ten.insertOrAssign(ph_five.front());
        ph_five.pop_front();
    }
    out += assign_oneEqualOther(trie_ten,trie_nine,6);

    return out;
}

template <typename T>
std::string assign_oneEqualOther(radix<T>& one, radix<T>& other, uint32_t cnt) {
    std::string out("\t- one assigned to other(" + std::to_string(cnt) + "): ");
    try {
        one = other;
        return (one == other) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename T>
std::string assign_notByRef(const std::list<std::pair<std::string,T>>& inserts) {
    std::string out("\t- copied by value: ");
    try {
        radix<T> trie_one, trie_two, trie_three, trie_four;
        trie_two = trie_one;
        std::list<std::pair<std::string,T>> ph_one(inserts);
        while (!ph_one.empty()) {
            trie_one.insertOrAssign(ph_one.front());
            ph_one.pop_front();
        }

        std::list<std::pair<std::string,T>> ph_two(inserts);
        while (!ph_two.empty()) {
            trie_three.insertOrAssign(ph_two.front());
            ph_two.pop_front();
        }
        trie_four = trie_three;

        std::string moreOut;

        moreOut += ((trie_one != trie_two) ? "" : "fail -- inserted after assignment; ");
        moreOut +=((trie_three == trie_four) ? "" : "fail -- inserted before assignment");

        return (moreOut.empty() ? "" : out + moreOut + "\n");
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename T>
void empty_tests(const std::list<std::pair<std::string,T>>& inserts) {
    std::cout << "empty test(s): ";
    std::string s;

    s += empty_checksValid_cases<T>(inserts);

    print_message(s);
}
//region //EMPTY
template <typename T>
std::string empty_checksValid_cases(std::list<std::pair<std::string,T>> inserts) {
    radix<T> trie_one;
    std::string out;

    // proper return when actually empty
    out += empty_checksValid(trie_one,true,1);

    // proper return when not empty (contains one item)
    trie_one.insertOrAssign(inserts.front());
    inserts.pop_front();
    out += empty_checksValid(trie_one,false,2);

    // proper return when not empty (contains two item)
    trie_one.insertOrAssign(inserts.front());
    inserts.pop_front();
    out += empty_checksValid(trie_one,false,2);

    return out;
}

template <typename T>
std::string empty_checksValid(radix<T> &trie, bool isEmpty, uint32_t cnt) {
    std::string out("\t- proper return(" + std::to_string(cnt) + "): ");
    try {
        return (trie.empty() == isEmpty) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename T>
void size_tests(const std::list<std::pair<std::string,T>>& inserts) {
    std::cout << "size test(s): ";
    std::string s;

    s += size_checksValid_cases<T>(inserts);

    print_message(s);
}
//region //SIZE
template <typename T>
std::string size_checksValid_cases(std::list<std::pair<std::string,T>> inserts) {
    radix<T> trie;
    std::string out("");

    int32_t i(0);
    while (!inserts.empty()) {
        out += size_checkValid(trie,i,i+1);
        if (trie.contains(inserts.front().first))
            --i;
        trie.insertOrAssign(inserts.front());
        inserts.pop_front();
        ++i;
    }

    return out;
}

template <typename T>
std::string size_checkValid(radix<T> &trie, uint32_t correctCnt, uint32_t cnt) {
    std::string out("\t- proper return(" + std::to_string(cnt) + "): ");
    try {
        return (trie.size() == correctCnt) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename T>
void clear_tests(const std::list<std::pair<std::string,T>>& inserts) {
    std::cout << "clear test(s): ";
    std::string s;

    // when empty and not empty
    s += clear_diffCases<T>(inserts);

    // called multiple times
    s += clear_multiple<T>(inserts);

    print_message(s);
}
//region //EMPTY
template <typename T>
std::string clear_diffCases(std::list<std::pair<std::string,T>> inserts) {
    radix<T> trie_one, trie_two;
    std::string out;

    // when empty
    out += clear_properOut(trie_one, 1);

    // filled with one
    trie_two.insertOrAssign(inserts.front());
    inserts.pop_front();
    out += clear_properOut(trie_two, 2);

    // filled with more than one
    while (!inserts.empty()) {
        trie_two.insertOrAssign(inserts.front());
        inserts.pop_front();
    }
    out += clear_properOut(trie_two,3);

    return out;
}

template <typename T>
std::string clear_properOut(radix<T> &trie, uint32_t cnt) {
    std::string out("\t- proper return(" + std::to_string(cnt) + "): ");
    try {
        trie.clear();
        return (trie.empty() && trie.size() == 0) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename T>
std::string clear_multiple(const std::list<std::pair<std::string,T>>& inserts) {

    std::string out;

    out += clear_empty_empty<T>();
    out += clear_filled_empty<T>(inserts);
    out += clear_empty_filled<T>(inserts);
    out += clear_filled_filled<T>(inserts);

    return out;
}

template <typename T>
std::string clear_empty_empty() {
    radix<T> trie_empty;
    std::string out;

    out += clear_properOut(trie_empty, 4);
    out += clear_properOut(trie_empty, 5);

    return out;
}

template <typename T>
std::string clear_filled_empty(std::list<std::pair<std::string,T>> inserts) {
    radix<T> trie;
    std::string out;

    trie.insertOrAssign(inserts.front());
    inserts.pop_front();

    out += clear_properOut(trie, 6);
    out += clear_properOut(trie,7);

    return out;
}

template <typename T>
std::string clear_empty_filled(std::list<std::pair<std::string,T>> inserts) {
    radix<T> trie;
    std::string out;

    out += clear_properOut(trie,8);

    trie.insertOrAssign(inserts.front());
    inserts.pop_front();

    out += clear_properOut(trie,9);

    return out;
}

template <typename T>
std::string clear_filled_filled(std::list<std::pair<std::string,T>> inserts) {
    radix<T> trie;
    std::string out;

    trie.insertOrAssign(inserts.front());
    inserts.pop_front();
    out += clear_properOut(trie,10);
    trie.insertOrAssign(inserts.front());
    inserts.pop_front();
    out += clear_properOut(trie,11);

    return out;
}

//endregion

template <typename T>
void insert_tests(const std::list<std::pair<std::string,T>>& inserts) {
    std::cout << "insert test(s): ";
    std::string s;

    // pairType&
    s += insert_pairTypeRef<T>(inserts);

    // pairType&&
    s += insert_pairTypeVal<T>(inserts);

    // type&
    s += insert_typeRef<T>(inserts);

    // type&&
    s += insert_typeVal<T>(inserts);

    print_message(s);
}
//region //INSERT
template <typename T>
std::string insert_pairTypeRef(std::list<std::pair<std::string,T>> inserts) {
    std::string out;

    // new key in empty trie
    // size change
    // trie has new key and its node has new value
    out += insert_pairTypeRef_empty<T>(inserts.front());
    inserts.pop_front();

    // old key in trie
    radix<T> trie;
    std::pair<std::string,T> p(inserts.front());
    inserts.pop_front();
    trie.insertOrAssign(p);

    // no size change
    // old val
    // no new value at key
    out += insert_pairTypeRef_filled<T>(trie,p);
    // new val
    // new value at key
    p.second = inserts.front().second;
    inserts.pop_front();
    out += insert_pairTypeRef_filled<T>(trie,p);

    return out;
}
template <typename T>
std::string insert_pairTypeRef_empty(std::pair<std::string,T> p) {
    std::string out("\t- pairTypeRef empty: ");
    try {
        radix<T> trie;
        auto it = trie.insertOrAssign(p);
        return (trie.size() == 1 && (*it).first == p.first && (*it).second == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}
template <typename T>
std::string insert_pairTypeRef_filled(radix<T> &trie, std::pair<std::string,T> p) {
    std::string out("\t- pairTypeRef filled: ");
    try {
        int32_t prevSize = trie.size();
        auto it = trie.insertOrAssign(p);

        bool incArtCnt(trie.size() == prevSize);
        return (incArtCnt && (*it).second == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename T>
std::string insert_pairTypeVal(std::list<std::pair<std::string,T>> inserts) {
    std::string out;

    // new key in empty trie
    // size change
    // trie has new key and its node has new value
    out += insert_pairTypeVal_empty<T>(inserts.front());
    inserts.pop_front();

    // old key in trie
    radix<T> trie;
    std::pair<std::string,T> p(inserts.front().first,inserts.front().second);
    inserts.pop_front();
    trie.insertOrAssign(p);

    // no size change
    // old val
    // no new value at key
    out += insert_pairTypeVal_filled(trie,p);
    // new val
    // new value at key
    p.second = inserts.front().second;
    inserts.pop_front();
    out += insert_pairTypeVal_filled(trie,p);

    return out;
}
template <typename T>
std::string insert_pairTypeVal_empty(std::pair<std::string,T> p) {
    std::string out("\t- pairTypeVal empty: ");
    try {
        radix<T> trie;
        auto it = trie.insertOrAssign(std::pair<std::string,T>(p));
        return (trie.size() == 1 && (*it).first == p.first && (*it).second == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}
template <typename T>
std::string insert_pairTypeVal_filled(radix<T> &trie, std::pair<std::string,T> p) {
    std::string out("\t- pairTypeVal filled: ");
    try {
        int32_t prevSize = trie.size();
        auto it = trie.insertOrAssign(std::pair<std::string,T>(p));

        bool incArtCnt(trie.size() == prevSize);
        return (incArtCnt && (*it).second == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename T>
std::string insert_typeRef(std::list<std::pair<std::string,T>> inserts) {
    std::string out;

    // new key in empty trie
    // size change
    // trie has new key and its node has new value
    out += insert_typeRef_empty<T>(inserts.front());
    inserts.pop_front();

    // old key in trie
    radix<T> trie;
    std::pair<std::string,T> p(inserts.front().first,inserts.front().second);
    trie.insertOrAssign(p);

    // no size change
    // old val
    // no new value at key
    out += insert_typeRef_filled<T>(trie,p);
    inserts.pop_front();
    // new val
    // new value at key
    p.second = inserts.front().second;
    out += insert_typeRef_filled<T>(trie,p);

    return out;
}
template <typename T>
std::string insert_typeRef_empty(std::pair<std::string,T> p) {
    std::string out("\t- typeRef empty: ");
    try {
        radix<T> trie;
        T val(p.second);
        auto it = trie.insertOrAssign(p.first,val);

        return (trie.size() == 1 && (*it).first == p.first && (*it).second == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}
template <typename T>
std::string insert_typeRef_filled(radix<T> &trie, std::pair<std::string,T> p) {
    std::string out("\t- typeRef filled: ");
    try {
        int32_t prevSize = trie.size();
        auto it = trie.insertOrAssign(p.first,p.second);

        bool incArtCnt(trie.size() == prevSize);
        return (incArtCnt && (*it).first == p.first && (*it).second == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename T>
std::string insert_typeVal(std::list<std::pair<std::string,T>> inserts) {
    std::string out;

    // new key in empty trie
    // size change
    // trie has new key and its node has new value
    out += insert_typeVal_empty<T>(inserts.front());
    inserts.pop_front();

    // old key in trie
    radix<T> trie;
    std::pair<std::string,T> p(inserts.front().first,inserts.front().second);
    trie.insertOrAssign(p);

    // no size change
    // old val
    // no new value at key
    out += insert_typeVal_filled<T>(trie,p);
    inserts.pop_front();
    // new val
    // new value at key
    p.second = inserts.front().second;
    out += insert_typeVal_filled<T>(trie,p);

    return out;
}
template <typename T>
std::string insert_typeVal_empty(std::pair<std::string,T> p) {
    std::string out("\t- typeVal empty: ");
    try {
        radix<T> trie;
        auto it = trie.insertOrAssign(p.first,p.second);

        return (trie.size() == 1 && (*it).first == p.first && (*it).second == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}
template <typename T>
std::string insert_typeVal_filled(radix<T> &trie, std::pair<std::string,T> p) {
    std::string out("\t- typeVal filled: ");
    try {
        int32_t prevSize = trie.size();
        auto it = trie.insertOrAssign(p.first,p.second);

        bool incArtCnt(trie.size() == prevSize);
        return (incArtCnt && (*it).first == p.first && (*it).second == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename T>
void erase_tests(const std::list<std::pair<std::string,T>>& inserts) {
    std::cout << "erase test(s): ";
    std::string s;

    // erase via key
    s += erase_key<T>(inserts);

    //todo do erase test cases

    // erase via iterator
    //s += erase_iterators();

    // called on empty trie
    // changes number appropriately


    // non-existent key
    // changes number appropriately

    // actual key

    print_message(s);
}
//region //ERASE
template <typename T>
std::string erase_key(std::list<std::pair<std::string,T>> inserts) {
    std::string out;
    // called on empty trie
    // changes number appropriately
    radix<T> trie;
    out += erase_key_diffCases<T>(trie,inserts.front().first,false,1);

    // non-existent key
    // changes number appropriately
    std::pair<std::string,T> p(inserts.front());
    inserts.pop_front();
    auto it_ = trie.insertOrAssign(p);
    out += erase_key_diffCases(trie,inserts.front().first,false,2);

    // actual key
    std::pair<std::string,T> p_uniq_one(inserts.front());
    inserts.pop_front();
    auto it__ = trie.insertOrAssign(p_uniq_one);

    std::pair<std::string,T> p_uniq_two(inserts.front());
    inserts.pop_front();
    auto it___ = trie.insertOrAssign(p_uniq_two);

    std::pair<std::string,T> ph(inserts.front());
    inserts.pop_front();
    while (!inserts.empty()) {
        trie.insertOrAssign(ph);

        ph = inserts.front();
        inserts.pop_front();
    }

    std::pair<std::string,T> p_uniq_three(ph);
    trie.insertOrAssign(p_uniq_three);

    out += erase_key_diffCases(trie,p_uniq_one.first,true,3);

    out += erase_key_diffCases(trie,p_uniq_two.first,true,4);

    out += erase_key_diffCases(trie,p_uniq_three.first,true,5);

    return out;
}
template <typename T>
std::string erase_key_diffCases(radix<T> &trie, std::string key, bool validKey, uint32_t cnt) {
    std::string out("\t- key diffCases (" + std::to_string(cnt) + "): ");
    try {
        radix<T> copy(trie);
        int32_t ogSize(copy.size());
        copy.erase(key);

        return (((ogSize == copy.size() + 1) == validKey) && !(copy.contains(key))) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename T>
void swap_tests(const std::list<std::pair<std::string,T>>& inserts) {
    std::cout << "swap test(s): ";
    std::string s;

    // empty to empty
    radix<T> trie_one, trie_two;
    s += swap_oneAndOther<T>(trie_one,trie_two,1);

    // empty to filled
    std::list<std::pair<std::string,T>> ph_one(inserts);
    radix<T> trie_three, trie_four;
    trie_four.insertOrAssign(ph_one.front());
    ph_one.pop_front();
    trie_four.insertOrAssign(ph_one.front());
    ph_one.pop_front();
    trie_four.insertOrAssign(ph_one.front());
    ph_one.pop_front();
    s += swap_oneAndOther<T>(trie_three,trie_four,2);

    // filled to empty
    std::list<std::pair<std::string,T>> ph_two(inserts);
    radix<T> trie_five, trie_six;
    trie_five.insertOrAssign(ph_two.front());
    ph_two.pop_front();
    trie_five.insertOrAssign(ph_two.front());
    ph_two.pop_front();
    trie_five.insertOrAssign(ph_two.front());
    ph_two.pop_front();
    s += swap_oneAndOther<T>(trie_five,trie_six,3);

    // filled to filled
    std::list<std::pair<std::string,T>> ph_three(inserts);
    uint32_t ratio(int32_t(ph_three.size() * 0.45));
    radix<T> trie_seven, trie_eight;
    for (uint32_t i(0); i < ratio; ++i) {
        trie_seven.insertOrAssign(ph_three.front());
        ph_three.pop_front();
    }

    while (!ph_three.empty()) {
        trie_eight.insertOrAssign(ph_three.front());
        ph_three.pop_front();
    }
    s += swap_oneAndOther<T>(trie_seven,trie_eight,4);

    print_message(s);
}
//region //SWAP
template <typename T>
std::string swap_oneAndOther(radix<T> &one, radix<T> &other, uint32_t cnt) {
    std::string out("\t- proper swap(" + std::to_string(cnt) + "): ");
    try {
        radix<T> copy_one(one), copy_other(other);
        one.swap(other);
        return (one == copy_other && other == copy_one) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename T>
void find_tests(std::list<std::pair<std::string,T>> inserts) {
    std::cout << "find test(s): ";
    std::string s;

    // empty trie
    radix<T> empty;
    s += find_keyInTrie<T>(empty,inserts.front().first,false,1);

    // filled trie, invalid key
    radix<T> filled;
    std::pair<std::string,T> ph_notWithin(inserts.front()), ph_within;
    inserts.pop_front();
    while (!inserts.empty()) {
        ph_within = inserts.front();
        inserts.pop_front();
        filled.insertOrAssign(ph_within);
    }
    s += find_keyInTrie<T>(filled,ph_notWithin.first,false,2);

    // filled trie, valid key
    s += find_keyInTrie<T>(filled,ph_within.first,true,2);

    print_message(s);
}
//region //FIND
template <typename T>
std::string find_keyInTrie(radix<T> &trie, std::string key, bool valid, uint32_t cnt) {
    std::string out("\t- proper find(" + std::to_string(cnt) + "): ");
    try {
        auto it = trie.find(key);
        return ((it != trie.end()) == valid) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename T>
void scout_tests(std::list<std::pair<std::string,T>> inserts) {
    std::cout << "scout test(s): ";
    std::string s;

    // empty trie
    radix<T> empty;
    s += scout_keyInTrie<T>(empty,inserts.front().first,false,1);

    // filled trie, invalid key
    radix<T> trie;
    std::pair<std::string,T> ph_notWithin(inserts.front()), ph_within;
    inserts.pop_front();
    while (!inserts.empty()) {
        ph_within = inserts.front();
        inserts.pop_front();
        trie.insertOrAssign(ph_within);
    }
    s += scout_keyInTrie<T>(trie,ph_notWithin.first,false,2);

    // filled key, valid key
    s += scout_keyInTrie<T>(trie,ph_within.first,true,3);

    print_message(s);
}
//region //SCOUT
template <typename T>
std::string scout_keyInTrie(radix<T> &trie, std::string key, bool valid, uint32_t cnt) {
    std::string out("\t- proper scout(" + std::to_string(cnt) + "): ");
    try {
        auto it = trie.scout(key);
        return (it.first == valid) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion,

template <typename T>
void contains_tests(std::list<std::pair<std::string,T>> inserts) {
    std::cout << "contains test(s): ";
    std::string s;

    // empty trie
    radix<T> empty;
    s += contains_keyInTrie<T>(empty,inserts.front().first,false,1);

    // filled trie, invalid key
    radix<T> trie;
    std::pair<std::string,T> ph_notWithin(inserts.front()), ph_within;
    inserts.pop_front();
    while (!inserts.empty()) {
        ph_within = inserts.front();
        inserts.pop_front();
        trie.insertOrAssign(ph_within);
    }
    s += contains_keyInTrie<T>(trie,ph_notWithin.first,false,2);

    // filled key, valid key
    s += contains_keyInTrie<T>(trie,ph_within.first,true,3);

    print_message(s);
}
//region //CONTAINS
template <typename T>
std::string contains_keyInTrie(radix<T> &trie, std::string key, bool valid, uint32_t cnt) {
    std::string out("\t- proper contains(" + std::to_string(cnt) + "): ");
    try {
        return (trie.contains(key) == valid) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

void iterator_tests() {
    std::cout << "iterator test(s): ";
    std::string s;

    // empty trie
    s += iterator_empty_beginIsEnd();

    // filled trie
    radix<char32_t> trie;
    std::map<std::string,char32_t> map;
    std::pair<std::string,char32_t> p("HELLO",'a');
    trie.insertOrAssign(p);
    map.insert(p);

    p = std::pair<std::string,char32_t>("HELL",'b');
    trie.insertOrAssign(p);
    map.insert(p);

    p = std::pair<std::string,char32_t>("ABBOT",'c');
    trie.insertOrAssign(p);
    map.insert(p);

    p = std::pair<std::string,char32_t>("AB",'d');
    trie.insertOrAssign(p);
    map.insert(p);

    p = std::pair<std::string,char32_t>("HERSHEY",'e');
    trie.insertOrAssign(p);
    map.insert(p);

    s += iterator_filled_diffCases(trie,map,1);

    print_message(s);
}
std::string iterator_empty_beginIsEnd() {
    std::string out("\t- empty begin is end: ");
    try {
        radix<char32_t> trie;
        return (trie.begin() == trie.end()) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

std::string iterator_filled_diffCases(radix<char32_t> &trie, std::map<std::string,char32_t> &map, int32_t cnt) {
    std::string out("\t- iterator filled (" + std::to_string(cnt) + "): ");
    try {
        radix<char32_t> copy(trie);

        bool allEqual(true);
        int32_t cnt(0);
        for (auto trieIt(trie.begin()); trieIt != trie.end(); ++trieIt) {
            ++cnt;
            if (cnt == 6) {
                std::cout << bool(trieIt != trie.end());
            }

            if (map.find((*trieIt).first) == map.end()) {
                allEqual = false;
                break;
            }
        }

        return (allEqual) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}