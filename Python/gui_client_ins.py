from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
import sys
import socket
 
# Arduino’s IP address (from Arduino Serial Monitor)
HOST = "192.168.10.43"  # Use Your Arduino's IP. It will print when
                        #You Run the Arduino Server Program
PORT = 12345            # Must match Arduino’s UDP port
 
# Create a UDP socket
mySocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
mySocket.settimeout(5.0)  # 5 seconds timeout for responses

app = QApplication([])

window = QMainWindow()
window.setWindowTitle('Welcome to GUI World')
window.setGeometry(100,100,500,300)

widgetContainer = QWidget()
window.setCentralWidget(widgetContainer)
mainLayout = QVBoxLayout(widgetContainer)

label = QLabel("Welcome to PyQt5!")
label.setAlignment(Qt.AlignCenter)
label.setStyleSheet("font-size: 24px; color: blue; padding: 10px;")
label.setFixedHeight(50)
mainLayout.addWidget(label)

pushButtonLayout = QHBoxLayout()
mainLayout.addLayout(pushButtonLayout)

pushButtonRed = QPushButton("Blink Red!")
pushButtonRed.setStyleSheet("background-color: red; color: white; font-size: 24px; padding:10;")
pushButtonRed.setFixedSize(150,50)
def pushButtonRedClicked():
    label.setText("Blink Red!")
    label.setStyleSheet(" font-size: 24px;color: red; padding:10;")
    cmd ="redblink:5:100\n"
    cmdEncoded=cmd.encode()
    mySocket.sendto(cmdEncoded, (HOST,PORT))
    print('Sent '+cmd+' to HOST',HOST,PORT)
    try:
        response, server_address = mySocket.recvfrom(1024)
        print("Server response:", response.decode())
    except socket.timeout:
        print("No response received from server within 5 seconds")
pushButtonRed.clicked.connect(pushButtonRedClicked)
pushButtonLayout.addWidget(pushButtonRed)

pushButtonGreen = QPushButton("Blink Green!")
pushButtonGreen.setStyleSheet("background-color: green; color: white; font-size: 24px; padding:10;")
pushButtonGreen.setFixedSize(150,50)
def pushButtonGreenClicked():
    label.setText("Blink Green!")
    label.setStyleSheet(" font-size: 24px;color: green; padding:10;")
    cmd ="greenblink:5:100\n"
    cmdEncoded=cmd.encode()
    mySocket.sendto(cmdEncoded, (HOST,PORT))
    print('Sent '+cmd+' to HOST',HOST,PORT)
    try:
        response, server_address = mySocket.recvfrom(1024)
        print("Server response:", response.decode())
    except socket.timeout:
        print("No response received from server within 5 seconds")
    
pushButtonGreen.clicked.connect(pushButtonGreenClicked)
pushButtonLayout.addWidget(pushButtonGreen)

pushButtonBlue = QPushButton("Blink Blue!")
pushButtonBlue.setStyleSheet("background-color: blue; color: white; font-size: 24px; padding:10;")
pushButtonBlue.setFixedSize(150,50)
def pushButtonBlueClicked():
    label.setText("Blink Blue!")
    label.setStyleSheet(" font-size: 24px;color: blue; padding:10;")
    cmd ="blueblink:5:100\n"
    cmdEncoded=cmd.encode()
    mySocket.sendto(cmdEncoded, (HOST,PORT))
    print('Sent '+cmd+' to HOST',HOST,PORT)
    try:
        response, server_address = mySocket.recvfrom(1024)
        print("Server response:", response.decode())
    except socket.timeout:
        print("No response received from server within 5 seconds")
 
pushButtonBlue.clicked.connect(pushButtonBlueClicked)
pushButtonLayout.addWidget(pushButtonBlue)

toggleButtonLayout = QHBoxLayout()
mainLayout.addLayout(toggleButtonLayout)


toggleButtonRed = QPushButton("Toggle Red")
toggleButtonRed.setCheckable(True)
toggleButtonRed.setStyleSheet("background-color: red; color: white; font-size: 18px; padding:10;")
toggleButtonRed.setFixedSize(150,50)
def toggleRed(checked):
    if checked:
        label.setText("Red Toggle ON")
        label.setStyleSheet(" font-size: 24px;color: red; padding:10;")
        cmd="redOn\n"
        cmdEncoded=cmd.encode()
        mySocket.sendto(cmdEncoded, (HOST,PORT))
        print('Sent '+cmd+' to HOST',HOST,PORT)
        try:
            response, server_address = mySocket.recvfrom(1024)
            print("Server response:", response.decode())
        except socket.timeout:
            print("No response received from server within 5 seconds")
    if not checked:
        label.setText("Red Toggle OFF")
        label.setStyleSheet(" font-size: 24px;color: red; padding:10;")
        cmd="redOff\n"
        cmdEncoded=cmd.encode()
        mySocket.sendto(cmdEncoded, (HOST,PORT))
        print('Sent '+cmd+' to HOST',HOST,PORT)
        try:
            response, server_address = mySocket.recvfrom(1024)
            print("Server response:", response.decode())
        except socket.timeout:
            print("No response received from server within 5 seconds") 
        

toggleButtonRed.toggled.connect(toggleRed)
toggleButtonLayout.addWidget(toggleButtonRed)

toggleButtonGreen = QPushButton("Toggle Green")
toggleButtonGreen.setCheckable(True)
toggleButtonGreen.setStyleSheet("background-color: green; color: white; font-size: 18px; padding:10;")
toggleButtonGreen.setFixedSize(150,50)
def toggleGreen(checked):
    if checked:
        label.setText("Green Toggle ON")
        label.setStyleSheet(" font-size: 24px;color: green; padding:10;")
        cmd="greenOn\n"
        cmdEncoded=cmd.encode()
        mySocket.sendto(cmdEncoded, (HOST,PORT))
        print('Sent '+cmd+' to HOST',HOST,PORT)
        try:
            response, server_address = mySocket.recvfrom(1024)
            print("Server response:", response.decode())
        except socket.timeout:
            print("No response received from server within 5 seconds")
    if not checked:
        label.setText("Green Toggle OFF")
        label.setStyleSheet(" font-size: 24px;color: green; padding:10;")
        cmd="greenOff\n"
        cmdEncoded=cmd.encode()
        mySocket.sendto(cmdEncoded, (HOST,PORT))
        print('Sent '+cmd+' to HOST',HOST,PORT)
        try:
            response, server_address = mySocket.recvfrom(1024)
            print("Server response:", response.decode())
        except socket.timeout:
            print("No response received from server within 5 seconds") 
   
toggleButtonGreen.toggled.connect(toggleGreen)
toggleButtonLayout.addWidget(toggleButtonGreen)

toggleButtonBlue = QPushButton("Toggle Blue")
toggleButtonBlue.setCheckable(True)
toggleButtonBlue.setStyleSheet("background-color: blue; color: white; font-size: 18px; padding:10;")
toggleButtonBlue.setFixedSize(150,50)
def toggleBlue(checked):
    if checked:
        label.setText("Blue Toggle ON")
        label.setStyleSheet(" font-size: 24px;color: blue; padding:10;")
        cmd='blueOn\n'
        cmdEncoded=cmd.encode()
        mySocket.sendto(cmdEncoded, (HOST,PORT))
        print('Sent '+cmd+' to HOST',HOST,PORT)
        try:
            response, server_address = mySocket.recvfrom(1024)
            print("Server response:", response.decode())
        except socket.timeout:
            print("No response received from server within 5 seconds")
    if not checked:
        label.setText("Blue Toggle OFF")
        label.setStyleSheet(" font-size: 24px;color: blue; padding:10;")
        cmd="blueOff\n"
        cmdEncoded=cmd.encode()
        mySocket.sendto(cmdEncoded, (HOST,PORT))
        print('Sent '+cmd+' to HOST',HOST,PORT)
        try:
            response, server_address = mySocket.recvfrom(1024)
            print("Server response:", response.decode())
        except socket.timeout:
            print("No response received from server within 5 seconds") 
   
toggleButtonBlue.toggled.connect(toggleBlue)
toggleButtonLayout.addWidget(toggleButtonBlue)

def sendBrightness(color, strength):
    cmd = color+"bright:"+str(strength)+"\n"
    mySocket.sendto(cmd.encode(), (HOST,PORT))
    print('Sent '+cmd+' to HOST',HOST,PORT)
    # Short wait so dragging a slider does not freeze the GUI or flood the Arduino
    mySocket.settimeout(0.1)
    try:
        response, server_address = mySocket.recvfrom(1024)
        print("Server response:", response.decode())
    except socket.timeout:
        print("No response received from server within 0.1 seconds")
    mySocket.settimeout(5.0)

redSlider = QSlider(Qt.Horizontal)
redSlider.setMinimum(0)
redSlider.setMaximum(100)
redSlider.setValue(100)
redSlider.setStyleSheet("""
QSlider::groove:horizontal {background: lightpink; height:20px;border-radius:5px;}
QSlider::handle:horizontal {background: red; margin-top: -10px;margin-bottom: -10px;height: 40px;width: 20px;border-radius:5px;}

""")
redSlider.setFixedHeight(50)
def updateRedSlider():
    label.setText("Red Slider: "+str(redSlider.value()))
    label.setStyleSheet("font-size: 24px: red; padding: 10;")
    redStrength = redSlider.value()/100*255
    print("Red Strengt: ", redStrength)
    sendBrightness("red", int(redStrength))

redSlider.valueChanged.connect(updateRedSlider)
mainLayout.addWidget(redSlider)

GreenSlider = QSlider(Qt.Horizontal)
GreenSlider.setMinimum(0)
GreenSlider.setMaximum(100)
GreenSlider.setValue(100)
GreenSlider.setStyleSheet("""
QSlider::groove:horizontal {background: lightgreen; height:20px;border-radius:5px;}
QSlider::handle:horizontal {background: green; margin-top: -10px;margin-bottom: -10px;height: 40px;width: 20px;border-radius:5px;}

""")
GreenSlider.setFixedHeight(50)
def updateGreenSlider():
    label.setText("Green Slider: "+str(GreenSlider.value()))
    label.setStyleSheet("font-size: 24px: red; padding: 10;")
    greenStrength = GreenSlider.value()/100*255
    print("Green Strengt: ", greenStrength)
    sendBrightness("green", int(greenStrength))

GreenSlider.valueChanged.connect(updateGreenSlider)
mainLayout.addWidget(GreenSlider)

BlueSlider = QSlider(Qt.Horizontal)
BlueSlider.setMinimum(0)
BlueSlider.setMaximum(100)
BlueSlider.setValue(100)
BlueSlider.setStyleSheet("""
QSlider::groove:horizontal {background: lightblue; height:20px;border-radius:5px;}
QSlider::handle:horizontal {background: blue; margin-top: -10px;margin-bottom: -10px;height: 40px;width: 20px;border-radius:5px;}

""")
BlueSlider.setFixedHeight(50)
def updateBlueSlider():
    label.setText("Blue Slider: "+str(BlueSlider.value()))
    label.setStyleSheet("font-size: 24px: red; padding: 10;")
    blueStrength = BlueSlider.value()/100*255
    print("Blue Strengt: ", blueStrength)
    sendBrightness("blue", int(blueStrength))

BlueSlider.valueChanged.connect(updateBlueSlider)
mainLayout.addWidget(BlueSlider)

mainLayout.addStretch()
# The sliders start at full, so make sure the Arduino matches them
sendBrightness("red", 255)
sendBrightness("green", 255)
sendBrightness("blue", 255)

window.show()
sys.exit(app.exec_())