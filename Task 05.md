### Task 05 *随机数的生成*

```python
#猜数字游戏
import random

def guess_number():
    min_val = int(input("请输入猜数范围的下限："))
    max_val = int(input("请输入猜数范围的上限："))
    if min_val > max_val:
        print("范围有误，请重新输入")
        return guess_number()  # 重新调用函数
    num = random.randint(min_val, max_val)
    print(f"猜一个 {min_val} 到 {max_val} 之间的数字：")

    times = 0
    while True:
        try:
            x = int(input("请输入你的数字："))
            times += 1
            if x == num:
                print(f"恭喜你猜对了！共用了 {times} 次。")
                break
            elif x < num:
                print("数字太小了")
            else:
                print("数字太大了")
        except ValueError:
            print("请输入一个有效的整数。")

guess_number()
```

1) 生成随机整数

   ```python
   #随机整数
   import random
   x=random.randint(0, 1000)
   # random.randint(a,b) 用于生成一个指定范围的整数
   print("随机生成整数：")
   print(x)
   ```



2.生成随机偶数

```python
#生成随机偶数
x=random.randrange(0,1000,2)
# random.randrange(a,b,c) a,b表示范围，c表示步长
print("生成随机偶数：")
print(x)

```

3.生成随机浮点数

```python
#生成随机浮点数
x=random.uniform(1, 3)
# random.uniform(a,b) 用于生成指定范围内的随机浮点数
print("随机生成浮点数：")
print(x)
```

Python 的 `random` 模块提供了生成随机数的功能，是进行概率和统计计算常用的工具。以下是一些 `random` 模块中常见的函数及其简要介绍：

1. **`random.random()`**: 返回一个[0.0, 1.0)范围内的随机浮点数。

2. **`random.randint(a, b)`**: 返回一个[a, b]范围内的随机整数。

3. **`random.randrange(start, stop[, step])`**: 返回一个从 start 开始到 stop 结束（不包括 stop），步长为 step 的随机整数。如果 step 不提供，默认为 1。

4. **`random.choice(seq)`**: 从非空序列 seq 中随机选择一个元素。

5. **`random.choices(population, weights=None, *, cum_weights=None, k=1)`**: 从给定的总体中随机选择 k 个元素，可以指定权重。

   #### random.choice ('abcdefg&#%^*f') 生成随机字符

   #### random.choice(['apple','pear','peach','orange','lemon']) 生成随机字符串

   #### random.sample('abcdefghij',3) 从多个字符中选取特定数量的字符

6. **`random.shuffle(x[, random])`**: 将序列 x 原地随机打乱。可以指定一个随机数生成器。

7. **`random.sample(population, k)`**: 从总体 population 中随机选择 k 个不重复的元素。

8. **`random.uniform(a, b)`**: 返回一个[a, b]范围内的随机浮点数。

9. **`random.normalvariate(mu, sigma)`**: 返回一个服从正态分布的随机数，其中 mu 是平均值，sigma 是标准差。

10. **`random.triangular(low, high, mode)`**: 返回一个在给定的 low、high 和 mode 之间的随机数，其中 mode 是最高概率的值。

这些函数在模拟实验、游戏开发、数据科学等领域中非常有用。使用这些函数时，确保理解它们的参数和返回值，以便正确地生成所需的随机数。



Python 的 `math` 模块提供了许多数学函数，用于执行各种数学运算。以下是一些 `math` 模块中常见的函数及其简要介绍：

1. **`math.pi`**: 圆周率的近似值。

2. **`math.e`**: 自然对数的底数。

3. **`math.sqrt(x)`**: 返回 x 的平方根。

4. **`math.pow(x, y)`**: 返回 x 的 y 次幂。

5. **`math.exp(x)`**: 返回 e 的 x 次幂。

6. **`math.log(x[, base])`**: 返回 x 的自然对数。如果提供了 base，则返回以 base 为底的对数。

7. **`math.log2(x)`**: 返回以 2 为底的 x 的对数。

8. **`math.log10(x)`**: 返回以 10 为底的 x 的对数。

9. **`math.sin(x)`**: 返回 x 的正弦值（x 以弧度为单位）。

10. **`math.cos(x)`**: 返回 x 的余弦值（x 以弧度为单位）。

11. **`math.tan(x)`**: 返回 x 的正切值（x 以弧度为单位）。

12. **`math.asin(x)`**: 返回 x 的反正弦值（结果以弧度为单位）。

13. **`math.acos(x)`**: 返回 x 的反余弦值（结果以弧度为单位）。

14. **`math.atan(x)`**: 返回 x 的反正切值（结果以弧度为单位）。

15. **`math.atan2(y, x)`**: 返回 y/x 的反正切值（结果以弧度为单位）。

16. **`math.sinh(x)`**: 返回 x 的双曲正弦值。

17. **`math.cosh(x)`**: 返回 x 的双曲余弦值。

18. **`math.tanh(x)`**: 返回 x 的双曲正切值。

19. **`math.asinh(x)`**: 返回 x 的反双曲正弦值。

20. **`math.acosh(x)`**: 返回 x 的反双曲余弦值。

21. **`math.atanh(x)`**: 返回 x 的反双曲正切值。

22. **`math.ceil(x)`**: 返回大于或等于 x 的最小整数。

23. **`math.floor(x)`**: 返回小于或等于 x 的最大整数。

24. **`math.fabs(x)`**: 返回 x 的绝对值。

25. **`math.factorial(x)`**: 返回 x 的阶乘。

26. **`math.fmod(x, y)`**: 返回 x 除以 y 的余数。

27. **`math.gcd(a, b)`**: 返回 a 和 b 的最大公约数。

28. **`math.hypot(x, y)`**: 返回欧几里得距离 sqrt(x^2 + y^2)。

29. **`math.isqrt(x)`**: 返回 x 的整数平方根。

30. **`math.trunc(x)`**: 返回 x 的整数部分，去除小数部分。

这些函数在科学计算、工程学、金融数学等领域中非常有用。使用 `math` 模块时，确保导入它：

```python
import math
```

然后就可以调用这些函数了。



###### *练习：（1）修改案例，随机生成字符及字符串*

*随机生成单个字符*

1. **使用 `random.choice()`**:

   ```
   pythonimport random
   import string
   
   random_char = random.choice(string.ascii_letters)
   print(random_char)
   ```

2. **使用 `random.randint()`**:

   ```
   pythonimport random
   
   random_char = chr(random.randint(65, 90))  # 生成大写字母
   print(random_char)
   ```

##### *随机生成字符串*

1. **使用 `random.choices()`**:

   ```
   pythonimport random
   import string
   
   random_string = ''.join(random.choices(string.ascii_letters + string.digits, k=10))
   print(random_string)
   ```

2. **使用循环和 `random.choice()`**:

   ```
   pythonimport random
   import string
   
   length = 10  # 字符串长度
   random_string = ''.join(random.choice(string.ascii_letters + string.digits) for _ in range(length))
   print(random_string)
   ```

##### *字符串模块中的字符集*

- `string.ascii_letters`: 包含所有字母（大写和小写）。
- `string.ascii_uppercase`: 包含所有大写字母。
- `string.ascii_lowercase`: 包含所有小写字母。
- `string.digits`: 包含数字 '0' 到 '9'。
- `string.punctuation`: 包含所有标点符号。

##### *示例：生成一个包含字母和数字的随机字符串*

```
pythonimport random
import string

def generate_random_string(length=10):
    return ''.join(random.choices(string.ascii_letters + string.digits, k=length))

random_string = generate_random_string(12)  # 生成一个长度为12的随机字符串
print(random_string)
```

这些方法可以生成随机字符和字符串，常用于密码生成、测试数据生成等场景。



*（2）修改本案例程序，打乱指定序列 [1,2,3,4,5,6]*

要打乱一个指定的序列，可以使用 `random` 模块中的 `shuffle` 函数。以下是修改后的程序，用于打乱列表 `[1, 2, 3, 4, 5, 6]`：

```python
import random

def shuffle_sequence(sequence):
    random.shuffle(sequence)
    return sequence

original_sequence = [1, 2, 3, 4, 5, 6]
print("原始序列:", original_sequence)

shuffled_sequence = shuffle_sequence(original_sequence.copy())  # 使用 copy 避免修改原始列表
print("打乱后的序列:", shuffled_sequence)
```

##### 代码解释：
1. **导入 `random` 模块**：首先导入 `random` 模块。
2. **定义 `shuffle_sequence` 函数**：这个函数接受一个序列作为参数，并使用 `random.shuffle()` 方法打乱这个序列。
3. **创建原始序列**：创建一个原始的序列 `[1, 2, 3, 4, 5, 6]`。
4. **打印原始序列**：在打乱之前打印原始序列。
5. **调用函数并打印结果**：调用 `shuffle_sequence` 函数并打印打乱后的序列。注意使用 `original_sequence.copy()` 来避免修改原始列表。

每次运行程序时，`shuffled_sequence` 都会是一个不同的打乱后的序列。