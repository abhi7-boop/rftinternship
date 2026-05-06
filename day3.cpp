#include <iostream>
#include <vector>
using namespace std;

class Item {
protected:
    int id;
    string title;
    bool issued;

public:
    Item(int id, string title) {
        this->id = id;
        this->title = title;
        issued = false;
    }

    virtual void displayDetails() {
        cout << "ID: " << id << "\nTitle: " << title;
        cout << "\nStatus: " << (issued ? "Issued" : "Available") << endl;
    }

    void issueItem() {
        if (!issued) {
            issued = true;
            cout << title << " issued successfully.\n";
        } else {
            cout << title << " already issued.\n";
        }
    }

    void returnItem(int lateDays = 0) {
        if (issued) {
            issued = false;
            cout << title << " returned successfully.\n";
            if (lateDays > 0) {
                cout << "Fine: ₹" << lateDays * 5 << endl;
            }
        } else {
            cout << title << " was not issued.\n";
        }
    }

    bool isAvailable() {
        return !issued;
    }
};

class Book : public Item {
    string author;

public:
    Book(int id, string title, string author)
        : Item(id, title) {
        this->author = author;
    }

    void displayDetails() override {
        cout << "\n--- Book ---\n";
        Item::displayDetails();
        cout << "Author: " << author << endl;
    }
};

class Magazine : public Item {
    int issueNumber;

public:
    Magazine(int id, string title, int issueNumber)
        : Item(id, title) {
        this->issueNumber = issueNumber;
    }

    void displayDetails() override {
        cout << "\n--- Magazine ---\n";
        Item::displayDetails();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

int main() {
    vector<Item*> library;

    library.push_back(new Book(1, "C++ Basics", "Bjarne Stroustrup"));
    library.push_back(new Magazine(2, "Tech Monthly", 45));
    library.push_back(new Book(3, "Data Structures", "Mark Allen"));

    cout << "\n📚 Library Items:\n";
    for (auto item : library)
        item->displayDetails();

    cout << "\n--- Issuing Item 1 ---\n";
    library[0]->issueItem();

    cout << "\n--- Returning Item 1 (late by 3 days) ---\n";
    library[0]->returnItem(3);

    // Count available items (BONUS)
    int availableCount = 0;
    for (auto item : library)
        if (item->isAvailable())
            availableCount++;

    cout << "\nAvailable Items: " << availableCount << endl;

    // cleanup
    for (auto item : library)
        delete item;

    return 0;
}
