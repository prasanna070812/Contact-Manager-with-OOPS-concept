#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

// Forward declaration of FileManager class
class FileManager;

// Base class Person with virtual function
class Person {
protected:
    string name;

public:
    virtual void show_details() = 0; // Pure virtual function
};

// Contact class inheriting from Person
class contact : public Person {
private:
    string ph, add, email;

public:
    void save_contact();
    void show_all_contact();
    void search_contact();
    void delete_contact();
    void create();
    void show_contact();
    void update_contact();
    void edit_contact(); // New function declaration
    void menu();

    void show_details()  {
        // Implementation of virtual function from Person class
        show_contact();
    }

    friend void output_contacts(contact c); // Friend function declaration
};

// Singleton-like FileManager class for file handling
class FileManager {
private:
    static fstream file;

public:
    static fstream& get_file() {
        if (!file.is_open()) {
            file.open("phonedirectory.txt", ios::in | ios::out | ios::app);
            if (!file) {
                throw runtime_error("Error opening file: phonedirectory.txt");
            }
        }
        return file;
    }

    static void close_file() {
        if (file.is_open()) {
            file.close();
        }
    }
};

fstream FileManager::file; // Initialize static member

// Function definitions for contact class
void contact::create() {
    system("cls");
    cin.ignore();
    cout << "Enter Phone: ";
    getline(cin, ph);

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter address: ";
    getline(cin, add);

    cout << "Enter email-id: ";
    getline(cin, email);

    cout << endl;
}

void contact::show_contact() {
    system("cls");
    cout << "\t\t\t\t\t\tphone: " << ph << endl;
    cout << "\t\t\t\t\t\tname: " << name << endl;
    cout << "\t\t\t\t\t\taddress: " << add << endl;
    cout << "\t\t\t\t\t\temail: " << email << endl;
}

void contact::update_contact() {
    system("cls");
    cout << "Enter new Phone: ";
    getline(cin, ph);

    cout << "Enter new name: ";
    getline(cin, name);

    cout << "Enter new address: ";
    getline(cin, add);

    cout << "Enter new email-id: ";
    getline(cin, email);

    cout << endl;
}

void contact::menu() {
    system("cls");
    cout<<"\n\t\t     ___________________________________________________________________________________________"<<endl;
        cout<<"\t\t    |                                                  \t\t\t\t\t        |";
        cout<<"\n\t\t    |\t\t\t               CONTACT MANAGEMENT SYSTEM                                |"<<endl;
        cout<<"\t\t    |                                                  \t\t\t\t\t        |";
        cout<<"\n\t\t    |_|"<<endl<<endl<<endl;
    cout << "\n\t\t\t\t\t ______________________________________\n";
    cout << "\t\t\t\t\t|                                      |\n";
    cout << "\n\t\t\t\t\t|                 MENU                 |\n";
    cout << "\n\t\t\t\t\t||\n";
    cout << "\n\t\t\t\t\t|                                      |\n";
    cout << "\n\t\t\t\t\t|Kindly select an option below:        |\n";
    cout << "\n\t\t\t\t\t|1. SAVE CONTACT                       |\n";
    cout << "\n\t\t\t\t\t|2. LIST OF ALL CONTACTS               |\n";
    cout << "\n\t\t\t\t\t|3. SEARCH CONTACT                     |\n";
    cout << "\n\t\t\t\t\t|4. DELETE CONTACT                     |\n";
    cout << "\n\t\t\t\t\t|5. EDIT CONTACT                       |\n"; // New menu option
    cout << "\n\t\t\t\t\t|6. EXIT                               |\n" << endl;
    cout << "\t\t\t\t\t||\n" << endl << endl;
    int ch;
    cout << "\t\t\t\t\t->";
    cin >> ch;
    system("cls");
    switch (ch) {
        case 1:
            try {
                save_contact();
            } catch (const exception& e) {
                cerr << "Error saving contact: " << e.what() << endl;
                system("pause");
            }
            break;
        case 2:
            try {
                show_all_contact();
            } catch (const exception& e) {
                cerr << "Error showing all contacts: " << e.what() << endl;
                system("pause");
            }
            break;
        case 3:
            try {
                search_contact();
            } catch (const exception& e) {
                cerr << "Error searching contact: " << e.what() << endl;
                system("pause");
            }
            break;
        case 4:
            try {
                delete_contact();
            } catch (const exception& e) {
                cerr << "Error deleting contact: " << e.what() << endl;
                system("pause");
            }
            break;
        case 5:
            try {
                edit_contact();
            } catch (const exception& e) {
                cerr << "Error editing contact: " << e.what() << endl;
                system("pause");
            }
            break;
        default:
            break;
    }
}

void contact::save_contact() {
    system("cls");
    cout << "\n\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t|                                        |\n";
    cout << "\n\t\t\t\t|               SAVE CONTACT             |\n";
    cout << "\t\t\t\t||\n" << endl;
    try {
        fstream& file = FileManager::get_file();
        create();
        file << ph << endl << name << endl << add << endl << email << endl;
        cout << "contact created successfully..." << endl;
        FileManager::close_file();
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        throw; // Re-throw the exception for handling in menu()
    }
    system("pause");
    menu();
}

void contact::show_all_contact() {
    system("cls");
    cout << endl;
    cout << "\t\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t\t|                                        |\n";
    cout << "\n\t\t\t\t\t|           LIST OF ALL CONTACTS         |\n";
    cout << "\t\t\t\t\t||\n" << endl;
    try {
        fstream& file = FileManager::get_file();
        file.seekg(0, ios::beg); // Move file pointer to beginning
        int x = 1;
        while (file >> ph >> name >> add >> email) {
            cout << "\t\t\t\t\t\t\t\t(" << x++ << ")" << endl << endl;
            cout << "\t\t\t\t\t\t   phone: " << ph << endl;
            cout << "\t\t\t\t\t\t   name: " << name << endl;
            cout << "\t\t\t\t\t\t   address: " << add << endl;
            cout << "\t\t\t\t\t\t   email: " << email << endl;
            cout << endl << endl;
        }
        FileManager::close_file();
        system("pause");
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        throw; // Re-throw the exception for handling in menu()
    }
    menu();
}

void contact::search_contact() {
    system("cls");
    cout << endl;
    cout << "\t\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t\t|                                        |\n";
    cout << "\n\t\t\t\t\t|              SEARCH CONTACT            |\n";
    cout << "\t\t\t\t\t||\n"
         << endl;
    try {
        fstream& file = FileManager::get_file();
        bool found = false;
        string ch;
        cout << "enter u want to search by name or number ? " << endl;
        cin >> ch;
        if (ch == "number") {
            string num;
            cout << "enter number to search: ";
            cin.ignore();
            getline(cin, num);
            file.seekg(0, ios::beg); // Move file pointer to beginning
            while (file >> ph >> name >> add >> email) {
                if (ph == num) {
                    cout << "phone: " << ph << endl;
                    cout << "name: " << name << endl;
                    cout << "address: " << add << endl;
                    cout << "email: " << email << endl;
                    found = true;
                }
            }
        }
        if (ch == "name") {
            string nm;
            cout << "enter name to search: ";
            cin.ignore();
            getline(cin, nm);
            file.seekg(0, ios::beg); // Move file pointer to beginning
            while (file >> ph >> name >> add >> email) {
                if (name == nm) {
                    cout << "phone: " << ph << endl;
                    cout << "name: " << name << endl;
                    cout << "address: " << add << endl;
                    cout << "email: " << email << endl;
                    found = true;
                }
            }
        }
        FileManager::close_file();
        if (!found) {
            cout << "no such contact saved!" << endl;
        }
        system("pause");
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        throw; // Re-throw the exception for handling in menu()
    }
    menu();
}

void contact::delete_contact() {
    system("cls");
    cout << endl;
    cout << "\t\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t\t|                                        |\n";
    cout << "\n\t\t\t\t\t|              DELETE CONTACT            |\n";
    cout << "\t\t\t\t\t||\n"
         << endl;
    try {
        fstream file1("modify.txt", ios::app | ios::out); // Open a new file for modifications
        if (!file1.is_open()) {
            throw runtime_error("Error opening modify.txt for writing.");
        }
        fstream& file = FileManager::get_file();
        string nm;
        cout << "enter name to delete:";
        cin.ignore();
        getline(cin, nm);
        file.seekg(0, ios::beg); // Move file pointer to beginning
        bool deleted = false;
        while (file >> ph >> name >> add >> email) {
            if (name == nm) {
                cout << "Deleting contact: " << name << endl;
                deleted = true;
            } else {
                file1 << ph << endl << name << endl << add << endl << email << endl;
            }
        }
        file1.close();
        FileManager::close_file();
        if (!deleted) {
            cout << "Contact not found!" << endl;
        } else {
            remove("phonedirectory.txt");
            rename("modify.txt", "phonedirectory.txt");
            cout << "Contact deleted successfully!" << endl;
        }
        system("pause");
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        throw; // Re-throw the exception for handling in menu()
    }
    menu();
}

void contact::edit_contact() {
    system("cls");
    cout << "\n\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t|                                        |\n";
    cout << "\n\t\t\t\t|                EDIT CONTACT            |\n";
    cout << "\t\t\t\t||\n" << endl;
    try {
        fstream file1("modify.txt", ios::app | ios::out); // Open a new file for modifications
        if (!file1.is_open()) {
            throw runtime_error("Error opening modify.txt for writing.");
        }
        fstream& file = FileManager::get_file();
        string nm;
        cout << "enter name to edit:";
        cin.ignore();
        getline(cin, nm);
        file.seekg(0, ios::beg); // Move file pointer to beginning
        bool edited = false;
        while (file >> ph >> name >> add >> email) {
            if (name == nm) {
                cout << "Editing contact: " << name << endl;
                cout << "Enter new Phone: ";
                getline(cin, ph);
                cout << "Enter new name: ";
                getline(cin, name);
                cout << "Enter new address: ";
                getline(cin, add);
                cout << "Enter new email-id: ";
                getline(cin, email);
                edited = true;
            }
            file1 << ph << endl << name << endl << add << endl << email << endl;
        }
        file1.close();
        FileManager::close_file();
        if (!edited) {
            cout << "Contact not found!" << endl;
        } else {
            remove("phonedirectory.txt");
            rename("modify.txt", "phonedirectory.txt");
            cout << "Contact edited successfully!" << endl;
        }
        system("pause");
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        throw; // Re-throw the exception for handling in menu()
    }
    menu();
}

// Friend function implementation
void output_contacts(contact c) {
    system("cls");
    cout << endl;
    cout << "\t\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t\t|                                        |\n";
    cout << "\n\t\t\t\t\t|           LIST OF ALL CONTACTS         |\n";
    cout << "\t\t\t\t\t||\n" << endl;
    try {
        fstream& file = FileManager::get_file();
        file.seekg(0, ios::beg); // Move file pointer to beginning
        int x = 1;
        while (file >> c.ph >> c.name >> c.add >> c.email) {
            cout << "\t\t\t\t\t\t\t\t(" << x++ << ")" << endl << endl;
            cout << "\t\t\t\t\t\t   phone: " << c.ph << endl;
            cout << "\t\t\t\t\t\t   name: " << c.name << endl;
            cout << "\t\t\t\t\t\t   address: " << c.add << endl;
            cout << "\t\t\t\t\t\t   email: " << c.email << endl;
            cout << endl << endl;
        }
        FileManager::close_file();
        system("pause");
    } catch (const exception& e) {
        cerr << "Exception caught in output_contacts: " << e.what() << endl;
        throw; // Re-throw the exception for handling in calling function
    }
}

int main() {
    system("Color F0");
    contact c;
    try {
        c.menu();
    } catch (const exception& e) {
        cerr << "Exception caught in main: " << e.what() << endl;
        system("pause");
        return 1;
    }
    cout << endl;
    cout << "\t\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t\t|                                        |\n";
    cout << "\n\t\t\t\t\t|          THANKS FOR USING CMS!         |\n";
    cout << "\t\t\t\t\t||\n"
         << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    return 0;
}
