# Project: Producer and Consumer Solution

This project demonstrates a producer-consumer problem implementation using C++ threads and a ring buffer.

## Compiler and C++ Standard

- Compiler: MinGW-w64 (g++)
- C++ Standard: C++11

## Project Structure


- `main.cpp`: Main program file that contains the producer and consumer threads.
- `ring_buffer.hpp`: Header file for the ring buffer class.

## Build and Run Instructions

Follow these steps to build and run the executable:

1. **Install MinGW-w64**:
   Ensure that MinGW-w64 is installed on your system. You can download it using https://github.com/msys2/msys2-installer/releases/download/2023-05-26/msys2-x86_64-20230526.exe.

2. **Open a Command Prompt**:
   Open a command prompt or terminal.

3. **Navigate to Project Directory**:
   Use the `cd` command to navigate to the directory containing your project files.

Existing Binary: 

An existing binary file named `main.exe` is already available for direct use without compilation.
You can find it in the "project_directory\binaries" folder.
To run the binary, you can navigate to "project_directory\binaries" and run the below command :

main.exe <producer_value> <buffer_size>

4. **Build the Executable**:
Run the following command to build the executable using g++:

```sh
C:\msys64\mingw64\bin\g++.exe -fdiagnostics-color=always -g -std=c++11 main.cpp -o main.exe

main.exe <producer_value> <buffer_size>

main.exe 10 4 (example)






