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
int64_t _1718_main(void);
int64_t _1711_cmp(void* _1711_$self_ptr, int64_t* _1711_other);
int64_t _1709_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1708_$vtable = {
    .id = _1709_id,
};


/* Function definitions */
int64_t _1718_main(void){
    int64_t _1719_x;
    int64_t _1719_y;
    int64_t* _1718_t6;
    int64_t* _1718_t7;
    function3 _1718_t8;
    int64_t _1718_t5;
    int64_t _1718_t9;
    uint8_t _1718_t11;
    int64_t _1718_t12;
    int64_t _1718_t13;
    int64_t _1718_$retval;
    _1719_x = 5;
    _1719_y = 6;
    _1718_t6 = &_1719_x;
    _1718_t7 = &_1719_y;
    _1718_t8 = (function3) _1711_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1718_t5 = _1718_t8(_1718_t6, _1718_t7);
    $line_idx--;
    _1718_t9 = 1;
    _1718_t11 = _1718_t5==_1718_t9;
    if (_1718_t11) {
        goto BB1911;
    } else {
        goto BB1915;
    }
BB1911:
    _1718_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1718_t13 = _1708_$vtable.id();
    $line_idx--;
    _1718_$retval = $add_int64_t(_1718_t12, _1718_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1718_$retval;
BB1915:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1711_cmp(void* _1711_$self_ptr, int64_t* _1711_other){
    int64_t _1712_self;
    uint8_t _1711_t2;
    int64_t _1711_t1;
    int64_t _1711_t5;
    int64_t _1711_$retval;
    uint8_t _1711_t7;
    _1712_self = *(int64_t*)_1711_$self_ptr;
    _1711_t2 = _1712_self>*_1711_other;
    if (_1711_t2) {
        goto BB1893;
    } else {
        goto BB1897;
    }
BB1893:
    _1711_t1 = -1;
    goto BB1896;
BB1897:
    _1711_t7 = _1712_self==*_1711_other;
    if (_1711_t7) {
        goto BB1900;
    } else {
        goto BB1903;
    }
BB1896:
    _1711_$retval = _1711_t1;
    return _1711_$retval;
BB1900:
    _1711_t5 = 0;
    goto BB1902;
BB1903:
    _1711_t5 = 1;
    goto BB1902;
BB1902:
    _1711_t1 = _1711_t5;
    goto BB1896;
}

int64_t _1709_id(void){
    int64_t _1709_$retval;
    _1709_$retval = 4;
    return _1709_$retval;
}


int main(void) {
  printf("%ld",_1718_main());
  return 0;
}
