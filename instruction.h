#define iinp 1
#define ista 2
#define iadd 3
#define isub 4
#define iout 5
#define ilda 6
#define icmp 7
#define ijmp 8
#define ijlt 9
#define ijet 10
#define ijmt 11
#define ihlt 12
#define ipsh 13
#define inop 14

typedef struct instruction {
	char 			inst;
	unsigned char 	param;
} inst;