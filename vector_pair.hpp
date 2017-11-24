//
//  vector_pair.hpp
//  C-Utils
//
//  Created by Alagris on 30/10/2017.
//  Copyright © 2017 alagris. All rights reserved.
//

#ifndef vector_pair_hpp
#define vector_pair_hpp
#include "auto_vector.hpp"
namespace util_lib {
    template<typename T>
    class vector_pair{
    public:
        vector_pair(){}
        vector_pair(const size_t size){
            m_vec1.reserve(size);
            m_vec2.reserve(size);
        }
        vector_pair(const size_t size,const T&default_value1,const T&default_value2):
        m_vec1(default_value1),
        m_vec2(default_value2){
            m_vec1.reserve(size);
            m_vec2.reserve(size);
        }
        vector_pair(const size_t size,const T&default_value):vector_pair(size,default_value){}
        const T operator[](const size_t i)const{
            return get(i);
        }
        T & operator[](const size_t i){
            return get(i);
        }
        void swap(){
            auto_vector<T> * tmp=m_current;
            m_current=m_other;
            m_other=tmp;
        }
        const auto_vector<T> * const get()const{
            return m_current;
        }
        auto_vector<T> * const get(){
            return m_current;
        }
        const auto_vector<T> * const other()const{
            return m_other;
        }
        auto_vector<T> * const other(){
            return m_other;
        }
        const size_t size(){
            return get()->size();
        }
        const size_t otherSize(){
            return other()->size();
        }
        const T get(const size_t i)const{
            return (*get())[i];
        }
        T & get(const size_t i){
            return (*get())[i];
        }
        const T  other(const size_t i)const{
            return (*other())[i];
        }
        T & other(const size_t i){
            return (*other())[i];
        }
        const auto_vector<T> * const first()const{
            return &m_vec1;
        }
        auto_vector<T> * const first(){
            return &m_vec1;
        }
        const auto_vector<T> * const second()const{
            return &m_vec2;
        }
        auto_vector<T> * const second(){
            return &m_vec2;
        }
    private:
        auto_vector<T> m_vec1,m_vec2;
        auto_vector<T> * m_current=first();
        auto_vector<T> * m_other=second();
    };

}
#endif /* vector_pair_hpp */
