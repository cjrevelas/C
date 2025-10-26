#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint32_t memory[1024];   // simulated memory
    uint32_t *R5 = &memory[100]; // R5 holds an address (a pointer)

    // Initialize test data
    memory[101] = (uint32_t)&memory[200];  // used for indirect example
    memory[200] = 42;                      // final value
    int displacement = 4;                  // bytes (not words!)

    // Displacement mode: displacement(R5)
    // Compute the address of memory[100] + 4 bytes = memory[101]
    uint32_t *disp_addr = (uint32_t *)((char *)R5 + displacement);
    uint32_t disp_value = *disp_addr;
    printf("Displacement 4(R5): %x\n", disp_value);

    // Indirect displacement: @displacement(R5) - way 1
    // Fetch address from memory[101], then read through it
    printf("\n");
    uint32_t indirect_disp_value =  *(uint32_t *)( *(uint32_t *)( (char *)R5 + displacement ));
    printf("Indirect displacement @4(R5): %u\n", indirect_disp_value);

    // Indirect displacement: @displacement(R5) - way 2
    // Fetch address from memory[101], then read through it
    printf("\n");
    uint32_t **indirect_disp_addr = (uint32_t **)((char *)R5 + displacement);
    indirect_disp_value = **indirect_disp_addr;
    printf("Indirect displacement @4(R5): %u\n", indirect_disp_value);
    return 0;
}
