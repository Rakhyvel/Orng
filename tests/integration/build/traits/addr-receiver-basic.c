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
int64_t _1624_main(void);
int64_t _1622_a(void* _1622_$self_ptr, int64_t _1622_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1624_main(void){
    int64_t _1624_t1;
    int64_t _1624_t2;
    struct struct2 _1625_my_val;
    struct struct2* _1625_my_val_ptr;
    int64_t _1624_t7;
    function3 _1624_t8;
    int64_t _1624_t6;
    int64_t _1624_t9;
    int64_t _1624_$retval;
    _1624_t1 = 200;
    _1624_t2 = 45;
    _1625_my_val = (struct struct2) {_1624_t1, _1624_t2};
    _1625_my_val_ptr = &_1625_my_val;
    _1624_t7 = 2;
    _1624_t8 = (function3) _1622_a;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-basic.orng:15:17:\n    my_val_ptr.>a(2) + 3\n               ^";
    _1624_t6 = _1624_t8(_1625_my_val_ptr, _1624_t7);
    $line_idx--;
    _1624_t9 = 3;
    _1624_$retval = $add_int64_t(_1624_t6, _1624_t9, "tests/integration/traits/addr-receiver-basic.orng:15:23:\n    my_val_ptr.>a(2) + 3\n                     ^");
    return _1624_$retval;
}

int64_t _1622_a(void* _1622_$self_ptr, int64_t _1622_x){
    struct struct2 _1623_self;
    int64_t _1622_t1;
    int64_t _1622_$retval;
    _1623_self = *(struct struct2*)_1622_$self_ptr;
    _1622_t1 = $mult_int64_t(_1623_self._1, _1622_x, "tests/integration/traits/addr-receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1622_$retval = $add_int64_t(_1623_self._0, _1622_t1, "tests/integration/traits/addr-receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1622_$retval;
}


int main(void) {
  printf("%ld",_1624_main());
  return 0;
}
