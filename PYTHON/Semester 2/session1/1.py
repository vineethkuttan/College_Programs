try:
    name=input("Enter the file name : ")
    char=input("Enter the character to be counted : ")
    with open(name) as fp:
        print(fp.read().count(char)+fp.read().count(char.swapcase()))
except Exception as e:
    print(e)        