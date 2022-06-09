#include "memory_manager_best_fit.h"
#include <string>

using namespace std;

MemoryManagerBestFit::MemoryManagerBestFit(int size)
{
    
    // Set up the list of memory blocks with the info for this initial
    // unallocated block.
    memory_block b;
    
    // TODO: Fill in the appropriate values here based on the data elements you added in the header file.
    // Note: finished!

    b.block_name = "";
    b.len = size;
    b.allocated = false;
    b.start = 0;

    // Add the block to the list of blocks
    m_blocks.push_back(b);
}


// Allocate memory
int MemoryManagerBestFit::allocate(int size, string name)
{
    // TODO: Implement the allocate logic here
    // Note: finished!

    auto head = m_blocks.begin();
    auto temp = m_blocks.begin();
    int out;
    int min_len = INT_MAX;
    for (int i = 0; i < m_blocks.size(); i++) {
        head = m_blocks.begin();
        advance(head, i);
        if (head->len == size and !head->allocated) { //If the block to be assigned is exactly the same size as the amount needed, set its data values to indicate that it is assigned.

            head->block_name = name;
            head->len = size;
            head->allocated = true;

            return i;  //Return the location of the block that was allocated.
        }
        else if (head->len > size and !head->allocated and head->len < min_len) {
            min_len = head->len;
            out = i;
            temp = head;
        }
        else if (head == m_blocks.end() and head->allocated) {
            return -1;
        }
        else {
            continue;
        }
    }

    memory_block n;
    n.start = temp->start;
    n.block_name = name;
    n.allocated = true;
    n.len = size;

    //Update old block
    temp->start = temp->start + size;
    temp->len = temp->len - size;
    //Insert new partition before old
    m_blocks.insert(temp, n);

    return out;  //Return the location of the block that was allocated.
}

// Release memory
bool MemoryManagerBestFit::release(string name) { //Return true if the block was successfully released, and false otherwise
    // TODO: Implement the release logic
    // Note: finished!

    auto temp = m_blocks.begin();
    for (int i = 0; i < m_blocks.size(); i++) {
        auto head = m_blocks.begin();
        advance(head, i);
        if (head->block_name == name) { //Find the block with the indicated name.

            head->block_name = ""; //Change the name of the block to "" to indicate that it is empty.
            head->allocated = false;

            //Check if next block is empty; if so, coalesce
            if (head != m_blocks.end()) {
                advance(head, 1);
                if (head->allocated) {
                    return true;
                }
                else {
                    int templen = head->len; //Grab len of following block
                    advance(head, -1); //Go back to original block
                    head->len = head->len + templen; //Coalesce

                    advance(head, 1);
                    advance(temp,i + 2);
                    m_blocks.erase(head, temp);
                    return true;
                }
            }
        }
    }
    return false;
}