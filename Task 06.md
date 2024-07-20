### *Task 06 判断字符串是否为数字*

```python
def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        pass
    # 修正了函数名，将 Unicodedate 改为 unicodedata
    # 并且修正了函数名，将 .numeric 改为 .isdigit
    try:
        import unicodedata
        if unicodedata.isdigit(s):
            return True
    except (TypeError, ValueError):
        pass
    return False
```

##### 客观上讲，这个代码太繁琐

##### *使用正则表达式*

```python
import re

def is_number(s):
    return bool(re.match(r'^[-+]?\d*\.?\d+$', s))
```

这段Python代码使用了正则表达式来检查一个字符串 `s` 是否表示一个数字。下面是对代码的逐行解释：

1. `import re`：这行代码导入了Python的正则表达式模块 `re`，它提供了用于处理正则表达式的一系列方法。

2. 定义了一个函数 `is_number(s)`，它接受一个参数 `s`，这个参数应该是一个字符串。

3. `return bool(re.match(r'^[-+]?\d*\.?\d+$', s))`：这行代码使用了 `re.match()` 函数来检查字符串 `s` 是否与正则表达式模式匹配。`re.match()` 函数会在字符串的起始位置搜索匹配项，如果找到匹配项，则返回一个匹配对象，否则返回 `None`。

   - `r'^[-+]?\d*\.?\d+$'` 是正则表达式的模式字符串，其中：
     - `^` 表示匹配字符串的开始。
     - `[-+]?` 表示数字前面可以有可选的正号或负号。
     - `\d*` 表示匹配零个或多个数字（`\d` 是数字的简写）。
     - `\.?` 表示小数点是可选的。
     - `\d+` 表示至少匹配一个数字。
     - `$` 表示匹配字符串的结束。

4. `bool(...)` 将 `re.match()` 的结果转换为布尔值。如果 `re.match()` 返回一个匹配对象，则 `bool()` 将返回 `True`，表示字符串 `s` 是一个数字；如果没有找到匹配项，`re.match()` 返回 `None`，`bool()` 将返回 `False`，表示字符串 `s` 不是一个数字。

这个函数可以正确地识别整数、正数、负数以及小数，包括那些以正负号开头的数字，但不包括没有数字的空字符串或只包含小数点的字符串。



*在Python中，判断一个字符串是否为数字还可以使用多种方法，以下是几种常见的方法：*

1. 使用 `str.isdigit()` 方法：
   这个方法检查字符串中的所有字符是否都是数字，并且字符串不为空。

   ```python
   s = "123"
   if s.isdigit():
       print("字符串是数字")
   else:
       print("字符串不是数字")
   ```

2. 使用 `str.isnumeric()` 方法：
   这个方法类似于 `isdigit()`，但支持Unicode数字字符，比如罗马数字或汉字数字。

   ```python
   s = "Ⅳ"
   if s.isnumeric():
       print("字符串是数字")
   else:
       print("字符串不是数字")
   ```

3. 使用正则表达式：
   使用 `re` 模块中的 `match` 函数，可以检查字符串是否符合数字的模式。

   ```python
   import re
   s = "123"
   if re.match(r'^\d+$', s):
       print("字符串是数字")
   else:
       print("字符串不是数字")
   ```

4. *尝试将字符串转换为数字：*
   *使用 `int()` 或 `float()` 函数尝试转换字符串，如果转换成功，则字符串表示数字。*

   ```python
   s = "123"
   try:
       int(s)
       print("字符串是数字")
   except ValueError:
       print("字符串不是数字")
   ```

请注意，这些方法中有一些只能检查字符串是否完全由数字组成，而不能检查字符串是否表示有效的数字（例如，包含小数点或负号的数字）。如果需要检查这些情况，你可能需要使用更复杂的正则表达式或尝试转换为 `float`。

### *Task 07 奇偶数判断*

```python
def Is_EvenNumber(m):
    # 判断输入是否为数字
    def Is_Number(m):
        try:
            int(m)
            return True
        except ValueError:
            print("这不是数字")
            return False

    # 判断是否为偶数
    if Is_Number(m):
        num = int(m)
        if num % 2 == 0:
            print("{0}是偶数".format(num))
        else:
            print("{0}是奇数".format(num))
    else:
        print("{0}不是数字".format(m))

Is_EvenNumber('lalala')
```

*练习题：现有一个比赛，一共有10道题目，参赛选手需要答对5道题目才能进入下一阶段的比赛。请设计一个程序来判断选手是否可以进入下一阶段的比赛。*

```python
def Competition(total_questions,correct_questions):
    def Can_Advance(total_questions,correct_questions):
        return correct_questions >= 5

    if Can_Advance(total_questions, correct_questions):
        print("恭喜，你可以进入下一阶段的比赛！")
    else:
        print("很遗憾，你没有达到进入下一阶段的标准。")
        
Competition(10, 5)
```



### *Task 08* *闰年的判断*

- *如果年份能被4整除，但不能被100整除，那么这一年是闰年。*
- *如果年份能被400整除，那么这一年也是闰年。*

```python
def Leap_Year():
    year = int(input("请输入年份："))
    try:
        if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
            return True
        else:
            return False
    except ValueError:
        print("输入的不是有效年份，请重新输入！")
    return False

# 调用函数
if Leap_Year():
    print("是闰年。")
else:
    print("不是闰年。")
```

*练习题：某市出租车的起步里程数为3公里，起步费用为9元。行驶里程数大于3公里，小于10公里时，收费标准是2元/公里。行驶里程数大于10公里之后，收费标准是3元/公里。请设计一个程序，计算出门坐出租车所需的费用。*

```python
def taxi_fare():
    distance = float(input("请输入里程数："))
    fare = 0
    if distance <= 3:
        fare = 9
    elif distance < 10:
        fare = 9 + 2 * (distance - 3)
    else:
        fare = 9 + 2 * 7 + 3 * (distance - 10)
    print("里程数为{0}公里时，费用为{1}元".format(distance, fare))

taxi_fare()
```

