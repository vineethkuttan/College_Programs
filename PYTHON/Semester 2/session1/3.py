try:
    with open(input("Enter the input file : ")) as fp1:
        li=fp1.read().split()
        li2=set(li)
        for i in sorted(li2):
            print("{} : {}".format(i,li.count(i)))
except Exception as e:
    print(e)
        