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