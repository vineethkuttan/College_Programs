try:
    with open(input("Enter the input file : ")) as fp1:
        with open(input("Enter the output file : "),'w') as fp2:
            fp2.writelines(fp1.readlines())
except Exception as e:
    print(e)