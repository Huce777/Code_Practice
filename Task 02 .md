### *Task 02  数字求和*

```python
#用户输入待求和的数字
num1=input("请输入第一个数字：")
num2=input("请输入第二个数字：")
sum=int(num1)+int(num2)
print("两个数字的和为：",sum)
```

### *Task 03 二次方程求解*

```python
import math

def solve_quadratic():
    a = float(input("请输入二次项系数："))
    b = float(input("请输入一次项系数："))
    c = float(input("请输入常数项："))

    discriminant = b**2 - 4*a*c

    if discriminant < 0:
        print("该二次方程在实数范围内无解")
    else:
        d = math.sqrt(discriminant)
        e1 = (-b + d) / (2*a)
        e2 = (-b - d) / (2*a)
        print(f"{a}x²+{b}x+{c}=0的解是：{e1:.2f} 和 {e2:.2f}")

solve_quadratic()
```

#### *Python 的保留字，也称为关键字，是 Python 语言中具有特殊意义的单词。它们在 Python 程序中扮演着重要的角色，比如控制程序流程、定义数据结构等。以下是一些常用的 Python 关键字及其简要介绍：*

1. ###### ***`if`**: 用于条件判断，执行不同的代码块。*
2. ***`else`**: 与 `if` 配合使用，表示当条件不满足时执行的代码块。*
3. ***`elif`**: 与 `if` 配合使用，表示当前面的 `if` 或 `elif` 条件都不满足时执行的代码块。*
4. ***`for`**: 用于遍历序列（如列表、元组、字典等）。*
5. ***`while`**: 用于创建循环，重复执行代码块直到条件不满足。*
6. ***`break`**: 用于立即退出循环。*
7. ***`continue`**: 用于跳过当前循环的剩余部分，开始下一次循环。*
8. ***`def`**: 用于定义函数。*
9. ***`return`**: 用于从函数返回值。*
10. ***`class`**: 用于定义类。*
11. ***`pass`**: 用作占位符，表示空代码块。*
12. ***`import`**: 用于导入模块。*
13. ***`from`**: 与 `import` 一起使用，从模块中导入特定的类或函数。*
14. ***`global`**: 用于声明全局变量。*
15. ***`nonlocal`**: 用于声明非局部变量。*
16. ***`try`**: 用于异常处理，尝试执行代码块。*
17. ***`except`**: 与 `try` 配合使用，捕获并处理异常。*
18. ***`finally`**: 与 `try` 配合使用，无论是否发生异常，都会执行的代码块。*
19. ***`raise`**: 用于手动抛出异常。*
20. ***`with`**: 用于资源管理，确保代码块执行完毕后资源被正确释放。*
21. ***`as`**: 用于给导入的模块或变量赋予别名。*
22. ***`lambda`**: 用于定义匿名函数。*
23. ***`and`**: 逻辑与操作符。*
24. ***`or`**: 逻辑或操作符。*
25. ***`not`**: 逻辑非操作符。*
26. ***`in`**: 用于成员检测，检查一个值是否存在于序列中。*
27. ***`is`**: 用于检查两个对象是否是同一个对象。*
28. ***`del`**: 用于删除对象。*
29. ***`async`**: 用于定义异步函数。*
30. ***`await`**: 用于调用异步函数。*

*这些关键字是 Python 编程中的基础，理解它们对于编写有效的 Python 程序至关重要。*



#### *在 Python 中，转义字符用于在字符串中表示那些通常被解释为特殊字符的字符。以下是一些常见的转义字符及其作用：*

1. **`\'`** (单引号): 允许在字符串中使用单引号，而不会终止字符串。
   
   ```python
   print('He\'s the one')
   ```
   
2. **`\"`** (双引号): 允许在字符串中使用双引号，而不会终止字符串。
   ```python
   print("He\"s the one")
   ```

3. **`\\`** (反斜杠): 表示一个反斜杠字符。
   ```python
   print("C:\\Windows")
   ```

4. **`\n`** (换行): 换行符，将输出移到下一行。
   ```python
   print("Hello\nWorld")
   ```

5. **`\t`** (制表符): 制表符，通常用于对齐文本。
   ```python
   print("Hello\tWorld")
   ```

6. **`\r`** (回车): 回车符，将光标移至行首。
   ```python
   print("Hello\rWorld")
   ```

7. **`\b`** (退格): 退格符，删除前一个字符。
   ```python
   print("Hello\bWorld")
   ```

8. **`\f`** (换页): 换页符，通常用于打印机。
   ```python
   print("Hello\fWorld")
   ```

9. **`\0`** (空字符): 空字符，通常用于二进制数据。
   ```python
   print("Hello\0World")
   ```

10. **`\a`** (响铃): 响铃符，通常用于终端。
    ```python
    print("Hello\aWorld")
    ```

11. **`\ooo`** (八进制): 表示一个八进制数字，其中 `ooo` 是一到三位的八进制数。
    ```python
    print("\x41")  # 输出字母 'A'
    ```

12. **`\xhh`** (十六进制): 表示一个十六进制数字，其中 `hh` 是两位十六进制数。
    ```python
    print("\x41")  # 输出字母 'A'
    ```

13. **`\uxxxx`** (Unicode): 表示一个 Unicode 字符，其中 `xxxx` 是四位十六进制数。
    ```python
    print("\u03A9")  # 输出希腊字母大写的 Omega
    ```

14. **`\Uxxxxxxxx`** (Unicode): 表示一个 Unicode 字符，其中 `xxxxxxxx` 是八位十六进制数。
    ```python
    print("\u03A9")  # 输出希腊字母大写的 Omega
    ```

这些转义字符在处理字符串时非常有用，尤其是在需要在文本中包含特殊字符时。



#### *在Python中，数据类型转换是常见的操作，可以通过内置函数轻松实现。以下是一些常用的数据类型转换函数：*

1. **`int(x [, base])`**: 将 x 转换为整数。如果 x 是字符串，可以指定 base 来指定进制。
   ```python
   int("123")  # 123
   int("0b101", 2)  # 5
   ```

2. **`float(x)`**: 将 x 转换为浮点数。
   ```python
   float("123.456")  # 123.456
   ```

3. **`str(x)`**: 将 x 转换为字符串。
   ```python
   str(123)  # "123"
   ```

4. **`list(x)`**: 将 x 转换为列表。
   ```python
   list("hello")  # ['h', 'e', 'l', 'l', 'o']
   ```

5. **`tuple(x)`**: 将 x 转换为元组。
   ```python
   tuple([1, 2, 3])  # (1, 2, 3)
   ```

6. **`dict(x)`**: 将 x 转换为字典。通常需要提供键值对。
   ```python
   dict([('key1', 'value1'), ('key2', 'value2')])  # {'key1': 'value1', 'key2': 'value2'}
   ```

7. **`set(x)`**: 将 x 转换为集合。
   ```python
   set([1, 2, 3])  # {1, 2, 3}
   ```

8. **`bool(x)`**: 将 x 转换为布尔值。大多数值转换为 `True`，除了 `None`、`False`、`0`、空字符串、空列表、空字典、空集合等。
   ```python
   bool(10)  # True
   bool(0)   # False
   ```

9. **`complex(real [, imag])`**: 将实部和虚部转换为复数。
   ```python
   complex(1, 2)  # (1+2j)
   ```

10. **`bytes(x [, encoding [, errors]])`**: 将 x 转换为字节对象。可以指定编码和错误处理方式。
    ```python
    bytes("hello", "utf-8")  # b'hello'
    ```

11. **`bytearray(x [, encoding [, errors]])`**: 将 x 转换为可变的字节数组。可以指定编码和错误处理方式。
    ```python
    bytearray("hello", "utf-8")  # bytearray(b'hello')
    ```

12. **`memoryview(x)`**: 创建一个内存视图对象，允许访问原始数据。
    ```python
    memoryview(b'hello')  # <memory at 0x7f2a9a8005f0>
    ```

这些函数使得在不同数据类型之间进行转换变得简单直接，是处理数据时不可或缺的工具。
