/*
 * Lab1_3 : String Exercise
 * Name : 이 연 주
 * ID : 20191644
 * Program Description : (2) compare String size
 * Algorithm : string 2개를 입력받는다.
 *             두 string이 같으면 넘어가고, 왼쪽부터 다른 단어를 찾아 비교한다.
 * Variable :
 * 			Scanner : 입력을 받는다.
 * 			charAt(index) : index에 해당하는 부분의 char값.
 *          equal() : 두개의 string을 비교
 */
package 자료구조.Lab;
import java.util.Scanner;

public class Lab1_3_compare_20191644_이연주 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String string1 = sc.next();
		String string2 = sc.next(); //두개의 string을 입력받는다.
		System.out.println("Result is \'" + compare(string1, string2) + "\'");
	}
	public static int compare(String string1, String string2) {
		int result;
		int i = 0;
		while (string1.charAt(i) == string2.charAt(i) && !string1.equals(string2)) {
			i += 1;
		} //두개의 string을 비교하였을때 각 자릿수에 해당하는 단어가 같거나 두단어가 같은 단어일 경우 index 값을 증가시켜준다.
		if (string1.charAt(i) > string2.charAt(i)) {
			result = 1;
		} //string1의 단어크기가 클 경우 1 반환.
		else if (string1.charAt(i) < string2.charAt(i)) {
			result = -1;
		} //string2의 단어크기가 클 경우 -1 반환.
		else {
			result = 0;
		} //index가 끝까지 증가하였고 두 단어가 같은 경우 0 반환.
		return result;
	}
}
