#include <stdio.h>

struct Book__ {
    char title[100];
    int page;
    int readPage;
};

typedef struct Book__ Book;

int main(){
    Book book;
    book.title = "Introduction to C/C++";
    book.page = 700;
    book.readPage = 0;
}