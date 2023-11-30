//13. Simulate first fit, best fit and worst fit memory allocation strategies using linked list.

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Block {
//     int size;
//     int process;
//     struct Block* link;
// } Block;

// Block* createBlock(int size) {
//     Block* block = (Block*)malloc(sizeof(Block));
//     block->size = size;
//     block->process = 0;
//     block->link = NULL;
//     return block;
// }

// void displayMemoryBlocks(Block* head) {
//     Block* current = head;
//     while (current != NULL) {
//         printf("Block Size: %d KB,", current->size);
//         printf("Allocated Memory: %d KB\n", current->process);
//         current = current->link;
//     }
// }

// void allocateFirstFit(Block** head, int processSize) {
//     Block* current = *head;

//     while (current != NULL) {
//         if (current->size - current->process >= processSize) {
//             current->process += processSize;
//             printf("for %d KB process : %d KB Block\n", processSize, current->size);
//             return;
//         }
//         current = current->link;
//     }
//     printf("Not enough memory for process %d KB\n", processSize);
// }

// void allocateBestFit(Block** head, int processSize) {
//     Block* current = *head;
//     Block* bfBlock = NULL;

//     while (current != NULL) {
//         if (current->size - current->process >= processSize) {
//             if (bfBlock && (current->size - current->process < bfBlock->size - bfBlock->process)) {
//                 bfBlock = current;
//             }
//         }

//         current = current->link;
//     }

//     if (bfBlock) {
//         bfBlock->process += processSize;
//         printf("for %d KB process : %d KB Block\n", processSize, bfBlock->size);
//     } else {
//         printf("Not enough memory for process %d KB\n", processSize);
//     }
// }

// void allocateWorstFit(Block** head, int processSize) {
//     Block* current = *head;
//     Block* worstFitBlock = NULL;

//     while (current != NULL) {
//         if (current->size - current->process >= processSize) {
//             if (worstFitBlock == NULL || (current->size - current->process > worstFitBlock->size - worstFitBlock->process)) {
//                 worstFitBlock = current;
//             }
//         }

//         current = current->link;
//     }

//     if (worstFitBlock != NULL) {
//         worstFitBlock->process += processSize;
//         printf("Memory allocated for process of size %d KB using Worst Fit\n", processSize);
//     } else {
//         printf("Not enough memory to allocate for process of size %d KB using Worst Fit\n", processSize);
//     }
// }

// void deallocateMemory(Block** head) {
//     while (*head != NULL) {
//         Block* temp = *head;
//         *head = (*head)->link;
//         free(temp);
//     }
// }

// int main() {
//     Block* memory = createBlock(500);
//     memory->link = createBlock(200);        
//     memory->link->link = createBlock(350);  
//     memory->link->link->link = createBlock(150);

//     printf("Initial Memory State:\n");
//     displayMemoryBlocks(memory);

//     allocateFirstFit(&memory, 300); 
//     allocateFirstFit(&memory, 200);

//     printf("\nMemory State after First Fit:\n");
//     displayMemoryBlocks(memory);

//     deallocateMemory(&memory);

//     memory = createBlock(500);
//     memory->link = createBlock(200);
//     memory->link->link = createBlock(350);
//     memory->link->link->link = createBlock(150);

//     printf("\nInitial Memory State:\n");
//     displayMemoryBlocks(memory);

//     allocateBestFit(&memory, 300);
//     allocateBestFit(&memory, 200);

//     printf("\nMemory State after Best Fit:\n");
//     displayMemoryBlocks(memory);

//     deallocateMemory(&memory);

//     memory = createBlock(500);
//     memory->link = createBlock(200);
//     memory->link->link = createBlock(350);
//     memory->link->link->link = createBlock(150);

//     printf("\nInitial Memory State:\n");
//     displayMemoryBlocks(memory);

//     allocateWorstFit(&memory, 300);
//     allocateWorstFit(&memory, 200); 

//     // Display memory state after Worst Fit
//     printf("\nMemory State after Worst Fit:\n");
//     displayMemoryBlocks(memory);

//     // Clear memory
//     deallocateMemory(&memory);

//     return 0;
// }


/*Algorithm
Step 1: Start.

*/
