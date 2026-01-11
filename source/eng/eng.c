#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>

int main(void) {

    // --- doc-0001 - tries to explain what this block does. ------------------------------------------ //
    struct passwd *pw = getpwuid(getuid()); 								//
    if (!pw) return 1;											//
    char *home = pw->pw_dir;										//
													//
    int build_path(char *out, size_t size, const char *base, const char *suffix) {			//
        return snprintf(out, size, "%s/%s", base, suffix) >= (int)size					//
               ? -1											//
               : 0;											//
    };													//
													//
    char path[256];											//
													//
    char SAVE_DIR = build_path(path, sizeof(path), home, ".minecraft/saves");				//
    char BKP_HID_DIR = build_path(path, sizeof(path), home, ".local/share/.backupcraft_hidden");	//
    char SETT_FILE = build_path(path, sizeof(path), home, ".config/backupcraft/settings.conf");		//
    char LOG_DIR = build_path(path, sizeof(path), home, ".config/backupcraft/logs");			//
    // ------------------------------------------------------------------------------------------------ //

    

    return 0;
}
