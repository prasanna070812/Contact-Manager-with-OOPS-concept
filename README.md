
# 📒 Contact Management System (C++)

A simple, menu-driven **Contact Management System** built using **C++**, demonstrating Object-Oriented Programming concepts, file handling, and console-based UI design.
This application allows users to **add, view, search, edit, and delete contacts** efficiently using a persistent text-file storage system.

---

## 📝 Problem Statement

Managing personal and professional contacts manually becomes difficult as the list grows. Users need a simple and reliable system to store, retrieve, update, and delete contact information.
This project implements a **C++-based Contact Management System** that performs all major contact operations using file handling while demonstrating core OOP principles.

---

## ✨ Features

### 📌 **1. Add New Contact**

Create and save a new contact with:

* Phone Number
* Name
* Address
* Email ID

Data is stored securely in a text file (`phonedirectory.txt`).

---

### 📌 **2. View All Contacts**

Displays all saved contacts in a clean, readable format.

---

### 📌 **3. Search Contacts**

Supports two search methods:

* 🔍 Search by **Name**
* 🔍 Search by **Phone Number**

---

### 📌 **4. Delete Contacts**

Delete any contact by name.
The system safely rewrites the file without the deleted record.

---

### 📌 **5. Edit / Update Contact**

Modify any existing contact’s:

* Phone
* Name
* Address
* Email

---

### 📌 **6. Robust File Handling**

* Centralized file management through a `FileManager` class
* Automatic file opening and closing
* Exception handling for safe file operations

---

### 📌 **7. Object-Oriented Architecture**

* Inheritance (`Person` → `contact`)
* Virtual functions
* Friend functions for controlled data access

---

### 📌 **8. User-Friendly Console Interface**

* Clean menu
* Clear instructions
* Smooth navigation using `system("cls")`

---


# 🧩 Class Descriptions

### **1. Person**

`Person` is an abstract base class that stores the basic attribute `name`. It defines a pure virtual function `show_details()`, ensuring that all derived classes implement their own version of this function. This class acts as a foundational blueprint for representing a person-like entity in the system.

---

### **2. contact**

The `contact` class inherits from `Person` and represents an individual contact entry. It contains additional attributes such as phone number, address, and email. This class handles all major operations including creating, editing, deleting, searching, and displaying contacts through file management.

---

### **3. FileManager**

`FileManager` is a utility class responsible for handling file operations. It maintains a static `fstream` object that ensures consistent and safe file access. This class simplifies file handling by opening files when required and closing them after use.

---

### **4. output_contacts (Friend Function)**

This friend function has special access to private members of the `contact` class. It reads contact data from the file and displays all stored contacts in a formatted way. It supports the overall functionality by offering an alternative method to list contacts.


## 📂 File Structure

```
📁 Contact-Manager-Cpp/
│
├── main.cpp              # Main source code
├── phonedirectory.txt    # Stores saved contacts
├── modify.txt            # Temporary file used for edit/delete operations
└── README.md             # Documentation
```

---

## 🛠 Technologies Used

* **C++**
* File Handling (fstream)
* Object-Oriented Programming
* Console UI
* Windows System Calls

---

## 🎯 Learning Outcomes

This project helps understand:

* How to perform CRUD operations in C++
* File handling (read/write/update)
* Designing a menu-driven user interface
* Applying OOP concepts in real projects
* Error handling and safe file operations

---





