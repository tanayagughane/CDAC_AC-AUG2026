package fourh;

//Parent Class
class Member {
 // Data members
 private String name;
 private int age;
 private String phoneNumber;
 private String address;
 private double salary;

 //  Setters
 public void setName(String newName) { name = newName; }
 public void setAge(int newAge) { age = newAge; }
 public void setPhoneNumber(String newPhone) { phoneNumber = newPhone; }
 public void setAddress(String newAddress) { address = newAddress; }
 public void setSalary(double newSalary) { salary = newSalary; }

 // Getters
 public String getName() { 
	 return name;
	 }
 public int getAge() {
	 return age; 
	 }
 public String getPhoneNumber() {
	 return phoneNumber;
	 }
 public String getAddress() {
	 return address; 
	 }
 public double getSalary() {
	 return salary; 
	 }

 // Method to print salary
 public void printSalary() {
     System.out.println("Salary: " + salary);
 }
}

//Child Class inherited from Member
class PrimeMembers extends Member {
 // Additional data members
 private int joiningYear;
 private double joiningFees;
 private boolean isActive;

 // Setters for PrimeMembers 
 public void setJoiningYear(int newYear) { joiningYear = newYear; }
 public void setJoiningFees(double newFees) { joiningFees = newFees; }
 public void setIsActive(boolean status) { isActive = status; }

 // Getters for PrimeMembers
 public int getJoiningYear() { return joiningYear; }
 public double getJoiningFees() { return joiningFees; }
 public boolean getIsActive() { return isActive; }

 // Display method to show all fields
 public void display() {
     System.out.println("Name: " + getName());
     System.out.println("Age: " + getAge());
     System.out.println("Phone Number: " + getPhoneNumber());
     System.out.println("Address: " + getAddress());
     printSalary(); // Calling parent method
     System.out.println("Joining Year: " + joiningYear);
     System.out.println("Joining Fees: " + joiningFees);
     System.out.println("Is Active: " + isActive);
 }
}

//Main Class to run the program
public class Main {
 public static void main(String[] args) {
     // Creating an object of PrimeMembers
     PrimeMembers pm = new PrimeMembers();

     // Assigning values
     pm.setName("Rahul");
     pm.setAge(22);
     pm.setPhoneNumber("9876543210");
     pm.setAddress("Mumbai, India");
     pm.setSalary(45000.0);
     pm.setJoiningYear(2024);
     pm.setJoiningFees(1500.0);
     pm.setIsActive(true);

     // Displaying all details using the display method
     pm.display();
 }
}
