//
// Created by Alejandro  Otero on 2019-10-10.
//

#ifndef CS1103_PC2_201902_ARCHIVO_H
#define CS1103_PC2_201902_ARCHIVO_H

#endif //CS1103_PC2_201902_ARCHIVO_H

#include <fstream>
#include "heap.h"


template <typename T>
void load_from(const string& file_name, heap<T>& hp){
    fstream data;
    data.open("data.txt",ios::out);
    vector<heap<T>> elements;
    string num;
    while(data.is_open()){
        getline(cin,num);
        elements.push_back(stoi(num));
    }
    heap_sort(elements);
}

template <typename T>
void heap_sort(vector<T> elem){
    T n= elem.size();
    for (T i = n / 2 - 1; i >= 0; i--){
        sort(elem, n, i);}
    for (T i = n - 1; i >= 0; i--) {
        swap(elem[0], elem[i]);
        sort(elem, i, 0);
    }
}

template <typename T>
void sort(vector<T> elem, T n, T x) {
    T l = x;
    T izq = 2*x+1;
    T der = 2*x+2;

    if (izq < n && elem[izq] > elem[l]) {
        l = izq;
    }

    if (der < n && elem[der] > elem[l]) {
        l = der;
    }

    if (l != x) {
        swap(elem[x], elem[l]);
        sort(elem, n, l);
    }
}
