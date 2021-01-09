# Unicode

- [x] u8cout,u16cout.
it enables us OUTPUT UTF-16 and UTF-8 string by using u8cout and u16cout.
still TODO: Add `_setmode(_fileno(stdout),_O_U16TEXT);` to u16cout.
- [x] UTF-32 to surrogate
it enables us convert UTF32 to surrogate by using function `surrogate_t _U32_2_U16_(char32_t __c);`.
the defination of surrogate_t is:
```cpp
typedef struct __surrogate__{
	char16_t lo=0,hi=0; //if is surrogate,it isn't zero.
	char16_t normal_s=0;//else,normal string:just use normal_s.
}surrogate_t;
```
