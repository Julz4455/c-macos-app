#import <objc/runtime.h>
#import <objc/message.h>
#import <Carbon/Carbon.h>
#import <stdio.h>
#import <string.h>
#import <stdlib.h>
#import <math.h>
#import <time.h>
#import <unistd.h>

/* constant defines */
#define ARGS_MAX 10

#ifndef NAN
#define NAN sqrt(-1)
#endif

/* objc macros */
#define cls objc_getClass
#define sel sel_getUid
#define msg ((id (*)(id, SEL, ...))objc_msgSend)
#define msg_sup ((id (*)(Class, SEL, ...))objc_msgSendSuper)
#define cls_msg ((id (*)(Class, SEL, ...))objc_msgSend)
#define cls_init(c) msg(msg((id)cls(c), sel("alloc")), sel("init"))
#define cls_alloc(c) msg((id)cls(c), sel("alloc")) 
#define cls_allpr objc_allocateClassPair
#define cls_mthd class_addMethod
#define cls_pair objc_registerClassPair


/* Global Variables */
int w, h;
char* title;
id controller;
id win;

/* general typedef */
typedef long NSInteger;
typedef double CGFloat;
typedef double NSTimeInterval;
typedef NSInteger NSModalResponse;

/* typedef enums */
typedef enum NSApplicationActivationPolicy {
	NSApplicationActivationPolicyRegular  = 0,
	NSApplicationActivationPolicyAccesory = 1,
	NSApplicationActivationPolicyERROR    = 2,
} NSApplicationActivationPolicy;

typedef enum NSWindowStyleMask {
	NSWindowStyleMaskBorderless          = 0,
	NSWindowStyleMaskTitled              = 1 << 0,
	NSWindowStyleMaskClosable            = 1 << 1,
	NSWindowStyleMaskMiniaturizable      = 1 << 2,
	NSWindowStyleMaskResizable           = 1 << 3,
	NSWindowStyleMaskFullSizeContentView = 1 << 15,
} NSWindowStyleMask;

typedef enum NSBackingStoreType {
	NSBackingStoreTypeBuffered = 2,
} NSBackingStoreType;

typedef enum NSBezelStyle {
	NSBezelStyleRounded = 1,
} NSBezelStyle;

typedef enum NSButtonType {
	NSButtonTypeMomentaryLight = 0
} NSButtonType;

typedef enum NSVisualEffectMaterial {
	NSVisualEffectMaterialLight                 = 1,
	NSVisualEffectMaterialWindowBackground      = 12,
	NSVisualEffectMaterialContentBackground     = 18,
	NSVisualEffectMaterialUnderWindowBackground = 21
} NSVisualEffectMaterial;

typedef enum NSVisualEffectBlendingMode {
  NSVisualEffectBlendingModeBehindWindow = 0,
  NSVisualEffectBlendingModeWithinWindow = 1,
} NSVisualEffectBlendingMode;

typedef enum NSVisualEffectState {
  NSVisualEffectStateFollowsWindowActiveState = 0,
  NSVisualEffectStateActive                   = 1,
  NSVisualEffectStateInactive                 = 2,
} NSVisualEffectState;

/* typedef structs */
typedef struct arg_t {
	char *content;
	unsigned int len;
	int tack; // None - 0, Single - 1, Double - 2
	int type; // Executable - 0, Tack - 1, Value - 2
} arg_t;
