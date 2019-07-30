# Expresssion-Calculator
I implemented the expression calculator algorithm for basic math operations.
 Expressions may include
 Positive or negative integers.
 Brackets.
Basic math operators.
 New line char.
 Typical Operaitons:
 1) Input and Output lines
 In all the following, a3.exe is assumed to be the name of your executable, le:
 Input line include
 a3.exe 15+(4/2x3)
 OUTPUT: 21.00
 Multiplication operator in input line is 'x' not '*' (* is considered a wild card in command line arguments).
No spaces in the input expression.
 Output is a float number with two digits after decimal point (use setprecision() function).
 2) ERROR Handling
You should check for the correctness of every command. A wrong expression may include
unbalanced brackets or division by zero.
Wrong expression, Invalid Expression
3) Example Test Cases
 Input: a3.exe (3+4x5)/3
Output: 7.66
 Input: a3.exe
Output: 0.00
Input: a2.exe 5x-3
Output: -15.00
 Input: a2.exe 5x/3
Output: Invalid Expression
