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
int64_t _1529_main(void);
void _1527_c(void* _1527_self, int64_t _1527_x);
int64_t _1525_b(void* _1525_self, int64_t _1525_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1529_main(void){
    int64_t _1529_t1;
    int64_t _1529_t2;
    struct struct3 _1530_my_val;
    struct struct3* _1530_my_val_ptr;
    int64_t _1529_t7;
    function4 _1529_t8;
    int64_t _1529_t10;
    function6 _1529_t11;
    int64_t _1529_t9;
    int64_t _1529_t12;
    int64_t _1529_$retval;
    _1529_t1 = 100;
    _1529_t2 = 45;
    _1530_my_val = (struct struct3) {_1529_t1, _1529_t2};
    _1530_my_val_ptr = &_1530_my_val;
    _1529_t7 = 2;
    _1529_t8 = (function4) _1527_c;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:19:17:\n    my_val_ptr.>c(2)\n               ^";
    (void) _1529_t8(_1530_my_val_ptr, _1529_t7);
    $line_idx--;
    _1529_t10 = 2;
    _1529_t11 = (function6) _1525_b;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:20:17:\n    my_val_ptr.>b(2) + 4\n               ^";
    _1529_t9 = _1529_t11(_1530_my_val_ptr, _1529_t10);
    $line_idx--;
    _1529_t12 = 4;
    _1529_$retval = $add_int64_t(_1529_t9, _1529_t12, "tests/integration/traits/addr-receiver-addr.orng:20:23:\n    my_val_ptr.>b(2) + 4\n                     ^");
    return _1529_$retval;
}

void _1527_c(void* _1527_self, int64_t _1527_x){
    (*(struct struct3*)_1527_self)._0 = $mult_int64_t((*(struct struct3*)_1527_self)._0, _1527_x, "tests/integration/traits/addr-receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _1525_b(void* _1525_self, int64_t _1525_x){
    int64_t _1525_t0;
    int64_t _1525_$retval;
    _1525_t0 = $mult_int64_t((*(struct struct3*)_1525_self)._1, _1525_x, "tests/integration/traits/addr-receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _1525_$retval = $add_int64_t((*(struct struct3*)_1525_self)._0, _1525_t0, "tests/integration/traits/addr-receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _1525_$retval;
}


int main(void) {
  printf("%ld",_1529_main());
  return 0;
}
