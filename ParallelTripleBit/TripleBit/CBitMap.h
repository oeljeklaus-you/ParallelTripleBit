#ifndef CBITMAP_H_
#define CBITMAP_H_
#include "TripleBit.h"
#include <boost/dynamic_bitset.hpp>
//一个固定baseID具有最小和最大ID的bitmap
class CBitMap{
public:
    ID base;
    boost::dynamic_bitset<> bits;

    CBitMap(ID minID,ID maxID):base(minID){
        // cout<<minID<<" "<<maxID<<endl;
        bits.resize(maxID-minID+1,false);
        // cout<<"size "<<bits.size()<<endl;
    }

    bool contains(ID id){
        if(id < base || id > base+bits.size()-1) return false;
        return bits[id-base];
    }

    bool insert(ID id){
         bits[id-base] = true;
    }

    bool get(ID id){
        if(id < base || id > base+bits.size()-1) return false;
        return bits[id-base];
    }

    void set(ID id,bool v){
        bits[id-base] = v;
    }
};
#endif