/*
 * Lab1_3 : String Exercise
 * Name : �� �� ��
 * ID : 20191644
 * Program Description : (1) print String length
 * Algorithm : method 1) string �ϳ��� �Է¹޴´�. 2) ������ string�� string1�̶�� ������ �����Ѵ�
 *                     length�Լ��� �̿��Ͽ� ���̸� ã�´�.
 * Variable :
 * 			Scanner : �Է��� �޴´�.
 *          length() : String�� ���̸� ��ȯ�Ѵ�.
 */
package �ڷᱸ��.Lab;
import java.util.Scanner;

public class Lab1_3_length_20191644_�̿��� {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String strLen = sc.next(); //string�� �Է¹޴´�.
		String string1 = "Hello World"; //string�� �����Ѵ�.
		System.out.println(strLen + " : " + printLen(strLen));
		System.out.println(string1 + " : " + printLen(string1));
	}
	
	public static int printLen(String strLen) {
		return strLen.length();//string���̸� ��ȯ�Ѵ�.
	}
}
