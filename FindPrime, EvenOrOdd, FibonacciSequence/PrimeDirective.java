// Import statement:
import java.util.ArrayList;

class PrimeDirective {
  
  // Add your methods here:
  public boolean isPrime(int number) {
    for (int i = 2; i < number; i++) {
      if (number % i == 0) return false;
    }
      if (number == 2) return true;
      if (number < 2) return false;
    return true;
  }

  public ArrayList<Integer> onlyPrimes(int[] numbers, int nPrime) {
    ArrayList<Integer> primes = new ArrayList<Integer>();

    for (int number : numbers) {
      if (nPrime > 0 && isPrime(number)) {
        primes.add(number);
        nPrime--;
      }
    }
    return primes;
  }
  
  public ArrayList<Integer> evenOrOdd(int[] numbers, boolean isEven) {
    ArrayList<Integer> filteredNumbers = new ArrayList<Integer>();

    for (int number : numbers) {
      if (isEven && number % 2 == 0) {
        filteredNumbers.add(number);
      } else if (!isEven && number % 2 == 1) {
        filteredNumbers.add(number);
      }
    }
    return filteredNumbers;
  }

  public ArrayList<Integer> fibonacci(int number) {
    ArrayList<Integer> fibonacciNumbers = new ArrayList<Integer>();

    if (number < 0) return fibonacciNumbers;

    fibonacciNumbers.add(0);
    if (number > 1) fibonacciNumbers.add(1);

    for (int i = 2; i < number; i++) {
      int fibonacci = fibonacciNumbers.get(i-1) + fibonacciNumbers.get(i-2);
      fibonacciNumbers.add(fibonacci);
    }

    return fibonacciNumbers;
  }
  
  public static void main(String[] args) {

    
    PrimeDirective pd = new PrimeDirective();

    int[] numbers = {6, 29, 28, 33, 11, 100, 101, 43, 89};
    int n = 5;
    System.out.println("The first " + n + " Prime Numbers : " + pd.onlyPrimes(numbers, n));

    boolean a = false;
    if (a == true) {
      System.out.println("Even numbers : " + pd.evenOrOdd(numbers, a));
    } else {
      System.out.println("Odd numbers : " + pd.evenOrOdd(numbers, a));
    }

    System.out.println("Fibonacci Sequence : " + pd.fibonacci(20));
    

  }  

}