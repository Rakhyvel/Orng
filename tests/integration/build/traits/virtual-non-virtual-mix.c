/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct2;
struct struct4;

/* Struct, union, and function definitions */
typedef int64_t(*function0)(void);

struct struct2 {
    void* _0;
    void* _1;
};

typedef int64_t(*function1)(void*, void*);

struct struct4 {
    int64_t* _0;
    int64_t* _1;
};

typedef int64_t(*function3)(int64_t*, int64_t*);

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*id)(void);
};

/* Function forward definitions */
int64_t _1818_main(void);
int64_t _1811_cmp(void* _1811_$self_ptr, int64_t* _1811_other);
int64_t _1809_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1808_$vtable = {
    .id = _1809_id,
};


/* Function definitions */
int64_t _1818_main(void){
    int64_t _1819_x;
    int64_t _1819_y;
    int64_t* _1818_t6;
    int64_t* _1818_t7;
    function3 _1818_t8;
    int64_t _1818_t5;
    int64_t _1818_t9;
    uint8_t _1818_t11;
    int64_t _1818_t12;
    int64_t _1818_t13;
    int64_t _1818_$retval;
    _1819_x = 5;
    _1819_y = 6;
    _1818_t6 = &_1819_x;
    _1818_t7 = &_1819_y;
    _1818_t8 = (function3) _1811_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1818_t5 = _1818_t8(_1818_t6, _1818_t7);
    $line_idx--;
    _1818_t9 = 1;
    _1818_t11 = _1818_t5==_1818_t9;
    if (_1818_t11) {
        goto BB1988;
    } else {
        goto BB1992;
    }
BB1988:
    _1818_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1818_t13 = _1808_$vtable.id();
    $line_idx--;
    _1818_$retval = $add_int64_t(_1818_t12, _1818_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1818_$retval;
BB1992:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1811_cmp(void* _1811_$self_ptr, int64_t* _1811_other){
    int64_t _1812_self;
    uint8_t _1811_t2;
    int64_t _1811_t1;
    int64_t _1811_t5;
    int64_t _1811_$retval;
    uint8_t _1811_t7;
    _1812_self = *(int64_t*)_1811_$self_ptr;
    _1811_t2 = _1812_self>*_1811_other;
    if (_1811_t2) {
        goto BB1970;
    } else {
        goto BB1974;
    }
BB1970:
    _1811_t1 = -1;
    goto BB1973;
BB1974:
    _1811_t7 = _1812_self==*_1811_other;
    if (_1811_t7) {
        goto BB1977;
    } else {
        goto BB1980;
    }
BB1973:
    _1811_$retval = _1811_t1;
    return _1811_$retval;
BB1977:
    _1811_t5 = 0;
    goto BB1979;
BB1980:
    _1811_t5 = 1;
    goto BB1979;
BB1979:
    _1811_t1 = _1811_t5;
    goto BB1973;
}

int64_t _1809_id(void){
    int64_t _1809_$retval;
    _1809_$retval = 4;
    return _1809_$retval;
}


int main(void) {
  printf("%ld",_1818_main());
  return 0;
}
