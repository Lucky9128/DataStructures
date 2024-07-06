
def merge(lst,l,m,r):
    n1 = m-l+1
    n2 = r-m
    ll = []
    rl = []

    for i in range(n1):
        ll.append(lst[l+i])
    for i in range(n2):
        rl.append(lst[m+i+1])
    i=0
    j=0
    k=l
    while k<=r and i<n1 and j<n2:
        if ll[i]<=rl[j]:
            lst[k]=ll[i]
            i+=1
        else:
            lst[k]=rl[j]
            j+=1
        k+=1

    while k<=r:
        if i<n1:
            lst[k]=ll[i]
            k+=1
            i+=1
        if j<n2:
            lst[k]=rl[j]
            k+=1
            j+=1


def mergeSort(lst,l,r):
    m = int((l+r)/2)
    if (r-l)>0:
        mergeSort(lst,l,m)
        mergeSort(lst,m+1,r)
        merge(lst,l,m,r)


lst = [710,827,383,986,350,259,135,595,890,44,776,489,408,437,218,738,334,394,954,418,925,922,778,777,716,563,252,110,556,538,97,707,542,792,614,613,885,257,961,266,652,604,89,118,390,609,736,449,268,639,170,7,142,761,398,382,267,642,943,530,169,173,920,292,602,945,393,234,969,822]
mergeSort(lst,0,len(lst)-1)
print(lst)






