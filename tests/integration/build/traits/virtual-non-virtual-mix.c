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
int64_t _1828_main(void);
int64_t _1821_cmp(void* _1821_$self_ptr, int64_t* _1821_other);
int64_t _1819_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1818_$vtable = {
    .id = _1819_id,
};


/* Function definitions */
int64_t _1828_main(void){
    int64_t _1829_x;
    int64_t _1829_y;
    int64_t* _1828_t6;
    int64_t* _1828_t7;
    function3 _1828_t8;
    int64_t _1828_t5;
    int64_t _1828_t9;
    uint8_t _1828_t11;
    int64_t _1828_t12;
    int64_t _1828_t13;
    int64_t _1828_$retval;
    _1829_x = 5;
    _1829_y = 6;
    _1828_t6 = &_1829_x;
    _1828_t7 = &_1829_y;
    _1828_t8 = (function3) _1821_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1828_t5 = _1828_t8(_1828_t6, _1828_t7);
    $line_idx--;
    _1828_t9 = 1;
    _1828_t11 = _1828_t5==_1828_t9;
    if (_1828_t11) {
        goto BB1996;
    } else {
        goto BB2000;
    }
BB1996:
    _1828_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1828_t13 = _1818_$vtable.id();
    $line_idx--;
    _1828_$retval = $add_int64_t(_1828_t12, _1828_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1828_$retval;
BB2000:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1821_cmp(void* _1821_$self_ptr, int64_t* _1821_other){
    int64_t _1822_self;
    uint8_t _1821_t2;
    int64_t _1821_t1;
    int64_t _1821_t5;
    int64_t _1821_$retval;
    uint8_t _1821_t7;
    _1822_self = *(int64_t*)_1821_$self_ptr;
    _1821_t2 = _1822_self>*_1821_other;
    if (_1821_t2) {
        goto BB1978;
    } else {
        goto BB1982;
    }
BB1978:
    _1821_t1 = -1;
    goto BB1981;
BB1982:
    _1821_t7 = _1822_self==*_1821_other;
    if (_1821_t7) {
        goto BB1985;
    } else {
        goto BB1988;
    }
BB1981:
    _1821_$retval = _1821_t1;
    return _1821_$retval;
BB1985:
    _1821_t5 = 0;
    goto BB1987;
BB1988:
    _1821_t5 = 1;
    goto BB1987;
BB1987:
    _1821_t1 = _1821_t5;
    goto BB1981;
}

int64_t _1819_id(void){
    int64_t _1819_$retval;
    _1819_$retval = 4;
    return _1819_$retval;
}


int main(void) {
  printf("%ld",_1828_main());
  return 0;
}
