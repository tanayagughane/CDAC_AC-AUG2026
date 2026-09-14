package second;

public class StarPattern {

	public static void main(String[] args) {
		
		// Outer loop 
        for (int iTemp = 1; iTemp <= 5; iTemp++) {
            
            // Inner loop 
            for (int jTemp = 1; jTemp <= iTemp; jTemp++) {
                System.out.print("* ");
            }
            
            System.out.println();
        }

	}

}
