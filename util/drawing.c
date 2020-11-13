#import "drawing.h"

struct CGRect drawing_createFrame(int x, int y, int w, int h) {
	struct CGRect rect;
	rect.origin.x = x;
	rect.origin.y = y;
	rect.size.width = w;
	rect.size.height = h;
	return rect;
}