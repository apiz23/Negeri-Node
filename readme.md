# Linked List: Malaysian States in C

This is a simple C program that demonstrates how to use **singly linked lists** to manage and manipulate a list of Malaysian states and federal territories. It includes common linked list operations such as insertion, deletion, sorting, and searching.

## 📋 Features

- Display list in **ascending** order
- Display list in **descending** order
- **Sort** the list alphabetically
- **Search** for a specific state or territory
- **Delete** a state or territory from the list
- **Insert** a new state or territory
- **Menu-based** user interface with ASCII art

## 📌 Initial States

The program starts with the following 16 Malaysian states and federal territories:

- Johore, Kelantan, Sabah, Perak, Kedah, Malacca, Putrajaya, Pahang, Perlis, Labuan, Negeri Sembilan, Sarawak, Pulau Pinang, Selangor, Terengganu, Kuala Lumpur1.

## 🧠 How It Works

- Each state is stored as a `Node` in a singly linked list.
- Menu options allow the user to interactively perform various operations on the list.
- Sorting is done using a simple **bubble sort**-like algorithm.
- Searching is **case-insensitive**.
- The program includes `pauseAndClear()` to simulate a console menu feel (uses `system("cls")`, so it's best run on **Windows**).

## 🛠️ Compilation & Execution

### ✅ Requirements

- A C compiler (e.g., GCC)
- Windows terminal (for `system("cls")`)

### 💻 To Compile:

```
gcc linkedlist_states.c -o linkedlist_states

```

▶️ To Run:

```
./linkedlist_states
```

📂 File Structure

```
main.c   # Main C source file
README.md             # This documentation file

```

📧 Author
Written by Hafiz,
Software Engineering student at UTHM 💻
