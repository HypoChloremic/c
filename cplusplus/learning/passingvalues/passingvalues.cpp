// Aight, first and foremost, it seems that there is no issue in
// passing variables thru functions:
double somefunction(double, double);


int main(int argc, char const *argv[])
{
	double X = 10;
	double Y = 12;

	double result = somefunction(X, Y);
	return 0;

}

double somefunction(double x, double y){
	return x + y;
}

// We see that it is possible to be passing these values around relatively
// simple.