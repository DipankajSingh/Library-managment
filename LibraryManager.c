#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Default size of arrays
#define LIBRARY_CAPACITY 100

typedef struct
{
    char name[MAX_SIZE];
    int price;
    int available;
    char author[MAX_SIZE];
} Book;

void printArray(Book b[MAX_SIZE])
{
    printf("hi from args");
};

Book books[LIBRARY_CAPACITY];

int last_book_index = 0; // automatically initalized to 0 at the start of the program

void add_book(Book book)
{
    if (last_book_index < LIBRARY_CAPACITY)
    {
        strcpy(books[last_book_index].name, book.name);
        strcpy(books[last_book_index].author, book.author);
        books[last_book_index].price = book.price;
        books[last_book_index].available = book.available;
        last_book_index++;

        printf("Book added successfully!\n\n");
    }
    else
    {
        printf("Library is full!\n\n");
    }
}

int find_book_index(char name[MAX_SIZE])
{
    printf("The query string is: %s\n\n", name);

    for (int i = 0; i <= last_book_index; i++)
    {
        if (strcmp(books[i].name, name) == 0)
        {
            printf("The query string is true\n\n");
            return i;
        }
    }

    printf("The query string is false\n\n");
    return -1;
}

Book newBook(char *name, char *author, int price, int available)
{
    Book b;
    strcpy(b.author, author);
    b.available = available;
    strcpy(b.name, name);
    b.price = price;
    return b;
}

int main()
{
    int true = 1;
    int false = 0;
    int option;
    Book book[MAX_SIZE];

    book[0] = newBook("new try", "myself", 998, 3);
    book[1] = newBook("new try 1", "myself111", 899, 3);
    book[2] = newBook("try2", "myself2", 700, 3);

    return 0;
};