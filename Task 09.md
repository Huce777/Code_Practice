### *Task 09 获取最大值*

##### *列表常用函数*

- **len(list)** - 返回列表的长度，即列表中元素的数量。
- **max(list)** - 返回列表中的最小元素。如果列表为空，会抛出 `ValueError`。
- **min(list)** - 返回列表中的最大元素。如果列表为空，会抛出 `ValueError`。
- **list(seq)** - 将一个可迭代对象 `seq` 转换成列表。这可以用于将元组、字典、集合等转换成列表。

***列表常用方法***

在Python中，列表（list）是一种非常灵活的数据结构，提供了许多内置方法来操作列表。以下是一些常用的列表方法：

- 1. **append(x)** - 在列表末尾添加一个元素 x。
     
     ```python
     lst = [1, 2, 3]
     lst.append(4)
     print(lst)  # 输出: [1, 2, 3, 4]
     ```
     
  2. **extend(iterable)** - 将一个可迭代对象（如另一个列表）的所有元素添加到列表末尾。
     ```python
     lst = [1, 2, 3]
     lst.extend([4, 5])
     print(lst)  # 输出: [1, 2, 3, 4, 5]
     ```

  3. **insert(i, x)** - 在指定位置 i 插入一个元素 x。
     
     ```python
     lst = [1, 2, 4]
     lst.insert(2, 3)
     print(lst)  # 输出: [1, 2, 3, 4]
     ```
     
  4. **remove(x)** - 移除列表中第一个值为 x 的元素。
     ```python
     lst = [1, 2, 3, 2]
     lst.remove(2)
     print(lst)  # 输出: [1, 3, 2]
     ```

  5. **pop([i])** - 移除列表中指定位置 i 的元素，并返回该元素。如果不指定位置，默认移除并返回列表中的最后一个元素。
     ```python
     lst = [1, 2, 3]
     last_element = lst.pop()
     print(lst)       # 输出: [1, 2]
     print(last_element)  # 输出: 3
     ```

  6. **clear()** - 清空列表中的所有元素。
     ```python
     lst = [1, 2, 3]
     lst.clear()
     print(lst)  # 输出: []
     ```

  7. **index(x[, start[, end]])** - 返回列表中第一个值为 x 的元素的索引，可以指定搜索的起始和结束位置。
     ```python
     lst = [1, 2, 3, 2]
     print(lst.index(2))  # 输出: 1
     ```

  8. **count(x)** - 返回 x 在列表中出现的次数。
     ```python
     lst = [1, 2, 3, 2]
     print(lst.count(2))  # 输出: 2
     ```

  9. **sort(key=None, reverse=False)** - 对列表进行排序。`key` 参数指定一个函数，用于从列表元素中提取一个用于比较的值。`reverse` 参数为 `True` 时表示降序排序。
     ```python
     lst = [3, 1, 2]
     lst.sort()
     print(lst)  # 输出: [1, 2, 3]
     ```

  10. **reverse()** - 反转列表中的元素顺序。
      ```python
      lst = [1, 2, 3]
      lst.reverse()
      print(lst)  # 输出: [3, 2, 1]
      ```

  11. **copy()** - 返回列表的浅拷贝。
      ```python
      lst = [1, 2, 3]
      copied_lst = lst.copy()
      print(copied_lst)  # 输出: [1, 2, 3]
      ```

  12. **__len__()** - 返回列表的长度，即列表中元素的数量。
      ```python
      lst = [1, 2, 3]
      print(len(lst))  # 输出: 3
      ```

  13. **__getitem__(i)** - 获取列表中指定位置 i 的元素。
      ```python
      lst = [1, 2, 3]
      print(lst[1])  # 输出: 2
      ```

  14. **__setitem__(i, x)** - 设置列表中指定位置 i 的元素为 x。
      ```python
      lst = [1, 2, 3]
      lst[1] = 5
      print(lst)  # 输出: [1, 5, 3]
      ```

  15. **__delitem__(i)** - 删除列表中指定位置 i 的元素。
      ```python
      lst = [1, 2, 3]
      del lst[1]
      print(lst)  # 输出: [1, 3]
      ```

  16. **__iter__()** - 返回列表的迭代器，用于遍历列表。
      ```python
      lst = [1, 2, 3]
      for item in lst:
          print(item)
      # 输出: 1
      # 输出: 2
      # 输出: 3
      ```

- 这些方法提供了强大的方式来处理列表数据，使得列表操作更加灵活和方便。



*Python 提供了几种不同的循环结构来重复执行代码块，主要有以下几种：*

1. **`for` 循环** - 用于遍历可迭代对象（如列表、元组、字典、集合、字符串等）中的元素。
   ```python
   for item in [1, 2, 3]:
       print(item)
   ```

2. **`while` 循环** - 根据条件重复执行代码块，直到条件不再为真。
   ```python
   i = 1
   while i <= 3:
       print(i)
       i += 1
   ```

3. **`break` 语句** - 用于立即退出 `for` 或 `while` 循环。
   ```python
   for i in range(5):
       if i == 3:
           break
       print(i)
   ```

4. **`continue` 语句** - 跳过当前循环的剩余部分，并继续执行下一次循环。
   ```python
   for i in range(5):
       if i % 2 == 0:
           continue
       print(i)
   ```

5. **`else` 子句** - 在 `for` 和 `while` 循环中，如果没有执行过 `break` 语句，循环结束后会执行 `else` 子句。
   ```python
   for i in range(5):
       if i == 3:
           break
       print(i)
   else:
       print("没有执行 break 语句")
   ```

6. **循环控制语句的嵌套** - 可以在一个循环内使用另一个循环。
   ```python
   for i in [1, 2]:
       for j in [1, 2]:
           print(i, j)
   ```

7. **`enumerate()` 函数** - 用于在 `for` 循环中获取每个元素的索引和值。
   ```python
   items = ['a', 'b', 'c']
   for index, value in enumerate(items):
       print(index, value)
   ```

8. **`zip()` 函数** - 将多个可迭代对象中对应的元素打包成一个个元组，然后返回由这些元组组成的列表，常用于并行遍历多个列表。
   ```python
   a = [1, 2, 3]
   b = ['a', 'b', 'c']
   zipped = zip(a, b)
   for x, y in zipped:
       print(x, y)
   ```

9. **列表推导式** - 用于创建列表的简洁方式，可以包含循环和条件。
   ```python
   squares = [x**2 for x in range(5)]
   print(squares)  # 输出: [0, 1, 4, 9, 16]
   ```

这些循环结构是Python编程中非常重要的组成部分，它们允许你重复执行代码块，直到满足特定条件。
