from PyQt6.QtCore import Qt, QRect, QSize, QMetaObject
from PyQt6.QtGui import QCursor, QFont, QIcon
from PyQt6.QtWidgets import QApplication, QMainWindow, QPushButton, QTextBrowser, QWidget, QFrame


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi()

    def setupUi(self):
        self.setObjectName("MainWindow")
        self.resize(487, 490)
        font = QFont()
        font.setBold(False)
        self.setFont(font)
        self.setFocusPolicy(Qt.FocusPolicy.NoFocus)
        self.setStyleSheet("background-color:rgb(37, 42, 51);")
        self.setWindowFlags(Qt.WindowType.WindowCloseButtonHint | Qt.WindowType.WindowMinimizeButtonHint)

        self.centralwidget = QWidget(self)
        self.centralwidget.setObjectName("centralwidget")
        self.centralwidget.setStyleSheet("background-color:rgb(37, 42, 51);")
        self.setCentralWidget(self.centralwidget)

        self.pushButton = QPushButton(self.centralwidget)
        self.pushButton.setObjectName("pushButton")
        self.pushButton.setGeometry(QRect(10, 10, 461, 121))
        self.pushButton.setToolTipDuration(-17)
        icon = QIcon()
        icon.addFile("logo.png", QSize(), QIcon.Mode.Normal, QIcon.State.Off)
        self.pushButton.setIcon(icon)
        self.pushButton.setIconSize(QSize(400, 500))
        self.pushButton.setFlat(True)

        self.textBrowser = QTextBrowser(self.centralwidget)
        self.textBrowser.setObjectName("textBrowser")
        self.textBrowser.setGeometry(QRect(20, 130, 451, 411))
        self.textBrowser.viewport().setCursor(QCursor(Qt.CursorShape.ArrowCursor))
        self.textBrowser.setFrameShape(QFrame.Shape.NoFrame)
        self.textBrowser.setLineWidth(0)
        self.textBrowser.setHtml("""
            <p style='font-size:11pt; font-weight:700;'>Windows Specifications</p>
            <p><span style='font-weight:700;'>Edition </span>Windows 12 Concept</p>
            <p><span style='font-weight:700;'>Version </span>25H2</p>
            <p><span style='font-weight:700;'>Build </span>2025.1234</p>
            <p style='font-size:11pt; font-weight:700;'>Legal</p>
            <p>The software is provided "as is", without any warranty of any kind, express or implied. This includes, but is not limited to, warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claims, damages, or other liabilities, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the software or the use or other dealings in the software.</p>
            <p>This software is a conceptual theme and is not affiliated with, endorsed by, or in any way connected to <a href='https://microsoft.com'>Microsoft Inc.</a> or its related projects.</p>
            <p>This project is licensed under the <a href='https://github.com/jthweb/windows-12/license'>GNU General Public License v3.0</a>. You are free to modify and distribute this software as long as you keep the same license and credit the <a href='https://www.github.com/jthweb'>creator</a>.</p>
        """)

        QMetaObject.connectSlotsByName(self)


if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
