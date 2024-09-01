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
int64_t _1762_main(void);
int64_t _1755_cmp(void* _1755_$self_ptr, int64_t* _1755_other);
int64_t _1753_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1752_$vtable = {
    .id = _1753_id,
};


/* Function definitions */
int64_t _1762_main(void){
    int64_t _1763_x;
    int64_t _1763_y;
    int64_t* _1762_t6;
    int64_t* _1762_t7;
    function3 _1762_t8;
    int64_t _1762_t5;
    int64_t _1762_t9;
    uint8_t _1762_t11;
    int64_t _1762_t12;
    int64_t _1762_t13;
    int64_t _1762_$retval;
    _1763_x = 5;
    _1763_y = 6;
    _1762_t6 = &_1763_x;
    _1762_t7 = &_1763_y;
    _1762_t8 = (function3) _1755_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1762_t5 = _1762_t8(_1762_t6, _1762_t7);
    $line_idx--;
    _1762_t9 = 1;
    _1762_t11 = _1762_t5==_1762_t9;
    if (_1762_t11) {
        goto BB1963;
    } else {
        goto BB1967;
    }
BB1963:
    _1762_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1762_t13 = _1752_$vtable.id();
    $line_idx--;
    _1762_$retval = $add_int64_t(_1762_t12, _1762_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1762_$retval;
BB1967:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1755_cmp(void* _1755_$self_ptr, int64_t* _1755_other){
    int64_t _1756_self;
    uint8_t _1755_t2;
    int64_t _1755_t1;
    int64_t _1755_t5;
    int64_t _1755_$retval;
    uint8_t _1755_t7;
    _1756_self = *(int64_t*)_1755_$self_ptr;
    _1755_t2 = _1756_self>*_1755_other;
    if (_1755_t2) {
        goto BB1945;
    } else {
        goto BB1949;
    }
BB1945:
    _1755_t1 = -1;
    goto BB1948;
BB1949:
    _1755_t7 = _1756_self==*_1755_other;
    if (_1755_t7) {
        goto BB1952;
    } else {
        goto BB1955;
    }
BB1948:
    _1755_$retval = _1755_t1;
    return _1755_$retval;
BB1952:
    _1755_t5 = 0;
    goto BB1954;
BB1955:
    _1755_t5 = 1;
    goto BB1954;
BB1954:
    _1755_t1 = _1755_t5;
    goto BB1948;
}

int64_t _1753_id(void){
    int64_t _1753_$retval;
    _1753_$retval = 4;
    return _1753_$retval;
}


int main(void) {
  printf("%ld",_1762_main());
  return 0;
}
