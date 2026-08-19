# 📚 Data Structures & Algorithms — C++ Implementations

Practice code, lab tasks, and assignment solutions from the **Data Structures and Algorithms Lab**, Department of Computer Science, University of Engineering and Technology (UET), Lahore.

This repo is a personal archive of everything I implemented and practiced — Arrays, Linked Lists, Stacks, and Queues — including core operations, dry runs, and real-world application programs.

---

## 🗂️ Repo Structure

```
📁 #1. List and Array
📁 #2. Stack
   └── 📁 Stack_Applications
📁 #3. Queue
```

---

## 1️⃣ Arrays & Linked Lists

**Folder:** `#1. List and Array`

Covers array fundamentals and both singly & doubly linked list implementations.

| File | What it does |
|---|---|
| `Arrays_Functions.cpp` | Core array operations (traverse, insert, delete, search) |
| `Arrays_Task1.cpp` / `Arrays_Task2.cpp` | Assignment tasks on arrays |
| `Dynamic_Array.cpp` | Custom dynamic array class (resize, append, capacity) |
| `List_Functions.cpp` | Generic linked list helper functions |
| `Full_Link_List.cpp` / `Linked_List_All_in_one.cpp` | Complete singly linked list (insert/update/delete at start, end, position) |
| `My_Linked_List.cpp` | Personal practice version of singly linked list |
| `Doubly_list.cpp` / `My_Doubly_list.cpp` | Doubly linked list with forward/backward traversal |

**Topics practiced:** memory layout, random access vs traversal, insertion/deletion complexity, reverse a linked list, find middle node (slow/fast pointer), cycle detection, merge sorted lists, remove duplicates, rotate array/list.

---

## 2️⃣ Stack

**Folder:** `#2. Stack`

LIFO structure — array-based and linked-list-based implementations, plus real applications.

| File | What it does |
|---|---|
| `stack_with_array.cpp` | Stack using array (push, pop, peek, overflow/underflow) |
| `Stack_with_Linked_list.cpp` | Stack using linked list (push/pop at head) |
| `Stack_Task3.cpp` | Assignment task |

**`Stack_Applications/`** — real-world & problem-solving uses of stack:

| File | What it does |
|---|---|
| `Reverse_a_String.cpp` | Reverse a string using stack |
| `Task2.cpp` | Balanced parentheses checker |
| `Task3.cpp` | Infix → Postfix conversion |
| `Task4.cpp` | Postfix expression evaluation |
| `Task5.cpp` | Decimal → Binary using stack |
| `Task6.cpp` | Palindrome check using stack |

---

## 3️⃣ Queue

**Folder:** `#3. Queue`

FIFO structure — array, circular, and linked-list implementations, plus applications.

| File | What it does |
|---|---|
| `Queue_with_Array2.cpp` / `Queue_by_array.exe` | Queue using array |
| `Circular_Queue.cpp` | Circular queue (solves memory wastage of simple array queue) |
| `queue_by_linked_list.cpp` | Queue using linked list (dynamic size) |
| `My_Best_queue.cpp` | Personal best/clean implementation |
| `Printer_queue_system.cpp` | Real-world simulation — printer job queue |
| `Task1.cpp` | Reverse a queue using stack |
| `Task2.cpp` | Generate binary numbers using queue |
| `Task4.cpp` | BFS traversal using queue |
| `Task5.cpp` | Queue using two stacks |
| `Ideal_Task2.cpp` | Alternate/refined solution |

**Topics practiced:** enqueue/dequeue, overflow/underflow, circular queue formula `(rear+1) % SIZE`, BFS, CPU scheduling (Round Robin) concept, priority queue (conceptual).

---

## ⚙️ How to Run

Every `.cpp` file can be compiled and run individually:

```bash
g++ filename.cpp -o filename
./filename
```

*(`.exe` files included are just compiled Windows binaries from local testing — the `.cpp` source is the actual code.)*

---

## 🎯 Purpose

This repo isn't a polished library — it's my **practice trail**: every task, dry run, and small experiment I did while learning DS from lab manuals and assignments. Kept here for revision before exams/vivas and to track progress over the semester.

---

## 🙋 Author

**Asim** — BS Computer Science, UET
