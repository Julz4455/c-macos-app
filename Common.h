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
#define cls_msg ((id (*)(Class, SEL, ...))objc_msgSend)
#define cls_init(c) msg(msg((id)cls(c), sel("alloc")), sel("init"))
#define cls_alloc objc_allocateClassPair
#define cls_mthd class_addMethod
#define cls_pair objc_registerClassPair

/* typedef enums */
typedef enum NSApplicationActivationPolicy {
	NSApplicationActivationPolicyRegular  = 0,
	NSApplicationActivationPolicyAccesory = 1,
	NSApplicationActivationPolicyERROR    = 2,
} NSApplicationActivationPolicy;

typedef enum NSWindowStyleMask {
	NSWindowStyleMaskBorderless     = 0,
	NSWindowStyleMaskTitled         = 1 << 0,
	NSWindowStyleMaskClosable       = 1 << 1,
	NSWindowStyleMaskMiniaturizable = 1 << 2,
	NSWindowStyleMaskResizable      = 1 << 3,
} NSWindowStyleMask;

typedef enum NSBackingStoreType {
	NSBackingStoreTypeBuffered = 2,
} NSBackingStoreType;

/* typedef structs */
typedef struct arg_t {
	char *content;
	unsigned int len;
	int tack; // None - 0, Single - 1, Double - 2
	int type; // Executable - 0, Tack - 1, Value - 2
} arg_t;
