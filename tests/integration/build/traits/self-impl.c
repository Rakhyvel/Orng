/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;
struct struct5;

/* Struct, union, and function definitions */
struct struct2 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    struct struct2* _0;
    struct struct2 _1;
};

typedef struct struct2(*function0)(struct struct2*, struct struct2);

typedef int64_t(*function3)(struct struct2*);

struct struct5 {
    struct struct2* _0;
    struct struct2 _1;
};

typedef struct struct2(*function4)(struct struct2*, struct struct2);

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _1684_main(void);
struct struct2 _1680_add(void* _1680_$self_ptr, struct struct2 _1680_other);
int64_t _1682_cab(void* _1682_$self_ptr);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1684_main(void){
    int64_t _1684_t1;
    int64_t _1684_t2;
    struct struct2 _1685_a;
    struct struct2* _1684_t5;
    int64_t _1684_t7;
    int64_t _1684_t8;
    struct struct2 _1684_t6;
    function4 _1684_t9;
    struct struct2 _1684_t4;
    struct struct2* _1684_t11;
    function3 _1684_t12;
    int64_t _1684_t10;
    int64_t _1684_$retval;
    _1684_t1 = 100;
    _1684_t2 = 90;
    _1685_a = (struct struct2) {_1684_t1, _1684_t2};
    _1684_t5 = &_1685_a;
    _1684_t7 = 100;
    _1684_t8 = 9;
    _1684_t6 = (struct struct2) {_1684_t7, _1684_t8};
    _1684_t9 = (function4) _1680_add;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:13:12:\n    a = a.>add((100, 9))\n          ^";
    _1684_t4 = _1684_t9(_1684_t5, _1684_t6);
    $line_idx--;
    _1685_a = _1684_t4;
    _1684_t11 = &_1684_t4;
    _1684_t12 = (function3) _1682_cab;
    $lines[$line_idx++] = "tests/integration/traits/self-impl.orng:14:8:\n    a.>cab()\n      ^";
    _1684_t10 = _1684_t12(_1684_t11);
    $line_idx--;
    _1684_$retval = _1684_t10;
    return _1684_$retval;
}

struct struct2 _1680_add(void* _1680_$self_ptr, struct struct2 _1680_other){
    struct struct2 _1681_self;
    int64_t _1680_t2;
    int64_t _1680_t3;
    struct struct2 _1680_$retval;
    _1681_self = *(struct struct2*)_1680_$self_ptr;
    _1680_t2 = $add_int64_t(_1681_self._0, _1680_other._0, "tests/integration/traits/self-impl.orng:5:18:\n        (self.x + other.x, self.y + other.y)\n                ^");
    _1680_t3 = $add_int64_t(_1681_self._1, _1680_other._1, "tests/integration/traits/self-impl.orng:5:36:\n        (self.x + other.x, self.y + other.y)\n                                  ^");
    _1680_$retval = (struct struct2) {_1680_t2, _1680_t3};
    return _1680_$retval;
}

int64_t _1682_cab(void* _1682_$self_ptr){
    struct struct2 _1683_self;
    int64_t _1682_$retval;
    _1683_self = *(struct struct2*)_1682_$self_ptr;
    _1682_$retval = $add_int64_t(_1683_self._0, _1683_self._1, "tests/integration/traits/self-impl.orng:8:35:\n    fn cab(self) -> Int { self.x + self.y }\n                                 ^");
    return _1682_$retval;
}


int main(void) {
  printf("%ld",_1684_main());
  return 0;
}
