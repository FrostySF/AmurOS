#include "lib.h"
char *__driver_kb_kbbuffer = "";
bool __driver_kb_endinp = false;
int __driver_kb_kbbcur = 0;
int __std__cursorx = 0;
int __std__cursory = 0;
void keyboard_handler(void);
char read_port(bit8 port);
void write_port(bit8 port, byte data);
void load_idt(byte32 *idt_ptr);
void reboot(void);
void videomode(void);
void shutdown(void);
void __driver_audio_music();
void __driver_audio_beeps();
#include "colors.h"
static void *__std__malloc(int sz);
void __std__putc(char ch);
void __std__cursorPosition(int pos);
void __std__delete();
#include "drivers/keyboard.h"
#include "drivers/sound.h"
#include "std.h"
#include "process.h"
#include "shell.h"