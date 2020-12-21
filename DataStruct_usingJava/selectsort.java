package 자료구조;

import java.util.Arrays;

public class selectsort {
	public static void main(String[] args) {
		int[] arr = {2, 8, 5, 7, 3, 6, 4};
		System.out.println(Arrays.toString(SelectSort(arr)));
	}
	public static int[] SelectSort(int[] arr) {
		int min;
		int tmp;
		
		for (int i = 0; i < arr.length - 1; i++) {
			min = i;
			for (int j = i; j < arr.length; j++) {
				if (arr[j] < arr[min]) {
					min = j;
				}
			}
			if (min != i) {
				tmp = arr[i];
				arr[i] = arr[min];
				arr[min] = tmp;
			}
		}
		
		return arr;
	}
}
