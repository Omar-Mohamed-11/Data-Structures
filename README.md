# Data Structures in C++

A collection of practical C++ data-structure implementations, organized by topic for easier learning and review. Each source file is a self-contained implementation with simple usage examples.

## Contents

```text
.
├── 1- Linked_List/        # Singly, doubly, and circular linked lists
├── 2- Stack/              # Array- and list-based stacks, plus applications
├── 3- Queue/              # Linear, circular, array-, and list-based queues
└── 4- Trees/              # Binary-tree implementation and traversals
```

| Directory | Contents |
| --- | --- |
| `1- Linked_List` | `Linked_List.cpp`, `Doubly_Linked_List.cpp`, `CirclyLinkedList.cpp` |
| `2- Stack` | `Stack_array.cpp`, `Stack_list.cpp`, `Stack_Apps.cpp` |
| `3- Queue` | `Linear_queue.cpp`, `Circular_queue.cpp`, `Queue_array.cpp`, `Queue_List.cpp`, `Queue_Using_LinkedList.cpp` |
| `4- Trees` | `BinaryTree.cpp` |

## Prerequisites

- A C++17-compatible compiler: GCC, Clang, or MSVC.
- A terminal or IDE such as Visual Studio Code to compile and run individual examples.

## Build an example

Compile any file independently. For example, with GCC or Clang:

```bash
g++ -std=c++17 "4- Trees/BinaryTree.cpp" -o binary_tree
./binary_tree
```

On Windows with MSVC:

```powershell
cl /std:c++17 "4- Trees\BinaryTree.cpp"
```

Generated binaries, build folders, editor settings, and diagram files are intentionally excluded from version control via `.gitignore`.
