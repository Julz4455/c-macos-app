#import "win.h"
#import "../cls/controller.h"
#import "str.h"
#import "drawing.h"

id new_appWindow(struct CGRect frameRect, int styleMask, int backingStore, bool defer, bool tbt, bool vibrant) {
	id win = msg(cls_msg(cls("NSWindow"), sel("alloc")),
						 sel("initWithContentRect:styleMask:backing:defer:"),
						 frameRect,
						 styleMask,
						 backingStore,
						 defer);
	msg(win, sel("center"));
	/* View Controller */
	controller = cls_init("ViewController");
	msg(win, sel("setContentViewController:"), controller);
	msg(win, sel("setTitlebarAppearsTransparent:"), tbt);
	if(vibrant) {
		msg(win, sel("setOpaque:"), false);
		msg(win, sel("setBackgroundColor:"), cls_msg(cls("NSColor"), sel("clearColor")));
	}

	return win;
}

void win_setTitle(id win, char *title) {
	msg(win, sel("setTitle:"), new_str(title));
}