### *Task 04 摄氏度与华氏度的转换*

- $$
  - 华氏度 = 摄氏度 × 9/5 + 32
  - 摄氏度 = (华氏度 - 32) ÷ 1.8
  $$

  ```python
  #华氏度 = 摄氏度 × 9/5 + 32
  #摄氏度 = (华氏度 - 32) ÷ 1.8
  def convert_temperature():
      unit = input("请输入温度单位（Celsius 或 Fahrenheit）：")
      temp = float(input("请输入温度值："))
  
      if unit.upper() == "CELSIUS":
          fahrenheit = (temp * 9 / 5) + 32
          print(f"{temp}°C 将会被转换为 {fahrenheit:.3f}°F")
      elif unit.upper() == "FAHRENHEIT":
          celsius = (temp - 32) * 5 / 9
          print(f"{temp}°F 将会被转换为 {celsius:.3f}°C")
      else:
          print("无效的单位输入")
  
  convert_temperature()
  ```

- *练习：对正方体，圆柱及球的体积进行计算*

在Python中，计算正方体、圆柱和球的体积可以通过数学公式实现。以下是相关的数学公式和Python代码示例：

###### 正方体体积
- 公式：V = a³
  其中 \( a \) 是正方体的边长。

###### 圆柱体积
- 公式：V = pi * r² *h
  其中 \( r \) 是圆柱的半径，\( h \) 是圆柱的高。

###### 球体积
- 公式：V = 4/3 * pi *r³
  其中 \( r \) 是球的半径。

###### Python代码示例

```python
import math

def calculate_volume(shape, dimensions):
    if shape.lower() == "cube":
        a = dimensions[0]  # 边长
        volume = a ** 3
    elif shape.lower() == "cylinder":
        r, h = dimensions  # 半径和高
        volume = math.pi * r ** 2 * h
    elif shape.lower() == "sphere":
        r = dimensions[0]  # 半径
        volume = (4 / 3) * math.pi * r ** 3
    else:
        return "未知的形状"
    return volume

# 示例
cube_side = float(input("请输入正方体的边长："))
cylinder_radius = float(input("请输入圆柱的半径："))
cylinder_height = float(input("请输入圆柱的高："))
sphere_radius = float(input("请输入球的半径："))

cube_volume = calculate_volume("cube", cube_side)
cylinder_volume = calculate_volume("cylinder", (cylinder_radius, cylinder_height))
sphere_volume = calculate_volume("sphere", sphere_radius)

print(f"正方体的体积是：{cube_volume:.2f}")
print(f"圆柱的体积是：{cylinder_volume:.2f}")
print(f"球的体积是：{sphere_volume:.2f}")
```

这段代码首先导入了`math`模块以使用π的值。然后定义了一个函数`calculate_volume`，它接受形状名称和相应的尺寸参数，计算并返回体积。最后，代码通过用户输入获取尺寸，并调用函数计算体积，然后输出结果。