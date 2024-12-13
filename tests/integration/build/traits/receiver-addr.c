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
int64_t _1779_main(void);
void _1777_c(void* _1777_self, int64_t _1777_x);
int64_t _1775_b(void* _1775_self, int64_t _1775_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1779_main(void){
    int64_t _1779_t1;
    int64_t _1779_t2;
    struct struct3 _1780_my_val;
    struct struct3* _1779_t5;
    int64_t _1779_t6;
    function4 _1779_t7;
    struct struct3* _1779_t9;
    int64_t _1779_t10;
    function6 _1779_t11;
    int64_t _1779_t8;
    int64_t _1779_$retval;
    _1779_t1 = 100;
    _1779_t2 = 45;
    _1780_my_val = (struct struct3) {_1779_t1, _1779_t2};
    _1779_t5 = &_1780_my_val;
    _1779_t6 = 2;
    _1779_t7 = (function4) _1777_c;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:18:13:\n    my_val.>c(2)\n           ^";
    (void) _1779_t7(_1779_t5, _1779_t6);
    $line_idx--;
    _1779_t9 = &_1780_my_val;
    _1779_t10 = 2;
    _1779_t11 = (function6) _1775_b;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:19:13:\n    my_val.>b(2)\n           ^";
    _1779_t8 = _1779_t11(_1779_t9, _1779_t10);
    $line_idx--;
    _1779_$retval = _1779_t8;
    return _1779_$retval;
}

void _1777_c(void* _1777_self, int64_t _1777_x){
    (*(struct struct3*)_1777_self)._0 = $mult_int64_t((*(struct struct3*)_1777_self)._0, _1777_x, "tests/integration/traits/receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _1775_b(void* _1775_self, int64_t _1775_x){
    int64_t _1775_t0;
    int64_t _1775_$retval;
    _1775_t0 = $mult_int64_t((*(struct struct3*)_1775_self)._1, _1775_x, "tests/integration/traits/receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _1775_$retval = $add_int64_t((*(struct struct3*)_1775_self)._0, _1775_t0, "tests/integration/traits/receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _1775_$retval;
}


int main(void) {
  printf("%ld",_1779_main());
  return 0;
}
