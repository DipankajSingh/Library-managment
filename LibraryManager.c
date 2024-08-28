#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define LIBRARY_CAPACITY 100

typedef struct
{
    char name[MAX_SIZE];
    int book_count;
    int price;
    int available;
    char author[MAX_SIZE];
} Book;

Book books[LIBRARY_CAPACITY];

int next_book_index = 0; // Initialize to the first available index

void add_book(Book book)
{
    if (next_book_index < LIBRARY_CAPACITY)
    {

        books[next_book_index].book_count = 1; // Assume 1 copy initially
        strcpy(books[next_book_index].name, book.name);
        strcpy(books[next_book_index].author, book.author);
        books[next_book_index].price = book.price;
        books[next_book_index].available = book.available;
        next_book_index++;

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
    for (int i = 0; i < next_book_index; i++)
    {
        if (strcmp(books[i].name, name) == 0)
        {
            printf("The query string true\n\n");

            return i;
        }
    }
    printf("The query string false\n\n");
    return -1;
}

int main()
{
    int option;
    Book book;

    int true = 1;
    int false = 0;

    int library_open = true;

    while (library_open == true)
    {
        printf("Choose an option:\n");
        printf("1. Add a book\n2. Remove a book\n3. Update a book\n4. Display all books\n5. Exit\n\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Name: ");
            scanf("%s", book.name);
            printf("Author: ");
            scanf("%s", book.author);
            printf("Price: ");
            scanf("%d", &book.price);
            printf("Availability: ");
            scanf("%d", &book.available);
            add_book(book);
            break;
        case 2:
            if (next_book_index == 0)
            {
                printf("Nothing in Library!\n\n");
                break;
            };
            printf("Enter the name of the book to remove: ");
            char RemoveName[MAX_SIZE];
            scanf("%s", RemoveName);
            int index = find_book_index(RemoveName);
            printf("The book Position is: %d\n\n", index);
            if (index != -1)
            {
                for (int i = index; i < next_book_index - 1; i++)
                {
                    books[i] = books[i + 1];
                };
                printf("book removed!\n\n");
            };
            break;
        case 3:
            // update a book
            break;
        case 4:
            if (next_book_index == 0)
            {
                printf("Nothing in Library!\n\n");
                break;
            };

            for (int i = 0; i < next_book_index; i++)
            {
                printf("Book Name: %s\nBook Author: %s\nBook Price: %d$\nBook Available: %dpic\n\n", books[i].name, books[i].author, books[i].price, books[i].available);
            };
            break;
        case 5:
            library_open = false;
            break;
        default:
            printf("Invalid option\n\n");
            break;
        }
    }
    return 0;
};