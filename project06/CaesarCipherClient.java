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
	 * runs the server
	*/
	public static void main(String[] args) throws IOException {

		//get hostName from commnadLine
		String hostName = args[0];
		//get port number from command line argument
		int portNumber = Integer.parseInt(args[1]);

		//open socket
		Socket myClient = new Socket(hostName, portNumber);

		//open PrintWriter
		PrintWriter out = new PrintWriter(myClient.getOutputStream(), true);

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
		BufferedReader in =
        new BufferedReader(
            new InputStreamReader(myClient.getInputStream()));
        BufferedReader stdIn =
        new BufferedReader(
            new InputStreamReader(System.in));

        //get user input
		String userInput;
		while ((userInput = stdIn.readLine()) != "quit") {
    		out.println(userInput);
    		System.out.println("echo: " + in.readLine());
		}


        myClient.close();
		
	} //end main
} //end class