#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

{

import threading

class FibonacciSeries(threading.Thread):
  def __init__(self):
    super().__init__()
    self.fibonacci_numbers = []

  def run(self):
    for i in range(1, 10001):
      if i == 0 or i == 1:
        self.fibonacci_numbers.append(i)
      else:
        self.fibonacci_numbers.append(self.fibonacci_numbers[i - 1] + self.fibonacci_numbers[i - 2])

  def get_fibonacci_numbers(self):
    return self.fibonacci_numbers

class SquareNumbers(threading.Thread):
  def __init__(self):
    super().__init__()
    self.square_numbers = []

  def run(self):
    for i in range(1, 10001):
      self.square_numbers.append(i ** 2)

  def get_square_numbers(self):
    return self.square_numbers

class CubeNumbers(threading.Thread):
  def __init__(self):
    super().__init__()
    self.cube_numbers = []

  def run(self):
    for i in range(1, 10001):
      self.cube_numbers.append(i ** 3)

  def get_cube_numbers(self):
    return self.cube_numbers

def main():
  fibonacci_series = FibonacciSeries()
  square_numbers = SquareNumbers()
  cube_numbers = CubeNumbers()

  fibonacci_series.start()
  square_numbers.start()
  cube_numbers.start()

  fibonacci_series.join()
  square_numbers.join()
  cube_numbers.join()

  print("Fibonacci numbers: ", fibonacci_series.get_fibonacci_numbers())
  print("Square numbers: ", square_numbers.get_square_numbers())
  print("Cube numbers: ", cube_numbers.get_cube_numbers())

if __name__ == "__main__":
main()


}

