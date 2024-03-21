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
int64_t _1709_main(void);
int64_t _1702_cmp(void* _1702_$self_ptr, int64_t* _1702_other);
int64_t _1700_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1699_$vtable = {
    .id = _1700_id,
};


/* Function definitions */
int64_t _1709_main(void){
    int64_t _1710_x;
    int64_t _1710_y;
    int64_t* _1709_t6;
    int64_t* _1709_t7;
    function3 _1709_t8;
    int64_t _1709_t5;
    int64_t _1709_t9;
    uint8_t _1709_t11;
    int64_t _1709_t12;
    int64_t _1709_t13;
    int64_t _1709_$retval;
    _1710_x = 5;
    _1710_y = 6;
    _1709_t6 = &_1710_x;
    _1709_t7 = &_1710_y;
    _1709_t8 = (function3) _1702_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1709_t5 = _1709_t8(_1709_t6, _1709_t7);
    $line_idx--;
    _1709_t9 = 1;
    _1709_t11 = _1709_t5==_1709_t9;
    if (_1709_t11) {
        goto BB1905;
    } else {
        goto BB1909;
    }
BB1905:
    _1709_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1709_t13 = _1699_$vtable.id();
    $line_idx--;
    _1709_$retval = $add_int64_t(_1709_t12, _1709_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1709_$retval;
BB1909:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1702_cmp(void* _1702_$self_ptr, int64_t* _1702_other){
    int64_t _1703_self;
    uint8_t _1702_t2;
    int64_t _1702_t1;
    int64_t _1702_t5;
    int64_t _1702_$retval;
    uint8_t _1702_t7;
    _1703_self = *(int64_t*)_1702_$self_ptr;
    _1702_t2 = _1703_self>*_1702_other;
    if (_1702_t2) {
        goto BB1887;
    } else {
        goto BB1891;
    }
BB1887:
    _1702_t1 = -1;
    goto BB1890;
BB1891:
    _1702_t7 = _1703_self==*_1702_other;
    if (_1702_t7) {
        goto BB1894;
    } else {
        goto BB1897;
    }
BB1890:
    _1702_$retval = _1702_t1;
    return _1702_$retval;
BB1894:
    _1702_t5 = 0;
    goto BB1896;
BB1897:
    _1702_t5 = 1;
    goto BB1896;
BB1896:
    _1702_t1 = _1702_t5;
    goto BB1890;
}

int64_t _1700_id(void){
    int64_t _1700_$retval;
    _1700_$retval = 4;
    return _1700_$retval;
}


int main(void) {
  printf("%ld",_1709_main());
  return 0;
}
