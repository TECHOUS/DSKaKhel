#Making List l
l = [11, 12, 13, 14]
	
#Using append function on list	
l.append(50)	
l.append(60)	
print("list after adding 50 & 60:-  ", l)	

#Using remove function on list	
l.remove(11)	
l.remove(13)	
print("list after removing 11 & 13:-  ", l)	

#Using the sort function with their parameters changed	
#Implementing sorting in a list
l.sort(reverse=False)	
print("list after sortinng in ascending order:-  ",l)	
l.sort(reverse=True)	
print("list after sorting in descending order:-  ",l)	

#Implementing searching in a list
if 13 in l:	
  print("yes 13 is in the list")	  
else:	
    print("no 13 is not in the list")	    
print("no of elements list have:- ",len(l))	

#Implementing traversing in a list
s = 0	
oddsum = 0	
evensum = 0
primesum = 0	
for i in l:	
    s = s + i	    
    if i % 2 == 0:	    
        evensum = evensum + i	        
    else:	    
          oddsum = oddsum + i	          
    count = 0	    
    j = 1	    
    while( j < len(l)):	   
        if l[j] % j == 0:	        
            count = count + 1	            
    if count == 2:	    
        primesum = primesum + l[i]	       
print("sum of elements in the list:-  ",s)	
print("sum of odd elements in the list:-  ",oddsum)	
print("sum of even elements in the list:-  ",evensum)	
print("sum of prime elements in the list:- ",primesum)	

#Using clear function to delete all the data in list 	 
#Implementing delete functionality in a list by using predefined  functions
l.clear()	
print("list after using clear function:-  ",l)	
del l
