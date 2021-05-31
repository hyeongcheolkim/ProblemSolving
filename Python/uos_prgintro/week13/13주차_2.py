# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week13_02

from tkinter import *
from time import *
import os

fnameList = [
    "jeju1.gif",
    "jeju2.gif",
    "jeju3.gif",
    "jeju4.gif",
    "jeju5.gif",
    "jeju6.gif",
    "jeju7.gif",
    "jeju8.gif",
    "jeju9.gif",
]
phothoList = [None] * 9
num = 0

def clickNext():
    global num, btnnow
    num += 1
    if num > 8:
        num = 0
    photo = PhotoImage(
        file=os.path.dirname(os.path.realpath(__file__)) + "/" + fnameList[num]
    )
    pLabel.configure(image=photo)
    pLabel.image = photo
    btnnow.configure(text=fnameList[num])

def clickPrev():
    global num, btnnow
    num -= 1
    if num < 0:
        num = 8
    photo = PhotoImage(
        file=os.path.dirname(os.path.realpath(__file__)) + "/" + fnameList[num]
    )
    pLabel.configure(image=photo)
    pLabel.image = photo
    btnnow.configure(text=fnameList[num])


window = Tk()
window.geometry("700x500")
window.title("사진 앨범 보기")

btnPrev = Button(window, text="<< 이전", command=clickPrev)
btnNext = Button(window, text="다음 >>", command=clickNext)
btnnow = Button(window, text=fnameList[0])

photo = PhotoImage(
    file=os.path.dirname(os.path.realpath(__file__)) + "/" + fnameList[0]
)
pLabel = Label(window, image=photo)

btnPrev.place(x=250, y=10)
btnNext.place(x=400, y=10)
btnnow.place(x=325, y=10)
pLabel.place(x=15, y=50)

window.mainloop()
