char *USERNAMENONAMEINAMUROSSHELLSRING = "userok";

process __boot_process;
process __shell_process;
//отстой
char *__shell__user__setPointerNOUSER(char *string)
{
    if (string == "")
    {
        __std__printf("> ");
    }
    else
    {
        __std__printff("%s@%s", USERNAMENONAMEINAMUROSSHELLSRING, string);
        __std__newline();
        __std__printff("> ");
        __std__cursorPosition((COLUMNS_IN_LINE * __std__cursory) + __driver_kb_kbbcur + 1);
    }
}

void __shell_offset()
{

    char *str = "";
    if (__shell_pointer != 0)
        __shell__user__setPointerNOUSER("");
    __shell_pointer++;
    __std__scanf(str);

    __shell_cmd_ini(str);

    __std__newline();
    if (__std__cursory > LINES - 1)
    {
        __std__gotoxy(0, 0);
        __std__cls();
        __std__printc(HEADER, 112);
        __std__gotoxy(0, 1);
    }
    // ini cursor //ини курсор))))))))))))))))))))))))))))))))))
    __std__cursorPosition((COLUMNS_IN_LINE * __std__cursory) + __driver_kb_kbbcur + 1);
}

void __shell_init()
{
    __shell_process.offset = *__shell_offset;
}

void __boot_offset()
{
    __driver_audio_beeps();
    __std__cls();
    __driver_kb_idt_init();
    __std__printf(logo);
    __std__sleep(1000);
    __std__color(7);
    __std__cls();
    __std__goto(0);
    __driver_kb_stopinp();
    __fs_initdisk();

    __std__gotoxy(0, 0);
    __std__cls();
    __std__printc(HEADER, 112);
    __std__gotoxy(0, 1);
    __std__printf("\nWelcome to AmurOS!\n");
    __std__printf("Type 'help' to view the list of commands\n");

    __shell_init();
    __process_push(__shell_process);
    __start_processes(2);
}

void __boot_init()
{
    __boot_process.offset = *__boot_offset;
}

bool __shell_cmd_commandcmp(char *str, char *arg)
{
    __std__toLowerCase(str);
    if (__std__strcmp(str, arg))
        return true;
    else
        return false;
}

void __shell_cmd_ini(char *str)
{
    if (__shell_cmd_commandcmp(str, "help"))
    {
        __std__printff("\nUse -soundhw pcspk in QEMU or choose pc speaker in emulator%s", SYSVER);
        __std__printc(">--------help list--------<", 112);
        __std__printf("\n= reboot  cls        help =");
        __std__printf("\n= sleep   videomode  shut =");
        __std__printf("\n= test    videotype  time =");
        __std__printf("\n= sysinfo setcursor  echo =");
        __std__printf("\n= beep    music           =");
        __std__printf("\n= rand    mkfil           =");
        __std__printf("\n= rdfil   testfs          =");
        __std__printf("\n===========================");
    }
    else if (__shell_cmd_commandcmp(str, "reboot"))
    {
        write_port(0x64, 0xFE);
    }
    else if (__shell_cmd_commandcmp(str, "shut"))
    {
        __asm__("outw %%ax, %%dx"
                :
                : "a"(0x2000), "d"(0x604)); // worked on QEMU
    }
    else if (__shell_cmd_commandcmp(str, "time"))
    {
        __cmos_read_rtc();
        __std__printff("\n%d/%d/%d %d:%d:%d", __cmos_day, __cmos_month, __cmos_year, __cmos_hour, __cmos_minute, __cmos_second);
    }
    else if (__shell_cmd_commandcmp(str, "videotype"))
    {
        if (get_bios_area_video_type() == VIDEO_TYPE_COLOUR)
            __std__printff("\nVideo Type: Colour 0x20");
        else if (get_bios_area_video_type() == VIDEO_TYPE_MONOCHROME)
            __std__printff("\nVideo Type: Monochrome 0x30");
        else
            __std__printff("\nVideo Type: None 0x00");
    }
    else if (__shell_cmd_commandcmp(str, "cls"))
    {
        __std__cls();
        __std__gotoxy(0, 0);
        __std__printc(HEADER, 112);
        __std__gotoxy(0, 0);
    }
    else if (__shell_cmd_commandcmp(str, "sleep"))
    {
        __std__sleep(10000);
    }
    else if (__shell_cmd_commandcmp(str, "sysinfo"))
    {
        __std__cls();
        __std__gotoxy(0, 0);
        __std__printc(HEADER, 112);
        __std__gotoxy(0, 0);
        __std__printff("\nusername: %s", USERNAMENONAMEINAMUROSSHELLSRING);
        __std__printf(SYSVER);
        MULTIBOOT_INFO *mboot_info;
        byte32i i;
        __std__printff("magici: 0x%x\n", magici);
        if (magici == MULTIBOOT_BOOTLOADER_MAGIC)
        {
            mboot_info = (MULTIBOOT_INFO *)addri;
            __std__printff("  flags: 0x%x\n", mboot_info->flags);
            __std__printff("  mem_low: 0x%x KB\n", mboot_info->mem_low);
            __std__printff("  mem_high: 0x%x KB\n", mboot_info->mem_high);
            __std__printff("  boot_device: 0x%x\n", mboot_info->boot_device);
            __std__printff("  cmdline: %s\n", (char *)mboot_info->cmdline);
            __std__printff("  modules_count: %d\n", mboot_info->modules_count);
            __std__printff("  modules_addr: 0x%x\n", mboot_info->modules_addr);
            __std__printff("  mmap_length: %d\n", mboot_info->mmap_length);
            __std__printff("  mmap_addr: 0x%x\n", mboot_info->mmap_addr);
            __std__printff("  boot_loader_name: %s\n", (char *)mboot_info->boot_loader_name);
            __std__printff("  vbe_control_info: 0x%x\n", mboot_info->vbe_control_info);
            __std__printff("  vbe_mode_info: 0x%x\n", mboot_info->vbe_mode_info);
            __std__printff("  framebuffer_addr: 0x%x\n", mboot_info->framebuffer_addr);
            __std__printff("  framebuffer_width: %d\n", mboot_info->framebuffer_width);
            __std__printff("  framebuffer_height: %d\n", mboot_info->framebuffer_height);
            __std__printff("  framebuffer_type: %d", mboot_info->framebuffer_type);
            if (get_bios_area_video_type() == VIDEO_TYPE_COLOUR)
                __std__printff("\nVideo Type: Colour 0x20");
            else if (get_bios_area_video_type() == VIDEO_TYPE_MONOCHROME)
                __std__printff("\nVideo Type: Monochrome 0x30");
            else
                __std__printff("\nVideo Type: None 0x00");
        }
        else
        {
            __std__printff("invalid multiboot magici number\n");
        }
    }
    else if (__shell_cmd_commandcmp(str, "beep"))
    {
        __driver_audio_beeps();
    }
    else if (__shell_cmd_commandcmp(str, "music"))
    {
        __std_music();
    }
    else if (__shell_cmd_commandcmp(str, "videomode"))
    {
        __desktop_init();
        __process_push(__desktop_process);
        __start_process(3);
    }
    else if (__shell_cmd_commandcmp(str, "mkfil "))
    {
        char *string, other;
        int WordLen = 0, ilen = 0;

        char *space = __std__strstr(str, " ");
        WordLen = space - str;

        string = __std__strncpy(string, space[1], sizeof(str) - WordLen);

        char *ispace = __std__strstr(string, " ");
        ilen = space - str;

        other = __std__strncpy(other, ispace[1], sizeof(string) - ilen);

        __fs_writefile(__std__strtok(str, " ")[1], sizeof((char *)other) * sizeof(char *), (char *)other);
    }
    else if (__shell_cmd_commandcmp(str, "rdfil "))
    {
        __std__printff("\n%s", __fs_readfile(__std__strsplit(str, " ")[1]));
    }
    else if (__shell_cmd_commandcmp(str, "test"))
    {
        __std__printc("\nhello\nworld", 32);
    }
    else if (__shell_cmd_commandcmp(str, "rand"))
    {
        __std__printff("\n%d", __std__rand());
    }
    else if (__shell_cmd_commandcmp(str, "testfs"))
    {
        __fs_writefile("test", 4, "abcd");
        __std__printf("\n");
        __std__printf(__fs_readfile("test"));
        //__fs_readfile("test");
        __fs_writefile("test", 4, "efgk");
        __std__printf("\n");
        __std__printf(__fs_readfile("test"));
    }
    else if (__shell_cmd_commandcmp(str, "echo "))
    {
        char *firstWord, *otherString;
        int WordLen = 0, otherStringLen = 0;

        char *space = __std__strstr(str, " ");
        WordLen = space - str;
        otherStringLen = __std__strlen(str) - WordLen - 1;

        __std__printff("\n%s", __std__strncpy(otherString, &space[1], otherStringLen + 1));
    }
    else if (__shell_cmd_commandcmp(str, "setcursor "))
    {
        char *firstWord, *otherString;
        int WordLen = 0, otherStringLen = 0;

        char *space = __std__strstr(str, " ");
        WordLen = space - str;
        otherStringLen = __std__strlen(str) - WordLen - 1;

        if (__std__strcmp(__std__strncpy(otherString, &space[1], otherStringLen + 1), "false"))
        {
            write_port(COMMAND_PORT, 0x0A);
            write_port(DATA_PORT, 0x20);
        }
        else
        {
            write_port(COMMAND_PORT, 0x0A);
            write_port(DATA_PORT, (read_port(DATA_PORT) & 0xC0) | 0);
            write_port(COMMAND_PORT, 0x0A);
            write_port(DATA_PORT, (read_port(DATA_PORT) & 0xC0) | 14);
        }
    }
}