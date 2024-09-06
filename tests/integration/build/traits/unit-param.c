/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct3;
struct struct4;
struct struct6;

/* Struct, union, and function definitions */
struct struct1 {
    void* _0;
    int64_t _1;
};

typedef int64_t(*function0)(void*, int64_t);

struct struct3 {
    void* _0;
};

typedef int64_t(*function2)(void*);

struct struct4 {
    int64_t _0;
    int64_t _1;
};

struct struct6 {
    struct struct4* _0;
    int64_t _1;
};

typedef int64_t(*function5)(struct struct4*, int64_t);

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _1767_main(void);
int64_t _1763_a(void* _1763_$self_ptr, int64_t _1763_x);
int64_t _1765_b(void* _1765_$self_ptr);

/* Trait vtable implementations */
struct vtable_My_Trait _1762_$vtable = {
    .b = _1765_b,
};


/* Function definitions */
int64_t _1767_main(void){
    int64_t _1767_t1;
    int64_t _1767_t2;
    struct struct4 _1768_my_val;
    struct struct4* _1767_t5;
    int64_t _1767_t6;
    function5 _1767_t8;
    int64_t _1767_t4;
    int64_t _1767_$retval;
    _1767_t1 = 211;
    _1767_t2 = 50;
    _1768_my_val = (struct struct4) {_1767_t1, _1767_t2};
    _1767_t5 = &_1768_my_val;
    _1767_t6 = 2;
    _1767_t8 = (function5) _1763_a;
    $lines[$line_idx++] = "tests/integration/traits/unit-param.orng:18:13:\n    my_val.>a(2, {})\n           ^";
    _1767_t4 = _1767_t8(_1767_t5, _1767_t6);
    $line_idx--;
    _1767_$retval = _1767_t4;
    return _1767_$retval;
}

int64_t _1763_a(void* _1763_$self_ptr, int64_t _1763_x){
    struct struct4 _1764_self;
    int64_t _1763_t2;
    int64_t _1763_$retval;
    _1764_self = *(struct struct4*)_1763_$self_ptr;
    _1763_t2 = $mult_int64_t(_1764_self._1, _1763_x, "tests/integration/traits/unit-param.orng:11:64:\n    fn a(self, x: Int, y: ()) -> Int { _ = y; self.x + self.y * x }\n                                                              ^");
    _1763_$retval = $add_int64_t(_1764_self._0, _1763_t2, "tests/integration/traits/unit-param.orng:11:55:\n    fn a(self, x: Int, y: ()) -> Int { _ = y; self.x + self.y * x }\n                                                     ^");
    return _1763_$retval;
}

int64_t _1765_b(void* _1765_$self_ptr){
    int64_t _1765_$retval;
    (void)_1765_$self_ptr;
    _1765_$retval = 4;
    return _1765_$retval;
}


int main(void) {
  printf("%ld",_1767_main());
  return 0;
}
