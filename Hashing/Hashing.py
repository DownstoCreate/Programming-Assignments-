class Hashing():
    
    def __init__(self,size):
        self.array_size = size
        self.table = self.array_size * [None]
        self.size = 0
        self.keyList = []

    def _hash(self,key):
        pos = key
        print key, " ", pos % self.array_size
        return pos % self.array_size

    def doubleSize(self,_size):
        self.array_size = _size
        self.table = (self.array_size) * [None]
        value = 0
        self.size = 0
        #while self.keyList != None:
        for each in self.keyList:
            pos = self._hash(each)
            while True:
                if self.table[pos] is not None:
                    if self.table[pos][0] == each:
                        self.table[pos] = (each,value)
                        break
                else:
                    self.table[pos] = (each,value)
                    self.size += 1
                    value += 1
                    break
                pos = (pos + 1) % self.array_size
        
            
    def __setitem__(self,key,value):
        if self.size > self.array_size/2:
            self.doubleSize(self.array_size*2)
        pos = self._hash(key)
        while True:
            if self.table[pos] is not None:
                if self.table[pos][0] == key:
                    self.table[pos] = (key)
                    return
            else:
                self.table[pos] = (key,value)
                self.keyList.append(key)
                self.size += 1
                return
            pos = (pos + 1) % self.array_size
            
        
    def __delItem__(self,key):
        pos = self._hash(key)
        start = pos
        while True:
            if self.table[pos] is not None:
                if self.table[pos][0] == key:
                    self.table[pos] = '*'
                    self.size -= 1
                    return
            pos = (pos + 1) % self.array_size
            if pos == start:
                raise KeyError(key)
            
    def __getItem__(self,key):
        pos = self._hash(key)
        start = pos
        while True:
            if self.table[pos] is not None:
                if self.table[pos][0] == key:
                    return self.table[pos][1]
            pos = (pos + 1) % self.array_size
            if pos == start:
                raise KeyError(key)
                         
 
            