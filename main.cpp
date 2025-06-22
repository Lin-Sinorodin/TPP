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


/* Add a new allocation data to the linked list of currently allocated memory */
void addAllocation(void* ptr, std::size_t size) {
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
        addAllocation(new_ptr, size);
        return new_ptr;
    }

    throw std::bad_alloc{}; // required by [new.delete.single]/3
}

void operator delete(void* ptr) noexcept {
    std::free(ptrToAllocation(ptr));
}


int main() {
    int* a = new int;
    long* b = new long;
    std::cout << "[debug] Allocated int  at: " << a << std::endl;
    std::cout << "[debug] Allocated long at: " << b << std::endl;

    printAllocations();

    delete(b);
    delete(a);

    return 0;
}
