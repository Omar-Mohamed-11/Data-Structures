# Data Structures in C++

مجموعة تطبيقات عملية لهياكل البيانات بلغة C++، مرتبة حسب الموضوع لتسهيل التعلّم والمراجعة. يحتوي كل ملف على تنفيذ مستقل مع أمثلة تشغيل بسيطة.

A collection of practical C++ data-structure implementations, organized by topic for easier learning and review. Each source file is a self-contained implementation with simple usage examples.

## Contents | المحتويات

```text
.
├── 1.Dynamic_Array/       # Reserved for dynamic-array implementations
├── 2.Linked_List/         # Singly, doubly, and circular linked lists
├── 3.Stack/               # Array- and list-based stacks, plus applications
├── 4.Queue/               # Linear, circular, array-, and list-based queues
├── 5.Trees/               # Binary-tree implementation and traversals
└── 6.Miscellaneous/       # Small experiments and practice files
```

| Directory | Contents |
| --- | --- |
| `1.Dynamic_Array` | Placeholder for future dynamic-array examples. |
| `2.Linked_List` | `Linked_List.cpp`, `Doubly_Linked_List.cpp`, `CirclyLinkedList.cpp` |
| `3.Stack` | `Stack_array.cpp`, `Stack_list.cpp`, `Stack_Apps.cpp` |
| `4.Queue` | `Linear_queue.cpp`, `Circular_queue.cpp`, `Queue_array.cpp`, `Queue_List.cpp`, `Queue_Using_LinkedList.cpp` |
| `5.Trees` | `BinaryTree.cpp` |
| `6.Miscellaneous` | General practice files such as `Test.cpp` |

## Prerequisites | المتطلبات

- A C++17-compatible compiler: GCC, Clang, or MSVC.
- A terminal or IDE such as Visual Studio Code to compile and run individual examples.

## Build an example | تشغيل مثال

Compile any file independently. For example, with GCC or Clang:

```bash
g++ -std=c++17 5.Trees/BinaryTree.cpp -o binary_tree
./binary_tree
```

On Windows with MSVC:

```powershell
cl /std:c++17 5.Trees\BinaryTree.cpp
```

Generated binaries, build folders, editor settings, and diagram files are intentionally excluded from version control via `.gitignore`.
