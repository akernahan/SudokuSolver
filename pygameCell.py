# holds pygame rect parameters

class PygameCell:

    def __init__(self, w, h, offset_w, offset_h):
        self.num = 0
        self.width = w
        self.height = h
        self.off_w = offset_w
        self.off_h = offset_h
    
    def setNum(self, n):
        self.num = n