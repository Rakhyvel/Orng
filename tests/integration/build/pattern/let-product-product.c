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
} struct0;

typedef struct {
    struct0 _0;
    struct0 _1;
} struct1;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _2_t1;
    struct0 _2_t4;
    struct1 _2_t0;
    int64_t _3_x;
    int64_t _3_y;
    int64_t _3_a;
    int64_t _3_b;
    int64_t _2_$retval;
    _2_t1 = (struct0) {100, 20};
    _2_t4 = (struct0) {20, 2};
    _2_t0 = (struct1) {_2_t1, _2_t4};
    _3_x = _2_t0._0._0;
    _3_y = _2_t0._0._1;
    _3_a = _2_t0._1._0;
    _3_b = _2_t0._1._1;
    _2_$retval = _3_x + _3_y + _3_a + _3_b;
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
