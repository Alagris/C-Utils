//
//  shared_ptr_empty_destructor.h
//  C-Utils
//
//  Created by Alagris on 31/10/2017.
//  Copyright © 2017 alagris. All rights reserved.
//

#ifndef shared_ptr_empty_destructor_h
#define shared_ptr_empty_destructor_h

namespace util_lib {
    template<typename T>
    void emptyDestructor(T*){}
}
#endif /* shared_ptr_empty_destructor_h */
