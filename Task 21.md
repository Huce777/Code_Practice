### *Task 21 自定义矩阵*

在Python中，魔术方法（也称为特殊方法或双下方法）是一些具有特殊名称的函数，它们允许开发者定义或修改类的默认行为。以下是一些常见的魔术方法：

1. `__init__(self, ...)`: 类的构造器，用于初始化对象。
2. `__del__(self)`: 类的析构器，当对象被销毁时调用。
3. `__str__(self)`: 当使用 `print()` 函数或 `str()` 时，返回对象的字符串表示。
4. `__repr__(self)`: 当使用 `repr()` 函数时，返回对象的官方字符串表示，通常可以用来重新创建该对象。
5. `__len__(self)`: 当使用 `len()` 函数时，返回容器类型的长度。
6. `__getitem__(self, key)`: 用于获取序列的元素，如 `obj[key]`。
7. `__setitem__(self, key, value)`: 用于设置序列的元素，如 `obj[key] = value`。
8. `__delitem__(self, key)`: 用于删除序列的元素，如 `del obj[key]`。
9. `__iter__(self)`: 返回对象的迭代器，使得对象可以使用在 `for` 循环中。
10. `__next__(self)`: 迭代器的 `__next__()` 方法，返回下一个元素。
11. `__call__(self, ...)`: 允许一个对象像函数那样被调用，如 `obj()`。
12. `__eq__(self, other)`: 定义等于符号的行为，如 `obj == other`。
13. `__ne__(self, other)`: 定义不等于符号的行为，如 `obj != other`。
14. `__lt__(self, other)`, `__le__(self, other)`, `__gt__(self, other)`, `__ge__(self, other)`: 分别定义小于、小于等于、大于、大于等于符号的行为。
15. `__add__(self, other)`, `__sub__(self, other)`, `__mul__(self, other)`, `__truediv__(self, other)`, `__mod__(self, other)`, 等：定义加、减、乘、除、取模等运算符的行为。
16. `__radd__(self, other)`, `__rsub__(self, other)`, `__rmul__(self, other)`, 等：定义反射运算符的行为，如 `other + self`。
17. `__pow__(self, other[, modulo])`: 定义幂运算符的行为，如 `obj ** other`。
18. `__matmul__(self, other)`: 定义矩阵乘法的行为，如 `obj @ other`。
19. `__contains__(self, item)`: 定义成员资格测试的操作，如 `item in obj`。
20. `__bool__(self)`: 定义在布尔上下文中评估对象时的行为，如 `if obj:`。

这些魔术方法使得Python的类可以模拟内置类型的行为，提供了极大的灵活性和强大的功能。开发者可以根据需要重写这些方法来定制类的行为。

```python
#定义矩阵类的行数和列数
import copy
class Matrix:
    def __init__(self,row,column,fill=0.0):
        self.shape = (row,column)
        self.row = row
        self.column = column
        self._matrix = [[fill] * column for i in range(row)]
    #返回矩阵的行和列元素的值
    def __getitem__(self,index):
        if isinstance(index, int):
            return self._matrix[index-1]
        elif isinstance(index, tuple):
            return self._matrix[index[0]-1][index[1]-1]
    #设置矩阵的行和列元素的值
    def __setitem__(self,index,value):
        if isinstance(index, int):
            self._matrix[index-1]=copy.deepcopy(value)
        elif isinstance(index, tuple):
            self._matrix[index[0]-1][index[1]-1]=value
    #比较维度，也就是比较行数与列数
    def __eq__(self,N):
        '''相等'''
        assert isinstance(N, Matrix),"类型不匹配，不能比较"
        return N.shape == self.shape
    #将矩阵相加，矩阵能相加的条件是两个矩阵维度相等
    def __add__(self,N):
        '''加法'''
        assert N.shape == self.shape,"维度不匹配，不能相加"
        M = Matrix(self.row, self.column)
        for r in range(self.row):
            for c in range(self.column):
                M[r,c] = self[r,c] + N[r,c]
        return M
    #输出矩阵函数
    def show(self):
        for r in range(self.row):
            for c in range(self.column):
                print(self[r+1,c+1],end=' ')
            print()
    #使用所定义的类
if __name__=='__main__':
    m = Matrix(3, 3, fill=0.0)
    n = Matrix(3, 3, fill=0.0)
    m[1] = [1.,2.,3.]
    m[2] = [4.,5.,6.]
    n[1] = [6.,8.,6.]
    n[2] = [1.,0.,3.]
    n[3] = [4.,9.,2.]
    p = m+n
    m.show()
    print() #空格
    p.show()
    print()
    print(p[1,1])
```

