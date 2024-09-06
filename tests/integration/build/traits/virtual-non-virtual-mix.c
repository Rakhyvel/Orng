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
int64_t _1823_main(void);
int64_t _1816_cmp(void* _1816_$self_ptr, int64_t* _1816_other);
int64_t _1814_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1813_$vtable = {
    .id = _1814_id,
};


/* Function definitions */
int64_t _1823_main(void){
    int64_t _1824_x;
    int64_t _1824_y;
    int64_t* _1823_t6;
    int64_t* _1823_t7;
    function3 _1823_t8;
    int64_t _1823_t5;
    int64_t _1823_t9;
    uint8_t _1823_t11;
    int64_t _1823_t12;
    int64_t _1823_t13;
    int64_t _1823_$retval;
    _1824_x = 5;
    _1824_y = 6;
    _1823_t6 = &_1824_x;
    _1823_t7 = &_1824_y;
    _1823_t8 = (function3) _1816_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1823_t5 = _1823_t8(_1823_t6, _1823_t7);
    $line_idx--;
    _1823_t9 = 1;
    _1823_t11 = _1823_t5==_1823_t9;
    if (_1823_t11) {
        goto BB1992;
    } else {
        goto BB1996;
    }
BB1992:
    _1823_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1823_t13 = _1813_$vtable.id();
    $line_idx--;
    _1823_$retval = $add_int64_t(_1823_t12, _1823_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1823_$retval;
BB1996:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1816_cmp(void* _1816_$self_ptr, int64_t* _1816_other){
    int64_t _1817_self;
    uint8_t _1816_t2;
    int64_t _1816_t1;
    int64_t _1816_t5;
    int64_t _1816_$retval;
    uint8_t _1816_t7;
    _1817_self = *(int64_t*)_1816_$self_ptr;
    _1816_t2 = _1817_self>*_1816_other;
    if (_1816_t2) {
        goto BB1974;
    } else {
        goto BB1978;
    }
BB1974:
    _1816_t1 = -1;
    goto BB1977;
BB1978:
    _1816_t7 = _1817_self==*_1816_other;
    if (_1816_t7) {
        goto BB1981;
    } else {
        goto BB1984;
    }
BB1977:
    _1816_$retval = _1816_t1;
    return _1816_$retval;
BB1981:
    _1816_t5 = 0;
    goto BB1983;
BB1984:
    _1816_t5 = 1;
    goto BB1983;
BB1983:
    _1816_t1 = _1816_t5;
    goto BB1977;
}

int64_t _1814_id(void){
    int64_t _1814_$retval;
    _1814_$retval = 4;
    return _1814_$retval;
}


int main(void) {
  printf("%ld",_1823_main());
  return 0;
}
