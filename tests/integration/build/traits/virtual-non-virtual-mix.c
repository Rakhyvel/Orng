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
int64_t _1834_main(void);
int64_t _1827_cmp(void* _1827_$self_ptr, int64_t* _1827_other);
int64_t _1825_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1824_$vtable = {
    .id = _1825_id,
};


/* Function definitions */
int64_t _1834_main(void){
    int64_t _1835_x;
    int64_t _1835_y;
    int64_t* _1834_t6;
    int64_t* _1834_t7;
    function3 _1834_t8;
    int64_t _1834_t5;
    int64_t _1834_t9;
    uint8_t _1834_t11;
    int64_t _1834_t12;
    int64_t _1834_t13;
    int64_t _1834_$retval;
    _1835_x = 5;
    _1835_y = 6;
    _1834_t6 = &_1835_x;
    _1834_t7 = &_1835_y;
    _1834_t8 = (function3) _1827_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1834_t5 = _1834_t8(_1834_t6, _1834_t7);
    $line_idx--;
    _1834_t9 = 1;
    _1834_t11 = _1834_t5==_1834_t9;
    if (_1834_t11) {
        goto BB1999;
    } else {
        goto BB2003;
    }
BB1999:
    _1834_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1834_t13 = _1824_$vtable.id();
    $line_idx--;
    _1834_$retval = $add_int64_t(_1834_t12, _1834_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1834_$retval;
BB2003:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1827_cmp(void* _1827_$self_ptr, int64_t* _1827_other){
    int64_t _1828_self;
    uint8_t _1827_t2;
    int64_t _1827_t1;
    int64_t _1827_t5;
    int64_t _1827_$retval;
    uint8_t _1827_t7;
    _1828_self = *(int64_t*)_1827_$self_ptr;
    _1827_t2 = _1828_self>*_1827_other;
    if (_1827_t2) {
        goto BB1981;
    } else {
        goto BB1985;
    }
BB1981:
    _1827_t1 = -1;
    goto BB1984;
BB1985:
    _1827_t7 = _1828_self==*_1827_other;
    if (_1827_t7) {
        goto BB1988;
    } else {
        goto BB1991;
    }
BB1984:
    _1827_$retval = _1827_t1;
    return _1827_$retval;
BB1988:
    _1827_t5 = 0;
    goto BB1990;
BB1991:
    _1827_t5 = 1;
    goto BB1990;
BB1990:
    _1827_t1 = _1827_t5;
    goto BB1984;
}

int64_t _1825_id(void){
    int64_t _1825_$retval;
    _1825_$retval = 4;
    return _1825_$retval;
}


int main(void) {
  printf("%ld",_1834_main());
  return 0;
}
