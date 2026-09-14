package second;

public class EverySeventhNumber {

	public static void main(String[] args) {
		System.out.println("Every 7th number from 1 to 200: ");

        
        for (int iTemp = 1; iTemp <= 200; iTemp = iTemp + 7) {
            System.out.print(iTemp + " ");
        }

	}

}
