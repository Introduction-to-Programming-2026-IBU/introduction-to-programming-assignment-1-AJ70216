number = input("Number: ")
sum = 0
alternate = False
for digit in number[::-1]:
    n = int(digit)
    if alternate:
        n *= 2
        if n > 9:
            n -= 9
    sum += n
    alternate = not alternate
if sum % 10 == 0:
    print("VALID")
else:
    print("INVALID")