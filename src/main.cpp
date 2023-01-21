// compile with gcc -g call_rust.c -o call_rust -lrustcalls -L./rustcalls/target/debug

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>


// sample struct to illustrate passing a C-struct to Rust
struct CStruct {
    char c;
    unsigned long ul;
    char *s;
};

// functions called in the Rust library
extern "C" {
void rust_char(char c);
void rust_wchar(wchar_t c);
void rust_short(short i);
void rust_ushort(unsigned short i);
void rust_int(int i);
void rust_uint(unsigned int i);
void rust_long(long i);
void rust_ulong(unsigned long i);
void rust_string(const char *s);
void rust_void(void *s);
void rust_int_array(const int *array, int length);
void rust_string_array(const char **array, int length);
void rust_cstruct(struct CStruct *c_struct);
}

int main(int argc, char **argv) {
    printf("- - - Calling Rust from C++:\n");
    // pass char to Rust
    rust_char('A');
    rust_wchar(L'ζ');

    // pass short to Rust
    rust_short(-100);
    rust_ushort(100);

    // pass int to Rust
    rust_int(-10);
    rust_uint(10);

    // pass long to Rust
    rust_long(-1000);
    rust_ulong(1000);

    // pass a NULL terminated string
    rust_string("hello world");

    // pass a void* pointer
    void *p = malloc(1000);
    rust_void(p);

    // pass an array of ints
    int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    rust_int_array(digits, 10);

    // pass an array of c strings
    const char *words[] = { "This", "is", "an", "example"};
    rust_string_array(words, 4);

    // pass a C struct
    struct CStruct c_struct;
    c_struct.c = 'A';
    c_struct.ul = 1000;
    c_struct.s = (char*)malloc(20);
    strcpy(c_struct.s, "0123456789");
    rust_cstruct(&c_struct);

    // don't forget to clean up ;-)
    free(p);
    free(c_struct.s);

    printf("- - - SUCCESS\n");
    return 0;
}
