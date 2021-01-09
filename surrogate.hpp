#ifndef NULL_sss
#define NULL_sss surrogate_t{0,0,0}
typedef struct __surrogate__{
	char16_t lo=0,hi=0;
	char16_t normal_s=0;
}surrogate_t;
surrogate_t _U32_2_U16_(char32_t __c){
	if(__c<0xD800){surrogate_t __s;__s.normal_s=__c;return __s;}
	else if(__c<0x10000){surrogate_t __s;if(__c<0xE000) return NULL_sss;__s.normal_s=__c;return __s;}
	else if(__c<0x110000){surrogate_t __s;int vc=__c-0x10000,vh=(vc&0xFFC00)>>10,vl=vc&0x3FF,w1=0xD800|vh,w2=0xDC00|vl;__s.hi=w1,__s.lo=w2;return __s;}
	return NULL_sss;
}
#undef NULL_sss
#endif
