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
int64_t _9_main(void);
void _7_c(void* _7_self, int64_t _7_x);
int64_t _5_b(void* _5_self, int64_t _5_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _9_main(void){
    int64_t _9_t1;
    int64_t _9_t2;
    struct struct3 _10_my_val;
    struct struct3* _10_my_val_ptr;
    int64_t _9_t5;
    function4 _9_t6;
    int64_t _9_t8;
    function6 _9_t9;
    int64_t _9_t7;
    int64_t _9_t10;
    int64_t _9_$retval;
    _9_t1 = 100;
    _9_t2 = 45;
    _10_my_val = (struct struct3) {_9_t1, _9_t2};
    _10_my_val_ptr = &_10_my_val;
    _9_t5 = 2;
    _9_t6 = (function4) _7_c;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:19:17:\n    my_val_ptr.>c(2)\n               ^";
    (void) _9_t6(_10_my_val_ptr, _9_t5);
    $line_idx--;
    _9_t8 = 2;
    _9_t9 = (function6) _5_b;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:20:17:\n    my_val_ptr.>b(2) + 4\n               ^";
    _9_t7 = _9_t9(_10_my_val_ptr, _9_t8);
    $line_idx--;
    _9_t10 = 4;
    _9_$retval = $add_int64_t(_9_t7, _9_t10, "tests/integration/traits/addr-receiver-addr.orng:20:23:\n    my_val_ptr.>b(2) + 4\n                     ^");
    return _9_$retval;
}

void _7_c(void* _7_self, int64_t _7_x){
    (*(struct struct3*)_7_self)._0 = $mult_int64_t((*(struct struct3*)_7_self)._0, _7_x, "tests/integration/traits/addr-receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _5_b(void* _5_self, int64_t _5_x){
    int64_t _5_t0;
    int64_t _5_$retval;
    _5_t0 = $mult_int64_t((*(struct struct3*)_5_self)._1, _5_x, "tests/integration/traits/addr-receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _5_$retval = $add_int64_t((*(struct struct3*)_5_self)._0, _5_t0, "tests/integration/traits/addr-receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _5_$retval;
}


int main(void) {
  printf("%ld",_9_main());
  return 0;
}
