def dequeque(page_sequence):
    page_sequence.remove(page_sequence[0])

def page_replacement(page_sequence):
    page = []
    hit = 0
    for i in page_sequence:
        if(len(page)<13):
            if(i not in page):
                page.append(i)
            else:
                hit+=1
        else:
            if(i not in page):
                dequeque(page)
                page.append(i)
            else:
                hit+=1
    print(page,hit)

if __name__ == "__main__":
    n = int(input("Enter Number of page sequences. "))
    page_sequence = []
    for i in range(n):
        input1 = input("")
        page_sequence.append(input1)
    page_replacement(page_sequence)