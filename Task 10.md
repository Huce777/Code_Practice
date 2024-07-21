### *Task 10 质数的判断*

```python
import math

def is_prime(num):
    if num <= 1:
        return False
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    for i in range(3, math.isqrt(num) + 1, 2):
        if num % i == 0:
            return False
    return True

try:
    num = int(input("请输入待判断的数字："))
    if is_prime(num):
        print(f"{num} 是个质数")
    else:
        print(f"{num} 不是质数")
except ValueError:
    print("请输入一个有效的整数。")
```

*练习：请输入老师设计一个程序，实现对多个学生的成绩进行统计。值得注意的是，学生成绩低于60分将被划分为“不及格”；若学生成绩在60分到70分，将被划分为“及格”；若学生成绩高于70分且低于85分，将被划分为“良好”；若学生成绩高于85分，将被划分为“优秀”。*

```python
def Student_Grade(grade):
    if grade < 60:
        print("不及格")
    elif grade <= 70:
        print("及格")
    elif grade < 85:
        print("良好")
    else:
        pritn("优秀")
        
grade=float(input("请输入分数："))
Student_Grade(grade)
```

### *Task 11 素数的统计与输出*

```python
import math

def PrimeNumber():
    min=int(input("请输入范围的下限："))
    max=int(input("请输入范围的上限："))
    times=0
    
    def Is_Prime(num):
        if num <= 1:
            return False
        elif num == 2:
            return True
        elif num > 2 and num % 2==0:
            return False
        else:
            for i in range(3,math.isqrt(num)+1,2):
                if num % i== 0:
                    return False
            return True
        
    for item in range(min,max):
        if Is_Prime(item):
            print(f"{item}是素数")
            times+=1
    print("总共有%d个素数"%(times))
        
PrimeNumber()
```

*例题：小明通过分期付款的方式买下自己的鞋。小明选择的是6期分期付款，每月的利息是0.6%，已知此鞋的价格是2369元。请编写一个Python程序，计算小明每月需要偿还的金额。*

```python
def calculate_monthly_repayment():
    price = int(input("请输入商品价格："))
    monthly_interest_rate = float(input("请输入月利率（如0.6表示6%）：")) / 100  # 转换为小数
    times = int(input("请输入分期还款次数："))

    monthly_repayment_amount = (price * monthly_interest_rate) / (1 - ((1 + monthly_interest_rate) ** (-times)))
    print(f"每月还款金额为：{round(monthly_repayment_amount, 2)}元")

calculate_monthly_repayment()
```

### *Task 12 阶乘的实现*

*用递归实现*

```python
def Factorial(n):
    if n==0:
        return 1
    else:
        return n*Factorial(n-1)

num=int(input("请输入需要求的阶乘："))
print(f"结果为：{Factorial(num)}")
```

*用循环实现*

```python
def Factorial():
    num=int(input("请输入需要求的阶乘："))
    fac=1
    for i in range(1,num+1,1):
        fac *= i
    return fac

print(f"结果是：{Factorial()}")
```

比较这两个程序的效率，主要考虑以下几个方面：

1. **递归调用的开销**：
   - 递归实现的阶乘函数每次调用都会在内存中增加一层调用栈，这会增加额外的内存开销。对于较大的`n`，可能会导致栈溢出。
   - 每次递归调用都会有一定的函数调用开销，包括参数传递和栈帧的创建。

2. **循环的效率**：
   - 循环实现的阶乘函数不需要额外的函数调用开销，只需要一个简单的循环即可完成计算。
   - 循环实现通常比递归实现更节省内存，因为它不需要维护多个函数调用的栈。

3. **可读性**：
   - 递归实现的代码通常更简洁，易于理解，特别是对于数学递归定义的操作。
   - 循环实现的代码虽然稍长，但同样清晰明了。

4. **尾递归优化**：
   - 尽管Python没有尾递归优化，但递归实现的阶乘函数在理论上可以通过尾递归优化来减少内存开销。

5. **输入处理**：
   - 递归实现的程序将输入处理和阶乘计算混合在一起，而循环实现的程序将输入处理和阶乘计算分开。

具体到这两个程序：

- **递归实现**：
  - 每次调用`Factorial`都会增加一层调用栈，对于较大的`n`，可能会导致性能问题。
  - 代码简洁，易于理解。

- **循环实现**：
  - 循环实现避免了递归调用的开销，通常更高效。
  - 代码稍长，但逻辑清晰。

**结论**：
对于阶乘计算，循环实现通常更高效，因为它避免了递归调用的额外开销。然而，递归实现的代码更简洁，易于理解。在实际应用中，如果阶乘的数值不是特别大，递归实现也是可接受的。但如果考虑到性能和内存使用，循环实现是更好的选择。

*练习：输出 直角三角形 ，矩形 及 球形等图形。*

在Python中，可以使用打印语句来输出直角三角形、矩形以及球形的图案。以下是一些示例代码：

##### 直角三角形

```python
def print_right_triangle(height):
    for i in range(1, height + 1):
        print('*' * i)

height = 5  # 直角三角形的高度
print_right_triangle(height)
```

##### 矩形

```python
def print_rectangle(width, height):
    for i in range(height):
        print('*' * width)

width = 10  # 矩形的宽度
height = 4  # 矩形的高度
print_rectangle(width, height)
```

##### 

### *Task 13 乘法表的输出*

```python
def multiplication_table():
    for i in range(1,10):
        for j in range(1,i+1):
            s=i*j
            print("%d×%d=%d"%(i,j,s),end=',')
        print("\n")
    
multiplication_table()
```

### *Task 14 阿姆斯特朗数的实现*

*阿姆斯特朗数（Armstrong number），也称为水仙花数（Narcissistic number），是指一个n位数，其各位数字的n次幂之和等于该数本身。例如，对于三位数来说*

*一个著名的阿姆斯特朗数例子是 153（1³ + 5³ + 3³ = 153）。*

##### 判断是否为阿姆斯特朗数

```python
def Is_ArmNum(num):
    length=len(str(num))
    sum=0
    temp = num
    while temp > 0:
        digit = temp % 10
        sum += digit**length
        temp//=10
    #判断
    if sum==num:
        print(f"{sum}是阿姆斯特朗数")
    else:
        print(f"{sum}不是阿姆斯特朗数")
```

##### 求范围内的阿姆斯特朗数

```python
def is_arm_num(num):
    length = len(str(num))
    total = 0
    temp = num
    while temp > 0:
        digit = temp % 10
        total += digit ** length
        temp //= 10
    return total == num

def arm():
    min_val = int(input("请输入范围内的最小值："))
    max_val = int(input("请输入范围内的最大值："))
    for num in range(min_val, max_val):
        if is_arm_num(num):
            print(f"{num} 是阿姆斯特朗数")
        else:
            print(f"{num} 不是阿姆斯特朗数")

arm()
```



### *Task 15 斐波那契数列的实现*

在Python中，集合（Set）是一个无序的、不包含重复元素的数据结构。集合支持数学上的集合操作，如并集、交集、差集、对称差集等。以下是Python中集合的一些常用方法：

1. **创建集合**：
   - `s = set()` 创建一个空集合。
   - `s = {1, 2, 3}` 或 `s = set([1, 2, 3])` 创建一个包含元素的集合。

2. **添加元素**：
   - `s.add(element)` 向集合中添加一个元素。

3. **删除元素**：
   - `s.remove(element)` 从集合中删除一个元素，如果元素不存在则会引发 `KeyError`。
   - `s.discard(element)` 从集合中删除一个元素，如果元素不存在则不抛出异常。
   - `s.pop()` 随机删除一个元素，并返回被删除的元素。

4. **集合运算**：
   - `s1.union(s2)` 或 `s1 | s2` 返回两个集合的并集。
   - `s1.intersection(s2)` 或 `s1 & s2` 返回两个集合的交集。
   - `s1.difference(s2)` 或 `s1 - s2` 返回两个集合的差集（ s1 中有而 s2 中没有的元素）。
   - `s1.symmetric_difference(s2)` 或 `s1 ^ s2` 返回两个集合的对称差集（两个集合中不重叠的部分）。

5. **检查元素**：
   - `element in s` 检查元素是否在集合中。

6. **集合大小**：
   - `len(s)` 返回集合中元素的数量。

7. **集合清空**：
   - `s.clear()` 清空集合中的所有元素。

8. **集合转换**：
   - `list(s)` 将集合转换为列表。
   - `tuple(s)` 将集合转换为元组。
   - `frozenset(s)` 将集合转换为不可变集合。

9. **集合复制**：
   - `s.copy()` 返回集合的浅拷贝。

10. **集合迭代**：
    - 直接使用 `for element in s` 进行迭代。

以下是一些示例代码：

```python
# 创建集合
s = {1, 2, 3}

# 添加元素
s.add(4)
print(s)  # 输出: {1, 2, 3, 4}

# 删除元素
s.remove(1)
print(s)  # 输出: {2, 3, 4}

# 集合运算
s1 = {1, 2, 3}
s2 = {3, 4, 5}
print(s1.union(s2))  # 输出: {1, 2, 3, 4, 5}
print(s1.intersection(s2))  # 输出: {3}
print(s1.difference(s2))  # 输出: {1, 2}
print(s1.symmetric_difference(s2))  # 输出: {1, 2, 4, 5}

# 检查元素
print(3 in s1)  # 输出: True
print(6 in s1)  # 输出: False

# 集合大小
print(len(s1))  # 输出: 3

# 集合清空
s1.clear()
print(s1)  # 输出: set()

# 集合转换
print(list(s1))  # 输出: []
print(tuple(s1))  # 输出: ()
print(frozenset(s1))  # 输出: frozenset()

# 集合复制
s1 = {1, 2, 3}
s1_copy = s1.copy()
print(s1_copy)  # 输出: {1, 2, 3}
```

这些是Python中集合的一些基本操作和方法。

*Python中的字典（Dictionary）是一种可变容器模型，且可存储任意类型对象，包括数字、字符串、元组等，其键值 key-value 对是唯一的。以下是Python字典的一些常用方法：*

1. **创建字典**：
   - `d = {}` 创建一个空字典。
   - `d = {'key1': 'value1', 'key2': 'value2'}` 创建一个包含键值对的字典。

2. **添加键值对**：
   - `d[key] = value` 给字典添加一个新的键值对，如果键已存在，则会更新其值。

3. **访问字典中的值**：
   - `value = d[key]` 通过键访问字典中的值。

4. **删除键值对**：
   - `del d[key]` 删除字典中的一个键值对。
   - `d.pop(key)` 删除字典中的一个键值对，并返回被删除的键对应的值。
   - `d.popitem()` 删除并返回一个随机的键值对。

5. **更新字典**：
   - `d.update({key: value, ...})` 更新字典，添加新的键值对或更新现有键的值。

6. **检查键是否存在**：
   - `if key in d:` 检查字典中是否存在某个键。

7. **获取所有键**：
   - `keys = d.keys()` 返回字典中所有键的视图。

8. **获取所有值**：
   - `values = d.values()` 返回字典中所有值的视图。

9. **获取所有键值对**：
   - `items = d.items()` 返回字典中所有键值对的视图。

10. **字典长度**：
    - `len(d)` 返回字典中键值对的数量。

11. **清空字典**：
    - `d.clear()` 清空字典中的所有键值对。

12. **复制字典**：
    - `d.copy()` 返回字典的一个浅拷贝。

13. **字典转换**：
    - `dict(list(d.items()))` 将字典转换为列表。
    - `dict(tuple(d.items()))` 将字典转换为元组。

14. **获取字典的键**：
    - `d.keys()` 返回一个包含字典所有键的视图对象。

15. **获取字典的值**：
    - `d.values()` 返回一个包含字典所有值的视图对象。

16. **获取字典的项**：
    - `d.items()` 返回一个包含字典所有键值对的视图对象。

以下是一些示例代码：

```python
# 创建字典
d = {'apple': 1, 'banana': 2}

# 添加键值对
d['cherry'] = 3

# 访问字典中的值
print(d['apple'])  # 输出: 1

# 删除键值对
del d['banana']
print(d)  # 输出: {'apple': 1, 'cherry': 3}

# 更新字典
d.update({'date': 4, 'apple': 5})
print(d)  # 输出: {'apple': 5, 'cherry': 3, 'date': 4}

# 检查键是否存在
if 'cherry' in d:
    print('Cherry is in the dictionary.')

# 获取所有键、值和键值对
keys = d.keys()
values = d.values()
items = d.items()

print(list(keys))  # 输出: ['apple', 'cherry', 'date']
print(list(values))  # 输出: [5, 3, 4]
print(list(items))  # 输出: [('apple', 5), ('cherry', 3), ('date', 4)]

# 字典长度
print(len(d))  # 输出: 3

# 清空字典
d.clear()
print(d)  # 输出: {}

# 复制字典
d = {'apple': 1, 'cherry': 3}
d_copy = d.copy()
print(d_copy)  # 输出: {'apple': 1, 'cherry': 3}
```

这些是Python中字典的一些基本操作和方法。

*递归法实现斐波那契数列*

```python
def fib(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fib(n-1) + fib(n-2)

# 测试代码
n = int(input("请输入待计算的斐波那契数列的位置："))
print(f"{n}的斐波那契数是：{fib(n)}")
```

### *Task 16 寻找最大公约数*

求两个数的最大公约数（Greatest Common Divisor，GCD）可以使用多种算法，其中最著名且效率较高的是欧几里得算法（Euclidean Algorithm）。以下是使用欧几里得算法求两个数的最大公约数的步骤：

1. **迭代法**：从较小的数开始，用较小的数去除较大的数，然后用除数去除余数，重复这个过程直到余数为0。最后的除数即为最大公约数。

2. **递归法**：将问题分解为更小的问题，递归地调用函数本身来解决问题。

以下是使用迭代法和递归法实现求最大公约数的Python代码示例：

##### 迭代法：

```python
def gcd_iter(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# 测试代码
num1 = 48
num2 = 18
print(f"{num1} 和 {num2} 的最大公约数是：{gcd_iter(num1, num2)}")
```

##### 递归法：

```python
def gcd_recursive(a, b):
    if b == 0:
        return a
    else:
        return gcd_recursive(b, a % b)

# 测试代码
print(f"{num1} 和 {num2} 的最大公约数是：{gcd_recursive(num1, num2)}")
```

在这两种方法中，迭代法通常比递归法更高效，因为它避免了函数调用的开销。然而，递归法在理解上可能更直观一些。对于非常大的数，迭代法通常是更好的选择。

*练习：（1)修改本案例的程序，使程序可以寻找多个整数之间的最大公约数。*

```python
def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
    
def gcd_list(lyst):
    if not lyst:
        return 0
    current_gcd = lyst[0]
    for num in lyst[1:]:
        current_gcd = gcd(current_gcd, num)
        if current_gcd == 1:
            return 1
    return current_gcd

num=[12,46,8,96,32]
print(f"最大公约数为：{gcd_list(num)}")
```

### *Task 17 寻找最小公约数*

```python
def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b,a%b)
    
def lcm(a,b):
    return a*b/gcd(a, b)

num1=int(input("请输入第一个数："))
num2=int(input("请输入第二个数："))
print(f"最小公约数是：{lcm(num1,num2)}")
```

### *Task 18 计算器的实现*

*简单的四则运算计算器*

```python
def calculate():
    # 获取用户输入待计算的数字
    # 首先选择运算技能
    print("选择运算：")
    print("+.相加")
    print("-.相减")
    print("*.相乘")
    print("/.相除")
    choice = input("输入你的选择（+ , - , * , /）：")
    num1 = int(input("获取第一个数字："))
    num2 = int(input("获取第二个数字："))

    def add(x, y):
        return x + y

    def subtraction(x, y):
        return x - y

    def multiply(x, y):
        return x * y

    def divide(x, y):
        return x / y

    def show(choice, num1, num2):
        if choice == '+':
            print(num1, "+", num2, "=", add(num1, num2))
        elif choice == '-':
            print(num1, "-", num2, "=", subtraction(num1, num2))
        elif choice == '*':
            print(num1, "×", num2, "=", multiply(num1, num2))
        elif choice == '/':
            if num2 != 0:
                print(num1, "÷", num2, "=", divide(num1, num2))
            else:
                print("除数不能为0")
        else:
            print("非法输入")

    return show(choice, num1, num2)

calculate()
```

### *Task 19 汉诺塔的实现*

```python
def move(n, a, b, c):
    if n == 1:
        print(a, "-->", c)
    else:
        move(n-1, a, c, b)  # 注意这里将 b 和 c 交换了位置
        print(a, "-->", c)
        move(n-1, b, a, c)  # 递归调用时，b 现在作为源，a 作为辅助，c 作为目标

n = int(input("请输入盘子数："))
a = input("名字1：")
b = input("名字2：")
c = input("名字3：")
move(n, a, b, c)
```

*当然，可以尝试用非递归方法实现汉诺塔*
