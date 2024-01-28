/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Trait vtable type definitions */
struct vtable_impl {
    int64_t(*a)(void*, int64_t);
    int64_t(*c)(void*, int64_t);
    int64_t(*d)(int64_t);
};

/* Function forward definitions */
int64_t _1567_main(void);
int64_t _1561_a(void* _1561_$self_ptr, int64_t _1561_x);
int64_t _1563_c(void* _1563_self, int64_t _1563_x);
int64_t _1565_d(int64_t _1565_x);

/* Trait vtable implementations */
struct vtable_impl _1559_$vtable = {
    .a = _1561_a,
    .c = _1563_c,
    .d = _1565_d,
};


/* Function definitions */
int64_t _1567_main(void){
    int64_t _1567_t1;
    int64_t _1567_t2;
    struct struct0 _1568_my_val;
    struct struct0* _1567_t5;
    int64_t _1567_t6;
    int64_t _1567_t3;
    int64_t _1567_t7;
    int64_t _1567_$retval;
    _1567_t1 = 200;
    _1567_t2 = 45;
    _1568_my_val = (struct struct0) {_1567_t1, _1567_t2};
    _1567_t5 = &_1568_my_val;
    _1567_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1567_t3 = _1559_$vtable.a(_1567_t5, _1567_t6);
    $line_idx--;
    _1567_t7 = 2;
    _1567_$retval = $add_int64_t(_1567_t3, _1567_t7, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1567_$retval;
}

int64_t _1561_a(void* _1561_$self_ptr, int64_t _1561_x){
    struct struct0 _1562_self;
    int64_t _1561_t0;
    int64_t _1561_$retval;
    _1562_self = *(struct struct0*)_1561_$self_ptr;
    _1561_t0 = $mult_int64_t(_1562_self._1, _1561_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1561_$retval = $add_int64_t(_1562_self._0, _1561_t0, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1561_$retval;
}

int64_t _1563_c(void* _1563_self, int64_t _1563_x){
    int64_t _1563_t0;
    int64_t _1563_$retval;
    (*(struct struct0*)_1563_self)._0 = _1563_x;
    _1563_t0 = $mult_int64_t((*(struct struct0*)_1563_self)._1, _1563_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1563_$retval = $add_int64_t((*(struct struct0*)_1563_self)._0, _1563_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1563_$retval;
}

int64_t _1565_d(int64_t _1565_x){
    int64_t _1565_t0;
    int64_t _1565_$retval;
    _1565_t0 = 4;
    _1565_$retval = $add_int64_t(_1565_x, _1565_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1565_$retval;
}


int main(void) {
  printf("%ld",_1567_main());
  return 0;
}
