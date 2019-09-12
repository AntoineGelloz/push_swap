#!/usr/bin/env python3

import sys
import time
import subprocess
import os
from math import sqrt
from tkinter import *

class visuClass:
    def __init__(self, window):
        window.title("push_swap")
        self.i = 0
        self.speed = 0
        program_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'push_swap')
        if (len(sys.argv) < 3):
            print('usage: python3 visualizer.py [NB1, NB2, ...] << 2 numbers minimum')
            sys.exit(0)
        if not (os.path.exists(program_path)):
            print('Error, push_swap program not found in this directory.')
            sys.exit(0)
        self.stack_a = [int(num) for num in sys.argv[1:]]
        self.first_pile = self.stack_a[:]
        self.stack_b = []
        self.instructions = subprocess.check_output([program_path] + sys.argv[1:], stderr=subprocess.STDOUT, timeout=12).splitlines()
        self.main_frame = Frame(window).pack()
        self.main_canvas = Canvas(self.main_frame, width=800, height=800, bg="white")
        self.main_canvas.pack()
        self.button_frame = Frame(self.main_frame)
        self.button_frame.pack()
        self.play_pause_button = Button(self.button_frame, text="go", command=self.play_pause, font=("monospace", 11), width=4)
        self.play_pause_button.grid(row=1, column=1)
        self.reset_button = Button(self.button_frame, text="reset", command=self.reset, font=("monospace", 11))
        self.reset_button.grid(row=1, column=2)
        self.speed_label = Label(self.button_frame, text='  |  speed ', font=("monospace", 11))
        self.speed_label.grid(row=1, column=3)
        self.speed_spinbox = Spinbox(self.button_frame, font=("monospace", 11), command=self.change_speed, from_=1, to=50, increment=1, width=3)
        self.speed_spinbox.grid(row=1, column=4)
        self.speed_spinbox.delete(0, "end")
        self.speed_spinbox.insert(0, "25")
        self.operations_label = Label(self.button_frame, text='  |  '+str(len(self.instructions))+' operations', font=("monospace", 11), width=22, anchor='w')
        self.operations_label.grid(row=1, column=5)
        self.progress_canvas = Canvas(self.main_frame, width=800, height=8, bg="white")
        self.progress_canvas.pack()
        self.draw_rectangles()

    def play_pause(self):
        if self.speed != 0:
            self.speed = 0
            self.play_pause_button.config(text='go')
        else:
            self.speed = 1 / int(self.speed_spinbox.get())
            self.play_pause_button.config(text='||')
            self.main()

    def reset(self):
        self.i = 0
        self.speed = 0
        del self.stack_a[:]
        self.stack_a = self.first_pile[:]
        del self.stack_b[:]
        self.main_canvas.delete("all")
        self.progress_canvas.delete("all")
        self.draw_rectangles()
        self.play_pause_button.config(text='go')

    def change_speed(self):
        if (self.speed != 0):
            self.speed = 1 / int(self.speed_spinbox.get())

    def exec_instructions(self, instruction):
        if instruction == b'sa' and len(self.stack_a) >= 2:
            self.stack_a[0], self.stack_a[1] = self.stack_a[1], self.stack_a[0]
        if instruction == b'sb' and len(self.stack_b) >= 2:
            self.stack_b[0], self.stack_b[1] = self.stack_b[1], self.stack_b[0]
        if instruction == b'ss':
            if (len(self.stack_a) >= 2):
                self.stack_a[0], self.stack_a[1] = self.stack_a[1], self.stack_a[0]
            if (len(self.stack_b) >= 2):
                self.stack_b[0], self.stack_b[1] = self.stack_b[1], self.stack_b[0]
        if instruction == b'ra' and len(self.stack_a) >= 2:
            self.stack_a.append(self.stack_a[0])
            del self.stack_a[0]
        if instruction == b'rb' and len(self.stack_b) >= 2:
            self.stack_b.append(self.stack_b[0])
            del self.stack_b[0]
        if instruction == b'rr':
            if (len(self.stack_a) >= 2):
                self.stack_a.append(self.stack_a[0])
                del self.stack_a[0]
            if (len(self.stack_b) >= 2):
                self.stack_b.append(self.stack_b[0])
                del self.stack_b[0]
        if instruction == b'rra' and len(self.stack_a) >= 2:
            self.stack_a = [self.stack_a[-1]] + self.stack_a
            del self.stack_a[-1]
        if instruction == b'rrb' and len(self.stack_b) >= 2:
            self.stack_b = [self.stack_b[-1]] + self.stack_b
            del self.stack_b[-1]
        if instruction == b'rrr':
            if (len(self.stack_a) >= 2):
                self.stack_a = [self.stack_a[-1]] + self.stack_a
                del self.stack_a[-1]
            if (len(self.stack_b) >= 2):
                self.stack_b = [self.stack_b[-1]] + self.stack_b
                del self.stack_b[-1]
        if instruction == b'pa' and len(self.stack_b) >= 1:
            self.stack_a = [self.stack_b[0]] + self.stack_a
            del self.stack_b[0]
        if instruction == b'pb' and len(self.stack_a) >= 1:
            self.stack_b = [self.stack_a[0]] + self.stack_b
            del self.stack_a[0]
        return self.stack_a, self.stack_b

    def set_color(self, index):
        color = '#%02x%02x%02x' % (int(255 * (index - 0.3) * (index > 0.3)),
                                   int(255 * index - ((510 * (index - 0.6)) * (index > 0.6))),
                                   int((255 - 510 * index) * (index < 0.5)))
        return color

    def draw_rectangles(self):
        vi = 0
        ww = 800
        wh = 800
        hw = ww / 2
        hm = len(self.stack_a) + len(self.stack_b)
        mx, mn = (0, 0)
        if (hm != 0):
            mx = max(self.stack_a + self.stack_b)
            mn = min(self.stack_a + self.stack_b)
        rects = []
        if len(self.stack_a) > 0:
            a_val = [(num - mn) / (mx - mn) for num in self.stack_a]
            for vala in a_val:
                rects.append(self.main_canvas.create_rectangle(hw - vala * hw - 1, vi,  hw, vi + wh / hm, fill=self.set_color(vala), outline=""))
                vi += wh / hm
        vi = 0
        if len(self.stack_b) > 0:
            b_val = [(num - mn) / (mx - mn) for num in self.stack_b]
            for valb in b_val:
                rects.append(self.main_canvas.create_rectangle(hw + 1, vi, hw + valb * hw + 1, vi + wh / hm, fill=self.set_color(valb), outline=""))
                vi += wh / hm

    def main(self):
        while self.i < len(self.instructions):
            if self.speed != 0:
                while self.i < len(self.instructions):
                    self.main_canvas.delete("all")
                    self.stack_a, self.stack_b = self.exec_instructions(self.instructions[self.i])
                    self.draw_rectangles()
                    time.sleep(self.speed)
                    self.main_canvas.update()
                    self.progress_canvas.delete("all")
                    self.progress_canvas.create_rectangle(0, 0, self.i / len(self.instructions) * 820, 8, fill='green', outline="")
                    self.operations_label.config(text='  |  '+str(self.i)+' / '+str(len(self.instructions))+' operations', anchor='w')
                    self.i += 1
                    if self.speed == 0:
                        break
            time.sleep(0.1)
            self.main_canvas.update()
        self.play_pause_button.config(text='go')
        self.operations_label.config(text='  |  '+str(len(self.instructions))+' operations', anchor='w')
        self.progress_canvas.create_rectangle(0, 0, 820, 8, fill='green', outline="")

window = Tk()
window.resizable(width=False, height=False)
visuInstance = visuClass(window)
window.mainloop()
