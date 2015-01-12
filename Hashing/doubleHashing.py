class doubleHashing():
    
    def __init__(self,size = 10):
        self.array_size = size
        self.table = self.array_size * [None]
        self.size = 0
        self.keyList = []
        self.primeNum = 5
        self.x = 1

    def _hash(self,key):
        pos = key
        print key, " ", pos % self.array_size
        return pos % self.array_size

    def doubleSize(self,_size):
        self.array_size = _size
        self.table = (self.array_size) * [None]
        value = 0
        self.size = 0
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
                self.primeNumber(self.primeNum)
                print 'New pos',self.primeNum
                pos = (self.primeNum -(pos % self.primeNum)) % self.array_size
        
            
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
            self.primeNumber(self.primeNum)
            print 'New pos',self.primeNum
            pos = (self.primeNum -(pos % self.primeNum)) % self.array_size
            
            

            
    def primeNumber(self,n):
        for p in range(2, n+1):
            for i in range(2, p):
                if p % i == 0 or self.x == self.primeNum:
                    self.primeNum = n+1
                    self.primeNumber(self.primeNum)
                    return
                else:
                    self.primeNum = n
                    self.x = n
                    return self.primeNum
                
    def __delItem__(self,key):
            pos = self._hash(key)
            start = pos
            while True:
                if self.table[pos] is not None:
                    if self.table[pos][0] == key:
                        self.table[pos] = '*'
                        self.size -= 1
                        return
                self.primeNumber(self.primeNum)
                pos = (self.primeNum -(pos % self.primeNum)) % self.array_size
                if pos == start:
                    raise KeyError(key)
                
    def __getItem__(self,key):
            pos = self._hash(key)
            start = pos
            while True:
                if self.table[pos] is not None:
                    if self.table[pos][0] == key:
                        return self.table[pos][1]
                self.primeNumber(self.primeNum)
                pos = (self.primeNum -(pos % self.primeNum)) % self.array_size
                if pos == start:
                    raise KeyError(key)
        
   
         
    