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
int64_t _84_main(void);
int64_t _82_a(void* _82_$self_ptr, int64_t _82_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _84_main(void){
    int64_t _84_t1;
    int64_t _84_t2;
    struct struct2 _85_my_val;
    struct struct2* _84_t4;
    int64_t _84_t5;
    function3 _84_t6;
    int64_t _84_t3;
    int64_t _84_t7;
    int64_t _84_$retval;
    _84_t1 = 200;
    _84_t2 = 45;
    _85_my_val = (struct struct2) {_84_t1, _84_t2};
    _84_t4 = &_85_my_val;
    _84_t5 = 2;
    _84_t6 = (function3) _82_a;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic.orng:14:13:\n    my_val.>a(2) - 1\n           ^";
    _84_t3 = _84_t6(_84_t4, _84_t5);
    $line_idx--;
    _84_t7 = 1;
    _84_$retval = $sub_int64_t(_84_t3, _84_t7, "tests/integration/traits/receiver-basic.orng:14:19:\n    my_val.>a(2) - 1\n                 ^");
    return _84_$retval;
}

int64_t _82_a(void* _82_$self_ptr, int64_t _82_x){
    struct struct2 _83_self;
    int64_t _82_t0;
    int64_t _82_$retval;
    _83_self = *(struct struct2*)_82_$self_ptr;
    _82_t0 = $mult_int64_t(_83_self._1, _82_x, "tests/integration/traits/receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _82_$retval = $add_int64_t(_83_self._0, _82_t0, "tests/integration/traits/receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _82_$retval;
}


int main(void) {
  printf("%ld",_84_main());
  return 0;
}
