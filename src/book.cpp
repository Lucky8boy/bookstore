#include "book.h"
#include <fstream>
#include <unistd.h>

    Book::Book(int year, int count, std::string name, std::string author, std::string description) {
        this->year = year;
        this->count = count;
        this->name = name;
        this->author = author;
        this->description = description;
    }

    Book::Book(int year, int count, std::string name, std::string author) {
        this->year = year;
        this->count = count;
        this->name = name;
        this->author = author;
        this->description = "-";
    }

    Book::Book(int year, int count, std::string name) {
        this->year = year;
        this->count = count;
        this->name = name;
        this->author = "-";
        this->description = "-";
    }

    void Book::displayBook() {
        std::cout << "========================================================\n"
                  << "Year: " << year <<".\n"
                  << "The bookstore has " << count << " copies of this book.\n"
                  << "Book name: " << name << ".\n"
                  << "Author: " << author << ".\n"
                  << "Description: " << description << ".\n"
                  << "========================================================\n";
    }

    void Book::addToCatalog() {
        std::ofstream fout("books/catalog.txt", std::ios::app); // appending the .txt file cuz I don't want to delete it
        if(!fout) {
            system("mkdir books; cd books; touch catalog.txt; cd -");
            std::cout << "Added catalog.txt because someone messed up wtf.\n";
        }
        fout << this->id << " " << this->count << " " + this->name + "\n"; // adding to the catalog
        fout.close();
    }

    void Book::setId(int id) {
        this->id = id;
    }

    std::string Book::getName() {
        return this->name;
    }

    int Book::getId() {
        return this->id;
    }

    int Book::getCount() {
        return this->count;
    }

    int Book::createFile() {
        std::string path = "books/" + this->name + ".txt";

        if(this->name == "catalog" || this->name == "prices") { // these names are used already
            std::cout << "Choose a different name for the book!\n";
            return -1;
        }

        if(access(path.c_str(), F_OK) != -1) { // check if filename is already used
            std::cout << "The book already exists! You don't need to add it again!\n";
            return -2;
        }

        std::ofstream fout(path.c_str()); // make the new .txt file

        if(!fout) { // file could't be created / opened / etc
            fprintf(stderr, "Error: File couldn't be created. Please try again!\n");
            return -3;
        }

        fout << "Id: " << this->id << "\nBook name: " + this->name + "\nAuthor: " + this->author
             << "\nYear: " << this->year << "\nCount: " << this->count << "\nDescription: " + this->description + "\n";

        /*
            Example:
            __________________________________________
            | Id: 1                                  |
            | Book name: Some cool book              |
            | Author: Lucky8boy                      |
            | Year: 2003                             |
            | Count: 3                               |
            | Description: A very simple description.|
            |________________________________________|
        */

        fout.close();
        return 1;
    }

    int Book::destroyFile() {
        std::string path = "books/" + this->name + ".txt";

        if(this->name == "catalog" || this->name == "prices") {
            std::cout << "Choose a different name for the book!\n";
            return -1;
        }

        if(access(path.c_str(), F_OK) == -1) {
            std::cout << "The book doesn't even exist lol!\n";
            return -2;
        }

        std::string command = "cd books; rm " + this->name + ".txt; cd -";
        system(command.c_str());

        return 1;
    }

    // Book::~Book() {
    //     static int destroyCounter = 0;
    //     if(!destroyCounter++) std::cout << "The book \"" << this->name << "\" was destroyed by the admin.\n<Lucky8boy>: f\n";
    //     else std::cout << "The book \"" << this->name << "\" was destroyed by the admin.\n<Lucky8boy>: f x" << destroyCounter <<'\n';
    // }