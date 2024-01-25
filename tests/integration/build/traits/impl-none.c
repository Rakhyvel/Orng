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
int64_t _1563_main(void);
int64_t _1557_a(void* _1557_$self_ptr, int64_t _1557_x);
int64_t _1559_c(void* _1559_self, int64_t _1559_x);
int64_t _1561_d(int64_t _1561_x);

/* Trait vtable implementations */
struct vtable_impl _1556_$vtable = {
    .a = _1557_a,
    .c = _1559_c,
    .d = _1561_d,
};


/* Function definitions */
int64_t _1563_main(void){
    int64_t _1563_t1;
    int64_t _1563_t2;
    struct struct0 _1564_my_val;
    struct struct0* _1563_t5;
    int64_t _1563_t6;
    int64_t _1563_t3;
    int64_t _1563_t7;
    int64_t _1563_$retval;
    _1563_t1 = 200;
    _1563_t2 = 45;
    _1564_my_val = (struct struct0) {_1563_t1, _1563_t2};
    _1563_t5 = &_1564_my_val;
    _1563_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _1563_t3 = _1556_$vtable.a(_1563_t5, _1563_t6);
    $line_idx--;
    _1563_t7 = 2;
    _1563_$retval = $add_int64_t(_1563_t3, _1563_t7, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _1563_$retval;
}

int64_t _1557_a(void* _1557_$self_ptr, int64_t _1557_x){
    struct struct0 _1558_self;
    int64_t _1557_t0;
    int64_t _1557_$retval;
    _1558_self = *(struct struct0*)_1557_$self_ptr;
    _1557_t0 = $mult_int64_t(_1558_self._1, _1557_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1557_$retval = $add_int64_t(_1558_self._0, _1557_t0, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1557_$retval;
}

int64_t _1559_c(void* _1559_self, int64_t _1559_x){
    int64_t _1559_t0;
    int64_t _1559_$retval;
    (*(struct struct0*)_1559_self)._0 = _1559_x;
    _1559_t0 = $mult_int64_t((*(struct struct0*)_1559_self)._1, _1559_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _1559_$retval = $add_int64_t((*(struct struct0*)_1559_self)._0, _1559_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _1559_$retval;
}

int64_t _1561_d(int64_t _1561_x){
    int64_t _1561_t0;
    int64_t _1561_$retval;
    _1561_t0 = 4;
    _1561_$retval = $add_int64_t(_1561_x, _1561_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _1561_$retval;
}


int main(void) {
  printf("%ld",_1563_main());
  return 0;
}
