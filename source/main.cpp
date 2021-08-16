#include <nds.h>
#include <filesystem.h>

#include <stdio.h>

int main(int argc, char **argv) {
	
	consoleDemoInit();

	char* path = "fat:/nitrofs-example.nds";
	__system_argv->argvMagic = ARGV_MAGIC; 
	__system_argv->argc = 1;
	__system_argv->argv = &path;
	
	nitroFSInit(NULL);

	char buffer[256];
	FILE* file = fopen("nitro:/file.txt","r");
	fscanf(file, "%s", buffer);
	iprintf("%s", buffer);

	while(1) {
		swiWaitForVBlank();
		scanKeys();
		if(keysDown()&KEY_START) break;
	}

	return 0;
}
