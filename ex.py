# # n=int(input())
# avengers=["wanda","thor","hulk","iron man","captain america"]
# # print(avengers)
# # for i in range (n):
# #     print(avengers)
# print(avengers[1])

t=int(input())
for j in range(t):
    def gcd(a, b):
        if(b == 0):
            return a
        else:
            return gcd(b, a % b)
    def isDivisible(x,y):
        if (y == 1):
            return 1
 
        z = gcd(x, y);
        if (z == 1):
            return False;
     
        return isDivisible(x, y / z);
 
    y=int(input())
    x=int(input())
    if (isDivisible(y, x)):
        print("Yes")
    else:
        print("No")




 


