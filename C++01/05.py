from ast import Str


def test(arr):
    for i in range(len(arr)):
        arr[i] += 1
    
def test02():
    str1 = "asdfg"
    str1 = list(str1)
    str1[1] = 'o'
    print("".join(str1))

if __name__ == '__main__':
    # arr = [1,2,3]
    # test(arr)
    # print(arr)
    test02()
