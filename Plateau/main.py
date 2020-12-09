from kivy.app import App
from kivy.uix.button import Button
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.core.window import Window
from kivy.config import ConfigParser
from kivy.metrics import dp
from datetime import datetime
import os
import time
import threading
from kivy.clock import Clock
from kivy.graphics import Color, Ellipse, Rectangle
from kivy.core.window import Window

#set window size to 600 600 and center the window
t=Window.top
Window.maximize()
w,h=Window.width,Window.height
Window.size = (600, 600)
Window.left=(w-600)/2
Window.top=t

#make window no resizeable
from kivy.config import Config
Config.set('graphics','resizeable',0)

#input from file
with open("card.txt","r") as f:
    strokes=f.readlines()
    h,w=int(strokes[0].split(' ')[1]),int(strokes[0].split(' ')[2])
    array=[]
    for i in range(1,h+1):
        num=int(strokes[i].split(' ')[0])
        stroke=strokes[i].split(' ')[1].lower()
        array.append([])
        for i1 in range(w):
            array[num].append(stroke[i1])


#card visualisation
class MainScreen(Screen):
    def __init__(self,w,h,array,**kw):
        super(MainScreen, self).__init__(**kw)
        self.array=array
        self.card=[]
        
        winW=Window.width
        rw=winW/w#rectangles width
        winH=Window.height
        rh=winH/h#rectangles height
        # rh=rw=min(rh,rw)
        print(array)
        with self.canvas:
            for y in range(h):
                self.card.append([])
                for x in range (w):
                    if (array[y][x] == "x"):
                        Color(1, 0, 0, 1)
                    elif (array[y][x] == 'o'):
                        Color(0, 0, 1, 1)
                    else:
                        Color(.75, .75, .75, 1)
                    self.card[-1].append(Rectangle(
                    pos=((x*rw),Window.height-(y*rh)-rh),
            size=(rw/1.01,rh/1.01)))
        th=threading.Thread(name='1',target=self.update,args=[rw,rh])
        th.start()
    def update(self,rw,rh):
        while True:
            try:
                print()
                s=input()
                h, w = int(s.split(' ')[1]), int(s.split(' ')[2])
                array=[]
                for i in range(h):
                    s=input()
                    num = int(s.split(' ')[0])
                    stroke = s.split(' ')[1].lower()
                    array.append([])
                    for i1 in range(w):
                        array[num].append(stroke[i1])
                for y in range(h):
                    for x in range(w):
                        if self.array[y][x]!=array[y][x]:
                            self.array[y][x]=array[y][x]
                            with self.canvas:
                                if (array[y][x] == "x"):
                                    Color(1, 0, 0, 1)
                                elif (array[y][x] == 'o'):
                                    Color(0, 0, 1, 1)
                                else:
                                    Color(.75, .75, .75, 1)
                                self.card[y][x]=Rectangle(
                                    pos=((x * rw), Window.height - (y * rh) - rh),
                                    size=(rw / 1.01, rh / 1.01))
            except:pass




#some extra class       
class MScreenManager(ScreenManager):  
    def __init__(self, args={},**kwargs):
        super(MScreenManager, self).__init__(**kwargs)
        #Clock.schedule_interval(self.check_sound,1)
  
  
sm = MScreenManager()
sm.add_widget(MainScreen(w,h,array,name='main'))


#main class
class PlateauApp(App):
    def __init__(self, **kvargs):
        super(PlateauApp, self).__init__(**kvargs)
    def set_screen(self,name_screen):
        sm.current = name_screen
    def build(self):
        self.set_screen('main')
        return sm

if __name__ == '__main__':
    PlateauApp().run()