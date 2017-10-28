# TCP peer to peer chat
#	Ashwin Vaidya
#	302098
#	TE 1
import socket
import select
import sys # input from keyboard

print("Starting client")

s = socket.socket()
host = socket.gethostname()
port = 3000

s.connect((host,port)) #connect takes only one argument
while True:
	socket_list = [sys.stdin,s] #get a list of sockets which are readable
	read_sockets, write_sockets, error_sockets = select.select(socket_list , [], [])
	for sock in read_sockets:
			#incoming message from remote server
			if sock == s: #incoming message from socket
				data = s.recv(1024)
				if not data:
					print("Disconnected")
					s.close
					sys.exit()
				else:
					print('Other: ',data.decode())
					sys.stdout.flush()
			else:
				sys.stdout.write('> ')
				msg = sys.stdin.readline()
				s.send(msg.encode())
				sys.stdout.flush()
s.close