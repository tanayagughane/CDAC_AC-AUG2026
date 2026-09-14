package third;

class ComplexNumber {
	private int number1;
	private int number2;
	
	public int getNumber1() {
		return number1;
	}
	
	public int getNumber2() {
		return number2;
	}
	
	
	public ComplexNumber(int n1, int n2) {
        number1 = n1;
        number2 = n2;
    }
	
	public int multiply() {
		return number1 * number2;
	}
}

public class Main {

	public static void main(String[] args) {
		
		ComplexNumber[] numbersArray = new ComplexNumber[5];
		
		for(int iTemp = 0; iTemp < 5; iTemp++) {
			
			
			int num1 = (iTemp + 1) * 2;
			int num2 = (iTemp + 1) * 3;
			
			
			numbersArray[iTemp] = new ComplexNumber(num1, num2); 
            
            System.out.println("Object " + (iTemp + 1) + " values set to: " + num1 + " and " + num2);
		}
		
		System.out.println("\n--- Results ---");
        for (int iTemp = 0; iTemp < 5; iTemp++) {
            int result = numbersArray[iTemp].multiply();
            System.out.println("Result " + (iTemp + 1) + ": " + result);
        }
	}
}
