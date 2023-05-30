// Homework7.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include<iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Book.h"
using namespace std;

char tolower(char letter) {
    if (letter >= 'A' && letter <= 'Z') {
        letter = letter + 32;
    }
    return letter;
}
char toupper(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        letter = letter - 32;
    }
    return letter;
}
string tolowerSTR(string str) {
    string returnStr = "";
    for (int i = 0; i < str.length(); i++) {
        returnStr += tolower(str[i]);
    }
    return returnStr;
}

void createVec(vector<Book>& V1) { // +
    string author, title;
    int publicationyear;

    Book newBook1("The Great Gatsby", "F Scott Fitzgerald", 1925);
    V1.push_back(newBook1);
    
    Book newBook2("Moby Dick", "Herman Melville", 1851);
    V1.push_back(newBook2);

    Book newBook3("To Kill a Mockingbird", "Harper Lee", 1960);
    V1.push_back(newBook3);

    Book newBook4("Pride and Prejudice", "Jane Austen", 1813);
    V1.push_back(newBook4);

    Book newBook5("Burmese Days", "George Orwell", 1934);
    V1.push_back(newBook5);

    Book newBook6("Brave New World", "Aldous Huxley", 1932);
    V1.push_back(newBook6);

    Book newBook7("Animal Farm", "George Orwell", 1945);
    V1.push_back(newBook7); 
}

void sortingbooks(vector<Book>& V1) {
    for (int i = 1; i < V1.size(); i++)
    {
        Book temp = V1[i];
        int j = i - 1;
        string iauthor = tolowerSTR(V1[i].getAuthorLastName());
        while (j >= 0 && tolowerSTR(V1[j].getAuthorLastName()) > iauthor) {
            V1[j + 1] = V1[j];
            j--;
        }
        while (j >= 0 && tolowerSTR(V1[j].getAuthorLastName()) == iauthor && V1[j].getAuthor() == V1[i].getAuthor() && V1[j].getTitle() > V1[i].getTitle()) {
            V1[j + 1] = V1[j];
            j--;
        }
        V1[j + 1] = temp;
    }
}

void addition(vector<Book>& V1) { // +
    string NBtitle, NBauthor; //NB = newbook
    int NBpublicationyear;
    cout << "Enter the new book details:" << endl;
    cout << "Enter book's title: ";
    getline(cin >> ws, NBtitle);

    cout << "Enter book's author: ";
    getline(cin >> ws, NBauthor);

    cout << "Enter book's publication year: ";
    cin >> NBpublicationyear;

    Book newBook(NBtitle, NBauthor, NBpublicationyear);
    V1.push_back(newBook);
}

void searchingauthor(vector<Book>& V1) { //Binary Search Algorithm // V1[middle].author[V1[middle].author.rfind(" ") + 1]   6. Orwell 7. Orwell high - low >0, high - low =0 V1[high]
    string authorname;

    int middle, low = 0;
    int high = V1.size() - 1;

    cout << "Enter the author of the book you want to search for: ";
    getline(cin >> ws, authorname);

    string authorsurname = tolowerSTR(authorname.substr(authorname.rfind(" ") + 1));
    bool x = false;
    while (low <= high) {
        middle = low + (high - low) / 2;
        string lastname = tolowerSTR(V1[middle].getAuthorLastName());
        if (lastname > authorsurname) {
            high = middle - 1;
        }
        else if (lastname < authorsurname) {
            low = middle + 1;
        }
        else {
            cout << "Books by " << authorname.substr(authorname.rfind(" ") + 1, authorname.size()) << ":" << endl; // Boosk by Orwell
            for (int i = low; i <= high; i++) {
                string controlsurname = tolowerSTR(V1[i].getAuthorLastName());
                if (controlsurname == authorsurname)
                {
                    cout << "Title: " << V1[i].getTitle() << ", " << "Publication Year: " << V1[i].getPublicationYear() << ", "
                        << "Position: " << i + 1 << endl;
                    x = true;
                }
            }
            break;
        }
    }
    if (x == false) {
        cout << "No books were found." << endl;
    }
}

void searchingtitle(vector<Book>& V1) { // Linear Search +
    string titlebook, lowertitlebook;
    int control = 0;
    cout << "Enter the title of the book you want to search for: ";
    getline(cin >> ws, titlebook);
    lowertitlebook = tolowerSTR(titlebook);
    for (int j = 0; j < V1.size(); j++) {
        if (tolowerSTR(V1[j].getTitle()) == lowertitlebook) {
            cout << "Books matching the title " << "\"" << titlebook << "\":" << endl;
            cout << "Title: " << V1[j].getTitle() << ", Author: " << V1[j].getAuthor() << ", Publication Year: "
                << V1[j].getPublicationYear() << ", Position: " << j + 1 << endl;
            control = 1;
            break;

        }
    }
    if (control == 0) {
        cout << "Books matching the title " << "\"" << titlebook << "\":" << endl;
        cout << "No books were found." << endl;
    }
    control = 0;
}

void displaybooks(vector<Book> const& V1) { // +
    cout << "Sorted books by author's last name:" << endl;
    for (int i = 0; i < V1.size(); i++) {
        cout << i + 1 <<". ";
        V1[i].display();
    }
}
int main()
{
    vector<Book> book;
    createVec(book); // +
    int choice;
    do {
        cout << "Library System Menu:\n1. Add books\n2. Search for an author\n3. Search for by book title\n4. Display books\n5. Quit\nEnter your choice: ";
        cin >> choice;
        sortingbooks(book);
        switch (choice)
        {
        case 1:
            addition(book); // +
            sortingbooks(book); //+
            break;
        case 2:
            searchingauthor(book);
            break;
        case 3:
            searchingtitle(book); // +
            break;
        case 4:
            displaybooks(book); // +
            cout << endl;
            break;
        default:
            if (choice != 5) {
                cout << "Invalid choice, please try again." << endl;
                break;
            }
        }
    } while (choice != 5);
    cout << "Goodbye!";

}

