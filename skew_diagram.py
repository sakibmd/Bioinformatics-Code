import matplotlib.pyplot as plt

myStr = input("Enter Your String : ") #GAAGTCGCTCGGAC
StrLength = len(myStr)

# x axis values
x = [0]
# corresponding y axis values
y = [0]


i=0
for m in range(StrLength):
    if myStr[m]=='G':
        i=i+1
        y.append(i)
        x.append(m+1)
    elif myStr[m]=='C':
        i=i-1
        y.append(i)
        x.append(m + 1)
    elif myStr[m]=='T':
        y.append(i)
        x.append(m + 1)
    elif myStr[m]=='A':
        y.append(i)
        x.append(m + 1)


# plotting the points
plt.plot(x, y, color='green', linestyle='dashed', linewidth = 3,
      marker='o', markerfacecolor='blue', markersize=5)

# setting x and y axis range
plt.xlim(0,StrLength)
plt.ylim(-3, 3)

# naming the x axis
plt.xlabel('x - axis')
# naming the y axis
plt.ylabel('y - axis')

# giving a title to my graph
plt.title('Skew Diagram')

# function to show the plot
plt.show()
