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
int64_t _1704_main(void);
int64_t _1700_a(void* _1700_$self_ptr, int64_t _1700_x);
int64_t _1702_b(void* _1702_$self_ptr);

/* Trait vtable implementations */
struct vtable_My_Trait _1699_$vtable = {
    .b = _1702_b,
};


/* Function definitions */
int64_t _1704_main(void){
    int64_t _1704_t1;
    int64_t _1704_t2;
    struct struct4 _1705_my_val;
    struct struct4* _1704_t5;
    int64_t _1704_t6;
    function5 _1704_t8;
    int64_t _1704_t4;
    int64_t _1704_$retval;
    _1704_t1 = 211;
    _1704_t2 = 50;
    _1705_my_val = (struct struct4) {_1704_t1, _1704_t2};
    _1704_t5 = &_1705_my_val;
    _1704_t6 = 2;
    _1704_t8 = (function5) _1700_a;
    $lines[$line_idx++] = "tests/integration/traits/unit-param.orng:18:13:\n    my_val.>a(2, {})\n           ^";
    _1704_t4 = _1704_t8(_1704_t5, _1704_t6);
    $line_idx--;
    _1704_$retval = _1704_t4;
    return _1704_$retval;
}

int64_t _1700_a(void* _1700_$self_ptr, int64_t _1700_x){
    struct struct4 _1701_self;
    int64_t _1700_t2;
    int64_t _1700_$retval;
    _1701_self = *(struct struct4*)_1700_$self_ptr;
    _1700_t2 = $mult_int64_t(_1701_self._1, _1700_x, "tests/integration/traits/unit-param.orng:11:64:\n    fn a(self, x: Int, y: ()) -> Int { _ = y; self.x + self.y * x }\n                                                              ^");
    _1700_$retval = $add_int64_t(_1701_self._0, _1700_t2, "tests/integration/traits/unit-param.orng:11:55:\n    fn a(self, x: Int, y: ()) -> Int { _ = y; self.x + self.y * x }\n                                                     ^");
    return _1700_$retval;
}

int64_t _1702_b(void* _1702_$self_ptr){
    int64_t _1702_$retval;
    (void)_1702_$self_ptr;
    _1702_$retval = 4;
    return _1702_$retval;
}


int main(void) {
  printf("%ld",_1704_main());
  return 0;
}
