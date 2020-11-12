#import "args.h"

struct arg_t* parse_args(int argc, char **argv) {
	int i;
	arg_t *args = (arg_t*)malloc(ARGS_MAX * sizeof(arg_t));

	for(i = 0; i < (argc > ARGS_MAX ? ARGS_MAX : argc); i++) {
		if(i == 0) {
			arg_t new_arg = {
				*argv, strlen(*argv),
				0, 0
			};
			args[i] = new_arg;
		} else {
			int tack_num = count_chars(*(argv + i), '-');
			int tack_type = tack_num >= 2 ? 2 : tack_num == 1 ? 1 : 0;
			int arg_type = tack_type ? 1 : 2;
			arg_t new_arg = {
				*(argv + i), strlen(*(argv + i)),
				tack_type, arg_type
			};
			args[i] = new_arg;
		}
	}

	return args;
}

int count_chars(char *s, char ch) {
	int c = 0;
	for(; *s; c += (*s++ == ch)) ;
	return c;
}
