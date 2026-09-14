package fourh;

//Parent Class 
class ShapeRectangle {
 double length;
 double breadth;

 public ShapeRectangle(double len, double bre) {
     length = len;
     breadth = bre;
 }

 public void printArea() {
     double area = length * breadth;
     System.out.println("Area: " + area);
 }

 public void printPerimeter() {
     double perimeter = 2 * (length + breadth);
     System.out.println("Perimeter: " + perimeter);
 }
}

//Child Class
class Square extends ShapeRectangle {
 public Square(double side) {
     super(side, side); 
 }
}


public class Rectangle {
 public static void main(String[] args) {
     System.out.println("--- Rectangle Details ---");
     ShapeRectangle rect = new ShapeRectangle(5.0, 4.0);
     rect.printArea();
     rect.printPerimeter();

     System.out.println(); 

     System.out.println("--- Square Details ---");
     Square sq = new Square(4.0);
     sq.printArea();       
     sq.printPerimeter();  
 }
}

