# TCP peer to peer chat
#	Ashwin Vaidya
#	302098
#	TE 1
import socket
import select
import sys # input from keyboard
print("Starting server")
s = socket.socket()
host = socket.gethostname() #get local machine name
port = 3000
s.bind((host,port)) #bind takes only one argument

s.listen(5) #wait for connection
c, addr = s.accept() # Establish connection with client | return value is a pair (conn, address)
print('Got connection from ',addr)
c.send('You are now connected\n'.encode())
while True:
	socket_list = [sys.stdin,c] #get a list of sockets which are readable
	read_sockets, write_sockets, error_sockets = select.select(socket_list , [], [])
	for sock in read_sockets:
		#incoming message from remote server
		if sock ==c: #incoming messag from socket
			data = c.recv(1024)
			if not data:
				print("Disconnected")
				c.close
				sys.exit()
			else:
				print('Other: ',data.decode())
				sys.stdout.flush()
		else:
			sys.stdout.write('> ')
			msg = sys.stdin.readline()
			c.send(msg.encode())
			sys.stdout.flush()
c.close