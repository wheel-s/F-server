# Overview
F-server is a command-linr utility built in C designed for fundamental local file and directory management. it performs common task such as listing directory contents, retrieving file metadata, and is intendend to serve as  the **core logic foundation for a future network-accessible file srever.

## prerequisites

* ** GCC

## Building the project

1. Clone the repo.
2. run  ```gcc -o file src/main.c src/operation.c  ```


## Usage

1. List files or folders in a directory ```./file list <path>```
2. Display metadata ``` ./file info <path> ```
3. copy a file from source to destination ```./file copy <src> <dest>```
4. move a file ```./file copy <src> <dest>```
5. delete afile or empty directory  ```./file delete <path>```
