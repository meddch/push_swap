# push_swap

# PushSwap

PushSwap is a project that involves sorting a stack of integers using only two stacks and a set of predefined operations. The goal of this project is to implement an efficient sorting algorithm that uses a minimal number of operations to sort the stack in ascending order.

## Project Overview

In the PushSwap project, you'll be given a stack of integers and two stacks (A and B) to work with. The stack A initially contains a random order of integers, and the goal is to sort this stack in ascending order using the following operations:

- **sa**: Swap the first two elements of stack A.
- **sb**: Swap the first two elements of stack B.
- **ss**: Perform sa and sb simultaneously.
- **pa**: Push the first element of stack B to stack A.
- **pb**: Push the first element of stack A to stack B.
- **ra**: Rotate stack A (shift all elements up by one, the first element becomes the last).
- **rb**: Rotate stack B (shift all elements up by one, the first element becomes the last).
- **rr**: Perform ra and rb simultaneously.
- **rra**: Reverse rotate stack A (shift all elements down by one, the last element becomes the first).
- **rrb**: Reverse rotate stack B (shift all elements down by one, the last element becomes the first).
- **rrr**: Perform rra and rrb simultaneously.

The objective is to create a program that takes a list of integers as input and outputs the series of operations required to sort the stack A.

## How to Use PushSwap

To compile the PushSwap program, run the following command:

```
make
```

This will generate two executables: `push_swap` and `checker`.

### push_swap

The `push_swap` executable is responsible for generating the series of operations to sort the stack A. To use it, execute the following command:

```
./push_swap [list_of_integers]
```

- `list_of_integers` is a space-separated list of integers that will be used to initialize stack A.

The program will output the series of operations required to sort the stack A. For example:

```
$ ./push_swap 3 1 2
sa
```

### checker

The `checker` executable is used to verify if the series of operations provided sorts the stack A correctly. To use it, execute the following command:

```
./checker [list_of_integers]
```

- `list_of_integers` is a space-separated list of integers that will be used to initialize stack A.

After executing the `checker` program, you can provide a series of operations through standard input. If the operations correctly sort the stack A, the program will output "OK." Otherwise, it will output "KO."

```
$ ./checker 3 1 2
sa
OK
```

## Learning Objectives

The PushSwap project provides an opportunity to learn and practice various concepts, including:

- Implementing sorting algorithms efficiently.
- Working with stacks and stack operations.
- Analyzing time complexity and optimizing algorithms.
- Handling input and output in a command-line program.
- Implementing and testing edge cases.

## Resources

Here are some resources that can be helpful for completing the PushSwap project:

- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm)

Good luck with your PushSwap project! Enjoy implementing an efficient sorting algorithm using stacks and mastering the art of sorting a stack of integers with minimal operations!
