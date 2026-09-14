package third;

public class ArrayAverage {

    public static void main(String[] args) {
        
        int size = 5; 
        int[] numbersArray = new int[size];
        
        
        numbersArray[0] = 45;
        numbersArray[1] = 12;
        numbersArray[2] = 89;
        numbersArray[3] = 7;
        numbersArray[4] = 23;

        // 1.total sum
        int totalSum = 0;

        // 2. Loop: calculate the total sum
        for (int i = 0; i < size; i++) {
            totalSum = totalSum + numbersArray[i]; 
        }

        // 3. Calculate the average
        double average = (double) totalSum / size;

        
        System.out.println("The average value of array elements is: " + average);
    }
}
