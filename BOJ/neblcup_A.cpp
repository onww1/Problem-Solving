#include <iostream>
using namespace std;

int abs(int a){ return a>0?a:-a;}

int gcd(int a, int b){
	int ta = a, tb = b, gcd = b;

	while(a%gcd > 0){
		b = a % gcd;
		a = gcd;
		gcd = b;
	}

	return gcd;
}

struct fraction{
	int numerator;
	int denominator;

	fraction(){}
	fraction(int num, int den){
		int new_gcd = gcd(num, den);
		numerator = num/new_gcd;
		denominator = den/new_gcd;
	}
};

fraction add(fraction a, fraction b){
	int de_gcd = gcd(a.denominator, b.denominator);
	int denominator = (a.denominator * b.denominator) / de_gcd;
	int numerator = a.numerator * (a.denominator / de_gcd) + b.numerator * (b.denominator / de_gcd);
	int new_gcd = gcd(denominator, numerator);
	return {numerator/new_gcd, denominator/new_gcd};
}

fraction multiply(fraction a, fraction b){
	int numerator = a.numerator * b.numerator;
	int denominator = a.denominator * b.denominator;
	int new_gcd = gcd(numerator, denominator);
	return {numerator/new_gcd, denominator/new_gcd};
}

fraction divide(fraction a, fraction b){
	int numerator = a.numerator * b.denominator;
	int denominator = a.denominator * b.numerator;
	int new_gcd = gcd(numerator, denominator);
	return {numerator/new_gcd, denominator/new_gcd};
}

fraction add_int(fraction a, int b){
	int numerator = a.numerator + b * a.denominator;
	return {numerator, a.denominator};
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, X[51], H[51], S, E;
	cin >> N;
	for(int i=0; i<N+1; i++){
		cin >> X[i] >> H[i];
	}
	cin >> S >> E;

	fraction Sh, Eh;
	bool flag = false;
	for(int i=0; i<N+1; i++){
		if(!flag && X[i] <= S){
			flag = true;
			Sh = fraction((H[i+1] - H[i]) * (S-X[i]), (X[i+1]-X[i]));
			add_int(Sh, H[i]);
		}
		if(flag && X[i] <= E){
			Eh = fraction((H[i+1] - H[i]) * (E-X[i]), (X[i+1]-X[i]));
			add_int(Eh, H[i]);
		}
	}

	Sh.numerator *= -1;
	fraction FinalH = add(Eh, Sh);
	FinalH.numerator = abs(FinalH.numerator);
	int FinalX = abs(E - S);
	FinalH.denominator *= FinalX;

	int new_gcd = gcd(FinalH.numerator, FinalH.denominator);
	if(FinalH.denominator == 1 || FinalH.numerator % FinalH.denominator == 0) cout << (FinalH.numerator / FinalH.denominator) << '\n';
	else cout << (FinalH.numerator/new_gcd) << '/' << (FinalH.denominator/new_gcd) << '\n';

	return 0;
}