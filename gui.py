# screen will always be a square

import pygame
import sys
import time
from pygameCell import PygameCell

# Colours
BLACK = (0,0,0)
WHITE = (255,255,255)
GREY = (124,124,124)
RED = (255,0,0)
GREEN = (0,255,0)

# some global variables
sudokuSize = 9

class SudokuGUI:

    def __init__(self, board=None):
        if board is None:
            self.board = [[0 for x in range(9)] for y in range(9)]
        else:
            self.board = board
        self.screenSize = 450
        self.screen = None
        self.clock = pygame.time.Clock()
        self.tiles = [[0 for x in range(9)] for y in range(9)]


    # initalises screen
    def initScreen(self):
        pygame.init()
        self.screen = pygame.display.set_mode((self.screenSize, self.screenSize))
        pygame.display.set_caption("Sudoku")
        self.initTiles(self.board)
    
    def initTiles(self, board):
        gap = self.screenSize / 9
        for x in range(sudokuSize):
            for y in range(sudokuSize):
                self.tiles[x][y] = GuiTile(x, y, gap, board[x][y])

        # self.tiles[4][4].select()

    def draw(self):
        self.drawLines()
        for t1 in self.tiles:
            for t2 in t1:
                t2.draw(self.screen)

    # draws lines on screen
    def drawLines(self):
        gap = self.screenSize / 9
        for i in range(1,sudokuSize):
            thick = 2
            if i % 3 == 0:
                thick = 4
            pygame.draw.line(self.screen, BLACK, (0,i*gap), (self.screenSize, i*gap), thick)
            pygame.draw.line(self.screen, BLACK, (i*gap,0), (i*gap,self.screenSize), thick)
    



class GuiTile:

    def __init__(self, row, column, gap, value):
        self.row = row
        self.col = column
        self.x = gap*row  # x_offset
        self.y = gap*column  # y_offset
        self.gap = gap
        self.val = value
        self.fnt = pygame.font.SysFont("trebuchetms", 35)
        self.highlight = False
        
        self.og = False
        if (value > 0):
            self.og = True

    def draw(self, screen):
        # choose text colour
        colour = GREY
        if self.og:
            colour = BLACK
        text = self.fnt.render(str(self.val), 1, colour)
        screen.blit(text, (self.x+15,self.y+5))
        
        if self.highlight:
            self.drawHighlights(screen)

    def drawHighlights(self, screen):
        thick = 5
        pygame.draw.line(screen, RED, (self.x, self.y), (self.x+self.gap, self.y), thick)
        pygame.draw.line(screen, RED, (self.x+self.gap, self.y), (self.x+self.gap, self.y+self.gap), thick)
        pygame.draw.line(screen, RED, (self.x, self.y), (self.x, self.y+self.gap), thick)
        pygame.draw.line(screen, RED, (self.x, self.y+self.gap), (self.x+self.gap, self.y+self.gap), thick)

    def select(self):
        self.highlight = True

    def deselct(self):
        self.highlight = False    

    def setVal(self, n):
        self.val = n
    
    # set if already given
    def setOG(self):
        self.og = True
    

        

if __name__=="__main__":
    s = SudokuGUI()
    s.initScreen()

    # clock = pygame.time.Clock()

    # loop until user exits
    done = False
    while not done:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
                #done = True
        
        # makes screen white
        s.screen.fill(WHITE)

        # draw 
        s.draw()

        # update the screen (use pygame.display.update(rect_list) for more efficiency)
        pygame.display.flip()

        # fps limit
        s.clock.tick(30)

# clase the window and quit
pygame.quit()

        
        
