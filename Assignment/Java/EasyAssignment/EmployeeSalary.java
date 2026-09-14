package com.first;

public class EmployeeSalary {
    
    double salary;
    int hoursPerDay;

    // 1. getInfo Method: 
    public void getInfo(double sal, int hours) {
        salary = sal;
        hoursPerDay = hours;
    }

    // 2. addSal Method: 
    public void addSal() {
        if (salary < 500) {
            salary = salary + 10;
        }
    }

    //add work
    public void addWork() {
        if (hoursPerDay > 6) {
            salary = salary + 5;
        }
    }

    
    public void finalSalary() {
        System.out.println("Final Salary: $" + salary);
    }

    public static void main(String[] args) {
        
        EmployeeSalary emp = new EmployeeSalary();

      
        emp.getInfo(450.0, 8);
  
        emp.addSal();
        emp.addWork();

        emp.finalSalary();
    }
}

