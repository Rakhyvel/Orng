/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;

/* Struct, union, and function definitions */
struct struct2 {
    uint8_t* _0;
    int64_t _1;
};

struct struct1 {
    uint64_t tag;
    union {
        struct struct2 _0;
        int64_t _1;
    };
};

typedef struct struct1(*function0)(int64_t);

/* Interned Strings */
char* string_0 = "\x66\x69\x7A\x7A\x62\x75\x7A\x7A";
char* string_1 = "\x62\x75\x7A\x7A";
char* string_2 = "\x66\x69\x7A\x7A";

/* Function forward definitions */
struct struct2 _1452_main(void);
struct struct1 _1455_fizzbuzz(int64_t _1455_n);


/* Function definitions */
struct struct2 _1452_main(void){
    function0 _1452_t0;
    int64_t _1452_t2;
    struct struct1 _1452_t1;
    uint64_t _1452_t3;
    struct struct2 _1452_$retval;
    _1452_t0 = (function0) _1455_fizzbuzz;
    _1452_t2 = 30;
    $lines[$line_idx++] = "tests/integration/sums/fizzbuzz.orng:3:14:\n    fizzbuzz(30).string\n            ^";
    _1452_t1 = _1452_t0(_1452_t2);
    $line_idx--;
    _1452_t3 = _1452_t1.tag;
    $tag_check(_1452_t3, 0, "tests/integration/sums/fizzbuzz.orng:2:3:\nfn main()-> String {\n ^");
    _1452_$retval = _1452_t1._0;
    return _1452_$retval;
}

struct struct1 _1455_fizzbuzz(int64_t _1455_n){
    int64_t _1455_t1;
    int64_t _1455_t2;
    int64_t _1455_t3;
    uint8_t _1455_t4;
    struct struct1 _1455_t0;
    struct struct2 _1455_t13;
    struct struct2 _1455_t15;
    struct struct2 _1455_t11;
    int64_t _1455_t8;
    int64_t _1455_t9;
    uint8_t _1455_t10;
    struct struct1 _1455_$retval;
    int64_t _1455_t5;
    int64_t _1455_t6;
    uint8_t _1455_t7;
    _1455_t1 = 0;
    _1455_t2 = 15;
    _1455_t3 = $mod_int64_t(_1455_n, _1455_t2, "tests/integration/sums/fizzbuzz.orng:12:13:\n        {n % 15} => .string(\"fizzbuzz\")\n           ^");
    _1455_t4 = _1455_t1==_1455_t3;
    if (_1455_t4) {
        goto BB1674;
    } else {
        goto BB1677;
    }
BB1674:
    _1455_t11 = (struct struct2) {(uint8_t*)string_0, 8};
    _1455_t0 = (struct struct1) {.tag=0, ._0=_1455_t11};
    goto BB1676;
BB1677:
    _1455_t5 = 5;
    _1455_t6 = $mod_int64_t(_1455_n, _1455_t5, "tests/integration/sums/fizzbuzz.orng:13:13:\n        {n % 5}  => .string(\"buzz\")\n           ^");
    _1455_t7 = _1455_t1==_1455_t6;
    if (_1455_t7) {
        goto BB1680;
    } else {
        goto BB1681;
    }
BB1676:
    _1455_$retval = _1455_t0;
    return _1455_$retval;
BB1680:
    _1455_t13 = (struct struct2) {(uint8_t*)string_1, 4};
    _1455_t0 = (struct struct1) {.tag=0, ._0=_1455_t13};
    goto BB1676;
BB1681:
    _1455_t8 = 3;
    _1455_t9 = $mod_int64_t(_1455_n, _1455_t8, "tests/integration/sums/fizzbuzz.orng:14:13:\n        {n % 3}  => .string(\"fizz\")\n           ^");
    _1455_t10 = _1455_t1==_1455_t9;
    if (_1455_t10) {
        goto BB1684;
    } else {
        goto BB1686;
    }
BB1684:
    _1455_t15 = (struct struct2) {(uint8_t*)string_2, 4};
    _1455_t0 = (struct struct1) {.tag=0, ._0=_1455_t15};
    goto BB1676;
BB1686:
    _1455_t0 = (struct struct1) {.tag=1, ._1=_1455_n};
    goto BB1676;
}


int main(void) {
  printf("%s",_1452_main()._0);
  return 0;
}
