const Calculate = {
  factorial(number) {
    let total = 1;
    for(i=number;i>0;i--) {
      
      total *= number;
      number--;
    }
    return total;
  }
}

console.log(Calculate.factorial(5));