//Lab2-1 20191644이연주
package 자료구조.Lab;
import java.util.Scanner;

public class Lab2_1_binarySearch_20191644이연주 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int select_num = 0;
		int f_n;
		int[] arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
		while (select_num != 3) {
			System.out.print("1. BinarySearch 2. Recursive Search 3. Exit : ");
			select_num = sc.nextInt();
			if (select_num == 1) {
				System.out.print("Enter an integer to search : ");
				f_n = sc.nextInt();
				if (findUseBinary(arr, f_n) >= 0) {
				 System.out.println("--> Search Number \'" + f_n +
						"\' is at position " + findUseBinary(arr, f_n));
				}
				else {
					System.out.println("--> Search Number \'" + f_n +
							"\' is not in the list");
				}
			}
			else if (select_num == 2) {
				System.out.print("Enter an integer to search : ");
				f_n = sc.nextInt();
				if (binaryUsingRecursive(arr, f_n, arr.length - 1, 0) >= 0) {
					System.out.println("--> Search Number \' " +
				f_n + "\' is at position " + binaryUsingRecursive(arr, f_n, arr.length - 1, 0));
			}
				else {
					System.out.println("--> Search Number \'" + f_n +
							"\' is not in the list");
				}
		}
			else if (select_num == 3) {
				System.out.println("Bye.");
			}
			else {
				System.out.println("Wrong Num, please input again");
			}
	}
	}
	public static int findUseBinary(int[] arr, int f_n) {
		int middle;
		int left = 0;
		int right = arr.length - 1;
		
		while(left <= right) {
			middle = (left + right) / 2;
			if (arr[middle] == f_n) {
				return middle + 1;
			}
			else if (arr[middle] > f_n) {
				right = middle - 1;
			}
			else if (arr[middle] < f_n){
				left = middle + 1;
			}
		}
		return -1;
	}
	public static int binaryUsingRecursive(int[] arr, int f_n, int right, int left) {
		int middle = (right + left) / 2;
		if (left <= right) {
			if (arr[middle] == f_n) {
				return middle + 1;
			}
			else if (arr[middle] > f_n){
				return binaryUsingRecursive(arr, f_n, middle - 1, left);
			}
			else if (arr[middle] < f_n) {
				return binaryUsingRecursive(arr, f_n, right, middle + 1);
			}
		}
		return -1;
	}
}
