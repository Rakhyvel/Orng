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
int64_t _1636_main(void);
void _1634_c(void* _1634_self, int64_t _1634_x);
int64_t _1632_b(void* _1632_self, int64_t _1632_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1636_main(void){
    int64_t _1636_t1;
    int64_t _1636_t2;
    struct struct3 _1637_my_val;
    struct struct3* _1636_t5;
    int64_t _1636_t6;
    function4 _1636_t7;
    struct struct3* _1636_t9;
    int64_t _1636_t10;
    function6 _1636_t11;
    int64_t _1636_t8;
    int64_t _1636_$retval;
    _1636_t1 = 100;
    _1636_t2 = 45;
    _1637_my_val = (struct struct3) {_1636_t1, _1636_t2};
    _1636_t5 = &_1637_my_val;
    _1636_t6 = 2;
    _1636_t7 = (function4) _1634_c;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:18:13:\n    my_val.>c(2)\n           ^";
    (void) _1636_t7(_1636_t5, _1636_t6);
    $line_idx--;
    _1636_t9 = &_1637_my_val;
    _1636_t10 = 2;
    _1636_t11 = (function6) _1632_b;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:19:13:\n    my_val.>b(2)\n           ^";
    _1636_t8 = _1636_t11(_1636_t9, _1636_t10);
    $line_idx--;
    _1636_$retval = _1636_t8;
    return _1636_$retval;
}

void _1634_c(void* _1634_self, int64_t _1634_x){
    (*(struct struct3*)_1634_self)._0 = $mult_int64_t((*(struct struct3*)_1634_self)._0, _1634_x, "tests/integration/traits/receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _1632_b(void* _1632_self, int64_t _1632_x){
    int64_t _1632_t0;
    int64_t _1632_$retval;
    _1632_t0 = $mult_int64_t((*(struct struct3*)_1632_self)._1, _1632_x, "tests/integration/traits/receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _1632_$retval = $add_int64_t((*(struct struct3*)_1632_self)._0, _1632_t0, "tests/integration/traits/receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _1632_$retval;
}


int main(void) {
  printf("%ld",_1636_main());
  return 0;
}
