

i=10000
temp = i
lst = set()
while temp % 13 != 0:
    lst.add(temp)
    print(temp%13,end=" ")
    temp = (temp+i)%13
print()
print(len(lst))