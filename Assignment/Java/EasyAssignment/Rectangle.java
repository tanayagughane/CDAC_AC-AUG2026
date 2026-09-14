package com.first;

public class Rectangle {
	double length;
	double breadth;
	
	 public Rectangle(double l, double b) {
	        length = l;
	        breadth = b;
	    }
	 
	 public double area() {
	        return length * breadth;
	    }
	 
	public static void main(String[] args) {
        //1st rectangle:
		Rectangle rect1 = new Rectangle(4, 5);
        ////2st rectangle:
        Rectangle rect2 = new Rectangle(5, 8);

        
        System.out.println("Area of first rectangle (4, 5): " + rect1.area());
        System.out.println("Area of second rectangle (5, 8): " + rect2.area());
	}

}
