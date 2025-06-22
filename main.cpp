#include "iostream"
#include <cstdlib>
#include <new>

typedef struct Allocation {
    void* next;
    std::size_t size;
} Allocation;


Allocation allocation = Allocation{nullptr, 0};


/* Get address to a pointer from new, and return address to the corresponding allocation data structure */
Allocation* ptrToAllocation(void* ptr) {
    return (Allocation*)((char*)ptr - sizeof(Allocation));
}


/* Get address to an allocation data structure, and return address to the corresponding pointer from new */
void* AllocationToPtr(Allocation* allocation) {
    return (void*)((char*)allocation + sizeof(Allocation));
}


/* Add a new allocation data to the linked list of currently allocated memory */
void newAllocation(void* ptr, std::size_t size) {
    // Modify tail to point to the new node of allocated memory
    Allocation* curr = &allocation;
    while (curr->next) {
        curr = ptrToAllocation(curr->next);
    }
    curr->next = ptr;

    // Update new object at tail to contain the correct size, and point to null as it's last
    Allocation* next = ptrToAllocation(curr->next);
    next->next = nullptr;
    next->size = size;
}


void deleteAllocation(void* ptr) {
    Allocation* curr = &allocation;
    if (!curr->next) {
        return;
    }
    Allocation* next = ptrToAllocation(curr->next);

    while (AllocationToPtr(next) != ptr) {
        curr = next;
        if (!curr->next) {
            return;
        }
        next = ptrToAllocation(curr->next);
    }

    curr->next = next->next;
}


/* Print a list of all the memory that is currently allocated */
void printAllocations() {
    std:: cout << "\nCurrently dynamically allocated memory: " << std::endl;
    Allocation* curr = &allocation;
    while (curr->next) {
        auto* next = ptrToAllocation(curr->next);
        std::cout << "\tAddress: " << curr->next << ", size: " << next->size << std::endl;
        curr = next;
    }
}


void* operator new(std::size_t size) {
    if (size == 0) {
        ++size; // avoid std::malloc(0) which may return nullptr on success
    }

    if (void *ptr = std::malloc(size + sizeof(Allocation))) {
        void* new_ptr = (void*)((char*)ptr + sizeof(Allocation));
        newAllocation(new_ptr, size);
        return new_ptr;
    }

    throw std::bad_alloc{}; // required by [new.delete.single]/3
}

void operator delete(void* ptr) noexcept {
    deleteAllocation(ptr);
    std::free(ptrToAllocation(ptr));
}


int main() {
    short* a = new short;
    int*  b = new int;
    long* c = new long;
    std::cout << "[debug] Allocated short a at: " << a << std::endl;
    std::cout << "[debug] Allocated int   b at: " << b << std::endl;
    std::cout << "[debug] Allocated long  c at: " << c << std::endl;

    printAllocations();

    delete(a);
    std::cout << "\n[debug] Deleted a" << std::endl;
    printAllocations();

    delete(c);
    std::cout << "\n[debug] Deleted c" << std::endl;
    printAllocations();

    delete(b);
    std::cout << "\n[debug] Deleted c" << std::endl;
    printAllocations();

    return 0;
}
