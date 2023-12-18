/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint8_t* _0;
    int64_t _1;
} struct2;

typedef struct {
    uint64_t tag;
    union {
        struct2 _0;
        int64_t _1;
    };
} struct1;

typedef struct1(*function0)(int64_t);

/* Interned Strings */
char* string_0 = "\x66\x69\x7A\x7A\x62\x75\x7A\x7A";
char* string_1 = "\x62\x75\x7A\x7A";
char* string_2 = "\x66\x69\x7A\x7A";

/* Function forward definitions */
struct2 _1650_main(void);
struct1 _1653_fizzbuzz(int64_t _1653_n);

/* Function definitions */
struct2 _1650_main(void){
    function0 _1650_t0;
    int64_t _1650_t2;
    struct1 _1650_t1;
    uint64_t _1650_t3;
    struct2 _1650_$retval;
    _1650_t0 = _1653_fizzbuzz;
    _1650_t2 = 30;
    $lines[$line_idx++] = "tests/integration/sums/fizzbuzz.orng:3:14:\n    fizzbuzz(30).string\n            ^";
    _1650_t1 = _1650_t0(_1650_t2);
    $line_idx--;
    _1650_t3 = _1650_t1.tag;
    $tag_check(_1650_t3, 0, "tests/integration/sums/fizzbuzz.orng:2:3:\nfn main()-> String {\n ^");
    _1650_$retval = _1650_t1._0;
    return _1650_$retval;
}

struct1 _1653_fizzbuzz(int64_t _1653_n){
    int64_t _1653_t1;
    int64_t _1653_t2;
    int64_t _1653_t3;
    uint8_t _1653_t4;
    struct1 _1653_t0;
    struct2 _1653_t13;
    struct2 _1653_t15;
    struct2 _1653_t11;
    int64_t _1653_t8;
    int64_t _1653_t9;
    uint8_t _1653_t10;
    struct1 _1653_$retval;
    int64_t _1653_t5;
    int64_t _1653_t6;
    uint8_t _1653_t7;
    _1653_t1 = 0;
    _1653_t2 = 15;
    _1653_t3 = $mod_int64_t(_1653_n, _1653_t2, "tests/integration/sums/fizzbuzz.orng:12:13:\n        {n % 15} => .string <- \"fizzbuzz\"\n           ^");
    _1653_t4 = _1653_t1 == _1653_t3;
    if (_1653_t4) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _1653_t11 = (struct2) {(uint8_t*)string_0, 8};
    _1653_t0 = (struct1) {.tag=0, ._0=_1653_t11};
    goto BB6;
BB7:
    _1653_t5 = 5;
    _1653_t6 = $mod_int64_t(_1653_n, _1653_t5, "tests/integration/sums/fizzbuzz.orng:13:13:\n        {n % 5}  => .string <- \"buzz\"\n           ^");
    _1653_t7 = _1653_t1 == _1653_t6;
    if (_1653_t7) {
        goto BB10;
    } else {
        goto BB11;
    }
BB6:
    _1653_$retval = _1653_t0;
    return _1653_$retval;
BB10:
    _1653_t13 = (struct2) {(uint8_t*)string_1, 4};
    _1653_t0 = (struct1) {.tag=0, ._0=_1653_t13};
    goto BB6;
BB11:
    _1653_t8 = 3;
    _1653_t9 = $mod_int64_t(_1653_n, _1653_t8, "tests/integration/sums/fizzbuzz.orng:14:13:\n        {n % 3}  => .string <- \"fizz\"\n           ^");
    _1653_t10 = _1653_t1 == _1653_t9;
    if (_1653_t10) {
        goto BB14;
    } else {
        goto BB16;
    }
BB14:
    _1653_t15 = (struct2) {(uint8_t*)string_2, 4};
    _1653_t0 = (struct1) {.tag=0, ._0=_1653_t15};
    goto BB6;
BB16:
    _1653_t0 = (struct1) {.tag=1, ._1=_1653_n};
    goto BB6;
}

int main(void) {
  printf("%s",_1650_main()._0);
  return 0;
}
