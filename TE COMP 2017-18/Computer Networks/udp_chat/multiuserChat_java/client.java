//UDP CHATTING

import java.io.IOException;
import java.net.*;
import java.util.Scanner;

public class client {
DatagramSocket Socket;

//public client() {
//
//}

public void createAndListenSocket() {
	try {
		Scanner sc=new Scanner(System.in);
		byte[] incomingData = new byte[1024];
		while(true){
			System.out.println();
			System.out.println("Me: ");
			Socket = new DatagramSocket();
			InetAddress IPAddress = InetAddress.getByName("localhost");
			
			for(int i=0;i<1024;i++){
				incomingData[i]=0;
			}
			String sentence = sc.nextLine();
			//System.out.println("a1");
			byte[] data = sentence.getBytes();
			DatagramPacket sendPacket = new DatagramPacket(data, data.length, IPAddress, 3000);
			Socket.send(sendPacket);
			if(sentence.equalsIgnoreCase("exit")){
				System.out.println("Disconnecting....");
				break;
			}
			//System.out.println("a2");
			//System.out.println("Message sent from client");
			DatagramPacket incomingPacket = new DatagramPacket(incomingData, incomingData.length);
			Socket.receive(incomingPacket);
			//System.out.println("a3");
			String response = new String(incomingPacket.getData());
			if(response.equalsIgnoreCase("exit")){
				System.out.println("Disconnecting....");
				break;
			}
			System.out.println();
			System.out.println("Other:");
			System.out.println(response);
		}
		Socket.close();
	} catch (UnknownHostException e) {
		e.printStackTrace();
	} catch (SocketException e) {
		e.printStackTrace();
	} catch (IOException e) {
		e.printStackTrace();
	}
}

public static void main(String[] args) {
client client = new client();
client.createAndListenSocket();
}
}
