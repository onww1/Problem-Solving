#include <cstdio>
int sh, sm, ss, eh, em, es;
int main() {
	scanf("%d:%d:%d", &sh, &sm, &ss);
	scanf("%d:%d:%d", &eh, &em, &es);
	es -= ss;
	if (es < 0) es += 60, em -= 1;
	em -= sm;
	if (em < 0) em += 60, eh -= 1;
	eh = (eh - sh + 24) % 24;
	printf("%02d:%02d:%02d\n", eh, em, es);
	return 0;
}