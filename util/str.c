#import "str.h"

id new_str(char *str) {
	return cls_msg(cls("NSString"), sel("stringWithUTF8String:"), str);
}