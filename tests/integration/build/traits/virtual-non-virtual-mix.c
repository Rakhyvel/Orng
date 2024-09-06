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
int64_t _1788_main(void);
int64_t _1781_cmp(void* _1781_$self_ptr, int64_t* _1781_other);
int64_t _1779_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1778_$vtable = {
    .id = _1779_id,
};


/* Function definitions */
int64_t _1788_main(void){
    int64_t _1789_x;
    int64_t _1789_y;
    int64_t* _1788_t6;
    int64_t* _1788_t7;
    function3 _1788_t8;
    int64_t _1788_t5;
    int64_t _1788_t9;
    uint8_t _1788_t11;
    int64_t _1788_t12;
    int64_t _1788_t13;
    int64_t _1788_$retval;
    _1789_x = 5;
    _1789_y = 6;
    _1788_t6 = &_1789_x;
    _1788_t7 = &_1789_y;
    _1788_t8 = (function3) _1781_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1788_t5 = _1788_t8(_1788_t6, _1788_t7);
    $line_idx--;
    _1788_t9 = 1;
    _1788_t11 = _1788_t5==_1788_t9;
    if (_1788_t11) {
        goto BB1988;
    } else {
        goto BB1992;
    }
BB1988:
    _1788_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1788_t13 = _1778_$vtable.id();
    $line_idx--;
    _1788_$retval = $add_int64_t(_1788_t12, _1788_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1788_$retval;
BB1992:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1781_cmp(void* _1781_$self_ptr, int64_t* _1781_other){
    int64_t _1782_self;
    uint8_t _1781_t2;
    int64_t _1781_t1;
    int64_t _1781_t5;
    int64_t _1781_$retval;
    uint8_t _1781_t7;
    _1782_self = *(int64_t*)_1781_$self_ptr;
    _1781_t2 = _1782_self>*_1781_other;
    if (_1781_t2) {
        goto BB1970;
    } else {
        goto BB1974;
    }
BB1970:
    _1781_t1 = -1;
    goto BB1973;
BB1974:
    _1781_t7 = _1782_self==*_1781_other;
    if (_1781_t7) {
        goto BB1977;
    } else {
        goto BB1980;
    }
BB1973:
    _1781_$retval = _1781_t1;
    return _1781_$retval;
BB1977:
    _1781_t5 = 0;
    goto BB1979;
BB1980:
    _1781_t5 = 1;
    goto BB1979;
BB1979:
    _1781_t1 = _1781_t5;
    goto BB1973;
}

int64_t _1779_id(void){
    int64_t _1779_$retval;
    _1779_$retval = 4;
    return _1779_$retval;
}


int main(void) {
  printf("%ld",_1788_main());
  return 0;
}
