package 자료구조;
import java.util.Scanner;

public class GCD {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		System.out.println("gcd : " + gcd(a, b) + " Rgcd : " + Rgcd(a, b));
	}
	public static int gcd(int a, int b) {
		int tmp;
		int r;
		
		if (a < b) {
			tmp = a;
			a = b;
			b = tmp;
		}
		while (b != 0) {
			r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
	public static int Rgcd(int a, int b) {
		if (a == b) {
			return a;
		}
		else if (a > b) {
			return Rgcd(a - b, b);
		}
		else {
			return Rgcd(a, b - a);
		}
	}
}
