name = input()
vowels = 'aeiou'
hiLo = 0

for letter in name:
    if letter in vowels:
        hiLo += 1
    else:
        hiLo -= 1

if hiLo > 0:
    print(1)
else:
    print(0)
