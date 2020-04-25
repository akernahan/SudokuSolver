import sys
from gui import SudokuGUI, GuiTile

class Sudoku:

    def __init__(self, path, display):
        self.size = 9
        self.path = path
        self.board = [[0 for x in range(9)] for y in range(9)]
        self.createBoard()
        self.count = 0

        self.display = display
        self.gui = None


    # add exception handeling
    def createBoard(self):
        with open(self.path, "r") as f:
            t = f.readlines()
        
        for x in range(self.size):
            for y in range(self.size):
                self.board[x][y] = int(t[x][y])


    def createScreen(self):
        self.gui = SudokuGUI()
        self.gui.initScreen()


    
    # solves puzzles without displaying it on screen
    def solveBacktrack(self):
        self.count += 1
        pass

    # solves on screen
    def displayGui(self):
        pass
    
    def checkIfSafe(self, row, col, n):
        if not self.validRow(row, n):
            return False
        if not self.validCol(col, n):
            return False
        if not self.validBox(row, col, n):
            return False
        return True
    
    def validRow(self, row, n):
        for i in range(self.size):
            if (self.board[row][i] == n):
                return False
        return True

    def validCol(self, col, n):
        for i in range(self.size):
            if (self.board[i][col] == n):
                return False
        return True

    def vaildBox(self, row, col, n):
        siz = self.size // 3
        box_row = (row // 3) * 3
        box_col = (col // 3) * 3
        for x in range(siz):
            for y in range(siz):
                # print(self.board[box_row+x][box_col+y],end='')
                if (self.board[box_row+x][box_col+y] == n):
                    return False
            # print()
        return True

    def findEmpty(self):
        pass

    def printBoard(self):
        i = 0
        print(" -----------------------\n| ", end='')
        for row in self.board:
            j = 0
            for n in row:
                print("{} ".format(n), end='')
                if j == 2 or j == 5:
                    print("| ", end='')
                j += 1
            if i == 2 or i== 5:
                print("|\n|-------|-------|-------|\n| ", end='')
            elif i == 8:
                print("|")
            else:
                print("|\n| ", end='')
            i -=- 1 # spicy
        print(" -----------------------")


if __name__=="__main__":
    display = False
    s = Sudoku("puzzles/Beginner/0.txt", display)
    # s.printBoard()

    # loop until user closes gui
    # done = True
    # if display:
    #     done = False
    # while not done:
    #     for event in pygame.event.get()
    #         if (event = pygame.QUIT):
    #             sys.exit()
        
    #     s.