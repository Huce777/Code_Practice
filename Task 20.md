### *Task 20 自定义数组*

##### *面向对象编程*  ：封装 ， 继承 ， 多态

*面向对象编程中的“对象”和“类”是两个核心概念，它们之间的关系和特点如下：*

1. ***类（Class）**：*
   - *类是现实世界中某些具有共同属性和行为的事物的抽象和模型。*
   - *它定义了一组属性（变量）和方法（函数），这些属性和方法共同描述了一类事物的特征和行为。*
   - *类是创建对象的蓝图或模板，它规定了对象的结构和行为。*

2. ***对象（Object）**：*
   - *对象是根据类的定义创建的具体实例，是类的具体化。*
   - *每个对象都拥有自己的状态（属性值）和行为（方法的实现）。*
   - *对象之间的交互是通过消息传递进行的，即一个对象可以请求另一个对象执行其方法。*

*类和对象之间的关系可以这样理解：*

- *类是抽象的概念，它定义了一组属性和方法，但不包含具体的数据。*
- *对象是具体的，它是根据类的定义创建的，包含了实际的数据和行为。*

*例如，如果我们有一个名为 `Car` 的类，它可能包含属性如 `color`、`speed` 和方法如 `start()`、`stop()`。当我们创建一个 `Car` 类的实例时，我们得到了一个具体的对象，比如 `myCar`，它有特定的颜色和速度值，并且可以使用 `start()` 和 `stop()` 方法来控制它的启动和停止。*

*面向对象编程的这种抽象和实例化机制，使得代码更加模块化，易于理解和维护。同时，它也支持代码复用，因为多个对象可以共享同一个类的定义。*



**面向对象编程（Object-Oriented Programming，简称OOP）是一种编程范式，它使用“对象”来设计软件，将数据和处理数据的方法结合在一起。OOP 的核心概念包括封装、继承和多态 **

1. ***封装（Encapsulation）**：*
   - *封装是将数据（属性）和操作数据的方法（行为）组合在一起的过程。*
   - *它隐藏了对象的内部状态和实现细节，只暴露出一个可以被外界访问的接口。*
   - *封装提高了代码的安全性和易于维护性，因为外部代码不能直接访问对象的内部状态，只能通过对象提供的方法来操作。*

2. ***继承（Inheritance）**：*
   - *继承是一种机制，允许一个类（子类）继承另一个类（父类或超类）的属性和方法。*
   - *子类可以扩展或修改父类的行为，也可以添加新的行为。*
   - *继承支持代码复用，可以创建层次结构，使得类之间的关系更加清晰。*

3. ***多态（Polymorphism）**：*
   - *多态是指允许不同类的对象对同一消息做出响应，但具体的行为会根据对象的实际类型而有所不同。*
   - *多态可以通过重载（方法名相同，参数不同）和重写（子类重写父类的方法）实现。*
   - *多态使得代码更加灵活，可以在不知道对象具体类型的情况下编写通用的代码。*

*这三个概念共同构成了面向对象编程的基础，使得软件设计更加模块化、可扩展和易于维护。*

```python
#创建MyArray类
class MyArray:
    '''定义了一个私有方法 __isNumber 用于
检查传入的参数是否为数值类型（整数、浮点数或复数）'''
    #建立__isNumber()的方法，保证输入值为数字元素(整型，浮点，复数)
    def __isNumber(self,n):
        if not isinstance(n, (int,float,complex)):
            return False
        return True
    '''在初始化方法 __init__ 中使用此方法来确保所有传入
的元素都是数值。如果发现非数值元素，会打印错误消息并提前退出初始化方法。'''
    def __init__(self,*args):
        if not args:
            self.__value=[]
        else:
            for arg in args:
                if not self.__isNumber(arg):
                    print('All elements must be numbers')
                    return 
            self.__value = list(args)
    #*args的实质是将函数传入的参数，存储在元组类型的变量args中
    #**kargs的实质是将函数的参数和值，存储在字典类型的变量kargs中
    #实现数组之间的加法运算
    def __add__(self,other):
        '''数组中每个元素都与数字other相加，
    或者两个数组相加，得到一个新数组'''
        if self.__isNumber(other):
            #数组与数字other相加
            b=MyArray()
            b.__value=[item + other for item in self.__value]
            return b
        elif isinstance(other, MyArray):
            #两个数组对应元素相加
            if (len(other.__value)==len(self.__value)):
                c=MyArray()
                c.__value=[i+j for i,j in zip(self.__value,other.__value)]
                return c
            else:
                print('Length no equal')
        else:
            print('Not supported')
   # zip()函数用于将可迭代的对象作为参数，将对象中对应的元素打包
    #    成元组，然后返回由这些元组组成的列表
  #建立dot()方法，使MyArray类具有计算内积运算的功能
    def dot(self,v):
        if not isinstance(v, MyArray):
            print('must be an instance of MyArray.')
            return 
        if len(v) != len(self.__value):
            print('size must be equal .')
            return
        return sum([i*j for i,j in zip(self.__value,v.__value)])
    #建立__len__()方法，使MyArray类具有查看对象长度的功能
    def __len__(self):
        return len(self.__value)
    #建立__str__()方法，使MyArray类具有转换为字符串类型的功能
    def __str__(self):
        return str(self.__value)
    #建立__contains__方法，使MyArray类具有判断数字是否属于数组的功能
    def __contains__(self,n):
        if n in self.__value:
            return True
        return False
    #建立append()方法，使MyArray类具有附加元素的功能
    def append(self,n):
        if isinstance(n,(int,float)):
            self.__value.append(n)
        else:
            print('isinstance error')
    def __repr__(self):
        return repr(self.__value)
    #建立__getitem__方法，使MyArray类判断指定元素是否属于数组
    def __getitem__(self,key):
        length=len(self.__value)
        if isinstance(key, int) and 0 <= key < length:
            return self.__value[key]
        else:
            return 'Index Error'
    #建立__setitem__方法，使MyArray类具有修改数组元素的功能
    def __setitem__(self,key,value):
        length = len(self.__value)
        if isinstance(key, int) and 0 <= key < length:
            self.__value[key] = value
        else:
            return 'Index Error'
        
#检验结果
a = MyArray(1,2,3,4,5,6)
b = MyArray(6,5,4,3,2,1)
print('案例20：自定义数组的实现')
print('数组a:',a)
print('数组b:',b)
print('a+b:',a+b)
print('a,b的内积为:',a.dot(b))
print('2是否在a内:',2 in a)
a.append(7)
print('a添加元素7:',a)
print('查看a的第3个元素:',a[2])
a[6]=0
print('修改最后一项值为0：',a)
```

