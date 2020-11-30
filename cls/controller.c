#import "controller.h"
#import "../util/drawing.h"
#import "../util/str.h"

static id textField;
static id startButton;
static id mainView;
static id dateLabel;

void initController() {
	ViewControllerClass = cls_allpr((Class)cls("NSViewController"), "ViewController", 0);

	cls_mthd(ViewControllerClass,
					 sel("loadView"),
					 (IMP)Controller_loadView,
					 "v:");
	cls_mthd(ViewControllerClass,
					 sel("viewDidLoad"),
					 (IMP)Controller_viewDidLoad,
					 "v:");
	cls_mthd(ViewControllerClass,
					 sel("viewDidAppear:"),
					 (IMP)Controller_viewDidAppear,
					 "vB:");
	cls_mthd(ViewControllerClass,
					 sel("beginTranslation:"),
					 (IMP)Controller_beginTranslation,
					 "v@:");

	cls_pair(ViewControllerClass);
}

void Controller_loadView() {
	mainView = msg((id)cls_alloc("NSVisualEffectView"), sel("initWithFrame:"), drawing_createFrame(0, 0, w, h));
	msg(mainView, sel("setState:"), NSVisualEffectStateActive);
	msg(mainView, sel("setBlendingMode:"), NSVisualEffectBlendingModeBehindWindow);
	// msg(mainView, sel("setMaterial:"), NSVisualEffectMaterialContentBackground);

	msg(controller, sel("setView:"), mainView);
}

void Controller_viewDidLoad() {
	textField = msg(cls_alloc("NSTextField"), sel("init"));
	msg(textField, sel("setFrame:"), drawing_createFrame((w / 2) - 150, (h / 1.11), 200, 22));
	msg(textField, sel("setPlaceholderString:"), new_str("ID to translate (Snowflake)"));
	msg(mainView, sel("addSubview:"), textField);

	startButton = cls_msg(cls("NSButton"), sel("buttonWithTitle:target:action:"), 
										new_str("Translate"),
										controller,
										sel("beginTranslation:"));
	msg(startButton, sel("setFrame:"), drawing_createFrame((w / 2) + 50, (h / 1.11), 100, 22));
	msg(mainView, sel("addSubview:"), startButton);

	dateLabel = msg(cls_alloc("NSTextField"), sel("init"));
	msg(dateLabel, sel("setFrame:"), drawing_createFrame((w / 2) - 310, (h / 1.33), 1000, 62));
	msg(dateLabel, sel("setBezeled:"), false);
	msg(dateLabel, sel("setDrawsBackground:"), false);
	msg(dateLabel, sel("setEditable:"), false);
	msg(dateLabel, sel("setSelectable:"), false);
	msg(dateLabel, sel("setStringValue:"), new_str("Enter a date above"));
	msg(dateLabel, sel("setFont:"), cls_msg(cls("NSFont"), sel("systemFontOfSize:weight:"), 42.00, 0.300000));
	msg(mainView, sel("addSubview:"), dateLabel);
}

void Controller_beginTranslation(id sender) {
	const char* snowflake = (char*)msg(msg(textField, sel("stringValue")), sel("UTF8String"));
	long snowflake_l = atol(snowflake);
	unsigned long snowflake_len = strlen(snowflake);

	if(snowflake_len >= 18 && snowflake_l != 0) {
		time_t stamp = (snowflake_l >> (long)22) + (long)1577854800000;
		NSTimeInterval unixStamp = stamp / 1000.0;
		id date = cls_msg(cls("NSDate"), sel("dateWithTimeIntervalSince1970:"), unixStamp);
		id formatter = msg(cls_alloc("NSDateFormatter"), sel("init"));
		msg(formatter, sel("setDateFormat:"), new_str("MMMM d, yyyy HH:mm:ss.SSS zzz\n"));
		id fdate = msg(formatter, sel("stringFromDate:"), date);

		msg(dateLabel, sel("setFrame:"), drawing_createFrame((w / 2) - 390, (h / 1.33), 1000, 62));
		msg(dateLabel, sel("setStringValue:"), fdate);
		// 121171143313850368
	}
}

void Controller_viewDidAppear(bool animated) {

}

