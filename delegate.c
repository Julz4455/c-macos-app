#import "delegate.h"

void initDelegate() {
	AppDelegateClass = cls_allpr((Class)cls("NSObject"), "AppDelegate", 0);

	cls_mthd(AppDelegateClass, 
					 sel("applicationShouldTerminateAfterLastWindowClosed:"), 
					 (IMP)Delegate_applicationShouldTerminateAfterLastWindowClosed, 
					 "B@:");
	
	cls_pair(AppDelegateClass);
}

bool Delegate_applicationShouldTerminateAfterLastWindowClosed(id app) {
	return true;
}