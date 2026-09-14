package com.first;

public class Triangle {
	
	double side1;
	double side2;
	double side3;
	
	public Triangle (double s1 ,double s2 , double s3 ) {
		side1 = s1;
		side2 = s2;
		side3 = s3;
	}
	
	//perimeter 
	public void Perimeter() {
		double perimeter = side1 + side2 + side3;
		System.out.println("Perimeter of the triangle: " + perimeter + " Units");
		
	}
	
	public void Area() {
		//semi= semiPerimeter
		double semi = (side1 + side2 + side3) / 2;
		
		double area = Math.sqrt(semi * (semi - side1) * (semi - side2) * (semi - side3));
		System.out.println("Area of the triangle: " + area + " Units");
		
	}

	public static void main(String[] args) {
		Triangle objTriangle = new Triangle(3, 4, 5);
		
		objTriangle.Perimeter();
		objTriangle.Area();

	}

}
