//
//  fixed_size_dynamic_array.hpp
//  C-Utils
//
//  Created by Alagris on 01/11/2017.
//  Copyright © 2017 alagris. All rights reserved.
//

#ifndef fixed_size_dynamic_array_hpp
#define fixed_size_dynamic_array_hpp
#include <memory>
#include "shared_ptr_empty_destructor.h"
namespace util_lib{
    template<typename T>
    class fixed_size_dynamic_array{
    public:
        fixed_size_dynamic_array(const size_t size=0,T *const usePreallocatedBuffer=nullptr):
        m_size(size),
        m_ptr(usePreallocatedBuffer==nullptr?
              std::shared_ptr<T>(new T[size]):
              std::shared_ptr<T>(usePreallocatedBuffer,util_lib::emptyDestructor<T>)
              ){}
        
        const std::shared_ptr<const T> ptr()const{
            return m_ptr;
        }
        const std::shared_ptr<T> ptr(){
            return m_ptr;
        }
        const T operator->()const noexcept{
            return operator[](0);
        }
        T & operator->(){
            return operator[](0);
        }
        const T operator[](const size_t i)const{
            return *get(i);
        }
        T & operator[](const size_t i){
            return *get(i);
        }
        const size_t size()const{
            return m_size;
        }
        operator const T*const()const{
            return get();
        }
        operator T*const(){
            return get();
        }
        const T *const get(const size_t i=0)const{
            return m_ptr.get()+i;
        }
        T *const get(const size_t i=0){
            return m_ptr.get()+i;
        }
    private:
        size_t m_size;
        std::shared_ptr<T> m_ptr;
    };
}
#endif /* fixed_size_dynamic_array_hpp */
