package com.first;

public class Employee {
	
	 String name;
	 int yearOfJoining;
	 String address;
	 
	 public Employee(String n, int y, String a) {
	        name = n;
	        yearOfJoining = y;
	        address = a;
	    }

	    // Method to print data
	    public void detail() {
	        // \t is a tab space 
	        System.out.println(name + "\t\t" + yearOfJoining + "\t\t\t" + address);
	    }

	public static void main(String[] args) {
		
		 // Creating three employee objects 
        Employee emp1 = new Employee("Robert", 1994, "64C- WallsStreat");
        Employee emp2 = new Employee("Sam", 2000, "68D- WallsStreat");
        Employee emp3 = new Employee("John", 1999, "26B- WallsStreat");

        // Printing the table headers
        System.out.println("Name\t\tYear of joining\t\tAddress");
        System.out.println("--------------------------------------------------");

        // Calling the method to print each employee's data
        emp1.detail();
        emp2.detail();
        emp3.detail();
	}

}
