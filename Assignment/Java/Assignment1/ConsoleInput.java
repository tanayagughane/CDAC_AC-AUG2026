package com.practice;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class ConsoleInput {
    public static int getInt() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            return Integer.parseInt(br.readLine());
        } catch (IOException e) {
            System.out.println("Error reading input!");
            return 0;
        } catch (NumberFormatException e) {
            System.out.println("Invalid integer! Setting to 0.");
            return 0;
        }
    }
}