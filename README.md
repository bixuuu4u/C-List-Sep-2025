# C Doubly Linked List

A simple implementation of a **doubly linked list in C**, inspired by the C++ STL `list` container.  
It demonstrates how to create a dynamic container with nodes containing `prev` and `next` pointers.

## Features

- **push_back(value)** – Add a node to the end of the list.
- **push_front(value)** – Add a node to the start of the list.
- **pop_back() / pop_front()** – Remove nodes from the end or start.
- **insert(position, value)** – Insert a node at a specific index.
- **erase(position)** – Remove a node at a specific index.
- **front() / back()** – Get the value of the first or last node.
- **clear()** – Delete all nodes and reset the list.
- **empty() / size()** – Check if the list is empty and get the current size.
- **display()** – Print all elements in order.

## Implementation Notes

- Uses **struct Node** for each element, storing `data`, `prev`, and `next`.
- Uses **struct List** to store `head`, `tail`, and `size` of the list.
- Demonstrates memory management with `malloc()` and `free()`.
- Mimics C++ STL behavior while using plain C.

## Example Usage

```c
#include "list.h"

int main() {
    List l;
    init_list(&l);

    push_back(&l, 10);
    push_back(&l, 20);
    push_front(&l, 5);
    display(&l);  // Output: 5 -> 10 -> 20 -> NULL

    insert(&l, 1, 7);  // Insert 7 at index 1
    display(&l);        // Output: 5 -> 7 -> 10 -> 20 -> NULL

    erase(&l, 2);       // Delete element at index 2
    display(&l);        // Output: 5 -> 7 -> 20 -> NULL

    clear(&l);          // Remove all nodes

    return 0;
}
```
