def add(a, b):
    n = max(len(a), len(b))
    a = a.zfill(n)
    b = b.zfill(n)

    carry = 0
    result = ''

    for i in range(n - 1, -1, -1):
        sum = int(a[i]) + int(b[i]) + carry

        if sum == 2:
            carry = 1
            result = '0' + result
        elif sum == 3:
            carry = 1
            result = '1' + result
        else:
            carry = 0
            result = str(sum) + result

    if carry == 1:
        result = '1' + result

    return result


def mul(a, b):
    n = len(a)
    m = len(b)

    product = '0' * (n + m)

    for i in range(m-1, -1, -1):
        if b[i] == '1':
            partial_product = a + '0' *(m-i-1)
            product = add(product, partial_product)

    return product

a = input("Enter the first number: ")
b = input("Enter the second number: ")

product = mul(a, b)
print("The product is:", product)

