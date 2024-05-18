import sys
from PyQt5.QtWidgets import QApplication, QMainWindow
import serial
from PyQt5 import QtCore, uic

qtCreatorFile = "interface2.ui"  # Nombre del archivo .ui
Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)

class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.ConectarArduino()
        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self.update_label)
        self.timer.start(500)

    def update_label(self):
        if self.serial_port.in_waiting > 0:
            distance = self.serial_port.readline().decode('utf-8').strip()
            self.label.setText(f"Distance: {distance} cm")

    def ConectarArduino(self):
        try:
            self.arduino = serial.Serial("COM4", 9600)
            if self.arduino != None:
                print("Puerto conectado con Exito")
        except:
            print("No se pudo conectar")
            self.arduino = None



if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_())
