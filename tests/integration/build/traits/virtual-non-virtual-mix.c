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
int64_t _1773_main(void);
int64_t _1766_cmp(void* _1766_$self_ptr, int64_t* _1766_other);
int64_t _1764_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1763_$vtable = {
    .id = _1764_id,
};


/* Function definitions */
int64_t _1773_main(void){
    int64_t _1774_x;
    int64_t _1774_y;
    int64_t* _1773_t6;
    int64_t* _1773_t7;
    function3 _1773_t8;
    int64_t _1773_t5;
    int64_t _1773_t9;
    uint8_t _1773_t11;
    int64_t _1773_t12;
    int64_t _1773_t13;
    int64_t _1773_$retval;
    _1774_x = 5;
    _1774_y = 6;
    _1773_t6 = &_1774_x;
    _1773_t7 = &_1774_y;
    _1773_t8 = (function3) _1766_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1773_t5 = _1773_t8(_1773_t6, _1773_t7);
    $line_idx--;
    _1773_t9 = 1;
    _1773_t11 = _1773_t5==_1773_t9;
    if (_1773_t11) {
        goto BB1973;
    } else {
        goto BB1977;
    }
BB1973:
    _1773_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1773_t13 = _1763_$vtable.id();
    $line_idx--;
    _1773_$retval = $add_int64_t(_1773_t12, _1773_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1773_$retval;
BB1977:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1766_cmp(void* _1766_$self_ptr, int64_t* _1766_other){
    int64_t _1767_self;
    uint8_t _1766_t2;
    int64_t _1766_t1;
    int64_t _1766_t5;
    int64_t _1766_$retval;
    uint8_t _1766_t7;
    _1767_self = *(int64_t*)_1766_$self_ptr;
    _1766_t2 = _1767_self>*_1766_other;
    if (_1766_t2) {
        goto BB1955;
    } else {
        goto BB1959;
    }
BB1955:
    _1766_t1 = -1;
    goto BB1958;
BB1959:
    _1766_t7 = _1767_self==*_1766_other;
    if (_1766_t7) {
        goto BB1962;
    } else {
        goto BB1965;
    }
BB1958:
    _1766_$retval = _1766_t1;
    return _1766_$retval;
BB1962:
    _1766_t5 = 0;
    goto BB1964;
BB1965:
    _1766_t5 = 1;
    goto BB1964;
BB1964:
    _1766_t1 = _1766_t5;
    goto BB1958;
}

int64_t _1764_id(void){
    int64_t _1764_$retval;
    _1764_$retval = 4;
    return _1764_$retval;
}


int main(void) {
  printf("%ld",_1773_main());
  return 0;
}
