#include "menu.h"
#include "book.h"
#include "catalog.h"
#include <iostream>
int main() {

    Menu menu;
    // menu.welcome();
    // menu.getOptions();

    Book book1(2000, 2, "Name", "Author", "Lorem ipsum"), book2(1900, 1, "Name2", "Author2"), book3(1945, 15, "Name3");
    // book1.displayBook();
    // book2.displayBook();
    // book3.displayBook();

    // book1.addToCatalog();
    // book1.addToCatalog();
    // book1.addToCatalog();

    Catalog catalog;
    // catalog.showCatalog();
    // catalog.searchBook("Very cool name");
    catalog.updateCatalog();

    return 0;
}