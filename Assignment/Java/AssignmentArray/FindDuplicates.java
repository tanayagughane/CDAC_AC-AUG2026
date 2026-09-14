package third;

public class FindDuplicates {

    public static void main(String[] args) {
        
        int size = 5; 
        int[] numbersArray = new int[size];
        
        // Assigning values to the array (added '23' twice to create a duplicate)
        numbersArray[0] = 45;
        numbersArray[1] = 23;  // Duplicate element
        numbersArray[2] = 89;
        numbersArray[3] = 7;
        numbersArray[4] = 23; // Duplicate element

        System.out.println("Duplicate elements in the array: ");
        
        
        for (int i = 0; i < size; i++) {
            
            
            for (int j = i + 1; j < size; j++) {
                
                // If a match is found, it is a duplicate
                if (numbersArray[i] == numbersArray[j]) {
                    System.out.println(numbersArray[j]);
                }
            }
        }
    }
}

