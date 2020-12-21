package 자료구조;

import java.util.Scanner;

public class sum_using_recursive {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n_1 = sc.nextInt();
		int n_2 = sc.nextInt();
		System.out.println("Fibo \'" + n_1 + "\' : " + fiboSum(n_1));
		System.out.println("Sum \'" + n_1 + "\' + \'" + 
		n_2 + "\' : " + sum(n_1, n_2));
		System.out.println("Substract \'" + n_1 + "\' + \'" + 
				n_2 + "\' : " + substract(n_1, n_2));
	}
	public static int fiboSum(int num) {
		if (num == 1) {
			return 1;
		}
		else {
			return fiboSum(num - 1) + num;
		}
	}
	public static int sum(int num1, int num2) {
		// 2 + 3 -> 1 + 4 -> 0 + 5 == 5
		int tmp;
		if (num1 > num2) {
			tmp = num1;
			num1 = num2;
			num2 = tmp;
		}
		if (num1 == 0) {
			return num2;
		}
		else {
			return sum(num1 - 1, num2 + 1);
		}
	}
	public static int substract(int num1, int num2) {
		//2 - 3 -> 1 - 2 -> 0 - 1  == 1
		if (num1 == 0) {
			return num2;
		}
		else if (num2 == 0) {
			return num1;
		}
		else {
			return substract(num1 - 1, num2 - 1);
		}
	}
}
