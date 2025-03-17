package Construct;

public class Book {
    String name;
    String author;
    int page;

    Book(String name, String author, int page){
        this.name = name;
        this.author = author;
        this.page = page;
    }

    void DisplayBook(){
            System.out.println("제목 : " + this.name + " 저자 : " + this.author + " 페이지 : " + this.page);
        }
    }

