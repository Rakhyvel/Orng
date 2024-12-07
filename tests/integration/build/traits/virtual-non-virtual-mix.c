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
int64_t _1848_main(void);
int64_t _1841_cmp(void* _1841_$self_ptr, int64_t* _1841_other);
int64_t _1839_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1838_$vtable = {
    .id = _1839_id,
};


/* Function definitions */
int64_t _1848_main(void){
    int64_t _1849_x;
    int64_t _1849_y;
    int64_t* _1848_t6;
    int64_t* _1848_t7;
    function3 _1848_t8;
    int64_t _1848_t5;
    int64_t _1848_t9;
    uint8_t _1848_t11;
    int64_t _1848_t12;
    int64_t _1848_t13;
    int64_t _1848_$retval;
    _1849_x = 5;
    _1849_y = 6;
    _1848_t6 = &_1849_x;
    _1848_t7 = &_1849_y;
    _1848_t8 = (function3) _1841_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1848_t5 = _1848_t8(_1848_t6, _1848_t7);
    $line_idx--;
    _1848_t9 = 1;
    _1848_t11 = _1848_t5==_1848_t9;
    if (_1848_t11) {
        goto BB2018;
    } else {
        goto BB2022;
    }
BB2018:
    _1848_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1848_t13 = _1838_$vtable.id();
    $line_idx--;
    _1848_$retval = $add_int64_t(_1848_t12, _1848_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1848_$retval;
BB2022:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1841_cmp(void* _1841_$self_ptr, int64_t* _1841_other){
    int64_t _1842_self;
    uint8_t _1841_t2;
    int64_t _1841_t1;
    int64_t _1841_t5;
    int64_t _1841_$retval;
    uint8_t _1841_t7;
    _1842_self = *(int64_t*)_1841_$self_ptr;
    _1841_t2 = _1842_self>*_1841_other;
    if (_1841_t2) {
        goto BB2000;
    } else {
        goto BB2004;
    }
BB2000:
    _1841_t1 = -1;
    goto BB2003;
BB2004:
    _1841_t7 = _1842_self==*_1841_other;
    if (_1841_t7) {
        goto BB2007;
    } else {
        goto BB2010;
    }
BB2003:
    _1841_$retval = _1841_t1;
    return _1841_$retval;
BB2007:
    _1841_t5 = 0;
    goto BB2009;
BB2010:
    _1841_t5 = 1;
    goto BB2009;
BB2009:
    _1841_t1 = _1841_t5;
    goto BB2003;
}

int64_t _1839_id(void){
    int64_t _1839_$retval;
    _1839_$retval = 4;
    return _1839_$retval;
}


int main(void) {
  printf("%ld",_1848_main());
  return 0;
}
