package third;

public class ArraySum {

    public static void main(String[] args) {
        
        
        int size = 5; 
        int[] numbersArray = new int[size];
        
        
        numbersArray[0] = 45;
        numbersArray[1] = 12;
        numbersArray[2] = 89;
        numbersArray[3] = 7;
        numbersArray[4] = 23;

        // 1. total sum
        int totalSum = 0;

        // 2. Loop: array and add each element to totalSum
        for (int i = 0; i < size; i++) {
            totalSum = totalSum + numbersArray[i]; 
        }

        
        System.out.println("The sum of all array values is: " + totalSum);
    }
}
