#include <stdio.h>
#include <string.h>

struct Book__ {
    char title[100];
    int page;
    int readPage;
};

typedef struct Book__ Book;
typedef Book* BookPtr;
    
void printBook(Book book){
    printf("Title: %s\n", book.title);
    printf("Read: %d/%d\n", book.readPage, book.page);

}

void readBook(Book* book, int page){
    book->readPage += page;
}

// int main(){
//     Book book;
//     strcpy(book.title, "Introduction to C/C++");
//     book.page = 780;
//     book.readPage = 0;

//     readBook(&book, 10);

//     printBook(book);
// }

//level 3;

void findTopPage(Book books[], int size, Book** topPage){
    *topPage = &books[0];
    for(int i = 1; i < 3; ++i){
        if(books[i].page > (*topPage)->page){
            *topPage = &books[i];
        }
    }
}

int main(){
    Book books[10], *topPage;

    strcpy(books[0].title, "The 1st Book of Array");
    books[0].page = 300;
    strcpy(books[1].title, "The 2nd Book of Array");
    books[1].page = 330;
    strcpy(books[2].title, "The 3rd Book of Array");
    books[2].page = 250;
    for(int i = 0; i < 3; ++i){
        books[i].readPage = 0;
    }

    findTopPage(books, 3, &topPage);
    printBook(*topPage);
}