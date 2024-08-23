

### *简单题*

##### *1.编程，输入一个10进制正整数，然后输出它所对应的八进制数。*

##### *输入格式：一个10进制数     输出格式：对应的8进制数*

```c
/*C语言*/

#include <stdio.h>

int main()
{
	//十进制整数 
	int decimal;
	scanf("%d",&decimal);
	
	printf("%o\n",decimal);
	return 0;
 } 
```

![image-20240810210955975](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240810210955975.png)

```python
#Python

#读取10进制数字
decimal_num = int(input("请输入一个10进制正整数："))

#使用内置函数 oct() 将数字转换为八进制数字
octal_num = oct(decimal_num)[2:]
#[2:]，它去掉了字符串的前两个字符'0o'

print("对应的八进制数是：",octal_num)
```

##### 2.输入一个华氏温度，要求输出摄氏温度。公式为

![二级C语言-温度转换](https://www.dotcpp.com/oj/upload/pimg1056_1.png)

**保留两位小数**

```c
/*C语言*/

#include<stdio.h>

int main()
{
	float fah,cel;
	scanf("%f",&fah);
	
	cel=5*(fah-32)/9;
	printf("%.2f",cel);
	
	return 0;
}
```

![image-20240810211031763](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240810211031763.png)

##### 3.有一个函数如下，写一程序，输入x，输出y值。

![二级C语言-分段函数](https://www.dotcpp.com/oj/upload/pimg1057_1.png)

**保留两位小数**

```c
/*C语言*/

#include <stdio.h>

int main() {
    float x, y;
    scanf("%f", &x);

    if (x < 1) {
        y = x;
    } else if (x < 10) {  // 由于x已经大于等于1，所以这里只需要判断x是否小于10
        y = 2 * x - 1;
    } else {
        y = 3 * x - 11;
    }

    printf("%.2f", y);
    return 0;
}
```

![image-20240810211108222](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240810211108222.png)

```python
#Python

def main():
    x = float(input("请输入x的值: "))
    y = 0

    if x < 1:
        y = x
    elif 1 <= x < 10:
        y = 2 * x - 1
    else:
        y = 3 * x - 11

    print(f"{y:.2f}")

if __name__ == "__main__":
    main()
```

##### *4.sum=2+5+8+11+14+…，输入正整数n，求sum的前n项和。*

数字分析 ：an = 3n-1   ，sum = n × (3n+1)/2

```c
/*C语言*/

#include<stdio.h>

int main()
{
	int n;
	double sum;
	scanf("%d",&n);
	
	sum = 0.5*n*(3*n+1);
	printf("%lf",sum);
	return 0;
}
```

![image-20240810211149125](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240810211149125.png)

```python
#Python

def main():
    n=int(input("请输入有几项："))
    sum = 0.5*n*(3*n+1)
    print("等差数列和为：",sum)
    
if __name__=="__main__":
    main()
```

##### *5.求出10至1000之内能同时被 2、3、7整除的数，并输出。每行一个。*

```c
/*C语言*/

#include <stdio.h>

int main() {
    int i;
    // 从10开始，因为10是第一个可能被2、3、7整除的数的候选
    for (i = 10; i <= 1000; i++) {
        // 判断i是否能同时被2、3、7整除
        if (i % 2 == 0 && i % 3 == 0 && i % 7 == 0) {
            printf("%d\n", i); // 输出符合条件的数
        }
    }
    return 0;
}
```

![image-20240810211213896](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240810211213896.png)

##### 6.从键盘输入任意20个整型数，统计其中的负数个数并求所有正数的平均值。保留两位小数

```c
/*C语言*/

#include <stdio.h> 
int main()
{
	int num[20];
	int countNegative=0;
	double sumPositive=0;
	double average;
	
	for(int i=0;i<20;i++){
		scanf("%d",&num[i]);
		
		if (num[i]<0){
			countNegative++;
		}
		else{
			sumPositive += num[i];
		}
	}
	
	average = sumPositive / (20-countNegative);
	printf("%d\n",countNegative);
	printf("%.2lf",average);
	
	return 0;
}
```

![image-20240810211314113](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240810211314113.png)

```python
#Python

def main():
    #创建一个长度为20的列表
    num = [0] * 20
    count_negative = 0
    sum_positive =0.0
    
    for i in range(20):
        num[i] = int(input(f"Enter number{i+1}:"))
        
        if num[i] < 0:
            count_negative += 1
        else:
            sum_positive += num[i]
            
    average = sum_positive / (20-count_negative)
    
    print(f"{count_negative}")
    print(f"{average:.2f}")
    
if __name__=="__main__":
    main()
```

##### *7.输入两个正整数m和n，求其最大公约数和最小公倍数。*

```c
/*C语言*/

#include<stdio.h>

int gcd(int m,int n)
{
	while (n>0){
		int temp = m;
		m = n ;
		n =	temp % n ;
	}
	return m;
}

int lcm(int m,int n)
{
	return m*n/gcd(m,n);
}

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	if (m<n){
		int temp=m;
		m=n;
		n=temp;
	}
	printf("%d\n",gcd(m,n));
	printf("%d",lcm(m,n));
	
	return 0;
}
```

![image-20240810211350853](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240810211350853.png)

```python
#Python

def gcd(m,n):
    while n:
        m , n = n , m%n
    return m

def lcm(m,n):
    return abs(m*n)//gcd(m, n)

m=int(input("第一个数："))
n=int(input("第二个数："))
if m<n:
    m,n=n,m
print("最大公约数为：",gcd(m, n))
print("最小公倍数为：",lcm(m, n))
```

##### *8.输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。*

```c
/*C语言*/

#include<stdio.h>

int main()
{
	char ch;
	int letters=0,spaces=0,digits=0,others=0;
	printf("请输入一行字符：\n");
	
	while((ch=getchar())!='\n' && ch!=EOF)
	{
		if (ch>='A'&&ch<='Z' || ch>='a'&&ch<='z'){
			letters++;
		}
		else if(ch==' '){
			spaces++;
		}
		else if(ch>='0'&&ch<='9'){
			digits++;
		}
		else{
			others++;
		}
	}
	printf("\n");
	printf("英文字母的个数：%d\n", letters);
    printf("空格的个数：%d\n", spaces);
    printf("数字的个数：%d\n", digits);
    printf("其他字符的个数：%d\n", others);
    
    return 0;
 } 
```

![image-20240810211431398](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240810211431398.png)

```python
#Python

def main():
    letters = 0
    spaces = 0
    digits = 0
    others = 0

    print("请输入一行字符：")

    ch = input()
    for char in ch:
        if 'A' <= char <= 'Z' or 'a' <= char <= 'z':
            letters += 1
        elif char == ' ':
            spaces += 1
        elif '0' <= char <= '9':
            digits += 1
        else:
            others += 1

    print("\n")
    print("英文字母的个数：", letters)
    print("空格的个数：", spaces)
    print("数字的个数：", digits)
    print("其他字符的个数：", others)

if __name__ == "__main__":
    main()
```

##### *9. 求1+2!+3!+4!+…+30!。 科学计数法，保留两位小数。*

```c
/*C语言*/

#include<stdio.h>

int Fac(int n)
{
	int fac=1;
	for(int i=1;i<=n;i++)
	{
		fac *= i;
	}
	return fac;
}

int FacSum(int n)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum += Fac(i);
	}
	return sum;
}

int main()
{
	int n=30;
	int sum=FacSum(n);
	printf("%E",sum);
	return 0;
}
```

![image-20240810211500324](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240810211500324.png)

```python
#Python

def fac(n):
    fac = 1
    for i in range(1, n + 1):
        fac *= i
    return fac

def fac_sum(n):
    sum = 0
    for i in range(1, n + 1):
        sum += fac(i)
    return sum

def main():
    n = 30
    sum = fac_sum(n)
    print(f"{sum:.0E}")  # 使用Python的格式化字符串来打印科学计数法

if __name__ == "__main__":
    main()
```

##### 10. 输入一个正数x和一个正整数n，求下列算式的值。要求定义两个调用函数：fact(n)计算n的阶乘；mypow(x,n)计算x的n次幂（即xn），两个函数的返回值类型是double。

   **x - x2/2! + x3/3! + ... + (-1)n-1xn/n!**

**×输出保留4位小数。**

```c
/*C语言*/

#include<stdio.h>
#include<math.h>

double fact(int n)
{
	double fac=1.0;
	for(int i=1;i<=n;i++)
	{
		fac *= i;
	}
	return fac;
}

double mypow(double x,int n)
{
	double result=1.0;
	for(int i=0;i<n;i++)
	{
		result *= x;
	}
	return result;
}

double Sum(double x,int n)
{
	double sum=0.0;
	
	for(int i=1;i<=n;i++)
	{
		sum += (pow(-1,i-1) * mypow(x,i) / fact(i)) ;
	}
	return sum;
}

int main(){
	double x,sum;
	int n;
	scanf("%lf %d",&x,&n);
	sum = Sum(x,n);
	printf("%.4lf",sum);
	return 0;
}
```

![image-20240810211537263](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240810211537263.png)

```python
#Python

import math

def fact(n):
    return math.factorial(n)

def mypow(x, n):
    return x ** n

def calculate_expression(x, n):
    result = 0.0
    for i in range(1, n + 1):
        result += ((-1) ** (i - 1) * mypow(x, i) / fact(i))
    return result

def main():
    x = float(input("请输入一个正数x: "))
    n = int(input("请输入一个正整数n: "))
    value = calculate_expression(x, n)
    print(f"{value:.4f}")

if __name__ == "__main__":
    main()
```

##### 11.输入x ，计算并输出下列分段函数 f(x) 的值。可以调用数学库函数：平方根函数sqrt(),绝对值函数fabs() 和幂函数 pow()。

![二级C语言-分段函数](https://www.dotcpp.com/oj/upload/image/20170807/20170807160131_33320.png)

#####  保留2位小数

```c
/*C语言*/

#include<stdio.h>
#include<math.h>

double func(double x)
{
	double y=0;
	
	if (x<0)
	{
		y=fabs(x);	
	}
	else if (x>=0 && x<2)
	{
		y=sqrt(x+1);
	}
	else if (x>=2 && x<4)
	{
		y=pow(x+2,5);
	}
	else
	{
		y=2*x+5;
	}
	return y;
}

int main()
{
	double x,y;
	scanf("%lf",&x);
	y=func(x);
	printf("%.2lf",y);
	return 0;
}
```

![image-20240810213301706](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240810213301706.png)

```python
#Python

import math

def func(x):
    y = 0
    if x < 0:
        y = abs(x)
    elif 0 <= x < 2:
        y = math.sqrt(x + 1)
    elif 2 <= x < 4:
        y = (x + 2) ** 5
    else:
        y = 2 * x + 5
    return y

def main():
    x = float(input("请输入x的值："))
    y = func(x)
    print(f"{y:.2f}")

if __name__ == "__main__":
    main()
```

##### *12.输入一个正整数n (1≤ n ≤6),再输入一个 n 行n列的矩阵，找出该矩阵中绝对值最大的元素以及它的行下标和列下标。*

```c
/*C语言*/

#include<stdio.h>
#include<limits.h> //引入limits.h以使用INT_MIN
#include<math.h>

int main()
{
	int n,i,j;
	int max_value = INT_MIN; //初始化为最小的整数
	int row_index =0 , col_index = 0;
	
	//读取 N 的值
	scanf("%d",&n);
	
	//读取矩阵，并找到绝对值最大的元素及其索引
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			int value ;
			scanf("%d",&value);
			if (abs(value)>abs(max_value))
			{
				max_value = value;
				row_index = i+1; //因为题目要求的下标从1开始，所以加1
				col_index =j+1; 
			}
		}
	 } 
	 
	 printf("%d %d %d\n",max_value,row_index,col_index);
	 
	 return 0;
 } 
```

![image-20240811100502919](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240811100502919.png)

```python
#Python

def find_max_abs_element(matrix):
    max_value = float('-inf')  # 初始化为负无穷
    max_row, max_col = -1, -1

    # 遍历矩阵中的每个元素
    for row in range(len(matrix)):
        for col in range(len(matrix[row])):
            # 检查当前元素的绝对值是否是最大的
            if abs(matrix[row][col]) > abs(max_value):
                max_value = matrix[row][col]
                max_row, max_col = row, col

    return max_value, max_row, max_col

def main():
    n = int(input("请输入正整数n (1≤ n ≤6): "))
    if 1 <= n <= 6:
        matrix = []
        print("请输入一个{}行{}列的矩阵，用空格分隔每个元素：".format(n, n))
        for _ in range(n):
            row = list(map(int, input().split()))
            if len(row) == n:
                matrix.append(row)
            else:
                print("输入的行长度不正确，请重新输入。")
                return

        max_value, max_row, max_col = find_max_abs_element(matrix)
        print("绝对值最大的元素是 {}，在第 {} 行第 {} 列".format(max_value, max_row + 1, max_col + 1))
    else:
        print("输入的n不在允许的范围内。")

if __name__ == "__main__":
    main()
```

##### *13.编写程序，输入一批学生的成绩，遇0或负数则输入结束，要求统计并输出优秀（大于85）、通过（60～84）和不及格（小于60）的学生人数。*一批学生成绩，遇0结束.

```c
#include <stdio.h>

int main() {
    int excellent = 0, pass = 0, fail = 0 ;
    int score;

    while (scanf("%d", &score) == 1 && score > 0) {
        if (score >= 85) {
            excellent++;
        } else if (score >= 60) {
            pass++;
        } else {
            fail++;
        }
    }

    printf(">=85: %d\n", excellent);
    printf("60~84: %d\n", pass);
    printf("<60: %d\n", fail);

    return 0;
}
```

![image-20240811114747343](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240811114747343.png)

 ##### *14.编写程序，输入一个正整数n，求下列算式的值。要求定义和调用函数fact(k)计算k的阶乘，函数返回值的类型是double。*
***1+1/2+ .... +1/n!***
***输出保留五位小数***                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

```c
/*C语言*/

#include<stdio.h>

int fac(int n)
{
	int result=1;
	for(int i=1;i<=n;i++)
	{
		result *= i;
	}
	return result;
}

double fact(int k)
{
	double sum=0.0;

	for(int i=1;i<=k;i++)
	{
		sum += (1.0 / fac(i));		
	}
	return sum;
 } 
 
 int main()
 {
 	int n;
 	scanf("%d",&n);
 	double sum = fact(n);
 	printf("sum=%.5lf",sum);
 	return 0;
 }
```

![image-20240811123545867](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240811123545867.png)

##### *15.用筛法求之N内的素数。*

```c
#include<stdio.h>
#include<math.h>

int prime_num(int n) {
    if (n <= 1) {
        return 0; 
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0; 
    	 }
    }
    return 1; 
}

int main()
{
	int N;
	scanf("%d",&N);
	
	for(int i=2;i<N;i++)
	{
		if(prime_num(i))
		printf("%d\n",i);
	}
	return 0;
}
```

![image-20240811125219599](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240811125219599.png)

##### *16.定义一个结构体变量（包括年、月、日）。计算该日在本年中是第几天，注意闰年问题。*

```c
#include<stdio.h>

typedef struct{
	int year;
	int month;
	int day;
} Date;

int isLeapYear(int year)
{
	return (year%4==0 && year%100!=0)||(year%400==0);
 } 
 
int getMonthDays(int year,int month)
{
	switch(month){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			return isLeapYear(year) ? 29:28 ;
		default:
			return 0;
	}
}

int getDayOfYear(Date date){
	int days=0;
	for(int i=1;i<date.month;i++){
		days += getMonthDays(date.year,i);
	}
	days += date.day;
	return days;
}

int main(){
	Date mydate;
	printf("请输入日期（ 年 月 日）：");
	scanf("%d %d %d",&mydate.year,&mydate.month,&mydate.day);
	
	int dayOfYear = getDayOfYear(mydate);
	printf("%d年%d月%d日是第%d日\n",mydate.year,mydate.month,mydate.day,dayOfYear);
	
	return 0;
}
```

![image-20240811150238231](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240811150238231.png)

##### *17.已知三条边的长度，判断这三条边是否可以构成三角形*

```c
#include <stdio.h>
#include <stdbool.h>

bool canFormTriangle(int a, int b, int c) {
    // 根据三角形的性质，任意两边之和必须大于第三边
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
    int a, b, c;
    
    printf("请输入三条边的长度：");
    scanf("%d %d %d", &a, &b, &c);
    
    if (canFormTriangle(a, b, c)) {
        printf("TES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
```

![image-20240811160559708](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240811160559708.png)

##### 18  . 成绩转换，输入一个成绩，输出成绩对应的等级
**90 ~ 100 对应 A**
**75 ~ 89 对应 B**
**60 ~ 74 对应 C**
**0 ~ 59  对应 D**

```c
#include <stdio.h>

// 定义一个结构体，包含成绩和对应的等级
typedef struct {
    int score;
    char grade;
} Grade;

// 函数用于根据成绩转换等级
char getGrade(int score) {
    if (score >= 90 && score <= 100) {
        return 'A';
    } else if (score >= 75 && score < 90) {
        return 'B';
    } else if (score >= 60 && score < 75) {
        return 'C';
    } else if (score >= 0 && score < 60) {
        return 'D';
    } else {
        return '\0'; // 非法的成绩，返回空字符
    }
}

int main() {
    int score;
    while (scanf("%d", &score) == 1) {
        char grade = getGrade(score);
        if (grade != '\0') {
            printf("%c\n", grade);
        } else {
            printf("Error!\n");
        }
    }
    return 0;
}
```

![image-20240811161154459](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240811161154459.png)

##### *19. 服务器端可以知道一共参加统计的机器个数n,以及每台机器的开机时间(单位:s)要求你把时间按大小顺序排列出来。*

##### *输入格式*

*多行测试数据，每行包含1个整数n(0<n<100)表示机器的个数，和n个32位整数代表每台机器的开机时间。*

##### *输出格式*

*对n个数降序排序，然后依次输出每个数，每个数的后面要有一个空格*

```c
#include <stdio.h>

// 选择排序算法（降序）
void selectionSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // 找到最大的元素的索引
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        // 交换找到的最大元素和第i个元素
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n > 0) {
        // 读取n个开机时间
        int bootTimes[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &bootTimes[i]);
        }

        // 对开机时间进行降序排序
        selectionSortDesc(bootTimes, n);

        // 输出排序后的结果
        for (int i = 0; i < n; i++) {
            printf("%d ", bootTimes[i]);
        }
        printf("\n");
    }
    return 0;
}
```

![image-20240811161815786](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240811161815786.png)

##### *20.**有n个小朋友围坐成一圈。老师给每个小朋友随机发偶数个糖果，然后进行下面的游戏：***

*每个小朋友都把自己的糖果分一半给左手边的孩子。*

*一轮分糖后，拥有奇数颗糖的孩子由老师补给1个糖果，从而变成偶数。*

*反复进行这个游戏，直到所有小朋友的糖果数都相同为止。*

*你的任务是预测在已知的初始糖果情形下，老师一共需要补发多少个糖果。*

##### *输入格式*

*程序首先读入一个整数N(2< N< 100)，表示小朋友的人数。* 
*接着是一行用空格分开的N个偶数（每个偶数不大于1000，不小于2）* 

##### *输出格式*

*要求程序输出一个整数，表示老师需要补发的糖果数。*

```c
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N); // 读取小朋友的人数

    // 初始化糖果数组，读取每个小朋友的初始糖果数
    int candies[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &candies[i]);
    }

    int totalCandiesGiven = 0; // 老师补发的糖果总数
    while (1) {
        int candiesGiven = 0; // 这轮游戏中需要补发的糖果数
        int prev = candies[N - 1]; // 上一个小朋友的糖果数，用于第一个小朋友分糖果

        for (int i = 0; i < N; i++) {
            // 计算当前小朋友分给左边小朋友的糖果数（一半）
            int give = candies[i] / 2;
            candies[i] -= give;

            // 如果当前小朋友剩下的糖果数是奇数，老师需要补发1个糖果
            if (candies[i] % 2 != 0) {
                candies[i]++;
                candiesGiven++;
            }

            // 将分出去的糖果给下一个小朋友
            if (i < N - 1) {
                candies[i + 1] += give;
            } else {
                // 如果是最后一个小朋友，将糖果给第一个小朋友
                candies[0] += give;
            }
        }

        // 如果这轮游戏中没有补发糖果，说明所有小朋友的糖果数都相同，结束游戏
        if (candiesGiven == 0) {
            break;
        }

        // 累计补发的糖果数
        totalCandiesGiven += candiesGiven;
    }

    printf("%d\n", totalCandiesGiven);
    return 0;
}
```

![image-20240811162318510](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240811162318510.png)



### *中等题*

##### *21.对输入的n个数进行排序并输出。*

##### *01.冒泡排序*

![img](https://www.runoob.com/wp-content/uploads/2019/03/bubbleSort.gif)

###### Python代码实现

```python
def BubbleSort(arr):
    for i in range(1,len(arr)):
        for j in range(0,len(arr)-i):
            if arr[j] > arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
    return arr

```

###### C语言实现

```c
void BubbleSort(int arr[],int len)
{
	for(int i=1;i<len;i++){
		for(int j=0;j<len-i;j++){
			if ( arr[j]>arr[j+1] ){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
 }
```



##### *22. 给你两个按 **非递减顺序** 排列的整数数组 `nums1` 和 `nums2`，另有两个整数 `m` 和 `n` ，分别表示 `nums1` 和 `nums2` 中的元素数目。*

##### *请你 **合并** `nums2` 到 `nums1` 中，使合并后的数组同样按 **非递减顺序** 排列。*

***注意：**最终，合并后数组不应由函数返回，而是存储在数组 `nums1` 中。为了应对这种情况，`nums1` 的初始长度为 `m + n`，其中前 `m` 个元素表示应合并的元素，后 `n` 个元素为 `0` ，应忽略。`nums2` 的长度为 `n` 。*

###### *直接合并后排序*

```c
int cmp(int* a , int* b){
    return *a - *b ;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    for(int i=0; i!= n ; i++)
        nums1[m+i] = nums2[i] ;
    qsort( nums1, m+n, sizeof(int), cmp);
}
```

##### *23.假设你正在爬楼梯。需要 `n` 阶你才能到达楼顶。*

*每次你可以爬 `1` 或 `2` 个台阶。你有多少种不同的方法可以爬到楼顶呢？*

**示例 1：**

```
输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶
```

**示例 2：**

```
输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
```

*我们用 f（x）表示爬到第x级台阶的方案数，考虑到最后一步可能跨了一级台阶，也可能跨了两级台阶，所以我们可以列出： f (x) = f (x-1) + f (x-2)*

*它意味着爬到第 x 级台阶的方案数是爬到第 x−1 级台阶的方案数和爬到第 x−2 级台阶的方案数的和。很好理解，因为每次只能爬 1 级或 2 级，所以 f(x) 只能从 f(x−1) 和 f(x−2) 转移过来。*

*以上是动态规划的转移方程，下面我们来讨论边界条件。我们是从第 0 级开始爬的，所以从第 0 级爬到第 0 级我们可以看作只有一种方案，即 f(0)=1；从第 0 级到第 1 级也只有一种方案，即爬一级，f(1)=1。这两个作为边界条件就可以继续向后推导出第 n 级的正确结果。我们不妨写几项来验证一下，根据转移方程得到 f(2)=2，f(3)=3，f(4)=5，……，我们把这些情况都枚举出来，发现计算的结果是正确的。*

 我们令 f(x-1) 为p , f(x-2) 为q , f(x) 为 r 

```c
int climbStairs(int n) {
    int p=0, q=0, r=1;
    for(int i=1;i<=n;i++){
        p=q;
        q=r;
        r=p+q;
    }
    return  r;
}
```

![](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240812231840302.png)

```c
#include<stdio.h>

int climbStairs(int n){
	int p=0,q=0,r=1;
	for(int i=1;i<=n;i++){
		p=q;
		q=r;
		r=p+q;
	}
	return r;
} 

int main(){
	int m,n;
	printf("输入台阶数：");
	scanf("%d",&n);
	m=climbStairs(n);
	printf("有%d种方法爬到楼顶。\n",m);
	
	return 0;
}
```

 

##### 24.陶陶家的院子里有一棵苹果树，每到秋天树上就会结出10个苹果。苹果成熟的时候，陶陶就会跑去摘苹果。陶陶有个30厘米高的板凳，当她不能直接用手摘到苹果的时候，就会踩到板凳上再试试。

现在已知10个苹果到地面的高度，以及陶陶把手伸直的时候能够达到的最大高度，请帮陶陶算一下她能够摘到的苹果的数目。假设她碰到苹果，苹果就会掉下来。

###### 输入格式

输入包括两行数据。第一行包含10个100到200之间（包括100和200）的整数（以厘米为单位）分别表示10个苹果到地面的高度，两个相邻的整数之间用一个空格隔开。第二行只包括一个100到120之间（包含100和120）的整数（以厘米为单位），表示陶陶把手伸直的时候能够达到的最大高度。

###### 输出格式

输出包括一行，这一行只包含一个整数，表示陶陶能够摘到的苹果的数目。

```c
#include<stdio.h>

int apple_num(int arr[], int size, int height) {
    int num = 0;
    for (int i = 0; i < size; i++) {
        if (height + 30 >= arr[i]) {
            num++;
        }
    }
    return num;
}

int main() {
    int arr[10], height, temp;
    printf("请输入10个整数，用空格分隔：\n");
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("输入错误，请输入整数。\n");
            return 1; // 非正常退出
        }
    }
    printf("请输入height的值：");
    if (scanf("%d", &height) != 1) {
        printf("输入错误，请输入整数。\n");
        return 1; // 非正常退出
    }
    temp = apple_num(arr, 10, height);
    printf("能够达到或超过%d的苹果数量是：%d\n", height, temp);
    return 0;
}
```

![image-20240814214155573](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240814214155573.png)

##### 25.某校大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是1米。我们可以把马路看成一个数轴，马路的一端在数轴0的位置，另一端在L的位置；数轴上的每个整数点，即0，1，2，……，L，都种有一棵树。

由于马路上有一些区域要用来建地铁。这些区域用它们在数轴上的起始点和终止点表示。已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。现在要把这些区域中的树（包括区域端点处的两棵树）移走。你的任务是计算将这些树都移走后，马路上还有多少棵树。

###### 输入格式

输入的第一行有两个整数L（1 <= L <= 10000）和 M（1 <= M <= 100），L代表马路的长度，M代表区域的数目，L和M之间用一个空格隔开。接下来的M行每行包含两个不同的整数，用一个空格隔开，表示一个区域的起始点和终止点的坐标。

###### 输出格式

输出包括一行，这一行只包含一个整数，表示马路上剩余的树的数目。

```c
#include<stdio.h>
#include<stdbool.h>

int main(){
	int L,M;
	int start,end;
	scanf("%d %d",&L,&M);
	
	bool is_tree[L+1];
	for(int i=0;i<=L;i++)
		is_tree[i]=true;
		
	for(int i=0;i<M;i++){
	
		scanf("%d %d",&start,&end);
		
		for(int j=start;j<=end;j++){
				is_tree[j]=false;
			}	
	}
	
	int remain_tree=0;
	for(int k=0;k<=L;k++){
		if(is_tree[k]){
			remain_tree++;
		}
	}
	printf("%d",remain_tree);
	return 0;
}
```

![image-20240815104659187](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240815104659187.png)

##### 26.金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间他自己专用的很宽敞的房间。更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎么布置，你说了算，只要不超过N元钱就行”。今天一早金明就开始做预算，但是他想买的东西太多了，肯定会超过妈妈限定的N元。于是，他把每件物品规定了一个重要度，分为5等：用整数1~5表示，第5等最重要。他还从因特网上查到了每件物品的价格（都是整数元）。他希望在不超过N元（可以等于N元）的前提下，使每件物品的价格与重要度的乘积的总和最大。

设第j件物品的价格为v[j]，重要度为w[j]，共选中了k件物品，编号依次为j1，j2，……，jk，则所求的总和为：

v[j1]*w[j1]+v[j2]*w[j2]+ …+v[jk]*w[jk]。（其中*为乘号）

请你帮助金明设计一个满足要求的购物单。

##### 输入格式

输入第1行，为两个正整数，用一个空格隔开：N m

（其中N（<30000）表示总钱数，m（<25）为希望购买物品的个数。）

从第2行到第m+1行，第j行给出了编号为j-1的物品的基本数据，每行有2个非负整数v p

（其中v表示该物品的价格(v<=10000)，p表示该物品的重要度(1~5)）

##### 输出格式

输出只有一个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值（<100000000）。

##### 样例输入

```
1000 5
800 2
400 5
300 5
400 3
200 2
```

##### 样例输出

```
3900
```

```c
#include<stdio.h>
#include<limits.h>

int main(){
	int N,m;
	scanf("%d %d",&N,&m);
	
	int v[m],w[m];
	for (int i=0;i<m;i++)
		scanf("%d %d",&v[i],&w[i]);
		
	//初始化 dp数组，所有元素设为0
	int dp[N+1]={0};
	int max_value=0;
	
	for (int i=0;i<m;i++){
		for (int j=N;j>=v[i];j--){
			dp[j]=dp[j]>dp[j-v[i]]+v[i]*w[i] ? dp[j]:dp[j-v[i]]+v[i]*w[i];
			
		}
	} 
	for (int i=0;i<=N;i++){
		max_value=max_value>dp[i]?max_value:dp[i];
	}
	printf("%d\n",max_value);
	return 0;
}
```

![image-20240821113630639](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240821113630639.png)

##### 27.给定一个正整数k(3≤k≤15),把所有k的方幂及所有有限个互不相等的k的方幂之和构成一个递增的序列，例如，当k=3时，这个序列是：

1，3，4，9，10，12，13，…

（该序列实际上就是：30，31，30+31，32，30+32，31+32，30+31+32，…）

请你求出这个序列的第N项的值（用10进制数表示）。

例如，对于k=3，N=100，正确答案应该是981。

##### 输入格式

输入只有1行，为2个正整数，用一个空格隔开：k N

（k、N的含义与上述的问题描述一致，且3≤k≤15，10≤N≤1000）。

##### 输出格式

输出计算结果是一个正整数（在所有的测试数据中，结果均不超过2.1*109）。（整数前不要有空格和其他符号）。

```c
#include<stdio.h>
    int main()
    {
        int   k,n,sum=0,i,j=0,m;
        scanf("%d%d",&k,&n);
        while(n)//n为0时退出循环
        {
            if(n%2==1)
            {
                m=1;
                for(i=1;i<=j;i++)//用m表示k的j次方
                {
                    m*=k;
                }
                sum+=m;
            }
            //这里其实应该写一个else 但0*k^m=0,所以加不加无所谓
            j++;
            n/=2;
        }
        printf("%d",sum);
        return 0;
     }  
```

![image-20240821221937551](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240821221937551.png)

##### 28. 解一元二次方程ax^2+bx+c=0的解。

##### 输入格式

a,b,c的值。

##### 输出格式

输出两个解，按照大小顺序输出，一个解时需要打印两次，不用考虑无解问题，保留两位小数

```c
#include<stdio.h>
#include<math.h>

int main()
{
	/* ax^2 + bx + c =0 */
	int a,b,c;
	double res1=0.0,res2=0.0,temp=0.0;
	scanf("%d %d %d",&a,&b,&c);
	
	if ( (b*b-4*a*c)<0 ){
		printf("无实数解");
	}else{
		temp = (double)sqrt(b*b-4*a*c);
		res1 = ((-1)*b+temp)/(2*a);
		res2 = ((-1)*b-temp)/(2*a);
		printf("%.2lf %.2lf",res1,res2);
	}
	return 0;
}
```

![image-20240821223527282](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240821223527282.png)

##### 29. 编一个程序，输入一个字符串，将组成字符串的所有非英文字母的字符删除后输出。

##### 输入格式

一个字符串，长度不超过80个字符

##### 输出格式

删掉非英文字母后的字符串。

##### 样例输入

```
abc123+xyz.5
```

##### 样例输出

```
abcxyz
```

```c
#include<stdio.h>
#include<string.h>

int main(){
	char str[80],res[80];
	gets(str);
	
	for(int i=0,j=0;i<strlen(str);i++){
		if (str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'){
			res[j++]=str[i];
		}
	}
	puts(res);
} 
```

![image-20240821225437783](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240821225437783.png)

##### 30. 有4个互不相同的数字，输出由其中三个不重复数字组成的排列。

##### 输入格式

4个整数。

##### 输出格式

所有排列

##### 样例输入

```
1 2 3 4
```

```c
#include <stdio.h>
int main(){
    int i,j,k;
    int a[4];
    for(i=0;i<4;i++)
        scanf("%d", a + i);
    for(i=3;i>=0;i--)//从后往前除去一个数据，剩下三个排序
        for(j=0;j<4;j++)
            if(j!=i)
                 for(k=0;k<4;k++)
                     if(k!=i&&k!=j)
                       printf("%d %d %d\n", a[j], a[k], a[6-i-j-k]);//3+2+1=6
    return 0;
}
```

![image-20240821231127524](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240821231127524.png)

##### 31. 判断一个数是否为"水仙花数"，所谓"水仙花数"是指这样的一个数：首先是一个三位数，其次，其各位数字的立方和等于该数本身。例如：371是一个"水仙花数"，371=3^3+7^3+1^3.

##### 输入格式

一个三位数

##### 输出格式

1或者0 ( 1代表此数为水仙花数,0代表此数不是水仙花数 )

```c
#include <stdio.h>

int main() {
    int num, original, remainder, result = 0;
    scanf("%d", &num);

    if (num < 100 || num > 999) {
        printf("0\n");
        return 0;
    }

    original = num; // 保存原始数值
    while (num != 0) {
        remainder = num % 10; // 获取个位数
        result += remainder * remainder * remainder; // 计算各位数的立方和
        num /= 10; // 移除个位数
    }

    if (result == original) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
```

![image-20240821233338297](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240821233338297.png)

##### 32. 输出所有的"水仙花数".所谓"水仙花数"是指这样的一个三位数：其各位数字的立方和等于该数本身。例如：371是一个"水仙花数"，371=3^3+7^3+1^3.

```c
#include<stdio.h>
#include<math.h>

int flower(int n){
	int digit,sum=0,temp=n;
	for(int i=0;i<3;i++){
		digit = n%10;
		sum += pow(digit,3);
		n /= 10;
	}
	if(temp==sum)
		return 1;
	else
		return 0;
}

int main(){
	int num;
	for (int i=100;i<=999;i++){
		if (flower(i)==1)
			printf("%d\n",i);
	}
	return 0;
}
```

![image-20240822090537408](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822090537408.png)

##### 33. 按递增顺序依次列出所有分母为40，分子小于40的最简分数。

```c
#include <stdio.h>

// 函数：计算两个数的最大公约数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int first = 1; // 用于控制输出格式，是否输出逗号
    for (int numerator = 1; numerator < 40; numerator++) {
        if (gcd(numerator, 40) == 1) { // 检查是否是最简分数
            if (first) {
                first = 0; // 第一个分数后不再输出逗号
            } else {
                printf(",");
            }
            printf("%d/40", numerator);
        }
    }
    return 0;
}
```

![image-20240822102304946](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822102304946.png)

##### 34.输入一串字符,将其中的大写变成小写，若不为大写则原样输出

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100]; // 不需要初始化为 {'\0'}

    for (int i = 0; i < 99; i++) { // 读取最多 99 个字符
        char ch = getchar();
        if (ch == '\n' || ch == EOF) { // 如果是换行符或文件结束符，停止读取
            break;
        }
        str[i] = ch;
    }
    str[99] = '\0'; // 确保字符串以 '\0' 结尾

    for (int i = 0; str[i] != '\0'; i++) { // 使用 str[i] != '\0' 来遍历字符串
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = tolower(str[i]);
        }
    }

    for (int i = 0; str[i] != '\0'; i++) { // 再次遍历并打印转换后的字符串
        printf("%c", str[i]);
    }
    printf("\n"); // 在字符串末尾打印换行符

    return 0;
}
```

![image-20240822104744404](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822104744404.png)

##### 35. 将四个整数进行从小到大的顺序排列,

```c
#include<stdio.h>
#include<string.h>
/* 插入排序 */
void insertionSort(int nums[], int size) {
    // 外循环：已排序区间为 [0, i-1]
    for (int i = 1; i < size; i++) {
        int base = nums[i], j = i - 1;
        // 内循环：将 base 插入到已排序区间 [0, i-1] 中的正确位置
        while (j >= 0 && nums[j] > base) {
            // 将 nums[j] 向右移动一位
            nums[j + 1] = nums[j];
            j--;
        }
        // 将 base 赋值到正确位置
        nums[j + 1] = base;
    }
}

int main(){
	int lyst[4];
	for(int i=0;i<4;i++)
		scanf("%d",&lyst[i]);
	
	insertionSort(lyst,4);
	
	for(int j=0;j<4;j++)
		printf("%d ",lyst[j]);
	
	return 0;
}
```

![image-20240822135029355](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822135029355.png)

##### 36.将十个数进行从大到小的顺序进行排列

```c
#include<stdio.h>
#include<string.h>
/* 插入排序 */
void insertionSort(int nums[], int size) {
    // 外循环：已排序区间为 [0, i-1]
    for (int i = 1; i < size; i++) {
        int base = nums[i], j = i - 1;
        // 内循环：将 base 插入到已排序区间 [0, i-1] 中的正确位置
        while (j >= 0 && nums[j] > base) {
            // 将 nums[j] 向右移动一位
            nums[j + 1] = nums[j];
            j--;
        }
        // 将 base 赋值到正确位置
        nums[j + 1] = base;
    }
}

int main(){
	int lyst[10];
	for(int i=0;i<10;i++)
		scanf("%d",&lyst[i]);
	
	insertionSort(lyst,10);
	
	for(int j=9;j>=0;j--)
		printf("%d ",lyst[j]);
	
	return 0;
}
```

![image-20240822135423350](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822135423350.png)

##### 37. 输入一个字符串,数出其中的字母的个数.

```c
#include<stdio.h>
#include<ctype.h>

int main(){
	char str[100];
	int count=0;
	//使用 fgets 读取一行输入，包括空格 
	fgets(str,sizeof(str),stdin);
	
	for(int i=0;str[i]!='\0';i++){
		if(isalpha(str[i])){
			//使用 isalpha 函数检查字符是否为字母
			count++; 
		}
	}
	printf("%d",count);
	return 0;
}
```

![image-20240822140225947](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822140225947.png)

##### 38.斐波纳契数列  :( 1，1，2，3，5，8，13，21，34，55，89……这个数列则称为“斐波纳契数列”，其中每个数字都是“斐波纳契数”。)
```c
#include<stdio.h>

int fib(int n){
	if(n==1||n==2)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		printf("%d ",fib(i));
	return 0;
}
```

![image-20240822140848812](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822140848812.png)

##### 39. 输入若干个整数,以-1标记输入结束。输出其中的最大数

```c
#include<stdio.h>

int main(){
	int num,maxNum;
	scanf("%d",&num);
	//假定第一个数是最大的 
	maxNum = num;
	
	while (num != -1){
		if (num>maxNum){
			maxNum = num;
		}
		scanf("%d",&num);
	}
	printf("%d\n",maxNum);
	return 0;
}
```

![image-20240822144833612](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822144833612.png)

##### 40. 求1+2!+3!+...+N!的和

```c
#include<stdio.h>

int fac(int n){
	int result=1;
	for(int i=1;i<=n;i++)
		result *= i;
	return result;
}

int fac_sum(int n){
	int sum=0;
	for(int i=1;i<=n;i++)
		sum += fac(i);
	return sum;
}

int main(){
	int N;
	scanf("%d",&N);
	int result=fac_sum(N);
	printf("%d",result);
	return 0;
}
```

![image-20240822145404242](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822145404242.png)

##### 41.利用 pi/4=1-1/3+1/5-1/7...公式求pi的近似值，当某一项的绝对值小于10-6为止

```c
#include<stdio.h>
#include<math.h>

int main(){
    double P, result = 0.0;
    for(int i = 0; i < 10000000; i++){
        result += pow(-1, i) * (1.0 / (2.0 * i + 1.0));
    }
    P = 4.0 * result;
    printf("%.6lf\n", P);
    return 0;
}
```

![image-20240822152908187](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822152908187.png)

##### 42. 求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个一位的整数。 例如2+22+222+2222+22222(此时共有5个数相加)
```c
#include<stdio.h>
#include<math.h>

int single_hace(int a,int m){
		int sum=0;
		for(int i=0;i<m;i++){
			sum += a*pow(10,i);
		}
		return sum;
	}
	
int hace(int a,int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum += single_hace(a,i);
	}
	return sum;	
}

int main(){
	int a,n;
	scanf("%d %d",&a,&n);
	int sum=hace(a,n);
	printf("%d",sum);
	return 0;
}
```

![image-20240822154935700](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822154935700.png)

##### 43. 3025这个数具有一种独特的性质：将它平分为二段，即30和25，使之相加后求平方，即(30+25)2，恰好等于3025本身。请求出具有这样性质的全部四位数

```c
#include<stdio.h>
#include<math.h>

int hace(int num){
	int left,right,temp;
	temp = num;
	right = temp%100;
	temp /= 100;
	left = temp;
	
	if( pow(left+right,2)==num )
		return 1;
	else
		return 0;
}

int main(){
	for(int i=1000;i<=9999;i++){
		if( hace(i) )
			printf("%d ",i);
	}
	return 0;
}
```

![image-20240822155900979](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822155900979.png)

##### 44. 按如下递归公式求函数值。 x=1时 f(x)=10；x>1时 f(x)=f(x-1)+2
```c
#include<stdio.h>

int function(int x){
	if(x==1)
		return 10;
	else
		return function(x-1)+2;
} 

int main(){
	int result,x;
	scanf("%d",&x);
	result = function(x);
	printf("%d",result);
	return 0;
}
```

![image-20240822160438336](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822160438336.png)

##### 45. 求矩阵的两对角线上的元素之和

```c
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define COLS 10

int matrix_sum(int **matrix,int len){
	int sum=0,res1=0,res2=0;
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(i==j)
				res1 += matrix[i][j];
			if ( (i+j) == (len+1) )
				res2 += matrix[i][j];
		}
	}
	sum = res1+res2;
	if(len%2==1){
		int middle=len/2;
		sum -= matrix[middle][middle];
	}	
	return sum;
}

int main(){
	int N;
	scanf("%d",&N);
	int **arr=(int**)malloc(N*sizeof(int*));
	
	for(int i=0;i<N;i++){
		arr[i]=(int*)malloc(N*sizeof(int));
		//为每一行分配内存
		for(int j=0;j<N;j++){
			scanf("%d",&arr[i][j]);
		} 
	}
	int sum=matrix_sum(arr,N);
	printf("%d",sum);
	//释放内存
	for(int i=0;i<N;i++){
		free(arr[i]);
	} 
	free(arr);
	
	return 0;
}
```

![image-20240822165322823](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822165322823.png)

##### 46.求出1-N中的所有素数

```c
#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int is_prime(int num){
	if(num<=1)
		return false;
	if(num==2)
		return true;
	if(num%2==0)
		return false;
	for(int i=3;i<sqrt(num)+1;i+=2){
		if(num%i==0)
			return false;
	}
	return true;
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		if( is_prime(i) )
			printf("%d ",i);
}
```

![image-20240822183926835](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822183926835.png)

##### 47. 试求满足下述立方和不等式的m的整数解。
1^3+2^3+...+m^3〈=n
本题算法如下：
对指定的n，设置求和循环，从i=1开始，i递增1取值，把i3(或i*i*i)累加到s，直至s>=n，脱离循环作相应的打印输出。

```c
#include<stdio.h>
#define CUBE(x) ((x)*(x)*(x))

int cube_sum(int n){
	int i=1,sum=0;
	while(sum<=n){
		sum += CUBE(i);
		i++;
	}
	return i-2;
}
int main(){
	int n;
	scanf("%d",&n);
	int result=cube_sum(n);
	printf("%d",result);
	return 0;
}
```

![image-20240822190941922](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822190941922.png)

##### 48. 编写一个程序判断一个数是否为素数

```c
#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool is_prime(int num){
	if(num<=1)
		return false;
	if(num==2)
		return false;
	if(num%2==0)
		return false;
	for(int i=3;i<=sqrt(num)+1;i+=2)
		if(num%i==0)
			return false;
	return true;
}
int main(){
	int num;
	scanf("%d",&num);
	if(is_prime)
		printf("1");
	else
		printf("0");
	return 0;
}
```

![image-20240822191715084](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822191715084.png)

##### 49.自守数是指一个数的平方的尾数等于该数自身的自然数。
例如：
25^2=625
76^2=5776
9376^2=87909376
请求出200000以内的自守数?

```c
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int num_of_digit(int n){
	int count=0;
	while(n>0){
		count++;
		n /= 10;
	}
	return count;
}

bool self_adjoint(int num){
	int temp=pow(num,2);
	int num_digit=num_of_digit(num);
	
	int last_past=temp%(int)pow(10,num_digit);
	
	if( last_past == num)
		return true;
	else
		return false;	
}

int main(){
	for(int i=0;i<=200000;i++){
		if (self_adjoint(i))
			printf("%d ",i);
	}
	return 0;
}
```

![image-20240822194145676](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822194145676.png)

##### 50. 一个球从100m高度自由落下,每次落地后反跳回原来高度的一半,再落下,再反弹.求它在第N次落地时共经过多少米?

```c
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int N;
	scanf("%d",&N);
	
	double *gap=(double*)malloc((N+1)*sizeof(double));
	gap[0]=100.0;
	for(int i=1;i<=N;i++){
		gap[i]=gap[i-1]/2.0;
	}
	
	double distance=-100.0;
	for(int i=0;i<N;i++){
		distance += 2.0*gap[i];
	}
	printf("%.4lf",distance);
	free(gap);
	return 0;
} 
```

![image-20240822211856764](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822211856764.png)

##### 51. 相传国际象棋是古印度舍罕王的宰相达依尔发明的.舍罕王十分喜爱象棋,决定让宰相自己选择何种赏赐.这位聪明的宰相指着8*8共64格的象棋说:陛下,请您赏给我一些麦子吧.就在棋盘的第1格放1粒,第2格放2粒,第三格放4粒,以后每一格都比前一格增加一位,依此放完棋盘一64格,我就感激不尽了.舍罕王让人扛了一袋麦子,他要兑现他的许诺.
请问,国王要兑现他的许诺共要多少粒麦子赏赐他的宰相?

```c
#include<stdio.h>
#include<math.h>

int main(){
	long sum=0;
	for(int i=0;i<64;i++)
		sum += pow(2,i);
	printf("%ld",sum);
	return 0;
}
```

##### 52. 角谷猜想:
日本一位中学生发现一个奇妙的“定理”，请角谷教授证明，而教授无能为力，于是产生角谷猜想。猜想的内容是：任给一个自然数，若为偶数除以2，若为奇数则乘3加1，得到一个新的自然数后按照上面的法则继续演算，若干次后得到的结果必然为1。请编程验证。

```c
#include<stdio.h>

void collatz(int num){
	while(num!=1){
		if (num%2==0){
			printf("%d/2=%d\n",num,num/2);
			return collatz(num/2);
		}
		else{
			printf("%d*3+1=%d\n",num,num*3+1);
			return collatz(num*3+1);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	collatz(n);
}
```

![image-20240822221228102](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822221228102.png)

##### 53.编写一个程序，计算1977！的值，

```python
# 初始化结果为1
result = 1

# 计算1977的阶乘
for i in range(1, 1978):
    result *= i

# 输出结果
print(result)
```

##### 54. 计算1~N之间所有奇数之和

```c
#include<stdio.h>

int main(){
	int N,sum=0;
	scanf("%d",&N);
	for(int i=1;i<=N;i+=2)
		sum += i;
	printf("%d",sum);
	return 0;
}
```

![image-20240822232624959](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822232624959.png)

##### 55.计算t=1+1/2+1/3+...+1/n

```c
#include<stdio.h>

int main(){
	double t=0.0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		t += 1.0/i;
	printf("%.6lf",t);
	return 0;
}
```

![image-20240822233020299](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822233020299.png)

##### 56.计算一个整数N的阶乘

```c
#include<stdio.h>

int fac(int n){
	int result=1;
	for(int i=1;i<=n;i++)
		result *= i;
	return result;
}
int main(){
	int N;
	scanf("%d",&N);
	int result=fac(N);
	printf("%d",result);
	return 0;
}
```

![image-20240822233312913](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240822233312913.png)

##### 57. 计算：t=1-1/(2*2)-1/(3*3)-...-1/(m*m)

```c
#include<stdio.h>
#include<math.h>

int main(){
	int m;
	scanf("%d",&m);
	double t,sum=1.0;
	for(int i=2;i<=m;i++){
		sum += 	(-1.0)/pow(i,2);
	} 
	printf("%.6lf",sum);
	return 0;
} 
```

![image-20240823090239014](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823090239014.png)

##### 58. 一个正整数如果等于组成它的各位数字的阶乘之和，该整数称为阶乘和数。
例如，145=1!+4!+5!，则145是一个三位阶乘和数。
请问:共有多少个阶乘和数？（不会超过十万）

```c
#include <stdio.h>
#include <stdlib.h>

// 计算一个数字的阶乘
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// 计算一个数字的各位数字的阶乘之和
int fac_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += factorial(n % 10);
        n /= 10;
    }
    return sum;
}

// 比较两个整数用于排序
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int numbers[100000]; // 存储阶乘和数
    int count = 0; // 阶乘和数的计数

    // 遍历所有可能的数字
    for (int i = 1; i <= 100000; i++) {
        if (i == fac_sum(i)) {
            numbers[count++] = i;
        }
    }

    // 对阶乘和数进行排序
    qsort(numbers, count, sizeof(int), compare);

    // 按字典序输出阶乘和数
    for (int i = 0; i < count; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", numbers[i]);
    }
    printf("\n");

    return 0;
}
```

![image-20240823105304505](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823105304505.png)

##### 59.如果一个正整数等于其各个数字的立方和，则称该数为阿姆斯特朗数(亦称为自恋性数)。
如 407=4^3+0^3+7^3就是一个阿姆斯特朗数。试编程求大于1小于1000的所有阿姆斯特朗数。

```c
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool Armstrong(int n){
	int temp=n,sum=0;
	int numCount=0;
	//计算n的位数
	temp=n;
	while(temp>0){
		numCount++;
		temp /= 10;
	} 
	//重置temp为n的值
	temp=n;
	while(temp>0){
		int digit=temp%10;
		sum += pow(digit,numCount);
		temp /= 10;
	} 
	if(sum==n)
		return true;
	else
		return false;
}

int main(){
	for(int i=1;i<1000;i++){
		if(Armstrong(i))
			printf("%d ",i);
	}
	return 0;
}
```

![image-20240823110944511](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823110944511.png)

##### 60.根据输入的半径值，计算球的体积。

```c
#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793

int main(){
	double rad;
	while( scanf("%lf",&rad)==1 ){
		double vol=(4.0/3.0)*PI*pow(rad,3);
		printf("%.3lf\n",vol);
	}
	return 0;
} 
```

![image-20240823135626177](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823135626177.png)

##### 61 .  给定含有n个元素的多重集合S，每个元素在S中出现的次数称为该元素的重数。多重集S中重数最大的元素称为众数。
例如，S={1，2，2，2，3，5}。多重集S的众数是2，其重数为3。
编程任务：
对于给定的由n 个自然数组成的多重集S，编程计算S 的众数及其重数。

```c
#include<stdio.h>
#include<stdlib.h>

int *findMode(int *arr,int n){
	int maxCount=0;
	int mode=arr[0];
	//用于统计每个元素的出现次数 
	int *count=(int*)calloc(n,sizeof(int));
	
	//统计每个元素的出现次数
	for(int i=0;i<n;i++)
		count[ arr[i] ]++ ;
		
	//找到出现次数最多的元素
	for(int i=0;i<n;i++){
		if( count[arr[i]]>maxCount ){
			maxCount = count[arr[i]];
			mode = arr[i];
		}
	} 
	static int result[2];
	result[0]=mode;
	result[1]=maxCount;
	
	free(count);
	return result;
}

int main(){
	int n;
	scanf("%d",&n);
	int *arr=(int*)malloc(n*sizeof(int));	
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	int *lyst = findMode(arr,n);
	printf("%d\n",lyst[0]);
	printf("%d\n",lyst[1]);
	
	free(arr);
	return 0;
}
```

![image-20240823150032188](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823150032188.png)

##### 62.将C程序代码中的双斜杠注释去掉。

```c
#include<stdio.h>
#include<string.h>

int main(){
	char A[100][201]; //用于保存真正的代码
	char B[201];
	int i,j=0;
	while( gets(B) ){ // 多次输入，每次获取一行 
		int len = strlen(B);
		for (i=0;i<len;i++){
			if (B[i]=='/' && B[i+1]=='/'){ //判断注释符
				break; 
			}
		}
		if (i==0){ //若注释符从下标0开始，则不保存，直接跳过 
			continue;
		}
		strncpy( A[j++],B,i ); //反之，则保存 
	}
	for (i=0;i<j;i++){
		printf("%s\n",A[i]);
	}
	return 0; 
}
```

![image-20240823152436353](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823152436353.png)

##### 63.读入一些字符串，将其中的空格去掉。

```c
#include<stdio.h>
#include<string.h>

void fun(char a[])
{
	int i,j;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]==' ')
		{
			for(j=i;j<strlen(a)-1;j++)
				a[j]=a[j+1];
			a[j]='\0';
		}
	}
}

int main()
{
	char a[101];
	while(gets(a))
	{
		fun(a);
		puts(a);
	}
	return 0;
}
```

![image-20240823153541336](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823153541336.png)

### *困难题*

##### 64.`n` 个孩子站成一排。给你一个整数数组 `ratings` 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

- 每个孩子至少分配到 `1` 个糖果。
- 相邻两个孩子评分更高的孩子会获得更多的糖果。

请你给每个孩子分发糖果，计算并返回需要准备的 **最少糖果数目** 。

 

**示例 1：**

```
输入：ratings = [1,0,2]
输出：5
解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
```

**示例 2：**

```
输入：ratings = [1,2,2]
输出：4
解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
```

```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int candy(int* ratings, int ratingsSize) {
    int left[ratingsSize];
    for (int i = 0; i < ratingsSize; i++) {
        if (i > 0 && ratings[i] > ratings[i - 1]) {
            left[i] = left[i - 1] + 1;
        } else {
            left[i] = 1;
        }
    }
    int right = 0, ret = 0;
    for (int i = ratingsSize - 1; i >= 0; i--) {
        if (i < ratingsSize - 1 && ratings[i] > ratings[i + 1]) {
            right++;
        } else {
            right = 1;
        }
        ret += fmax(left[i], right);
    }
    return ret;
}

int main(){
    int ratings[] = {1, 0, 2}; // 测试数据
    int ratingsSize = sizeof(ratings) / sizeof(ratings[0]);
    int result = candy(ratings, ratingsSize);
    printf("Minimum number of candies: %d\n", result);
    return 0;
}

```

![image-20240823201834262](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823201834262.png)



##### 65.接雨水：给定 `n` 个非负整数表示每个宽度为 `1` 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

**示例 1：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png)

```
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
```

**示例 2：**

```
输入：height = [4,2,0,3,2,5]
输出：9
```

```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<string.h>

int trap(int* height, int heightSize) {
    int n = heightSize;
    if (n == 0) {
        return 0;
    }
    int leftMax[n];
    memset(leftMax, 0, sizeof(leftMax));
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = fmax(leftMax[i - 1], height[i]);
    }

    int rightMax[n];
    memset(rightMax, 0, sizeof(rightMax));
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = fmax(rightMax[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += fmin(leftMax[i], rightMax[i]) - height[i];
    }
    return ans;
}

int main(){
	int height[12]={0,1,0,2,1,0,1,3,2,1,2,1};
	int result=trap(height,12);
	printf("%d",result);
	return 0;
} 
```

![image-20240823223253390](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823223253390.png)



##### 66. 文本左右对齐：给定一个单词数组 `words` 和一个长度 `maxWidth` ，重新排版单词，使其成为每行恰好有 `maxWidth` 个字符，且左右两端对齐的文本。

你应该使用 “**贪心算法**” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 `' '` 填充，使得每行恰好有 *maxWidth* 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入**额外的**空格。

**注意:**

- 单词是指由非空格字符组成的字符序列。
- 每个单词的长度大于 0，小于等于 *maxWidth*。
- 输入单词数组 `words` 至少包含一个单词。

 

**示例 1:**

```
输入: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
```

**示例 2:**

```
输入:words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
```

**示例 3:**

```
输入:words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]，maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
```

```python
# python  , c语言完成此题挺麻烦的
# blank 返回长度为 n 的由空格组成的字符串
def blank(n: int) -> str:
    return ' ' * n

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ans = []
        right, n = 0, len(words)
        while True:
            left = right  # 当前行的第一个单词在 words 的位置
            sumLen = 0  # 统计这一行单词长度之和
            # 循环确定当前行可以放多少单词，注意单词之间应至少有一个空格
            while right < n and sumLen + len(words[right]) + right - left <= maxWidth:
                sumLen += len(words[right])
                right += 1

            # 当前行是最后一行：单词左对齐，且单词之间应只有一个空格，在行末填充剩余空格
            if right == n:
                s = " ".join(words[left:])
                ans.append(s + blank(maxWidth - len(s)))
                break

            numWords = right - left
            numSpaces = maxWidth - sumLen

            # 当前行只有一个单词：该单词左对齐，在行末填充空格
            if numWords == 1:
                ans.append(words[left] + blank(numSpaces))
                continue

            # 当前行不只一个单词
            avgSpaces = numSpaces // (numWords - 1)
            extraSpaces = numSpaces % (numWords - 1)
            s1 = blank(avgSpaces + 1).join(words[left:left + extraSpaces + 1])  # 拼接额外加一个空格的单词
            s2 = blank(avgSpaces).join(words[left + extraSpaces + 1:right])  # 拼接其余单词
            ans.append(s1 + blank(avgSpaces) + s2)

        return ans

```

![image-20240823224621562](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823224621562.png)

##### 67 .给定一个单词数组 `words` 和一个长度 `maxWidth` ，重新排版单词，使其成为每行恰好有 `maxWidth` 个字符，且左右两端对齐的文本。

你应该使用 “**贪心算法**” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 `' '` 填充，使得每行恰好有 *maxWidth* 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入**额外的**空格。

**注意:**

- 单词是指由非空格字符组成的字符序列。
- 每个单词的长度大于 0，小于等于 *maxWidth*。
- 输入单词数组 `words` 至少包含一个单词。

**示例 1:**

```
输入: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
```

**示例 2:**

```
输入:words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
```

**示例 3:**

```
输入:words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]，maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
```

```python
# Python ，c语言完成此题挺麻烦的
# blank 返回长度为 n 的由空格组成的字符串
def blank(n: int) -> str:
    return ' ' * n

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ans = []
        right, n = 0, len(words)
        while True:
            left = right  # 当前行的第一个单词在 words 的位置
            sumLen = 0  # 统计这一行单词长度之和
            # 循环确定当前行可以放多少单词，注意单词之间应至少有一个空格
            while right < n and sumLen + len(words[right]) + right - left <= maxWidth:
                sumLen += len(words[right])
                right += 1

            # 当前行是最后一行：单词左对齐，且单词之间应只有一个空格，在行末填充剩余空格
            if right == n:
                s = " ".join(words[left:])
                ans.append(s + blank(maxWidth - len(s)))
                break

            numWords = right - left
            numSpaces = maxWidth - sumLen

            # 当前行只有一个单词：该单词左对齐，在行末填充空格
            if numWords == 1:
                ans.append(words[left] + blank(numSpaces))
                continue

            # 当前行不只一个单词
            avgSpaces = numSpaces // (numWords - 1)
            extraSpaces = numSpaces % (numWords - 1)
            s1 = blank(avgSpaces + 1).join(words[left:left + extraSpaces + 1])  # 拼接额外加一个空格的单词
            s2 = blank(avgSpaces).join(words[left + extraSpaces + 1:right])  # 拼接其余单词
            ans.append(s1 + blank(avgSpaces) + s2)

        return ans

```

![image-20240823224934591](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823224934591.png)

##### 68. [ 串联所有单词的子串](https://leetcode.cn/problems/substring-with-concatenation-of-all-words/)

给定一个字符串 `s` 和一个字符串数组 `words`**。** `words` 中所有字符串 **长度相同**。

 `s` 中的 **串联子串** 是指一个包含 `words` 中所有字符串以任意顺序排列连接起来的子串。

- 例如，如果 `words = ["ab","cd","ef"]`， 那么 `"abcdef"`， `"abefcd"`，`"cdabef"`， `"cdefab"`，`"efabcd"`， 和 `"efcdab"` 都是串联子串。 `"acdbef"` 不是串联子串，因为他不是任何 `words` 排列的连接。

返回所有串联子串在 `s` 中的开始索引。你可以以 **任意顺序** 返回答案。

**示例 1：**

```
输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
输出顺序无关紧要。返回 [9,0] 也是可以的。
```

**示例 2：**

```
输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]
解释：因为 words.length == 4 并且 words[i].length == 4，所以串联子串的长度必须为 16。
s 中没有子串长度为 16 并且等于 words 的任何顺序排列的连接。
所以我们返回一个空数组。
```

**示例 3：**

```
输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]
解释：因为 words.length == 3 并且 words[i].length == 3，所以串联子串的长度必须为 9。
子串 "foobarthe" 开始位置是 6。它是 words 中以 ["foo","bar","the"] 顺序排列的连接。
子串 "barthefoo" 开始位置是 9。它是 words 中以 ["bar","the","foo"] 顺序排列的连接。
子串 "thefoobar" 开始位置是 12。它是 words 中以 ["the","foo","bar"] 顺序排列的连接。
```

```python
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        res = []
        m, n, ls = len(words), len(words[0]), len(s)
        for i in range(n):
            if i + m * n > ls:
                break
            differ = Counter()
            for j in range(m):
                word = s[i + j * n: i + (j + 1) * n]
                differ[word] += 1
            for word in words:
                differ[word] -= 1
                if differ[word] == 0:
                    del differ[word]
            for start in range(i, ls - m * n + 1, n):
                if start != i:
                    word = s[start + (m - 1) * n: start + m * n]
                    differ[word] += 1
                    if differ[word] == 0:
                        del differ[word]
                    word = s[start - n: start]
                    differ[word] -= 1
                    if differ[word] == 0:
                        del differ[word]
                if len(differ) == 0:
                    res.append(start)
        return res

```

![image-20240823225025524](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823225025524.png)

##### 69. 最小覆盖子串

给你一个字符串 `s` 、一个字符串 `t` 。返回 `s` 中涵盖 `t` 所有字符的最小子串。如果 `s` 中不存在涵盖 `t` 所有字符的子串，则返回空字符串 `""` 。

**注意：**

- 对于 `t` 中重复字符，我们寻找的子字符串中该字符数量必须不少于 `t` 中该字符数量。
- 如果 `s` 中存在这样的子串，我们保证它是唯一的答案。

**示例 1：**

```
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
```

**示例 2：**

```
输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。
```

**示例 3:**

```
输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
```

```python
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ans_left, ans_right = -1, len(s)
        left = 0
        cnt_s = Counter()  # s 子串字母的出现次数
        cnt_t = Counter(t)  # t 中字母的出现次数
        for right, c in enumerate(s):  # 移动子串右端点
            cnt_s[c] += 1  # 右端点字母移入子串
            while cnt_s >= cnt_t:  # 涵盖
                if right - left < ans_right - ans_left:  # 找到更短的子串
                    ans_left, ans_right = left, right  # 记录此时的左右端点
                cnt_s[s[left]] -= 1  # 左端点字母移出子串
                left += 1  # 移动子串左端点
        return "" if ans_left < 0 else s[ans_left: ans_right + 1]
```

![image-20240823225441548](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823225441548.png)

##### 70 .基本计算器

给你一个字符串表达式 `s` ，请你实现一个基本计算器来计算并返回它的值。

注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 `eval()` 。

**示例 1：**

```
输入：s = "1 + 1"
输出：2
```

**示例 2：**

```
输入：s = " 2-1 + 2 "
输出：3
```

**示例 3：**

```
输入：s = "(1+(4+5+2)-3)+(6+8)"
输出：23
```

```c
int calculate(char* s) {
    int n = strlen(s);
    int ops[n], top = 0;
    int sign = 1;
    ops[top++] = sign;

    int ret = 0;
    int i = 0;
    while (i < n) {
        if (s[i] == ' ') {
            i++;
        } else if (s[i] == '+') {
            sign = ops[top - 1];
            i++;
        } else if (s[i] == '-') {
            sign = -ops[top - 1];
            i++;
        } else if (s[i] == '(') {
            ops[top++] = sign;
            i++;
        } else if (s[i] == ')') {
            top--;
            i++;
        } else {
            long num = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                i++;
            }
            ret += sign * num;
        }
    }
    return ret;
}

```

![image-20240823225907932](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823225907932.png)

##### 71. K 个一组翻转链表

给你链表的头节点 `head` ，每 `k` 个节点一组进行翻转，请你返回修改后的链表。

`k` 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 `k` 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg)

```
输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg)

```
输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
```

```python
class Solution:
    # 翻转一个子链表，并且返回新的头与尾
    def reverse(self, head: ListNode, tail: ListNode):
        prev = tail.next
        p = head
        while prev != tail:
            nex = p.next
            p.next = prev
            prev = p
            p = nex
        return tail, head

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        hair = ListNode(0)
        hair.next = head
        pre = hair

        while head:
            tail = pre
            # 查看剩余部分长度是否大于等于 k
            for i in range(k):
                tail = tail.next
                if not tail:
                    return hair.next
            nex = tail.next
            head, tail = self.reverse(head, tail)
            # 把子链表重新接回原链表
            pre.next = head
            tail.next = nex
            pre = tail
            head = tail.next
        
        return hair.next

```

![image-20240823230132248](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823230132248.png)

##### 72.二叉树中的最大路径和

二叉树中的 **路径** 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 **至多出现一次** 。该路径 **至少包含一个** 节点，且不一定经过根节点。

**路径和** 是路径中各节点值的总和。

给你一个二叉树的根节点 `root` ，返回其 **最大路径和** 。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/10/13/exx1.jpg)

```
输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg)

```
输入：root = [-10,9,20,null,null,15,7]
输出：42
解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
```

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.maxSum = float("-inf")

    def maxPathSum(self, root: TreeNode) -> int:
        def maxGain(node):
            if not node:
                return 0

            # 递归计算左右子节点的最大贡献值
            # 只有在最大贡献值大于 0 时，才会选取对应子节点
            leftGain = max(maxGain(node.left), 0)
            rightGain = max(maxGain(node.right), 0)
            
            # 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
            priceNewpath = node.val + leftGain + rightGain
            
            # 更新答案
            self.maxSum = max(self.maxSum, priceNewpath)
        
            # 返回节点的最大贡献值
            return node.val + max(leftGain, rightGain)
   
        maxGain(root)
        return self.maxSum


```

![image-20240823230346755](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823230346755.png)

##### 73. 删除有序数组中的重复项 

给你一个有序数组 `nums` ，请你**[ 原地](http://baike.baidu.com/item/原地算法)** 删除重复出现的元素，使得出现次数超过两次的元素**只出现两次** ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 **[原地 ](https://baike.baidu.com/item/原地算法)修改输入数组** 并在使用 O(1) 额外空间的条件下完成。

**说明：**

为什么返回数值是整数，但输出的答案是数组呢？

请注意，输入数组是以**「引用」**方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

```
// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

**示例 1：**

```
输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。
```

**示例 2：**

```
输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前七个元素被修改为 0, 0, 1, 1, 2, 3, 3。不需要考虑数组中超出新长度后面的元素。
```

```c
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }
    int slow = 2, fast = 2;
    while (fast < numsSize) {
        if (nums[slow - 2] != nums[fast]) {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}
```

![image-20240823230633389](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823230633389.png)

##### 74. 轮转数组

给定一个整数数组 `nums`，将数组中的元素向右轮转 `k` 个位置，其中 `k` 是非负数。

**示例 1:**

```
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
```

**示例 2:**

```
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]
```

```c
void rotate(int* nums, int numsSize, int k) {
    int newArr[numsSize];
    for (int i = 0; i < numsSize; ++i) {
        newArr[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; ++i) {
        nums[i] = newArr[i];
    }
}
```

![image-20240823231326629](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20240823231326629.png)
