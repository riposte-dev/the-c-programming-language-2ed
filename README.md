# The C Programming Language (2nd Edition)
A repository made for educational use, containing coding examples and exercises from the second edition of the book *The C Programming Language* by Brian Kernighan and Dennis Ritchie.
## Setting Up
To write code, we need a code editor! Install [VS Code](https://code.visualstudio.com/), an integrated development environment (IDE).
### Extensions
Upon opening VS Code, head to the Extensions tab (Ctrl+Shift+X) and install these two extensions (they will come in handy):
- [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)
- [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)

Go to Preferences > Settings and search for the Code-runner plugin:
- Enable "Clear Previous Output"
- Enable "Save File Before Run"
### Compilers
C is a compiled language, meaning we need to turn it into machine code before executing it. The installation process is a little different for each operating system, so follow the one that matches your machine!
#### MacOS
MacOS should already have a C compiler installed. Run `clang --version` to check.

If not, run `xcode-select --install` to install Command Line Tools.
#### Linux
Linux should already have a C compiler installed. Run `gcc --version` to check.

If not, run `sudo apt-get update` and then `sudo apt-get install build-essential gdb` (Sorry `pacman` users).
#### Windows
Windows requires more steps at first as it doesn't come with a C compiler by default.

Although there are many options, we will install the [GCC](https://gcc.gnu.org/) compiler via [MinGW-w64](https://www.mingw-w64.org/getting-started/msys2/). Follow the installation process for "Windows / MSYS2 (GCC)."

To use GCC outside of MSYS2, we need to add it to our PATH environment variable:
- Use Windows search to open Control Panel.
- In Control Panel, search for "View advanced system settings" and open "Environment Variables..."
- Under "System variables," find the variable `Path`.
- Click new and add the path `C:\msys64\ucrt64\bin`.
- Press OK out of everything. Restart the terminal if necessary.

If you're having trouble, follow along [this video](https://youtu.be/2ciUcosJFBc?t=388) instead.

Run `gcc --version` in terminal to check.

---

Although we will use the Code Runner extension to execute our programs swiftly, you can always use the terminal to compile and run code.

On MacOS, compile `.c` files by running:
```bash
cc path/to/file.c -o a.out
```

This will create a file named `a.out` which you can execute by running `./a.out`.

To use `.txt` files as input for testing programs, run:
```bash
./a.out < test.txt
```

On Windows, compile `.c` files by running:
```shell
cc path\to\file.c -o a.exe
```

This will create a file named `a.exe` which you can manually execute by running `.\a.exe`.

To use `.txt` files as input for testing programs, run:
```shell
cat test.txt | .\a.exe
```
(where the command `cat test.txt` simply retrieves the contents of `test.txt`).

Windows Security may block .exe programs from running. If this is the case, try opening VS Code as an administrator.