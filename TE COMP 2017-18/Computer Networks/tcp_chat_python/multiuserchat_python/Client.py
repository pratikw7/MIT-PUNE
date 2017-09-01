#Ashwin Vaidya
#302098
import sys
import socket
import select

def chat_client():


    host = "192.168.0.4"
    port = 3000

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.settimeout(2)

    # connect to remote host
    try :
        s.connect((host, port))
    except :
        print ('Unable to connect')
        sys.exit()

    print ('Connected to remote host. You can start sending messages')
    sys.stdout.write('Current: '); sys.stdout.flush()

    while 1:
        socket_list = [sys.stdin, s]

        # Get the list sockets which are readable
        ready_to_read,ready_to_write,in_error = select.select(socket_list , [], [])

        for sock in ready_to_read:
            if sock == s:
                # incoming message from remote server, s
                data2 = sock.recv(4096)
                data = data2.decode('utf-8')
                if not data :
                    print ('\nDisconnected from chat server')
                    sys.exit()
                else :
                    #print data
                    sys.stdout.write(data)
                    sys.stdout.write('Other: '); sys.stdout.flush()

            else :
                # user entered a message
                msg = sys.stdin.readline()
                s.send(msg.encode())
                sys.stdout.write('Current: '); sys.stdout.flush()

if __name__ == "__main__":

    sys.exit(chat_client())
