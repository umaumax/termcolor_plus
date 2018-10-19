# terminal ANSI color library

* termcolor wrapper library
* header only library

## how to use
```
std::string str = tc::yellow("yellow text");
std::cout << tc::cout_blue("blue text only stdout output") << std::endl;
std::cerr << tc::cerr_cyan("cyan text only stderr output") << std::endl;
```

## how to build and run example
```
git submodule update -i
ninja

./main
```

## dependence
* [ikalnytskyi/termcolor: Termcolor is a header-only C++ library for printing colored messages to the terminal. Written just for fun with a help of the Force.]( https://github.com/ikalnytskyi/termcolor )

