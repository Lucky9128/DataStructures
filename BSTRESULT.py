
# import matplotlib.pyplot as plt


# f1 = open("By Iteration.txt","r")
# f2 = open("By Recursion.txt","r")
# lst1 = f1.readlines()
# lst2 = f2.readlines()
# f1.close()
# f2.close()

# lst3=[]
# for i in lst1:
# 	lst3.append(i.split(" "))
# for i in range(len(lst3)):
# 	lst3[i][-1] = lst3[i][-1][:-1]
# x_axs= []
# y_axs = []
# for i in range(len(lst3)):
# 	x_axs.append(int(lst3[i][0]))
# for i in range(len(lst3)):
# 	y_axs.append(float(lst3[i][1]))



# lst4=[]
# for i in lst2:
# 	lst4.append(i.split(" "))
# for i in range(len(lst4)):
# 	lst4[i][-1] = lst4[i][-1][:-1]
# x_axs2= []
# y_axs2 = []
# for i in range(len(lst4)):
# 	x_axs2.append(int(lst4[i][0]))
# for i in range(len(lst4)):
# 	y_axs2.append(float(lst4[i][1]))



# print(lst3)
# print(x_axs)
# print(y_axs)

# plt.plot(x_axs,y_axs,color='blue')
# plt.scatter(x_axs2,y_axs2,color='red')
# plt.title("Red : Recursion\n Blue:Iteration")
# plt.xlabel("Number of Nodes")
# plt.ylabel("Time in seconds")
# plt.show()


# from random import randint as rt
import numpy as np
# lst= []
# for i in range(100):
# 	lst.append(rt(1,60))
# print(set(lst))

arr = np.array([1,2,3,4])
arr = arr**2
print(arr)