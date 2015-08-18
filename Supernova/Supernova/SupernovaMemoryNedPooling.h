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
        static void deallocBytesAligned(size_t align , void* ptr);
    };
}


#endif
