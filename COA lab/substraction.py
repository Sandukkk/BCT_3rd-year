def twos_complement(b):
    b_c = ''
    for bit in b:
        if bit == '0':
            b_c+='1'
        else:
            b_c +='0'
        result=bin(int(b_c,2)+1)[2:] 
    return result
