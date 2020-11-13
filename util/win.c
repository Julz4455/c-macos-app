#import "win.h"
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
	msg(win, sel("setTitlebarAppearsTransparent:"), tbt);
	if(vibrant) {
		msg(win, sel("setOpaque:"), false);
		msg(win, sel("setBackgroundColor:"), cls_msg(cls("NSColor"), sel("clearColor")));

		/* General Drawing */
		id mainView = msg((id)cls_alloc("NSVisualEffectView"), sel("initWithFrame:"), drawing_createFrame(0, 0, frameRect.size.width, frameRect.size.height));
		msg(mainView, sel("setState:"), NSVisualEffectStateActive);
		msg(mainView, sel("setBlendingMode:"), NSVisualEffectBlendingModeBehindWindow);
		// msg(mainView, sel("setMaterial:"), NSVisualEffectMaterialContentBackground);

		// msg(msg(win, sel("contentView")), sel("addSubview:"), mainView);
		msg(win, sel("setContentView:"), mainView);
	}

	return win;
}

void win_setTitle(id win, char *title) {
	msg(win, sel("setTitle:"), new_str(title));
}