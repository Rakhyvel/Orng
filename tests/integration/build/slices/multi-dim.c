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
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef struct {
    struct1 _0;
    struct1 _1;
    struct1 _2;
} struct2;

typedef struct {
    struct1* _0;
    int64_t _1;
} struct3;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _3_x;
    int64_t* _2_t9;
    struct1 _2_t5;
    int64_t* _2_t15;
    struct1 _2_t11;
    int64_t* _2_t21;
    struct1 _2_t17;
    struct2 _3_y;
    struct1* _2_t27;
    struct3 _3_z;
    int64_t _2_$retval;
    _3_x = (struct0) {1, 2, 3};
    _2_t9 = (int64_t*)&_3_x;
    _2_t5 = (struct1) {_2_t9, 3};
    _2_t15 = (int64_t*)&_3_x;
    _2_t11 = (struct1) {_2_t15, 3};
    _2_t21 = (int64_t*)&_3_x;
    _2_t17 = (struct1) {_2_t21, 3};
    _3_y = (struct2) {_2_t5, _2_t11, _2_t17};
    _2_t27 = (struct1*)&_3_y;
    _3_z = (struct3) {_2_t27, 3};
    $bounds_check(2, ((struct1*)_3_z._0 + 1)->_1, "tests/integration/slices/multi-dim.orng:6:10:\n    z[1][2] = 82\n        ^");
    *((int64_t*)((struct1*)_3_z._0 + 1)->_0 + 2) = 82;
    $bounds_check(2, ((struct1*)_3_z._0 + 1)->_1, "tests/integration/slices/multi-dim.orng:7:10:\n    z[1][2]\n        ^");
    _2_$retval = *((int64_t*)((struct1*)_3_z._0 + 1)->_0 + 2);
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
