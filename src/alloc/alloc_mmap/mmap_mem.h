/*
* Memory Mapping Allocator
* (C) 1999-2007 Jack Lloyd
*
* Distributed under the terms of the Botan license
*/

#ifndef BOTAN_MMAP_ALLOCATOR_H__
#define BOTAN_MMAP_ALLOCATOR_H__

#include <botan/internal/mem_pool.h>

namespace Botan {

/**
* Allocator that uses memory maps backed by disk. We zeroize the map
* upon deallocation. If swap occurs, the VM will swap to the shared
* file backing rather than to a swap device, which means we know where
* it is and can zap it later.
*/
class MemoryMapping_Allocator : public Pooling_Allocator
   {
   public:
      MemoryMapping_Allocator(Mutex* m) : Pooling_Allocator(m) {}
      std::string type() const { return "mmap"; }
   private:
      void* alloc_block(u32bit);
      void dealloc_block(void*, u32bit);
   };

}

#endif
