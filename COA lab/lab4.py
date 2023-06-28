# #restoring division algorithm
# a = input("Enter the first number: ")
# b = input("Enter the second number: ")
# c='0000'


# def sub(a,b):
#     n=max(len(a),len(b))
#     a=a.zfill(n)
#     b=b.zfill(n)    

#     b_c = ''
#     for bit in b:
#         if bit == '0':
#             b_c+='1'
#         else:
#             b_c +='0'
#     carry=1
#     diff=""
#     borrow=''
    
#     for i in range (n-1,-1,-1):     #4 bit ko vaye 3 bata start vayera 0 samma jancha as indicated by -1
#         a_val=int(a[i])             #converting binary digits to integer
#         b_val=int(b_c[i])
#         result = a_val + b_val +carry
        
#         if result==2:
#             carry = 1
#             diff = '0' + diff
#             borrow= '0' + borrow
#         elif result == 3:
#             carry = 1
#             diff = '1' +diff
#         else:
#             carry = 0
#             diff = str(result)+ diff
#             borrow = '0' + borrow
        
        
#     return diff
# def add(a,b):
#     n=max(len(a),len(b))
#     a=a.zfill(n)
#     b=b.zfill(n)    

#     result=""
#     sum=0
#     carry=0

#     for i in range (n-1,-1,-1):     #4 bit ko vaye 3 bata start vayera 0 samma jancha as indicated by -1
#         sum=(int(a[i])+int(b[i])+carry) % 2
#         carry=(int(a[i])+int(b[i])+carry) // 2    #gives int value
#         result=str(sum)+result
        
#     return result
    
# def restore_div(a, b):
#     n = max(len(a), len(b))
#     a = a.zfill(n)
#     b = b.zfill(n)

#     for i in range (n-1,-1,-1):
#         global c
#         c[i]= a[n-i-1]
#         a[n-i-1]= a[n-i]
#         c= sub(c,b)
#         if c[0] =='1':
#             a[2]='0'
#         else:
#             a[2]='1'
#         c= add(c,b)   
        
#     return c, a

# rem, quo =restore_div(c,a )
# print("quotient= ", quo)
# print("remainder= ",rem)


a = input("Enter the first number: ")
b = input("Enter the second number: ")
c = list('0000')


def sub(a, b):
    n = max(len(a), len(b))
    a = a.zfill(n)
    b = b.zfill(n)

    b_c = ''
    for bit in b:
        if bit == '0':
            b_c += '1'
        else:
            b_c += '0'
    carry = 1
    diff = ""
    borrow = ''

    for i in range(n - 1, -1, -1):
        a_val = int(a[i])
        b_val = int(b_c[i])
        result = a_val + b_val + carry

        if result == 2:
            carry = 1
            diff = '0' + diff
            borrow = '0' + borrow
        elif result == 3:
            carry = 1
            diff = '1' + diff
        else:
            carry = 0
            diff = str(result) + diff
            borrow = '0' + borrow

    return diff


def add(a, b):
    n = max(len(a), len(b))
    a = a.zfill(n)
    b = b.zfill(n)

    result = ""
    sum = 0
    carry = 0

    for i in range(n - 1, -1, -1):
        sum = (int(a[i]) + int(b[i]) + carry) % 2
        carry = (int(a[i]) + int(b[i]) + carry) // 2
        result = str(sum) + result

    return result


def restore_div(a, b):
    n = max(len(a), len(b))
    a = list(str(a).zfill(n))
    b = list(str(b).zfill(n))
    global c
    for i in range(n - 1, -1, -1):
        c[i] = a[n - i - 1]
        a[n - i - 1] = a[n - i]
        c = list(sub(''.join(c), ''.join(b)))
        if c[0] == '1':
            a[2] = '0'
        else:
            a[2] = '1'
        c = list(add(''.join(c), ''.join(b)))

    return c,a


rem, quo = restore_div(a, b)
print("quotient =", quo)
print("remainder =", rem)
