import sys
import os
import shutil
import webbrowser
from PySide6.QtCore import Qt, QUrl, QMimeData, QPropertyAnimation
from PySide6.QtGui import QIcon, QDragEnterEvent, QDropEvent, QDrag, QFont
from PySide6.QtWidgets import QApplication, QWidget, QLabel, QVBoxLayout, QListWidget, QListWidgetItem, QHBoxLayout, QPushButton, QFrame
from qfluentwidgets import LineEdit

USER_DOCS = os.path.expanduser("~/Documents/dgdr")
if not os.path.exists(USER_DOCS):
    os.makedirs(USER_DOCS)

class RunApp(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowFlags(Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint)
        self.setAttribute(Qt.WA_TranslucentBackground)
        self.setFixedSize(420, 320)
        self.move_to_top_right()
        
        self.initUI()
        self.populateFileList()
        self.animate_popup()
        
    def move_to_top_right(self):
        screen_geometry = QApplication.primaryScreen().geometry()
        self.move(screen_geometry.width() - self.width() - 10, 10)
        
    def initUI(self):
        main_layout = QVBoxLayout(self)
        
        # Outer Frame with Background Color
        self.frame = QFrame(self)
        self.frame.setStyleSheet("border-radius: 15px; background-color: #252a33; padding: 10px;")
        self.frame.setFixedSize(400, 300)
        frame_layout = QVBoxLayout(self.frame)

        # Header Layout
        header_layout = QHBoxLayout()
        
        self.runButton = QPushButton(self.frame)
        self.runButton.setIcon(QIcon("Run.ico"))
        self.runButton.setStyleSheet("border: none; background: transparent;")
        self.runButton.setIconSize(self.runButton.sizeHint() * 2)
        self.runButton.setFixedSize(65, 65)
        header_layout.addWidget(self.runButton)
        
        self.lineEdit = LineEdit(self.frame)
        self.lineEdit.setPlaceholderText("Run command...")
        self.lineEdit.returnPressed.connect(self.execute_command)
        self.lineEdit.setStyleSheet("font-size: 14px;")
        header_layout.addWidget(self.lineEdit, 1)  # Stretch
        
        # Close Button
        close_button = QPushButton("❌", self.frame)
        close_button.setStyleSheet("border: none; font-size: 18px; background: transparent;")
        close_button.setFixedSize(40,40)
        close_button.clicked.connect(self.close)
        header_layout.addWidget(close_button)
        
        frame_layout.addLayout(header_layout)
        
        # File List
        self.fileList = QListWidget(self.frame)
        self.fileList.setViewMode(QListWidget.IconMode)
        self.fileList.setSpacing(10)
        self.fileList.setAcceptDrops(True)
        self.fileList.setDragEnabled(True)
        self.fileList.setDropIndicatorShown(True)
        self.fileList.setStyleSheet("border-radius: 10px; background-color: #2f3640; color: white; text-align: center;")
        self.fileList.itemPressed.connect(self.startDrag)
        frame_layout.addWidget(self.fileList)
        
        main_layout.addWidget(self.frame)
        self.setLayout(main_layout)
        self.setAcceptDrops(True)
    
    def execute_command(self):
        cmd = self.lineEdit.text()
        if cmd:
            if os.path.exists(cmd) or shutil.which(cmd):
                os.system(cmd)
            else:
                webbrowser.open(f"https://www.duckduckgo.com/?q={cmd}")
        self.lineEdit.clear()
        
    def dragEnterEvent(self, event: QDragEnterEvent):
        if event.mimeData().hasUrls():
            event.acceptProposedAction()
    
    def dropEvent(self, event: QDropEvent):
        for url in event.mimeData().urls():
            file_path = url.toLocalFile()
            dest_path = os.path.join(USER_DOCS, os.path.basename(file_path))
            shutil.move(file_path, dest_path)
        self.populateFileList()
    
    def populateFileList(self):
        self.fileList.clear()
        files = os.listdir(USER_DOCS)
        if not files:
            empty_item = QListWidgetItem("Drop Files Here")
            empty_item.setTextAlignment(Qt.AlignCenter)
            font = QFont("Segoe UI")  # Using Segoe UI font
            font.setPointSize(12)
            empty_item.setFont(font)
            self.fileList.addItem(empty_item)
        else:
            for file in files:
                item = QListWidgetItem(os.path.basename(file))
                file_path = os.path.join(USER_DOCS, file)
                icon = QIcon(file_path) if file.endswith(".lnk") or os.path.isfile(file_path) else QIcon.fromTheme("folder")
                item.setIcon(icon)
                self.fileList.addItem(item)
    
    def startDrag(self):
        selected_item = self.fileList.currentItem()
        if selected_item:
            file_path = os.path.join(USER_DOCS, selected_item.text())
            if os.path.exists(file_path):
                drag = QDrag(self)
                mime_data = QMimeData()
                mime_data.setUrls([QUrl.fromLocalFile(file_path)])
                drag.setMimeData(mime_data)
                drag.exec(Qt.CopyAction)
                os.remove(file_path)
    
    def animate_popup(self):
        self.animation = QPropertyAnimation(self, b"windowOpacity")
        self.animation.setDuration(450)
        self.animation.setStartValue(0)
        self.animation.setEndValue(1)
        self.animation.start()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = RunApp()
    window.show()
    sys.exit(app.exec())
