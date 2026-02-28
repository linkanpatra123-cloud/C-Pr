#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d) {
        title = t;
        author = a;
        dueDate = d;
    }

    virtual ~LibraryItem() {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

class Book : public LibraryItem {
private:
    string isbn;
    bool issued;

public:
    Book(string t, string a, string d, string i)
        : LibraryItem(t, a, d) {

        if (i.length() != 13)
            throw "Invalid ISBN! Must be 13 characters.";

        isbn = i;
        issued = false;
    }

    void checkOut() {
        if (issued)
            cout << "Book already issued."<<endl;
        else {
            issued = true;
            cout << "Book checked out successfully."<<endl;
        }
    }

    void returnItem() {
        if (!issued)
            cout << "Book was not issued."<<endl;
        else {
            issued = false;
            cout << "Book returned successfully."<<endl;
        }
    }

    void displayDetails() const {
        cout <<endl<< "[BOOK]"<<endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Status: " << (issued ? "Issued" : "Available") << endl;
    }
};

class DVD : public LibraryItem {
private:
    int duration;
    bool issued;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d) {

        if (dur <= 0)
            throw "Invalid duration!";

        duration = dur;
        issued = false;
    }

    void checkOut() {
        if (issued)
            cout << "DVD already issued."<<endl;
        else {
            issued = true;
            cout << "DVD checked out successfully."<<endl;
        }
    }

    void returnItem() {
        if (!issued)
            cout << "DVD was not issued."<<endl;
        else {
            issued = false;
            cout << "DVD returned successfully."<<endl;
        }
    }

    void displayDetails() const {
        cout <<endl<< "[DVD]"<<endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Duration: " << duration << " minutes"<<endl;
        cout << "Status: " << (issued ? "Issued" : "Available") << endl;
    }
};

class Magazine : public LibraryItem {
private:
    int issueNumber;
    bool issued;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d) {

        if (issue <= 0)
            throw "Invalid issue number!";

        issueNumber = issue;
        issued = false;
    }

    void checkOut() {
        if (issued)
            cout << "Magazine already issued."<<endl;
        else {
            issued = true;
            cout << "Magazine checked out successfully."<<endl;
        }
    }

    void returnItem() {
        if (!issued)
            cout << "Magazine was not issued."<<endl;
        else {
            issued = false;
            cout << "Magazine returned successfully."<<endl;
        }
    }

    void displayDetails() const {
        cout <<endl<< "[MAGAZINE]"<<endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Status: " << (issued ? "Issued" : "Available") << endl;
    }
};

int main() {

    int capacity = 2;  
    int count = 0;

    LibraryItem** items = new LibraryItem*[capacity];

    int choice;

    do {
        cout <<endl<< "===== LIBRARY MANAGEMENT SYSTEM ====="<<endl;
        cout << "1. Add Book"<<endl;
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine"<<endl;
        cout << "4. Display All Items"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        try {

            if (choice >= 1 && choice <= 3) {

                if (count == capacity) {
                    capacity *= 2;
                    LibraryItem** temp = new LibraryItem*[capacity];

                    for (int i = 0; i < count; i++)
                        temp[i] = items[i];

                    delete[] items;
                    items = temp;
                }

                string t, a, d;
                cin.ignore();
                cout << "Enter Title: ";
                getline(cin, t);
                cout << "Enter Author: ";
                getline(cin, a);
                cout << "Enter Due Date: ";
                getline(cin, d);

                if (choice == 1) {
                    string isbn;
                    cout << "Enter ISBN (13 chars): ";
                    getline(cin, isbn);
                    items[count++] = new Book(t, a, d, isbn);
                }
                else if (choice == 2) {
                    int dur;
                    cout << "Enter Duration: ";
                    cin >> dur;
                    items[count++] = new DVD(t, a, d, dur);
                }
                else {
                    int issue;
                    cout << "Enter Issue Number: ";
                    cin >> issue;
                    items[count++] = new Magazine(t, a, d, issue);
                }
            }

            else if (choice == 4) {
                for (int i = 0; i < count; i++) {
                    cout <<endl<< "Index: " << i;
                    items[i]->displayDetails();
                }
            }

        } catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }

    } while (choice != 0);

    for (int i = 0; i < count; i++)
        delete items[i];

    delete[] items;

    cout << "Program Ended."<<endl;
    return 0;
}

//output
//
//===== LIBRARY MANAGEMENT SYSTEM =====
//1. Add Book
//2. Add DVD
//3. Add Magazine
//4. Display All Items
//0. Exit
//Enter choice: 1
//Enter Title: ddds
//Enter Author: ssaas
//Enter Due Date: 12
//Enter ISBN (13 chars): 11fadwaafeef
//Error: Invalid ISBN! Must be 13 characters.
//
//===== LIBRARY MANAGEMENT SYSTEM =====
//1. Add Book
//2. Add DVD
//3. Add Magazine
//4. Display All Items
//0. Exit
//Enter choice: 2
//Enter Title: ass
//Enter Author: asffe
//Enter Due Date: 12
//Enter Duration: 2
//
//===== LIBRARY MANAGEMENT SYSTEM =====
//1. Add Book
//2. Add DVD
//3. Add Magazine
//4. Display All Items
//0. Exit
//Enter choice: 4
//
//Index: 0
//[DVD]
//Title: ass
//Author: asffe
//Due Date: 12
//Duration: 2 minutes
//Status: Available