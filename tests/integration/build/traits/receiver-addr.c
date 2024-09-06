/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct3;
struct struct5;

/* Struct, union, and function definitions */
struct struct1 {
    void* _0;
    int64_t _1;
};

typedef int64_t(*function0)(void*, int64_t);

typedef void(*function2)(void*, int64_t);

struct struct3 {
    int64_t _0;
    int64_t _1;
};

struct struct5 {
    struct struct3* _0;
    int64_t _1;
};

typedef void(*function4)(struct struct3*, int64_t);

typedef int64_t(*function6)(struct struct3*, int64_t);

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _1732_main(void);
void _1730_c(void* _1730_self, int64_t _1730_x);
int64_t _1728_b(void* _1728_self, int64_t _1728_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1732_main(void){
    int64_t _1732_t1;
    int64_t _1732_t2;
    struct struct3 _1733_my_val;
    struct struct3* _1732_t5;
    int64_t _1732_t6;
    function4 _1732_t7;
    struct struct3* _1732_t9;
    int64_t _1732_t10;
    function6 _1732_t11;
    int64_t _1732_t8;
    int64_t _1732_$retval;
    _1732_t1 = 100;
    _1732_t2 = 45;
    _1733_my_val = (struct struct3) {_1732_t1, _1732_t2};
    _1732_t5 = &_1733_my_val;
    _1732_t6 = 2;
    _1732_t7 = (function4) _1730_c;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:18:13:\n    my_val.>c(2)\n           ^";
    (void) _1732_t7(_1732_t5, _1732_t6);
    $line_idx--;
    _1732_t9 = &_1733_my_val;
    _1732_t10 = 2;
    _1732_t11 = (function6) _1728_b;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:19:13:\n    my_val.>b(2)\n           ^";
    _1732_t8 = _1732_t11(_1732_t9, _1732_t10);
    $line_idx--;
    _1732_$retval = _1732_t8;
    return _1732_$retval;
}

void _1730_c(void* _1730_self, int64_t _1730_x){
    (*(struct struct3*)_1730_self)._0 = $mult_int64_t((*(struct struct3*)_1730_self)._0, _1730_x, "tests/integration/traits/receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _1728_b(void* _1728_self, int64_t _1728_x){
    int64_t _1728_t0;
    int64_t _1728_$retval;
    _1728_t0 = $mult_int64_t((*(struct struct3*)_1728_self)._1, _1728_x, "tests/integration/traits/receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _1728_$retval = $add_int64_t((*(struct struct3*)_1728_self)._0, _1728_t0, "tests/integration/traits/receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _1728_$retval;
}


int main(void) {
  printf("%ld",_1732_main());
  return 0;
}
