class Language {

    protected String name;
    protected int numSpeakers;
    protected String regionsSpoken;
    protected String wordOrder;

    Language(String langName, int number, String region, String order) {
      this.name = langName;
      this.numSpeakers = number;
      this.regionsSpoken = region;
      this.wordOrder = order;
    }

    public void getInfo() {
      System.out.println(this.name + " is spoken by " + this.numSpeakers + " people mainly in " + this.regionsSpoken + ".");
      System.out.println(" The language follows the word order: " + this.wordOrder + ".");
    }

    public void setNumber (int number) {
      this.numSpeakers = number;
    }

    public void setRegion (String region) {
      this.regionsSpoken = region;
    }

    public void setWordOrder (String order) {
      this.wordOrder = order;
    }

  public static void main(String[] args) {
    Language english = new Language("English", 1000000000, "almost everywhere", "subject-verb-object");

    //english.getInfo();

    english.setNumber(1000000005);

    Mayan abc = new Mayan("abc", 1481751);

    //abc.getInfo();

    SinoTibetan chinese = new SinoTibetan("Chinese", 15315);

    //chinese.getInfo();

    SinoTibetan burmese = new SinoTibetan("Burmese", 426246);

    //burmese.getInfo();

    Language[] languages = {english, abc, chinese, burmese};

    for (Language language: languages) {
      language.getInfo();
    }
  }
}