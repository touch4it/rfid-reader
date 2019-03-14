#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int fd, result = 0;
    struct input_event ev;
    char *map = "..1234567890-=..qwertyuiop[]\n.asdfghjkl;'\\zxcvbnm,./";
    char name[256] = "unknown";

    if(argc < 2) {
        printf("Usage:   %s <device>\n", argv[0]);
        printf("Example: %s /dev/input/event6", argv[0]);
        printf("If you are unsure, which event to use, use '/dev/input/by-id/<id>'\n");
        printf("Have a look at 'evtest' utility to test desired input device.\n");
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    result = ioctl(fd, EVIOCGNAME(sizeof(name)), name);
    printf ("Reading From : %s (%s)\n", argv[1], name);

    printf("Getting exclusive access: ");
    result = ioctl(fd, EVIOCGRAB, 1);
    printf("%s\n", (result == 0) ? "SUCCESS" : "FAILURE");

    while (1){
           read(fd, &ev, sizeof(struct input_event));
        if( (ev.type == EV_KEY) && (ev.value == 0) )
            printf("%c", map[ev.code]);
    }
}
