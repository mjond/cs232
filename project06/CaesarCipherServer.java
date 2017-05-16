/*
	Mark Davis
	project 6, cs 232
	Caeser Cipher Server
*/

import java.util.Date;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.net.Socket;
import java.net.ServerSocket;

public class CaeserCipherServer {

	/*
	driver program for the server
	handles multi-threading
	*/
	public static void main(String[] args) throws IOException (
		
		int portNumber = Integer.parseInt(args[0]);

		ServerSocket serverSocket = new ServerSocket(portNumber);

		while(true) {
			private Socket clientSocket = null;

			//multithreading
			//call cipher

		}
	)

	/*
	Code that helped write the cipher found at:
	http://stackoverflow.com/questions/19108737/java-how-to-implement-a-shift-cipher-caesar-cipher
	*/
	public String Cipher(String input, int rotation) {
		String s = "";
		int length = input.length();
		for (int x = 0; x < length; x++) {
			char c = (char)(input.charAt(x) + rotation);
			if (c > 'z')
				s += (char)(input.charAt(x) - (26-shift));
			else
				s += (char)(input.charAt(x) + rotation);
		}
		return s;
	} //end cipher

} //end class