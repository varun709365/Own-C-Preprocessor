Own C Preprocessor

## 📌 Project Overview

**MyPreprocessor** is a preprocessor tool developed using C programming. It processes C source files by performing three major preprocessing operations:

- Comment Removal
- File Inclusion
- Macro Substitution

The tool reads a C source file, processes the preprocessing directives, and generates an extended source file with a `.i` extension.

## 🎯 Objectives

- To understand the working of a C preprocessor.
- To remove single-line and multi-line comments.
- To implement file inclusion functionality.
- To perform macro substitution.
- To develop a modular C application using multiple source and header files.
- To use Makefile for compiling and building the project.

## ✨ Features

### 1. Comment Removal
- Removes single-line comments (`//`).
- Removes multi-line comments (`/* ... */`).
- Preserves the structure and readability of the remaining source code.

### 2. File Inclusion
- Identifies `#include` directives.
- Opens the specified header file.
- Replaces the include directive with the contents of the included file.

### 3. Macro Substitution
- Identifies and stores macro definitions using `#define`.
- Replaces macro names with their corresponding values.
- Supports simple macros.

Example:
```c
#define PI 3.14
```


## 📂 Project Structure

```text
MyPreprocessor/
│
├── main.c
├── comment_removal.c
├── comment_removal.h
├── file_inclusion.c
├── file_inclusion.h
├── macro_handler.c
├── macro_handler.h
├── Makefile
└── README.md
```

## 🛠️ Technologies Used

- Programming Language: C
- Compiler: GCC
- Operating System: Linux / Ubuntu
- Build Tool: Makefile

## ⚙️ Compilation

Compile the project using:

```bash
make
```

This creates an executable named:

```bash
mypreprocessor
```

## ▶️ Execution

Run the executable by providing the input C filename as a command-line argument.

```bash
./mypreprocessor inputfile.c
```

After successful processing, an output file will be generated:

```text
inputfile.i
```

## 📌 Example

**Input file: `inputfile.c`**

```c
#include <stdio.h>

#define PI 3.14

int main()
{
    // Calculate area
    float radius = 5;
    float area = PI * radius * radius;

    printf("Area = %f", area);

    return 0;
}
```

**Expected output file: `inputfile.i`**

The output contains the processed source code with:
- Comments removed.
- Included file contents expanded.
- Defined macros substituted with their corresponding values.

## 📚 Concepts Learned

- C Programming
- File Handling
- Command-Line Arguments (`argc`, `argv`)
- String Manipulation
- Dynamic Memory Allocation
- Modular Programming
- Header Files
- Preprocessor Directives
- Makefile and Compilation Process

## 👩‍💻 Author

Developed as a C programming project to understand the internal working of a C preprocessor.
