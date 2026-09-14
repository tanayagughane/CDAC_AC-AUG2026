package com.first;

public class Complex {
	
	double real;
	double imag;
	
	public  Complex(double r , double iTemp) {
		real = r;
		imag = iTemp;
		
	}
	
	public static void add(Complex c1, Complex c2) {
		double resReal = c1.real + c2.real;
        double resImag = c1.imag + c2.imag;
        System.out.println("Sum: " + resReal + " + " + resImag + " iTemp");
	}
	
	public static void subtract(Complex c1, Complex c2) {
		double resReal = c1.real - c2.real;
        double resImag = c1.imag - c2.imag;
        System.out.println("Difference: " + resReal + " + " + resImag + " iTemp");
	}
	
	public static void multiply(Complex c1, Complex c2) {
		
		double resReal = (c1.real * c2.real) - (c1.imag * c2.imag);
		double resImag = (c1.real * c2.imag) + (c1.imag * c2.real); 
		System.out.println("Product: " + resReal + " + " + resImag + " iTemp");
	}

	public static void main(String[] args) {
		
		Complex num1 = new Complex(4.0, 5.0);
        Complex num2 = new Complex(2.0, 3.0);
        
        System.out.println("--- Results ---");
        
        add(num1, num2);
        subtract(num1, num2);
        multiply(num1, num2);
		
	}

}
