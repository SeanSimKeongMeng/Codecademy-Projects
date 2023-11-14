let humanScore = 0;
let computerScore = 0;
let currentRoundNumber = 1;

// Write your code below:

const generateTarget = () => {
  return Math.floor(Math.random() * 9 + 1);
};



const compareGuesses = (humanGuess, computerGuess, targetNumber) => {
  if (humanGuess < 0 || humanGuess > 9) {
    window.alert('Please key in 0-9');
  }
  const humanDistance = Math.abs(humanGuess - targetNumber);
  const computerDistance = Math.abs(computerGuess - targetNumber);
  return humanDistance <= computerDistance;
};

const updateScore = winner => {
  if (winner === "human") {
    humanScore += 1;
  } else if (winner === "computer") {
    computerScore += 1;
  };
}

const advanceRound = () => {
  currentRoundNumber += 1;
}