a=input("enter first number: ")
b=input("enter second number: ")

def add(a,b):
    n=max(len(a),len(b))
    a=a.zfill(n)
    b=b.zfill(n)    

    result=""
    sum=0
    carry=0

    for i in range (n-1,-1,-1):     #4 bit ko vaye 3 bata start vayera 0 samma jancha as indicated by -1
        sum=(int(a[i])+int(b[i])+carry) % 2
        carry=(int(a[i])+int(b[i])+carry) // 2    #gives int value
        result=str(sum)+result
        
    return result, str(carry)
sum,carry= add(a,b)
print("sum= ",sum)
print("carry= ",carry)    