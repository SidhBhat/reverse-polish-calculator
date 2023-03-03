# reverse-polish-calculator

An interactive reverse polish calculator. This tiny project is an extension of the example
given in chapter 4 of the book "The C Programming Language" second edition, by Brian W. Kernighan
and Dennis M. Ritchie \(ISBN: 978-93-325-4944-9\). Basically exersice 4.3 t0 4.9.

## Compilation

The Makefile here is taken from [simple-make-build](https://github.com/SidhBhat/simple-make-build).
To build this project just call `make`, the makefile handles the rest.

```bash
# clone repo
git clone --depth=1 https://github.com/SidhBhat/reverse-polish-calculator
# build
make
# and execute...
./build/reverse-polish-calculator
```
## Syntax

The moment you run the progran you are presented with a interactive prompt, where you can type
your calculations. The expressions you type here are in the reverse polish syntax.

Every expression consists a function and it's arguments in order to the left of the function.
the function can return only one value, which is the value of the expression. Suppose the function
is `func` with arguments `a`, `b` and `c`, we would write:

```
a b c func
```

we can pass this value to a another function `func2` with two arguments as:

```
arg1 a b c func func 2
```

Here we notice `a b c func` is bahaving as a single agrument to `func2`.

Thus $a + (b - c)$ would become `a b c - +` and $(a + b) - c$ will be `a b + c -`. Let us take a more
complicated expression $sin^2(a) + cos^4(b)$ we would espress it as `a sin 2 ^ b cos ^ 4 +`. Let us see
one more example $e^x cos(2x + 3) + ln(y)$:

```
2 x * 3 + cos e x ^ * y ln +
```

The reverse polish syntax is easy to implement in code as it is independant of operator precedance, but is pretty
unintutive to the human reader.

## Supported Functions

```
sin
cos
tan
sinh
cosh
tanh
pow
ln
log
sqrt
cbrt
```

## Supported binary operators

```
+
-
*
/
%
^
```

## Commands

These are commands that take zero arguments but allow one to modify the program environment:

```
# Get the last answer
ans
# clear the stack memory
clear
# exit the program
exit
```

## Some special operators

`?` Operator returns the value of the last calculation, so for example `2 3 * ? +` would be
equal to $2 \times 3$ added to itself and would produce $12$.

`=` The assignment operator assigns a [variable](#variables) to the value of the second argument. A variable must be the first argument.
If that is not the case an error is thrown. The value of the expression is equal to the assignment value that is, the
second argument. We can use this fact to perform assignments (multiple in a single expression) along with computations.


```
a 1 sin 2 ^ = b 1 cos 2 ^ = +
```

would evalute to $1$ as well as assign $a = sin^2 (1)$ and $b = cos^2 (1)$. Thus if we run `a b +` now we would again
get  $1$, which is cool.

## Variables

We have 26 variables which can hold values. These are the english small alphabets. We can assign values to these variables
using the `=` operator. 

## Contributing

As with my other projects you can start contributing by simply creating a pull request. And for suggesions you can contact me by email[^1].

[^1]:available on my profile
