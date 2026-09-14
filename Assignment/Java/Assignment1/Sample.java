package com.practice;

public class Sample {
    public static void main(String[] args) {
        Days objDate = new Days();
        
        System.out.println("Enter the day"); 
        int day = ConsoleInput.getInt(); // Fixed missing '='
        
        System.out.println("Enter the month"); 
        int month = ConsoleInput.getInt();
        System.out.println("Enter the year"); 
        int year= ConsoleInput.getInt();
        
        objDate.setDate(day, month, year);
        
        System.out.println(objDate.getDay() + "/" + objDate.getMonth() + "/" + objDate.getYear());
        
        System.out.print("Current Date:");
        System.out.println(objDate.getDay() + "/" + objDate.getMonth() + "/" + objDate.getYear());
        
        System.out.println("Enter days to add:");
        int daysToAdd = ConsoleInput.getInt();
        
        objDate.addDays(daysToAdd);
        
        System.out.print("New Date: ");
        System.out.println(objDate.getDay() + "/" + objDate.getMonth() + "/" + objDate.getYear());
    }
}
