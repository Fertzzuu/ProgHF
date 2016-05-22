//
// Created by mmarci on 2016.05.15..
//

#ifndef PROGHF_ALGORITHMS_H
#define PROGHF_ALGORITHMS_H

#include <cstring>
#include <iostream>
#include "String.hpp"

class Algorithms {
public:

    template<typename T>
    static void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }

    template<typename T>
    void static sort(T* begin, T* end, bool (*cmp)(const T&, const T&)) {
        for (T* i = begin ; i != end; ++i) {
            T* min = i;
            for (T* j = i+1 ; j != end; ++j)
                if (cmp(*j , *min))
                    min = j;
            if (i != min)
                swap(*i, *min);
        }
    }

    template<typename T>
    void static sort(T* begin, T* end) {
        for (T* i = begin ; i != end; ++i) {
            T* min = i;
            for (T* j = i+1 ; j != end; ++j)
                if (*j < *min)
                    min = j;
            if (i != min)
                swap(*i, *min);
        }
    }
};




#endif //PROGHF_ALGORITHMS_H
