# PocketMine-MP-Plugin-Template-Maker

A simple template to help you create [PocketMine-MP](https://github.com/pmmp/PocketMine-MP) plugins quickly. This tool will generate a basic structure with the required files for a `PocketMine` plugin.

## 💡 No Compilation? Download Instantly!
If you're not familiar with compiling or if you just want to skip that step, you can `download` the precompiled version of the tool directly from the [releases page](https://github.com/Jasson44/PocketMine-MP-Plugin-Template/releases/tag/1.0.0).
`Simply download the file`, and you’ll be ready to use it without any setup!

## 🚀 How to use

### 1. Install MinGW

MinGW is required to compile the source code on Windows. Follow these steps:

- Download and install [MinGW](https://sourceforge.net/projects/mingw/).
- Follow the instructions on the installation page to set it up on your system.
  
### 2. Clone this repository

Clone this repository to your local machine using `Git.` Run the following commands in your terminal:

```bash
git clone https://github.com/Jasson44/PocketMine-MP-Plugin-Template.git
cd PocketMine-MP-Plugin-Template
```

### 3. Install C++ To Exe

To compile the `create.cpp` program and create the executable PocketMine-MP Plugin Template, run the following command:
```bash
g++ create.cpp ext/tinyfiledialogs.c resources/resources.o -o "PocketMine-MP Plugin Template Maker" -lole32 -lcomdlg32
```

### 4. Customize Your Plugin
Once the plugin structure is generated, you can open and modify the following files:

- `src/Main.php`: The main PHP file for the plugin.
- `plugin.yml`: The configuration file for the plugin.
Feel free to add your own functionality and make changes to these files according to your plugin's needs.

### 5. Build and Deploy Your Plugin
After customizing your plugin, deploy it to your PocketMine-MP server. Make sure everything is configured correctly, and you should be able to run your plugin.


---
## 🧩 How to change the icon
1. Prepare your icon First, you need to prepare an icon file in `.ico` format. You can use online tools to convert an image to `.ico` format if your image is in another format like `.png` or `.jpg`.
2. Use Resource Compiler (RC) To add an icon to a C++ application on Windows, you need to use a `.rc` (Resource Script) file to declare the icon. Follow these steps:
   - Create a `.rc` file that contains the declaration for your icon. For example, create a resource.rc file and add the following code:
  ```rc
  // resources.rc
  #include <windows.h>

  IDI_ICON1 ICON "icon.ico"  //Replace with the same .ico file name
  ```
3. Modify the Makefile or Compiler Command If you're using `g++` to compile your application, you need to add the `.rc` file you just created to the compilation command. Here's an example of how to modify the compile command to include the icon:
 ```rc
windres resource.rc -o resources.o
g++ create.cpp ext/tinyfiledialogs.c resources.o -o "PocketMine-MP Plugin Template Maker" -lole32 -lcomdlg32
  ```
The `windres` command is used to convert the `.rc` file into an object file `(resources.o)` that can be linked with `g++`. **Make sure the path is the same to avoid errors**

4. Compile and Run the Application After adding the icon to your application, recompile the program using the modified `g++` command. The icon will be applied to the resulting executable.
---

### Thank you for using the **PocketMine-MP Plugin Template**! 

If you found this project helpful, feel free to `star` it on GitHub or share it with others.

---
