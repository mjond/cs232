//CaeserCipher client
//Mark Davis
//May 15, 2017

import java.lang.String;
import java.net.Socket;
import java.util.Scanner;
import java.io.DataOutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.PrintWriter;

public class CaesarCipherClient {

	/*
	 * gets user input and sends to the server
	*/
	public static void main(String[] args) throws IOException {

		//get hostName from commnadLine
		String hostName = args[0];
		//get port number from command line argument
		int portNumber = Integer.parseInt(args[1]);

		//open socket
		Socket myClient = new Socket(hostName, portNumber);

		OutputStream outStream = myClient.getOutputStream();
		//open PrintWriter
		PrintWriter out = new PrintWriter(outStream, true);

		//get user input
		Scanner userInput = new Scanner(System.in);
		int rotation = userInput.nextInt();

		out.append(rotation.toString());
		out.flush();

		//   can't get DataOutputStream to work...
		/*
		//write data out to socket
		ByteArrayOutputStream baos = null;
        DataOutputStream dos = null;
		//string to send to server
		String s = "abc";
		// create byte array output stream
        baos = new ByteArrayOutputStream();
        // create data output stream
        dos = new DataOutputStream(baos);         
        // write to the output stream from the string
        dos.writeBytes(s);
        //flush btes to underlying output stream
        dos.flush();
		*/

		//read in response
		BufferedReader in = new BufferedReader(
            new InputStreamReader(myClient.getInputStream()));

        //get user input
		String input;
		while (true) {
			input = getInput.nextLine();
    		if (userInput.equals("quit")) {
    			break;
    		}
    		out.append(userInput);
    		out.flush();
    		System.out.println("user input is: " + input);

    		input = in.readLine();
		}

        myClient.close();
		
	} //end main
} //end class