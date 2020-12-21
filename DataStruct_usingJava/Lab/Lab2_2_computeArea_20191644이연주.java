//Lab2-2 20191644 이연주

package 자료구조.Lab;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

class Angle{
	public double Angle(double round) {
		return round*round*3.14;
	}
	public double Angle(int type, double width, double height) {
		if (type == 1) { //triangle
			return width*height*0.5;
		}
		else if (type == 2) { //rectangle
			return width*height;
		}
		return 0.0;
	}
}
public class Lab2_2_computeArea_20191644이연주 {
	public static void main(String[] args) {
		String[] arr;
		String type;
		double width;
		double height;
		double round;
		double result;
		
		File inFile = new File("C:\\Users\\duswn\\eclipse-workspace\\자료구조\\src\\자료구조", "lab2-2.dat"); //파일을 읽음
		BufferedReader br = null;
		try {
			Angle angle = new Angle();
			br = new BufferedReader(new FileReader(inFile));
			String line;
			while ((line = br.readLine()) != null) {
				arr = line.split(" ");
				type = arr[0];
				if (type.equals("triangle")){
					width = Double.parseDouble(arr[1]);
					height = Double.parseDouble(arr[2]);
					result = angle.Angle(1, width, height);
					
					System.out.println(type + " " + width + " " + height + " " + result);
				}
				else if (type.equals("rectangle")) {
					width = Double.parseDouble(arr[1]);
					height = Double.parseDouble(arr[2]);	
					result = angle.Angle(2, width, height);
					
					System.out.println(type + " " + width + " " + height + " " + result);
				}
				else {
					round = Double.parseDouble(arr[1]);
					result = angle.Angle(round);
					
					System.out.println(type + " " + round + " " + result);
				}
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}finally {
			if(br != null) try {br.close();} catch (IOException e) {}
		}
	}
}
