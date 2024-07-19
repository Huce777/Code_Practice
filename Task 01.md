### *Task 01 “Hello World !” 输出*

*print 函数用于输出；*

*语法说明如下：*

  	*print ( *objects , sep=' ', end='\n', file=sys.stdout )*

编程实现：

#### How to Use Jupyter Notebooks: The Ultimate Guide

##### Command mode and edit mode

Jupyter notebooks have two different modes of interaction: command mode and edit mode. In command mode, you can navigate between cells, add and delete cells, and change the cell type. In edit mode, you can edit the contents of a cell.

In order to enter command mode, you can either press Escape or click outside a cell. To enter edit mode, you can press Enter or click inside a cell.

In DataLab, you can click the ‘Add Text’ or ‘Add Code’ buttons to add a new cell.

## Writing text

Text cells are written in the Markdown markup language, allowing you to easily write and format text. While in edit mode, you can use syntax such as ** ** for bold, or use the buttons, to format your text. 

Here are a few different options:

![image11.png](https://images.datacamp.com/image/upload/v1678467411/image11_b4a54e034a.png)

Pressing shift + enter or the ‘View’ button will run the cell, giving the following result.

![image17.png](https://images.datacamp.com/image/upload/v1678467456/image17_5da27154ac.png)

- Lines beginning # are a top-level header. Start with ## for a second-level header, ### for a third-level header, and so on.
- Surround text in ** to make it bold, __ to make it italic, and ` to make it code formatted.
- Start consecutive lines with - to make them into a bulleted list.
- Start lines with numbers followed by a period to make them into a numbered list.
- Hyperlinks are written in two parts. The text to display is surrounded by square brackets, then the url is surrounded by parentheses.

## Writing and running code

Pressing ‘Add Code’ or entering a command with (escape) and pressing ‘B’ will add a new code block.

![image3.png](https://images.datacamp.com/image/upload/v1678467548/image3_36dfdb203a.png)

Write code in the cell just as you would in a script.

![image12.png](https://images.datacamp.com/image/upload/v1678467604/image12_2cc31056d8.png)

Pressing Run or CTRL/CMD+Enter runs the code and displays its output.

![image2.png](https://images.datacamp.com/image/upload/v1678467646/image2_8517f11ca9.png)

## Reading and writing files

Pressing ‘Browse and upload files’ on the left-hand menu brings up the file system, and pressing the ‘plus’ will allow you to upload a file from your local machine. Below, we have uploaded a simple text file called hello_world.txt.

![image13.png](https://images.datacamp.com/image/upload/v1678467790/image13_29907ecc8c.png)![image19.png](https://images.datacamp.com/image/upload/v1678467701/image19_38cb19af81.png)
We can use the following code to open the file, add some text, then save a new file.

![image7.png](https://images.datacamp.com/image/upload/v1678467859/image7_0ce924157e.png)
You’ll now see the new file in the file system, and it will contain our updates.

## ![image15.png](https://images.datacamp.com/image/upload/v1678467902/image15_0764423db1.png) Working with the File System

We have shown how to upload, update and create a new file. To download the new file, press the three dots in the file system and hit download.

![image18.png](https://images.datacamp.com/image/upload/v1678467948/image18_42abb0180d.png)
The plus button used to create new files can also be used to create fresh notebooks, which will have no cells or output. 

![image4.png](https://images.datacamp.com/image/upload/v1678467993/image4_8e0a7851ce.png)

### *PyCharm Using*

# Create and run your first project﻿

Last modified: 28 June 2024

## Before you start﻿

Ensure that the following prerequisites are met:

- You are working with [PyCharm](https://www.jetbrains.com/pycharm/) Community or Professional
- You have installed Python itself. If you're using macOS or Linux, your computer already has Python installed. You can get Python from [python.org](http://python.org/download/).

To get started with PyCharm, let’s write a Python script.

## Create a Python project﻿

1. If you’re on the [Welcome screen](https://www.jetbrains.com/help/pycharm/welcome-screen.html), click New Project. If you’ve already got any project open, choose File | New Project from the main menu.

2. Although you can create projects of various types in PyCharm, in this tutorial let's create a simple Pure Python project. This template will create an empty project.

   ![Create a new project](https://resources.jetbrains.com/help/img/idea/2024.1/py_new_python_file_without_main.png)

3. Choose the project location. Click ![the Browse button](https://resources.jetbrains.com/help/img/idea/2024.1/app.expui.inline.browse.svg) in the Location field and specify the directory for your project.

4. Python best practice is to create a dedicated environment for each project. In most cases, the default Project venv will do the job, and you won't need to configure anything.

   Still, you can switch to Custom environment to be able to use an existing environment, select other environment types, specify the environment location, and modify other options.

   ![Custom environment options for the new Python project](https://resources.jetbrains.com/help/img/idea/2024.1/py_create_python_project_custom_env.png)

   > ### 
   >
   > 
   >
   > If PyCharm detects no Python on your machine, it provides the following options:
   >
   > - Specify a path to the Python executable (in case of non-standard installation)
   > - Download and install the latest Python versions from [python.org](http://python.org/)
   > - Install Python using the Command-Line Developer Tools (macOS only).

   For more information, refer to [Configure a Python interpreter](https://www.jetbrains.com/help/pycharm/configuring-python-interpreter.html).

   For now, let's keep the default Project venv option.

5. Click Create when you are ready.

If you’ve already got a project open, after clicking Create PyCharm will ask you whether to open a new project in the current window or in a new one. Choose Open in current window - this will close the current project, but you'll be able to reopen it later.

For more information, refer to [Open, reopen, and close projects](https://www.jetbrains.com/help/pycharm/open-projects.html).

## Create a Python file﻿

1. In the Project tool window, select the project root (typically, it is the root node in the project tree), right-click it, and select File | New ....

   ![Create a Python file](https://resources.jetbrains.com/help/img/idea/2024.1/py_create_class.png)

2. Select the option Python File from the context menu, and then type the new filename.

   ![Creating a new Python file](https://resources.jetbrains.com/help/img/idea/2024.1/py_create_new_python_file.png)

   PyCharm creates a new Python file and opens it for editing.

   ![New Python file](https://resources.jetbrains.com/help/img/idea/2024.1/py_create_class_open.png)

## Edit Python code﻿

Let's start editing the Python file you've just created.

1. Start with declaring a class. Immediately as you start typing, PyCharm suggests how to complete your line:

   ![Create class completion](https://resources.jetbrains.com/help/img/idea/2024.1/py_create_class_completion.png)

   Choose the keyword `class` and type the class name, `Car`.

2. PyCharm informs you that there are errors in your file:

   ![Create class analysis](https://resources.jetbrains.com/help/img/idea/2024.1/py_create_class_analysis.png)

   Note that PyCharm analyzes your code on-the-fly, the results are immediately shown in the inspection indicator in the upper-right corner of the editor.

   This inspection indication works like a traffic light: when it is green, everything is OK, and you can go on with your code; a yellow light means some minor problems that however will not affect compilation; but when the light is red, it means that you have some serious errors.

   Click it to preview the details in the Problems tool window. There's a missing colon, then an indentation is expected:

   ![View code problems](https://resources.jetbrains.com/help/img/idea/2024.1/py_view_problems.png)

3. Let's continue by creating the `__init__` function for the class: when you start typing the function's name, PyCharm suggests pasting the entire code construct including the mandatory `self` parameter, the closing parenthesis, and the colon:

   ![Create class](https://resources.jetbrains.com/help/img/idea/2024.1/py_create_class_demo.png)

4. If you notice any inspection warnings as you're editing your code, click the bulb symbol to preview the list of possible fixes and recommended actions:

   ![Intention actions](https://resources.jetbrains.com/help/img/idea/2024.1/py_view_intention_actions.png)

5. Let's copy and paste the entire code sample. Hover over the upper-right corner of the code block below, click the copy icon, and then paste the code into the PyCharm editor replacing the content of the **Car.py** file:

   > ### 
   >
   > 
   >
   > This application is intended for Python 3

   ```python
   class Car:
   
       def __init__(self, speed=0):
           self.speed = speed
           self.odometer = 0
           self.time = 0
   
       def accelerate(self):
           self.speed += 5
   
       def brake(self):
           self.speed -= 5
   
       def step(self):
           self.odometer += self.speed
           self.time += 1
   
       def average_speed(self):
           return self.odometer / self.time
   
   
   if __name__ == '__main__':
   
       my_car = Car()
       print("I'm a car!")
       while True:
           action = input("What should I do? [A]ccelerate, [B]rake, "
                           "show [O]dometer, or show average [S]peed?").upper()
           if action not in "ABOS" or len(action) != 1:
               print("I don't know how to do that")
               continue
           if action == 'A':
               my_car.accelerate()
               print("Accelerating...")
           elif action == 'B':
               my_car.brake()
               print("Braking...")
           elif action == 'O':
               print("The car has driven {} kilometers".format(my_car.odometer))
           elif action == 'S':
               print("The car's average speed was {} kph".format(my_car.average_speed()))
           my_car.step()
   ```

   

At this point, you're ready to run your first Python application in PyCharm.

## Run your application﻿

Use either of the following ways to run your code:

- Right-click the editor and select Run 'Car' from the context menu .

- Press CtrlShiftF10.

- Since this Python script contains a main function, you can click ![img](https://resources.jetbrains.com/help/img/idea/2024.1/app.expui.gutter.run.svg) in the gutter.

  You'll see the popup menu of the available commands. Choose Run 'Car':

  ![Run command](https://resources.jetbrains.com/help/img/idea/2024.1/py_run_script1.png)

PyCharm executes your code in the [Run tool window](https://www.jetbrains.com/help/pycharm/run-tool-window.html).

![Run Tool window](https://resources.jetbrains.com/help/img/idea/2024.1/py_run_car_console.png)

Here you can enter the expected values and preview the script output.

Note that PyCharm has created a temporary run/debug configuration for the **Car** file.

![Temporary run/debug configuration](https://resources.jetbrains.com/help/img/idea/2024.1/py_temp_run_debug_configuration.png)

The run/debug configuration defines the way PyCharm executes your code. You can save it to make it a permanent configuration or modify its parameters. For more information about running Python code, refer to [Run/debug configurations](https://www.jetbrains.com/help/pycharm/run-debug-configuration.html).