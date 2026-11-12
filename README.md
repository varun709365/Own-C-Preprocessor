## Repository 2: C Preprocessor

Suggested repository name: `custom-c-preprocessor`

````markdown
# Custom C Preprocessor

A modular preprocessor tool written in C. It processes a C source file by removing comments, expanding included files, and substituting macros.

The final executable is named `mypreprocessor`.

## Features

- Remove single-line comments beginning with `//`
- Remove multi-line comments enclosed by `/*` and `*/`
- Preserve the readability of the remaining source code
- Process file inclusion directives
- Replace an `#include` directive with the included file's contents
- Store and substitute object-like macros
- Support function-like macros with arguments
- Generate a preprocessed file with the `.i` extension
- Accept the source filename as a command-line argument
- Use separate modules for different preprocessing operations

## Supported Directives

### File Inclusion

```c
#include <filename>
The specified file is opened, and its contents replace the #include line in the generated output.

Simple Macros
c


#define PI 3.14
Subsequent occurrences of PI are replaced with 3.14.

Function-Like Macros
c


#define SQUARE(x) ((x) * (x))
A usage such as:

c


SQUARE(5)
is expanded using the macro definition.

Project Structure
text


custom-c-preprocessor/
├── main.c
├── comment_removal.c
├── comment_removal.h
├── macro_handler.c
├── macro_handler.h
├── file_inclusion.c
├── file_inclusion.h
├── preprocessor.c
├── preprocessor.h
├── Makefile
└── README.md
The exact module names may differ, but comment removal, file inclusion, macro processing, and overall program control should remain separated.

Compilation
Build the project using the supplied Makefile:

bash


make
The command creates the executable:

text


mypreprocessor
Usage
bash


./mypreprocessor inputfile.c
For an input file named inputfile.c, the program creates:

text


inputfile.i
Example
Input: example.c
c


#include <stdio.h>

#define PI 3.14
#define SQUARE(x) ((x) * (x))

// Program entry point
int main(void)
{
    /* Calculate the area of a circle. */
    float area = PI * SQUARE(5);
    printf("%f\n", area);
    return 0;
}
Run the Preprocessor
bash


./mypreprocessor example.c
Generated Output
text


example.i
The generated file contains the processed source after comment removal, file inclusion, and macro substitution.

Processing Stages
Read the input filename from the command line.
Open the source file.
Remove single-line and multi-line comments.
Process file inclusion directives.
Store macro definitions.
Substitute subsequent macro usages.
Write the processed source to a .i file.
Release allocated resources and close all files.
Error Handling
The program should report errors for cases such as:

Missing command-line arguments
Input file not found
Included file not found
Invalid macro definitions
Output file creation failure
Memory allocation failure
Concepts Used
Command-line arguments
File handling
String processing
Macro storage and substitution
Dynamic memory allocation
Modular programming
Header files
Makefiles
