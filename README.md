Here's the readme I stole from the project files:


# Introduction

In this homework, you will be implementing Newton's method, also known as the Newton-Raphson method, to find roots of equations. Note that this homework only uses quadratic equations. You will practice calling functions, using a loop, and writing code to solve a specific problem through this homework assignment.

# Background: Newton's Method

The algorithm is an iterative process that produces better approximations of an equation's root.

The initial approximation of the root ($$x_1$$) is calculated based on an initial guess ($$x_0$$), evaulation of the equation function $$f(x_0)$$, and its derivative $$f'(x_0)$$.

$$x_1 = x_0 - \frac{f(x_0)}{f'(x_0)}$$

This process is repeated 1) `MAX_ITERS` times or 2) until the absolute difference between $$x_{n+1}$$ and $$x_n$$ is less than `THRESHOLD`.

$$x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}$$

You can find more information about this method here: https://en.wikipedia.org/wiki/Newton%27s_method.

# Tasks

* Implement the `myQuad()` and `myQuadPrime()` functions in `quadratic.cpp`. These functions are already declared in `quadratic.h`, and you can find information about their parameters in this header file.
  
* Implement the `newtonRaphsonQuad()` function in `netwon.cpp`. This function is already declared in `newton.h`, and you can find information about its parameters in this header file.
  * In `newtonRaphsonQuad()`, call the `myQuad()` and `myQuadPrime()` functions to calculate approximate roots.
  * In `newtonRaphsonQuad()`, use the constants `THRESHOLD` and `MAX_ITERS`, which are declared in `newton.h`, to terminate the algorithm. Do not change their values.

# Compile and Test

1. Type the following commands on Terminal.

```
g++ -o main *.cpp *.h
```
```
./main
```

2. Enter 4 numbers (a, b, c, and guess of main() in order) and check if your result is correct. Here is an example.
 * Input
 ```
 3 -11 1 0.1
 
 // Quadratic: 3x^2 - 11x + 1

 // Initial Root Guess: 0.1
 ```

 * Expected Output
 ```
 Root Found: 0.0932822, Iterations: 2
 ```

  * More test sets (your output must be the same)
  ```
  3 -11 1 2.5 --> Root Found: 3.57338, Iterations: 5
  ```
  ```
  0.5 14.6 -20.2 1 --> Root Found: 1.32357, Iterations: 3
  ```
  ```
  0.5 14.6 -20.2 -50 --> Root Found: -30.5236, Iterations: 5
  ```
  ```
  10 1 1 1 --> No root found. Max iterations reached ( 100 )
  ```

# Submit

Please upload your `quadratic.cpp` and `netwon.cpp` files to `myCourses > Assignments > HW2`. Do not submit *.docx, *.pdf, *.txt, or *.zip file. Do not change the function names.
