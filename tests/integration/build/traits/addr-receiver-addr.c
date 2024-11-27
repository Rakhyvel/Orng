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
int64_t _1599_main(void);
void _1597_c(void* _1597_self, int64_t _1597_x);
int64_t _1595_b(void* _1595_self, int64_t _1595_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1599_main(void){
    int64_t _1599_t1;
    int64_t _1599_t2;
    struct struct3 _1600_my_val;
    struct struct3* _1600_my_val_ptr;
    int64_t _1599_t7;
    function4 _1599_t8;
    int64_t _1599_t10;
    function6 _1599_t11;
    int64_t _1599_t9;
    int64_t _1599_t12;
    int64_t _1599_$retval;
    _1599_t1 = 100;
    _1599_t2 = 45;
    _1600_my_val = (struct struct3) {_1599_t1, _1599_t2};
    _1600_my_val_ptr = &_1600_my_val;
    _1599_t7 = 2;
    _1599_t8 = (function4) _1597_c;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:19:17:\n    my_val_ptr.>c(2)\n               ^";
    (void) _1599_t8(_1600_my_val_ptr, _1599_t7);
    $line_idx--;
    _1599_t10 = 2;
    _1599_t11 = (function6) _1595_b;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:20:17:\n    my_val_ptr.>b(2) + 4\n               ^";
    _1599_t9 = _1599_t11(_1600_my_val_ptr, _1599_t10);
    $line_idx--;
    _1599_t12 = 4;
    _1599_$retval = $add_int64_t(_1599_t9, _1599_t12, "tests/integration/traits/addr-receiver-addr.orng:20:23:\n    my_val_ptr.>b(2) + 4\n                     ^");
    return _1599_$retval;
}

void _1597_c(void* _1597_self, int64_t _1597_x){
    (*(struct struct3*)_1597_self)._0 = $mult_int64_t((*(struct struct3*)_1597_self)._0, _1597_x, "tests/integration/traits/addr-receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _1595_b(void* _1595_self, int64_t _1595_x){
    int64_t _1595_t0;
    int64_t _1595_$retval;
    _1595_t0 = $mult_int64_t((*(struct struct3*)_1595_self)._1, _1595_x, "tests/integration/traits/addr-receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _1595_$retval = $add_int64_t((*(struct struct3*)_1595_self)._0, _1595_t0, "tests/integration/traits/addr-receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _1595_$retval;
}


int main(void) {
  printf("%ld",_1599_main());
  return 0;
}
