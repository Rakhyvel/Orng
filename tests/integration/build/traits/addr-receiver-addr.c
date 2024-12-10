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
int64_t _1643_main(void);
void _1641_c(void* _1641_self, int64_t _1641_x);
int64_t _1639_b(void* _1639_self, int64_t _1639_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1643_main(void){
    int64_t _1643_t1;
    int64_t _1643_t2;
    struct struct3 _1644_my_val;
    struct struct3* _1644_my_val_ptr;
    int64_t _1643_t7;
    function4 _1643_t8;
    int64_t _1643_t10;
    function6 _1643_t11;
    int64_t _1643_t9;
    int64_t _1643_t12;
    int64_t _1643_$retval;
    _1643_t1 = 100;
    _1643_t2 = 45;
    _1644_my_val = (struct struct3) {_1643_t1, _1643_t2};
    _1644_my_val_ptr = &_1644_my_val;
    _1643_t7 = 2;
    _1643_t8 = (function4) _1641_c;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:19:17:\n    my_val_ptr.>c(2)\n               ^";
    (void) _1643_t8(_1644_my_val_ptr, _1643_t7);
    $line_idx--;
    _1643_t10 = 2;
    _1643_t11 = (function6) _1639_b;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:20:17:\n    my_val_ptr.>b(2) + 4\n               ^";
    _1643_t9 = _1643_t11(_1644_my_val_ptr, _1643_t10);
    $line_idx--;
    _1643_t12 = 4;
    _1643_$retval = $add_int64_t(_1643_t9, _1643_t12, "tests/integration/traits/addr-receiver-addr.orng:20:23:\n    my_val_ptr.>b(2) + 4\n                     ^");
    return _1643_$retval;
}

void _1641_c(void* _1641_self, int64_t _1641_x){
    (*(struct struct3*)_1641_self)._0 = $mult_int64_t((*(struct struct3*)_1641_self)._0, _1641_x, "tests/integration/traits/addr-receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _1639_b(void* _1639_self, int64_t _1639_x){
    int64_t _1639_t0;
    int64_t _1639_$retval;
    _1639_t0 = $mult_int64_t((*(struct struct3*)_1639_self)._1, _1639_x, "tests/integration/traits/addr-receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _1639_$retval = $add_int64_t((*(struct struct3*)_1639_self)._0, _1639_t0, "tests/integration/traits/addr-receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _1639_$retval;
}


int main(void) {
  printf("%ld",_1643_main());
  return 0;
}
