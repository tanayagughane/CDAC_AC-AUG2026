package com.first;

class Student{
	String name;
	int roll_no;
	String phone_no;
	String address;
	
}
public class Main {

	public static void main(String[] args) {
		
		//part1:- 
		Student obj = new Student();
		obj.name = "John";
		obj.roll_no = 2;
		
		System.out.println("Part (1): ");
		System.out.println("Name: " + obj.name);
		System.out.println("Roll No.: " + obj.roll_no);
		System.out.println("===============================");
		System.out.println();
		
		
		// part2:- 
		
		//obj1 sam
		Student sam = new Student();
		sam.name = "Sam";
		sam.roll_no = 1;
		sam.phone_no = "1234567890";
		sam.address = "pune";
		
		//obj 2 john
		Student john = new Student();
		john.name = "John";
		john.roll_no = 2;
		john.phone_no = "9876543210";
		john.address = "Nagpur";
		
		
		//print obj sam
		System.out.println("Part (2): ");
		System.out.println("Details of " + sam.name + ":");
		System.out.println("Roll No.: " + sam.roll_no);
		System.out.println("Phone No: " + sam.phone_no);
		System.out.println("Address.: " + sam.address);
		System.out.println();
		
		//print obj john
		System.out.println("Details of  " + john.name + ":");
		System.out.println("Roll No: " + john.roll_no);
		System.out.println("Phone No: " + john.phone_no);
		System.out.println("Address: " + john.address);
		
			
		
	}

}
