package third;

public class CommonElements {

    public static void main(String[] args) {
        
        int size = 5; 
        
        // 1.  First Array
        int[] firstArray = new int[size];
        firstArray[0] = 45;
        firstArray[1] = 12;
        firstArray[2] = 89;
        firstArray[3] = 7;
        firstArray[4] = 23;

        // 2. Second Array 
        int[] secondArray = new int[size];
        secondArray[0] = 12; // Common element
        secondArray[1] = 55;
        secondArray[2] = 23; // Common element
        secondArray[3] = 99;
        secondArray[4] = 45; // Common element

        System.out.println("Common elements between the two arrays:");

        // 3. Outer loop iterates through the first array
        for (int i = 0; i < size; i++) {
            
            // 4. Inner loop iterates through the second array to find a match
            for (int j = 0; j < size; j++) {
                
                // If an element from firstArray matches an element in secondArray, it's common
                if (firstArray[i] == secondArray[j]) {
                    System.out.println(firstArray[i]);
                    break; // Break prevents printing duplicates if the second array has the same number twice
                }
            }
        }
    }
}
