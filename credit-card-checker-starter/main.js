// Returns a random DNA base
const returnRandBase = () => {
  const dnaBases = ["A", "T", "C", "G"];
  return dnaBases[Math.floor(Math.random() * 4)];
};

// Returns a random single strand of DNA containing 15 bases
const mockUpStrand = () => {
  const newStrand = [];
  for (let i = 0; i < 15; i++) {
    newStrand.push(returnRandBase());
  }
  return newStrand;
};
//Task 3. Create a Factory function.
const pAequorFactory = (num, arrDNA) => {
  return {
    specimenNum: num,
    dna: arrDNA,

//Task 4. Mutate 1 random base using mutate method.
    mutate() {
      let DNABases = ["A", "T", "C", "G"];
      let randomDNAIndex = Math.floor(Math.random() * 15);
      let remainingDNABases = DNABases.filter(
        (base) => base !== this.dna[randomDNAIndex]
      );
      this.dna[randomDNAIndex] =
        remainingDNABases[Math.floor(Math.random() * 3)];
      return this.dna;
    },

//Task 5. Compare 2 different DNA.
    compareDNA(secondDNA) {
      let count = 0;
      for (i = 0; i < this.dna.length; i++) {
        if (this.dna[i] === secondDNA.dna[i]) {
          count++;
        }
      }
      let percentDNA = (count / 15) * 100;
      return `Specimen #${this.specimenNum} and specimen #${
        secondDNA.specimenNum
      } have ${percentDNA.toFixed(2)}% DNA in common`;
    },

//Task 6. Find Survival rate and return true or false.
    willLikelySurvive() {
      let count = 0;
      for (i = 0; i < this.dna.length; i++) {
        if (this.dna[i] == "C" || this.dna[i] == "G") {
          count++;
        }
      }
      let percentSurvival = (count / 15) * 100;
      if (percentSurvival >= 60) {
        return true;
      } else {
        return false;
      }
    },

//Task 9. Find complementary strand of DNA.
    complementStrand() {
      let complementDNA = [];
      for (i = 0; i < this.dna.length; i++) {
        if (this.dna[i] == 'A') {
          complementDNA.push('T');
        } else if (this.dna[i] == 'T') {
          complementDNA.push('A');
        } else if (this.dna[i] == 'C') {
          complementDNA.push('G');
        } else if (this.dna[i] == 'G') {
          complementDNA.push('C');
        }
      }
      return complementDNA;
    }
  };
};

//Task 7. Create 30 instances of pAequor that can survive.
let count = 0;
let survivedCount = 0;
let survivedPAequor = [];
while (survivedCount < 30) {
  if (pAequorFactory(count, mockUpStrand()).willLikelySurvive() == true) {
    survivedPAequor.push(`Specimen #${count}`);
    survivedCount++;
  }
  count++;
}

firstPAequor = pAequorFactory(1234, mockUpStrand());
secondPAequor = pAequorFactory(11236, mockUpStrand());

//Test for Task 4
console.log(firstPAequor.mutate());

//Test for Task 5.
console.log(
  `Specimum #${firstPAequor.specimenNum}\'s DNA: [${firstPAequor.dna}]`
);
console.log(
  `Specimum #${secondPAequor.specimenNum}\'s DNA: [${secondPAequor.dna}]`
);
console.log(firstPAequor.compareDNA(secondPAequor));

//Test for Task 6.
console.log(firstPAequor.willLikelySurvive());

//Test for Task 7.
console.log(survivedPAequor)

//Test for Task 9.
console.log(`Specimum #${firstPAequor.specimenNum}\'s DNA: [${firstPAequor.dna}]`);
console.log(`Specimum #${firstPAequor.specimenNum}\'s complementary DNA: [${firstPAequor.complementStrand()}]`);
