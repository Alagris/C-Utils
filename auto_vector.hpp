//
//  auto_vector.hpp
//  C-Utils
//
//  Created by Alagris on 30/10/2017.
//  Copyright © 2017 alagris. All rights reserved.
//

#ifndef auto_vector_hpp
#define auto_vector_hpp
#include <vector>
namespace util_lib{
    template<typename T>
    class auto_vector:public std::vector<T>{
    public:
        auto_vector(const T& default_value):default_val(default_value){}
        auto_vector():auto_vector(T()){}
        typedef typename std::vector<T>::reference ref;
        typedef typename std::vector<T>::reference cref;
        typedef typename std::vector<T>::size_type st;
        ref operator[](st __n){
            ensureSize(__n+1);
            return std::vector<T>::operator[](__n);
        }
        cref operator[](st __n) const {
            ensureSize(__n+1);
            return std::vector<T>::operator[](__n);
        }
        ref at(st __n){
            ensureSize(__n+1);
            return std::vector<T>::at(__n);
        }
        cref at(st __n) const {
            ensureSize(__n+1);
            return std::vector<T>::at(__n);
        }
        void fillToCapacity(){
            ensureSize(std::vector<T>::capacity());
        }
    private:
        void ensureSize(st __n){
            st s=std::vector<T>::size();
            std::vector<T>::reserve(__n);
            while(s<__n)
                std::vector<T>::push_back(default_val);
        }
        
        T default_val;
    };
}
#endif /* auto_vector_hpp */
