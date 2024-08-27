#include <iostream>
#include <string>

using namespace std;

// Author class
class Author {
public:
    string name;
    string degree;

    Author(string aName, string aDegree) {
        name = aName;
        degree = aDegree;
    }
};

// Publication class
class Publication {
public:
    string name;
    string location;

    Publication(string pName, string pLocation) {
        name = pName;
        location = pLocation;
    }
};

// Book class
class Book {
public:
    string title;
    int pages;
    double price;
    Author author;
    Publication publication;

    Book(string bTitle, int bPages, double bPrice, Author bAuthor, Publication bPublication)
        : author(bAuthor), publication(bPublication) {
        title = bTitle;
        pages = bPages;
        price = bPrice;
    }

    void displayDetails() {
        cout << "Book Title: " << title << endl;
        cout << "Number of Pages: " << pages << endl;
        cout << "Price: $" << price << endl;
        cout << "Author Name: " << author.name << endl;
        cout << "Author Degree: " << author.degree << endl;
        cout << "Publication Name: " << publication.name << endl;
        cout << "Publication Location: " << publication.location << endl;
    }
};

int main() {
    string authorName, authorDegree, pubName, pubLocation, bookTitle;
    int pages;
    double price;

    
    cout << "Enter Author Name: ";
    getline(cin, authorName);
    cout << "Enter Author Degree: ";
    getline(cin, authorDegree);
    cout << "Enter Publication Name: ";
    getline(cin, pubName);
    cout << "Enter Publication Location: ";
    getline(cin, pubLocation);
    cout << "Enter Book Title: ";
    getline(cin, bookTitle);
    cout << "Enter Number of Pages: ";
    cin >> pages;
    cout << "Enter Price of the Book: ";
    cin >> price;

    // Create objects
    Author author(authorName, authorDegree);
    Publication publication(pubName, pubLocation);
    Book book(bookTitle, pages, price, author, publication);

    // Display details
    cout << "\nBook Details:\n";
    book.displayDetails();

    return 0;
}

