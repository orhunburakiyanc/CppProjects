#include <vector>
#include <iostream>
#include <string>
using namespace std;


struct Books {
    string title;
    string author;
    int publicationyear;
};

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

vector<Books> creatingVector(vector<Books>& V1) { 
    V1[0].title = "The Great Gatsby";
    V1[0].author = "F Scott Fitzgerald";
    V1[0].publicationyear = 1925;

    V1[1].title = "Moby Dick";
    V1[1].author = "Herman Melville";
    V1[1].publicationyear = 1851;

    V1[2].title = "To Kill a Mockingbird";
    V1[2].author = "Harper Lee";
    V1[2].publicationyear = 1960;

    V1[3].title = "Pride and Prejudice";
    V1[3].author = "Jane Austen";
    V1[3].publicationyear = 1813;

    V1[4].title = "Burmese Days";
    V1[4].author = "George Orwell";
    V1[4].publicationyear = 1934;

    V1[5].title = "Brave New World";
    V1[5].author = "Aldous Huxley";
    V1[5].publicationyear = 1932;

    V1[6].title = "Animal Farm";
    V1[6].author = "George Orwell";
    V1[6].publicationyear = 1945;
    return V1;
} 

vector<Books> sortingbooks(vector<Books> V1) { //Insortion Sort Algorithm 
    for (int i = 1; i < V1.size() ;i++)
    {
        Books temp = V1[i];
        int j = i - 1;
        string iauthor = tolowerSTR(V1[i].author.substr(V1[i].author.rfind(" ") + 1));
        while (j >= 0 && tolowerSTR(V1[j].author.substr(V1[j].author.rfind(" ") + 1)) > iauthor) {
            V1[j + 1] = V1[j];
            j--;
        }
        while (j >= 0 && tolowerSTR(V1[j].author.substr(V1[j].author.rfind(" ") + 1)) == iauthor && V1[j].author == V1[i].author && V1[j].title > V1[i].title) {
            V1[j + 1] = V1[j];
            j--;
        }
        V1[j + 1] = temp;
    }
    return V1;
}

void addition(vector<Books>& V1){ // +
    string NBtitle, NBauthor; //NB = newbook
    int NBpublicationyear;
    cout << "Enter the new book details:" << endl;
    cout << "Enter book's title: ";
    getline(cin >> ws, NBtitle);

    cout << "Enter book's author: ";
    getline(cin >> ws, NBauthor);

    cout << "Enter book's publication year: ";
    cin >> NBpublicationyear;
    V1.push_back({ NBtitle, NBauthor, NBpublicationyear});
}

void searchingauthor(vector<Books>& V1) { //Binary Search Algorithm // V1[middle].author[V1[middle].author.rfind(" ") + 1]   6. Orwell 7. Orwell high - low >0, high - low =0 V1[high]
    string authorname;

    int middle,low = 0;
    int high = V1.size() - 1;

    cout << "Enter the author of the book you want to search for: ";
    getline(cin >> ws, authorname);

    string authorsurname = tolowerSTR(authorname.substr(authorname.rfind(" ") + 1));
    bool x = false;
    while (low <= high) {
        middle = low + (high - low) / 2;
        string lastname = tolowerSTR(V1[middle].author.substr(V1[middle].author.rfind(" ") + 1));
        if (lastname > authorsurname) {
            high = middle -1 ;
        }
        else if (lastname < authorsurname) {
            low = middle +1;
        }
        else {
            cout << "Books by " << authorname.substr(authorname.rfind(" ") + 1, authorname.size()) << ":" << endl; // Boosk by Orwell
            for (int i = low; i <= high; i++) {
                string controlsurname = tolowerSTR(V1[i].author.substr(V1[i].author.rfind(" ") + 1));
                if ( controlsurname == authorsurname)
                {                  
                    cout << "Title: " << V1[i].title << ", " << "Publication Year: " << V1[i].publicationyear << ", "
                        << "Position: " << i+1 << endl;
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


void searchingtitle(vector<Books>& V1) { // Linear Search +
    string titlebook,lowertitlebook;
    int control = 0;
    cout << "Enter the title of the book you want to search for: ";
    getline(cin >> ws, titlebook);
    lowertitlebook = tolowerSTR(titlebook);
    for (int j = 0; j < V1.size(); j++) {
        if (tolowerSTR(V1[j].title) == lowertitlebook) {
            cout << "Books matching the title " << "\"" << titlebook << "\":" << endl;
            cout << "Title: " << V1[j].title << ", Author: " << V1[j].author << ", Publication Year: "
                << V1[j].publicationyear << ", Position: " << j+1 << endl;
            control = 1;
            break;
           
        }
    }
    if (control == 0) {
        cout << "Books matching the title " << "\"" << titlebook << "\":" << endl;
        cout << "No books were fond." << endl;
    }
    control = 0;
}

void displaybooks(vector<Books> const& V1) { // +
    cout << "Sorted books by author's last name:" << endl;
    for (int i = 0; i < V1.size(); i++) {
        cout << i + 1 << ". " << V1[i].title << ", " <<
                            V1[i].author << ", " <<
                            V1[i].publicationyear << endl;
    }
}
int main()
{
    vector<Books> book(7);
    creatingVector(book); // +
    int choice;
    do {
        cout << "Library System Menu:\n1. Add books\n2. Search for an author\n3. Search for by book title\n4. Display books\n5. Quit\nEnter your choice: ";
        cin >> choice;
        book = sortingbooks(book);
        switch (choice)
        {
        case 1:                     
            addition(book); // +
            book = sortingbooks(book); //+
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
