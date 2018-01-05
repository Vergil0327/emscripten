//===------------------------ cxa_aux_runtime.cpp -------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//
// This file implements the "Auxiliary Runtime APIs"
// http://www.codesourcery.com/public/cxx-abi/abi-eh.html#cxx-aux
//===----------------------------------------------------------------------===//

#include "cxxabi.h"
#include <typeinfo>

namespace __cxxabiv1
{

extern "C"
{

LIBCXXABI_NORETURN
void __cxa_bad_cast (void) {
#if !__has_feature(cxx_noexcept)
    throw std::bad_cast();
#else
    abort();
#endif
}

LIBCXXABI_NORETURN
void __cxa_bad_typeid(void) {
#if !__has_feature(cxx_noexcept)
    throw std::bad_typeid();
#else
    abort();
#endif
}

}  // extern "C"

}  // abi
