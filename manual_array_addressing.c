// save as vax_pointer_sim.c
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

// --- Simulated byte-addressable memory ---
#define MEM_SIZE 4096
static uint8_t mem[MEM_SIZE];   // our fake RAM
static uint8_t *base = mem;     // base pointer, like address 0

// Helper: read/write 32-bit little-endian values from/to "mem"
static uint32_t read_u32(uint8_t *addr) {
    uint32_t v;
    memcpy(&v, addr, sizeof(v));   // safe regardless of alignment
    return v;
}
static void write_u32(uint8_t *addr, uint32_t val) {
    memcpy(addr, &val, sizeof(val));
}

int main(void) {
    // Think of R5 as a pointer into memory:
    uint8_t *R5 = base + 100 * sizeof(uint32_t); // roughly "memory[100]" in words

    printf("\n base = %" PRIu32 "\n", base);
    printf("\n R5 = memory[100] = base + 100*4 = %" PRIu32 "\n\n", R5);

    // For analogy: displacement = 4 bytes (i.e., "4(R5)")
    int displacement = 4;
    printf(" R5 + displacement = memory[101] = %" PRIu32 "\n\n", R5 + displacement);

    // We’ll make memory[R5 + 4] contain an offset (800 == 200*4) to memory[200].
    // And memory[200] contains the value 42.
    write_u32(base + 200 * sizeof(uint32_t), 42);
    write_u32(R5 + displacement, 200 * sizeof(uint32_t));  // store offset 800

    // ---- 1️⃣ Displacement mode: displacement(R5) ----
    // effective address = R5 + displacement
    uint8_t *EA = R5 + displacement;
    uint32_t disp_value = read_u32(EA);
    printf(" *(EA) = *(R5+displacement) = *mem[101] = %" PRIu32 "\n\n", disp_value);

    // ---- 2️⃣ Indirect displacement mode: @displacement(R5) ----
    // fetch offset stored at (R5+disp), then interpret as new address
    uint8_t *indirect_EA = base + disp_value;   // compute actual target address
    uint32_t indirect_value = read_u32(indirect_EA);
    printf(" @4(R5) = *(base + disp_value) = \n    \
      *(base + *(EA))      = %" PRIu32 "\n\n", indirect_value);

    // ---- Show addresses to make it clear ----
    printf("EA = R5+4 = base + %td\n\n", EA - base);
    printf("Indirect EA = base + %u\n", disp_value);

    return 0;
}