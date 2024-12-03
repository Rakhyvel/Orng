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
int64_t _11_main(void);
void _9_c(void* _9_self, int64_t _9_x);
int64_t _7_b(void* _7_self, int64_t _7_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _11_main(void){
    int64_t _11_t1;
    int64_t _11_t2;
    struct struct3 _12_my_val;
    struct struct3* _12_my_val_ptr;
    int64_t _11_t7;
    function4 _11_t8;
    int64_t _11_t10;
    function6 _11_t11;
    int64_t _11_t9;
    int64_t _11_t12;
    int64_t _11_$retval;
    _11_t1 = 100;
    _11_t2 = 45;
    _12_my_val = (struct struct3) {_11_t1, _11_t2};
    _12_my_val_ptr = &_12_my_val;
    _11_t7 = 2;
    _11_t8 = (function4) _9_c;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:19:17:\n    my_val_ptr.>c(2)\n               ^";
    (void) _11_t8(_12_my_val_ptr, _11_t7);
    $line_idx--;
    _11_t10 = 2;
    _11_t11 = (function6) _7_b;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:20:17:\n    my_val_ptr.>b(2) + 4\n               ^";
    _11_t9 = _11_t11(_12_my_val_ptr, _11_t10);
    $line_idx--;
    _11_t12 = 4;
    _11_$retval = $add_int64_t(_11_t9, _11_t12, "tests/integration/traits/addr-receiver-addr.orng:20:23:\n    my_val_ptr.>b(2) + 4\n                     ^");
    return _11_$retval;
}

void _9_c(void* _9_self, int64_t _9_x){
    (*(struct struct3*)_9_self)._0 = $mult_int64_t((*(struct struct3*)_9_self)._0, _9_x, "tests/integration/traits/addr-receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _7_b(void* _7_self, int64_t _7_x){
    int64_t _7_t0;
    int64_t _7_$retval;
    _7_t0 = $mult_int64_t((*(struct struct3*)_7_self)._1, _7_x, "tests/integration/traits/addr-receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _7_$retval = $add_int64_t((*(struct struct3*)_7_self)._0, _7_t0, "tests/integration/traits/addr-receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _7_$retval;
}


int main(void) {
  printf("%ld",_11_main());
  return 0;
}
