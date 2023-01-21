# Testowy program linkujący bibliotekę Rust do programu pisanego w C++

Na podstawie: https://dev.to/dandyvica/how-to-call-rust-functions-from-c-on-linux-h37

## Budowanie

### Linux

```sh
make
```

### MSys2 - CLang64

`C:\msys64\clang64.exe`:

```sh
pacman -Ss cargo
pacman -S clang64/mingw-w64-clang-x86_64-cargo-c
cargo -V
# cargo 1.65.0
```

Uruchom `C:\msys64\clang64.exe`, nie `msys2` bo `cargo` jest zainstalowane pod `C:\msys64\clang64\bin`

## Test symboli

```sh
LD_LIBRARY_PATH=target/debug ldd call_rust
```

## Uruchomienie

```sh
make run
```
