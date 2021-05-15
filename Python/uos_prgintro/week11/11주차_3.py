# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week11_03

from tkinter import *
import os

window = Tk()
window.title("냥이들 ^^")
photo1 = PhotoImage(file=os.path.dirname(os.path.realpath(__file__))+"/cat.gif")
photo2 = PhotoImage(file=os.path.dirname(os.path.realpath(__file__))+"/cat2.gif")
label1 = Label(window, image = photo1)
label2 = Label(window, image = photo2)
label1.pack(side=LEFT)
label2.pack(side=LEFT)
window.mainloop()
