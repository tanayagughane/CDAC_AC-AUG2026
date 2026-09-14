package third;

public class ArrayDuplicates {

    public static void main(String[] args) {
        
        int size = 5; 
        int[] numbersArray = new int[size];
        
        // Assigning values to the array (added a duplicate '12' for testing)
        numbersArray[0] = 45;
        numbersArray[1] = 12; // Duplicate element
        numbersArray[2] = 89;
        numbersArray[3] = 12; // Duplicate element
        numbersArray[4] = 23;

        System.out.println("Duplicate elements in the given array: ");
        
        // 1. First loop picks an element one by one
        for (int i = 0; i < size; i++) {
            
            // 2. Second loop compares the picked element with the remaining elements
            for (int j = i + 1; j < size; j++) {
                
                // If a match is found, it means the value is a duplicate
                if (numbersArray[i] == numbersArray[j]) {
                    System.out.println(numbersArray[j]);
                }
            }
        }
    }
}

