#include <stdio.h>

struct Book
{
    char title[100];
    int  isbn;
    float price;
};

void inputBook(struct Book *b){
    scanf(" %s ", b->title);
    scanf("%d", &b->isbn);
    scanf("%f", &b->price);
    getchar();
}

void displayBook(struct Book *b){
    puts(b->title);
    printf("%d\n",b->isbn);
    printf("%f\n",b->price);
}

int main(){

struct Book books[50];
struct Book *bs = books;
float total=0;

for(int i=0; i<2; i++)
{
    inputBook(bs);
    total += books[i].price;
    bs++;
}
bs = books;
for (int i = 0; i < 2; i++)
{
    displayBook(bs);
    bs++;
}



    return 0;
}