# Test program linking Rust library to C++ program

Based on:
https://dev.to/dandyvica/how-to-call-rust-functions-from-c-on-linux-h37

## How to build

Assuming that `g++, make, cargo` are installed:

```sh
make
```

## Run test program

```sh
make run
```

### MSys2 - installing Rust in CLang64

We are using CLang64 because cargo/rust are not available for plain MSys.

In the console: `C:\msys64\clang64.exe`:

```sh
pacman -Ss cargo
pacman -S clang64/mingw-w64-clang-x86_64-cargo-c
cargo -V
# cargo 1.65.0
```

## List the symbols

```sh
LD_LIBRARY_PATH=target/debug ldd ./target/cppcaller
```
