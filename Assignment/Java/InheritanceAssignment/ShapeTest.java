package fourh; 

// Base Parent Class
class Shape {
    public void printShape() {
        System.out.println("This is shape");
    }
}

// Child Class 1 (Inherits Shape)
class RectangleA extends Shape {
    public void printRectangleA() {
        System.out.println("This is rectangular shape");
    }
}

// Child Class 2 (Inherits Shape)
class Circle extends Shape {
    public void printCircle() {
        System.out.println("This is circular shape");
    }
}

// Subclass of Rectangle
class SquareA extends RectangleA {
   
    public SquareA() {
        super();
    }

    public void printSquare() {
        System.out.println("Square is a rectangle");
    }
}


public class ShapeTest {
    public static void main(String[] args) {
        // Creating object of Square class
        SquareA sq = new SquareA();

        // Calling methods
        sq.printShape();
        sq.printRectangleA();
    }
}
