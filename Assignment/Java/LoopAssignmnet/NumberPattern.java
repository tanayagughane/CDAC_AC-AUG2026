package second;

public class NumberPattern {

	public static void main(String[] args) {
		 int number = 1;

	        // Outer loop 
	        for (int iTemp = 1; iTemp <= 4; iTemp++) {
	            
	            // Inner loop 
	            for (int jTemp = 1; jTemp <= iTemp; jTemp++) {
	                System.out.print(number + " ");
	                
	                number++;   // Increases the number by 1 after printing
	            }
	        
	            System.out.println();
	        }
	}

}
