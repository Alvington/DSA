//Mellisa Stephanie	SCT221-0184/2024
//Alvin Mutahi	SCT221-0089/2024

import time
numbers = []
def linearSearch(array, key):
    start = time.time()
    for i in range (0, len(array)):
        if array[i] == key:
            print(f"{linearValue} found at index {numbers.index(linearValue)}\n")
    
    if key not in array:
            print(f"{linearValue} not found\n")
    
    end = time.time()
    total = start - end
    print(f"Linear total search time = {total}\n")


def binarySearch(array, key):
    start = time.time()
    array.sort()
    low = 0
    high = len(array) - 1
    
    while low <= high:
        mid = (low + high) // 2
        if array[mid] > key:
            high = mid - 1
        elif array[mid] < key:
            low = mid + 1
        else:
            print(f"{key} found at index {mid}\n")
            return
        
    print(f"{key} not found\n")
    end = time.time()
    total = start - end
    print(f"Binary total search time = {total}")


def hashing(array, key):
    start = time.time()
    if key in array:
        index = key % len(array)
        print(f"{key} found at index {index}\n")
    else:
        print(f"{key} not found\n")

    end = time.time()
    total = start - end
    print(f"Hashing total search time = {total}")

while True:
    num = int(input("Enter the number you want to add to the array (-1 to exit): "))
    if num == -1:
        break
    else:
        numbers.append(num)

print()


while True:
    print("1.Linear Search\n2.Binary Search\n3.Hashing\n4.Exit")
    choice = int(input("\nMake your choice: "))

    if choice == 1:
        linearValue = int(input("Which number would you like to search for: "))
        linearSearch(numbers, linearValue)
    elif choice == 2:
        binaryValue = int(input("Which number would you like to search for: "))
        binarySearch(numbers, binaryValue)
    elif choice == 3:
        hashValue = int(input("Which number would you like to search for: "))
        hashing(numbers, hashValue)
    else:
        break
