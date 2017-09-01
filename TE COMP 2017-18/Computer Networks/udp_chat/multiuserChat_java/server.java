//UDP CHATTING

import java.util.Scanner;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;					//represents IP address
import java.net.SocketException;

public class server {
	DatagramSocket socket = null;
	
	
	public void createAndListenSocket() {
		try {
			Scanner sc=new Scanner(System.in);
			socket = new DatagramSocket(3000);				//parameter is port number
			byte[] incomingData = new byte[1024];
			//System.out.println("b01");
			while (true) {
				for(int i=0;i<1024;i++){
				incomingData[i]=0;
				}
				DatagramPacket incomingPacket = new DatagramPacket(incomingData, incomingData.length);
				socket.receive(incomingPacket);
				String message = new String(incomingPacket.getData());
				if(message.equalsIgnoreCase("exit")){
					System.out.println("Disconnecting....");
					break;
				}
				System.out.println();
				System.out.println("Me: ");
				System.out.println(message);
				System.out.println();
				System.out.println("Other: ");
				InetAddress IPAddress = incomingPacket.getAddress();
				int port = incomingPacket.getPort();
				
				String reply = sc.nextLine();
				byte[] data = reply.getBytes();
				DatagramPacket replyPacket =
				new DatagramPacket(data, data.length, IPAddress, port);
				socket.send(replyPacket);
				if(reply.equalsIgnoreCase("exit")){
					System.out.print("Disconnecting....");
					break;
				}
				Thread.sleep(2000);
			}
			socket.close();
		} catch (SocketException e) {
			e.printStackTrace();
		} catch (IOException i) {
			i.printStackTrace();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		server server = new server();
		server.createAndListenSocket();
	}
}
