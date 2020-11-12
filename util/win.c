#import "win.h"
#import "str.h"

id new_appWindow(struct CGRect frameRect, int styleMask, int backingStore, bool defer) {
	return msg(cls_msg(cls("NSWindow"), sel("alloc")),
						 sel("initWithContentRect:styleMask:backing:defer:"),
						 frameRect,
						 styleMask,
						 backingStore,
						 defer);
}

void win_setTitle(id win, char *title) {
	msg(win, sel("setTitle:"), new_str(title));
}

struct CGRect win_createFrame(int x, int y, int w, int h) {
	struct CGRect rect;
	rect.origin.x = x;
	rect.origin.y = y;
	rect.size.width = h;
	rect.size.height = h;
	return rect;
}