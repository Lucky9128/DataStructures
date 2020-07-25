
import functools as ft


def MapFuncAgr(n):
    return 100-n



lst = [x**2 for x in range(0,10)]
print(lst)

para = ["Hello brother.","how are you","I am all good","how is your job0","Everyting is fine"]
single=[]
#one way
for sent in para:
    for word in sent.split(" "):
        single.append(word)
print(single)

single2 = [word for sent in para for word in sent.split(" ")]
print(single2)

# string number to int number
lst2 = ['1','23','54','45']
lst3 = list(map(lambda x: int(x),lst2))
lst4 = list(map(int,lst2))
print(lst3)
print(lst4)


#reduce function in python
"""
At first step, first two elements of sequence are picked and the result is obtained.
Next step is to apply the same function to the previously attained result and the number just succeeding the second element and the result is again stored.
This process continues till no more elements are left in the container.
The final returned result is returned and printed on console
"""

lst5 = [1,2,3,4,5,6,7]
print(ft.reduce(lambda a,b :a if a>b else b,lst5))
print(ft.reduce(lambda a,b :a+b,lst5))


#matrix row to col
matrix = [[1,2,3],[4,5,6],[7,8,9]]

lst6 = [[row[i] for row in matrix] for i in range(3)]
print(lst6)


Squ_dict = {x:x**2 for x in range(10)}
print(Squ_dict)

Squ_even = {x:y for x,y in Squ_dict.items() if x%2==0}
print(Squ_even)

#map function takes a two arguments : i-> function, ii-> iterative data type

print(map(lambda x:x**2,lst5))
print(list(map(lambda x:x**2,lst5)))
print(list(map(MapFuncAgr,lst5)))

lst1_1 = [1,2,3,4]
lst1_2 = [4,3,2,1]
print(list(map(lambda x,y:x+y,lst1_1,lst1_2)))

#filter is similar to map but it requries a condition