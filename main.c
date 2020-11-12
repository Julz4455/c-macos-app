#import "Common.h"
#import "util/args.h"
#import "util/win.h"
#import "delegate.h"

int main(int argc, char **argv) {
	int i, w, h, c;
	char* title;
	bool skipNext;

	w = 600;
	h = 500;
	title = "Pure C App";

	struct arg_t *args = parse_args(argc, argv);
	for(i = 0; i < (argc > ARGS_MAX ? ARGS_MAX : argc); i++) {
		arg_t arg = *(args + i);
		printf("argv[%i : name]: %s\n",  i, arg.content);
		printf("argv[%i :  len]: %u\n",  i, arg.len);
		printf("argv[%i : type]: %i\n",  i, arg.type);
		printf("argv[%i : tack]: %i\n\n",  i, arg.tack);
		if(arg.type == 0) continue;
		else if(skipNext) skipNext = false;
		else if(arg.type == 1 && arg.len == 2) {
			if(arg.tack == 1) {
				c = count_chars(arg.content, 'w');
				if(c == 1) {
					skipNext = true;
					w = atoi((*(args + i + 1)).content);
					w = w == NAN || w == 0 ? 600 : w;
				} else {
					c = count_chars(arg.content, 'h');
					if(c == 1) {
						skipNext = true;
						h = atoi((*(args + i + 1)).content);
						h = h == NAN || h == 0 ? 600 : h;
					} else {
						c = count_chars(arg.content, 't');
						if(c == 1) {
							skipNext = true;
							char *content = (*(args + i + 1)).content;
							title = strlen(content) < 2 ? "Pure C App" : content;
						} else {
							continue;
						}
					}
				}
			}
		}
	}

	initDelegate();

	id app = cls_msg(cls("NSApplication"), sel("sharedApplication"));
	if(app == NULL) {
		fprintf(stderr, "Failed to init NSApplication...\n");
		return 0;
	}
	msg(app, sel("setActivationPolicy:"), NSApplicationActivationPolicyRegular);

	struct CGRect frameRect = win_createFrame(0, 0, 1280, 720);
	int styleMask = NSWindowStyleMaskTitled|NSWindowStyleMaskClosable|NSWindowStyleMaskResizable;
	int backingStore = NSBackingStoreTypeBuffered;
	bool defer = false;

	id win = new_appWindow(frameRect, styleMask, backingStore, defer);
	win_setTitle(win, title);
	msg(win, sel("center"));

	id appDelegate = cls_init("AppDelegate");
	msg(app, sel("setDelegate:"), appDelegate);
	msg(win, sel("makeKeyAndOrderFront:"), nil);
	msg(app, sel("activateIgnoringOtherApps:"), true);
	msg(app, sel("run"));

	return 0;
}
