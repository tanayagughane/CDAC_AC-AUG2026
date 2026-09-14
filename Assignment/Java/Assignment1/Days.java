package com.practice;

public class Days {
	private int day;
	private int month;
	private int year;
	
//	public boolean isValidDate(int day, int month, int year) {
//		if(year<1) return false;
//		if(month<1 || month>12) return false;
//		return day
//	}

	public int getDay() {
		return day;
	}

	public void setDate(int dd, int mm, int yy) {
		year = yy;
		
		//month
		if(mm<1 || mm>12) {
			month =1;
		}else {
			month = mm;
		}
		
		if(month ==1 || month ==3 || month ==5 || month ==7 || month ==8 || month ==10 || month ==12) {
			if(dd <1 || dd>31) {
				day =1;
			}else {
				day = dd;
			}
		}else if (month == 4 || month == 6 || month ==9 || month ==11) {
			if(dd <1 || dd<30) {
				day = 1;
			}else {
				day = dd;
			}
		}else if (month ==2){  //leap year
			if((year %4 ==0 && year %100 !=0) || (year% 400 ==0)) {
			if(dd < 1 || dd >29) {
				day = 1;
			}else {
				day = dd;
			}	
		}else {
			if(dd < 1 || dd >28) {
				day = 1;
			}else {
				day = dd;
			}	
		}
			
		}
	}
	
	void addDays(int numberOfDays) {
        for (int i = 0; i < numberOfDays; i++) {
            
            day++; // Step 1: Add 1 day

            // Step 2: Check if day exceeded current month's limit
            
            // 31-day months
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                if (day > 31) {
                    day = 1;
                    month++;
                }
            } 
            // 30-day months
            else if (month == 4 || month == 6 || month == 9 || month == 11) {
                if (day > 30) {
                    day = 1;
                    month++;
                }
            } 
            // February
            else if (month == 2) {
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    if (day > 29) {
                        day = 1;
                        month++;
                    }
                } else {
                    if (day > 28) {
                        day = 1;
                        month++;
                    }
                }
            }

            // Step 3: Check if month exceeded December (12)
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
	
	
	
	public int getMonth() {
		return month;
	}

	

	public int getYear() {
		return year;
	}
	
}