// sysinfo
#define SYSVER "\nSysName: AmurOS\nversion: 0.0.5e(0.0.6)\nCorp: AmurOS"
// header
#define HEADER "                                      Amur                                      "

char *logo = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BPx<@@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#dc<`    #@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BGi,         #@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@gj^.             #@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@8V^`                 #@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Rn!`                 `,<i@@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#Rl~`               ,^lUR#@@@@@@"
             "@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#Si:             `??JOB@@@@@@@@@@@@@"
             "@8^h#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#Dtr-            ,*nqQ@@@@@@@@@@@@@@@@@@@"
             "@@@z,>XB@@@@@@@@@@@@@@@@@@@@@@@@@@Qqn*-          `!(J6B@@@@@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@qr`_rzdB@@@@@@@@@@@@@#QdX]^,         `?^}aR#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@Rl=`  `-,=!!=:,-`        -:^|la6Q#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@@@@@Qdhn]v(((vx}u2ePd$Q#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@@@@@@@@@@@@@]`,BB@@@@@@#@@#@@@##@@@@@##@@@##@@@@@#@@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@@@@@@@@@@@@n S#_-#@@@@V =Ux ~wn <@@@@  #@@  #@@@: ?VzW@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@@@@@@@@@@@? (nn}--8@@@V *@Q :@#``@@@@` D#E  #@@@: R@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@@@@@@@@@@#eq@@@@QeZ@@@8eE@#eZ@@mm@@@@QX2eRhh@@@@Ze#@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
             "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

#include "include.h"

void kmain(void)
{
    __shell_init();
    __process_push(__shell_process);
    __start_processes();
}
