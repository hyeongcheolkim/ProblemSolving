# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week13_03

from tkinter import *
from tkinter import messagebox

def keyEvent(event):
    res = "눌린키 : "
    if(event.keycode == 37):
        res += "Shift + 왼쪽 화살표"
    if(event.keycode ==38):
        res += "Shift + 위쪽 화살표"
    if(event.keycode ==39):
        res += "Shift + 오른쪽 화살표"
    if(event.keycode ==40):
        res += "Shift + 아래쪽 화살표"
    messagebox.showinfo("키보드 이벤트", res)

window=Tk()
window.bind("<Shift-Up>",keyEvent)
window.bind("<Shift-Down>",keyEvent)
window.bind("<Shift-Left>",keyEvent)
window.bind("<Shift-Right>",keyEvent)
window.mainloop()