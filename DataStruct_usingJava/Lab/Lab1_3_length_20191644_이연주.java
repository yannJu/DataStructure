/*
 * Lab1_3 : String Exercise
 * Name : 이 연 주
 * ID : 20191644
 * Program Description : (1) print String length
 * Algorithm : method 1) string 하나를 입력받는다. 2) 지정된 string을 string1이라는 변수에 저장한다
 *                     length함수를 이용하여 길이를 찾는다.
 * Variable :
 * 			Scanner : 입력을 받는다.
 *          length() : String의 길이를 반환한다.
 */
package 자료구조.Lab;
import java.util.Scanner;

public class Lab1_3_length_20191644_이연주 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String strLen = sc.next(); //string을 입력받는다.
		String string1 = "Hello World"; //string을 저장한다.
		System.out.println(strLen + " : " + printLen(strLen));
		System.out.println(string1 + " : " + printLen(string1));
	}
	
	public static int printLen(String strLen) {
		return strLen.length();//string길이를 반환한다.
	}
}
