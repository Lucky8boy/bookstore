![Bookshelf image](img/bookshelf.png)

# [Wiki](https://github.com/Lucky8boy/bookstore/wiki/Bookstore-Wiki)
  Full documentation for the program is now in the repo's wiki!

# My Bookstore
  Welcome to my bookstore! Of course it is not an official one. It is made in C++ and with a bit of help from Makefile. I wondered how does it feel to have a pseudo-database without using anything like SQL. Below are a lot of informations about the program and how to develop further if wanted. There is even a Wiki page about everything you may want to know. It works in both Linux and Windows [^1]

# How to compile
  Type in the terminal the following if it is the first time:
 ```sh
 make run
```

 If you modify something, I recommend you to do this:
 ```sh
 make clean; make run
```

# How does it work
  Well, to be fast and easy to use, each book will be represented as a .txt file. There is a "Catalog" containing all the books.
All the functions are well explained in the headers containing their name (look for *menu.h*, *book.h* and *catalog.h* from the src folder).
  Warning! There are some functions not used by me, but implemented because someone may need them. They have the text *(maybe someone will need it)*
somewhere in the comments. Have fun!

 # How to use the Makefile [^2]

   You need to type in terminal ```make rule_you_want``` in the same level of directory as the **Makefile** file. All *make* commands: [^3]
 
 |         Command         | Creates the executable | Cleans the objects | Cleans the log | Runs the program | Debug | Simple valgrind | Leak check | All valgrind info |
|:-----------------------:|:----------------------:|:------------------:|:--------------:|:----------------:|:-----:|:---------------:|:----------:|:-----------------:|
|        make (all)       |           yes          |          x         |        x       |         x        |   x   |        x        |      x     |         x         |
|        make clean       |            x           |         yes        |        x       |         x        |   x   |        x        |      x     |         x         |
|   make valgrind_clean   |            x           |          x         |       yes      |         x        |   x   |        x        |      x     |         x         |
|         make run        |           yes          |          x         |        x       |        yes       |   x   |        x        |      x     |         x         |
|        make debug       |           yes          |          x         |        x       |        yes       |   x   |        x        |      x     |         x         |
|      make valgrind      |           yes          |          x         |        x       |        yes       |   x   |       yes       |      x     |         x         |
| make valgrind_leakcheck |           yes          |          x         |        x       |        yes       |   x   |       yes       |     yes    |         x         |
|  make valgrind_extreme  |           yes          |          x         |        x       |        yes       |   x   |       yes       |     yes    |        yes        |

# Images of the menu

## Main menu
![Main menu](img/Main_menu.png)

## Add book menu
![Add book menu](img/Add_book_menu.png)

## Buy menu
![Buy menu](img/Buy_menu.png)

## Save Menu
![Save menu](img/Save_menu.png)

[^1]: For Windows you need something like GNU Make to run it. It won't run without it.
[^2]: I don't own anything related to the GNU Make. I am not getting any money from it, nor from the repo.
[^3]: I don't own anything related to the Valgrind. I am not getting any money from it, nor from the repo.
