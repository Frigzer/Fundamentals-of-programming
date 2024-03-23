#include <stdlib.h> // USES
#include <stdio.h>	// USES
#include <math.h>	// USES

// sposób na łatwą zmianę typu dla wszystkich zmiennych w programie
//#define SCALAR double
#define SCALAR float

#define TOLERANCE 0.0000001

#define SMALL_NUMBER 1.e-20

// Testowanie: konstrukcji sterujących (a także nazw zmiennych,
// zakresów widoczności i czasu życia)
int main(void)
{
	// rozwiązanie równania kwadratowego ax^2 + bx + c = 0

	printf("\nProgram rozwiązywania równania kwadratowego ax^2 + bx + c = 0\n");

	// typ a, b, c ustalany poprzez symbol SCALAR
	SCALAR a, b, c;
	// rozważania o kontrakcie... (czy uwzględnia skończoną precyzję?)
	// input - uodpornianie na błędy wczytywania danych
	printf("\nPodaj parametr a: ");
	scanf("%f", &a); // adres! (miejsce na wpisanie wartości)
	printf("Podaj parametr b: ");
	scanf("%f", &b); // uwaga: inny format dla float!
	printf("Podaj parametr c: ");
	scanf("%f", &c);

	//printf("b;x1;x2\n"); // formatowanie pod tabele w excel

	// a = 10^-ai z kazda iteracja
	// for(int ia = 5; ia < 16; ia++) {
	// a = powf(10, -ia);

	// b = 10^ib z kazda iteracja
	// for(int ib = 2; ib < 10; ib++)
	{
		// b = powf(10, ib);
		//  if(a==0 && b==0){ // alternatywa: if( a==0 || b==0 ) - zależnie od kontraktu
		if (fabs(a) < SMALL_NUMBER && fabs(b) < SMALL_NUMBER)
		{ // poprawnie

			printf("Błędne dane: a i b równe 0 (zbyt bliskie 0). Przerwanie programu.\n");
			exit(-1);
		}
		else
		{

			if (a == 0)
			{	// równanie liniowe
				// Obliczmy dla prostej:
				if (fabs(b) < TOLERANCE)
					if (fabs(c) > TOLERANCE)
						// rownolegla do OX
						printf("Prosta linia, nie przecina sie z osia OX");
					else
						// C = 0, wiec przechodzi przez x = 0
						printf("Prosta przecina sie z osia OX dla x = 0\n");
				else
				{
					// skoro y = bx + c, to y = 0 dla x = -c/b
					printf("Prosta przecina sie z osia OX dla x = %lf\n", (-c / b));
				}

				// co mówi kontrakt? - czy należy rozważyć liczby a bliskie 0 ?
			}
			else
			{

				SCALAR delta;				   // zakres widoczności nazwy - powiązanie z czasem życia
				delta = (b * b) - (4 * a * c); // problem jeśli delta bliskie b*b (w skończonej precyzji)
											   // wtedy odejmowanie b i sqrt(delta) traci cyfry znaczące
											   // printf("delta: %lf, real delta: %lf\n", delta, (b*b) - (4*a*c));

				if (delta < 0)
				{

					// printf("Dwa pierwiastki zespolone - nie umiem obliczyć. \\;\n");

					SCALAR real_part1 = -b / (2 * a);
					SCALAR imaginary_part1 = sqrt((b * b) - 4 * a * c) / (2 * a);

					SCALAR real_part2 = -b / (2 * a);
					SCALAR imaginary_part2 = -sqrt((b * b) - 4 * a * c) / (2 * a);

					printf("Pierwiastki liczby zespolonej:\n");
					printf("z1: Re(z1) = %lf, Im(z1) = i%lf\n", real_part1, imaginary_part1);
					printf("z2: Re(z2) = %lf, Im(z2) = i%lf\n", real_part2, imaginary_part2);
				}
				else if (fabs(delta) < TOLERANCE)
				{
					printf("Jeden pierwiastek rzeczywisty: x = %.5le\n", -b/(2*a) );
					//SCALAR temp = sqrt(delta);
					//SCALAR x1 = (-b - temp) / (2 * a);
					//printf("%.le;%le;%le\n", a, x1, 0);
				}
				else
				{
					SCALAR temp = sqrt(delta);
					SCALAR x1 = (-b - temp) / (2 * a);
					SCALAR x2 = (-b + temp) / (2 * a);
					//printf("%.le;%le;%le\n", b, x1, x2);
					printf("Dwa pierwiastki rzeczywiste: x1 = %.5le, x2 = %.5le\n",x1, x2 );

					if ((fabs(a * (x1 * x1) + (b * x1) + c) < TOLERANCE) &&
						(fabs(a * (x2 * x2) + (b * x2) + c) < TOLERANCE))
					{
						printf("x1 oraz x2 sa sprawdzonymi pierwiastkami rzeczywistymi rownania.\n");
					}
					else
					{
						printf("x1, lub x2 nie jest poprawnym pierwiastkiem rzeczywistym rownania\n");
					}
				}
			} // znaczenie wcięć i nawiasów klamrowych dla zwiekszenia czytelności kodu !
		}
	}

	return (0);
}
