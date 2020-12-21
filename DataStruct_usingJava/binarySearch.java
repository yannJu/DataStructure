package 자료구조;
import java.util.Scanner;

public class binarySearch {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] arr = {1, 3, 5, 6, 7, 9};
		int f_n = sc.nextInt();
		if (findUseBinary(arr, f_n) > 0) {
			System.out.println("찾고자하는 값 \'" + f_n + "\'이 \'" +
		findUseBinary(arr, f_n) + "\'번째 자리에 있습니다!");
		}
		else {
			System.out.println("찾고자하는 값 \'" + f_n + "\'이 이 배열에 없습니다!");
		}
		if (binaryUsingRecursive(arr, f_n, arr.length, 0) > 0) {
			System.out.println("찾고자하는 값 \'" + f_n + "\'이 \'" +
		binaryUsingRecursive(arr, f_n, arr.length, 0) + "\'번째 자리에 있습니다!");
		}
		else {
			System.out.println("찾고자하는 값 \'" + f_n + "\'이 이 배열에 없습니다!");
		}
	}
	public static int findUseBinary(int[] arr, int f_n) {
		int middle;
		int left = 0;
		int right = arr.length - 1;
		
		while(left <= right) {
			middle = (left + right) / 2;
			if (arr[middle] == f_n) {
				return middle;
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
				return middle;
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
