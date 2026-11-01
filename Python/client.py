import socket
HOST="192.168.10.45"
PORT= 12345
mySocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
mySocket.settimeout(5.0)
print("UDP Client started. Enter a color (or 'quit' to exit).")
while True:
    color=input("Enter a Color: ")
    if color.lower() == 'quit':
        break
    sendColor=color.encode()
    mySocket.sendto(sendColor, (HOST, PORT))
    print("Sent " + color + " to HOST ", HOST,PORT)
    try:
        response, server_address=mySocket.recvfrom(1024)
        print("Server Response: ", response.decode())
    except socket.timeout:
        print("No Response from Server in 5 seconds")
mySocket.close()
print("Socket Closed")
        