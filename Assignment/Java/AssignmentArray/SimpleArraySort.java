package third;

public class SimpleArraySort {

    public static void main(String[] args) {
        
        
        int size = 5; 
        int[] numbersArray = new int[size];
        
        
        numbersArray[0] = 45;
        numbersArray[1] = 12;
        numbersArray[2] = 89;
        numbersArray[3] = 7;
        numbersArray[4] = 23;

        //1. Print original array
        System.out.println("Original Array:");
        for (int i = 0; i < size; i++) {
            System.out.print(numbersArray[i] + " ");
        }
        System.out.println(); 

        // 2. Simple Bubble Sort logic 
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                
                // If the left element is bigger than the right element, swap them
                if (numbersArray[i] > numbersArray[j]) {
                    int temp = numbersArray[i];
                    numbersArray[i] = numbersArray[j];
                    numbersArray[j] = temp;
                }
            }
        }

        // 3. Print the sorted array
        System.out.println("\nSorted Array (Ascending):");
        for (int i = 0; i < size; i++) {
            System.out.print(numbersArray[i] + " ");
        }
    }
}

