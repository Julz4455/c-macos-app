#import "delegate.h"
#import "util/str.h"

void initDelegate() {
	AppDelegateClass = cls_allpr((Class)cls("NSObject"), "AppDelegate", 0);

	cls_mthd(AppDelegateClass, 
					 sel("applicationShouldTerminateAfterLastWindowClosed:"), 
					 (IMP)Delegate_applicationShouldTerminateAfterLastWindowClosed, 
					 "B@:");

	cls_mthd(AppDelegateClass,
					 sel("applicationDockMenu:"),
					 (IMP)Delegate_applicationDockMenu,
					 "@@:");

	cls_mthd(AppDelegateClass,
					 sel("itemDidActivate:"),
					 (IMP)Delegate_itemDidActivate,
					 "v@:");
	
	cls_pair(AppDelegateClass);
}

bool Delegate_applicationShouldTerminateAfterLastWindowClosed(id app) {
	return true;
}

id Delegate_applicationDockMenu(id app) {
	id menu = cls_msg((Class)cls_alloc("NSMenu"), sel("initWithTitle:"), new_str(title));
	id itemA = cls_msg((Class)cls_alloc("NSMenuItem"), sel("initWithTitle:action:keyEquivalent:"), 
										new_str("Some Item"),
										sel("itemDidActivate:"),
										new_str(""));

	msg(menu, sel("addItem:"), itemA);

	return menu;
}

void Delegate_itemDidActivate(id item) {
	id alert = cls_init("NSAlert");
	msg(alert, sel("addButtonWithTitle:"), new_str("Cancel"));
	msg(alert, sel("addButtonWithTitle:"), new_str("Sure"));
	msg(alert, sel("setMessageText:"), new_str("Begin?"));
	msg(alert, sel("setShowsSuppressionButton:"), true);
	msg(alert, sel("beginSheetModalForWindow:completionHandler:"),
						 cls_msg((Class)cls_msg(cls("NSApplication"), sel("sharedApplication")), sel("keyWindow")),
						 ^(NSModalResponse code) {
						 	printf("Code: %li\n", code);
						 });
}