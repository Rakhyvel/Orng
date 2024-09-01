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
int64_t _1680_main(void);
void _1678_c(void* _1678_self, int64_t _1678_x);
int64_t _1676_b(void* _1676_self, int64_t _1676_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1680_main(void){
    int64_t _1680_t1;
    int64_t _1680_t2;
    struct struct3 _1681_my_val;
    struct struct3* _1680_t5;
    int64_t _1680_t6;
    function4 _1680_t7;
    struct struct3* _1680_t9;
    int64_t _1680_t10;
    function6 _1680_t11;
    int64_t _1680_t8;
    int64_t _1680_$retval;
    _1680_t1 = 100;
    _1680_t2 = 45;
    _1681_my_val = (struct struct3) {_1680_t1, _1680_t2};
    _1680_t5 = &_1681_my_val;
    _1680_t6 = 2;
    _1680_t7 = (function4) _1678_c;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:18:13:\n    my_val.>c(2)\n           ^";
    (void) _1680_t7(_1680_t5, _1680_t6);
    $line_idx--;
    _1680_t9 = &_1681_my_val;
    _1680_t10 = 2;
    _1680_t11 = (function6) _1676_b;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:19:13:\n    my_val.>b(2)\n           ^";
    _1680_t8 = _1680_t11(_1680_t9, _1680_t10);
    $line_idx--;
    _1680_$retval = _1680_t8;
    return _1680_$retval;
}

void _1678_c(void* _1678_self, int64_t _1678_x){
    (*(struct struct3*)_1678_self)._0 = $mult_int64_t((*(struct struct3*)_1678_self)._0, _1678_x, "tests/integration/traits/receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _1676_b(void* _1676_self, int64_t _1676_x){
    int64_t _1676_t0;
    int64_t _1676_$retval;
    _1676_t0 = $mult_int64_t((*(struct struct3*)_1676_self)._1, _1676_x, "tests/integration/traits/receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _1676_$retval = $add_int64_t((*(struct struct3*)_1676_self)._0, _1676_t0, "tests/integration/traits/receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _1676_$retval;
}


int main(void) {
  printf("%ld",_1680_main());
  return 0;
}
