long_str = input()
strings = long_str.split('-')

for string in strings:
    print(string[:1], end='')

