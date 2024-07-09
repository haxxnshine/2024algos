test=input()

for i in range(int(test)):
    a,b=input().split(" ")
    cnt=len(b)
    for i in range(cnt):
        print(b[i]*int(a),end="")
    print()
