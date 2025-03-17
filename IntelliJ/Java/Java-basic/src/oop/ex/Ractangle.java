package oop.ex;

public class Ractangle {
    int width = 5;
    int hight = 8;

    int calculateArea() {
        int Area = width * hight;
        return  Area;
    }

    int calculatePerimeter(){
        int Perimeter = (width + hight) * 2;
        return Perimeter;
    }

    boolean square(){
        boolean isSquare = false;
        if(width == hight){
            isSquare = true;
            return isSquare;
        }
        else return isSquare;
    }
}
