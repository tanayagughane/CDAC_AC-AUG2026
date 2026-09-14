package third;

public class ArrayReverse {

    public static void main(String[] args) {
        
        int size = 5; 
        int[] numbersArray = new int[size];
        
        
        numbersArray[0] = 45;
        numbersArray[1] = 12;
        numbersArray[2] = 89;
        numbersArray[3] = 7;
        numbersArray[4] = 23;

        // Print original array
        System.out.println("Original Array:");
        for (int i = 0; i < size; i++) {
            System.out.print(numbersArray[i] + " ");
        }
        System.out.println(); 

        // 1. Setup two pointers: one start, one at the end
        int start = 0;
        int end = size - 1;

        // 2. Loop until the two pointers meet in the middle
        while (start < end) {
            // Swap the elements at 'start' and 'end' positions
            int temp = numbersArray[start];
            numbersArray[start] = numbersArray[end];
            numbersArray[end] = temp;

            // Move the pointers toward the center
            start++;
            end--;
        }

        // 3. Print the reversed array
        System.out.println("\nReversed Array:");
        for (int i = 0; i < size; i++) {
            System.out.print(numbersArray[i] + " ");
        }
    }
}
