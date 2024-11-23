#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to display memory allocation
void displayAllocation(const vector<int>& blockSize, const vector<int>& processSize, const vector<int>& allocation) {
    cout << "Process No.\tProcess Size\tBlock No.\tBlock Size\n";
    for (size_t i = 0; i < allocation.size(); ++i) {
        if (allocation[i] != -1) {
            cout << "   " << i + 1 << "\t\t" << processSize[i]
                 << "\t\t" << allocation[i] + 1 << "\t\t" << blockSize[allocation[i]] << endl;
        } else {
            cout << "   " << i + 1 << "\t\t" << processSize[i] << "\t\tNot Allocated\n";
        }
    }
}

// First-Fit Memory Allocation
vector<int> firstFit(const vector<int>& blockSize, const vector<int>& processSize) {
    vector<int> allocation(processSize.size(), -1); // -1 means not allocated
    vector<int> blocks = blockSize;
    
    for (size_t i = 0; i < processSize.size(); ++i) {
        for (size_t j = 0; j < blocks.size(); ++j) {
            if (blocks[j] >= processSize[i]) {
                allocation[i] = j;
                blocks[j] -= processSize[i]; // Reduce the available block size
                break;
            }
        }
    }
    return allocation;
}

// Best-Fit Memory Allocation
vector<int> bestFit(const vector<int>& blockSize, const vector<int>& processSize) {
    vector<int> allocation(processSize.size(), -1); // -1 means not allocated
    vector<int> blocks = blockSize;
    
    for (size_t i = 0; i < processSize.size(); ++i) {
        int bestIdx = -1;
        for (size_t j = 0; j < blocks.size(); ++j) {
            if (blocks[j] >= processSize[i]) {
                if (bestIdx == -1 || blocks[bestIdx] > blocks[j]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blocks[bestIdx] -= processSize[i]; // Reduce the available block size
        }
    }
    return allocation;
}

// Worst-Fit Memory Allocation
vector<int> worstFit(const vector<int>& blockSize, const vector<int>& processSize) {
    vector<int> allocation(processSize.size(), -1); // -1 means not allocated
    vector<int> blocks = blockSize;
    
    for (size_t i = 0; i < processSize.size(); ++i) {
        int worstIdx = -1;
        for (size_t j = 0; j < blocks.size(); ++j) {
            if (blocks[j] >= processSize[i]) {
                if (worstIdx == -1 || blocks[worstIdx] < blocks[j]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blocks[worstIdx] -= processSize[i]; // Reduce the available block size
        }
    }
    return allocation;
}

int main() {
    // Sample input for memory blocks and processes
    vector<int> blockSize = {100, 500, 200, 300, 600}; // Block sizes
    vector<int> processSize = {212, 417, 112, 426};    // Process sizes

    // First-Fit Allocation
    vector<int> firstFitAlloc = firstFit(blockSize, processSize);
    cout << "First-Fit Allocation:\n";
    displayAllocation(blockSize, processSize, firstFitAlloc);

    // Best-Fit Allocation
    vector<int> bestFitAlloc = bestFit(blockSize, processSize);
    cout << "\nBest-Fit Allocation:\n";
    displayAllocation(blockSize, processSize, bestFitAlloc);

    // Worst-Fit Allocation
    vector<int> worstFitAlloc = worstFit(blockSize, processSize);
    cout << "\nWorst-Fit Allocation:\n";
    displayAllocation(blockSize, processSize, worstFitAlloc);

    return 0;
}
