# Data Structures in C++

A structured collection of fundamental data structures implemented in C++. This repository focuses on understanding internal implementations, memory management, pointer manipulation, and the different approaches used to build and manage common data structures.

It also serves as a personal learning and revision reference, containing concise notes about core concepts, operations, characteristics, and algorithmic complexities.

---

## Repository Structure & Module Overview

The project is organized into modules, with each directory covering a specific data structure and its implementation variations.

| **Module** | **Implementations** | **Description** |
|---|---|---|
| **1. Linked List** | Singly Linked List<br>Doubly Linked List<br>Circular Linked List | Explores dynamic node-based structures, pointer manipulation, and different linking mechanisms. |
| **2. Stack** | Array-Based Stack<br>Linked List-Based Stack<br>Stack Applications | Demonstrates the Last-In, First-Out (LIFO) principle through different implementation approaches and practical applications. |
| **3. Queue** | Linear Queue<br>Circular Queue<br>Array-Based Queue<br>Linked List-Based Queue<br>Queue Using Linked List | Covers First-In, First-Out (FIFO) structures and different approaches to managing insertion and removal operations. |
| **4. Trees** | Binary Tree | Introduces hierarchical data structures and their fundamental implementation concepts. |

## Repository Organization

```text
Data Structures/
│
├── .vscode/
│
├── 1- Linked_List/
│   ├── CircliyLinkedList.cpp
│   ├── Doubly_Linked_List.cpp
│   └── Linked_List.cpp
│
├── 2- Stack/
│   ├── Stack_Apps.cpp
│   ├── Stack_array.cpp
│   └── Stack_list.cpp
│
├── 3- Queue/
│   ├── Circular_queue.cpp
│   ├── Linear_queue.cpp
│   ├── Queue_array.cpp
│   ├── Queue_List.cpp
│   └── Queue_Using_LinkedList.cpp
│
├── 4- Trees/
│   └── BinaryTree.cpp
│
├── .gitignore
├── Board.excalidraw
└── README.md
```

---

# Study Notes & Key Concepts

A compact revision guide covering the fundamental concepts, operations, characteristics, and complexities of the implemented data structures.

## 1. Linked Lists

A Linked List is a dynamic linear data structure consisting of nodes, where each node stores data and one or more pointers connecting it to other nodes.

### Types

- **Singly Linked List:** Each node points to the next node.
- **Doubly Linked List:** Each node contains pointers to both the previous and next nodes.
- **Circular Linked List:** The last node points back to the first node.

### Core Operations

- Insertion and deletion.
- Traversal.
- Searching.
- Updating node values.

### Key Points

- Supports dynamic memory allocation.
- Does not require contiguous memory.
- Provides sequential access rather than direct indexing.
- Insertion and deletion at the head take O(1).

## 2. Stack

A Stack is a linear data structure that follows the **Last-In, First-Out (LIFO)** principle.

### Core Operations

| Operation | Description | Time Complexity |
|---|---|---|
| `push()` | Insert an element | O(1)* |
| `pop()` | Remove the top element | O(1) |
| `top()` | Access the top element | O(1) |
| `empty()` | Check whether the stack is empty | O(1) |

*Array-based stacks may require O(N) when resizing occurs.*

### Implementation Approaches

- **Array-Based Stack:** Uses an array to store elements.
- **Linked List-Based Stack:** Uses dynamically allocated nodes.

### Common Applications

- Function call management.
- Expression evaluation.
- Parentheses matching.
- Reversing sequences.

## 3. Queue

A Queue is a linear data structure that follows the **First-In, First-Out (FIFO)** principle.

### Core Operations

| Operation | Description | Time Complexity |
|---|---|---|
| `enqueue()` | Insert an element at the rear | O(1) |
| `dequeue()` | Remove an element from the front | O(1) |
| `front()` | Access the first element | O(1) |
| `empty()` | Check whether the queue is empty | O(1) |

### Types & Implementations

- **Linear Queue:** Standard FIFO implementation.
- **Circular Queue:** Connects the last array position back to the first using circular indexing.
- **Array-Based Queue:** Stores elements in contiguous memory.
- **Linked List-Based Queue:** Uses dynamically allocated nodes.

### Important Concept: Circular Indexing

Circular Queue indexing allows efficient reuse of previously occupied array positions.

\[
\text{next} = (\text{current} + 1) \bmod \text{capacity}
\]

## 4. Binary Tree

A Binary Tree is a hierarchical data structure in which each node can have at most two children.

- Left Child
- Right Child

### Basic Terminology

- **Root:** The topmost node.
- **Parent:** A node that has children.
- **Child:** A node connected below another node.
- **Leaf:** A node with no children.
- **Subtree:** A tree formed by a node and its descendants.
- **Height:** The length of the longest path from a node to a leaf.

### Tree Traversals

| Traversal | Visiting Order |
|---|---|
| Preorder | Root → Left → Right |
| Inorder | Left → Root → Right |
| Postorder | Left → Right → Root |
| Level Order | Level by level |

### Key Points

- Each node has at most two children.
- Recursive algorithms are commonly used for tree traversal.
- Traversing all nodes takes O(N).
- Searching in a general Binary Tree takes O(N).

---

## Algorithmic Complexity Reference

A quick comparison of the common operations across the implemented data structures.

| **Data Structure** | **Access** | **Search** | **Insertion** | **Deletion** |
|---|---|---|---|---|
| Singly Linked List | O(N) | O(N) | O(1)* | O(1)* |
| Doubly Linked List | O(N) | O(N) | O(1)* | O(1)* |
| Stack | O(1)** | O(N) | O(1)*** | O(1) |
| Queue | O(1)** | O(N) | O(1)*** | O(1) |
| Binary Tree | O(N) | O(N) | O(N)**** | O(N)**** |

**Complexity Notes:**

1. **Linked Lists:** O(1) insertion/deletion assumes the target position or required node pointer is already known.
2. **Stack & Queue:** O(1) access refers to accessing the top of a Stack or the front of a Queue.
3. **Array-Based Implementations:** Resizing may require O(N), while dynamic array insertion is O(1) amortized.
4. **Binary Tree:** Insertion and deletion complexities depend on the implementation and tree structure.

---

## Learning Objectives

- Understand the internal structure of fundamental data structures.
- Practice implementing data structures from scratch.
- Explore different implementation approaches and their trade-offs.
- Understand memory allocation and pointer manipulation.
- Analyze time and space complexity.
- Strengthen problem-solving and algorithmic thinking.

---

## Repository Status

This repository is continuously evolving as more implementations, examples, and learning materials are added.

---

**Language:** C++  
**Focus:** Data Structures & Algorithms
