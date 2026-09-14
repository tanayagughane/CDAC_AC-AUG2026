package third;

public class ArrayCopy {

    public static void main(String[] args) {
        
        int size = 5; 
        int[] originalArray = new int[size];
        
       
        originalArray[0] = 45;
        originalArray[1] = 12;
        originalArray[2] = 89;
        originalArray[3] = 7;
        originalArray[4] = 23;

       
        int[] newArray = new int[size];

        // 1. Copy elements by iterating (looping) through the original array
        for (int i = 0; i < size; i++) {
            newArray[i] = originalArray[i]; 
        }

        // 2. Print the copied (new) array to verify
        System.out.println("Elements in the new copied array:");
        for (int i = 0; i < size; i++) {
            System.out.print(newArray[i] + " ");
        }
    }
}

