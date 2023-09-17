/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

inline static void $panic(const char *restrict msg) {
    fprintf(stderr, "panic: %s\n", msg);
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}

inline static void $bounds_check(const int64_t idx, const int64_t length, const char *restrict line) {
    if (0 > idx || idx >= length) {
        $lines[$line_idx++] = line;
        $panic("bounds check failed");
    }
}

inline static void $tag_check(const int64_t tag, const int64_t sel, const char *restrict line) {
    if (tag != sel) {
        $lines[$line_idx++] = line;
        $panic("inactive field");
    }
}
/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _2_main();
int64_t _4_f();

/* Function definitions */
int64_t _2_main() {
    struct0 _3_x;
    int64_t* _2_t9;
    struct1 _3_y;
    int64_t _2_t11;
    int64_t _2_t12;
    int64_t* _2_t15;
    int64_t* _2_t16;
    struct1 _3_z;
    int64_t _2_$retval;
    _3_x = (struct0) {0, 0, 0, 0};
    _2_t9 = (int64_t*)&_3_x;
    _3_y = (struct1) {_2_t9, 4};
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
    _2_t11 = _4_f();
    $line_idx--;
    _2_t12 = 1;
    if (_2_t11 > _2_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _2_t15 = _3_y._0;
    _2_t16 = _2_t15 + _2_t11;
    _3_z = (struct1) {_2_t16, (_2_t12 - _2_t11)};
    $bounds_check(0, _2_t12 - _2_t11, "tests/integration/lint/subslice-bounds.orng:6:7:\n    z[0]\n     ^");
    _2_$retval = *(int64_t*)_3_z._0;
    return _2_$retval;
}

int64_t _4_f() {
    int64_t _4_$retval;
    _4_$retval = 2;
    return _4_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
