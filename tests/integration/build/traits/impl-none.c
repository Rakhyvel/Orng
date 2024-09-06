/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct3;

/* Struct, union, and function definitions */
struct struct1 {
    struct struct3* _0;
    int64_t _1;
};

typedef int64_t(*function0)(struct struct3*, int64_t);

typedef int64_t(*function2)(int64_t);

struct struct3 {
    int64_t _0;
    int64_t _1;
};

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _1662_main(void);
int64_t _1656_a(void* _1656_$self_ptr, int64_t _1656_x);
int64_t _1658_c(void* _1658_self, int64_t _1658_x);
int64_t _1660_d(int64_t _1660_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1662_main(void){
    int64_t _1662_t1;
    int64_t _1662_t2;
    struct struct3 _1663_my_val;
    struct struct3* _1662_t5;
    int64_t _1662_t6;
    function0 _1662_t7;
    int64_t _1662_t4;
    int64_t _1662_t8;
    int64_t _1662_$retval;
    _1662_t1 = 200;
    _1662_t2 = 45;
    _1663_my_val = (struct struct3) {_1662_t1, _1662_t2};
    _1662_t5 = &_1663_my_val;
    _1662_t6 = 2;
    _1662_t7 = (function0) _1656_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1662_t4 = _1662_t7(_1662_t5, _1662_t6);
    $line_idx--;
    _1662_t8 = 2;
    _1662_$retval = $add_int64_t(_1662_t4, _1662_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1662_$retval;
}

int64_t _1656_a(void* _1656_$self_ptr, int64_t _1656_x){
    struct struct3 _1657_self;
    int64_t _1656_t1;
    int64_t _1656_$retval;
    _1657_self = *(struct struct3*)_1656_$self_ptr;
    _1656_t1 = $mult_int64_t(_1657_self._1, _1656_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1656_$retval = $add_int64_t(_1657_self._0, _1656_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1656_$retval;
}

int64_t _1658_c(void* _1658_self, int64_t _1658_x){
    int64_t _1658_t0;
    int64_t _1658_$retval;
    (*(struct struct3*)_1658_self)._0 = _1658_x;
    _1658_t0 = $mult_int64_t((*(struct struct3*)_1658_self)._1, _1658_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1658_$retval = $add_int64_t((*(struct struct3*)_1658_self)._0, _1658_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1658_$retval;
}

int64_t _1660_d(int64_t _1660_x){
    int64_t _1660_t0;
    int64_t _1660_$retval;
    _1660_t0 = 4;
    _1660_$retval = $add_int64_t(_1660_x, _1660_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1660_$retval;
}


int main(void) {
  printf("%ld",_1662_main());
  return 0;
}
