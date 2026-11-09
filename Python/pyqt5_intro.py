from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
import sys

app = QApplication([])

window = QMainWindow()
window.setWindowTitle('Welcome to GUI World')
window.setGeometry(100, 100, 500, 300)

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
    label.setStyleSheet("color: red; font-size: 24px; padding:10;")
pushButtonRed.clicked.connect(pushButtonRedClicked)
pushButtonLayout.addWidget(pushButtonRed)

pushButtonGreen = QPushButton("Blink Green!")
pushButtonGreen.setStyleSheet("background-color: green; color: white; font-size: 24px; padding:10;")
pushButtonGreen.setFixedSize(150,50)
def pushButtonGreenClicked():
    label.setText("Blink Green!")
    label.setStyleSheet("color: green; font-size: 24px; padding:10;")
pushButtonGreen.clicked.connect(pushButtonGreenClicked)
pushButtonLayout.addWidget(pushButtonGreen)

pushButtonBlue = QPushButton("Blink Blue!")
pushButtonBlue.setStyleSheet("background-color: blue; color: white; font-size: 24px; padding:10;")
pushButtonBlue.setFixedSize(150,50)
def pushButtonBlueClicked():
    label.setText("Blink Blue!")
    label.setStyleSheet("color: blue; font-size: 24px; padding:10;")
pushButtonBlue.clicked.connect(pushButtonBlueClicked)
pushButtonLayout.addWidget(pushButtonBlue)

toggleButtonLayout = QHBoxLayout()
mainLayout.addLayout(toggleButtonLayout)

toggleButtonRed = QPushButton("Toggle Red")
toggleButtonRed.setCheckable(True)
toggleButtonRed.setStyleSheet("background-color: red; color: white; font-size: 24px; padding:10;")
toggleButtonRed.setFixedSize(150,50)
def toggleRed(checked):
    if checked:
        label.setText("Red Toggle ON")
        label.setStyleSheet("color: red; font-size: 24px; padding:10;")
    if not checked:
        label.setText("Red Toggle OFF")
        label.setStyleSheet("color: red; font-size: 24px; padding:10;")

toggleButtonRed.toggled.connect(toggleRed)
toggleButtonLayout.addWidget(toggleButtonRed)


#toggleButtonLayout = QHBoxLayout()
mainLayout.addLayout(toggleButtonLayout)

toggleButtonGreen = QPushButton("Toggle Green")
toggleButtonGreen.setCheckable(True)
toggleButtonGreen.setStyleSheet("background-color: green; color: white; font-size: 18px; padding:10;")
toggleButtonGreen.setFixedSize(150,50)
def toggleGreen(checked):
    if checked:
        label.setText("Green Toggle ON")
        label.setStyleSheet("color: green; font-size: 24px; padding:10;")
    if not checked:
        label.setText("Green Toggle OFF")
        label.setStyleSheet("color: green; font-size: 24px; padding:10;")

toggleButtonGreen.toggled.connect(toggleGreen)
toggleButtonLayout.addWidget(toggleButtonGreen)

#toggleButtonLayout = QHBoxLayout()
mainLayout.addLayout(toggleButtonLayout)

toggleButtonBlue = QPushButton("Toggle Blue")
toggleButtonBlue.setCheckable(True)
toggleButtonBlue.setStyleSheet("background-color: Blue; color: white; font-size: 18px; padding:10;")
toggleButtonBlue.setFixedSize(150,50)
def toggleBlue(checked):
    if checked:
        label.setText("Blue Toggle ON")
        label.setStyleSheet("color: blue; font-size: 24px; padding:10;")
    if not checked:
        label.setText("Blue Toggle OFF")
        label.setStyleSheet("color: blue; font-size: 24px; padding:10;")

toggleButtonBlue.toggled.connect(toggleBlue)
toggleButtonLayout.addWidget(toggleButtonBlue)

mainLayout.addStretch()
window.show()
sys.exit(app.exec_())