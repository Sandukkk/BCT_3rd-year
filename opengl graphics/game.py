import pygame as pg
from OpenGL.GL import *

class App:
    def __init__(self):
        pg.init()
        pg.display.set_mode((640, 480), pg.OPENGL | pg.DOUBLEBUF)
        self.clock = pg.time.Clock()
        glClearColor(3, 0.2, 0.2, 1)
        self.running = True

    def mainloop(self):
        while self.running:
            self.handle_events()
            self.update()
            self.render()
            self.clock.tick(60)

    def handle_events(self):
        for event in pg.event.get():
            if event.type == pg.QUIT:
                self.running = False

    def update(self):
        pass

    def render(self):
        glClear(GL_COLOR_BUFFER_BIT)
        pg.display.flip()

    def quit(self):
        pg.quit()


if __name__ == "__main__":
    myApp = App()
    myApp.mainloop()
    myApp.quit()

