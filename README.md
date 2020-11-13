# macOS App in C

This is a tiny project to create macOS applications in C. I'll probably extend this to other platforms but for now I'm concerned about macOS and macOS only.

## Prerequisites

To build this, you'll need a device with at least macOS Sierra (possibly lower, I haven't tested any lower than that). Alongside macOS Sierra, you'll need clang, make, and all the other important things for compiling this code. These tools are easily available by using `xcode-select --install`. It is also recommended that you have Xcode 6.0 or later.

Here is a general list of prerequisites:

- Xcode 6.0 or later
- macOS Developer Tools
- Your preferred code editor
- A Terminal (the default macOS terminal works fine)

## Building

Now that we have everything, lets get building! To build, clone this repository and run `make` in the project directory. If any errors occur, try and google it first and if problems continually occur, feel free to create an issue. Make sure to include your Xcode version, macOS Version, Clang version `clang --version`, and make version `make -v`.

## Contributions

I'd love to have contributions (especially on remaking my Makefile)! If you'd like to merge a contribution, create a pull request and I'll look over the code, fix any warnings or errors, and merge!

## License

This code is licensed under the MIT License. Enjoy!