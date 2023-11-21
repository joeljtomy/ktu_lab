//13. Simulate first fit, best fit and worst fit memory allocation strategies using linked list.

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a block of memory
struct MemoryBlock {
    int id;  // Process ID
    int size;  // Size of the block
    struct MemoryBlock* next;  // Pointer to the next block
};

// Function to initialize a new memory block
struct MemoryBlock* createBlock(int id, int size) {
    struct MemoryBlock* block = (struct MemoryBlock*)malloc(sizeof(struct MemoryBlock));
    block->id = id;
    block->size = size;
    block->next = NULL;
    return block;
}

// Function to print the memory blocks
void printMemory(struct MemoryBlock* memory) {
    while (memory != NULL) {
        printf("ID: %d, Size: %d\n", memory->id, memory->size);
        memory = memory->next;
    }
}

// Function to perform First Fit memory allocation
void firstFit(struct MemoryBlock** memory, int id, int size) {
    struct MemoryBlock* newBlock = createBlock(id, size);
    struct MemoryBlock* current = *memory;

    while (current != NULL) {
        if (current->size >= size) {
            newBlock->next = current->next;
            current->next = newBlock;
            return;
        }
        current = current->next;
    }

    // If no suitable block is found, append to the end
    while ((*memory)->next != NULL) {
        *memory = (*memory)->next;
    }
    (*memory)->next = newBlock;
}

// Function to perform Best Fit memory allocation
void bestFit(struct MemoryBlock** memory, int id, int size) {
    struct MemoryBlock* newBlock = createBlock(id, size);
    struct MemoryBlock* current = *memory;
    struct MemoryBlock* bestFitBlock = NULL;

    while (current != NULL) {
        if (current->size >= size && (bestFitBlock == NULL || current->size < bestFitBlock->size)) {
            bestFitBlock = current;
        }
        current = current->next;
    }

    if (bestFitBlock != NULL) {
        newBlock->next = bestFitBlock->next;
        bestFitBlock->next = newBlock;
    } else {
        // If no suitable block is found, append to the end
        while ((*memory)->next != NULL) {
            *memory = (*memory)->next;
        }
        (*memory)->next = newBlock;
    }
}

// Function to perform Worst Fit memory allocation
void worstFit(struct MemoryBlock** memory, int id, int size) {
    struct MemoryBlock* newBlock = createBlock(id, size);
    struct MemoryBlock* current = *memory;
    struct MemoryBlock* worstFitBlock = NULL;

    while (current != NULL) {
        if (current->size >= size && (worstFitBlock == NULL || current->size > worstFitBlock->size)) {
            worstFitBlock = current;
        }
        current = current->next;
    }

    if (worstFitBlock != NULL) {
        newBlock->next = worstFitBlock->next;
        worstFitBlock->next = newBlock;
    } else {
        // If no suitable block is found, append to the end
        while ((*memory)->next != NULL) {
            *memory = (*memory)->next;
        }
        (*memory)->next = newBlock;
    }
}

// Function to release memory occupied by a process
void releaseMemory(struct MemoryBlock** memory, int id) {
    struct MemoryBlock* current = *memory;
    struct MemoryBlock* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (previous != NULL) {
            previous->next = current->next;
        } else {
            *memory = current->next;
        }
        free(current);
    }
}

// Function to free the allocated memory
void freeMemory(struct MemoryBlock** memory) {
    struct MemoryBlock* current = *memory;
    struct MemoryBlock* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *memory = NULL;
}

int main() {
    struct MemoryBlock* memory = createBlock(-1, 0);  // Dummy block representing the entire memory

    // Simulate memory allocation using different strategies
    printf("First Fit:\n");
    firstFit(&memory, 1, 20);
    firstFit(&memory, 2, 10);
    firstFit(&memory, 3, 15);
    printMemory(memory);

    releaseMemory(&memory, 2);

    printf("\nBest Fit:\n");
    bestFit(&memory, 4, 12);
    bestFit(&memory, 5, 18);
    bestFit(&memory, 6, 8);
    printMemory(memory);

    releaseMemory(&memory, 4);

    printf("\nWorst Fit:\n");
    worstFit(&memory, 7, 25);
    worstFit(&memory, 8, 10);
    worstFit(&memory, 9, 15);
    printMemory(memory);

    // Free allocated memory
    freeMemory(&memory);

    return 0;
}

/*Algorithm
Step 1: Start.

*/
