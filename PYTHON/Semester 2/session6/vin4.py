from collections import deque
de,de2=deque([]),deque([])
for i in input("Enter the string "):
    if i =='#':
        de.pop()
    else:
        de.append(i)
print("".join(de))
for i in range(len(de)):
    de2.append(de.popleft())
print("".join(de2))
