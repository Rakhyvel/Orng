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
int64_t _72_main(void);
int64_t _66_a(void* _66_$self_ptr, int64_t _66_x);
int64_t _68_c(void* _68_self, int64_t _68_x);
int64_t _70_d(int64_t _70_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _72_main(void){
    int64_t _72_t1;
    int64_t _72_t2;
    struct struct3 _73_my_val;
    struct struct3* _72_t5;
    int64_t _72_t6;
    function0 _72_t7;
    int64_t _72_t4;
    int64_t _72_t8;
    int64_t _72_$retval;
    _72_t1 = 200;
    _72_t2 = 45;
    _73_my_val = (struct struct3) {_72_t1, _72_t2};
    _72_t5 = &_73_my_val;
    _72_t6 = 2;
    _72_t7 = (function0) _66_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _72_t4 = _72_t7(_72_t5, _72_t6);
    $line_idx--;
    _72_t8 = 2;
    _72_$retval = $add_int64_t(_72_t4, _72_t8, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _72_$retval;
}

int64_t _66_a(void* _66_$self_ptr, int64_t _66_x){
    struct struct3 _67_self;
    int64_t _66_t1;
    int64_t _66_$retval;
    _67_self = *(struct struct3*)_66_$self_ptr;
    _66_t1 = $mult_int64_t(_67_self._1, _66_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _66_$retval = $add_int64_t(_67_self._0, _66_t1, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _66_$retval;
}

int64_t _68_c(void* _68_self, int64_t _68_x){
    int64_t _68_t0;
    int64_t _68_$retval;
    (*(struct struct3*)_68_self)._0 = _68_x;
    _68_t0 = $mult_int64_t((*(struct struct3*)_68_self)._1, _68_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _68_$retval = $add_int64_t((*(struct struct3*)_68_self)._0, _68_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _68_$retval;
}

int64_t _70_d(int64_t _70_x){
    int64_t _70_t0;
    int64_t _70_$retval;
    _70_t0 = 4;
    _70_$retval = $add_int64_t(_70_x, _70_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _70_$retval;
}


int main(void) {
  printf("%ld",_72_main());
  return 0;
}
