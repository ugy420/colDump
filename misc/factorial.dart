import 'dart:io';
void main() {
  stdout.write("Enter a number: ");
  String input = stdin.readLineSync() ?? '';
  int number = int.parse(input);
  int factorial = calculateFactorial(number);
  print("The factorial of $number is $factorial");
  }
  int calculateFactorial(int n) {
  if (n == 0 || n == 1) {
  return 1;
  } else {
  return n * calculateFactorial(n - 1);
  }
}