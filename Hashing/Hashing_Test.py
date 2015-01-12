from Hashing import Hashing
from doubleHashing import doubleHashing
import random
#############################################

i = 1
idouble = 1 
times_through = 0
size_array = 5
x = 0 
n = 0
while times_through < 5:
    if times_through >= 1:
        size_array *= 2
    myHash = Hashing(size_array)
    myArray = []     
    doubleHash = doubleHashing(size_array)    
    doubleArray = []
    myArray = random.sample(xrange(101), size_array/2)
    doubleArray = myArray
    print ''    
    print "Size of array:"
    print size_array
    print ''
    print 'Items inserted and hash value'
    print ''
    print '['
    for each in myArray:
        myHash[each] = i
        i += 1
    print ']'
    print ''
    print 'Items currently in hash table'
    print ''
    print '['
    for item in myHash.table:
        print item
    print ']'
    print myHash.size
    print ''
    #print 'Testing delete function'
    #print ''
    #myHash.__delItem__(14)
    #print '['
    #for item in myHash.table:
    #    print item
    #print ']'
    #print myHash.size
    #print ''
    #print 'Testing get function'
    #print ''
    #myHash.__getItem__(10)
    #print ''
    print 'Largest Cluster'
    for each in myHash.table:
        if each != None:
            if each == '*':
                x = 0
            else:
                x += 1
                if x > n:
                    n = x                
        elif each == None:
            x = 0
    print n
    
    
    #############################################
    print ''
    print 'Double Hashing'
    print ''
    print 'Items inserted and double hashed value'
    print '(New pos means the last value was double hashed)'
    print '['
    for each in doubleArray:
          doubleHash[each] = i
          idouble += 1
    print ']'
    print ''
    print 'Items currently in hash table'
    print ''    
    print '['
    for item in doubleHash.table:
          print item
    print ']'
    print doubleHash.size
    print ''
    #print 'Testing delete function'
    #print ''
    #doubleHash.__delItem__(21)
    #print '['
    #for item in doubleHash.table:
    #      print item
    #print ']'
    #print doubleHash.size
    #print ''
    #print 'Testing get function'
    #print ''
    #doubleHash.__getItem__(14)
    print 'Largest Double Cluster'
    print ''
    x = 0 
    n = 0
    for each in doubleHash.table:
          if each != None:
                if each == '*':
                   x = 0
                else:
                   x += 1
                   if x > n:
                       n = x                
          elif each == None:
                x = 0
    print n
    
    
    times_through += 1
   