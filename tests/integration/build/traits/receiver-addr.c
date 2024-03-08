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
int64_t _66_main(void);
void _64_c(void* _64_self, int64_t _64_x);
int64_t _62_b(void* _62_self, int64_t _62_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _66_main(void){
    int64_t _66_t1;
    int64_t _66_t2;
    struct struct3 _67_my_val;
    struct struct3* _66_t4;
    int64_t _66_t5;
    function4 _66_t6;
    struct struct3* _66_t8;
    int64_t _66_t9;
    function6 _66_t10;
    int64_t _66_t7;
    int64_t _66_$retval;
    _66_t1 = 100;
    _66_t2 = 45;
    _67_my_val = (struct struct3) {_66_t1, _66_t2};
    _66_t4 = &_67_my_val;
    _66_t5 = 2;
    _66_t6 = (function4) _64_c;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:18:13:\n    my_val.>c(2)\n           ^";
    (void) _66_t6(_66_t4, _66_t5);
    $line_idx--;
    _66_t8 = &_67_my_val;
    _66_t9 = 2;
    _66_t10 = (function6) _62_b;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:19:13:\n    my_val.>b(2)\n           ^";
    _66_t7 = _66_t10(_66_t8, _66_t9);
    $line_idx--;
    _66_$retval = _66_t7;
    return _66_$retval;
}

void _64_c(void* _64_self, int64_t _64_x){
    (*(struct struct3*)_64_self)._0 = $mult_int64_t((*(struct struct3*)_64_self)._0, _64_x, "tests/integration/traits/receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _62_b(void* _62_self, int64_t _62_x){
    int64_t _62_t0;
    int64_t _62_$retval;
    _62_t0 = $mult_int64_t((*(struct struct3*)_62_self)._1, _62_x, "tests/integration/traits/receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _62_$retval = $add_int64_t((*(struct struct3*)_62_self)._0, _62_t0, "tests/integration/traits/receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _62_$retval;
}


int main(void) {
  printf("%ld",_66_main());
  return 0;
}
