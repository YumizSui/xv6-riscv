#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char buf[512];

int
main(int argc, char *argv[])
{
  if(argc <= 1){
    fprintf(2, "Usage: readlink FILE...\n");
    exit(1);
  }

  for(int i = 1; i < argc; i++){
    if((readlink(argv[i], buf, 512)) < 0){
      fprintf(2, "readlink: cannot read %s\n", argv[i]);
      exit(1);
    }
    printf("%s\n", buf);
  }
  exit(0);
}
