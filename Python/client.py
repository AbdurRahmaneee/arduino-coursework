import socket
HOST="192.168.10.45"
PORT= 12345
mySocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
mySocket.settimeout(5.0)
print("UDP Client started. Enter a Data (or 'quit' to exit).")
while True:
    # Prompt for Data
    myData=input("Enter a Data: ")
    if myData.lower() == 'quit':
        break
    # Send Data to the server
    myData=myData+'\n'
    myDataEncoded=myData.encode()
    mySocket.sendto(myDataEncoded, (HOST, PORT))
    print("Sent " + myData + " to HOST ", HOST,PORT)
    try:
        response, server_address=mySocket.recvfrom(1024)
        print("Server Response: ", response.decode())
    except socket.timeout:
        print("No Response from Server in 5 seconds")
mySocket.close()
print("Socket Closed")
        