/*
 * Lab1_3 : String Exercise
 * Name : 이 연 주
 * ID : 20191644
 * Program Description : (3) String concat
 * Algorithm : string 2개를 입력받는다.
 *             'result'라는 이름의 빈 string을 만든다.
 *             string1, string2를 for문을 이용하여 result에 한 단어씩 추가해준다.
 * Variable :
 * 			Scanner : 입력을 받는다.
 * 			charAt(index) : index에 해당하는 부분의 char값.
 */

package 자료구조.Lab;
import java.util.Scanner;

public class Lab1_3_concat_20191644_이연주 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String string1 = sc.next();
		String string2 = sc.next(); //두개의 string을 입력받는다.
		System.out.println("\'" + string1 + "\' + \'" + string2 
				+ "\' : " + concat(string1, string2));
	}
	public static String concat(String string1, String string2) {
		String result = "";
		for(int i = 0; i < string1.length(); i++) {
			result += string1.charAt(i);
		} //string1을 result에 추가하여준다.
		for(int i = 0; i < string2.length(); i++) {
			result += string2.charAt(i);
		} //string2를 result에 추가하여준다.
		return result;
	}
}
