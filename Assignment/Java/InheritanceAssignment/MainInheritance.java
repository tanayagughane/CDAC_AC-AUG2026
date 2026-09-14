package fourh;


//1. Define the Parent Class
class ParentClass {
 public void printParentMessage() {
     System.out.println("This is parent class");
 }
}

//2. Define the Child Class (Subclass inheriting from ParentClass)
class ChildClass extends ParentClass {
 public void printChildMessage() {
     System.out.println("This is child class");
 }
}

public class MainInheritance {

 public static void main(String[] args) {
     
     // Creating an object of the Parent Class
     ParentClass parentObj = new ParentClass();
     
     // Creating an object of the Child Class
     ChildClass childObj = new ChildClass();

     System.out.println("--- Execution ---");

     // 1 - Call method of parent class by object of parent class
     parentObj.printParentMessage();

     // 2 - Call method of child class by object of child class
     childObj.printChildMessage();

     // 3 - Call method of parent class by object of child class
     childObj.printParentMessage(); 
 }
}
