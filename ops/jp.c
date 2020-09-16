#include "z80.h"
#include "struct.h"
#include "define.h"

static void printing(char *s1, char *s2, int size, int yes,t_mem *mem)
{
	if (PRINT & 1)
		read_mem_bytes(mem, size);
	if (PRINT & 2)
		printf("	JP %s, %s		|	%s", s1, s2, yes == 1 ? "YES" : "NO");
	printf("\n");
}

// 0xc2
int	jp_nz_a16(t_mem *mem)
{
	if (PRINT)
		printing("NZ", "a16", 3, CHECK_FLAG(7) == 0 ? 1 : 0, mem);
	if (CHECK_FLAG(7) == 0)
		mem->reg->pc = (read(mem->reg->pc + 1, mem) + (read(mem->reg->pc + 2, mem) << 8)) - 3;
	mem->cycle += 12;
	return (3);
}

// 0xc3
int	jp_a16(t_mem *mem)
{
	if (PRINT)
		printing("a16", "", 3, 1, mem);
	mem->reg->pc = read(mem->reg->pc + 1, mem) + (read(mem->reg->pc + 2, mem) << 8);
	mem->cycle += 12;
	return (0);
}

// 0xd2
int	jp_nc_a16(t_mem *mem)
{
	if (PRINT)
		printing("NC", "a16", 3, CHECK_FLAG(4) == 0 ? 1 : 0, mem);
	if (CHECK_FLAG(4) == 0)
		mem->reg->pc = (read(mem->reg->pc + 1, mem) + (read(mem->reg->pc + 2, mem) << 8)) - 3;
	mem->cycle += 12;
	return (3);
}