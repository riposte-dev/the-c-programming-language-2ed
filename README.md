# The C Programming Language (2nd Edition)
A repository made for educational use, containing coding examples and exercises from the second edition of the book *The C Programming Language* by Brian Kernighan and Dennis Ritchie.
## Compiling
### MacOS
MacOS should already have a C compiler installed. Run `cc` in terminal to check.

Compile `.c` files by running:
```bash
cc hello.c
```

This will create a file named `a.out` which you can execute by running `./a.out`.

To use `.txt` files as input for testing programs, run:
```bash
./a.out < test.txt
```
### Windows
Windows requires more steps at first as it doesn't come with a C compiler by default.

Although there are many options, we will install the [GCC](https://gcc.gnu.org/) compiler via [MinGW-w64](https://www.mingw-w64.org/getting-started/msys2/). Follow the installation process for "Windows / MSYS2 (GCC)."

To use GCC outside of MSYS2, we need to add it to our PATH environment variable:
- Use Windows search to open Control Panel.
- In Control Panel, search for "View advanced system settings" and open "Environment Variables..."
- Under "System variables," find the variable `Path`.
- Click new and add the path `C:\msys64\ucrt64\bin`.
- Press OK out of everything. Restart the terminal if necessary.

Run `cc` in terminal to check.

Compile `.c` files by running:
```shell
cc hello.c -o a.exe
```

This will create a file named `a.exe` which you can execute by running `.\a.exe`.

To use `.txt` files as input for testing programs, run:
```shell
cat test.txt | .\a.exe
```
(where the command `cat test.txt` simply retrieves the contents of `test.txt`).