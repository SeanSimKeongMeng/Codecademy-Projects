#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
};

struct RaceCar {
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};

// Print functions section
void printIntro(void) {
  printf("Welcome to our main event digital race fans!\n");
  printf("I hope everybody has their snacks because we are about to begin!\n");
}

void printCountdown(void) {
  printf("Racers Ready! In...\n");
  for (int i = 5 ; i > 0 ; i--) {
    printf("%d\n", i);
  }
  printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race race) {
  printf("After lap %d\n", race.currentLap);
  printf("First Place is: %s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race) {
  printf("Let's all congratulate %s in the %s race car for an amazing performance.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
  printf("It truly was a great race and everybody have a goodnight!\n");
}
// Logic functions section

int calculateTimeToCompleteLap(void) {
  int speed, acceleration, nerves;
  speed = (rand() % 3) + 1;
  acceleration = (rand() % 3) + 1;
  nerves = (rand() % 3) + 1;
  return (speed + acceleration + nerves);
}

void updateRaceCar(struct RaceCar* raceCar) {
  raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
    race->firstPlaceDriverName = raceCar1->driverName;
    race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
  } else {
    race->firstPlaceDriverName = raceCar2->driverName;
    race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
  }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {5, 1, "", ""};
  for (int i = 1 ; i <= race.numberOfLaps ; i++) {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
    race.currentLap++;
  }
  printCongratulation(race);
}

int main() {
    struct RaceCar raceCar1 = {"Sean", "Blue"};
    struct RaceCar raceCar2 = {"Cindy", "Red"};
	srand(time(0));
  printIntro();
  printCountdown();
  startRace(&raceCar1, &raceCar2);

};