#include <math.h>
#include <conio.h>
#include <stdio.h>

double f(double x) {
	return exp(x);
}

double aintegral(double a, double b) {
	double res = exp(b) - exp(a);
	return res;
}

double trap(double a, double b, int n) {
	double res = f(a);
	double delta = (b - a) / n;
	for (int i = 1; i < n; i++) {
		res += 2 * f(a + delta * i);
	}
	res += f(b);
	res = 0.5 * (delta * res);
	return res;

}
double left_rect (double a, double b, int n){
   double res = 0;
   double delta = (b - a) / n;
   for (int i = 0; i <= (n - 1); i++){
	   res += f(a);
	   a += delta;
   }
   return delta * res;
}

double right_rect (double a, double b, int n){
   double res = 0;
   double delta = (b - a) / n;
   a += delta;
   for (int i = 0; i < (n); i++){
	   res += f(a);
	   a += delta;
   }
   return delta * res;
}

double simpson (double a, double b, double n){
	double res = 0, delta;
	delta = (b-a)/n;
	for(int i = 0; i<=(n-1); i++){
		if (i%2 == 0)
			res += 2*f(a);
		else
			res += 4*f(a);
			a += delta;
	}
	return delta / 3*(res+f(a)+ f(b));
}

int main() {
	double a = 1;
	double b = 2;
	double prevI = 0;
	int n = 1;
	double eps = 0.00001;

	while (1) {
		double ai = aintegral(a, b);
		double i = trap(a, b, n);

		double deltaA = fabs(ai - i);
		double deltaPrev = fabs(i - prevI);

		if (deltaPrev < eps) {
			printf("n=%u\nreference=%lf\ntrap=%lf\n", n, ai, i);
			printf("delta=%lf\ndelta-prev=%lf\n", deltaA, deltaPrev);
			break;
		}
		n += 2;
		prevI = i;
	}
printf("=======================================\n");
	while (1) {
		double ai = aintegral(a, b);
		double i = left_rect(a, b, n);

		double deltaA = fabs(ai - i);
		double deltaPrev = fabs(i - prevI);

		if (deltaPrev < eps) {
			printf("n=%u\nreference=%lf\nleft rect=%lf\n", n, ai, i);
			printf("delta=%lf\ndelta-prev=%lf\n", deltaA, deltaPrev);
			break;
		}
		n += 2;
		prevI = i;
	}
	printf("=======================================\n");
	while (1) {
		double ai = aintegral(a, b);
		double i = right_rect(a, b, n);

		double deltaA = fabs(ai - i);
		double deltaPrev = fabs(i - prevI);

		if (deltaPrev < eps) {
			printf("n=%u\nreference=%lf\nright rect=%lf\n", n, ai, i);
			printf("delta=%lf\ndelta-prev=%lf\n", deltaA, deltaPrev);
			break;
		}
		n += 2;
		prevI = i;
	}
	printf("=======================================\n");
	while (1) {
		double ai = aintegral(a, b);
		double i = simpson(a, b, n);

		double deltaA = fabs(ai - i);
		double deltaPrev = fabs(i - prevI);

		if (deltaPrev < eps) {
			printf("n=%u\nreference=%lf\nsimpson=%lf\n", n, ai, i);
			printf("delta=%lf\ndelta-prev=%lf\n", deltaA, deltaPrev);
			break;
		}
		n += 2;
		prevI = i;
	}
	printf("=======================================\n");

	return 0;
}
