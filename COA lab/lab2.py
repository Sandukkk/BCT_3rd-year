

def sub(a,b):
    n=max(len(a),len(b))
    a=a.zfill(n)
    b=b.zfill(n)    

    b_c = ''
    for bit in b:
        if bit == '0':
            b_c+='1'
        else:
            b_c +='0'
    carry=1
    diff=""
    borrow=''
  
    

    for i in range (n-1,-1,-1):     #4 bit ko vaye 3 bata start vayera 0 samma jancha as indicated by -1
        a_val=int(a[i])             #converting binary digits to integer
        b_val=int(b_c[i])
        result = (a_val + b_val +carry)
        
        if result==2:
            carry = 1
            diff = '0' + diff
            borrow= '1' + borrow
        elif result == 3:
            carry = 1
            diff = '1' +diff
            borrow= '1' + borrow
        else:
            carry = 0
            diff = str(result)+ diff
            borrow = '0' + borrow
        
        
    return diff, borrow
a=input("enter first number: ")
b=input("enter second number: ")
diff , borrow =   sub(a,b)
print("difference is = ",diff)
print("borrow is = ", borrow)    


