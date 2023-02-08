#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void printWelcomeMessage();
void printResult(double num1, char *operation, double num2, double result);
void printSingleVarFunc(double x, char *operation, double result);
void resetCalc(double *result, double *num1, double *num2, bool *calculationMade, char *operationString);
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double power(double base, double exponent);
double squareRoot(double radicand);
double exponential(double x);
double naturalLog(double x);
double sine(double x);
double cosine(double x);
double tangent(double x);

int main(void)
{
  const int USER_TEXT_LIMIT = 500;
  double num1;
  double num2;
  double result = 0.00;
  bool continueCalculating = true;
  bool calculationMade = false;

  printWelcomeMessage();

  while (continueCalculating)
  {
    char inputString[USER_TEXT_LIMIT];
    char operationString[10];

    printf("[%.2lf]\n", result);

    fgets(inputString, USER_TEXT_LIMIT, stdin);
    sscanf(inputString, "%10s", operationString);

    if (strcmp(operationString, "help") == 0)
    {
      printWelcomeMessage();
    }
    else if (strcmp(operationString, "clear") == 0)
    {
      resetCalc(&result, &num1, &num2, &calculationMade, operationString);
      printf("\n**Memory Cleared**\n");
      continue;
    }
    else if (strcmp(operationString, "exit") == 0)
    {
      printf("\n**Turning off calculator**\n");
      break;
    }

    if (calculationMade)
    {
      num1 = result;
      sscanf(inputString, "%10s %20lf", operationString, &num2);
    }
    else
    {
      sscanf(inputString, "%20lf %10s %20lf", &num1, operationString, &num2);
      if (!num2)
      {
        result = num1;
      }
    }

    if (strcmp(operationString, "+") == 0)
    {
      result = add(num1, num2);
    }
    else if (strcmp(operationString, "-") == 0)
    {
      result = subtract(num1, num2);
    }
    else if (strcmp(operationString, "*") == 0)
    {
      result = multiply(num1, num2);
    }
    else if (strcmp(operationString, "/") == 0)
    {
      result = divide(num1, num2);
    }
    else if (strcmp(operationString, "^") == 0)
    {
      result = power(num1, num2);
    }
    else if (strcmp(operationString, "sqrt") == 0)
    {
      result = squareRoot(num1);
    }
    else if (strcmp(operationString, "e") == 0)
    {
      result = exponential(num1);
    }
    else if (strcmp(operationString, "ln") == 0)
    {
      result = naturalLog(num1);
    }
    else if (strcmp(operationString, "sin") == 0)
    {
      result = sine(num1);
    }
    else if (strcmp(operationString, "cos") == 0)
    {
      result = cosine(num1);
    }
    else if (strcmp(operationString, "tan") == 0)
    {
      result = tangent(num1);
    }

    calculationMade = true;
  }

  return 0;
}

void printWelcomeMessage(void)
{
  printf(
      "\n** Welcome to my C calculator.\n\n**"

      "About:\n\n"
      "* Perform one operation at a time.\n"
      "* Spaces are meaningful and required.\n"
      "* Initial one variable operation: <operand> <operator> Ex: 100 sqrt\n"
      "* Initial two variable operation: <operand> <operator> <operand> Ex: 2 + 2\n"
      "* 4 is now in memory.\n"
      "* Continue operating on answer (4) with <operator> <operand> Ex: + 2\n"
      "* 6 is now in memory.\n"
      "Available operations:\n"
      "add(+), subtract(-), multiply(*), divide(/), power(^),\n"
      "square-root(sqrt), euler(e), natural-log(ln),\nsine(sin), cosine(cos), tangent(tan)\n\n"
      "**Enter <help> to show this message again.**\n"
      "**Enter <exit> to quit calculator**\n"
      "* Enter <clear> to clear memory (AC).\n\n");
}

void printResult(double num1, char *operation, double num2, double result)
{
  printf("\n[ %.2lf %c %.2lf = %.4lf ]\n", num1, *operation, num2, result);
}

void printSingleVarFunc(double x, char *operation, double result)
{
  printf("\n[%s(%.2lf) = %.4lf]\n", operation, x, result);
}

void resetCalc(double *result, double *num1, double *num2, bool *calculationMade, char *operationString)
{
  *result = 0.00;
  *num1 = 0.00;
  *num2 = 0.00;
  *calculationMade = false;
  strcpy(operationString, "");
}

double add(double num1, double num2)
{
  char operation[1] = "+";
  double sum = num1 + num2;
  printResult(num1, operation, num2, sum);
  return sum;
}

double subtract(double num1, double num2)
{
  char operation[1] = "-";
  double difference = num1 - num2;
  printResult(num1, operation, num2, difference);
  return difference;
}

double multiply(double num1, double num2)
{
  char operation[1] = "*";
  double product = num1 * num2;
  printResult(num1, operation, num2, product);
  return product;
}

double divide(double num1, double num2)
{
  char operation[1] = "/";
  double quotient = num1 / num2;
  printResult(num1, operation, num2, quotient);
  return quotient;
}

double power(double base, double exponent)
{
  char operation[1] = "^";
  double power = pow(base, exponent);
  printResult(base, operation, exponent, power);
  return power;
}

// sqrt == x^(1/2)
double squareRoot(double radicand)
{
  double squareRoot = power(radicand, (1.0 / 2.0));
  return squareRoot;
}

// base e to the x
double exponential(double x)
{
  double exponential = exp(x);
  printf("\n[e^%.2lf = %.4lf]\n", x, exponential);
  return exponential;
}

// ln(x)
double naturalLog(double x)
{
  double ln = log(x);
  char operation[2] = "ln";
  printSingleVarFunc(x, operation, ln);
  return ln;
}

double sine(double x)
{
  char operation[3] = "sin";
  double s = sin(x);
  printSingleVarFunc(x, operation, s);
  return s;
}

double cosine(double x)
{
  char operation[3] = "cos";
  double c = cos(x);
  printSingleVarFunc(x, operation, c);
  return c;
}

double tangent(double x)
{
  char operation[3] = "tan";
  double t = tan(x);
  printSingleVarFunc(x, operation, t);
  return t;
}
