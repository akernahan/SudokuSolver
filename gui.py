# screen will always be a square

import pygame
import sys
import time

# Colours
BLACK = (0,0,0)
WHITE = (255,255,255)
RED = (255,0,0)
GREEN = (0,255,0)

# some global variables
sudokuSize = 9

class SudokuGUI:
    
    def __init__(self, size=1):
        self.board = [[0 for x in range(9)] for y in range(9)]
        self.blockSize = 20 * size
        self.blockMargin = 2 * size
        self.boxMargin = 5 * size
        self.screenSize = self.blockSize*sudokuSize + self.blockMargin*sudokuSize + 2*4
        self.screen = None
        self.solved = False

    # initalises screen
    def initScreen(self):
        pygame.init()
        self.screen = pygame.display.set_mode((self.screenSize, self.screenSize))
        pygame.display.set_caption("Sudoku")
        



if __name__=="__main__":
    s = SudokuGUI(2)
    s.initScreen()

    clock = pygame.time.Clock()

    # loop until user exits
    done = False
    while not done:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
                #done = True
        
        # makes screen black
        s.screen.fill(BLACK)

        # add sudoku grid
        for x in range(sudokuSize):
            for y in range(sudokuSize):
                x_mar = 3
                y_mar = 3
                if x == 3 or x == 6:
                    x_mar += 2
                if y == 3 or y == 6:
                    y_mar += 2
                off_width = (s.blockSize + s.blockMargin)*x + s.blockMargin + x_mar
                off_height = (s.blockSize + s.blockMargin)*y + s.blockMargin + y_mar
                loc = [off_width, off_height, s.blockSize, s.blockSize]
                pygame.draw.rect(s.screen, WHITE, loc)

        # update the screen
        pygame.display.flip()

        # fps limit
        clock.tick(30)

# clase the window and quit
pygame.quit()

        
        
