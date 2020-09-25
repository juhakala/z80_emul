#include "z80.h"
#include "struct.h"
#include "define.h"

static void printing(char *s1, char *s2, int size, t_mem *mem)
{
    if (PRINT & 1)
        read_mem_bytes(mem, size);
    if (PRINT & 2)
        printf("	%s %s", s1, s2);
    printf("\n");
}

static void	xor_x(unsigned char x, t_mem *mem)
{
	mem->reg->a ^= x; 
	if (mem->reg->a == 0)
		SET_FLAG(7);
	else
		CLEAR_FLAG(7);
	CLEAR_FLAG(6);
	CLEAR_FLAG(5);
	CLEAR_FLAG(4);
}

static void	and_x(unsigned char x, t_mem *mem)
{
	mem->reg->a &= x; 
	if (mem->reg->a == 0)
		SET_FLAG(7);
	else
		CLEAR_FLAG(7);
	CLEAR_FLAG(6);
	SET_FLAG(5);
	CLEAR_FLAG(4);
}

// 0xa0
int	and_b(t_mem *mem)
{
	if (PRINT)
		printing("ADN", "B", 1, mem);
	and_x(mem->reg->bc >> 8, mem);
	mem->cycle += 4;
	return (1);
}

// 0xa1
int	and_c(t_mem *mem)
{
	if (PRINT)
		printing("AND", "C", 1, mem);
	and_x(mem->reg->bc & 0x00ff, mem);
	mem->cycle += 4;
	return (1);
}

// 0xa2
int	and_d(t_mem *mem)
{
	if (PRINT)
		printing("ADN", "D", 1, mem);
	and_x(mem->reg->de >> 8, mem);
	mem->cycle += 4;
	return (1);
}

// 0xa3
int	and_e(t_mem *mem)
{
	if (PRINT)
		printing("AND", "E", 1, mem);
	and_x(mem->reg->de & 0x00ff, mem);
	mem->cycle += 4;
	return (1);
}

// 0xa4
int	and_h(t_mem *mem)
{
	if (PRINT)
		printing("ADN", "H", 1, mem);
	and_x(mem->reg->hl >> 8, mem);
	mem->cycle += 4;
	return (1);
}

// 0xa5
int	and_l(t_mem *mem)
{
	if (PRINT)
		printing("AND", "L", 1, mem);
	and_x(mem->reg->hl & 0x00ff, mem);
	mem->cycle += 4;
	return (1);
}

// 0xa6
int	and_ahl(t_mem *mem)
{
	if (PRINT)
		printing("AND", "(HL)", 1, mem);
	and_x(read(mem->reg->hl, mem), mem);
	mem->cycle += 8;
	return (1);
}

// 0xa7
int	and_a(t_mem *mem)
{
	if (PRINT)
		printing("AND", "A", 1, mem);
	and_x(mem->reg->a, mem);
	mem->cycle += 4;
	return (1);
}

// 0xa8
int	xor_b(t_mem *mem)
{
	if (PRINT)
		printing("XOR", "B", 1, mem);
	xor_x(mem->reg->bc >> 8, mem);
	mem->cycle += 4;
	return (1);
}

// 0xa9
int	xor_c(t_mem *mem)
{
	if (PRINT)
		printing("XOR", "C", 1, mem);
	xor_x(mem->reg->bc & 0x00ff, mem);
	mem->cycle += 4;
	return (1);
}

// 0xaa
int	xor_d(t_mem *mem)
{
	if (PRINT)
		printing("XOR", "D", 1, mem);
	xor_x(mem->reg->de >> 8, mem);
	mem->cycle += 4;
	return (1);
}

// 0xab
int	xor_e(t_mem *mem)
{
	if (PRINT)
		printing("XOR", "E", 1, mem);
	xor_x(mem->reg->de & 0x00ff, mem);
	mem->cycle += 4;
	return (1);
}

// 0xac
int	xor_h(t_mem *mem)
{
	if (PRINT)
		printing("XOR", "H", 1, mem);
	xor_x(mem->reg->hl >> 8, mem);
	mem->cycle += 4;
	return (1);
}

// 0xad
int	xor_l(t_mem *mem)
{
	if (PRINT)
		printing("XOR", "L", 1, mem);
	xor_x(mem->reg->hl & 0x00ff, mem);
	mem->cycle += 4;
	return (1);
}

// 0xae
int	xor_ahl(t_mem *mem)
{
	if (PRINT)
		printing("XOR", "(HL)", 1, mem);
	xor_x(read(mem->reg->hl, mem), mem);
	mem->cycle += 8;
	return (1);
}

// 0xaf
int	xor_a(t_mem *mem)
{
	if (PRINT)
		printing("XOR", "A", 1, mem);
	xor_x(mem->reg->a, mem);
	mem->cycle += 4;
	return (1);
}

// 0xe6
int	and_d8(t_mem *mem)
{
	if (PRINT)
		printing("AND", "d8", 2, mem);
	and_x(read(mem->reg->pc + 1, mem), mem);
	mem->cycle += 8;
	return (2);
}

// 0xee
int	xor_d8(t_mem *mem)
{
	if (PRINT)
		printing("XOR", "d8", 2, mem);
	xor_x(read(mem->reg->pc + 1, mem), mem);
	mem->cycle += 8;
	return (2);
}
