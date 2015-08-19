//
//  SupernovaMemoryNedPooling.h
//  Supernova
//
//  Created by Jimmy on 8/18/15.
//  Copyright (c) 2015 Jimmy. All rights reserved.
//

#ifndef Supernova_SupernovaMemoryNedPooling_h
#define Supernova_SupernovaMemoryNedPooling_h

namespace Supernova
{
    
    class NedPoolingImpl
    {
    public:
        static void* allocBytes(size_t count,const char* file , int line ,const char* func);
        static void deallocBytes(size_t align ,size_t count , const char* file , int line , const char* func );
        static void* allocBytesAligned(size_t align ,size_t count , const char* file , int line , const char* func);
        static void deallocBytesAligned(size_t align , void* ptr);
    };
    
    class NedPoolingPolicy
    {
    public:
        static inline void* allocateBytes(size_t count, const char* file = 0 ,int line = 0,const char* func = 0)
        {
            return NedPoolingImpl::allocBytes(count , file, line, func);
        }
        static inline void* deallocateBytes(void* ptr)
        {
            return NedPoolingImpl::deallocBytes(ptr);
        }
        static inline size_t getMaxAllocationSize()
        {
            return std::numeric_limits<size_t>::max();
        }
    private:
        NedPoolingPolicy()
        {}
    };
    
    template <size_t Alignment = 0>
    class NedPoolingAlignedPolicy
    {
    public:
        typedef int IsValidAlignment [Alignment <= 128 && ((Alignment & (Alignment-1)) ==0 )? +1 : -1]
    }
}


#endif
