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
int64_t _1629_main(void);
int64_t _1623_a(void* _1623_$self_ptr, int64_t _1623_x);
int64_t _1625_c(void* _1625_self, int64_t _1625_x);
int64_t _1627_d(int64_t _1627_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1629_main(void){
    int64_t _1629_t1;
    int64_t _1629_t2;
    struct struct3 _1630_my_val;
    struct struct3* _1629_t5;
    int64_t _1629_t6;
    function0 _1629_t7;
    int64_t _1629_t4;
    int64_t _1629_t8;
    int64_t _1629_$retval;
    _1629_t1 = 200;
    _1629_t2 = 45;
    _1630_my_val = (struct struct3) {_1629_t1, _1629_t2};
    _1629_t5 = &_1630_my_val;
    _1629_t6 = 2;
    _1629_t7 = (function0) _1623_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1629_t4 = _1629_t7(_1629_t5, _1629_t6);
    $line_idx--;
    _1629_t8 = 2;
    _1629_$retval = $add_int64_t(_1629_t4, _1629_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1629_$retval;
}

int64_t _1623_a(void* _1623_$self_ptr, int64_t _1623_x){
    struct struct3 _1624_self;
    int64_t _1623_t1;
    int64_t _1623_$retval;
    _1624_self = *(struct struct3*)_1623_$self_ptr;
    _1623_t1 = $mult_int64_t(_1624_self._1, _1623_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1623_$retval = $add_int64_t(_1624_self._0, _1623_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1623_$retval;
}

int64_t _1625_c(void* _1625_self, int64_t _1625_x){
    int64_t _1625_t0;
    int64_t _1625_$retval;
    (*(struct struct3*)_1625_self)._0 = _1625_x;
    _1625_t0 = $mult_int64_t((*(struct struct3*)_1625_self)._1, _1625_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1625_$retval = $add_int64_t((*(struct struct3*)_1625_self)._0, _1625_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1625_$retval;
}

int64_t _1627_d(int64_t _1627_x){
    int64_t _1627_t0;
    int64_t _1627_$retval;
    _1627_t0 = 4;
    _1627_$retval = $add_int64_t(_1627_x, _1627_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1627_$retval;
}


int main(void) {
  printf("%ld",_1629_main());
  return 0;
}
