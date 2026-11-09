import socket
HOST="192.168.10.45"
PORT= 12345
mySocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
mySocket.settimeout(5.0)
print("UDP Client started. Enter a Data (or 'quit' to exit).")
while True:
    S_rqt=input("Enter 't' for temperature, Enter 'p' for pressure, Enter 'b' for both: ")
    if S_rqt.lower() == 'quit':
        break
    sendRQT=S_rqt.encode()
    mySocket.sendto(sendRQT, (HOST, PORT))
    print("Sent " + S_rqt + " to HOST ", HOST,PORT)
    try:
        response, server_address=mySocket.recvfrom(1024)
        print("Server Response: ", response.decode())
    except socket.timeout:
        print("No Response from Server in 5 seconds")
mySocket.close()
print("Socket Closed")
        
