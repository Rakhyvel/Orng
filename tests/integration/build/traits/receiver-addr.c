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
int64_t _1777_main(void);
void _1775_c(void* _1775_self, int64_t _1775_x);
int64_t _1773_b(void* _1773_self, int64_t _1773_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1777_main(void){
    int64_t _1777_t1;
    int64_t _1777_t2;
    struct struct3 _1778_my_val;
    struct struct3* _1777_t5;
    int64_t _1777_t6;
    function4 _1777_t7;
    struct struct3* _1777_t9;
    int64_t _1777_t10;
    function6 _1777_t11;
    int64_t _1777_t8;
    int64_t _1777_$retval;
    _1777_t1 = 100;
    _1777_t2 = 45;
    _1778_my_val = (struct struct3) {_1777_t1, _1777_t2};
    _1777_t5 = &_1778_my_val;
    _1777_t6 = 2;
    _1777_t7 = (function4) _1775_c;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:18:13:\n    my_val.>c(2)\n           ^";
    (void) _1777_t7(_1777_t5, _1777_t6);
    $line_idx--;
    _1777_t9 = &_1778_my_val;
    _1777_t10 = 2;
    _1777_t11 = (function6) _1773_b;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:19:13:\n    my_val.>b(2)\n           ^";
    _1777_t8 = _1777_t11(_1777_t9, _1777_t10);
    $line_idx--;
    _1777_$retval = _1777_t8;
    return _1777_$retval;
}

void _1775_c(void* _1775_self, int64_t _1775_x){
    (*(struct struct3*)_1775_self)._0 = $mult_int64_t((*(struct struct3*)_1775_self)._0, _1775_x, "tests/integration/traits/receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _1773_b(void* _1773_self, int64_t _1773_x){
    int64_t _1773_t0;
    int64_t _1773_$retval;
    _1773_t0 = $mult_int64_t((*(struct struct3*)_1773_self)._1, _1773_x, "tests/integration/traits/receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _1773_$retval = $add_int64_t((*(struct struct3*)_1773_self)._0, _1773_t0, "tests/integration/traits/receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _1773_$retval;
}


int main(void) {
  printf("%ld",_1777_main());
  return 0;
}
