while True:
    height = int (input ("Height: "))
    if 1 <= height <= 8:
        break

for i in range(height):
    spaces = height - i - 1
    hashes = i + 1

    print (" " * spaces + "#" * hashes + " " + "#" * hashes)
