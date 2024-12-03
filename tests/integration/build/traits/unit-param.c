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
int64_t _214_main(void);
int64_t _210_a(void* _210_$self_ptr, int64_t _210_x);
int64_t _212_b(void* _212_$self_ptr);

/* Trait vtable implementations */
struct vtable_My_Trait _209_$vtable = {
    .b = _212_b,
};


/* Function definitions */
int64_t _214_main(void){
    int64_t _214_t1;
    int64_t _214_t2;
    struct struct4 _215_my_val;
    struct struct4* _214_t5;
    int64_t _214_t6;
    function5 _214_t8;
    int64_t _214_t4;
    int64_t _214_$retval;
    _214_t1 = 211;
    _214_t2 = 50;
    _215_my_val = (struct struct4) {_214_t1, _214_t2};
    _214_t5 = &_215_my_val;
    _214_t6 = 2;
    _214_t8 = (function5) _210_a;
    $lines[$line_idx++] = "tests/integration/traits/unit-param.orng:18:13:\n    my_val.>a(2, {})\n           ^";
    _214_t4 = _214_t8(_214_t5, _214_t6);
    $line_idx--;
    _214_$retval = _214_t4;
    return _214_$retval;
}

int64_t _210_a(void* _210_$self_ptr, int64_t _210_x){
    struct struct4 _211_self;
    int64_t _210_t2;
    int64_t _210_$retval;
    _211_self = *(struct struct4*)_210_$self_ptr;
    _210_t2 = $mult_int64_t(_211_self._1, _210_x, "tests/integration/traits/unit-param.orng:11:64:\n    fn a(self, x: Int, y: ()) -> Int { _ = y; self.x + self.y * x }\n                                                              ^");
    _210_$retval = $add_int64_t(_211_self._0, _210_t2, "tests/integration/traits/unit-param.orng:11:55:\n    fn a(self, x: Int, y: ()) -> Int { _ = y; self.x + self.y * x }\n                                                     ^");
    return _210_$retval;
}

int64_t _212_b(void* _212_$self_ptr){
    int64_t _212_$retval;
    (void)_212_$self_ptr;
    _212_$retval = 4;
    return _212_$retval;
}


int main(void) {
  printf("%ld",_214_main());
  return 0;
}
