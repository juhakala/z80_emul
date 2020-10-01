#include "z80.h"

void	map_io_registers(t_mem *mem)
{
	mem->io_reg->ff00 = &mem->rest_ram[0x0 + 0x1f00];
	mem->io_reg->ff01 = &mem->rest_ram[0x1 + 0x1f00];
	mem->io_reg->ff02 = &mem->rest_ram[0x2 + 0x1f00];
	mem->io_reg->ff04 = &mem->rest_ram[0x4 + 0x1f00];
	mem->io_reg->ff05 = &mem->rest_ram[0x5 + 0x1f00];
	mem->io_reg->ff06 = &mem->rest_ram[0x6 + 0x1f00];
	mem->io_reg->ff07 = &mem->rest_ram[0x7 + 0x1f00];
	mem->io_reg->ff0f = &mem->rest_ram[0xf + 0x1f00];
	mem->io_reg->ff10 = &mem->rest_ram[0x10 + 0x1f00];
	mem->io_reg->ff11 = &mem->rest_ram[0x11 + 0x1f00];
	mem->io_reg->ff12 = &mem->rest_ram[0x12 + 0x1f00];
	mem->io_reg->ff13 = &mem->rest_ram[0x13 + 0x1f00];
	mem->io_reg->ff14 = &mem->rest_ram[0x14 + 0x1f00];
	mem->io_reg->ff16 = &mem->rest_ram[0x16 + 0x1f00];
	mem->io_reg->ff17 = &mem->rest_ram[0x17 + 0x1f00];
	mem->io_reg->ff18 = &mem->rest_ram[0x18 + 0x1f00];
	mem->io_reg->ff19 = &mem->rest_ram[0x19 + 0x1f00];
	mem->io_reg->ff1a = &mem->rest_ram[0x1a + 0x1f00];
	mem->io_reg->ff1b = &mem->rest_ram[0x1b + 0x1f00];
	mem->io_reg->ff1c = &mem->rest_ram[0x1c + 0x1f00];
	mem->io_reg->ff1d = &mem->rest_ram[0x1d + 0x1f00];
	mem->io_reg->ff1e = &mem->rest_ram[0x1e + 0x1f00];
	mem->io_reg->ff20 = &mem->rest_ram[0x20 + 0x1f00];
	mem->io_reg->ff21 = &mem->rest_ram[0x21 + 0x1f00];
	mem->io_reg->ff22 = &mem->rest_ram[0x22 + 0x1f00];
	mem->io_reg->ff23 = &mem->rest_ram[0x23 + 0x1f00];
	mem->io_reg->ff24 = &mem->rest_ram[0x24 + 0x1f00];
	mem->io_reg->ff25 = &mem->rest_ram[0x25 + 0x1f00];
	mem->io_reg->ff26 = &mem->rest_ram[0x26 + 0x1f00];
	mem->io_reg->ff30 = &mem->rest_ram[0x30 + 0x1f00];
	mem->io_reg->ff40 = &mem->rest_ram[0x40 + 0x1f00];
	mem->io_reg->ff41 = &mem->rest_ram[0x41 + 0x1f00];
	mem->io_reg->ff42 = &mem->rest_ram[0x42 + 0x1f00];
	mem->io_reg->ff43 = &mem->rest_ram[0x43 + 0x1f00];
	mem->io_reg->ff44 = &mem->rest_ram[0x44 + 0x1f00];
	mem->io_reg->ff45 = &mem->rest_ram[0x45 + 0x1f00];
	mem->io_reg->ff46 = &mem->rest_ram[0x46 + 0x1f00];
	mem->io_reg->ff47 = &mem->rest_ram[0x47 + 0x1f00];
	mem->io_reg->ff48 = &mem->rest_ram[0x48 + 0x1f00];
	mem->io_reg->ff49 = &mem->rest_ram[0x49 + 0x1f00];
	mem->io_reg->ff4a = &mem->rest_ram[0x4a + 0x1f00];
	mem->io_reg->ff4b = &mem->rest_ram[0x4b + 0x1f00];
	mem->io_reg->ff50 = &mem->rest_ram[0x50 + 0x1f00];
	mem->io_reg->ffff = &mem->rest_ram[0xff + 0x1f00];
}

void	no_boot(t_mem *mem)
{
	map_io_registers(mem);
	mem->reg->a = 0x11;
	mem->reg->f = 0xb0;
	mem->reg->bc = 0x0013;
	mem->reg->de = 0x00d8;
	mem->reg->hl = 0x014d;
	mem->reg->sp = 0xfffe;
	*mem->io_reg->ff05 = 0x0; //tima
	*mem->io_reg->ff06 = 0x0; //tma
	*mem->io_reg->ff07 = 0x0; //tac
	*mem->io_reg->ff10 = 0x80; //nr10
	*mem->io_reg->ff11 = 0xbf; //nr11
	*mem->io_reg->ff12 = 0xf3; //nr12
	*mem->io_reg->ff14 = 0xbf; //nr14
	*mem->io_reg->ff16 = 0x3f; //nr21
	*mem->io_reg->ff17 = 0x0; //nr22
	*mem->io_reg->ff19 = 0xbf; //nr24
	*mem->io_reg->ff1a = 0x7f; //nr30
	*mem->io_reg->ff1b = 0xff; //nr31
	*mem->io_reg->ff1c = 0x9f; //nr32
	*mem->io_reg->ff1e = 0xbf; //nr33
	*mem->io_reg->ff20 = 0xff; //nr41
	*mem->io_reg->ff21 = 0x00; //nr42
	*mem->io_reg->ff22 = 0x0; //nr43
	*mem->io_reg->ff23 = 0xbf; //nr44
	*mem->io_reg->ff24 = 0x77; //nr50
	*mem->io_reg->ff25 = 0xf3; //nr51
	*mem->io_reg->ff26 = 0xf1; //nr52
	*mem->io_reg->ff40 = 0x91; //LCDC
	*mem->io_reg->ff42 = 0x0; //SCY
	*mem->io_reg->ff43 = 0x0; //SCX
	*mem->io_reg->ff45 = 0x0; //LYC
	*mem->io_reg->ff47 = 0xfc; //BGP
	*mem->io_reg->ff48 = 0xff; //OBP0
	*mem->io_reg->ff49 = 0xff; //OBP1
	*mem->io_reg->ff4a = 0x0; //WY
	*mem->io_reg->ff4b = 0x0; //WX
	*mem->io_reg->ffff = 0x0; //IE
	*mem->io_reg->ff50 = 1; //no boot
	mem->reg->pc = 0x100;
}

void	get_boot(t_mem *mem)
{
	//0x35 from 0xb8 to 0xbf
	unsigned char boot[256] = {0x31, 0xfe, 0xff, 0xaf, 0x21, 0xff, 0x9f, 0x32, 0xcb, 0x7c, 0x20, 0xfb, 0x21, 0x26, 0xff, 0x0e,
							   0x11, 0x3e, 0x80, 0x32, 0xe2, 0x0c, 0x3e, 0xf3, 0xe2, 0x32, 0x3e, 0x77, 0x77, 0x3e, 0xfc, 0xe0,
							   0x47, 0x11, 0x04, 0x01, 0x21, 0x10, 0x80, 0x1a, 0xcd, 0x95, 0x00, 0xcd, 0x96, 0x00, 0x13, 0x7b,
							   0xfe, 0x34, 0x20, 0xf3, 0x11, 0xd8, 0x00, 0x06, 0x08, 0x1a, 0x13, 0x22, 0x23, 0x05, 0x20, 0xf9,
							   0x3e, 0x19, 0xea, 0x10, 0x99, 0x21, 0x2f, 0x99, 0x0e, 0x0c, 0x3d, 0x28, 0x08, 0x32, 0x0d, 0x20,
							   0xf9, 0x2e, 0x0f, 0x18, 0xf3, 0x67, 0x3e, 0x64, 0x57, 0xe0, 0x42, 0x3e, 0x91, 0xe0, 0x40, 0x04,
							   0x1e, 0x02, 0x0e, 0x0c, 0xf0, 0x44, 0xfe, 0x90, 0x20, 0xfa, 0x0d, 0x20, 0xf7, 0x1d, 0x20, 0xf2,
							   0x0e, 0x13, 0x24, 0x7c, 0x1e, 0x83, 0xfe, 0x62, 0x28, 0x06, 0x1e, 0xc1, 0xfe, 0x64, 0x20, 0x06,
							   0x7b, 0xe2, 0x0c, 0x3e, 0x87, 0xe2, 0xf0, 0x42, 0x90, 0xe0, 0x42, 0x15, 0x20, 0xd2, 0x05, 0x20,
							   0x4f, 0x16, 0x20, 0x18, 0xcb, 0x4f, 0x06, 0x04, 0xc5, 0xcb, 0x11, 0x17, 0xc1, 0xcb, 0x11, 0x17,
							   0x05, 0x20, 0xf5, 0x22, 0x23, 0x22, 0x23, 0xc9, 0xce, 0xed, 0x66, 0x66, 0xcc, 0x0d, 0x00, 0x0b,
							   0x03, 0x73, 0x00, 0x83, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x08, 0x11, 0x1f, 0x88, 0x89, 0x00, 0x0e,
							   0xdc, 0xcc, 0x6e, 0xe6, 0xdd, 0xdd, 0xd9, 0x99, 0xbb, 0xbb, 0x67, 0x63, 0x6e, 0x0e, 0xec, 0xcc,
							   0xdd, 0xdc, 0x99, 0x9f, 0xbb, 0xb9, 0x33, 0x3e, 0x3c, 0x42, 0xb9, 0xa5, 0xb9, 0xa5, 0x42, 0x3c,
							   0x21, 0x04, 0x01, 0x11, 0xa8, 0x00, 0x1a, 0x13, 0xbe, 0x20, 0xfe, 0x23, 0x7d, 0xfe, 0x34, 0x20,
							   0xf5, 0x06, 0x19, 0x78, 0x86, 0x23, 0x05, 0x20, 0xfb, 0x86, 0x20, 0xfe, 0x3e, 0x01, 0xe0, 0x50};
	mem->boot = (unsigned char*)malloc(sizeof(unsigned char) * 256);
	memcpy(mem->boot, boot, 256);
	mem->reg->pc = 0;
	map_io_registers(mem);
    *mem->io_reg->ff50 = 0;
}

int		fetch_save(t_mem *mem)
{
	FILE *fp;
	char save[260];

	sprintf(save, "pokemone_save_size_%d", mem->memory->ram_size);
	mem->ram = (unsigned char*)malloc(sizeof(unsigned char) * mem->memory->ram_size);
	fp = fopen(save, "r");
	if (fp)
	{
		fread(mem->ram, 1, mem->memory->ram_size, fp);
		fclose(fp);
	}
	return (0);
}

int		get_header_info(t_mem *mem)
{
	if (mem->header->cart_type > 31 || mem->header->rom_size > 6 || mem->header->ram_size > 4)
		return (1);
	int mbc_arr[32] = {0, 1, 1, 1,-1, 2, 2,-1, 0, 0,-1, 0, 0, 0,-1, 3,
					   3, 3, 3, 3,-1,-1,-1,-1,-1, 5, 5, 5, 5, 5, 5, 0};
	mem->memory->mbc = mbc_arr[mem->header->cart_type];
	int rom_banks_arr[7] = {2, 4, 8, 16, 32, 64, 128};
	mem->memory->rom_banks = rom_banks_arr[mem->header->rom_size];
	int ram_banks_arr[5] = {0, 1, 1, 4, 16};
	mem->memory->ram_banks = ram_banks_arr[mem->header->ram_size];
	int ram_size_arr[6] = {0, 2048, 8192, 32768, 131072, 65536};
	mem->memory->ram_size = ram_size_arr[mem->header->ram_size];
	return (0);
}

int		read_to_mem(char **av, t_mem *mem)
{
	FILE *fp;
	size_t size;
	
	if (!(fp = fopen(av[1], "r")))
		return (1);
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	mem->rom = (unsigned char*)malloc(sizeof(unsigned char) * size);
	fread(mem->rom, 1, size, fp);
	mem->memory->rom_size = size;
	memcpy(mem->header, &(*(mem->rom + 0x104)), 76);
	fclose(fp);
	return (0);
}

void	defaults(t_mem *mem)
{
	mem->memory->rom_bank = 1;
	mem->memory->ram_bank = 1;
	mem->memory->rom_ram_mode = 0;
	mem->memory->ram_enable = 0;
	mem->reg->f = 0;
	mem->halt = 0;
	mem->timer->clock_freq = 4096;
	mem->timer->timer_counter = 1024;
	int i;
	for (i = 0; i < 0x8000; i++)
		mem->vram[i] = 0;
	for (i = 0; i < 0x8000; i++)
		mem->wram[i] = 0;
	for (i = 0; i < 0x2000; i++)
		mem->rest_ram[i] = 0;
}

t_mem	*initial_setup(int ac, char **av)
{
	t_mem *mem;

	mem = (t_mem*)malloc(sizeof(t_mem));
	mem->reg = (t_reg*)malloc(sizeof(t_reg));
	mem->io_reg = (t_io_reg*)malloc(sizeof(t_io_reg));
	mem->header = (t_header*)malloc(sizeof(t_header));
	mem->memory = (t_mem_control*)malloc(sizeof(t_mem_control));
	mem->timer = (t_timer*)malloc(sizeof(t_timer));
	mem->sdl = (t_sdl*)malloc(sizeof(t_sdl));
	if (ac > 1 && read_to_mem(av, mem))
		return (NULL);	//add free routine
	if (get_header_info(mem))
		return (NULL);	//add free routine
	if (fetch_save(mem))
		return (NULL);	//add free routine
	if (init_sdl(mem))
		return (NULL);	//add free routine
	defaults(mem);
	if (ac == 3 && !strcmp(av[2], "no_boot"))
		no_boot(mem);
	else
		get_boot(mem);
	return (mem);
}
