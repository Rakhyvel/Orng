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
int64_t _1774_main(void);
int64_t _1770_a(void* _1770_$self_ptr, int64_t _1770_x);
int64_t _1772_b(void* _1772_$self_ptr);

/* Trait vtable implementations */
struct vtable_My_Trait _1769_$vtable = {
    .b = _1772_b,
};


/* Function definitions */
int64_t _1774_main(void){
    int64_t _1774_t1;
    int64_t _1774_t2;
    struct struct4 _1775_my_val;
    struct struct4* _1774_t5;
    int64_t _1774_t6;
    function5 _1774_t8;
    int64_t _1774_t4;
    int64_t _1774_$retval;
    _1774_t1 = 211;
    _1774_t2 = 50;
    _1775_my_val = (struct struct4) {_1774_t1, _1774_t2};
    _1774_t5 = &_1775_my_val;
    _1774_t6 = 2;
    _1774_t8 = (function5) _1770_a;
    $lines[$line_idx++] = "tests/integration/traits/unit-param.orng:18:13:\n    my_val.>a(2, {})\n           ^";
    _1774_t4 = _1774_t8(_1774_t5, _1774_t6);
    $line_idx--;
    _1774_$retval = _1774_t4;
    return _1774_$retval;
}

int64_t _1770_a(void* _1770_$self_ptr, int64_t _1770_x){
    struct struct4 _1771_self;
    int64_t _1770_t2;
    int64_t _1770_$retval;
    _1771_self = *(struct struct4*)_1770_$self_ptr;
    _1770_t2 = $mult_int64_t(_1771_self._1, _1770_x, "tests/integration/traits/unit-param.orng:11:64:\n    fn a(self, x: Int, y: ()) -> Int { _ = y; self.x + self.y * x }\n                                                              ^");
    _1770_$retval = $add_int64_t(_1771_self._0, _1770_t2, "tests/integration/traits/unit-param.orng:11:55:\n    fn a(self, x: Int, y: ()) -> Int { _ = y; self.x + self.y * x }\n                                                     ^");
    return _1770_$retval;
}

int64_t _1772_b(void* _1772_$self_ptr){
    int64_t _1772_$retval;
    (void)_1772_$self_ptr;
    _1772_$retval = 4;
    return _1772_$retval;
}


int main(void) {
  printf("%ld",_1774_main());
  return 0;
}
