#import "../Common.h"

id new_appWindow(struct CGRect frameRect, int styleMask, int backingStore, bool defer, bool tbt, bool vibrant);
void win_setTitle(id win, char *title);
struct CGRect win_createFrame(int x, int y, int w, int h);