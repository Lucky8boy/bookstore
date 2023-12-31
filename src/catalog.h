#ifndef CATALOG_H
#define CATALOG_H

    #include <list>
    #include <unordered_map>
    #include "book.h"

    #define MAX_DIGITS 3 // how many digits an Id can have (in this case -1 < Id < 1000)

    typedef struct Trio {
        int id, count;
        std::string name;
    } Trio;

    /*
        The "catalog" is made of a list and an unordered map. The list is used
        to containg everything, and the map is used to find easier some info.
        Warnings:
        1. The price is not on the catalog! Maybe the owner of the book-
        store wants to change the price of a book sometimes. The price is in
        the 'books/prices.txt' file.
        2. The year/author/description will not be in the catalog. It will be
        another .txt file for each book.
    */

    class Catalog {
        private:
            std::unordered_map<std::string, int> mapData;
            std::unordered_map<int, double> prices;
            std::list<Trio> data;
            int numOfBooks;

        public:
            Catalog();                                  // it gets from the 'books/catalog.txt' all the data the bookstore has
            void showCatalog();                         // writes all the catalog to the terminal
            void updateCatalog();                       // it rewrites the catalog (maybe major changes)
            void addBook(Book book);                    // adds a book to the catalog
            bool searchBook(int id);                    // it returns the id of the search book or -1 if not found
            void removeBook(Book book);                 // removes a book from the catalog
            int searchBook(std::string name);           // it returns the id of the search book or -1 if not found

            int getNumOfBooks();
            void buyBook(int id);
            void buyBook(std::string name);
    };

#endif