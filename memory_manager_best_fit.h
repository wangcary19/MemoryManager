#ifndef MEMORY_MANAGER_BEST_FIT_H
#define MEMORY_MANAGER_BEST_FIT_H

#include "memory_manager_base.h"
#include <list>
#include <string>

using namespace std;

// memory_manager_best_fit.h
//
// Class implementing a best fit memory manager

class MemoryManagerBestFit : public MemoryManagerBase {

    public:

        // Constructor.
        // This function initializes the data structure
        // that tracks the memory blocks
        explicit MemoryManagerBestFit(int size);
        
        // Allocate the indicated amount of memory.
        // See the comments in memory_manager_base.h for details
        int allocate(int size, string name) override;

        // Release the memory with the given name.
        // See the comments in memory_manager_base.h for details
        bool release(string name) override;

    private:      

};

#endif