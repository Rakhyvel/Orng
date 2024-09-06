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
int64_t _1781_main(void);
int64_t _1774_cmp(void* _1774_$self_ptr, int64_t* _1774_other);
int64_t _1772_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1771_$vtable = {
    .id = _1772_id,
};


/* Function definitions */
int64_t _1781_main(void){
    int64_t _1782_x;
    int64_t _1782_y;
    int64_t* _1781_t6;
    int64_t* _1781_t7;
    function3 _1781_t8;
    int64_t _1781_t5;
    int64_t _1781_t9;
    uint8_t _1781_t11;
    int64_t _1781_t12;
    int64_t _1781_t13;
    int64_t _1781_$retval;
    _1782_x = 5;
    _1782_y = 6;
    _1781_t6 = &_1782_x;
    _1781_t7 = &_1782_y;
    _1781_t8 = (function3) _1774_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1781_t5 = _1781_t8(_1781_t6, _1781_t7);
    $line_idx--;
    _1781_t9 = 1;
    _1781_t11 = _1781_t5==_1781_t9;
    if (_1781_t11) {
        goto BB1980;
    } else {
        goto BB1984;
    }
BB1980:
    _1781_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1781_t13 = _1771_$vtable.id();
    $line_idx--;
    _1781_$retval = $add_int64_t(_1781_t12, _1781_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1781_$retval;
BB1984:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1774_cmp(void* _1774_$self_ptr, int64_t* _1774_other){
    int64_t _1775_self;
    uint8_t _1774_t2;
    int64_t _1774_t1;
    int64_t _1774_t5;
    int64_t _1774_$retval;
    uint8_t _1774_t7;
    _1775_self = *(int64_t*)_1774_$self_ptr;
    _1774_t2 = _1775_self>*_1774_other;
    if (_1774_t2) {
        goto BB1962;
    } else {
        goto BB1966;
    }
BB1962:
    _1774_t1 = -1;
    goto BB1965;
BB1966:
    _1774_t7 = _1775_self==*_1774_other;
    if (_1774_t7) {
        goto BB1969;
    } else {
        goto BB1972;
    }
BB1965:
    _1774_$retval = _1774_t1;
    return _1774_$retval;
BB1969:
    _1774_t5 = 0;
    goto BB1971;
BB1972:
    _1774_t5 = 1;
    goto BB1971;
BB1971:
    _1774_t1 = _1774_t5;
    goto BB1965;
}

int64_t _1772_id(void){
    int64_t _1772_$retval;
    _1772_$retval = 4;
    return _1772_$retval;
}


int main(void) {
  printf("%ld",_1781_main());
  return 0;
}
