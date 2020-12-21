/*
 * Lab1_3 : String Exercise
 * Name : �� �� ��
 * ID : 20191644
 * Program Description : (3) String concat
 * Algorithm : string 2���� �Է¹޴´�.
 *             'result'��� �̸��� �� string�� �����.
 *             string1, string2�� for���� �̿��Ͽ� result�� �� �ܾ �߰����ش�.
 * Variable :
 * 			Scanner : �Է��� �޴´�.
 * 			charAt(index) : index�� �ش��ϴ� �κ��� char��.
 */

package �ڷᱸ��.Lab;
import java.util.Scanner;

public class Lab1_3_concat_20191644_�̿��� {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String string1 = sc.next();
		String string2 = sc.next(); //�ΰ��� string�� �Է¹޴´�.
		System.out.println("\'" + string1 + "\' + \'" + string2 
				+ "\' : " + concat(string1, string2));
	}
	public static String concat(String string1, String string2) {
		String result = "";
		for(int i = 0; i < string1.length(); i++) {
			result += string1.charAt(i);
		} //string1�� result�� �߰��Ͽ��ش�.
		for(int i = 0; i < string2.length(); i++) {
			result += string2.charAt(i);
		} //string2�� result�� �߰��Ͽ��ش�.
		return result;
	}
}
