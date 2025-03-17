package oop.ex;

public class RectangleProcedureMain {
    public static void main(String[] args) {

        Ractangle ractangle = new Ractangle();

        int area = ractangle.calculateArea();
        System.out.println("면적 : " + area);

        int perimeter = ractangle.calculatePerimeter();
        System.out.println("둘레 : " + perimeter);

        boolean square = ractangle.square();
        System.out.println("정사각형 여부 : " + square);

    }


}