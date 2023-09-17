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
    uint64_t tag;
    union {
        int64_t _0;
        uint8_t _1;
    };
} struct0;

typedef struct {
    uint64_t tag;
    union {
        struct0 _0;
    };
} struct1;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _2_t1;
    struct1 _3_x;
    struct0 _2_t6;
    int64_t _2_$retval;
    _2_t1 = (struct0) {.tag=0, ._0=4};
    _3_x = (struct1) {.tag=0, ._0=_2_t1};
    _3_x._0._0 = 104;
    $tag_check(_3_x.tag, 0, "tests/integration/sums/double.orng:5:7:\n    x.sum.int\n     ^");
    _2_t6 = _3_x._0;
    $tag_check(_2_t6.tag, 0, "tests/integration/sums/double.orng:2:3:\nfn main() -> Int {\n ^");
    _2_$retval = _3_x._0._0;
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
