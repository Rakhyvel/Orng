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
        int64_t _1;
        int64_t _2;
    };
} struct0;

/* Function forward definitions */
int64_t _2_main();
struct0 _4_get_enum();

/* Function definitions */
int64_t _2_main() {
    struct0 _2_t0;
    int64_t _2_$retval;
    $lines[$line_idx++] = "tests/integration/sums/enum.orng:10:28:\n    let x: Enum = get_enum()\n                          ^";
    _2_t0 = _4_get_enum();
    $line_idx--;
    _2_$retval = _2_t0._2;
    return _2_$retval;
}

struct0 _4_get_enum() {
    struct0 _4_$retval;
    _4_$retval = (struct0) {.tag=2, ._2=3};
    return _4_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}