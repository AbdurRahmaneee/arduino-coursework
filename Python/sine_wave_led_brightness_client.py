import pyqtgraph as pg
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import QGuiApplication
import sys
from math import sin,pi
import time
import socket
 
# Arduino’s IP address (from Arduino Serial Monitor)
HOST = "192.168.10.42"  # Use Your Arduino's IP. It will print when
                        #You Run the Arduino Server Program
PORT = 12345            # Must match Arduino’s UDP port
 
# Create a UDP socket
mySocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

SEND_EVERY = 2          # Send brightness every Nth timer tick (2 -> ~50 packets/s)
tickCount = 0

Period = 5
frequency = 1/Period
numPoints = 500
timeStep = Period/numPoints
redData = [0]*numPoints
timeData = [0]*numPoints

app = QApplication([])
window = QMainWindow()
window.setWindowTitle("Red Sine Wave Graph")
window.setGeometry(100,100,800,600)

screens = QGuiApplication.screens()
if len(screens) > 1:    # Only move to the second monitor if there is one
    window.move(screens[1].geometry().x() + 100, screens[1].geometry().y() + 100)

widgetContainer = QWidget()
window.setCentralWidget(widgetContainer)

mainLayout = QVBoxLayout(widgetContainer)

plotWidget = pg.PlotWidget()
plotWidget.setLabel("left", "y=sin(2*Pi*f*t)")
plotWidget.setLabel("bottom", "Time (s)")
plotWidget.setTitle("My Fine Sine Wave")
plotWidget.addLegend()
mainLayout.addWidget(plotWidget)

for i in range(numPoints):
    t = i * timeStep
    timeData[i] = t
    redData[i] = sin(2*pi*frequency*t)

redPlot = plotWidget.plot(timeData, redData, pen=pg.mkPen("r",width=3),name="Red")
tStart = time.perf_counter()
def updateGraph():
    global t, tStart, tickCount
    t = t + timeStep
    r = sin(2*pi*frequency*t)
    for i in range(numPoints - 1):
        redData[i] = redData[i+1]
        timeData[i] = timeData[i+1]
    redData[numPoints -1] = r
    timeData[numPoints -1] = t
    redPlot.setData(timeData,redData)

    # Send the newest point to the Arduino, scaled from -1..1 to 0..255
    tickCount = tickCount + 1
    if tickCount % SEND_EVERY == 0:
        brightness = int((r + 1) / 2 * 255)
        cmd = str(brightness)
        try:
            mySocket.sendto(cmd.encode(), (HOST,PORT))
        except OSError as e:
            print("Send failed:", e)

    if redData[0] <=0 and redData[1] > 0:
        measuredPeriod = time.perf_counter() - tStart
        print("Measured Period: ", measuredPeriod)
        tStart = time.perf_counter()
timer = QTimer()
timer.timeout.connect(updateGraph)
timer.start(int(timeStep*1000))

window.show()
sys.exit(app.exec_())
