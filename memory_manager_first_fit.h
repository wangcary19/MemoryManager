#ifndef MEMORY_MANAGER_FIRST_FIT_H
#define MEMORY_MANAGER_FIRST_FIT_H

#include "memory_manager_base.h"
#include <string>
using namespace std;

// memory_manager_first_fit.h
//
// Class implementing a first fit memory allocation algorithm

class MemoryManagerFirstFit : public MemoryManagerBase {

    public:

        // Constructor.
        // This function will initialize the data structure
        // that tracks the memory blocks
        explicit MemoryManagerFirstFit(int size);

        // Allocate the indicated amount of memory.
        // See the comments in memory_manager_base.h for details
        int allocate(int size, string name) override;

        // Release the memory at the given location.
        // See the comments in memory_manager_base.h for details
        bool release(string name) override;
        
    private:

};

#endif