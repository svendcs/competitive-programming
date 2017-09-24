char0 = [];
char1 = [];
char2 = [];
char3 = [];
char4 = [];
char5 = [];
char6 = [];

char0.append("xxxxx")
char1.append("x...x")
char2.append("x...x")
char3.append("x...x")
char4.append("x...x")
char5.append("x...x")
char6.append("xxxxx")

char0.append("....x")
char1.append("....x")
char2.append("....x")
char3.append("....x")
char4.append("....x")
char5.append("....x")
char6.append("....x")

char0.append("xxxxx")
char1.append("....x")
char2.append("....x")
char3.append("xxxxx")
char4.append("x....")
char5.append("x....")
char6.append("xxxxx")

char0.append("xxxxx")
char1.append("....x")
char2.append("....x")
char3.append("xxxxx")
char4.append("....x")
char5.append("....x")
char6.append("xxxxx")

char0.append("x...x")
char1.append("x...x")
char2.append("x...x")
char3.append("xxxxx")
char4.append("....x")
char5.append("....x")
char6.append("....x")

char0.append("xxxxx")
char1.append("x....")
char2.append("x....")
char3.append("xxxxx")
char4.append("....x")
char5.append("....x")
char6.append("xxxxx")

char0.append("xxxxx")
char1.append("x....")
char2.append("x....")
char3.append("xxxxx")
char4.append("x...x")
char5.append("x...x")
char6.append("xxxxx")

char0.append("xxxxx")
char1.append("....x")
char2.append("....x")
char3.append("....x")
char4.append("....x")
char5.append("....x")
char6.append("....x")

char0.append("xxxxx")
char1.append("x...x")
char2.append("x...x")
char3.append("xxxxx")
char4.append("x...x")
char5.append("x...x")
char6.append("xxxxx")

char0.append("xxxxx")
char1.append("x...x")
char2.append("x...x")
char3.append("xxxxx")
char4.append("....x")
char5.append("....x")
char6.append("xxxxx")

char0.append(".....")
char1.append("..x..")
char2.append("..x..")
char3.append("xxxxx")
char4.append("..x..")
char5.append("..x..")
char6.append(".....")

row0 = input();
row1 = input();
row2 = input();
row3 = input();
row4 = input();
row5 = input();
row6 = input();

a = 0;
b = 0;
first = True
met_plus = False
while len(row0) > 0:
    if not first:
        row0 = row0[1:]
        row1 = row1[1:]
        row2 = row2[1:]
        row3 = row3[1:]
        row4 = row4[1:]
        row5 = row5[1:]
        row6 = row6[1:]
    first = False
    for i in range(11):
        if row0[:5] != char0[i]:
            continue
        if row1[:5] != char1[i]:
            continue
        if row2[:5] != char2[i]:
            continue
        if row3[:5] != char3[i]:
            continue
        if row4[:5] != char4[i]:
            continue
        if row5[:5] != char5[i]:
            continue
        if row6[:5] != char6[i]:
            continue

        if i == 10:
            met_plus = True
        elif not met_plus:
            a = a * 10 + i
        else:
            b = b * 10 + i

    row0 = row0[5:]
    row1 = row1[5:]
    row2 = row2[5:]
    row3 = row3[5:]
    row4 = row4[5:]
    row5 = row5[5:]
    row6 = row6[5:]

res0 = "";
res1 = "";
res2 = "";
res3 = "";
res4 = "";
res5 = "";
res6 = "";

first = True
for c in map(int, str(a+b)):
    if not first:
        res0 += "."
        res1 += "."
        res2 += "."
        res3 += "."
        res4 += "."
        res5 += "."
        res6 += "."
    first = False
    res0 += char0[c]
    res1 += char1[c]
    res2 += char2[c]
    res3 += char3[c]
    res4 += char4[c]
    res5 += char5[c]
    res6 += char6[c]

print(res0)
print(res1)
print(res2)
print(res3)
print(res4)
print(res5)
print(res6)
