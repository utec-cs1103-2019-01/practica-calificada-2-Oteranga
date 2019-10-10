//
// Created by rudri on 10/10/2019.
//

#ifndef CS1103_PC2_201902_HEAP_H
#define CS1103_PC2_201902_HEAP_H

#include <iostream>
#include <vector>
using namespace std;

template<typename T,typename ...T2>
class heap{
    vector<T> elementos;
public:
    T get_max(){
        return elementos[-1];
    }
    void insert(T item){
        elementos.push_back(item);
    }
    void insert(T2... items){
        (elementos.push_back(items),...);
    }
    ostream& operator<<(ostream& out, const heap<T>& list){
        for (int i=0; i<elementos.size();i++){
            out<<list[i];
        }
        return out;
    }
    istream& operator>>(istream& in, const heap<T>& list){
        in>>list;
        elementos.push_back(list);
        return in;
    }
    T size(){
        return elementos.size();
    }
    void clear(){
        for(int it=0;it<elementos.size();it++){
            elementos.pop_back();
        }
    }

};

#endif //CS1103_PC2_201902_HEAP_H
