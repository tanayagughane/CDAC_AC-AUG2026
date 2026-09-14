package third;

public class ArrayMaxMin {

    public static void main(String[] args) {
        
        int size = 5; 
        int[] numbersArray = new int[size];
        
        
        numbersArray[0] = 45;
        numbersArray[1] = 12;
        numbersArray[2] = 89;
        numbersArray[3] = 7;
        numbersArray[4] = 23;

        // 1. first is both the max and min initially
        int max = numbersArray[0];
        int min = numbersArray[0];

        // 2. Loop through the array to check all other numbers
        for (int i = 1; i < size; i++) {
            
            // If we find a number bigger than our current max, update max
            if (numbersArray[i] > max) {
                max = numbersArray[i];
            }
            
            // If we find a number smaller than our current min, update min
            if (numbersArray[i] < min) {
                min = numbersArray[i];
            }
        }

        // 3. Print the final results
        System.out.println("Maximum value in the array is: " + max);
        System.out.println("Minimum value in the array is: " + min);
    }
}
