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
int64_t _1724_main(void);
int64_t _1722_a(void* _1722_$self_ptr, int64_t _1722_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1724_main(void){
    int64_t _1724_t1;
    int64_t _1724_t2;
    struct struct2 _1725_my_val;
    struct struct2* _1724_t5;
    int64_t _1724_t6;
    function3 _1724_t7;
    int64_t _1724_t4;
    int64_t _1724_t8;
    int64_t _1724_$retval;
    _1724_t1 = 200;
    _1724_t2 = 45;
    _1725_my_val = (struct struct2) {_1724_t1, _1724_t2};
    _1724_t5 = &_1725_my_val;
    _1724_t6 = 2;
    _1724_t7 = (function3) _1722_a;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic.orng:14:13:\n    my_val.>a(2) - 1\n           ^";
    _1724_t4 = _1724_t7(_1724_t5, _1724_t6);
    $line_idx--;
    _1724_t8 = 1;
    _1724_$retval = $sub_int64_t(_1724_t4, _1724_t8, "tests/integration/traits/receiver-basic.orng:14:19:\n    my_val.>a(2) - 1\n                 ^");
    return _1724_$retval;
}

int64_t _1722_a(void* _1722_$self_ptr, int64_t _1722_x){
    struct struct2 _1723_self;
    int64_t _1722_t1;
    int64_t _1722_$retval;
    _1723_self = *(struct struct2*)_1722_$self_ptr;
    _1722_t1 = $mult_int64_t(_1723_self._1, _1722_x, "tests/integration/traits/receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1722_$retval = $add_int64_t(_1723_self._0, _1722_t1, "tests/integration/traits/receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1722_$retval;
}


int main(void) {
  printf("%ld",_1724_main());
  return 0;
}
