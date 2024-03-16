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
int64_t _102_main(void);
void _100_c(void* _100_self, int64_t _100_x);
int64_t _98_b(void* _98_self, int64_t _98_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _102_main(void){
    int64_t _102_t1;
    int64_t _102_t2;
    struct struct3 _103_my_val;
    struct struct3* _102_t5;
    int64_t _102_t6;
    function4 _102_t7;
    struct struct3* _102_t9;
    int64_t _102_t10;
    function6 _102_t11;
    int64_t _102_t8;
    int64_t _102_$retval;
    _102_t1 = 100;
    _102_t2 = 45;
    _103_my_val = (struct struct3) {_102_t1, _102_t2};
    _102_t5 = &_103_my_val;
    _102_t6 = 2;
    _102_t7 = (function4) _100_c;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:18:13:\n    my_val.>c(2)\n           ^";
    (void) _102_t7(_102_t5, _102_t6);
    $line_idx--;
    _102_t9 = &_103_my_val;
    _102_t10 = 2;
    _102_t11 = (function6) _98_b;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:19:13:\n    my_val.>b(2)\n           ^";
    _102_t8 = _102_t11(_102_t9, _102_t10);
    $line_idx--;
    _102_$retval = _102_t8;
    return _102_$retval;
}

void _100_c(void* _100_self, int64_t _100_x){
    (*(struct struct3*)_100_self)._0 = $mult_int64_t((*(struct struct3*)_100_self)._0, _100_x, "tests/integration/traits/receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _98_b(void* _98_self, int64_t _98_x){
    int64_t _98_t0;
    int64_t _98_$retval;
    _98_t0 = $mult_int64_t((*(struct struct3*)_98_self)._1, _98_x, "tests/integration/traits/receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _98_$retval = $add_int64_t((*(struct struct3*)_98_self)._0, _98_t0, "tests/integration/traits/receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _98_$retval;
}


int main(void) {
  printf("%ld",_102_main());
  return 0;
}
