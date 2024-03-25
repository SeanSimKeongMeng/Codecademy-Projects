class SinoTibetan extends Language {

  SinoTibetan(String langName, int number) {
    super(langName, number, "Asia", "subject-object-verb");

    if(langName.contains("Chinese")) {
      this.wordOrder = "subject-verb-object";
    }
  }
}