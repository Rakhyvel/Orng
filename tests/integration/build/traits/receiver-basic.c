/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;
struct struct4;

/* Struct, union, and function definitions */
struct struct1 {
    void* _0;
    int64_t _1;
};

typedef int64_t(*function0)(void*, int64_t);

struct struct2 {
    int64_t _0;
    int64_t _1;
};

struct struct4 {
    struct struct2* _0;
    int64_t _1;
};

typedef int64_t(*function3)(struct struct2*, int64_t);

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _1757_main(void);
int64_t _1755_a(void* _1755_$self_ptr, int64_t _1755_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1757_main(void){
    int64_t _1757_t1;
    int64_t _1757_t2;
    struct struct2 _1758_my_val;
    struct struct2* _1757_t5;
    int64_t _1757_t6;
    function3 _1757_t7;
    int64_t _1757_t4;
    int64_t _1757_t8;
    int64_t _1757_$retval;
    _1757_t1 = 200;
    _1757_t2 = 45;
    _1758_my_val = (struct struct2) {_1757_t1, _1757_t2};
    _1757_t5 = &_1758_my_val;
    _1757_t6 = 2;
    _1757_t7 = (function3) _1755_a;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic.orng:14:13:\n    my_val.>a(2) - 1\n           ^";
    _1757_t4 = _1757_t7(_1757_t5, _1757_t6);
    $line_idx--;
    _1757_t8 = 1;
    _1757_$retval = $sub_int64_t(_1757_t4, _1757_t8, "tests/integration/traits/receiver-basic.orng:14:19:\n    my_val.>a(2) - 1\n                 ^");
    return _1757_$retval;
}

int64_t _1755_a(void* _1755_$self_ptr, int64_t _1755_x){
    struct struct2 _1756_self;
    int64_t _1755_t1;
    int64_t _1755_$retval;
    _1756_self = *(struct struct2*)_1755_$self_ptr;
    _1755_t1 = $mult_int64_t(_1756_self._1, _1755_x, "tests/integration/traits/receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1755_$retval = $add_int64_t(_1756_self._0, _1755_t1, "tests/integration/traits/receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1755_$retval;
}


int main(void) {
  printf("%ld",_1757_main());
  return 0;
}
